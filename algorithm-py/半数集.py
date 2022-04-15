SET = [0 for i in range(1001)]
SET[1]=1
def halfnumset(n):
    if SET[n]:
        return SET[n]
    if n==1:
        return 1
    count = 0
    for i in range(1,n//2+1):
        count+=halfnumset(i)
    SET[n]=1+count
    return 1+count
n = int(input())
print('result:',halfnumset(n))