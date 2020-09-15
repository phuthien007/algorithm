# ham xoa nhung o khong thoa man theo cot hoac hang
def Fill1(res,x,y):
    for i in range(len(res)):
        for j in range(len(res[i])):
            if i==x or j==y:
                res[i][j]='X'
# ham xoa nhung o khong thoa man theo cac duong cheo
def Fill2(res,i,j,n,m):
    temp1=i;temp2=j
    while temp1>0 and temp2>0:
        if res[temp1-1][temp2-1] !='X':
            res[temp1-1][temp2-1] = 'X'
        temp1-=1;temp2-=1
    temp1 = i;temp2 = j
    while temp1+1 < n and temp2+1 <m:
        if res[temp1+1][temp2+1] != 'X':
            res[temp1+1][temp2+1] = 'X'
        temp1+=1;temp2+=1
    temp1 = i;temp2 = j
    while temp1+1<n and temp2>0:
        if res[temp1+1][temp2-1]!='X':
            res[temp1+1][temp2-1]='X'
        temp1+=1;temp2-=1
    temp1 = i;temp2 = j
    while temp1>0 and temp2+1<m:
        if res[temp1-1][temp2+1] != 'X':
            res[temp1-1][temp2+1]='X'
        temp1-=1;temp2+=1
# 2 ham Try la ham dat thu quan hau xem con nao chiem nhieu o nhat
def Try1(res,x,y,count):
    for i in range(len(res)):
        for j in range(len(res[i])):
            if i==x or j==y:
                count+=1
    return count
def Try2(res,i,j,n,m,count):
    temp1=i;temp2=j
    while temp1>0 and temp2>0:
        if res[temp1-1][temp2-1] !='X':
            count+=1
        temp1-=1;temp2-=1
    temp1 = i;temp2 = j
    while temp1+1 < n and temp2+1 <m:
        if res[temp1+1][temp2+1] != 'X':
            count += 1
        temp1+=1;temp2+=1
    temp1 = i;temp2 = j
    while temp1+1<n and temp2>0:
        if res[temp1+1][temp2-1]!='X':
            count += 1
        temp1+=1;temp2-=1
    temp1 = i;temp2 = j
    while temp1>0 and temp2+1<m:
        if res[temp1-1][temp2+1] != 'X':
            count += 1
        temp1-=1;temp2+=1
    return count
#kiem tra xem con o trong khong
def Check(res):
    for i in res:
        for j in i:
            if j == '*':
                return False
    return True
if __name__=="__main__":
    res=[]
    count=0
    n,m=input().split()
    n=int(n);m=int(m)
    for i in range(n):
        temp=[]
        for j in range(m):
            temp.append('*')
        res.append(temp)
    if n!=m:
        Fill1(res,0, 0)
        Fill2(res, 0, 0, n, m)
        res[0][0]='Q'
        while Check(res)==False:
            mx=0;lx=0;ly=0
            for i in range(len(res)):
                for j in range(len(res[i])):
                    if res[i][j]=='*':
                        count=0
                        count=Try1(res,i,j,count)
                        count=Try2(res,i,j,n,m,count)
                        if mx <= count:
                            mx=count
                            lx=i;ly=j
            Fill1(res,lx,ly)
            Fill2(res,lx,ly,n,m)
            res[lx][ly]='Q'
    else:
        for i in range(len(res)):
            for j in range(len(res[i])):
                if res[i][j] == '*':
                    Fill1(res, i, j)
                    Fill2(res, i, j, n, m)
                    res[i][j] = 'Q'
    result=0
    for i in res:
        for j in i:
            if j=='Q':
                result+=1
            print(j,end=' ')
        print()
    print('C1=',result)
    # cach khac
    if n >=m:
        n,m=m,n
    if n<=m<=2*n:
        print('C2=', n//2+1)
    else: print('C2=',n)
'''
co cong thuc gan dung min(n,m)/2 +1
nhung 1 so truong hop dac biet chua xet het 
Test 
INPUT: n=m=8
OUTPUT: 5
INPUT: n=3, m=5
OUTPUT: 2
'''
