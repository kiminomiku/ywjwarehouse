x = int(input())
z = 1
i = 0
a = ""
d = int(input())
while x >= d:
  y = x%d
  x//=d
  a=str(y)+a

print(str(d)+"进制")	
print(str(x)+a)	