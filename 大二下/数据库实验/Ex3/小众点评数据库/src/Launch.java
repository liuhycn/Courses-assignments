import com.Frame.Login;

import javax.swing.*;
import java.awt.*;

public class Launch {

    //static Login myLogin;
    public static void main(String[] args){
//        try{
//            UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
//        }catch (Exception e){
//            e.printStackTrace();
//        }
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    Login window = new Login();
                    //window.frame.setVisible(true);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
       // myLogin=new Login();
    }

}
