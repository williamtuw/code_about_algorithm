N = int(input("请输入一个正整数"))

for a in range(2,N+1):
    for b in range(2,a):
        for c in range(b,a):
            for d in range(c,a):
                if a**3 == b**3 + c**3 + d**3:
                    print("a=%d,b=%d,c=%d,d=%d"%(a,b,c,d))
