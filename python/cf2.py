tempstr=input("请输入")
if(tempstr[-2] in ['c','C'] and tempstr[-1] in ['e','E']):
     c=(eval(tempstr[0:-3])-32)/1.8
     print("摄氏度是{:.2f}c".format(c))
elif tempstr[-2] in ['f','F']and tempstr[-1] in ['a','A']:
    f=eval(tempstr[0:-3])*1.8+32
    print("华氏度是{:.2f}f".format(f))
else:
    print("输入有误")
