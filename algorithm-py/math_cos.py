import math

if __name__ == '__main__':
    while True:
        temp = input("输入x ")
        if temp=="exit":
            break
        try:
            x = float(temp)
            print("cos x = %.4f"%math.cos(x))
        except TypeError:
            print("请输入一个小数!")
    print("end")