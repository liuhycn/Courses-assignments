package com.Object;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class DishDel extends JPanel {
    private JLabel jl1;
    private JTextField jtf1;
    private JButton jb1;
    public DishDel(){
        setLayout(null);
        jl1=new JLabel("请输入要删除的菜品名");
        jl1.setBounds(300,90,160,20);
        jtf1=new JTextField();
        jtf1.setBounds(330,120,180,25);
        jb1=new JButton("确认");
        jb1.setBounds(340,180,120,30);

        add(jl1);
        add(jtf1);
        add(jb1);
        jb1.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				myConnect m=new myConnect();
				String sql="delete from DISH where Dname='"+jtf1.getText()+"'";
				m.isUpdateOk(sql);
				jtf1.setText("");
			}
        	
        });
    }
}
