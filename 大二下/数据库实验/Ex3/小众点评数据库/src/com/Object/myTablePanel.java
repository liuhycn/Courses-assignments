package com.Object;

import com.microsoft.sqlserver.jdbc.SQLServerException;

import javax.swing.*;
import javax.swing.event.TableModelEvent;
import javax.swing.event.TableModelListener;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.sql.*;

public class myTablePanel extends JScrollPane implements ActionListener ,MouseListener{
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private DefaultTableModel model;
    private JTable table;
    private PreparedStatement ps;
    private JMenuItem delete,setting,smaller,larger;
    private Connection con;
    private  JPopupMenu pop;
    private String ID,tablename="reader";
    private Font myfont=new Font("微软雅黑",0,14);
    private int count=0;
    //传入sql server语句
    public myTablePanel(String sql){
        init();
        createTable(sql);
    }
    //只创建
    public myTablePanel() {init(); }
    //传入表的名称
    public void setTableName(String tableName){
        this.tablename=tableName;
    }
    //连接函数返回connection
    private Connection getConnection(){
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
    //按钮控件
    public void init(){
        con=getConnection();
        model=new DefaultTableModel(){
        	
            /**
			 * 
			 */
			private static final long serialVersionUID = 1L;
           
			@Override
            public boolean isCellEditable(int row,int column){
				if(table.getSelectedRow()==row && column==table.getSelectedColumn()) {
					return true;
				}
                return false;
            }
        };
        model.addTableModelListener(new TableModelListener() {

			@Override
			public void tableChanged(TableModelEvent e) {
				// TODO Auto-generated method stub
				if(e.getType()==TableModelEvent.UPDATE) {
					if(e.getFirstRow()!=-1) {
					update_Table(e.getFirstRow(),e.getColumn());
					}
				}
			}
        });
        pop=new JPopupMenu();
        delete=new JMenuItem("删除");
        setting=new JMenuItem("更改");
        larger=new JMenuItem("字体放大");
        smaller=new JMenuItem("字体缩小");
       pop.add(delete);
        pop.add(setting);
        pop.add(larger);
        pop.add(smaller);
       delete.addActionListener(this);
        delete.setFont(myfont);
        setting.addActionListener(this);
        setting.setFont(myfont);
        larger.setFont(myfont);
        larger.addActionListener(this);
        smaller.setFont(myfont);
        smaller.addActionListener(this);
    }
  //  执行sql server语句
    public void createTable(String sql){
        try{
            ps=con.prepareStatement(sql);
            ResultSet rs=ps.executeQuery();
            ResultSetMetaData rsmd=rs.getMetaData();
            int titlecount=rsmd.getColumnCount();
            String title[]=new String[titlecount];
            for(int i=1;i<=titlecount;i++){
                title[i-1]=rsmd.getColumnName(i);
            }
            ID=title[0];
            count=0;
            while (rs.next()){
                count++;
            }
            if(count==0)
                JOptionPane.showMessageDialog(null,"信息不存在","错误",JOptionPane.ERROR_MESSAGE);
            else {
                Object [][]ob=new Object[count][titlecount];
                rs=ps.executeQuery();
                count=0;
                while (rs.next()){
                    for(int i=0;i<titlecount;i++){
                        ob[count][i]=rs.getString(title[i]);
                    }
                    count++;
                }
               model.setDataVector(ob,title);
//                model=new DefaultTableModel(ob,title){
//                	
//                    /**
//					 * 
//					 */
//					private static final long serialVersionUID = 1L;
//                   
//					@Override
//                    public boolean isCellEditable(int row,int column){
//						if(row==table.getRowCount() && column==table.getColumnCount()) {
//							return true;
//						}
//                        return false;
//                    }
//                };
                table=new JTable(model);
                table.addMouseListener(this);
                getViewport().add(table);
            }
        }catch (SQLException se){
            se.printStackTrace();
        }
    }
    //设置表字体
    public void setTabelFont(String str,int s,int size){
        table.setFont(new Font(str,s,size));
    }
    //设置表的高度
    public void setTableRowHeight(int height){
        table.setRowHeight(height);
    }
    //设置数值在中间
   // public int n=JTable.CENTER_ALIGNMENT;
    public void setTableCenter(int n){
        DefaultTableCellRenderer r=new DefaultTableCellRenderer();
        r.setHorizontalAlignment(n);
        table.setDefaultRenderer(Object.class,r);
    }
    //设置表头
    public void setTableHeader(){
        table.getTableHeader().setBackground(Color.decode("#F5F5DC"));
        table.getTableHeader().setReorderingAllowed(false);
        table.getTableHeader().setFont(new Font("微软雅黑",0,14));
    }

    //设置奇偶行颜色不同
    public void setRow(){
        makeFace(table);
    }
    public static void makeFace(JTable table) {
        try {
            DefaultTableCellRenderer tcr = new DefaultTableCellRenderer() {
                /**
				 * 
				 */
				private static final long serialVersionUID = 1L;

				public Component getTableCellRendererComponent(JTable table,
                                                               Object value, boolean isSelected, boolean hasFocus,
                                                               int row, int column) {
                    if (row % 2 == 0)
                        setBackground(Color.white); // 设置奇数行底色
                    else if (row % 2 == 1)
                        setBackground(new Color(206, 231, 255)); // 设置偶数行底色
                    return super.getTableCellRendererComponent(table, value,
                            isSelected, hasFocus, row, column);
                }
            };
            for (int i = 0; i < table.getColumnCount(); i++) {
                table.getColumn(table.getColumnName(i)).setCellRenderer(tcr);
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
    //按钮事件
    @Override
    public void actionPerformed(ActionEvent e){
        switch (e.getActionCommand()){
            case "删除":
                delete_row(tablename);break;
            case "更改":
            	model.isCellEditable(1, 1);break;
        }
       
    }
    //表格右键
    @Override
    public void mouseClicked(MouseEvent e) {
    	//String pre=table.getValueAt(table.getSelectedRow(), table.getSelectedColumn()).toString();
        if(e.getButton()==MouseEvent.BUTTON3){
            pop.show(table,e.getX(),e.getY());
        }
    }
    @Override
    public void mousePressed(MouseEvent e) {
    }
    @Override
    public void mouseReleased(MouseEvent e) {
    }
    @Override
    public void mouseEntered(MouseEvent e) {
    }
    @Override
    public void mouseExited(MouseEvent e) {
    }

    //返回表格
    public JTable getTable(){
        return this.table;
    }
    //获取所选行的第一个值
    public String getSelectRowID(){
        return table.getValueAt(table.getSelectedRow(),0).toString();
    }
    //删除所选行的值
    public void delete_row(String tablename){
        try{
            String sql="delete from "+tablename+" where "+ID+"= "+table.getValueAt(table.getSelectedRow(),0);
            ps=con.prepareStatement(sql);
            if(ps.executeUpdate()==1){
                model.removeRow(table.getSelectedRow());
            }
        }catch (SQLServerException sse){
            JOptionPane.showMessageDialog(null,sse.getLocalizedMessage(),"错误",JOptionPane.ERROR_MESSAGE);
        } catch (SQLException e){
            e.printStackTrace();
        }
    }
    public void update_Table(int row,int column) {
    	try{
            String sql="update "+tablename+" set "+table.getColumnName(column)+"="+table.getValueAt(row, column)+" where "+
    	table.getColumnName(0)+" = "+table.getValueAt(table.getSelectedRow(), 0);
           
            ps=con.prepareStatement(sql);               
            ps.executeUpdate();
        }catch (SQLServerException sse){
            JOptionPane.showMessageDialog(null,sse.getLocalizedMessage(),"错误",JOptionPane.ERROR_MESSAGE);
        } catch (SQLException e){
        	JOptionPane.showMessageDialog(null,e.getLocalizedMessage(),"错误",JOptionPane.ERROR_MESSAGE);
            e.printStackTrace();
        }
    }
//    public static void main(String[] args){
//        JFrame f=new JFrame();
//        f.setSize(700,600);
//        f.setLocationRelativeTo(null);
//        f.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
//        JPanel j=new JPanel();
//        myTablePanel m=new myTablePanel("select * from Reader");
//        m.setTabelFont("微软雅黑",0,16);
//        m.setTableRowHeight(20);
//        j.setSize(450,450);
//        j.add(m);
//        f.add(m);
//        f.setVisible(true);
//    }
}
