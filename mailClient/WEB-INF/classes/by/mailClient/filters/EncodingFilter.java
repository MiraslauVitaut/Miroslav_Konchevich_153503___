package by.mailClient.filters;

import java.io.IOException;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.annotation.WebFilter;
import javax.servlet.annotation.WebInitParam;
import javax.servlet.http.HttpServletRequest;

/**
 * Servlet Filter реализация класса AccessFilter Фильтр устанавливает кодировку request в "UTF-8".
 * 
 * @author Alex Nastin
 */
@WebFilter(urlPatterns = { "/*" }, initParams = { @WebInitParam(name = "encoding", value = "UTF-8", description = "Encoding Param") })
public class EncodingFilter implements Filter {
    private String code;
    
    /** Default constructor. */
    public EncodingFilter() {}
    
    /** @see Filter#init(FilterConfig) */
    @Override
    public void init(FilterConfig fConfig) throws ServletException {
        code = fConfig.getInitParameter("encoding");
    }
    
    /** @see Filter#doFilter(ServletRequest, ServletResponse, FilterChain) */
    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        
        ((HttpServletRequest) request).getSession();
        ((HttpServletRequest) request).getServletPath();
        String pageParam = ((HttpServletRequest) request).getQueryString();
        if (pageParam != null) {
            pageParam = "?" + pageParam;
        }
        else {
            pageParam = "";
        }
        
        String codeRequest = request.getCharacterEncoding();
        if (code != null && !code.equalsIgnoreCase(codeRequest)) {
            request.setCharacterEncoding(code);
            response.setCharacterEncoding(code);
        }
        chain.doFilter(request, response);
    }
    
    /** @see Filter#destroy() */
    @Override
    public void destroy() {
        code = null;
    }
}
