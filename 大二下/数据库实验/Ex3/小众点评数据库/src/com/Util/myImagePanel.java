package com.Util;


import javax.swing.*;
import java.awt.*;

public class myImagePanel extends JPanel {
    ImageIcon icon;
    Image img;
    public myImagePanel(String url) {
        //  /img/HomeImg.jpg 是存放在你正在编写的项目的bin文件夹下的img文件夹下的一个图片
        icon=new ImageIcon(getClass().getResource(url));
        img=icon.getImage();
    }
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        //下面这行是为了背景图片可以跟随窗口自行调整大小，可以自己设置成固定大小
        g.drawImage(img, 0, 0,this.getWidth(), this.getHeight(), this);
    }
    public static void main(String[] args){
        JFrame f=new JFrame();
        f.setBounds(0,0,500,400);
        f.setLayout(null);
        myImagePanel i=new myImagePanel("/img/1.jpg");
        i.setBounds(0,0,400,330);
        f.add(i);
        f.setVisible(true);
    }
}
