
def hanoi(n, a, b, c):
    if n == 1:
        print(a, 'to', b)
    else:
        hanoi(n - 1, a, c, b)
        hanoi(1, a, b, c)
        hanoi(n - 1, c, b, a)
    return 0

hanoi(3,'1','2','3')
