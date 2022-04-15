def ducks(n):
    a = 2
    for i in range(0,n):
        a = 2*a+4
    return a
def ducks_recursion(n):
    if n==0:
        return 2
    return 2*ducks_recursion(n-1)+4


if __name__ == '__main__':
    n=1
    while n:
        n = int(input())

        print("iteration:",ducks(n))
        print("recursion:",ducks_recursion(n))
