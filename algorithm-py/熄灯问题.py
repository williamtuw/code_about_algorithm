# 熄灯问题
def output_lights(lights):
    for i in range(len(lights)):
        light = "%6s" % bin(lights[i]).replace("0b", "")
        for j in range(len(light)):
            if light[j] == " ":
                print(0, end="")
            else:
                print(light[j], end="")
            if j < 5:
                print(" ", end="")
        if i < 5:
            print()


def get_bit(num, i):
    return (num >> i) & 1


def set_bit(num, i, value):
    if value:
        return (1 << i) | num
    else:
        return ~(1 << i) & num


def filp(num, i):
    return (1 << i) ^ num


def main():
    origin_lights = []
    result_lights = [""]*5

    # 读入原始数据
    for i in range(5):
        origin_lights.append(int(input().replace(" ", ""), 2))
    # output_lights(origin_lights)
    for num in range(64):
        # 枚举每一种情况
        switchs = num
        lights = list(origin_lights)
        for i in range(len(lights)):
            result_lights[i] = switchs
            for j in range(6):
                if get_bit(switchs, j):
                    if j > 0:
                        lights[i] = filp(lights[i], j - 1)
                    lights[i] = filp(lights[i], j)
                    if j < 5:
                        lights[i] = filp(lights[i], j + 1)
            if i < 4:
                lights[i+1] ^= switchs
            switchs = lights[i]

            # bin_switchs = "%6s" % bin(switchs).replace("0b", "")
            # for c in bin_switchs:
            #     if c == " ":
            #         print(0," ", end="")
            #     else:
            #         print(c," ",end="")
            # print()
            # output_lights(lights)
        if lights[-1] == 0:
            output_lights(result_lights)
            break

main()
