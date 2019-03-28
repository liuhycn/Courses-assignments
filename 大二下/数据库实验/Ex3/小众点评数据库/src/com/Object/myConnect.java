package com.Object;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public  class myConnect {
	public myConnect() {}
	public Connection getConnection() {
		Connection con=null;
        try{
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            con=DriverManager.getConnection("jdbc:sqlserver://127.0.0.1:1433;DatabaseName=Ex3;","sa","123456");
            // System.out.print("数据库连接成功");
        }catch (ClassNotFoundException cnfe){
            System.out.print("数据源错误");
            cnfe.printStackTrace();
        }catch (SQLException se){
            System.out.print("数据错误");
            se.printStackTrace();
        }
        return con;
	}
	public int isSqlserverOk(String sql) {
		int temp=0;
		try {
			Connection con=getConnection();
			PreparedStatement pstm=con.prepareStatement(sql);
			ResultSet rs=pstm.executeQuery();
			int count=0;
			while(rs.next()) {
				count++;
			}
			if(count!=0)
				temp=1;
			con.close();
			pstm.close();
		}catch(Exception e) {
			e.printStackTrace();
		}
		return temp;
	}
	public int isUpdateOk(String sql) {
		int t=0;
		try {
			Connection con=getConnection();
			PreparedStatement pstm=con.prepareStatement(sql);
			t=pstm.executeUpdate();
			con.close();
			pstm.close();
		}catch(Exception e) {
			e.printStackTrace();
		}
	
		return t;
	}
	public int max_borrow_ID() {
		int t=0;
		try {
			Connection con=getConnection();
			String sql="select max(Borrow_ID) from Borrow";
			PreparedStatement pstm=con.prepareStatement(sql);
			ResultSet rs=pstm.executeQuery();
			while(rs.next()) {
				t=rs.getInt(1);
			}
			con.close();
			pstm.close();
		}catch(Exception e) {
			e.printStackTrace();
		}
		return t;
	}
}
