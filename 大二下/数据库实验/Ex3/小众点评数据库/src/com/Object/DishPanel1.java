package com.Object;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
//import javax.swing.table.JTableHeader;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.sql.*;

public class DishPanel1 extends JScrollPane {
    //private JPanel look;

    //private CardLayout Card;
    private String url = "jdbc:sqlserver://127.0.0.1:1433;DatabaseName=Ex3;";
    private Connection conn;
    //private JScrollPane scpDemo;
    // private JTableHeader jth;
    private JTable jtb;
    private DefaultTableModel model;
    private JPopupMenu popupMenu;
    private JMenuItem  Insert, Delete, Update;
    //private Connection conn;
    public DishPanel1() {

        //super();
        //System.out.print("hello");
        //look=new JPanel();
        // Card=new CardLayout();
        // setLayout(null);
        //look.setSize(880,530);
        // look.add(scpDemo);
        // CardLayout card=new CardLayout();
        //setLayout(null);
        // scpDemo=new JScrollPane();
        // scpDemo.setBounds(0,0,880,500);
        //add(scpDemo);
        popupMenu=new JPopupMenu();
        Insert = new JMenuItem("添加");
        Insert.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
            }
        });
        Delete = new JMenuItem("删除");
        Delete.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int Row=jtb.getSelectedRow();
               // int row=jtb.getSelectedRow();
                //int col=jtb.getSelectedColumn();
                //String sql1="delete from Reader where ID="+jtb.getValueAt(Row,0);
                //System.out.print(sql1);
                delete_run(Row);
                model.removeRow(Row);
            }
        });
        Update = new JMenuItem("更新");
        popupMenu.add(Insert);
        popupMenu.add(Delete);
        popupMenu.add(Update);
        try {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            conn = DriverManager.getConnection(url, "sa", "123456");
            String sql = "select Dname,Dno,Dprice,Dpf,DISH.Sno,Sname from DISH,SELLERS WHERE DISH.Sno=SELLERS.Sno";
            PreparedStatement pstm = conn.prepareStatement(sql);
            ResultSet rs = pstm.executeQuery();
            int count = 0;
            while (rs.next()) {
                count++;
            }
            rs = pstm.executeQuery();
            Object[][] info = new Object[count][6];
            count = 0;
            while (rs.next()) {
                info[count][0] = rs.getString("Dname");
                info[count][1] = rs.getString("Dno");
                info[count][2] = rs.getString("Dprice");
                info[count][3] = rs.getString("Dpf");
                info[count][4] = rs.getString("Sno");
                info[count][5] = rs.getString("Sname");
                //info[count][4]=rs.getInt("Number");
                count++;
            }
            String[] title = {"菜品名", "菜品号", "价格","好评数", "所在商家号","商家名"};
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
            getViewport().add(jtb);
            jtb.addMouseListener(new MouseListener() {
                @Override
                public void mouseClicked(MouseEvent e) {
                       if(e.getButton()==MouseEvent.BUTTON3){
                           int focusedRowIndex = jtb.rowAtPoint(e.getPoint());
                           if (focusedRowIndex == -1) {
                               return;
                           }
                           jtb.setRowSelectionInterval(focusedRowIndex, focusedRowIndex);
                           popupMenu.show(jtb, e.getX(), e.getY());
                       }
                }
                @Override
                public void mousePressed(MouseEvent e) { }
                @Override
                public void mouseReleased(MouseEvent e) { }
                @Override
                public void mouseEntered(MouseEvent e) { }
                @Override
                public void mouseExited(MouseEvent e) {
                }
            });

        } catch (ClassNotFoundException cnfe) {
            JOptionPane.showMessageDialog(null, "数据源错误", "错误", JOptionPane.ERROR_MESSAGE);
            cnfe.printStackTrace();
        } catch (SQLException se) {
            JOptionPane.showMessageDialog(null, "数据操作错误", "错误", JOptionPane.ERROR_MESSAGE);
            se.printStackTrace();
        }
    }
    public void delete_run(int r){
        try{
            String sql="delete from Reader where ID="+"'"+jtb.getValueAt(r,0)+"'";
            PreparedStatement pstm = conn.prepareStatement(sql);
            pstm.executeUpdate();
        }catch (SQLException s){
            s.printStackTrace();
        }
    }
}

