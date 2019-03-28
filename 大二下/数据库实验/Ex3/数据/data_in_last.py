import pyodbc

cnxn = pyodbc.connect('DRIVER={ODBC Driver 17 for SQL Server};SERVER=localhost;DATABASE=Ex3;UID=sa;PWD=123456')
cursor = cnxn.cursor()

cursor.execute("insert into  ABSTRACT(Rno,Dno,Acnt) VALUES('R0001','25','1')")
cursor.execute("insert into  ABSTRACT(Rno,Dno,Acnt) VALUES('R0001','28','1')")
cursor.execute("insert into  ABSTRACT(Rno,Dno,Acnt) VALUES('R0001','30','1')")

cursor.execute("insert into  ABSTRACT(Rno,Dno,Acnt) VALUES('R0002','14','2')")
cursor.execute("insert into  ABSTRACT(Rno,Dno,Acnt) VALUES('R0002','19','1')")

cursor.execute("insert into  ABSTRACT(Rno,Dno,Acnt) VALUES('R0003','38','2')")
cursor.execute("insert into  ABSTRACT(Rno,Dno,Acnt) VALUES('R0003','39','3')")

cursor.commit()
