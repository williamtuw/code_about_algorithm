# true 吹 false 吸
map_dict = {"5--":True,"1-":True,"2-":False,"3-":True,"4-":False,"5-":True,"6-":False,"7-":False,
            "1":True,"2":False,"3":True,"4":False,"5":True,"6":False,"7":False,
            "1+": True, "2+": False, "3+": True, "4+": False, "5+": True, "6+": False, "7+": False,"1++": True, "3++": True}

n = int(input())
operates = input().split()
for op in operates:
    if op == "0":
        print("X",end="")
    elif map_dict.get(op):
        print("E",end="")
    else:
        print("I",end="")
print()
