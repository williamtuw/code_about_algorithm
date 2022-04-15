first_line = input()
k = int(first_line.split()[-1])
second_line = input()
numbers = [int(i) for i in second_line.split()]
n = len(numbers)-1
for i in range(k):
    for j in range(len(numbers)-i):
        numbers[n-j] = numbers[n-j-1]*(j+1)%998244353
    numbers[i] = 0

for i in range(n+1):
    if i!=n:
        print(numbers[i],end=" ")
    else:
        print(numbers[i])
