package by.mailClient.servlet;

import java.io.IOException;
import java.util.Date;
import java.util.Properties;

import javax.mail.Message;
import javax.mail.MessagingException;
import javax.mail.PasswordAuthentication;
import javax.mail.Session;
import javax.mail.Transport;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import by.mailClient.model.Setting;
import by.mailClient.service.SettingService;

@WebServlet(urlPatterns = { "/letterSend" })
public class LetterSendServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    
    public LetterSendServlet() {
        super();
    }
    
    // Отобразить страницу создания письма
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        
        try {
            // читаем настройки
            Setting setting = new Setting();
            SettingService service = new SettingService();
            setting = service.read();
            
            // от кого
            request.setAttribute("username", setting.getUsername());
        } catch (Exception e) {
            request.setAttribute("errorString", "Ошибка: " + e.toString());
        }
        
        RequestDispatcher dispatcher = request.getServletContext().getRequestDispatcher("/jsp/letterSend.jsp");
        dispatcher.forward(request, response);
    }
    
    // Когда пользователь вводит данные для посылки, и нажимает Submit.
    // Этот метод будет вызван.
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        
        String errorString = "Письмо успешно отправлено";
        
        // читаем настройки
        Setting setting = new Setting();
        SettingService service = new SettingService();
        setting = service.read();
        
        // данные с формы
        String recipient = request.getParameter("recipient"); // кому
        String subject = request.getParameter("subject"); // тема
        String body = request.getParameter("body"); // тело
        
        // готовим канал
        Properties props = new Properties();
        props.put("mail.transport.protocol", "smtp");
        props.put("mail.smtp.host", setting.getSMTPHost());
        props.put("mail.smtp.port", setting.getSMTPPort());
        props.put("mail.smtp.ssl.enable", "true");
        props.put("mail.smtp.auth", "true");
        final String username = setting.getUsername();
        final String password = setting.getPassword();
        Session session = Session.getInstance(props, new javax.mail.Authenticator() {
            @Override
            protected PasswordAuthentication getPasswordAuthentication() {
                return new PasswordAuthentication(username, password);
            }
        });
        
        if (session == null) {
            errorString = "Ошибка: [error sending Message:Не возможно получить объект javax.mail.Session неверные параметры почтового сервера]";
        }
        
        // посылка почты
        try {
            MimeMessage message = new MimeMessage(session);
            message.setFrom(new InternetAddress(setting.getUsername()));
            message.addRecipients(Message.RecipientType.CC, InternetAddress.parse(recipient));
            message.setSubject(subject);
            message.setSentDate(new Date());
            message.setText(body);
            
            Transport.send(message);
        }
        catch (MessagingException e) {
            System.err.println(e);
            errorString = "Ошибка: " + e.getMessage();
        }
        
        // Сохранить информацию в request attribute перед тем как forward к views.
        request.setAttribute("errorString", errorString);
        request.setAttribute("username", setting.getUsername());
        request.setAttribute("recipient", recipient);
        request.setAttribute("subject", subject);
        request.setAttribute("body", body);
        
        RequestDispatcher dispatcher = request.getServletContext().getRequestDispatcher("/jsp/letterSend.jsp");
        dispatcher.forward(request, response);
    }
}
