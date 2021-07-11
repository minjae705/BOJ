from math import gcd
from itertools import combinations
for i in range(int(input())):
    tc=list(map(int,input().split()))
    tc=tc[1:]
    com=list(combinations(tc,2))
    ts=0
    for j in com:
        ts+=gcd(j[0],j[1])
    print(ts)
