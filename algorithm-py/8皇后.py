def nQueen(Q, cur=0):
    if cur == len(Q):
        print(Q)
        return 0
    for i in range(len(Q)):
        for j in range(cur):
            if i == Q[j] or abs(i - Q[j]) == abs(cur - j):
                break
        else:
            Q[cur] = i
            nQueen(Q, cur + 1)


nQueen([None] * 8, 0)
