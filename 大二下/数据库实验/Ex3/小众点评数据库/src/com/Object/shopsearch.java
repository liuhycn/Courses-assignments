package com.Object;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
//import javax.swing.border.MatteBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

import com.Util.MyTextFieldBorder;

public class shopsearch extends JPanel {
    //private JLabel jl1;
    private String url = "jdbc:sqlserver://127.0.0.1:1433;DatabaseName=Ex3;";
    private JTextField jtf1;
    private JButton jb1;
    private JTable jtb;
    private JScrollPane scpDemo;
    private DefaultTableModel model;
    //MatteBorder border=new MatteBorder(0, 0, 2, 0, new Color(192, 192, 192));
    private MyTextFieldBorder border=new MyTextFieldBorder();
    public shopsearch(){
        setLayout(null);
        //jl1=new JLabel("请输入要搜索的学生的学号");
        //jl1.setBounds(300,90,160,20);
        setBackground(Color.white);
        jtf1=new JTextField();
        jtf1.setBorder(border);
        jtf1.setBounds(140,20,400,37);
        jb1=new JButton("确认");
        jb1.setBounds(545,20,100,37);
        jb1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String str=jtf1.getText();
                String sql;
                char c=str.charAt(0);
                try{
                    Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
                    Connection conn = DriverManager.getConnection(url, "sa", "123456");
                    PreparedStatement pstm;
                       sql = "select Dname,Dprice,Dpf from Dish,SELLERS where SELLERS.Sname ='"+jtf1.getText()+"' and SELLERS.Sno=Dish.Sno";
                       pstm=conn.prepareStatement(sql);
                      // pstm.setNString(1,str);
                    ResultSet rs = pstm.executeQuery();
                    int count = 0;
                    while (rs.next()) {
                        count++;
                    }
                    rs = pstm.executeQuery();
                    Object[][] info = new Object[count][3];
                    count = 0;
                    while (rs.next()) {
                    	info[count][0] = rs.getString("Dname");
                        info[count][1] = rs.getString("Dprice");
                        info[count][2] = rs.getString("Dpf");
                        //info[count][4]=rs.getInt("Number");
                        count++;
                    }
                    String[] title = {"菜品名", "价格","好评数"};
                    model = new DefaultTableModel(info, title) {
                        @Override
                        public boolean isCellEditable(int row, int column) {
                            return false;
                            //return super.isCellEditable(row, column);
                        }
                    };
                    //jtb=new JTable(info,title);
                    jtb = new JTable(model);
                    jtb.setFont(new Font("宋体", 0, 12));
                    //jtb.setAutoResizeMode(1);
                    jtb.setRowHeight(24);
                    //jtb.set
                    //jth=jtb.getTableHeader();
                    // jth.set
                    scpDemo=new JScrollPane();
                    scpDemo.getViewport().add(jtb);
                    scpDemo.setBounds(0,70,840,200);
                    add(scpDemo);
                }catch (ClassNotFoundException cnfe){
                    cnfe.printStackTrace();
                }catch (SQLException se){
                    se.printStackTrace();
                }
            }
        });

        add(jtf1);
        add(jb1);
        //add(scpDemo);
    }
    public static void main(String[] args){
        JFrame j=new JFrame();
        j.setBounds(120,50,700,600);
        j.setLayout(null);
        shopsearch s=new shopsearch();
        s.setBounds(20,30,500,400);
        j.add(s);
        j.setVisible(true);
    }
}
