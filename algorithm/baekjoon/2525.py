h,m=map(int,input().split())
c=int(input())
if (m+c)>=60:
    if (h+int((m+c)/60)>=24):
        print((h+int((m+c)/60))%24,(m+c)%60)
    elif (h+int((m+c)/60)<24):
        print(h+int((m+c)/60),(m+c)%60)
elif (m+c)<60:
    print(h,m+c)
