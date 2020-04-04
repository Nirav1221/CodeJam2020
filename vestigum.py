n = int(input())
import numpy as np
for i in range(1,n+1):
    repCol=0
    repRow=0
    trace=0
    N = int(input())
    mat = [[]*N]*N
    for j in range(N):
        mat[j]=[int(x) for x in input().split()]
        trace+=mat[j][j]
        if len(set(mat[j]))!=N:
            repRow+=1
    for j in range(N):
        l =[]
        for k in range(N):
            l.append(mat[k][j])
        if ( len(set(l))!=N):
            repCol+=1


    print("Case #{}: {} {} {}".format(i,trace,repRow,repCol))
