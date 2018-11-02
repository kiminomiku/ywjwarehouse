#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cctype>
#include <utility>


using namespace std;
//1001
void CallatzGuess(){
	int n,count = 0;
	cin >> n;
	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n = (3 * n + 1) / 2;
		}
		count++;
	}
	cout << count << endl;
}

//1002
void WriteTheNum(){
	string n;
	cin >> n;
	map<char, string> PinYinList = { {'0',"ling"},{ '1',"yi" },{ '2',"er" },{ '3',"san" },{ '4',"si" },{ '5',"wu" },{ '6',"liu" },{ '7',"qi" }, {'8',"ba"},{ '9',"jiu" } };
	int l = n.length(),x = 0;
	for (int i = 0; i < l; i++) {
		x += n[i] - '0';
	}
	string Str = to_string(x);
	int l2;
	l2 = Str.size();
	cout << PinYinList[Str[0]];
	if (l2 > 1) {
		for (int j = 1; j < l2; j++) {
			cout << " " << PinYinList[Str[j]];
		}
	}
	cout << endl;
}

//1003
bool CheckLegal(string Str) {
	int l = Str.length();
	for (int i = 0; i < l; i++) {
		if (Str[i] != 'P' && Str[i] != 'A' && Str[i] != 'T') {
			return false;
		}
	}
	return true;
}

bool IsPTOnce(string Str) {
	int l = Str.length();
	int PFlag = 0, TFlag = 0, AFlag = 0, BFlag = 0, CFlag = 0,A_Flag = 0;
	for(int i = 0; i < l; i++) {
		if (Str[i] == 'P') 
		{
			PFlag++;
		}
		else if(Str[i] == 'T')
		{
			TFlag++;
		}
		else if(Str[i] == 'A')
		{
			A_Flag++;
			if (PFlag == 0) {
				AFlag++;
			}
			else if(TFlag == 0 && PFlag == 1)
			{
				BFlag++;
			}
			else if(TFlag == 1 && PFlag == 1){
				CFlag++;
			}
		}
		if (PFlag == 0 && TFlag == 1) {
			return false;
		}
		if (PFlag > 1 || TFlag > 1) {
			return false;
		}
	}
	if (PFlag == 0 || TFlag == 0) {
		return false;
	}
	if (BFlag == 0) {
		return false;
	}
	if (AFlag * BFlag == CFlag) {
		return true;
	
	}
	return false;
}

void IWantPass(){
	int n;
	cin >> n;
	string Str;
	for (int i = 0; i < n; i++) {
		cin >> Str;
		if (IsPTOnce(Str) && CheckLegal(Str)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}

//1004
void grade_sort(){
	int n;
	cin >> n;
	string max_name, max_id, min_name, min_id,name,id;
	int grade, max_grade = -1, min_grade = 101;
	for (int i = 0; i < n; i++) {
		cin >> name >> id >> grade;
		if (grade < min_grade) {
			min_grade = grade;
			min_id = id;
			min_name = name;
		}
		if (grade > max_grade) {
			max_grade = grade;
			max_id = id;
			max_name = name;
		}
	}
	cout << max_name << " " << max_id << endl;
	cout << min_name << " " << min_id << endl;
}

//1005
void continue_Calltaz_Guess()
{
	vector<int> NumList(200, 0);
	vector<int> checklist;
	int n,num;
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> num;
		NumList[num] = 1;
		checklist.push_back(num);
	}
	for (int i = 0; i < n; i++) 
	{
		num = checklist[i];
		if (NumList[num] != 0) 
		{
			while (num != 1) 
			{
				if (num % 2 == 1) 
				{
					num = (num * 3 + 1) / 2;
				}
				else 
				{
					num /= 2;
				}
				if (NumList[num] == 1) 
				{
					NumList[num] = 0;
				}
				
			}
		}
	}
	int flag = 0;
	for (int i = 100; i > 0; i--) 
	{
		if (NumList[i] == 1) 
		{
			if (flag == 0) 
			{
				cout << i;
				flag = 1;
			}
			else 
			{
				cout << " " << i;
			}
		}
	}
	cout << endl;
}

//1006
void DiffPrintf(){
	map<char, int> map_list;
	map<int, char> ma = { {3,'B'},{2,'S'} };
	char c;
	for (int i = 0; i < 10; i++) {
		c = i + '0';
		map_list[c] = i;
	}
	string str;
	int num;
	cin >> num;
	if (num < 10) {
		for (int i = 1; i <= num; i++) {
			cout << i;
		}
	}
	else {
		str = to_string(num);
		for (int i = 0; i < str.size() - 1; i++) {
			for (int j = 1; j <= map_list[str[i]]; j++) {
				cout << ma[str.size() - i];
			}
		}
		for (int i = 1; i <= num % 10; i++) {
			cout << i;
		}
	}
	cout << endl;
}

//1007
vector<bool> Is_Prime(vector<bool> arr) {
	int len = arr.size(),k = 2;
	arr[1] = false;
	arr[0] = false;
	arr[2] = true;
	for (int i = 2; i < sqrt(len) + 1; i++) {
		while (i * k < len) {
			arr[i * k] = false;
			k++;
		}
		k = 2;
	}
	return arr;
}

void Double_Prime_Guess(){
	int n;
	cin >> n;
	vector<bool> arr(n + 2, true);
	arr = Is_Prime(arr);
	int count = 0;
	for (int i = 2; i < n; i++) {
		if (arr[i] == true && arr[i + 2] == true) {
			count++;
		}
	}
	cout << count << endl;
}

//1008
void Array_Shift(){
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (i != 0) cout << " ";
		cout << " " << arr[(n + i - (m % n))%n];
	}
	cout << endl;	
}

//1009
void Speak_Contrary(){
	string Str,str = "",new_str = "";
	int flag = 0;
	getline(cin, Str);
	for (int i = 0; i < Str.size(); i++) {
		if (Str[i] == ' ') {
			if (flag == 0) {
				new_str += str;
				flag = 1;
			}
			else {
				new_str =  str + " " +new_str ;
			}
			str = "";
		}
		else {
			str += Str[i];
		}
	}
	if (flag == 1) {
		new_str = str + " " + new_str;
	}
	else
	{
		new_str = str;
	}
	cout << new_str << endl;
}

//1010
void Polynome_Derivation(){
	int a, b;
	bool first = true;
	while (cin >> a >> b) {
		if (a != 0 && b != 0) {
			if (!first) {
				cout << " " << a * b << " " << b - 1;
			}
			else {
				cout << a * b<< " " << b - 1;
				first = false;
			}
		}
	}
	if (first) {
		cout << "0 0" << endl;
	}
}

//1011
void A_B_C(){
	int n;
	cin >> n;
	long long a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (a + b > c) {
			cout << "Case #" << i + 1	<< ": true" << endl;
		}
		else if(a + b <= c){
			cout << "Case #" << i + 1 << ": false" << endl;
		}
	}
}

//1012
void Data_Classification(){
	int n;
	cin >> n;
	double flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0, flag2_1 = -1,flag4_1 = 0;
	int x,f1 = 0,f2 = 0,f3 = 0,f4 = 0,f5 = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x % 10 == 0) {
			flag1 += x;
			f1++;
		}
		else if(x % 5 == 1){
			flag2_1 = - flag2_1;
			flag2 += flag2_1 * x;
			f2++;
		}
		else if (x % 5 == 2) {
			flag3++;
			f3++;
		}
		else if (x % 5 == 3) {
			flag4_1++;
			flag4 += x;
			f4++;
		}
		else if (x % 5 == 4) {
			if (x > flag5) {
				flag5 = x;
			}
			f5++;
		}
	}
	if (f1 > 0) {
		cout << flag1;
	}
	else {
		cout << "N";
	}
	if (f2 > 0) {
		cout << " " << flag2;
	}
	else {
		cout << " N";
	}

	if (f3 > 0) {
		cout << " " << flag3;
	}
	else {
		cout << " N";
	}
	if (f4 > 0) {
		printf(" %.1f", flag4 / flag4_1);
	}
	else {
		cout << " N";
	}
	if (f5 > 0) {
		cout << " " << flag5 << endl;
	}
	else {
		cout << " N";
	}
}
	
//1013
bool * set(bool is_Prime[])
{
	int i,k;
	for (i = 0; i < 105000; i++)
	{
		is_Prime[i] = true;
	}
	is_Prime[0] = is_Prime[1] = false;
	for (i = 2; i < sqrt(105000) + 1; i++)
	{
		if (is_Prime[i]) 
		{
			k = 2;
			while (k * i <= 105000)
			{
				is_Prime[i * k] = false;
				k++;
			}
		}
	}
	return is_Prime;
}

void choose_n_m()
{
int n,max,count = 0,flag = 0;
	cin >> n >> max;
	bool is_prime[105005];
	bool *change_prime;
	change_prime = set(is_prime);
	if (n == max) 
	{
		for (int i = 2; i < 105000; i++) 
		{
			if (change_prime[i] == true)
			{
				count++;
				if (count == n)
				{
					cout << i << endl;
					break;
				}
			}
		}
	}
	else {
		for (int i = 2; i < 105000; i++)
		{
			if (change_prime[i] == true) {
				count++;
				if (count == n)
				{
					flag = 1;
				}
				else if (count == max)
				{
					flag = 2;
				}

				if (flag == 1 && ((count - n) % 10) != 9) 
				{
					cout << i << " ";
				}
				else if (flag == 2 || ((count - n) % 10) == 9)
				{
					cout << i;
				}
				if ((count - n) % 10 == 9)
				{
					cout << endl;
				}
				if (flag == 2) 
				{
					break;
				}
			}
		}
	}
}



//1015
class student {
public:
	long long ID;
	int moral_grade, talent_grade,flag;

	student(long long id, int mg, int tg,int f) {
		ID = id;
		moral_grade = mg;
		talent_grade = tg;
		flag = f;
	}
	void stu_print() {
		printf("%lld %d %d\n", ID, moral_grade, talent_grade);
	}
};

bool compare(student a, student b) {
	if (a.flag != b.flag) {
		return a.flag < b.flag;
	}
	else if (a.moral_grade + a.talent_grade != b.moral_grade + b.talent_grade) {
		return a.moral_grade + a.talent_grade > b.moral_grade + b.talent_grade;
	}
	else if(a.moral_grade != b.moral_grade){
		return a.moral_grade > b.moral_grade;
	}
	else {
		return a.ID < b.ID;
	}
}
void moral_talent_thoerty(){	
	int n, worst_grade, bound_grade;
	cin >> n >> worst_grade >> bound_grade;
	vector<student> level1;
	long long stu_id;
	int num = 0;
	int m_grade, t_grade;
	for (int i = 0; i < n; i++) {
		scanf_s("%lld %d %d",&stu_id ,&m_grade ,&t_grade);
		if (m_grade >= bound_grade && t_grade >= bound_grade) {
			level1.push_back({ stu_id,m_grade,t_grade, 1});
		}
		else if (m_grade >= bound_grade && t_grade <= bound_grade && t_grade >= worst_grade) {
			level1.push_back({ stu_id,m_grade,t_grade, 2 });
		}
		else if (m_grade <= bound_grade && t_grade <= bound_grade && t_grade <= m_grade  && t_grade >= worst_grade && m_grade >= worst_grade) {
			level1.push_back({ stu_id,m_grade,t_grade, 3 });
		}
		else if(t_grade >= worst_grade && m_grade >= worst_grade){
			level1.push_back({ stu_id,m_grade,t_grade, 4 });
		}
		else {
			num++;
		}
	}
	sort(level1.begin(), level1.end(),compare);
	cout << n - num << endl;
	if (level1.size() > 0) for (int i = 0; i < level1.size(); i++) level1[i].stu_print();
}

//1016
void fragment_A_B(){
	string pa, pb;
	int da, db;
	cin >> pa >> da >> pb >> db;
	vector<int> pa_list(10, 0);
	vector<int> pb_list(10, 0);
	for (int i = 0; i < pa.length(); i++) {
		pa_list[pa[i] - '0']++;
	}
	for (int i = 0; i < pb.length(); i++) {
		pb_list[pb[i] - '0']++;
	}
	long long xa = 0,xb = 0;
	for (int i = 0; i < pa_list[da]; i++) {
		xa = 10 * xa + da;
	}
	for (int i = 0; i < pb_list[db]; i++) {
		xb = 10 * xb + db;
	}
	cout << xa + xb << endl;
}

//1017
string string_div(string str, int x) {
	string new_str = "";
	int flag = 0;
	for (int i = 0; i < str.length(); i++) {
		if ((str[i] - '0') + flag * 10 < x) {
			flag = (str[i] - '0') + flag * 10;
			if(i != 0)
			new_str += '0';
		}
		else {
			new_str += ((str[i] - '0') + flag * 10) / x + '0';
			flag = ((str[i] - '0') + flag * 10) % x;
		}
	}
	if (new_str == "")
		new_str = "0";
	return new_str + " " + to_string(flag);
}

void num_div(){
	string number;
	int divied;
	cin >> number >> divied;
	cout << string_div(number, divied) << endl;;	
}

//1018
int check_win(char a, char b) {
	if (a == 'C') {
		if (b == 'J') {
			return 1;
		}
		else if (b == 'B') {
			return -1;
		}
		else if (b == 'C') {
			return 0;
		}
	}
	else if (a == 'J') {
		if (b == 'B') {
			return 1;
		}
		else if (b == 'C') {
			return -1;
		}
		else if (b == 'J') {
			return 0;
		}
	}
	else if(a == 'B')
	{
		if (b == 'C') {
			return 1;
		}
		else if (b == 'J') {
			return -1;
		}
		else if (b == 'B') {
			return 0;
		}
	}
	return -2;
}
void sjb(){
		int n;
	cin >> n;
	vector<int> a_list(3);
	vector<int> b_list(3);
	map<int, char> m = { {0,'B'}, {1,'C'}, {2,'J'} };
	char a, b;
	int a_w = 0, a_d = 0, a_f = 0, b_w = 0, b_d = 0, b_f = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (check_win(a, b) == 1) {
			a_w++;
			b_f++;
			if (a == 'B') {    
				a_list[0]++;
			}
			else if (a == 'C') {
				a_list[1]++;
			}
			else if (a == 'J') {
				a_list[2]++;
			}
		}
		else if (check_win(a, b) == -1) {
			b_w++;
			a_f++;
			if (b == 'B') {
				b_list[0]++;
			}
			else if (b == 'C') {
				b_list[1]++;
			}
			else if (b == 'J') {
				b_list[2]++;
			}
		}
		else if(check_win(a, b) == 0)
		{
			a_d++;
			b_d++;
		}
	}
	char xa = 'B', xb = 'B';
	int x = 0,y = 0;
	for (int i = 0; i < 3; i++) {
		if (x < a_list[i]) {
			x = a_list[i];
			xa = m[i];
		}
		if (y < b_list[i]) {
			y = b_list[i];
			xb = m[i];
		}
	}
	printf("%d %d %d\n", a_w, a_d, a_f);
	printf("%d %d %d\n", b_w, b_d, b_f);
	printf("%c %c\n", xa, xb);
}

//1019
string negate_num(string num) {
	string new_num = "";
	for (int i = 0; i < num.length(); i++) {
		new_num = num[i] + new_num;
	}
	return new_num;
}

string cmp_sort(string str) {
	sort(str.begin(), str.end());
	return str;
}

string str_minus(string str1, string str2) {
	string n = "";
	int flag = 0;
	char a;
	for (int i = 0; i < str1.length(); i++) {
		if (str1[str1.length() - i - 1] - str2[str2.length() - i - 1] - flag >= 0) {
			a = str1[str1.length() - i - 1] - str2[str2.length() - i - 1] - flag + '0';
			n = a + n;
			flag = 0;
		}
		else {
			a = str1[str1.length() - i - 1] - str2[str2.length() - i - 1] - flag + 10 + '0';
			n = a + n;
			flag = 1;
		}
	}
	return n;
}

bool check_num(string str1, string str2) {
	if (str1 == str2) {
		return true;
	}
	return false;
}

void digit_black_hole(){
	string num,num1,num2;
	cin >> num;
	for (int i = num.length(); i < 4; i++) {
		num += "0";
	}
	if (check_num(num, negate_num(num))) {
		cout << num << " - " << num << " = " << "0000" << endl;
	}
	else if (num == "6174") {
		cout << "7641 - 1467 = 6174" << endl;
	}
	else {
		while (num != "6174") {
			num1 = cmp_sort(num);
			num2 = negate_num(num1);
			num = str_minus(num2, num1);
			cout << num2 << " - " << num1 << " = " << num << endl;
			if (check_num(num, negate_num(num))) {
				cout << num << " - " << num << " = " << "0000" << endl;
				break;
			}
		}
	}
}

//1020
class moon_cake {
public:
	double stock, whole_price;
	moon_cake(double s, double w) {
		stock = s;
		whole_price = w;
	}
};

bool cmp_single_price(moon_cake m1, moon_cake m2) {
	return m1.whole_price / m1.stock > m2.whole_price / m2.stock;
}

void moon_cake(){
		double n,d;
	cin >> n >> d;
	double s, p,money = 0;
	vector<moon_cake> moon_cake_list;
	for (int i = 0; i < n; i++) {
		cin >> s;
		moon_cake_list.push_back({ s,0 });
	}
	for (int i = 0; i < n; i++) {
		cin >> p;
		moon_cake_list[i].whole_price = p;
	}
	sort(moon_cake_list.begin(), moon_cake_list.end(), cmp_single_price);
	int i = 0;
	while (d > moon_cake_list[i].stock && i < n - 1) {
		money += moon_cake_list[i].whole_price;
		d -= moon_cake_list[i].stock;
		i++;
	}
	if (n - 1 != i || d < moon_cake_list[i].stock) {
		money += moon_cake_list[i].whole_price / moon_cake_list[i].stock * d;
	}
	else {
		money += moon_cake_list[n - 1].whole_price;
	}
	printf("%.2f\n", money);
}
//1021
void digit_count(){
	vector<int> digit_list(10, 0);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		digit_list[s[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		if (digit_list[i] != 0) {
			cout << i << ":" << digit_list[i] << endl;
		}
	}
}

//1022
void system_add(){
	int A, B, D, x;
	cin >> A >> B >> D;
	int C = A + B;
	string n = "";
	while (C >= D) {
		x = C % D;
		n = (char)(x + '0') + n;
		C /= D;
	}
	if (C != 0)
	n = char(C + '0') + n;
	if (n == "") {
		n = "0";
	}
	cout << n << endl;
}

//1023
void made_minnum(){
	vector<int> number_list(10, 0);
	for (int i = 0; i < 10; i++) {
		cin >> number_list[i];
	}
	string x = "";
	for (int i = 1; i < 10; i++) {
		if (number_list[i] != 0) {
			x = to_string(i);
			number_list[i]--;
			break;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < number_list[i]; j++) {
			x += (char)(i + '0');
		}
	}
	cout << x << endl;
}

//1025
class Node{
public:
	int number,next,now;
	Node();
	Node(int n,int no, int str);
};

Node::Node() {
	number = 0;
	next = 0;
	now = 0;
}
Node::Node(int n,int no, int str) {
	number = n;
	now = no;
	next = str;
}

void reverse_link()
{
	vector<Node> list(100010);
	vector<Node> shunxu;
	vector<Node> reserve;
	int first_, next_, last_, now_;
	cin >> first_;
	int n, long_, number_, address;
	cin >> n >> long_;
	for (int i = 0; i < n; i++) {
		cin >> now_ >> number_ >> next_;
		address = now_;
		list[address] = { number_, now_, next_ };
	}
	address = first_;
	while(address != -1) {
		shunxu.push_back(list[address]);
		address = list[address].next;
	}

	int size = shunxu.size();
	int temp = long_ - 1;

	while (temp < size) {
		for (int i = temp; i > temp - long_; i--) {
			reserve.push_back(shunxu[i]);
		}
		temp += long_;
	}
	for (int i = temp - long_ + 1; i < size; i++) {
		reserve.push_back(shunxu[i]);
	}
	for (int i = 0; i < size - 1; i++) {     
		reserve[i].next = reserve[i + 1].now;
		printf("%05d %d %05d\n", reserve[i].now, reserve[i].number, reserve[i].next);
	}
	printf("%05d %d %d\n", reserve[size - 1].now, reserve[size - 1].number, -1);
}

//1032
map<int, int> a;
struct node
{
	int p, q;
	friend bool operator < (node a, node b) 
	{
		return a.p < b.q;
	}
};

void best_digger()
{
	int n, i, temp, q;
	struct  node max = { -1,-1 };
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> q >> temp;
		a[q] += temp;
	}

	map<int, int>::iterator x = a.begin();
	for (; x != a.end(); x++) {
		if (max.q < x->second) {
			max.p = x->first;
			max.q = x->second;
		}

	}
	cout << max.p << " " << max.q << endl;
}


//1038
void statistics_stu_infomation(){
	vector<int> grade_list(110,0);
	int n,grade;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf_s("%d",&grade);
		grade_list[grade]++;
	}
	cin >> n;
	cin >> grade;
	cout << grade_list[grade];
	for (int i = 0; i < n - 1; i++) {
		scanf_s("%d", &grade);
		cout << " " << grade_list[grade];
	}
	cout << endl;
}

//1035
vector<int> Insertionsort(vector<int> arr, int x) {
	int n = arr[x];
	for (int i = 0; i < x; i++) {
		if (arr[x - i - 1] > n) {
			arr[x - i] = arr[x - i - 1];
		}
		else {
			arr[x - i] = n;
			return arr;
		}
	}
	arr[0] = n;
	return arr;
}

vector<int> Mergesort(vector<int> arr, int x) {
	int z;
	int l = arr.size(),change,m;
	for (int i = 0; i < l - l%x; i += x) {
		z = i;
		for (int k = i + x / 2; k < i + x; k++) {
			while (arr[k] > arr[z] && z < k) { z++;}
			change = arr[k];
			for (int j = 0; j < k - z; j++) {
				arr[k - j] = arr[k - j - 1];
			}
			arr[z] = change;
		}
	}
	if (x > 2) {
		m = l - l % x;
		for (int i = l - l % (x / 2); i < l; i++) {
			while (arr[i] > arr[m] && m < i) { m++; }
			change = arr[i];
			for (int j = 0; j < i - m; j++) {
				arr[i - j] = arr[i - j - 1];
			}
			arr[m] = change;
		}
	}
	return arr;
}

void merge_and_insert(){
	int n,flag = 0,a_f = 0,f_l = 0;
	cin >> n;
	vector<int> new_array(n);
	vector<int> newarray(n);
	vector<int> new_array1(n);
	for (int i = 0; i < n; i++) {
		cin >> new_array[i];
		newarray[i] = new_array[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> new_array1[i];
	}
	int x = 2;
	for (int i = 0; i < n; i++) {
		new_array = Insertionsort(new_array, i);
		for (int j = 0; j < n; j++) {
			if (new_array[j] == new_array1[j]) {
				flag = 1;
			}
			else
			{
				a_f = 1;
			}
		}
		if (flag == 1 && a_f == 0) {
			cout << "Insertion Sort" << endl;
			new_array = Insertionsort(new_array, i + 1);
			cout << new_array[0];
			for (int j = 1; j < n; j++) {
				cout << " " << new_array[j];
			}
			cout << endl;
			f_l = 1;
			break;
		}
		flag = 0;
		a_f = 0;
	}
	flag = 0;
	a_f = 0;
	if (f_l == 0) {
		while (x / 2 < n) {
			newarray = Mergesort(newarray, x);
			for (int j = 0; j < n; j++) {
				if (newarray[j] == new_array1[j]) {
					flag = 1;
				}
				else
				{
					a_f = 1;
				}
			}
			if (flag == 1 && a_f == 0) {
				cout << "Merge Sort" << endl;
				newarray = Mergesort(newarray, 2 * x);
				cout << newarray[0];
				for (int j = 1; j < n; j++) {
					cout << " " << newarray[j];
				}
				cout << endl;
				break;
			}
			flag = 0;
			a_f = 0;
			x *= 2;
		}
	}
}

//1039
void buy_or_no()
{
	vector<int> num1(130,0);
	vector<int> num2(130,0);
	string x1,x2;
	cin>>x1>>x2;
	int flag = -1;
	int more = 0, lose = 0;
	string::iterator p1 = x1.begin();
	string::iterator p2 = x2.begin();
	for (; p1 != x1.end(); p1++) {
		num1[*p1]++;
	}
	for (; p2 != x2.end(); p2++) {
		num2[*p2]++;
	}
	for (int i = 0; i < 130; i++) {
		if (num2[i] > num1[i]) {
			flag = 1;
			lose += num2[i] - num1[i];
		}
		else {
			more += num1[i] - num2[i];
		}
	}
	if (flag == 1) {
		cout << "No " << lose << endl;
	}
	else {
		cout << "Yes " << more << endl;
	}
}

void buy_or_no2(){
	string sell,want;
	cin >> sell >> want;
	sort(sell.begin(),sell.end());
	sort(want.begin(),want.end());
	string result;
	set_difference(want.begin(),want.end(),sell.begin(),sell.end(),inseter(result,result.end()));
}


//1040
void how_many_PAT(){
	string x;
	cin >> x;
	string::iterator p1 = x.begin();
	long p_num = 0, a_num = 0,t_num = 0,now_p_num = 0,now_a_num = 0,now_t_num = 0;
	long number = 0;
	for (; p1 != x.end(); p1++) 
	{
		if (*p1 == 'P') 
		{
			p_num++;
		}
		else if (*p1 == 'A') 
		{
			a_num++;
		}
		else if (*p1 == 'T') 
		{
			t_num++;
		}
	}

	for (p1 = x.begin(); p1 != x.end(); p1++) 
	{
		if (*p1 == 'P') 
		{
			now_p_num++;
		}
		else if (*p1 == 'A') 
		{
			now_a_num++;
			number += now_p_num * (t_num - now_t_num);
			number %= 1000000007;
		}
		else if (*p1 == 'T') 
		{
			now_t_num++;
		}
	}
	cout << number << endl;
}


//1041
void stu_infomation(){
	int n;
	cin >> n;
	map<string, string> m;
	string ID, testPosion, normalPosition;
	for (int i = 0; i < n; i++) {
		cin >> ID >> testPosion >> normalPosition;
		m[testPosion] = ID + ' ' + normalPosition;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> testPosion;
		cout << m[testPosion] << endl;
	}
}

//1042
void statistics_num(){
	int n,max = 0;
	string str;
	getline(cin, str);
	vector<int> number(257, 0);
	string::iterator p = str.begin();
	for (; p != str.end(); p++) {
		if (*p >= 'A'&&*p <= 'Z')*p += 32;
		if (isalpha(*p)) number[*p]++;
		if (max < number[*p]) {
			max = number[*p];
		}
	}
	char x;
	for (int i = 0; i < number.size(); i++) {
		if (max == number[i]) {
			x = i;
			cout << x << " " << max << endl;
			break;
		}
	}
}

//1043
void printPATest(){
	int n;
	string str;
	cin >> str;
	int max = 0;
	char c[6] = { 'P','A','T','e','s','t' };
	vector<int> number(100, 0);
	//PATest

	for (string::iterator p = str.begin(); p != str.end(); p++) {
		if (*p == 'P') {
			number[0]++;
		}
		else if (*p == 'A') {
			number[1]++;
		}
		else if (*p == 'T') {
			number[2]++;
		}
		else if (*p == 'e') {
			number[3]++;
		}
		else if (*p == 's') {
			number[4]++;
		}
		else if (*p == 't') {
			number[5]++;
		}
	}
	int x = 0, num = number[0] + number[1] + number[2] + number[3] + number[4] + number[5];
	while (num != 0) {
		if (number[x] != 0) {
			cout << c[x];
			number[x]--;
			x++;
			num--;
		}
		else {
			x++;
		}
		x = x % 6;
	}
	cout << endl;
}

//1044
void mars_lan(){
	int n,p;
	string first, second;
	int num;
	string get_str,x;
	string gewei[13] = { "tret","jan", "feb", "mar", "apr","may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
	string shiwei[12] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	cin >> n;
	getline(cin, x);
	for (int i = 0; i < n; i++)
	{
		getline(cin,get_str);
		if (isdigit(get_str[0])) {
			istringstream in(get_str);
			in >> num;
			if (num >= 13) {
				if (num % 13 != 0) {
					cout << shiwei[(num - (num % 13)) / 13 - 1] << " " << gewei[num % 13];
				}
				else if (num % 13 == 0) {
					cout << shiwei[num / 13 - 1];
				}
			}
			else 
			{
				cout << gewei[num];
			}
		}
		else {
			int nb;
			int flag = 1;
			p = get_str.find(" ");
			if (p != -1) {
				istringstream in(get_str);
				in >> first >> second;
				for (int x = 0; x <= 11; x++) {
					if (shiwei[x] == first)
						nb = 13 * (x+1);
				}
				for (int x = 0; x < 13; x++) {
					if (gewei[x] == second)
						nb += x;
				}
			}
			else {
				for (int x = 0; x < 13; x++) {
					if (gewei[x] == get_str) {
						nb = x;
						flag = 0;
					}
				}
				if (flag != 0) {
					for (int y = 0; y < 12; y++) {
						if (shiwei[y] == get_str) {
							nb = (y + 1)*(13);
						}
					}
				}
			}
			cout << nb;
			flag = 1;
		}
		cout << endl;
	}
}


//1045
void quick_sort()
{
	int n,max = -1;
	cin >> n;
	vector<int> arr1(n);
	vector<int> arr2(n);
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
		if (arr1[i] > max)
			max = arr1[i];
		arr2[i] = max;
	}
	int min = max,count = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (arr1[i] <= min && arr1[i] >= arr2[i]) {
			arr[count] = arr1[i];
			count++;
		}
		if (arr1[i] < min)
			min = arr1[i];	
	}
	cout << count << endl;
	if (count > 0) {
		cout << arr[count - 1];
		while (count > 1) {
			count--;
			cout << " " << arr[count - 1];
		}
	}
	cout << endl;	
}


//1048
void array_pick(){
	int n;
	cin >> n;
	vector<double> number_array(n);
	for (int i = 0; i < n; i++) {
		cin >> number_array[i];
	}
	double x = 0;
	for (int i = 1; i <= n; i++) {
		x += (long long int)i * (n - i + 1) * number_array[i-1];
	}
	printf("%.2f\n", x);
}

//1050
void screw_matrix(){
	int count,n;
	cin >> count;
	vector<int> arr(count);
	for (int i = 0; i < count; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end(),compare);
	int m = sqrt(count);
	while (true) {
		if (count % m == 0)
			break;
		m--;
	}
	n = count / m;
	int number_ = 0,flag;
	vector<vector<int> > array1(n, vector<int>(m));
	int circle = m/ 2;
	for (int i = 0; i < circle; i++) {
		for (int j = i; j < m - i - 1; j++) {
			array1[i][j] = arr[number_];
			number_++;
		}
		for (int j = i; j < n - i - 1; j++) {
			array1[j][m - i - 1] = arr[number_];
			number_++;
		}
		for (int j = i; j < m - i - 1; j++) {
			array1[n - i -1][m - j - 1] = arr[number_];
			number_++;
		}
		for (int j = i; j < n - i - 1; j++) {
			array1[n - j -1][i] = arr[number_];
			number_++;
		}
	}	
	if (m % 2 == 1) {
		for (int i = 0; i < n - m + 1; i++) {
			array1[circle+i][circle] = arr[number_];
			number_++;
		}
	}
	for (int i = 0;i < n;i++) {
		cout << array1[i][0];
		for (int j = 1; j < m; j++) {
			cout << " " << array1[i][j];
		}
		cout << endl;
	}
}

//1051
void mul_number_m(){
	double r1, p1, r2, p2, a, b;
	cin >> r1 >> p1 >> r2 >> p2;
	a = r1 * r2 *(cos(p1 + p2));
	b = r1 * r2 *(sin(p1 + p2));
	if (a > -0.005 && a < 0)
		printf("0.00");
	else
		printf("%.2lf", a);
	if (b > -0.005 && b < 0)
		printf("+0.00i");
	else if (b <= -0.005)
		printf("%.2lfi", b);
	else printf("+%.2lfi", b);
}

//1052
void acting_cute(){
	vector<string> hand_list;
	vector<string> eye_list;
	vector<string> mouth_list;
	string str,s = "";
	getline(cin, str);
	int l = str.length();
	int flag = 0;
	for (int i = 0; i < l; i++) {
		if (str[i] == ']') {
			flag = -1;
		}
		if (flag == -1 && s != "") {
			hand_list.push_back(s);
			s = "";
		}
		if (flag == 1) {
			s += str[i];
		}
		
		if (str[i] == '[') {
			flag = 1;
		}
	}
	if (flag == -1 && s != "") {
		hand_list.push_back(s);
		s = "";
	}
	getline(cin, str);
	l = str.length();
	flag = 0;
	for (int i = 0; i < l; i++) {
		if (str[i] == ']') {
			flag = -1;
		}
		if (flag == -1 && s != "") {
			eye_list.push_back(s);
			s = "";
		}
		if (flag == 1) {
			s += str[i];
		}
		
		if (str[i] == '[') {
			flag = 1;
		}
	}
	if (flag == -1 && s != "") {
		eye_list.push_back(s);
		s = "";
	}
	getline(cin, str);
	l = str.length();
	flag = 0;
	for (int i = 0; i < l; i++) {
		if (str[i] == ']') {
			flag = -1;
		}
		if (flag == 1) {
			s += str[i];
		}
		if (flag == -1 && s!= "") {
			mouth_list.push_back(s);
			s = "";
		}
		if (str[i] == '[') {
			flag = 1;
		}
		
	}
	if (flag == -1 && s != "") {
		mouth_list.push_back(s);
		s = "";
	}
	int n,l_h,l_e,m,r_e,r_h,s_flag = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l_h >> l_e >> m >> r_e >> r_h;
		if (l_h > hand_list.size() || r_h > hand_list.size() || m > mouth_list.size() || l_e > eye_list.size() || r_e > eye_list.size() || l_h < 1 || r_h < 1 || m < 1 || l_e < 1 || r_e < 1) {
			cout << "Are you kidding me? @\\/@" << endl;
		}
		else {
			cout << hand_list[l_h - 1] << "(" << eye_list[l_e - 1] << mouth_list[m - 1] << eye_list[r_e - 1] << ")" << hand_list[r_h - 1] << endl;
		}
	}
}

//1053
void house_empty_percent(){
	double house_n, ele_threshlod, obeservation_threshlod, single_observation_n, flag1 = 0, flag2 = 0,flag1_ = 0,single_a_obervation_grade;
	cin >> house_n >> ele_threshlod >> obeservation_threshlod;
	for (int i = 0; i < house_n; i++) {
		cin >> single_observation_n;
		for (int j = 0; j < single_observation_n; j++) {
			cin >> single_a_obervation_grade;
			if (single_a_obervation_grade < ele_threshlod) {
				flag1_++;
			}
		}
		if (flag1_ >(single_observation_n) / 2) {
			if(single_observation_n > obeservation_threshlod)
				flag2++;
			else
				flag1++;
		}
		flag1_ = 0;
	}	
	printf("%.1lf%% %.1lf%%", flag1 / house_n * 100, flag2 / house_n * 100);
}

//1055
class people {
public:
	string name;
	int high;
	people(string n, int h) {
		name = n;
		high = h;
	}
	people() {
	}
	void print_info() {
		cout << this->name << " " << this->high << endl;
	}
};

bool compare(people a,people b) {
	if (a.high != b.high) {
		return a.high < b.high;
	}
	else {
		return a.name > b.name;
	}
}

void take_photo()
{	
	int n,row;
	cin >> n >> row;
	string x_name = "";
	int x_high = 0;
	vector<people> people_list;
	vector<people> people_set_list;
	for (int i = 0; i < n; i++) {
		cin >> x_name >> x_high;
		people_list.push_back({ x_name,x_high });
		people_set_list.push_back({ x_name,x_high });
	}
	sort(people_list.begin(), people_list.end(), compare);
	
	int m = n / row;
	for (int i = 0; i < row - 1; i++) {
		if (m % 2 == 1) {
			people_set_list[i * m + m / 2] = people_list[i * m + m - 1];
			for (int j = 0; j < m / 2; j++) {
				people_set_list[i * m + j] = people_list[i * m + 2 * j + 1];
				people_set_list[i * m + m - j - 1] = people_list[i * m + 2 * j];
			}
		}
		else {
			for (int j = 0; j < m / 2; j++) {
				people_set_list[i * m + j] = people_list[i * m + 2 * j];
				people_set_list[i * m + m - j - 1] = people_list[i * m + 2 * j + 1];
			}
		}
	}
	if ((n - m * (row - 1)) % 2 == 1) {
		people_set_list[m * (row - 1) + m / 2] = people_list[m * (row - 1) + m - 1];
		for (int j = 0; j < (n - m * (row - 1)) / 2; j++) {
			people_set_list[m * (row - 1) + j] = people_list[m * (row - 1) + 2 * j + 1];
			people_set_list[m * (row - 1) + m - j - 1] = people_list[m * (row - 1) + 2 * j];
		}
	}
	else {
		for (int j = 0; j < (n - m * (row - 1)) / 2; j++) {
			people_set_list[m * (row - 1) + j] = people_list[m * (row - 1) + 2 * j];
			people_set_list[m * (row - 1) + (n - m * (row - 1)) - j - 1] = people_list[m * (row - 1) + 2 * j + 1];
		}
	}
	cout << people_set_list[m * (row - 1)].name;
	for (int i = 1; i < (n - m * (row - 1)); i++) {
		cout << " " << people_set_list[i + m * (row - 1)].name;
	}
	cout << endl;
	for (int i = row - 2; i >= 0; i--) {
		cout << people_set_list[i * m].name;
		for (int j = 1; j < m; j++) {
			cout << " " << people_set_list[i * m + j].name;
		}
		cout << endl;
	}
}

//1058
class question {
public:
	string answer;
	int nu,an_n, t_an_n,wrong_n,grade;
	question(int n,int g,int n1,int n2,string an) {
		nu = n;
		grade = g;
		an_n = n1;
		t_an_n = n2;
		answer = an;
		wrong_n = 0;
	}
	void question_print() {
		cout << grade << " " << an_n << " " << t_an_n << " " << answer << " " << wrong_n << endl;
	}
};

void choose()
{	
	int stu_n, question_n;
	cin >> stu_n >> question_n;
	vector<question> question_list;
	vector<int> student_grade_list(stu_n,0);
 	string answer = "";
	string a,ans;
	int n1, n2,g;
	for (int i = 0; i < question_n; i++) {
		cin >> g >> n1 >> n2;
		for (int j = 0; j < n2; j++) {
			cin >> a;
			answer += a;
		}
		question_list.push_back({i+1,g,n1,n2,answer });
		answer = "";
	}
	for (int i = 0; i < stu_n; i++) {
		string answer = "";
		for (int j = 0; j < question_n; j++) {
			cin >> answer;
			n1 = answer[1] - 48;
			for (int k = 0; k < n1; k++) {
				cin >> answer;
				ans += answer;
			}
			ans.pop_back();
			if (ans != question_list[j].answer) {
				question_list[j].wrong_n++;
			}
			else {
				student_grade_list[i] += question_list[j].grade;
			}
			ans = "";
		}
	}


	int max = -1;
	for (int i = 0; i < stu_n; i++) cout << student_grade_list[i] << endl;
	for (int i = 0; i < question_n; i++) {
		if (max < question_list[i].wrong_n)
		{
			max = question_list[i].wrong_n;
		}
	}
	if (max == 0) {
		cout << "Too simple" << endl;
	}
	else {
		cout << max;
		for (int i = 0; i < question_n; i++) {
			if (question_list[i].wrong_n == max) {
				cout << " " << question_list[i].nu;
			}
		}
		cout << endl;
	}
}

//1059
void c_match()
{
	vector<bool> is_prime(10030, 1);
	is_prime = set_(is_prime, 10020);
	vector<int> student_list(10020, -1);
	int n,n1,id,f;
	cin >> n;
	cin >> f;
	student_list[f] = 0;

	for (int i = 1; i < n; i++) {
		cin >> id;
		if (is_prime[i+1] == 1) {
			student_list[id] = 1;
		}
		else {
			student_list[id] = 2;
		}
	}

	cin >> n1;
	for (int i = 0; i < n1; i++) {
		cin >> id;
		if (student_list[id] == -1) {
			printf("%04d", id);
			cout << ": Are you kidding?" << endl;
		}
		else if (student_list[id] == 0) {
			printf("%04d", id);
			cout << ": Mystery Award" << endl;
			student_list[id] = 3;
		}
		else if (student_list[id] == 1) {
			printf("%04d", id);
			cout << ": Minion" << endl;
			student_list[id] = 3;
		}
		else if(student_list[id] == 2) {
			printf("%04d", id);
			cout << ": Chocolate" << endl;
			student_list[id] = 3;
		}
		else if (student_list[id] == 3) {
			printf("%4d", id);
			cout << ": Checked" << endl;
		}
	}
}

//1060
void aidingdunnum(){
	int n;
	cin >> n;
	vector<int> arr(1000000);
	arr[0] = -1;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin() + 1, arr.end(), compare);
	int x = 0, a = 0;

	while (a <= n && arr[x] > x) {
		x++;
		a++;
	}
	cout << a << endl;
}		

//1061
void judge(){
	int stu_n,ques_n,stu_a;
	cin >> stu_n >> ques_n;
	vector<int> stu_list(stu_n,0);
	vector<int> ques_list1(ques_n);
	vector<int> ques_list2(ques_n);
	for (int i = 0; i < ques_n; i++) {
		cin >> ques_list1[i];
	}
	for (int i = 0; i < ques_n; i++) {
		cin >> ques_list2[i];
	}
	for (int i = 0; i < stu_n; i++) {
		for (int j = 0; j < ques_n; j++) {
			cin >> stu_a;
			if (stu_a == ques_list2[j]) {
				stu_list[i] += ques_list1[j];
			}
		}
	}
	for (int i = 0; i < stu_n; i++) {
		cout << stu_list[i] << endl;
	}
}

//1062
int gcd(int a,int b) {
	int temp;
	while (b) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

void simple_fenshu(){
	double a1, a2, b1, b2, c;
	int x, y;
	double aa;
	vector<int> arr;
	scanf_s("%lf/%lf %lf/%lf %lf", &a1, &a2, &b1, &b2, &c);
	x = min(a1 * c / a2, b1 * c / b2) + 1;
	y = max(a1 * c / a2, b1 * c / b2);
	if (y == max(a1 * c / a2, b1 * c / b2)) {
		y = y - 1;
	}
	for (int i = x; i <= y; i++) {
		if (gcd(i, c) == 1) {
			arr.push_back(i);
		}
	}
	cout << arr[0] << "/" << c;
	int n = arr.size();
	if (n > 1) {
		for (int i = 1; i < n; i++) {
			cout << " " << arr[i] << "/" << c;
		}
	}
	cout << endl;
}

//1063
void cal_radius(){
	int n;
	cin >> n;
	vector<double> radius;
	double a, b,max = -1;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		radius.push_back(sqrt(a * a + b * b));
	}
	for (int i = 0; i < n; i++) {
		if (max < radius[i]) {
			max = radius[i];
		}
	}
	printf("%.2lf", max);
	cout << endl;
}

//1064
void friend_num(){
	vector<int> number_(50, 0);
	int n,x = 0,y,count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> y;
		while (y != 0) {
			x += y % 10;
			y /= 10;
		}
		number_[x]++;
		x = 0;
	}
	for (int i = 0; i < 50; i++) {
		if (number_[i] != 0) {
			count++;
		}
	}
	cout << count << endl;
	int flag = 0;
	for (int i = 0; i < 50; i++) {
		if (number_[i] != 0 && flag != 1) {
			flag = 1;
			cout << i;
		}
		else if(flag == 1 && number_[i] != 0){
			cout << " " << i;
		}
	}
	cout << endl;
}

//1065
void single_dog(){
	vector<int> list1(100010, -1);
	vector<int> list2(100010, -1);
	int x, y, n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		list1[x] = y;
		list1[y] = x;
	}
	cin >> n;
	int a = n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (list2[x] == -1) {
			list2[x] = 0;
		}
		if(list1[x] != -1){
			if (list2[list1[x]] == 0) {
				list2[list1[x]] = -1;
				list2[x] = -1;
				a -= 2;
			}
		}
	}
	cout << a << endl;
	if (a > 0) {
		int flag = 0;
		for (int i = 0; i <= 100005; i++) {
			if (flag == 0 && list2[i] == 0) {
				if (i == 0) {
					cout << "00000";
				}
				else {
					printf("%05d", i);
				}
				flag = 1;
			}
			else if (flag == 1 && list2[i] == 0) {
				printf(" %05d", i);
			}
		}
		cout << endl;
	}
}

//1066
void picture_deal(){
	int column, row, lower, high, replace_num,x;
	vector<int> number;
	cin >> column >> row >> lower >> high >> replace_num;
	for (int i = 0; i < column * row; i++) {
		cin >> x;
		if (x >= lower && x <= high) {
			number.push_back(replace_num);
		}
		else {
			number.push_back(x);
		}
	}
	for (int i = 0; i < column; i++) {
		printf("%03d", number[i * row]);
		for (int j = 1; j < row; j++) {
			printf(" %03d", number[i * row + j]);
		}
		cout << endl;
	}
}

//1067
void attempt_password(){
	string password,user_give_password;
	int most_wrong_time, wrong_time = 0;
	cin >> password >> most_wrong_time;
	getchar();
	for (int i = 0; i <= most_wrong_time; i++) {
		getline(cin,user_give_password);
		if (user_give_password == "#") {
			break;
		}

		if (user_give_password == password) {
			cout << "Welcome in" << endl;
			break;
		}
		else {	
			cout << "Wrong password: " << user_give_password << endl;
			wrong_time ++;
			if (wrong_time == most_wrong_time) {
				cout << "Accout locked" << endl;
				break;
			}
		}
	}
}

//1068
bool is_adequate_point(vector<vector<int>> arr,int x,int y,int min_differ) {
	if (fabs(arr[x][y] - arr[x + 1][y]) <= min_differ)return false;
	else if (fabs(arr[x][y] - arr[x + 1][y + 1]) <= min_differ)return false;
	else if (fabs(arr[x][y] - arr[x][y + 1]) <= min_differ) return false;
	else if (fabs(arr[x][y] - arr[x - 1][y + 1]) <= min_differ) return false;
	else if (fabs(arr[x][y] - arr[x - 1][y]) <= min_differ)return false;
	else if (fabs(arr[x][y] - arr[x - 1][y - 1]) <= min_differ)return false;
	else if (fabs(arr[x][y] - arr[x][y - 1]) <= min_differ)return false;
	else if (fabs(arr[x][y] - arr[x + 1][y - 1]) <= min_differ)return false;
	return true;
}

class point {
public:
	int x, y, color, num;
	point(int x1, int y1, int c) {
		x = x1;
		y = y1;
		color = c;
		num = 1;
	}
};

void find_red_from_green(){
	int column, row, min_differ, color;
	cin >> column >> row >> min_differ;
	vector<vector<int>> array1(2 + row, vector<int>(2 + column,0));
	map<int,int> color_list;
	int n = color_list.size(), x1, y1, color1, z = 0;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= column; j++) {
			scanf_s("%d", &array1[i][j]);
			color_list[array1[i][j]]++;
		}
	}
	int flag = 0;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= column; j++) {
			if (color_list[array1[i][j]] == 1 && is_adequate_point(array1, i, j, min_differ)) {
				x1 = i; y1 = j; color1 = array1[i][j];
				z++;
			}
		}
	}
	

	if (z == 0)
	{
		cout << "Not Exist" << endl;
	}
	else if (z > 1) {
		cout << "Not Unique" << endl;
	}
	else {
		cout << "(" << y1 << ", " << x1 << "): " << color1 << endl;
	}
}

//1069
void lottery_draw(){
	int n, level, first,x = 0,flag = 0;
	string name;
	set<string> name_list;
	int long_;
	cin >> n >> level >> first;
	for (int i = 1; i <= n; i++) {
		cin >> name;
		if (i == first) {
			flag = 1;
			name_list.insert(name);
			cout << name << endl;
		}else if ((i - x - first) % level == 0 && flag == 1) {
			long_ = name_list.size();
			name_list.insert(name);
			if (long_ == name_list.size()) {
				x++;
			}
			else {
				cout << name << endl;
			}
		}
	}
	if (name_list.size() == 0) {
		cout << "Keep going..." << endl;	
	}
}

//1070
void knot(){
	int n;
	cin >> n;
	vector<double> num_list(n,0);
	for (int i = 0; i < n; i++) {
		cin >> num_list[i];
	}
	
	sort(num_list.begin(), num_list.end());
	double x = num_list[0];
	for (int i = 0; i < n; i++) {
		x = (x / 2 + num_list[i]/2);
	}
	int l = x;
	cout << l << endl;
}

//1071
void gambel(){
	int T, K, n1, b, t, n2;
	cin >> T >> K;
	for (int i = 0; i < K; i++) {
		cin >> n1 >> b >> t >> n2;
		if (t > T) {
			cout << "Not enough tokens.  Total = " << T <<"."<< endl;
		}
		else if ((b == 1 && n2 > n1) || (b == 0 && n1 > n2)) {
			T += t;
			cout << "Win " << t <<"!  Total = "<< T <<"." << endl;
		}
		else if ((b == 1 && n2 < n1) || (b == 0 && n1 < n2)) {
			T -= t;
			cout << "Lose " << t << ".  Total = " << T << "." << endl;
		}
		if (T == 0) {
			cout << "Game Over." << endl;
			break;
		}
	}
}

//1072
class stu_ {
public:
	string forbidden_object,name;
	stu_(string n, string f) {
		name = n;
		forbidden_object = f;
	}
};
void school_begin() {
	int stu_n, forbidden_n, tools_number, flag = 0, stu_nu = 0, for_n = 0;
	string stu_name, o, obejcts = "";
	cin >> stu_n >> forbidden_n;
	vector<string> forbiddem_list(forbidden_n);
	vector<stu_> f_stu_list;
	for (int i = 0; i < forbidden_n; i++) {
		cin >> forbiddem_list[i];
	}
	for (int i = 0; i < stu_n; i++) {
		cin >> stu_name;
		cin >> tools_number;
		for (int j = 0; j < tools_number; j++) {
			cin >> o;
			for (int k = 0; k < forbidden_n; k++) {
				if (o == forbiddem_list[k]) {
					if (flag == 0) {
						flag = 1;
						obejcts += o;
						for_n++;
						stu_nu++;
					}
					else if (flag == 1) {
						obejcts += (" " + o);
						for_n++;
					}
				}
			}
		}
		if (flag == 1) {
			f_stu_list.push_back({stu_name,obejcts});
		}
		obejcts = "";
		flag = 0;
	}
	int si = f_stu_list.size();
	for (int i = 0; i < si; i++) {
		cout << f_stu_list[i].name << ": " << f_stu_list[i].forbidden_object << endl;
	}
	cout << stu_nu<< " " << for_n << endl;
}

//1073
class question{
public:
	int answer_n,answer_num;
	double answer_grade;
	string answer;
	question(double g, int a_n,int n,string a) {
		answer_grade = g;
		answer_num = a_n;
		answer_n = n;
		answer = a;
	}
	void question_print() {
		cout << answer_grade << " " << answer_num << " " << answer_n << " " << answer << endl;
	}
};

void many_chosse() {
	int question_n, stu_n,question_long,all_question_long = 0,answer_num,x,flag = 0;
	double question_grade,student_grade = 0;
	char a;
	string ll,student__ = "";
	string answ[] = { "a","b","c","d","e","f"};
	map<string, int> answer_list1;
	string answer_ = "",ans;
	cin >> stu_n >> question_n;
	vector<string> answer_list;
	vector<question> quest_list;
	vector<double> student_grade_list;
	for (int i = 0; i < question_n; i++) {
		cin >>question_grade >>answer_num >> question_long;
		all_question_long += answer_num;
		for (int j = 0; j < question_long; j++) {
			cin >> ans;
			answer_ += ans;
		}
		quest_list.push_back({question_grade, answer_num, question_long, answer_ });
		answer_ = "";
	}
	for (int i = 0; i < stu_n; i++) {
		for (int j = 0; j < question_n; j++) {
			cin >> a >> x;
			for (int k = 0; k < x; k++) {
				cin >> a;
				student__ += a;
			}
			cin >> a;
			for (int k = 0; k < quest_list[j].answer_num; k++) {
				if ((student__.find(answ[k]) == -1) != (quest_list[j].answer.find(answ[k])==-1)) {
					if(quest_list[j].answer.find(answ[k]) == -1)
						flag = 1;
					if(student__.find(answ[k]) == -1 && flag != 1) {
						flag = 2;
					}
					if (answer_list1[to_string(j + 1) + "-" + answ[k]] == 0)
						answer_list.push_back(to_string(j + 1) + "-" + answ[k]);
					answer_list1[to_string(j + 1) + "-" + answ[k]]++;
				}
			}
			if (flag == 2) {
				student_grade += quest_list[j].answer_grade / 2;
			}
			else if (flag == 0) {
				student_grade += quest_list[j].answer_grade;
			}
			else if (flag == 1) {
			}
			flag = 0;
			student__ = "";
		}
		student_grade_list.push_back(student_grade);
		student_grade = 0;
	}
	for (int i = 0; i < student_grade_list.size(); i++) {
		printf("%.1lf\n", student_grade_list[i]);
	}
	int size_ = answer_list.size(),max_ = -1;
	for (int i = 0; i < size_; i++) {
		if (max_ < answer_list1[answer_list[i]]) {
			max_ = answer_list1[answer_list[i]];
		}
	}
	if (max_ > 0) {
		for (int i = 0; i < size_; i++) {
			if (max_ == answer_list1[answer_list[i]]) {
				cout << max_ << " " << answer_list[i] << endl;
			}
		}
	}
	else {
		cout << "Too simple" << endl;
	}
}	

//1075

class Node {
public:
	int address, num, next;
	Node() {
		address = -1;
		num = -1;
		next = -1;
	}

	Node(int a, int n, int ne) {
		address = a;
		num = n;
		next = ne;
	}

	void node_print() {
		cout << address << " " << num << " " << next << endl;
	}
};

void link_classify() {
	int first, n, bound,addr,now_val,net_;
	cin >> first >> n >> bound;
	vector<Node> node_list(100010, {-1,-1,-1});
	vector<Node> nodelist_1;
	vector<Node> nodelist_2;
	vector<Node> nodelist_3;
	for (int i = 0; i < n; i++) {
		cin >> addr >> now_val >> net_;
		node_list[addr] = { addr,now_val,net_ };
	}

	while (first != -1) {
		if (node_list[first].num < 0) {
			nodelist_1.push_back(node_list[first]);
		}
		else if (node_list[first].num > bound) {
			nodelist_3.push_back(node_list[first]);
		}
		else if(node_list[first].num >= 0 && node_list[first].num <= bound){
			nodelist_2.push_back(node_list[first]);
		}
		first = node_list[first].next;		
	}
	int l1 = nodelist_1.size(), l3 = nodelist_3.size(),l2 = nodelist_2.size();
	if (l1 > 0) {
		if (l1 > 1) {
			for (int i = 0; i < l1 - 1; i++) {
				printf("%05d %d %05d\n", nodelist_1[i].address, nodelist_1[i].num, nodelist_1[i + 1].address);
			}
		}
		if (l2 > 0) {
			printf("%05d %d %05d\n", nodelist_1[l1 - 1].address, nodelist_1[l1 - 1].num, nodelist_2[0].address);
		}
		if(l2 == 0 && l3 > 0){
			printf("%05d %d %05d\n", nodelist_1[l1 - 1].address, nodelist_1[l1 - 1].num, nodelist_3[0].address);
		}
		if(l2 == 0 && l3 == 0){
			printf("%05d %d %05d\n", nodelist_1[l1 - 1].address, nodelist_1[l1 - 1].num, -1);
		}
	}
	if (l2 > 1) {
		if (l2 > 1) {
			for (int i = 0; i < l2 - 1; i++) {
				printf("%05d %d %05d\n", nodelist_2[i].address, nodelist_2[i].num, nodelist_2[i + 1].address);
			}
		}
		if (l3 > 1) {
			printf("%05d %d %05d\n", nodelist_2[l2 - 1].address, nodelist_2[l2 - 1].num, nodelist_3[0].address);
		}
		else {
			printf("%05d %d %05d\n", nodelist_2[l2 - 1].address, nodelist_2[l2 - 1].num, -1);
		}
	}
	if (l3 > 0) {
		if(l3 > 1){
			for (int i = 0; i < l3 - 1; i++) {
				printf("%05d %d %05d\n", nodelist_3[i].address, nodelist_3[i].num, nodelist_3[i + 1].address);
			}
		}
		printf("%05d %d %d\n", nodelist_3[l3 - 1].address, nodelist_3[l3 - 1].num, -1);
	}
}

//1076
void wifi_password(){
	int n;
	string x,password = "";
	map<char, string> mp = { {'A',"1"},{'B',"2"},{'C',"3"},{'D',"4"} };
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> x;
			if (x[2] == 'T') {
				password += mp[x[0]];
			}
		}
	}
	cout << password << endl;
}

//1077
void cal_grade(){
	double n, full_marks,count = 0,teacher_score,score,all_score = 0,max = -1,min = 100;
	cin >> n >> full_marks;
	for (double i = 0; i < n; i++) {
		cin >> teacher_score;
		for (double j = 0; j < n - 1; j++) {
			cin >> score;
			if (score <= full_marks && score >= 0) {
				if (max < score)
					max = score;
				if (min > score)
					min = score;
				all_score += score;
				count++;
			}
		}
		double s = (teacher_score + (all_score - max - min) / (count - 2))/2;
		int m;
		if (s - floor(s) >= 0.5) {
			m = s + 1;
		}else{
			m = s;
		}
		cout << m << endl;
		count = 0;
		all_score = 0;
		max = -1;
		min = 100;
	}
}


//1078
void decode_encode(){
	string get,get_str,number = "";
	cin >> get;
	getchar();
	getline(cin, get_str);
	long long length = get_str.size();
	int count = 0;
	vector<char> char_list;
	vector<int> num_list;
	if (get == "C") {
		char_list.push_back(get_str[0]);
		num_list.push_back(1);
		for (long long i = 1; i < length; i++) {
			if (get_str[i] != get_str[i - 1]) {
				char_list.push_back(get_str[i]);
				num_list.push_back(1);
				count++;
			}
			else {
				num_list[count]++;
			}
		}
		for (int i = 0; i < count + 1; i++) {
			if (num_list[i] == 1) {
				printf("%c", char_list[i]);
			}
			else {
				printf("%d%c", num_list[i], char_list[i]);
			}
		}
	}
	else if (get == "D") {
		for (long long i = 0; i < length; i++) {
			if (isdigit(get_str[i])) {
				number += get_str[i];
			}
			else if(!isdigit(get_str[i]) && isdigit(get_str[i - 1])){
				num_list.push_back(stoi(number));
				char_list.push_back(get_str[i]);
				number = "";
				count++;
			}
			else if (!isdigit(get_str[i]) && !isdigit(get_str[i - 1])){
				num_list.push_back(1);
				char_list.push_back(get_str[i]);
				count++;
			}
		}
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < num_list[i]; j++) {
				printf("%c",char_list[i]);
			}
		}
	}
	cout << endl;
}

//1079
string change(string n1) {
	string n2 = "";
	int l = n1.size();
	for (int i = 0; i < l; i++) {
		n2 += n1[l - i - 1];
	}
	return n2;
}

int is(string n1) {
	int l = n1.size();
	for (int i = 0; i < l; i++) {
		if (n1[l - i - 1] != n1[i])
			return 0;
	}
	return 1;
}

string add(string n1,string n2) {
	int l = n1.size();
	int k, j;
	string x = "";
	int flag = 0,a;
	for (int i = l - 1; i >= 0; i--) {
		k = n1[i];
		j = n2[i];
		a = k + j + flag - 96;
		if (a >= 10) {
			flag = 1;
			a = a - 10;
		}
		else if(a < 10){
			flag = 0;
		}
		x = to_string(a) + x;
	}
	if (flag == 1) {
		x = "1" + x;
	}
	return x;
}

void palindromic_number(){
	string number, change_number;
	cin >> number;
	int count = 0;
	change_number = change(number);
	while (change_number != number) {
		cout << number << " + " << change_number << " = " << add(number, change_number) << endl;
		number = add(number,change_number);
		change_number = change(number);
		count++;
		if (count == 10) {
			cout << "Not found in 10 iterations." << endl;
			break;
		}
	}
	if(count != 10)
	cout << number << " is a palindromic number." << endl;
}

//1080
class student {
public:
	string name;
	double daily_grade, mid_exam_grade, final_exam_grade;
	int last_grade;

	student(string n,double d_g) {
		name = n;
		daily_grade = d_g;
		mid_exam_grade = -1;
		final_exam_grade = -1;
		last_grade = -1;
	}
	void student_print() {
		printf("%s %.f %.f %.f %d\n", name.c_str(), daily_grade, mid_exam_grade, final_exam_grade,last_grade);
	}
};

bool cmp(student a, student b) {
	if (a.last_grade != b.last_grade) {
		return a.last_grade > b.last_grade;
	}
	else{
		return a.name < b.name;
	}
}

void mooc_sort(){
	vector<student> stu_list;
	map<string, int> map_list;
	stu_list.push_back({"-1", -1 });
	double daily_exam_num, mid_exam_num, final_exam_num, count = 1,grade;
	string name;
	cin >> daily_exam_num >> mid_exam_num >> final_exam_num;
	for (int i = 0; i < daily_exam_num; i++) {
		cin >> name >> grade;
		if (grade >= 200) {
			map_list[name] = count;
			stu_list.push_back({ name,grade });	
			count++;
		}
	}
	for (int i = 0; i < mid_exam_num; i++) {
		cin >> name >> grade;
		if (map_list[name] != 0) {
			stu_list[map_list[name]].mid_exam_grade = grade;
		}
	}
	for (int i = 0; i < final_exam_num; i++) {
		cin >> name >> grade;
		if (map_list[name] != 0) {
			stu_list[map_list[name]].final_exam_grade = grade;
		}
	}
	double last_grade;
	for (int i = 1; i < count; i++) {
		if (stu_list[i].mid_exam_grade > stu_list[i].final_exam_grade) {
			last_grade = stu_list[i].mid_exam_grade * 0.4 + stu_list[i].final_exam_grade * 0.6;
			if (last_grade - floor(last_grade) >= 0.5) {
				stu_list[i].last_grade = last_grade + 1;
			}
			else {
				stu_list[i].last_grade = last_grade;
			}
		}
		else {
			stu_list[i].last_grade = stu_list[i].final_exam_grade;
		}
	}
	sort(stu_list.begin() + 1, stu_list.end(), cmp);
	for (int i = 0; i < count; i++) {
		if (stu_list[i].last_grade != -1 && stu_list[i].last_grade >= 60) {
			stu_list[i].student_print();
		}
	}
}

//1081
int is_hefa(string password) {
	int l = password.size(),a_flag = 0,n_flag = 0,e_flag = 0;
	if (l < 6) {
		return 2;
	}
	for (int i = 0; i < l; i++) {
		if (isalpha(password[i])) {
			a_flag = 1;
		}
		else if (isdigit(password[i])) {
			n_flag = 1;
		}
		else if(password[i] != '.'){
			e_flag = 1;
		}
	}
	if (a_flag == 1 && n_flag == 1 && e_flag == 0) {
		return 1;
	}
	else if (e_flag == 1) {
		return 3;
	}
	else if (a_flag == 1 && n_flag == 0) {
		return 4;
	}
	else if (a_flag == 0) {
		return 5;
	}
}

void check_password(){
	int n,x;
	string password;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		getline(cin,password);
		switch (is_hefa(password))
		{
		case 1:
			cout << "Your password is wan mei." << endl;
			break;
		case 2:
			cout << "Your password is tai duan le." << endl;
			break;
		case 3:
			cout << "Your password is tai luan le." << endl;
			break;
		case 4:
			cout<<"Your password needs shu zi." <<endl;
			break;
		case 5:
			cout << "Your password needs zi mu." << endl;
			break;
		}
	}
}

//1082
void shoot_match(){
	int n,max = -1,min = 10000,grade,x,y;
	string id,max_id,min_id;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> id >> x >> y;
		grade = x * x + y * y;
		if (min > grade) {
			min_id = id;
			min = grade;
		}
		if (max < grade) {
			max = grade;
			max_id = id;
		}
	}
	cout << min_id << " " << max_id << endl;
}

//1083
void is_exist_same_num(){
	int n,x;
	cin >> n;
	vector<int> number_list(n + 2,0);
	for (int i = 1; i <= n;i++) {
		cin >> x;
		number_list[abs(x - i)]++;
	}
	for (int i = n; i >= 0; i--) {
		if (number_list[i] > 1) {
			cout << i << " " << number_list[i] << endl;
		}
	}
}

//1084
string l_array(string str) {
	int l = str.length(),count = 1;
	char x;
	string new_str = "";
	new_str += str[0];
	if (l == 1) {
		return str + "1";
	}
	for (int i = 1; i < l; i++) {
		if (str[i] != str[i - 1]) {
			new_str += to_string(count) + str[i];
			count = 1;
		}
		else if (str[i] == str[i - 1]) {
			count++;
		}
	}
	new_str += to_string(count);
	return new_str;
}
void view_array(){
	string first_str;
	int n;
	cin >> first_str >> n;
	for (int i = 1; i < n; i++) {
		first_str = l_array(first_str);
	}
	cout << first_str << endl;
}

//1085
class school {
public:
	int level,stu_num,last_grade;
	string school_name;
	double grade;
	school(string s_n,double g) {
		school_name = s_n;
		grade = g;
		stu_num = 1;
		level = 0;
		last_grade = g;
	}
	void school_pirnt() {
		printf("%d %s %d %d\n", level, school_name.c_str(), last_grade, stu_num);
	}
	void fresh_grade() {
		last_grade = grade;
	}
};

bool compare(school a,school b) {
	if (a.last_grade != b.last_grade) {
		return a.last_grade > b.last_grade;
	}
	else if (a.stu_num != b.stu_num) {
		return a.stu_num < b.stu_num;
	}
	else if(a.school_name != b.school_name){
		return a.school_name < b.school_name;
	}
}
void pat_section_list(){
	int n,count = 1;
	cin >> n;
	string id, school_;
	double grade;
	vector<school> school_list;
	school_list.push_back({ "1",-1 });
	map<string, int> map_list;
	for (int i = 0; i < n; i++) {
		cin >> id >> grade >> school_;
		if (id[0] == 'B') {
			grade /= 1.5;
		}
		else if (id[0] == 'T') {
			grade *= 1.5;
		}
		for (int j = 0; j < school_.length(); j++) {
			school_[j] = tolower(school_[j]);
		}
		if (map_list[school_] == 0) {
			map_list[school_] = count;
			count++;
			school_list.push_back({ school_,grade });
		}
		else if(map_list[school_] != 0){
			school_list[map_list[school_]].stu_num++;
			school_list[map_list[school_]].grade += grade;
			school_list[map_list[school_]].fresh_grade();
		}
	}
	sort(school_list.begin() + 1, school_list.end(), compare);
	int l = school_list.size();
	cout << l - 1 << endl;
	school_list[1].level = 1;
	school_list[1].school_pirnt();
	for (int i = 2; i < l; i++) {
		if (school_list[i].last_grade == school_list[i - 1].last_grade) {
			school_list[i].level = school_list[i - 1].level;
		}
		else {
			school_list[i].level = i;
		}
		school_list[i].school_pirnt();
	}
}

//1086
void never_talk(){
	int n, m;
	cin >> n >> m;
	int x = n * m;
	int y = 0;
	while (x > 0) {
		y = y * 10 + x % 10;
		x /= 10;
	}
	cout << y << endl;
}

//1087
void how_many_value(){
	int n;
	cin >> n;
	vector<int> list1(2 * n, 0);
	for (int i = 1; i <= n; i++) {
		list1[i / 2 + i / 3 + i / 5]++;
	}
	int count = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (list1[i] != 0) {
			count++;
		}
	}
	cout << count << endl;
}

//1088
void thrible_went(){
	int n;
	double u_grade, x, y;
	cin >> u_grade >> x >> y;
	double j,a = 10,b = 10,c = 10,flag = 0;
	for (int i = 10; i < 100; i++) {
		j = (i % 10) * 10 + i / 10;
		if (abs(i - j) / x == j / y) {
			a = i;
			b = j;
			c = abs(i - j) / x;
			flag = 1;
		}
	}
	if (flag == 1) {
		cout << a;
		if (a > u_grade) {
			cout << " Cong ";
		}
		else if (a == u_grade) {
			cout << " Ping ";
		}
		else {
			cout << " Gai ";
		}
		if (b > u_grade) {
			cout << "Cong ";
		}
		else if (b == u_grade) {
			cout << "Ping ";
		}
		else {
			cout << "Gai ";
		}
		if (c > u_grade) {
			cout << "Cong";
		}
		else if (c == u_grade) {
			cout << "Ping";
		}
		else {
			cout << "Gai";
		}
	}
	else {
		cout << "No Solution";
	}
	cout << endl;
}

//1089
void wholve_killed(){
	int n,flag = 0,count = 0,p_flag = 0,t_flag = 0;
	cin >> n;
	vector<int> list1(n + 1, 0);
	vector<int> people(n + 1, 0);
	vector<int> people1;
	for (int i = 1; i <= n; i++) {
		cin >> list1[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			list1[i] = -list1[i];
			list1[j] = -list1[j];
			for (int k = 1; k <= n; k++) {
				people[k] = 0;
			}
			for (int k = 1; k <= n; k++) {
				if (people[abs(list1[k])] == 0) {
					people[abs(list1[k])] = list1[k] / abs(list1[k]);
				}
				else {
					if (people[abs(list1[k])] * list1[k] < 0) {
						flag = 1;
					}
				}
			}
			if (flag == 0) {
				for (int k = 1; k <= n; k++) {
					if (people[k] < 0) {
						count++;
					}
				}
				if (count <= 2 && count >= 1) {
					if (!((count == 2 && people[i] < 0 && people[j] < 0) || (people[i] > 0 && people[j] > 0))) {
						t_flag = 1;
						for (int k = 1; k <= n; k++) {
							if (people[k] == 0 && p_flag == 0) {
								p_flag = 1;
								people1.push_back(k);
							}
							if (people[k] < 0) {
								people1.push_back(k);
							}
						}
					}
				}
			}
			list1[i] = -list1[i];
			list1[j] = -list1[j];
			count = 0;
			flag = 0;
			p_flag = 0;
		}
	}
	if (t_flag == 1) {
		int min1 = 100, min2 = 100;
		for (int i = 0; i < people1.size(); i += 2) {
			if (people1[i] < min1) {
				min1 = people1[i];
			}
		}
		for (int i = 1; i < people1.size(); i += 2) {
			if (people1[i] < min2 && people1[i - 1] == min1) {
				min2 = people1[i];
			}
		}
		cout << min1 << " " << min2 << endl;
	}
	else {
		cout << "No Solution" << endl;
	}
}

//1090
void dangerous_box(){
	int n, m, x, y;
	vector<vector<int>> list1(100000);
	cin >> n >> m;
	vector<vector<int>> list2(m);
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		list1[x].push_back(y);
		list1[y].push_back(x);
	}
	for (int i = 0; i < m; i++) {
		cin >> x;
		for (int j = 0; j < x; j++) {
			cin >> y;
			list2[i].push_back(y);
		}
	}
	int flag = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < list2[i].size(); j++) {
			for (int k = j + 1; k < list2[i].size(); k++) {
				for (int o = 0; o < list1[list2[i][j]].size();o++) {
					if (list1[list2[i][j]][o] == list2[i][k]) {
						flag = 1;
					}
				}
			}
		}
		if (flag == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
		flag = 0;
	}
}

int main()
{
	return 0;
}