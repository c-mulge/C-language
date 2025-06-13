import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class examp1 extends HttpServlet{
    public void init() throws ServletException{
        System.out.println("");
    }
    public void doGet(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException{

        res.setContentType("Text/html");
        PrintWriter out=res.getWriter();
        out.println("<html><body>");
        out.println("<h1>Hello World</h1>");
        out.println("</body></html>");
    }

    public void destroy(){
        System.out.println("Servlet Destroyed!");
    }
}