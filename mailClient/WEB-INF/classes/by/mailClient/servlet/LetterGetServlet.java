package by.mailClient.servlet;

import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Properties;

import javax.mail.Flags;
import javax.mail.Folder;
import javax.mail.Message;
import javax.mail.PasswordAuthentication;
import javax.mail.Session;
import javax.mail.Store;
import javax.mail.search.FlagTerm;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import by.mailClient.model.MessageBean;
import by.mailClient.model.Setting;
import by.mailClient.service.MessagesService;
import by.mailClient.service.SettingService;

@WebServlet(urlPatterns = { "/letterGet" })
public class LetterGetServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    
    public LetterGetServlet() {
        super();
    }
    
    // Получить список писем
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        
        try {
            // читаем настройки
            Setting setting = new Setting();
            SettingService service = new SettingService();
            setting = service.read();
            
            Properties props = new Properties();
            props.put("mail.store.protocol", "pop3");
            props.put("mail.pop3.host", setting.getPOP3Host());
            props.put("mail.pop3.port", setting.getPOP3Port());
            props.put("mail.pop3.ssl.enable", "true");
            props.put("mail.pop3.auth", "true");
            
            final String username = setting.getUsername();
            final String password = setting.getPassword();
            Session session = Session.getInstance(props, new javax.mail.Authenticator() {
                @Override
                protected PasswordAuthentication getPasswordAuthentication() {
                    return new PasswordAuthentication(username, password);
                }
            });
            
            // Получить store
            Store store = session.getStore();
            store.connect();
            
            // Получить folder (входящие)
            Folder inbox  = store.getFolder("INBOX");
            inbox .open(Folder.READ_WRITE);
            
            Message[] messages = inbox.search(new FlagTerm(new Flags(Flags.Flag.SEEN), false));
            ArrayList<String> attachments = new ArrayList<>();
            
            // получаем список писем
            MessagesService messageService = new MessagesService();
            LinkedList<MessageBean> listMessages = messageService.getPart(messages, attachments);
            
            // закрываем
            inbox.setFlags(messages, new Flags(Flags.Flag.SEEN), true);
            inbox.close(false);
            store.close();
            
            request.setAttribute("listMessages", listMessages);
            if (listMessages.size()==0) {
                request.setAttribute("errorString", "Нет входящих писем");
            }
            
        } catch (Exception e) {
            System.err.println(e);
            request.setAttribute("errorString", "Ошибка: " + e.toString());
        }
        
        RequestDispatcher dispatcher = request.getServletContext().getRequestDispatcher("/jsp/letterList.jsp");
        dispatcher.forward(request, response);
    }
}
