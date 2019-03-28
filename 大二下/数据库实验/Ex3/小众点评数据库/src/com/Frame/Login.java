package com.Frame;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.sql.*;
import com.Util.myImagePanel;

import javax.swing.*;
import javax.swing.border.MatteBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Login {
    private JFrame myLogin;
    private JLabel User_Label;
    private JTextField User_TextField;
    private JLabel Password_Label;
    private JPasswordField User_PasswordField;
    //private JLabel Title_Label;
    private JButton Login_Buttun;
    private JButton Exit_Button;
    private myImagePanel my;
    private final int WIDTH=400;
    private final int HEIGHT=300;
    private final int local_x=450;
    private final int local_y=200;
    private JLabel prompt=new JLabel();
    //private final String p1="请输入密码/账号";
    //private final String p2="密码/账号错误";
    private String url= "jdbc:sqlserver://127.0.0.1:1433;DatabaseName=Ex3;";
    private int isRight=1;
    private String path="/img/img1.png";
    private MatteBorder border=new MatteBorder(0, 0, 2, 0, new Color(192, 192, 192));
    public Login(){
        //super();
        myLogin=new JFrame();
        myLogin.setTitle("登录");
        try{
            //String path="/img/timg.png";
            ImageIcon icon=new ImageIcon(getClass().getResource(path));
            myLogin.setIconImage(icon.getImage());
        }catch (Exception e){
            e.printStackTrace();
        }
        myLogin.setAlwaysOnTop(true);
        myLogin.setLocation(local_x,local_y);
        myLogin.setSize(WIDTH,HEIGHT);
        myLogin.setResizable(false);
        myLogin.getContentPane().setBackground(Color.white);
        myLogin.setLayout(null);
        my=new myImagePanel("/img/img2.png");
        my.setBounds(0,0,400,100);
        //myLogin.setForeground(Color.GREEN);
        //Container myContainer=myLogin.getContentPane();
        //标题
        myLogin.add(my);
//        Title_Label=new JLabel("图书馆管理系统");
//        Title_Label.setFont(new Font("黑体",Font.PLAIN,25));
//        Title_Label.setBounds(115,30,200,25);
//        myLogin.add(Title_Label);

        //用户
        User_Label=new JLabel("用户名：");
        User_Label.setFont(new Font("微软雅黑",Font.PLAIN,16));
        //myLogin.add(User_Label);
        User_Label.setBounds(80,120,70,20);
        myLogin.add(User_Label);

        //MyTextFieldBorder mtfb=new MyTextFieldBorder();
        User_TextField=new JTextField();
        //User_TextField.setColumns(10);
        User_TextField.setBorder(border);
        //User_TextField.setText("用户名");
        User_TextField.setFont(new Font("微软雅黑", 0, 14));
        User_TextField.setBounds(150,115,160,30);

        myLogin.add(User_TextField);

        //密码
        Password_Label=new JLabel("密码：");
        Password_Label.setFont(new Font("微软雅黑",Font.PLAIN,16));
        Password_Label.setBounds(80,170,70,20);
        myLogin.add(Password_Label);

        User_PasswordField=new JPasswordField();
        User_PasswordField.setBorder(border);
        //User_PasswordField.setText("密码");
        User_PasswordField.setFont(new Font("微软雅黑", 0, 14));
        User_PasswordField.setBounds(150,158,160,30);

        myLogin.add(User_PasswordField);

        Login_Buttun=new JButton("登录");
       // Login_Buttun.setBackground(Color.BLUE);
        //Login_Buttun.set
        Login_Buttun.setBounds(100,216,60,30);
        Login_Buttun.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(User_TextField.getText().length()==0||User_PasswordField.getText().length()==0){
                    prompt.setText("请输入账号/密码");
                }
                else if(isOK(User_TextField.getText(),User_PasswordField.getText())==0){
                    prompt.setText("账号/密码错误");
                }
                else{
                    Framework f=new Framework(User_TextField.getText());
                    myLogin.setVisible(false);
                    //myLogin.setDefaultCloseOperation(0);
                }
            }
        });
        Login_Buttun.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {

            }

            @Override
            public void keyPressed(KeyEvent e) {
                  if(e.getKeyCode()==KeyEvent.VK_ENTER){
                      System.out.print("hello");
                      toRun();
                  }
            }

            @Override
            public void keyReleased(KeyEvent e) {

            }
        });
        //提示
        prompt.setBounds(150,190,100,21);
        prompt.setFont(new Font("宋体",Font.PLAIN,10));
        myLogin.add(prompt);
        //按钮
        Exit_Button=new JButton("退出");
        //Exit_Button.setBackground(Color.BLUE);
        //Exit_Button.setForeground(Color.red);
        Exit_Button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        Exit_Button.setBounds(240,216,60,30);
        myLogin.add(Login_Buttun);
        myLogin.add(Exit_Button);

        myLogin.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        myLogin.setVisible(true);
    }
    public int isOK(String User,String Password){
        try{
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            Connection conn=DriverManager.getConnection(url,User,Password);
            isRight=1;
        }catch(ClassNotFoundException cnfe){
            cnfe.printStackTrace();
            isRight=0;
        }catch (SQLException se){
            se.printStackTrace();
            isRight=0;
        }
        return isRight;
    }
    public void toRun(){
        if(User_TextField.getText().length()==0||User_PasswordField.getText().length()==0){
            prompt.setText("请输入账号/密码");
        }
        else if(isOK(User_TextField.getText(),User_PasswordField.getText())==0){
            prompt.setText("账号/密码错误");
        }
        else{
            Framework f=new Framework(User_TextField.getText());
            myLogin.setVisible(false);
            //myLogin.setDefaultCloseOperation(0);
        }
    }
}
