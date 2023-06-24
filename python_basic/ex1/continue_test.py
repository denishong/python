count=0

while count < 10:
    count +=1
    if count < 4:
        continue

    print('count:', count)
    if count == 8:
        break
