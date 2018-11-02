import sys,os,math,time,random
from functools import reduce

def power(x,n = 2):
	s = 1
	while n > 0:
		n -= 1
		s *= x
	return s

def baseN(num, b):
    return ((num == 0) and '0') or (baseN(num // b, b).lstrip('0') + '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'[num % b])

def enroll(name,gender,age = 6,city ='Beijing'):
	print('name',name)
	print('gender',gender)
	print('age',age)
	print('city',city)


def add_end(L=None):
	if L is None:
		L = []	 
	L.append('End')
	return L

def calc(f,*numbers):
	sum = 0
	for n in numbers:
		sum += f(n)
	return sum

def person(name,age,**kw):
	print('name:',name,'age:',age,'other:',kw)


def print2(*agrs,sep=' ',end='\n',file=sys.stdout):
	pass

def print_2(*args,**kargs):
	sep = kargs.get('sep',' ')
	end = kargs.get('end','\n')
	file = kargs.get('file',sys.stdout)
	output = ''
	first = True
	for arg in args:
		output += (''if first else sep) + str(arg)
		first = False
	file.write(output+end)	

#print_2(product(1,2,0,3))
#print(calc(lambda x:x*x,*[1,2,3,4,5]))
#x = open('C:\\Users\\dell\\Desktop\\new.txt','a')
#print_2(1,2,3,4,5,sep='OOO',end="XXX",file = x)

def product(*number):
	if len(number) is 0:
		return 0
	x = 1
	for num in number:
		if num is 0:
			return 0
		x*=num
	return x

def hanorta_move(n,a,b,c):
	  if n is 1:
	  	print(a,'-->',c)
	  else:
	  	hanorta_move(n-1, a, c, b)
	  	hanorta_move(1, a, b, c)
	  	hanorta_move(n-1, b, a, c)

#hanorta_move(4,'A','B','C')

def trim(str):
	#if not isinstance(str,(str)):
	#	raise TypeError('请输入字符串！')
    while str[-1:]==' ':
        str = str[:-1]
    while str[:1]==' ':
        str = str[1:]
    return str

#[i.lower()/upper() if isinstance(i,str) else i for i in L1]
#generator x = (i.lower() if isinstance(i,str) else i for i in L1) //1. next(x) 2. for n in x: print(n) 
#enumerate([]) list转[i,elem[i]]
#rint_2(trim('hello  11 '))
#[x * x * x for x in range(1, 11)]

def yanghui_triangles():
	L = [1]
	while len(L) < 100: 
		yield L
		L.append(0)
		L = [L[i-1] + L[i] for i in range(len(L))]

def num_output(f,x):
	g = f()
	i = 0
	while i < x:
		try:
			a = next(g)
			print('f:',a)
		except StopIteration as e:
			print('',e.value)
			break
		i+=1	
#num_output(yanghui_triangles,10)

#name = ['adam', 'LISA', 'barT']	
def normal_Name(name):
	return name[0].upper()+name[1:].lower()
#name = list(map(normal_Name,name))

def prod(*L):
	return reduce(lambda x,y:x*y,L)
#	return reduce(f,L)

#def f(x,y):
#	return x*y
#print(prod(1,2,3,4,5))	

#list(filter(not_empty, ['A', '', 'B', None, 'C', '  ']))

def is_huiwen(a):
	return str(a)[:len(str(a))//2+1] == str(a)[len(str(a))//2:len(str(a))][::-1]
#print(list(filter(is_huiwen,L)))

#sorted([('Bob', 75), ('Adam', 92), ('Bart', 66), ('Lisa', 88)], key=lambda i:i[0].lower(), reverse=True)


#1001
def jiaogu_guess(number):
	i = 0
	while number != 1:
		if number % 2 == 0:
			number /= 2
		else:
			number = int((number * 3 + 1)/2)
		i+=1
	return i

#1002
def sum(x):
	string = str(x)
	num = 0
	for i in range(len(string)):
		num += int(string[i])
	return num	

def to_chinese(x):
	x = str(x)
	a = ""
	number = {'0':'ling','1':'yi','2':'er','3':'san','4':'si','5':'wu','6':'liu','7':'qi','8':'ba','9':'jiu'}
	for i in range(len(x)-1):
		a += number.get(x[i]) + " "
	a += number.get(x[len(x)-1])
	return a
#print(to_chinese(sum(1234567890987654321123456789)))	

#1003
def is_exceed(string,*a):
	for i in range(len(string)):
		z = 0
		for j in range(len(a)):
			if string[i] != a[j]:
				z+=1
		if z == int(len(a)):
			return 0
	for i in range(len(a)):
		z = 0
		for j in range(len(string)):
			if string[j] != a[i]:
				z+=1
		if z == int(len(string)):
			return 0		
	return 1			

#x * y = z
def is_success(string,*a):
	if(is_exceed(string,*a) == 0):
		return 'NO'
	a = string.split('P')
	b = string.split('T')
	if len(a) > 2 or len(b) > 2:
		return 'NO'
	if len(a[0]) * (len(a[1])-1- len(b[1])) != len(b[1]):
		return 'NO'
	return 'YES'		
	#a += string[1].split('T')[1]

def PAT_circle(n):
	for i in range(int(n)):		
		x = input()
		print(is_success(x,'P','A','T'))


#1004
def compare_grade_better(stu_name1,stu_num1,stu_gra1,stu_name2,stu_num2,stu_gra2):
	if int(stu_gra1) > int(stu_gra2):
		return stu_name1,stu_num1,stu_gra1
	else:
		return stu_name2,stu_num2,stu_gra2

def compare_grade_worse(stu_name1,stu_num1,stu_gra1,stu_name2,stu_num2,stu_gra2):
	if int(stu_gra1) < int(stu_gra2):
		return stu_name1,stu_num1,stu_gra1
	else:
		return stu_name2,stu_num2,stu_gra2

def grade_circle(n):
	best_stu = input().split(" ")
	worst_stu = best_stu
	for i in range(int(n)-1):
		stu2 = input().split(" ")
		best_stu = compare_grade_better(best_stu[0],best_stu[1],best_stu[2],stu2[0],stu2[1],stu2[2])
		worst_stu = compare_grade_worse(worst_stu[0],worst_stu[1],worst_stu[2],stu2[0],stu2[1],stu_gra2[2])
	print(best_stu[0],best_stu[1])
	print(worst_stu[0],worst_stu[1])

#1005
#构造角谷序列
def cal_jiaogu_list(number):
	x = [number]
	while number != 1:
		if number % 2 == 0:
			number /= 2
		else:
			number = int((number * 3 + 1)/2)
		x+=[int(number)]
	return x

#x⊆y return 1, y⊆x return -1, x,y不存在包含关系 return 0
def compare_list(x,y):
	for i in y:
		if x[0] == i:
			return 1
	for j in x:
		if y[0] == j:
			return -1 	
	return 0

#创建角谷list的父list
def creat_f_list(l):
	num_list = [l[0]]
	jiaogu_list = [cal_jiaogu_list(l[0])]
	for i in range(len(l)-1):
		flag = 0
		for j in range((len(num_list))):
			new_list = cal_jiaogu_list(l[i+1])
			x = compare_list(jiaogu_list[j],new_list)
			if x == 1:
				jiaogu_list[j] = new_list
				num_list[j] = l[i+1]
				flag = 1
				break
			elif x == -1:
				flag = 1
				break
			elif x == 0:
				flag += x
		if flag == 0:
			jiaogu_list += [new_list]
			num_list += [l[i+1]]
		flag = 0			
	return  num_list

def jiaogu_circle2():
	x = input()
	y = input()
	num_list = y.split(" ")
	for i in range(len(num_list)):
		num_list[i] = int(num_list[i])
	last_list = sorted(creat_f_list(num_list),reverse = True)

	list_to_str = str(last_list[0])
	for i in range(len(last_list)-1):
		list_to_str += " "+str(last_list[i+1])
	return list_to_str
#print(jiaogu_circle2())

#1006	
def change(n):
	list_1 = ['S','B']
	x = ""
	for i in range(len(n)-1):
		for j in range(int(n[i])):
			x += list_1[len(n)-i-2]
	for i in range(int(n[len(n)-1])):
		x+=str(i+1)
	print(x)

#1007
def cal_prime_list(n):
	if n == 1 or n == 2:
		return []
	else:
		number = 0
		x = [2]
		flag = 0
		for i in range(3,n+1,2):
			for j in x:
				if i%j == 0:
					flag = 1
					break 
			if flag == 0:
				x+=[i]	
			flag = 0				
	return x

def cal_prime_num(n):
	number = 0
	if n == 1 or n == 2:
		return 0
	else:
		x = [2]
		flag = 0
		for i in range(3,n+1,2):
			for j in x:
				if i%j == 0:
					flag = 1
					break
				if j > int(math.sqrt(i)):
					break 
			if flag == 0:
				if x[len(x)-1] == i-2:
					number += 1
				x+=[i]
			flag = 0			
	return number

def cal_prime_list_x_num(n,x):
	a = 0
	prime_list = cal_prime_list(n)
	if prime_list == []:
		return 0
	for i in range(len(prime_list)-1):
		if (prime_list[i+1]-prime_list[i]) == x:
			a+=1
	return a

def cal_double_prime_num():
	MAX_INT = 100000
	x = int(input())
	marks_bool = [True] * (MAX_INT + 1)
	marks_bool[1] = False
	for i in range(2,int(math.sqrt(MAX_INT)) + 1):
	    j = i
	    k = j
	    while j * k <= MAX_INT:
	        marks_bool[j * k] = False
	        k += 1
	sum_int = 0
	for i in range(3,x+1,2):
	    if marks_bool[i] is True and marks_bool[i-2] is True:
	        sum_int += 1
	print(sum_int)
#print(cal_prime_num(int(input())))		

#1008
def get():
	str1 = input()
	n = str1.split(' ')[1]
	str2 = input()
	x = str2.split(' ')
	get_list = change(n,x)
	final_str = str(get_list[0])
	for i in range(len(get_list)-1):
		final_str+=' '+get_list[i+1]
	return final_str
def change(n,x):
	y = []
	for i in range(len(x)):
		y +=[x[(i-int(n))%len(x)]]
	return y

#1009
def opposite_talk():
	str_talk = input()
	n = str_talk.split(' ')
	final_str = n[len(n)-1]
	for i in range(len(n)-1):
		final_str+=' '+n[len(n) - i - 2]
	return final_str

#1010
def derivation_polyn():
	poly = list(map(int, input().split()))
	if poly[-1]==0:  
	    del poly[-2:]
	if poly:  
	    poly_l = list(range(len(poly))) 
	    for i, p in enumerate(poly):
	        if i % 2==0:  
	            poly_l[i] = str(p*poly[i+1])  
	            poly_l[i+1] = str(poly[i+1] - 1)  
	else:  
	    poly_l = '00'
	print(' '.join(poly_l).strip()) 

#1011
def compare_bignum():
	n = int(input())
	for i in range(n):
		get = input()
		a = get.split()[0]
		b = get.split()[1]
		c = get.split()[2]
		print('Case #'+str(i+1)+': true' if (int(a)+int(b)>int(c)) else 'Case #'+str(i+1)+': false')

#1012
def div_num():
	num_list = list(map(int,input().split()))
	a = [0,0,0,0,0]
	a_n = [0,0,0,0,0]	
	flag2 = -1
	if len(num_list) != 0:
		for i in range(1,len(num_list)):
			if num_list[i]%10 == 0:
				a[0]+=num_list[i]
				a_n[0]+=1
			if num_list[i]%5 == 1:
				flag2 =-flag2
				a[1]+=flag2*num_list[i]
				a_n[1]+=1
			if num_list[i]%5 == 2:
				a[2]+=1
				a_n[2]+=1
			if num_list[i]%5 == 3:
				a[3] += num_list[i]
				a_n[3] += 1
			if num_list[i]%5 == 4:
				if num_list[i] > a[4]:
					a[4] = num_list[i]
				a_n[4] += 1
	for i in range(5):
		if a_n[i] == 0:
			a[i] = 'N'
	if a_n[3] != 0:
		x = a[3]/a_n[3]		
		a[3] = '{:.1f}'.format(x)
	print(str(a[0])+' '+str(a[1])+' '+str(a[2])+' '+str(a[3])+' '+str(a[4]))			


#1013
def prime_list_num(n):
	if n == 0:
		return []
	else:
		number = 1
		x = '2'
		flag = 0
		i = 2
		while len(x) < n:
			i+=1
			for j in x:
				if i%j == 0:
					flag = 1
					break 
			if flag == 0:
				x+=str(i)	
			flag = 0				
	return x
def prime_list():
	get_str = input().split()
	m_list = prime_list_num(int(get_str[1]))
	n_list = prime_list_num(int(get_str[0]))
	for i in range(len(m_list)):
		if m_list[0] < n_list[-1]:
			m_list.pop(0)
		else:
			break
	str1 = m_list[0]
	for i in range(1,len(m_list)):
		if i%10 == 0:	
			print(str1)
			str1 = m_list[i]
		else:
			str1 +=' '+m_list[i]
	print(str1)


def pat_1013():
	get = input()
	MAX_INT = 105000
	marks_bool = [True] * (MAX_INT + 1)
	marks_bool[1] = False
	for i in range(2,int(math.sqrt(MAX_INT)) + 1):
	    j = i
	    k = j
	    while j * k <= MAX_INT:
	        marks_bool[j * k] = False
	        k += 1
	x = int(get.split()[0])
	y = int(get.split()[1])
	sum_int = 0
	flag = 0
	flag2 = 0
	i = 0
	while sum_int < y:
		if marks_bool[i] == True:
			sum_int += 1
			if sum_int == x:
				flag = 1
			elif sum_int == y:
				print(i)
				break
			if flag == 1:
				print(str(i) +' ',end='')
				flag2+=1
			if flag2%10 == 0 and flag2 != 0:
				print()
		i+=1
	print(end - start)	

#1014
def homes_party():
	day = {'1':'MON','2':'TUE','3':'WED','4':'THU','5':'FRI','6':'SAT','7':'SUN'}
	num_list = {'A':1,'B':2,'C':3,'D':4,'E':5,'F':6,'G':7,'H':8,'I':9,'J':10,'K':11,'L':12,'M':13,'N':14,'O':15,'P':16,'Q':17,'R':18,'S':19,'T':20,'U':21,'V':22,'W':23,'X':24,'Y':25,'Z':26}
	Ox_list = {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'A':10,'B':11,'C':12,'D':13,'E':14,'F':15,'G':16,'H':17,'I':18,'J':19,'K':20,'L':21,'M':22,'N':23}
	str_1 = input()
	str_2 = input()
	str_3 = input()
	str_4 = input()
	day_ = ''
	hour_ = 0
	time = 0
	x = 0
	for i in range(min(len(str_1),len(str_2))):
		if str_1[i] == str_2[i] and str_1[i].isalpha() and str_1[i].isupper() and (day.get(str(num_list[str_1[i]])) != None) and x == 0:
			day_ = day[str(num_list[str_1[i]])]
			x+=1
		elif str_1[i] == str_2[i] and (Ox_list.get(str_1[i]) != None) and x == 1:
			hour_ = Ox_list[str_1[i]]
			break
	for i in range(min(len(str_3),len(str_4))):
		if str_3[i] == str_4[i] and str_3[i].isalpha():
			time = i
			break
	hour_ = str(hour_) if (hour_>9) else '0'+str(hour_)
	time = str(time) if (time>9) else '0'+str(time)
	return day_+' '+hour_+':'+time

#1015 超时
		
#1016
def part_A_B():
	get = input().split()
	a = get[0]
	a_d = get[1]
	a_n = ''
	b = get[2]
	b_d = get[3]
	b_n = ''
	for i in range(len(a)):
		if a[i] == a_d:
			a_n += a_d
	for i in range(len(b)):
		if b[i] == b_d:
			b_n += b_d
	if len(a_n) == 0:
		a_n = '0'
	if len(b_n) == 0:
		b_n = '0'
	print(int(a_n)+int(b_n))

#1017
def div_num():
	get = list(map(int,input().split()))
	a = get[0]
	b = get[1]
	m=divmod(a,b)
	print(m[0],m[1])

#1018
# same return 0 a win return 1 else return -1
def compare_CJB(a,b):
	if a == b:
		return 0
	if a == 'C':
		if b == 'J':
			return 1
		if b == 'B':
			return -1
	if a == 'J':
		if b == 'B':
			return 1
		if b == 'C':
			return -1
	if a == 'B':
		if b == 'C':
			return 1
		if b == 'J':
			return -1
	else:
		return -2

def cal_win_num():
	n = int(input())
	a = {'B':1,'C':2,'J':3}
	b = {'1':'B','2':'C','3':'J'}
	a1 = [0,0,0,0,0,0]#YSPBJS
	a2 = [0,0,0,0,0,0]
	str_1 = ''
	str_2 = ''
	for i in range(n):
		get = input().split()
		x = compare_CJB(get[0],get[1])
		if x == 1:
			a1[0] += 1
			a2[1] += 1
			a1[a[get[0]]+2] += 1
		elif x == -1:
			a1[1] += 1
			a2[0] += 1
			a2[a[get[1]]+2] += 1
		elif x == 0:
			a1[2] += 1
			a2[2] += 1

	for i in range(3):	
		if a1[i+3] == max(a1[3],a1[4],a1[5]):
			str_1 += b[str(i+1)]
		if a2[i+3] == max(a2[3],a2[4],a2[5]):
			str_2 += b[str(i+1)]	
	print(a1[0],a1[2],a1[1])
	print(a2[0],a2[2],a2[1])
	print(str_1[0],str_2[0])

#1019
def math_blk_hole():
	get_num = int(input())
	str_get_num = str(get_num)
	if get_num == 6174:
		print('7641','-','1467','=','6174')
	while len(str_get_num)<4:
		str_get_num = '0'+str_get_num
	while get_num != 6174:
		str_num_r_st = ''.join(list(sorted(str_get_num,reverse = True)))
		str_num_st =  ''.join(list(sorted(str_get_num)))
		get_num = int(str_num_r_st) - int(str_num_st)
		str_get_num = str(get_num)
		while len(str_get_num)<4:	
			str_get_num = '0'+str_get_num
		print(str_num_r_st,'-',str_num_st,'=',str_get_num)
		if str_get_num == '0000':
			break

#1020
def moon_cake():
	_get = list(map(int,input().split()))
	_get_type = list(map(float,input().split()))
	_get_price = list(map(float,input().split()))
	lack_size = _get[1]
	sell_money = 0 
	_moon_cake_list = []
	for i in range(_get[0]):
		_moon_cake_list += [[_get_price[i],_get_type[i],_get_price[i]/_get_type[i]]]
	_moon_cake_list = sorted(_moon_cake_list,key=lambda s: s[2],reverse = True)
	for i in range(_get[0]):
		if _moon_cake_list[i][1] <= lack_size:
			lack_size -= _moon_cake_list[i][1]
			sell_money += _moon_cake_list[i][0]
		else:
			sell_money += _moon_cake_list[i][2] * lack_size
			break
	print('{:.2f}'.format(sell_money))

#1021
def num_count():
	_get = input()
	num_count_list = [0,0,0,0,0,0,0,0,0,0]
	for i in range(len(_get)):
		num_count_list[int(_get[i])]+=1
	for i in range(10):
		if num_count_list[i] == 0:
			continue
		else:
			print(i,':',num_count_list[i],sep='')	

#1022
def sys_transform():
	_get = list(map(int,input().split()))
	x = _get[0]+_get[1]
	z = 1
	i = 0
	a = ""
	d = _get[2]
	while x >= d:
	  y = x%d
	  x//=d
	  a=str(y)+a	
	print(str(x)+a)	

#1023
def num_count2():
	_get = list(map(int,input().split()))
	str1 = ''
	for x in range(1,10):
		if _get[x] != 0:
			str1 += _get[x] * str(x)
	if len(str1) > 0:		
		print(str1[0],_get[0] * '0',str1[1:],sep = '')
	else:
		print(0)

#1024
def science_num():
	_get = input().split('E')
	num = _get[0][1]+_get[0][3:]
	exp = int(_get[1])
	str1 = ''
	if _get[0][0] == '-':
		str1 += '-'
	if exp < -1:
		str1 += '0.'+ (-1 * (exp + 1)) * '0' + num
	elif exp == -1:
		str1 += '0.' + num
	elif exp >= 0:
		if exp < len(num)-1:
			str1 += num[:exp+1]+'.'+num[exp+1:]
		else:
			str1 += num + (exp - len(num) + 1) * '0'	
	print(str1)

#1025 4超时 5 wa
def reverse_link():
	_get = input().split()
	_data = list(range(100000))
	_next = list(range(100000))
	new_line = []
	_begin = _get[0]
	_long1 = int(_get[1])
	_size = int(_get[2])
	_long = 0
	for i in range(_long1):
		_new = input().split()
		_data[int(_new[0])] = _new[1]
		_next[int(_new[0])] = _new[2]
	for i in range(0,_long1):
		if isinstance(_next[int(_begin)],int):
			break
		new_line += [[_begin,_data[int(_begin)],_next[int(_begin)]]]
		_begin = _next[int(_begin)]
		_long+=1	
	for i in range(0,_long - _size,_size):
		for j in range(0,_size-1):
			print(new_line[i+_size-j-1][0],new_line[i+_size-j-1][1],new_line[i+_size-j-2][0])
		print(new_line[i][0],new_line[i][1],new_line[_long - 1 if (i + 2 * _size - 1) >= _long and _long%_size == 0 else ((i+_size) if(i + 2 * _size - 1) >= _long else (i + 2 * _size - 1))][0])
	for i in range(_long%_size):
		print(new_line[i +_long -_long%_size][0],new_line[i +_long -_long%_size][1],new_line[i + _long -_long%_size][2])
	if _long%_size == 0:
		for i in range(1,_size):
			print(new_line[_long-i][0],new_line[_long-i][1],new_line[_long-i-1][0])
		print(new_line[_long-_size][0],new_line[_long-_size][1],-1)

#1026
def clock_time():
	_get = list(map(int,input().split()))
	d_time = _get[1] - _get[0]
	hour = d_time // 360000 
	d_time %= 360000
	mintues = d_time // 6000
	d_time %= 6000
	second = d_time // 100
	d_time %= 100
	if d_time >= 50:
		second += 1
	if hour < 10:
		hour = '0' +str(hour)
	if mintues < 10:
		mintues = '0' + str(mintues)
	if second < 10:
		second = '0' + str(second)	
	print(hour,mintues,second,sep=':')

#1027
def print_hourglass():
	_get = input().split()
	num = int(_get[0])
	sym = _get[1]
	k = int(math.sqrt((num + 1)/2))
	extra = num - 2 * k * k + 1
	if num == 0:
		extra = 0
	for i in range(k):
		for j in range(i):
			print(' ',end = '')
		for i in range(2 * k - 1 - 2 * i):
			print(sym,end = '')
		print()
	for i in range(1,k):
		for j in range(k - i - 1):
			print(' ',end = '')
		for i in range(1 + 2 * i):
			print(sym,end = '')
		print()
	print(extra)

#1028
#legal return 1   else return 0
def birth_is_legal(a):
	a_list = list(map(int,a.split('/')))
	if a_list[0] > 2014:
		return 0
	elif a_list[0] == 2014 and a_list[1] > 9:
		return 0
	elif a_list[0] == 2014 and a_list[1] == 9 and a_list[2] > 6:
		return 0
	elif a_list[0] < 1814:
		return 0
	elif a_list[0] == 1814 and a_list[1] < 9:
		return 0
	elif a_list[0] == 1814  and a_list[1] == 9 and a_list[2] < 6:
		return 0
	return 1

#a > b return 1  b > a return 0
def compare_older(a,b):
	a_list = list(map(int,a.split('/')))
	b_list = list(map(int,b.split('/')))
	if a_list[0] >= b_list[0]:
		return 0
	elif a_list[0] == b_list[0] and a_list[1] >= b_list[1]:
		return 0
	elif a_list[0] == b_list[0] and a_list[1] == b_list[1] and a_list[2] >= b_list[2]:
		return 0
	else:
		return 1

def lustrum():
	_get_num = int(input())
	older_people = []
	younger_people = []
	n = 0
	for i in range(_get_num):
		_get_infomation = input().split()
		if(birth_is_legal(_get_infomation[1])):
			n += 1
			if len(older_people) == 0:
				older_people =[_get_infomation[0],_get_infomation[1]]
				younger_people = [_get_infomation[0],_get_infomation[1]]
			else:
				if compare_older(_get_infomation[1],older_people[1]) == 1:
					older_people = _get_infomation
				if compare_older(_get_infomation[1],younger_people[1]) == 0:
					younger_people = _get_infomation
		else:
			continue
	if len(older_people) != 0:	
		print(n,older_people[0],younger_people[0])
	else:
		print(0)

#1029
def find_failed_key():
	complete_str = input()
	incomplete_str = input()
	deta_str = ''
	j = 0
	num_list = {'_':0,'A':1,'B':2,'C':3,'D':4,'E':5,'F':6,'G':7,'H':8,'I':9,'J':10,'K':11,'L':12,'M':13,'N':14,'O':15,'P':16,'Q':17,'R':18,'S':19,'T':20,'U':21,'V':22,'W':23,'X':24,'Y':25,'Z':26,'0':27,'1':28,'2':29,'3':30,'4':31,'5':32,'6':33,'7':34,'8':35,'9':36}
	list_ = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
	for i in range(len(complete_str)):
		if j <= len(incomplete_str) - 1 and complete_str[i] == incomplete_str[j]:
			j += 1 
		else:
			deta_str += complete_str[i]
	for i in range(len(deta_str)):
		list_[num_list[deta_str[i].upper()] if deta_str[i].isalpha() else num_list[deta_str[i]]] += 1
		if list_[num_list[deta_str[i].upper()] if deta_str[i].isalpha() else num_list[deta_str[i]]] == 1:
			print(deta_str[i].upper() if deta_str[i].isalpha() else deta_str[i],end='')

#1030
def binary_search(x,a,b,e):
	if x == a[(b+e)//2]:
		return (b+e)//2
	elif x >= a[(b+e)//2]:
		b = (b+e)//2
	else:
		e = (b+e)//2
	if b == e-1:
		return e
	return binary_search(x,a,b,e)

def binary_search_(x,a):
	return binary_search(x,a,0,len(a))

def perfect_array():
	x = list(map(int,input().split()))
	length = x[0]
	p = x[1]
	num_list = list(map(int,input().split()))
	sorted_num_list = sorted(num_list)
	big_list = num_list[binary_search_(sorted_num_list[0]*p-1,sorted_num_list):-1] #[int(x)....max]
	small_list = num_list[:binary_search_(sorted_num_list[-1]//p,sorted_num_list)] #[0...int(x)+1]
	_max = 0
	for i in range(len(small_list)):
		small_list[i] = binary_search_(small_list[i]*p,big_list)
		_max = max(_max,len(big_list) - small_list[i] - 1 + i)
	print(length-_max)

def perfect_array2():
	n,p = list(map(int,input().split()))
	data = list(map(int,input().split()))
	data.sort()
	maxDist = 0
	for i in range(n):
		j = i + maxDist
		while j < n:
			if data[i] * p < data[j]:
				break
			else:
				maxDist = j - i + 1
			j += 1
	print(maxDist)

#1031
def check_hefa(s):
	for i in range(17):
		if not s[i].isdigit():
			return False
	return True


def checkAll(number):
	heavy_list = [7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2]
	M_list = ['1','0','X','9','8','7','6','5','4','3','2']
	x = 0
	for j in range(17):
		x += int(number[j]) * heavy_list[j]
	if number[17] == M_list[x%11]:
		return True
	else:
		return False

def ID_check():
	n = int(input())
	count = 0
	new_list = []
	for i in range(n):
		number = input()
		if check_hefa(number) and checkAll(number):
			count = count + 1
		else:
			new_list += [number]
	if count == n:
		print("All passed")
	else:
		for i in range(len(new_list)):
			print(new_list[i])

#1032
def best_digger():
	 n = int(input())
	 score_list = [0 for i in range(100000)]
	 for i in range(n):
	 	a = input().split()
	 	school,school_score = int(a[0]),int(a[1])
	 	score_list[school] += school_score
	 _max = 0
	 _nu = 0
	 for i in range(1,100000):
	 	if score_list[i] > _max:
	 		_nu = i
	 		_max = score_list[i]
	 print(_nu,_max)

def min_prime(s,a):
	for i in range(2,s):
		if a%i == 0:
			a+=1
			return min_prime(s,a)

	return a

#1033
def Old_keyboard_type():
	dead_key =  input()
	get_str = input()
	dictionary = {} 
	flag = 0
	for i in range(len(dead_key)):
		dictionary[dead_key[i]] = dictionary.get(dead_key[i],0) + 1
	if dictionary.get('+',0) != 0:
		flag = 1
	result = ""
	for i in range(len(get_str)):
		if flag == 1 and get_str[i].isalpha() and (get_str[i].islower()) and (dictionary.get(get_str[i].upper(),0) == 0):
			result += get_str[i]
		elif flag == 0 and get_str[i].isalpha() and (dictionary.get(get_str[i].upper(),0) == 0):
			result += get_str[i]
		elif not get_str[i].isalpha() and dictionary.get(get_str[i],0) == 0:
			result += get_str[i]
	print(result)


#1034
def gcd(a,b):
	while(b):
		temp = b
		b = a % b
		a = temp
	return a

def baozhuang_int(c1,c2,c_fh):
	if c_fh == -1:
		if c1 < c2:
			return '(-'+str(int(c1))+'/'+str(int(c2))+')'
		elif c1 > c2:
			if c1 % c2 != 0:	
				return '(-'+str(int(c1//c2))+' '+str(int(c1%c2))+'/'+str(int(c2))+')'
			elif c1 % c2 == 0:
				return '(-'+str(int(c1//c2))+')'
		elif c1 == c2:	
			return '(-1)'
	elif c_fh == 1:
		if c1 < c2:
			return str(int(c1))+'/'+str(int(c2))+''
		elif c1 > c2:	
			if c1 % c2 != 0:
				return str(int(c1//c2))+' '+str(int(c1%c2))+'/'+str(int(c2))+''
			elif c1 % c2 == 0:
				return str(int(c1/c2))
		elif c1 == c2:
			return '1'
	elif c_fh == 0:
		return '0'

def add(a1,a2,b1,b2):
	c1 = a1 * b2 + a2 * b1
	c2 = a2 * b2
	c_fh = 1
	if not c2 == 0: 
		if c1 < 0 and c2 > 0:
			c_fh = -1
			c1 = -c1
		elif c1 > 0 and c2 < 0:
			c_fh = -1
			c2 = -c2
		elif c1 < 0 and c2 < 0:
			c2 = -c2
			c1 = -c1
		elif c1 == 0:
			c_fh = 0
		gcd1 = gcd(c1,c2)
		c1 = c1/gcd1
		c2 = c2/gcd1
		return baozhuang_int(c1,c2,c_fh)
	else:
		return 'Inf'

def mul(a1,a2,b1,b2):
	c1 = a1 * b1
	c2 = a2 * b2
	c_fh = 1
	if not c2 == 0: 
		if c1 < 0 and c2 > 0:
			c_fh = -1
			c1 = -c1
		elif c1 > 0 and c2 < 0:
			c_fh = -1
			c2 = -c2
		elif c1 < 0 and c2 < 0:
			c2 = -c2
			c1 = -c1
		elif c1 == 0:
			c_fh = 0	
		gcd1 = gcd(c1,c2)
		c1 = c1/gcd1
		c2 = c2/gcd1
		return baozhuang_int(c1,c2,c_fh)
	else:
		return 'Inf'

def devi(a1,a2,b1,b2):
	c1 = a1 * b2
	c2 = a2 * b1

	c_fh = 1
	if not c2 == 0: 
		if c1 < 0 and c2 > 0:
			c_fh = -1
			c1 = -c1
		elif c1 > 0 and c2 < 0:
			c_fh = -1
			c2 = -c2
		elif c1 < 0 and c2 < 0:
			c2 = -c2
			c1 = -c1
		elif c1 == 0:
			c_fh = 0
		gcd1 = gcd(c1,c2)
		c1 = c1/gcd1
		c2 = c2/gcd1
		return baozhuang_int(c1,c2,c_fh)
	else:
		return 'Inf'

def calcute(a1,a2,b1,b2,fh_a,fh_b):
	print(baozhuang_int(a1,a2,fh_a)+' + '+baozhuang_int(b1,b2,fh_b)+' = '+add(fh_a * a1,a2,fh_b * b1,b2))
	print(baozhuang_int(a1,a2,fh_a)+' - '+baozhuang_int(b1,b2,fh_b)+' = '+add(fh_a * a1,a2,fh_b * -1 * b1,b2))
	print(baozhuang_int(a1,a2,fh_a)+' * '+baozhuang_int(b1,b2,fh_b)+' = '+mul(fh_a * a1,a2,fh_b * b1,b2))
	print(baozhuang_int(a1,a2,fh_a)+' / '+baozhuang_int(b1,b2,fh_b)+' = '+devi(fh_a * a1,a2,fh_b * b1,b2))

def arithmetic():
	a,b = input().split()
	a1,a2 = a.split('/')
	b1,b2 = b.split('/')
	int_a1 = int(a1)
	int_a2 = int(a2)
	int_b1 = int(b1)
	int_b2 = int(b2)
	fh_a = 1
	fh_b = 1
	if int_a1 < 0:
		fh_a = -1
		int_a1 = -int_a1
	elif int_a1 == 0:
		fh_a = 0
	if int_b1 < 0:
		fh_b = -1
		int_b1 = -int_b1
	elif int_b1 == 0:
		fh_b = 0

	gcd_a = gcd(int_a1,int_a2)
	gcd_b = gcd(int_b1,int_b2) 	
	
	if int_a1 % int_a2 == 0:
		int_a1 = int_a1/int_a2
		int_a2 = 1
	else:
		int_a1 = int_a1/gcd_a
		int_a2 = int_a2/gcd_a

	if int_b1%int_b2 == 0:
 		int_b1 = int_b1/int_b2
 		int_b2 = 1
	else:
		int_b1 = int_b1/gcd_b
		int_b2 = int_b2/gcd_b
	calcute(int_a1,int_a2,int_b1,int_b2,fh_a,fh_b)

def take_cash():
	price,pay = input().split()
	price = list(map(int,price.split('.')))
	pay = list(map(int,pay.split('.')))
	i_price = price[0] * 17 * 29 + price[1] * 29 + price[2]
	i_pay = pay[0] * 17 * 29 + pay[1] * 29 + pay[2]
	fi = i_pay - i_price
	if fi < 0:
		fi = -fi
		print('-',fi//(17 * 29),'.',(fi % (17 * 29)) // 29,'.',fi % 29,sep="")
	elif fi > 0:
		print(fi//(17 * 29),'.',(fi % (17 * 29)) // 29,'.',fi % 29,sep='')
	elif fi ==0:
		print('0.0.0')

#1047
def Team_contest():
	new_list=[0]
	for i in range(10000):
		new_list+=[0]
	n = int(input())
	grade = -1
	team =''
	for i in range(n):
		team,grade = input().split()
		team = int(team.split('-')[0])
		grade = int(grade)
		new_list[team] += grade
	n_max = -1
	team_n = -1
	for i in range(10000):
		if new_list[i] > n_max:
			team_n = i
			n_max = new_list[i]

	print(team_n,n_max)

def number(x):
	if 0 <= x < 10:
		return str(x)
	elif x == 10:
		return 'J'
	elif x == 11:
		return 'Q'
	elif x == 12:
		return 'K'
#1048
def put_number_sercet():
	x,y = input().split()
	l = min(len(x),len(y))
	m = max(len(x),len(y))
	if len(x) == m:
		y = '0'*(m-l)+y
	elif len(y) == m:
		x = '0'*(m-l)+x
	str1 = ''
	for i in range(1,m+1):
		if i % 2 == 1:
			str1 = str(number((int(y[-i]) + int(x[-i]))%13)) + str1
		if i % 2 == 0:
			if (int(y[-i]) - int(x[-i])) < 0:
				a = int(y[-i]) - int(x[-i]) + 10
			else:
				a = int(y[-i]) - int(x[-i])
			str1 = str(a) + str1
	print(str1)


#1052
def acting_cute():
	hand = input().replace('[','')
	eye = input().replace('[','')
	mouth = input().replace('[','')
	hand = hand.replace(' ','')
	eye = eye.replace(' ','')
	mouth = mouth.replace(' ','')
	hand = hand.split(']')
	eye = eye.split(']')
	mouth = mouth.split(']')
	hand.pop()
	eye.pop()
	mouth.pop()
	new_ = [hand,eye,mouth,eye,hand]
	n = int(input())
	x = []
	str_ = ""
	for i in range(n):
		x = list(map(int,input().split()))
		for i in range(5):
			if i == 1:
				str_ += '('
			if x[i] > len(new_[i]):
				print("Are you kidding me? @\/@",end="")
				str_ = ""
				break
			str_ += new_[i][x[i]-1]
			if i == 3:
				str_ += ')'
		print(str_)
		str_ = ""

#1054
def n_is_legal(n):
	x = []
	if n[0] == '-':
		n = n[1:]
	if n.find('.') != -1:
		x = n.split('.')
		if x[0][0] == '-':
			x[0] = x[0][1:]
		if x[1] == '':
		   x[1] = '0'
		if len(x) < 3 and x[0].isdigit() and x[1].isdigit() and len(x[1]) < 3 and int(x[0]) <= 1000:
			if int(x[0]) == 1000 and int(x[1]) != 0:
				return False
			return True
		else:
			return False
	elif n.isdigit():
		return int(n) <= 1000 and int(n) > -1000
	else:
		return False

def is_legimate():
	n = int(input())
	x = 0
	flag = 0 
	a = input().split()
	for i in range(n):
		if n_is_legal(a[i]):
			x += float(a[i])
			flag += 1
		else:
			print("ERROR:",a[i],"is not a legal number")
	if flag == 0:
		print("The average of 0 numbers is Undefined")
	elif flag == 1:
		print("The average of",flag,"number is",'{:.2f}'.format(x/flag))
	else:
		print("The average of",flag,"numbers is",'{:.2f}'.format(x/flag))

def sum_combination():
	n = int(input())
	x = list(map(int,input().split()))
	a = 0	
	for i in range(n):
		for j in range(n):
			if x[i] != x[j]:
				a += x[i] * 10 + x[j]
	print(a)

def cal_z_o():
	str_ = input()
	a = 0
	flag1 = 0
	flag2 = 0
	for i in range(len(str_)):
		if str_[i].isalpha():
			a += (ord(str_[i].upper()) - 64)
	st = str(bin(a))[2:]
	for i in range(len(st)):
		if st[i] == '0':
			flag1 += 1
		elif st[i] == '1':
			flag2 += 1
	print(flag1,flag2)

def pat_starer():
	x = input()
	for i in range(50 - len(x)):
		x = '0' + x
	a = input()
	b = input()
	a_n = int(a[0])
	b_n = int(b[0])
	for i in range(len(a) - 1):
		if x[i + 50 - len(a) + 1] == '0':
			a_n = a_n * 10 + int(a[i + 1])
		else:	
			a_n = a_n * int(x[i + 50 - len(a) + 1]) + int(a[i + 1])
	for i in range(len(b) - 1):
		if x[i + 50 - len(b) + 1] == '0':
			b_n = b_n * 10 + int(b[i + 1])
		else:	
			b_n = b_n * int(x[i + 50 - len(b) + 1]) + int(b[i + 1])
	n_sum = a_n + b_n
	r = ""
	s = 0
	for i in range(50):
		if int(x[50 - i - 1]) == 0:
			s = 10
		else:
			s = int(x[50 - i - 1])	
		r = str(n_sum%s) + r
		n_sum //= s
		if n_sum == 0:
			break
	print(r)


def guess_number():
	flag = 0
	while flag == 0:
		a = int(random.random()*100+1)
		print("随机数据生成成功")
		x = -1
		count = 0
		while x!= a:
			print("请输入你所猜测的数字:",end = "")
			x = int(input())
			if x == -1:
				flag = 1
				break
			count += 1
			if x > a:
				print("太大了")
			elif x < a:	
				print("太小了")
			else:
				break
		if flag == 1:
			break
		print("正确，本轮共猜了",count,"次")
		print("是否需要继续玩(Y/N)")
		while True:
			_get = input()
			if _get == 'Y':
				break
			elif _get == 'N':
				flag = 1
				break
			else:
				print("是否需要继续玩(Y/N)")
		count = 0

guess_number()