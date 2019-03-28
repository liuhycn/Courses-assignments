package com.Frame;

import com.Object.*;

import javax.swing.*;
//import javax.swing.event.AncestorEvent;
//import javax.swing.event.AncestorListener;
import com.Util.myImagePanel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class Framework extends JFrame implements ActionListener{
   private final int WIDTH=986;
    private final int HEIGHT=608;
    private final int Local_x=221;
    private final int Local_y=56;
    private JLabel User_Name;
    private JPanel W_Panel;//左面
    private JPanel N_Panel;//上面
    private JPanel C_Panel;//中间
    private JButton Dish_Button;
    private JButton Shop_Button;
    private JButton Userr_Button;
    private JButton Record_Button;
    private JLabel miyang;
    private JButton Exit_Button;
    private JLabel Nshow;
    private String str="当前位置：";
    private String path="/img/img1.png";
    private myImagePanel my;
   // private CardLayout CarL;
   // private JPanel Student_p,Book_P,Borrow_P,Return_P;
    public Framework(String User){
        setTitle("小众点评数据库");
        setSize(WIDTH,HEIGHT);
        setLocation(Local_x,Local_y);
        //setUndecorated(true);
        setLayout(null);
        setResizable(false);
        try{
            ImageIcon icon=new ImageIcon(getClass().getResource(path));
             setIconImage(icon.getImage());
        }catch (Exception e){
            e.printStackTrace();
        }

        W_Panel=new JPanel();
        W_Panel.setBackground(Color.decode("#2E2E2E"));
        W_Panel.setBounds(0,0,120,608);
        add(W_Panel);

        W_Panel.setLayout(null);

        my=new myImagePanel("/img/sa.jpg");
        my.setBounds(30,20,50,50);
        W_Panel.add(my);

        User_Name=new JLabel(User+" 你好！");
        User_Name.setFont(new Font("宋体",0,12));
        User_Name.setForeground(Color.WHITE);
        User_Name.setBounds(25,80,80,20);
        W_Panel.add(User_Name);


        Dish_Button=new JButton("菜品管理");
        Dish_Button.setBorderPainted(false);
        Dish_Button.setBackground(Color.decode("#2E2E2E"));
        Dish_Button.setForeground(Color.WHITE);
        //Dish_Button.setBackground(Color.BLACK);
        //Dish_Button.setForeground(Color.WHITE);
       // Dish_Button.setContentAreaFilled(false);
        //Dish_Button.setForeground(Color.WHITE);
        Dish_Button.setBorderPainted(false);
        Dish_Button.setBounds(0,120,120,40);
        Dish_Button.addActionListener(this);
        W_Panel.add(Dish_Button);

        Shop_Button=new JButton("商家管理");
        Shop_Button.setBounds(0,180,120,40);
        Shop_Button.setBorderPainted(false);
        Shop_Button.setBackground(Color.decode("#2E2E2E"));
        Shop_Button.setForeground(Color.WHITE);
        //Shop_Button.setBackground(Color.BLACK);
        //Shop_Button.setForeground(Color.WHITE);
        //Shop_Button.setContentAreaFilled(false);
        Shop_Button.setBorderPainted(false);
        Shop_Button.addActionListener(this);
        W_Panel.add(Shop_Button);

        Userr_Button=new JButton("用户管理");
        //Userr_Button.setBackground(Color.BLACK);
        //Dish_Button.setForeground(Color.WHITE);
        Userr_Button.setBorderPainted(false);
        Userr_Button.setBorderPainted(false);
        Userr_Button.setBackground(Color.decode("#2E2E2E"));
        Userr_Button.setForeground(Color.WHITE);
       // Userr_Button.setContentAreaFilled(false);
       // Userr_Button.setForeground(Color.white);
        Userr_Button.setBounds(0,240,120,40);
        Userr_Button.addActionListener(this);
        W_Panel.add(Userr_Button);

        Record_Button=new JButton("记录管理");
        Record_Button.setBorderPainted(false);
        Record_Button.setBackground(Color.decode("#2E2E2E"));
        Record_Button.setForeground(Color.WHITE);
        //Record_Button.setBackground(Color.BLACK);
        //Dish_Button.setForeground(Color.WHITE);
       // Record_Button.setContentAreaFilled(false);
        //Record_Button.setBorderPainted(false);
        //Record_Button.setForeground(Color.WHITE);
        Record_Button.setBorderPainted(false);
        Record_Button.setBounds(0,300,120,40);
        Record_Button.addActionListener(this);
        W_Panel.add(Record_Button);

        Exit_Button=new JButton("退出系统");
        Exit_Button.setBorderPainted(false);
        Exit_Button.setBackground(Color.decode("#2E2E2E"));
        Exit_Button.setForeground(Color.WHITE);
        Exit_Button.setBounds(0,529,120,40);
        Exit_Button.addActionListener(this);
        W_Panel.add(Exit_Button);
        //init_1();

        N_Panel=new JPanel();
        N_Panel.setBackground(Color.WHITE);
        N_Panel.setBounds(120,0,890,70);
        add(N_Panel);

        N_Panel.setLayout(null);
        Nshow=new JLabel(str+"主界面");
        Nshow.setBounds(20,30,120,60);
        N_Panel.add(Nshow);

        String s="<html><body>"+"吃就完事了！"+"</body></html>";
        miyang=new JLabel(s);
        miyang.setForeground(Color.BLACK);
        miyang.setBounds(700,0,300,70);//
        N_Panel.add(miyang);


        C_Panel=new JPanel();
        C_Panel.setBounds(120,70,890,538);
        //C_Panel.setBackground(Color.BLUE);

        C_Panel.setLayout(null);
        add(C_Panel);
        //C_Panel.set

        setVisible(true);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    }
    @Override
    public void actionPerformed(ActionEvent e){
        switch (e.getActionCommand()){
            case "退出系统": System.exit(0);break;
            case "菜品管理":
                Nshow.setText(str+"菜品管理");
                Dish_Button.setText("菜品信息");
                Shop_Button.setText("菜品添加");
                Userr_Button.setText("菜品删除");
                Record_Button.setText("菜品搜索");
                Exit_Button.setText("返回系统");break;
            case "商家管理":
                //Nshow.setText(str+e.getActionCommand());
                Nshow.setText(str+"商家管理");
                Dish_Button.setText("商家信息");
                Shop_Button.setText("商家添加");
                Userr_Button.setText("商家删除");
                Record_Button.setText("商家搜索");
                Exit_Button.setText("返回系统");break;
            case "用户管理":
                Nshow.setText(str+"用户管理");
                Dish_Button.setText("用户信息");
                Shop_Button.setText("添加用户");
                Userr_Button.setText("删除用户");
                Record_Button.setText("消费记录");
                Exit_Button.setText("返回系统");break;
            case "记录管理":
                Nshow.setText(str+"记录管理");
                Dish_Button.setText("记录信息");
                Shop_Button.setText("添加记录");
                Userr_Button.setText("商家排行");
                Record_Button.setText("用户排行");
                Exit_Button.setText("返回系统");break;
            case "返回系统":
                 Nshow.setText(str+"主界面");
                Dish_Button.setText("菜品管理");
                Shop_Button.setText("商家管理");
                Userr_Button.setText("用户管理");
                Record_Button.setText("记录管理");
                Exit_Button.setText("退出系统");
                C_Panel.removeAll();
                //C_Panel.updateUI();
                C_Panel.repaint();
                break;
            case "菜品信息":
                Dish_Button.setContentAreaFilled(true);
                //Nshow.setText(str+"学生管理");
                Nshow.setText(str+"菜品信息");
                C_Panel.removeAll();
                DishPanel1 sp=new DishPanel1();
                sp.setBounds(0,0,851,500);
                C_Panel.add(sp);
                C_Panel.repaint();break;
            case"菜品添加":
                Userr_Button.setContentAreaFilled(true);
                Nshow.setText(str+"菜品添加");
                //Nshow.setText(str+"学生管理");
                C_Panel.removeAll();
                DishAdd sa=new DishAdd();
                //userAdd sa=new userAdd();
                sa.setBounds(0,0,851,500);
                C_Panel.add(sa);
                C_Panel.repaint();break;
            case "菜品删除":
                Nshow.setText(str+"菜品删除");
                //Nshow.setText(str+"学生管理");
                C_Panel.removeAll();
                DishDel sd=new DishDel();
                sd.setBounds(0,0,851,500);
                C_Panel.add(sd);
                C_Panel.repaint();break;
            case "菜品搜索":
                Nshow.setText(str+"菜品搜索");
                C_Panel.removeAll();
                DishSeach ss=new DishSeach();
                ss.setBounds(0,0,851,500);
                C_Panel.add(ss);
                C_Panel.repaint();break;
            case "商家信息":
                Nshow.setText(str+"商家信息");
                C_Panel.removeAll();
                shopPanel bp=new shopPanel();
                bp.setBounds(0,0,851,500);
                C_Panel.add(bp);
                C_Panel.repaint();break;
            case "商家添加":
                Nshow.setText(str+"商家添加");
                C_Panel.removeAll();
                shopAdd ba=new shopAdd();
                ba.setBounds(0,0,851,500);
                C_Panel.add(ba);
                C_Panel.repaint();break;
            case "商家删除":
                Nshow.setText(str+"商家删除");
                C_Panel.removeAll();
                shopDel bd=new shopDel();
                bd.setBounds(0,0,851,500);
                C_Panel.add(bd);
                C_Panel.repaint();break;
            case "商家搜索":
                Nshow.setText(str+"商家搜索");
                C_Panel.removeAll();
                shopsearch bd1=new shopsearch();
                bd1.setBounds(0,0,851,500);
                C_Panel.add(bd1);
                C_Panel.repaint();break;
            case "用户信息":
                Nshow.setText(str+"用户信息");
                C_Panel.removeAll();
                userPanel bop=new userPanel();
                bop.setBounds(0,0,851,500);
                C_Panel.add(bop);
                C_Panel.repaint();break;
            case "添加用户":
                Nshow.setText(str+"添加用户");
                C_Panel.removeAll();
                userAdd ba1=new userAdd();
                ba1.setBounds(0,0,851,500);
                C_Panel.add(ba1);
                C_Panel.repaint();break;
            case "删除用户":
                Nshow.setText(str+"删除用户");
                C_Panel.removeAll();
                userDel be=new userDel();
                be.setBounds(0,0,851,500);
                C_Panel.add(be);
                C_Panel.repaint();break;
            case "记录信息":
                Nshow.setText(str+"记录信息");
                C_Panel.removeAll();
                recordPanel br=new recordPanel();
                br.setBounds(0,0,851,500);
                C_Panel.add(br);
                C_Panel.repaint();break;
            case "消费记录":
                Nshow.setText(str+"消费记录");
                C_Panel.removeAll();
                userrecord br1=new userrecord();
                br1.setBounds(0,0,851,500);
                C_Panel.add(br1);
                C_Panel.repaint();break;
                
            case "商家排行":
                Nshow.setText(str+"消费记录");
                C_Panel.removeAll();
                shoprank br4=new shoprank();
                br4.setBounds(0,0,851,500);
                C_Panel.add(br4);
                C_Panel.repaint();break;
            case "用户排行":
                Nshow.setText(str+"用户排行");
                C_Panel.removeAll();
                userrank br5=new userrank();
                br5.setBounds(0,0,851,500);
                C_Panel.add(br5);
                C_Panel.repaint();break;
                
            case "添加记录":
                Nshow.setText(str+"添加记录");
                C_Panel.removeAll();
                recordAdd rd=new recordAdd();
                rd.setBounds(0,0,851,500);
                C_Panel.add(rd);
                C_Panel.repaint();break;
                default:System.out.println("default");
        }
    }
    public static void main(String[] args){
        Framework f=new Framework("sa");
    }
}
