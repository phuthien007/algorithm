import math
n,x,y,z=input().split()
n=int(n);x=int(x);y=int(y);z=int(z)
d= y*z / math.gcd(y,z)
if n < d/y :
    print(n)
else:
    print( int(d/y) ) 