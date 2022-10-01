tempstr=input("输入")
if tempstr[0] in ['F','f']:
    C=(eval(tempstr[1:])-32)/1.8
    print("转换时{:.2f}C".format(C))
elif tempstr[0] in ['C','c']:
    F=1.8*eval(tempstr[1:])+32
    print("转换时{:.2f}F".format(F))
else:
    print("输入有误")
    
