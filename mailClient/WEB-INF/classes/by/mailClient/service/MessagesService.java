package by.mailClient.service;

import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.LinkedList;

import javax.mail.Message;
import javax.mail.MessagingException;
import javax.mail.Multipart;
import javax.mail.Part;
import javax.mail.internet.MimeUtility;

import by.mailClient.model.MessageBean;

public class MessagesService {
    
    public LinkedList<MessageBean> getPart(Message[] messages, ArrayList<String> attachments) throws MessagingException, IOException {
        LinkedList<MessageBean> listMessages = new LinkedList<>();
        SimpleDateFormat f = new SimpleDateFormat("dd.MM.yyyy HH:mm:ss");
        for (Message inMessage : messages) {
            attachments.clear();
            if (inMessage.isMimeType("text/plain")) {
                MessageBean message = new MessageBean(inMessage.getMessageNumber(), MimeUtility.decodeText(inMessage.getSubject()), inMessage.getFrom()[0].toString(), null,
                        f.format(inMessage.getSentDate()), (String) inMessage.getContent(), false, null);
                listMessages.add(message);
            }
            else if (inMessage.isMimeType("multipart/*")) {
                Multipart mp = (Multipart) inMessage.getContent();
                MessageBean message = null;
                for (int i = 0; i < mp.getCount(); i++) {
                    Part part = mp.getBodyPart(i);
                    if ((part.getFileName() == null || part.getFileName() == "") && part.isMimeType("text/plain")) {
                        message = new MessageBean(inMessage.getMessageNumber(), inMessage.getSubject(), inMessage.getFrom()[0].toString(), null, f.format(inMessage.getSentDate()),
                                (String) part.getContent(), false, null);
                    }
                    /*
                    else if (part.getFileName() != null || part.getFileName() != "") {
                        if (part.getDisposition() != null && part.getDisposition().equals(Part.ATTACHMENT)) {
                            attachments.add(saveFile(MimeUtility.decodeText(part.getFileName()), part.getInputStream()));
                            if (message != null) {
                                message.setAttachments(attachments);
                            }
                        }
                    }
                     */
                }
                listMessages.add(message);
            }
        }
        return listMessages;
    }
}
