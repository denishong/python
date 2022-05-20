a,b,c=map(int,input().split())
if a==b==c:
    print(10000+int(a)*1000)
elif a==b:
    print(1000+int(a)*100)
elif c==b:
    print(1000+int(b)*100)
elif c==a:
    print(1000+int(a)*100)
else: 
    print(max(a,b,c)*100)
