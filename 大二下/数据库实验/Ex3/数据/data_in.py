import pyodbc

cnxn = pyodbc.connect('DRIVER={ODBC Driver 17 for SQL Server};SERVER=localhost;DATABASE=Ex3;UID=sa;PWD=123456')
cursor = cnxn.cursor()
cursor.execute("insert into SELLERS(Sname,Sno,Saddr,Ssect,Sclass) VALUES('大渔铁板烧','S0001','五四路126号王府井百货负一楼B1GN03号铺','日韩菜系',4)")
cursor.execute("insert into SELLERS(Sname,Sno,Saddr,Ssect,Sclass) VALUES('海底捞火锅','S0002','杨桥东路8号东方百货7层','火锅',3)")
cursor.execute("insert into SELLERS(Sname,Sno,Saddr,Ssect,Sclass) VALUES('东北家常菜','S0003','通湖路129-5','家常菜',3)")
cursor.execute("insert into SELLERS(Sname,Sno,Saddr,Ssect,Sclass) VALUES('凯宾斯基酒店','S0004','横屿路1号福州泰禾凯宾斯基酒店1F','自助餐',5)")
cursor.execute("insert into SELLERS(Sname,Sno,Saddr,Ssect,Sclass) VALUES('Hunt season','S0005','白马支路与西洋路交叉口万科里广场内','西餐',4)")

cursor.commit()

cursor.execute("insert into  USERS(Uno,Uacnt,Usex,Uname,Ucredit) VALUES('U0001','aaa','男','牛二',2)")
cursor.execute("insert into  USERS(Uno,Uacnt,Usex,Uname,Ucredit) VALUES('U0002','bbb','男','张三',3)")
cursor.execute("insert into  USERS(Uno,Uacnt,Usex,Uname,Ucredit) VALUES('U0003','ccc','女','李四',4)")
cursor.execute("insert into  USERS(Uno,Uacnt,Usex,Uname,Ucredit) VALUES('U0004','ddd','男','王五',5)")

cursor.commit()

cursor.execute("insert into  S_CARD(Uno,Cno,Cpassword,Cbalance,Cclass,Cdiscount) VALUES('U0001','C0001','qweert',1000.5,2,0.9)")
cursor.execute("insert into  S_CARD(Uno,Cno,Cpassword,Cbalance,Cclass,Cdiscount) VALUES('U0002','C0002','asdfgt',194985,4,0.7)")
cursor.execute("insert into  S_CARD(Uno,Cno,Cpassword,Cbalance,Cclass,Cdiscount) VALUES('U0003','C0003','ijfddf',5555582,5,0.6)")
cursor.execute("insert into  S_CARD(Uno,Cno,Cpassword,Cbalance,Cclass,Cdiscount) VALUES('U0004','C0004','df485d',1.2,1,1)")

cursor.commit()

cursor.execute("insert into  RECORD(Uno,Sno,Rno,Rdate,Rsum) VALUES('U0001','S0003','R0001','2018年6月1日',125)")
cursor.execute("insert into  RECORD(Uno,Sno,Rno,Rdate,Rsum) VALUES('U0002','S0002','R0002','2018年7月1日',123)")
cursor.execute("insert into  RECORD(Uno,Sno,Rno,Rdate,Rsum) VALUES('U0003','S0004','R0003','2018年6月13日',518)")

cursor.commit()
