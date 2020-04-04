n = int(input())
for j in range(1,n+1):
    str = list(input())
    str.insert(0,0)
    str.append(0)
    d = list(str)
    c=0
    for i in range(len(str)-1):
        
        if(int(str[i+1])>int(str[i])):
            d.insert(i+1+c,"("*(int(str[i+1])-int(str[i])))
            c+=1
        elif(int(str[i])>int(str[i+1])):
            d.insert(i+1+c,")"*(int(str[i])-int(str[i+1])))
            c+=1
    d=d[1:len(d)-1]

    print( "Case #{}: {}".format( j, "".join(d)))

