package com.Object;

import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class recordAdd extends JPanel {
	private JTextField t1;
	private JTextField t2;
	private JTextField t3;
	private JTextField t4;
	private JTextField t5;

	/**
	 * Create the panel.
	 */
	public recordAdd() {
		setLayout(null);
		
		JLabel lblNewLabel = new JLabel("用户号");
		lblNewLabel.setBounds(358, 71, 58, 15);
		add(lblNewLabel);
		
		t1 = new JTextField();
		t1.setBounds(469, 68, 148, 21);
		add(t1);
		t1.setColumns(10);
		
		JLabel lblNewLabel_1 = new JLabel("商家号");
		lblNewLabel_1.setBounds(358, 136, 58, 15);
		add(lblNewLabel_1);
		
		JLabel lblNewLabel_2 = new JLabel("记录号");
		lblNewLabel_2.setBounds(358, 197, 58, 15);
		add(lblNewLabel_2);
		
		JLabel lblNewLabel_3 = new JLabel("消费时间");
		lblNewLabel_3.setBounds(358, 255, 58, 15);
		add(lblNewLabel_3);
		
		JLabel lblNewLabel_4 = new JLabel("消费金额");
		lblNewLabel_4.setBounds(358, 313, 58, 15);
		add(lblNewLabel_4);
		
		t2 = new JTextField();
		t2.setBounds(469, 133, 148, 21);
		add(t2);
		t2.setColumns(10);
		
		t3 = new JTextField();
		t3.setBounds(469, 194, 148, 21);
		add(t3);
		t3.setColumns(10);
		
		t4 = new JTextField();
		t4.setBounds(469, 252, 148, 21);
		add(t4);
		t4.setColumns(10);
		
		t5 = new JTextField();
		t5.setBounds(469, 310, 148, 21);
		add(t5);
		t5.setColumns(10);
		
		JButton btnNewButton = new JButton("确定");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				myConnect m=new myConnect();
				String sql="insert into RECORD VALUES('"+t1.getText()+"','"+t2.getText()+"','"+t3.getText()+"','"+t4.getText()+"',"+t5.getText()+") UPDATE USERS SET Ucredit=Ucredit+1 WHERE Uno='"+t1.getText()+"'";
				System.out.println(sql);
				m.isUpdateOk(sql);
				t1.setText("");
				t2.setText("");
				t3.setText("");
				t4.setText("");
				t5.setText("");
			}
		});
		btnNewButton.setBounds(432, 373, 97, 23);
		add(btnNewButton);

	}
}
