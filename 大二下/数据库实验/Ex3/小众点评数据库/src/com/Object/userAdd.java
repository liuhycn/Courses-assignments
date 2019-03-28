package com.Object;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class userAdd extends JPanel {
    private JLabel j1,j2,j3,j4;
    private JTextField jtf1,jtf2,jtf4;
    private JButton b1;
    private JRadioButton nan=new JRadioButton();
    private JRadioButton nu=new JRadioButton();
    private ButtonGroup sex=new ButtonGroup();
    private String sex1;
    String url= "jdbc:sqlserver://127.0.0.1:1433;DatabaseName=Ex3;";
    public userAdd(){
        setLayout(null);
        setBackground(Color.white);
        j1=new JLabel("用户编号：");
        j1.setBounds(300,30,70,20);
        jtf1=new JTextField();
        jtf1.setBounds(370,30,180,25);

        j2=new JLabel("用户姓名：");
        j2.setBounds(300,90,70,20);
        jtf2=new JTextField();
        jtf2.setBounds(370,90,180,25);

        j3=new JLabel("用户性别：");
        j3.setBounds(300,150,70,20);
        //jtf3=new JTextField();
        //jtf3.setBounds(370,150,180,25);
        nan.setText("男");
        nan.setBackground(Color.white);
        nan.setBounds(370,141,40,40);
        nan.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(nan.isSelected()){
                    sex1=nan.getText();
                }
            }
        });
        nu.setText("女");
        nu.setBackground(Color.white);
        nu.setBounds(470,141,40,40);
        nu.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(nan.isSelected()){
                    sex1=nu.getText();
                }
            }
        });
        sex.add(nan);
        sex.add(nu);
        add(nan);
        add(nu);


        j4=new JLabel("用户密码：");
        j4.setBounds(300,210,70,20);
        jtf4=new JTextField();
        jtf4.setBounds(370,210,180,25);

        b1=new JButton("确认");
        b1.setBounds(360,270,120,35);
        b1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(jtf1.getText().trim().length()==0){
                    JOptionPane.showMessageDialog(null,"用户号必填","错误",JOptionPane.ERROR_MESSAGE);
                }
                else{
                    //System.out.print("hello");
                    Torun();
                }
            }
        });

        add(j1);
        add(jtf1);
        add(j2);
        add(jtf2);
        add(j3);
//        add(jtf3);
        add(j4);
        add(jtf4);
        add(b1);
    }
    public void Torun(){
        try{
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            Connection conn=DriverManager.getConnection(url,"sa","123456");
            String sql="insert into USERS(Uno,Uname,Usex,Uacnt)"+
                    "values("+"'"+jtf1.getText()+"'"+","+"'"+jtf2.getText()+"'"+","+"'"+sex1+"'"+","+"'"+jtf4.getText()+"'"+")";
            System.out.print(sql);
            PreparedStatement pstm=conn.prepareStatement(sql);
            pstm.executeUpdate();
           // ResultSet rs=pstm.executeQuery();
        }catch (ClassNotFoundException cnfe){
            cnfe.printStackTrace();
        }catch (SQLException se){
            se.printStackTrace();
        }
    }
    public static void main(String[] args){
        JFrame j=new JFrame();
        j.setLayout(null);
        j.setBounds(20,60,900,500);
        userAdd s=new userAdd();
        s.setBounds(10,10,800,480);
        j.add(s);
        j.setVisible(true);
    }
}
