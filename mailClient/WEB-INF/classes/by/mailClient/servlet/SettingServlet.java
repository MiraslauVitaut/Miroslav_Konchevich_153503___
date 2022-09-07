package by.mailClient.servlet;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import by.mailClient.model.Setting;
import by.mailClient.service.SettingService;

@WebServlet(urlPatterns = { "/settingEdit" })
public class SettingServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    
    public SettingServlet() {
        super();
    }
    
    // Отобразить страницу редактирования настроек
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        
        Setting setting = new Setting();
        SettingService service = new SettingService();
        setting = service.read();
        
        request.setAttribute("setting", setting);
        
        RequestDispatcher dispatcher = request.getServletContext().getRequestDispatcher("/jsp/settingEdit.jsp");
        dispatcher.forward(request, response);
    }
    
    // Когда пользователь вводит информацию продукта, и нажимает Submit.
    // Этот метод будет вызван.
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        
        String errorString = "Настройки успешно перезаписаны";
        
        String SMTPHost = request.getParameter("SMTPHost");
        String SMTPPort = request.getParameter("SMTPPort");
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        
        Setting setting = new Setting();
        setting.setSMTPHost(SMTPHost);
        setting.setSMTPPort(SMTPPort);
        setting.setUsername(username);
        setting.setPassword(password);
        
        try {
            SettingService service = new SettingService();
            service.save(setting);
        } catch (Exception e) {
            System.err.println(e);
            errorString = "Ошибка: " + e.getMessage();
        }
        
        // Сохранить информацию в request attribute перед тем как forward к views.
        request.setAttribute("errorString", errorString);
        request.setAttribute("setting", setting);
        
        RequestDispatcher dispatcher = request.getServletContext().getRequestDispatcher("/jsp/settingEdit.jsp");
        dispatcher.forward(request, response);
    }
}
