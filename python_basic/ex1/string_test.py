aa=['    "machine":"O22N",', '    "region":"GLOBAL",', '    "sdpproductid":"webOSTV 23"']
bb=[]
for a in aa:
    bb.append(a.strip())
    bb.append(a.rstrip(','))
dd=[]
for c in bb:
    dd+=c.split(':')
list=[]
for d in dd:
    list.append(d.strip('"'))
print(list)

dict = {list[i]: list[i + 1] for i in range(0, len(list), 2)}
print(dict)
print(dict.get('machine'))
