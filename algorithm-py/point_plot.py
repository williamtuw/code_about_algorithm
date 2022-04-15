import math

from matplotlib.pyplot import scatter
import matplotlib.pyplot as plt

def dichotomy(a,b,f,e):
    """
    # 二分法
    :param a: 左边界
    :param b: 右边界
    :param f: 一元函数
    :param e: error
    :return: 返回x使得f(x)==0

    """
    # 如果f(a) f(b) 在同一侧则不符合条件
    if f(a)*f(b)>0:
        return None
    i = (a+b)/2
    while abs(f(i))>e :
        if f(a)*f(i)>0:
            a=  i
        else:
            b = i
        i = (a + b) / 2
    return i

# 定值


# 原函数
def func(kx,ky,t1,t2,u):
    return -2*t1*(math.cos(kx)+math.cos(ky))-4*t2*math.cos(kx)*math.cos(ky)-u

# 将二元函数转为一元函数
def func2(x0,t1,t2,u):
    return lambda y:func(x0,y,t1,t2,u)

def get_point(point_num,e,t1,t2,u):
    ls_x = []
    ls_y = []
    with open("rst.txt", "a", encoding="utf-8")as fp:
        # 扫描x 轴获取对应y
        for x in [i * math.pi / point_num for i in range(-point_num, point_num+1)]:
            # 此时x固定可将 二元函数转成一元函数，再通过dichotomy二分法获取y
            # 因为函数关于x对称所以y分成两段，最多同一个x得到两个y,但并不能确定找到所有的点
            # 要找到所有点请分析函数做出对应的分段
            y1 = dichotomy(-1 * math.pi, 0, func2(x,t1,t2,u), e)
            y2 = dichotomy(0, math.pi, func2(x,t1,t2,u), e)
            if y1:
                fp.write("%.4f %.4f\n" % (x, y1))
                ls_x.append(x)
                ls_y.append(y1)
            if y2:
                fp.write("%.4f %.4f\n" % (x, y2))
                ls_x.append(x)
                ls_y.append(y2)
        for y in [i * math.pi / point_num for i in range(-point_num, point_num+1)]:
            # 此时x固定可将 二元函数转成一元函数，再通过dichotomy二分法获取y
            # 因为函数关于x对称所以y分成两段，最多同一个x得到两个y,但并不能确定找到所有的点
            # 要找到所有点请分析函数做出对应的分段
            x1 = dichotomy(-1 * math.pi, 0, func2(y,t1,t2,u), e)
            x2 = dichotomy(0, math.pi, func2(y,t1,t2,u), e)
            if x1:
                fp.write("%.4f %.4f\n" % (x1,y))
                ls_x.append(x1)
                ls_y.append(y)
            if x2:
                fp.write("%.4f %.4f\n" % (x2,y))
                ls_x.append(x2)
                ls_y.append(y)
    return ls_x,ls_y
if __name__ == '__main__':
    point_group_ls = []
    for i in range(-1,2):
        group = get_point(100,1e-6,1,0,i)
        point_group_ls.append((group,"u=%d"%(i,)))

    for group in point_group_ls:
        scatter(*group[0],label=group[1])

    plt.legend()
    plt.show()



