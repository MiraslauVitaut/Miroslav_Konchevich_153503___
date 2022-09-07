package by.mailClient.model;

public class Setting implements Bean {
    
    private static final long serialVersionUID = -8041284149926389996L;
    
    private String SMTPHost; // SMTPHost
    private String SMTPPort; // SMTPPort
    private String POP3Host; // POP3Host
    private String POP3Port; // POP3Port
    private String username; // пользователь
    private String password; // пароль
    
    public String getSMTPHost() {
        return SMTPHost;
    }
    
    public void setSMTPHost(String sMTPHost) {
        SMTPHost = sMTPHost;
    }
    
    public String getSMTPPort() {
        return SMTPPort;
    }
    
    public void setSMTPPort(String sMTPPort) {
        SMTPPort = sMTPPort;
    }
    
    public String getPOP3Host() {
        return POP3Host;
    }
    
    public void setPOP3Host(String pOP3Host) {
        POP3Host = pOP3Host;
    }
    
    public String getPOP3Port() {
        return POP3Port;
    }
    
    public void setPOP3Port(String pOP3Port) {
        POP3Port = pOP3Port;
    }
    
    public String getUsername() {
        return username;
    }
    
    public void setUsername(String username) {
        this.username = username;
    }
    
    public String getPassword() {
        return password;
    }
    
    public void setPassword(String password) {
        this.password = password;
    }
    
    @Override
    public String toString() {
        return "Setting [SMTPHost=" + SMTPHost + ", SMTPPort=" + SMTPPort + ", POP3Host=" + POP3Host + ", POP3Port=" + POP3Port + ", username=" + username + ", password=" + password + "]";
    }
    
}
