package by.mailClient.service;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;

import by.mailClient.model.Setting;

/**
 * @author Konchevich
 * 
 * работа с настройками
 *
 */

public class SettingService {
    
    public SettingService() {}
    
    // Путь к файлу с параметрами
    private final String PATH = this.getClass().getResource("/setting.properties").getPath();
    
    // читаем настройки из файла
    public Setting read() throws FileNotFoundException, IOException {
        Properties properties = new Properties();
        properties.load(new BufferedReader(new FileReader(new File(PATH))));
        
        Setting setting = new Setting();
        setting.setSMTPHost(properties.getProperty("smtp.host"));
        setting.setSMTPPort(properties.getProperty("smtp.port"));
        setting.setPOP3Host(properties.getProperty("pop3.host"));
        setting.setPOP3Port(properties.getProperty("pop3.port"));
        setting.setUsername(properties.getProperty("username"));
        setting.setPassword(properties.getProperty("password"));
        
        return setting;
    }
    
    // записываем настройки в файл настроек
    public void save(Setting setting) throws FileNotFoundException, IOException {
        Properties properties = new Properties();
        properties.put("smtp.host", setting.getSMTPHost());
        properties.put("smtp.port", setting.getSMTPPort());
        properties.put("pop3.host", setting.getPOP3Host());
        properties.put("pop3.port", setting.getPOP3Port());
        properties.put("username", setting.getUsername());
        properties.put("password", setting.getPassword());
        
        FileOutputStream fr = new FileOutputStream(new File(PATH));
        properties.store(fr, "Properties");
        fr.close();
    }
}
