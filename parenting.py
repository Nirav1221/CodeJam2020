N = int(input())
for i in range(1,N+1):
    n = int(input())
    SB=[]
    SE=[]
    AS=[]

    AE=[]
    BS=[]
    BE=[]
    o=""
    for k in range(n):
        s = input().split()
        SB.append(int(s[0]))
        SE.append(int(s[1]))
    
    #Read complete.
    #Insert each element
    for k in range(n):
        
        
        #A and B are non empty
        #Insert in aa
        for a in range( len(AS) ):
            if(SB[k]>AS[a] and SB[k] < AE[a] or SE[k]> AS[a] and SE[k] < AE[a]):# SB or SE between any range
                break
        else:
            AS.append(SB[k])
            AE.append(SE[k])
            o+='C'
            continue
        #Insert in B
        for a in range( len(BS) ):
            if(SB[k]>BS[a] and SB[k]< BE[a] or SE[k]>BS[a] and SE[k]< BE[a]):
                break
        else:
            BS.append(SB[k])
            BE.append(SE[k])
            o+='J'
            continue
        o='IMPOSSIBLE'
        break
    print("Case #{}: {}".format(i,o))