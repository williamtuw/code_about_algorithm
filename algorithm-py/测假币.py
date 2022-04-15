# 假币问题
def is_fake(char:str,light:bool,left,right,result):
    if light:
        pleft = left
        pright = right
    else:
        pleft = right
        pright = left
    for i in range(3):
        if result[i] == "up":
            if char not in pright[i]:
                return False
        if result[i] == "down":
            if char not in pleft[i]:
                return False
        if result[i] == "even":
            if char in pleft[i] or char in pright[i]:
                return False
    return True

def test():
    N = int(input())
    for i in range(N):
        # 读取三次测量结果
        left, right, result = [],[],[]
        for j in range(3):
            row_left,row_right,row_result = tuple(input().split())
            left.append(row_left)
            right.append(row_right)
            result.append(row_result)
        # 依次假设A-L为假币
        for c in [chr(char) for char in range(65,77)]:
            if is_fake(c,True,left,right,result):
                print(c,"is the counterfeit coin and it is light.")
                break
            elif is_fake(c,False,left,right,result):
                print(c,"is the counterfeit coin and it is heavy.")
                break
test()
