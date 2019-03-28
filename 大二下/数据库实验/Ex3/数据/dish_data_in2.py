import pyodbc
import requests
from bs4 import BeautifulSoup
import bs4
import random

def getHTMLText(url):
    try:
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/60.0.3112.101 Safari/537.36',
            'Cookie': '_lxsdk_cuid=15eea339434c8-0d2cff6b34e61c-c313760-100200-15eea339434c8; _lxsdk=15eea339434c8-0d2cff6b34e61c-c313760-100200-15eea339434c8; _hc.v=cec4c6d7-039d-1717-70c0-4234813c6e90.1507167802;\
                s_ViewType=1; __mta=218584358.1507168277959.1507176075960.1507176126471.5; JSESSIONID=48C46DCEFE3A390F647F52FED889020D; aburl=1; cy=2; cye=beijing; _lxsdk_s=15eea9307ab-17c-f87-123%7C%7C48',
           
            'Host': 'www.dianping.com'
        }
        r = requests.get(url, headers=headers )
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        #print(r.text[:1000])
        return r.text
    except:
        return ""


def fillUnivList(ulist, html):
    soup = BeautifulSoup(html, 'html.parser')
    for tr in soup.find_all(attrs={'class':"shop-food-con"}):
        if isinstance(tr, bs4.element.Tag):
            tds = tr('div')
            ulist.append([tds[0].string, tds[1].string])


def printUnivList(ulist, num,c):
    tplt = "{:4}\t{:8}\t"
    for i in range(num):
        u = ulist[i]
        a = random.randint(40,80)
        c.execute("insert into DISH(Dno,Dname,Dprice,Dpf,Sno) VALUES(?,?,?,?,'S0002')",str(i+12),u[0],a,eval(u[1][0]))
        c.commit()          
        print(tplt.format(u[0], u[1], chr(12288)))
    # print("Suc"+str(num))


def main(cc):
    depth=5
    uinfo = []
    start_url = 'http://www.dianping.com/shop/19111165/dishlist/p'
    for i in range(1,depth):
        try:
            url = start_url + str(i)
            
            html = getHTMLText(url)
            fillUnivList(uinfo, html)
            printUnivList(uinfo, 100,cc)  # 20 univs
        except:
            continue


if __name__ == '__main__':
    cnxn = pyodbc.connect('DRIVER={ODBC Driver 17 for SQL Server};SERVER=localhost;DATABASE=Ex3;UID=sa;PWD=123456')
    cursor = cnxn.cursor()
    main(cursor)
    #row = cursor.fetchone() 
    #while row: 
        #print (row[1]) 
        #row = cursor.fetchone()
