#include "stdafx.h"
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

void A_and_B_Format(){
	long a, b;
	cin >> a >> b;
	long c = a + b;
	int flag = 1;
	if (c < 0) {
		flag = -1;
		c = -c;
	}
	string c_Str = to_string(c);
	if (flag == -1) {
		cout << "-";
	}
	for (int i = 0; i < c_Str.size(); i++) {
		if (i != 0 && i != c_Str.size() - 1 && (c_Str.size() - i) % 3 == 0) {
			cout << "," << c_Str[i];
		}
		else {
			cout << c_Str[i];
		}
	}
	cout << endl;
	
}

void A_and_B_Polynomial(){
	vector<double> polynomial_list(1001, 0);
	int n;
	double number,exp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> exp >> number;
		polynomial_list[exp] += number;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> exp >> number;
		polynomial_list[exp] += number;
	}
	int count = 0;
	for (int i = 1000; i >= 0; i--) {
		if (polynomial_list[i] != 0) {
			count++;
		}
	}
	cout << count;
	for (int i = 1000; i >= 0; i--) {
		if (polynomial_list[i] != 0) {
			cout << " " << i << " ";
			printf("%.1f", polynomial_list[i]);
		}
	}
	cout << endl;
}

/*
6 9 0 3
1 1 1 1 1 1
0 1 6
0 2 3
1 3 5
1 2 2
2 3 3
2 4 4
3 4 2
3 5 3
4 5 5
*/


void Emergency(){
	int City_n, Road_n, Now_p, Save_p, x, y,length,min_v;
	cin >> City_n >> Road_n >> Now_p >> Save_p;
	vector<int> Team_list(City_n,0);
	vector<int> Road_l(City_n, 0);
	vector<vector<int>> Road_list(City_n,vector<int>(City_n,100000));
	vector<vector<int>> D_list(City_n, vector<int>(City_n, 0));
	vector<int> Shortest_road_length(City_n, 100000);
	vector<int> Final(City_n, 0);
	vector<int> Newest_Team_list(City_n, 0);
	for (int i = 0; i < City_n; i++) {
		cin >> Team_list[i];
		Newest_Team_list[i] = Team_list[i];
		Road_list[i][i] = 0;
	}
	for (int i = 0; i < Road_n; i++) {
		cin >> x >> y >> length;
		Road_list[x][y] = length;
		Road_list[y][x] = length;
	}
	for (int i = 0; i < City_n; i++) {
		Shortest_road_length[i] = Road_list[Now_p][i];
		if (Shortest_road_length[i] != 100000 && i != Now_p) {
			D_list[i][Now_p] = 1;
			D_list[i][i] = 1;
			Newest_Team_list[i] = Newest_Team_list[Now_p] + Team_list[i];
			Road_l[i] = 1;
		}
	}
	for (int k = 0; k < City_n; k++) {
		int min = 100000;
		for (int i = 0; i < City_n; i++) {
			if (!Final[i]) {
				if (Shortest_road_length[i] < min) {
					min_v = i;
					min = Shortest_road_length[i];
				}
			}
		}
		Final[min_v] = 1;
		for (int i = 0; i < City_n; i++) {
			if ((!Final[i]) && (min + Road_list[min_v][i] < Shortest_road_length[i])) {
				Shortest_road_length[i] = min + Road_list[min_v][i];
				Newest_Team_list[i] = Newest_Team_list[min_v] + Team_list[i];
				Road_l[i] = Road_l[min_v];
				D_list[i][i] = 1;
			}
			else if ((!Final[i]) && (min + Road_list[min_v][i] == Shortest_road_length[i])) {
				Road_l[i] += Road_l[min_v];
				if (Newest_Team_list[i] < Newest_Team_list[min_v] + Team_list[i]) {
					Newest_Team_list[i] = Newest_Team_list[min_v] + Team_list[i];
				}
			}
		}
	}
	if(Save_p == Now_p){
		cout << 1 << " " << Team_list[Now_p] << endl;
	}
	else {
		cout << Road_l[Save_p] << " " << Newest_Team_list[Save_p] << endl;
	}
}

//1004
class Node {
public:
	string name;
	int level,son_n;
	Node(string n,int s_n,int l) {
		name = n;
		son_n = s_n;
		level = l;
	}
};

void search_tree(vector<Node> tree,int max_level) {
	vector<int> leaves_n(max_level + 1, 0);
	for (int i = 0; i < tree.size(); i++) {
		if(tree[i].son_n == 0)
		leaves_n[tree[i].level]++;
	}
	cout << leaves_n[0];
	for (int i = 1; i < max_level + 1; i++) {
		cout << " " << leaves_n[i];
	}
	cout << endl;
}

void count_leaves(){
	int n,m,num,count = 1,max_level = 0;
	string name,son;
	cin >> n >> m;
	vector<Node> node_list;
	map<string, int> map_list;
	if (n == 1 && m == 0) {
		cout << 1 << endl;
	}else{
		cin >> name >> num;
		map_list[name] = 0;
		node_list.push_back({name,num,0});
		for (int i = 0; i < num; i++) {
			cin >> son;
			map_list[son] = count;
			node_list.push_back({ son,0,node_list[map_list[name]].level + 1 });
			count++;
			if (node_list[map_list[name]].level + 1 > max_level)
				max_level = node_list[map_list[name]].level + 1;
		}
		for (int i = 0; i < m - 1; i++) {
			cin >> name >> num;
			node_list[map_list[name]].son_n = num;
			for (int j = 0; j < num; j++) {
				cin >> son;
				map_list[son] = count;
				node_list.push_back({ son,0,node_list[map_list[name]].level + 1 });
				count++;
				if (node_list[map_list[name]].level + 1 > max_level)
					max_level = node_list[map_list[name]].level + 1;
			}
		}
		search_tree(node_list, max_level);
	}	
}

//1005
void Spell_It_Right(){
	string n;
	cin >> n;
	int num = 0;
	map<char, string> n_list = { {'0',"zero"}, {'1',"one"},{'2',"two"},{'3',"three"},{'4',"four"},{'5',"five"},{'6',"six"},{'7',"seven"},{'8',"eight"},{'9',"nine"} };
	for (int i = 0; i < n.size(); i++) {
		num += n[i] - '0';
	}
	n = to_string(num);
	cout << n_list[n[0]];
	for (int i = 1; i < n.size(); i++) {
		cout << " " << n_list[n[i]];
	}
	cout << endl;	
}

//1006
void Sign_In_Out(){
	int n,e_t = 100000,l_t = 0,t_h,t_m,t_s;
	string name, earlest_id, latest_id;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name;
		scanf_s("%d:%d:%d", &t_h, &t_m, &t_s);
		if (t_h * 3600 + t_m * 60 + t_s < e_t) {
			e_t = t_h * 3600 + t_m * 60 + t_s;
			earlest_id = name;
		}
		scanf_s("%d:%d:%d", &t_h, &t_m, &t_s);
		if (t_h * 3600 + t_m * 60 + t_s > l_t) {
			l_t = t_h * 3600 + t_m * 60 + t_s;
			latest_id = name;
		}
	}
	cout << earlest_id << " " << latest_id << endl;
}

//1007
void max_sequences(){
	int n;
	cin >> n;
	vector<int> sequence_list(n, 0);
	vector<int> sque_sum_list(n, 0);
	int max = 0, m_index, min_index, min;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		cin >> sequence_list[i];
	}
	if (sequence_list[0] <= 0) {
		sque_sum_list[0] = 0;
	}
	else {
		sque_sum_list[0] = sequence_list[0];
	}
	for (int i = 1; i < n; i++) {
		if (sque_sum_list[i - 1] + sequence_list[i] >= 0) {
			sque_sum_list[i] = sque_sum_list[i - 1] + sequence_list[i];
		}
		else if (sque_sum_list[i - 1] + sequence_list[i] < 0) {
			sque_sum_list[i] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (sque_sum_list[i] > max) {
			max = sque_sum_list[i];
			m_index = i;
		}
	}
	int flag_l = 0;
	if (max == 0) {
		for (int i = 0; i < n; i++) {
			if (sequence_list[i] == 0) {
				m_index = i;
				flag_l = 1;
			}
		}
		if (flag_l == 0) {
			cout << 0 << " " << sequence_list[0] << " " << sequence_list[n - 1] << endl;
		}
		else if (flag_l == 1) {
			cout << 0 << " " << 0 << " " << 0 << endl;
		}
	}
	else {
		for (int i = m_index; i >= 0; i--) {
			if (sque_sum_list[i] <= 0) {
				min_index = i + 1;
				break;
			}
			if (i == 0) {
				min_index = 0;
			}
		}
		cout << max << " " << sequence_list[min_index] << " " << sequence_list[m_index] << endl;
	}
}

//1008
void elevator(){
	int n, i = 0, sum = 0;
	vector<int> a(100, 0);
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	for (i = 1; i <= n; i++)
	{
		if (a[i] > a[i - 1])
			sum = sum + (a[i] - a[i - 1]) * 6 + 5;
		else
			sum = sum + (a[i - 1] - a[i]) * 4 + 5;
	}
	cout << sum << endl;
}

//1009
void Product_Polynomial(){
	vector<double> a_list1(1001, 0);
	vector<double> a_list2(1001, 0);
	vector<double> a_l(100001, 0);
	int n1,n2,num;
	double x;
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		cin >> num >> x;
		a_list1[num] = x;
	}
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> num >> x;
		a_list2[num] = x;
	}

	for (int i = 0; i < 1000; i++) {
		if (a_list1[i] != 0) {
			for (int j = 0; j < 1000; j++) {
				if (a_list2[j] != 0) {
					a_l[i + j] += a_list1[i] * a_list2[j];
				}
			}
		}
	}
	int count = 0;
	for (int i = a_l.size() - 1; i >= 0; i--) {
		if (a_l[i] != 0) {
			count++;
		}
	}
	cout << count;
	for (int i = a_l.size() - 1; i >= 0; i--) {
		if(a_l[i] != 0){
			printf(" %d %.1f",i, a_l[i]);
		}
	}
	cout << endl;
}

//1010
void Radix(){
		map<char, int> map_list;
	char x = '0';
	for (int i = 0; i < 10; i++) {
		map_list[x] = i;
		x = x + 1;
	}
	x = 'a';
	for (int i = 0; i < 26; i++) {
		map_list[x] = i + 10;
		x += 1;
	}
	unsigned long long radix, tag;
	string n1, n2;
	unsigned long long x1 = 0,x2 = 0,begin, end, mid, result = 0;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 1) {
	  x = 0;
		for (int i = 0; i < n1.size(); i++) {
			x1 = x1 * radix + (map_list[n1[i]]);
		}
		char k = '0';
		for (int i = 0; i < n2.size(); i++) {
			if (n2[i] > k) {
				k = n2[i];
			}
		}
		begin = map_list[k] + 1;
		end = x1 + 1;
		while (begin <= end) {
			mid = (begin + end) / 2;
			x2 = 0;
			for (int i = 0; i < n2.size(); i++) {
				x2 = x2 * mid + (map_list[n2[i]]);
			}
			if (x2 == x1) {
				result = mid;
				break;
			}
			else if (x2 > x1 || x2 < 0) {
				end = mid - 1;
			}
			else if (x1 > x2) {
				begin = mid + 1;
			}
		}
		if (result == 0) {
			cout << "Impossible" << endl;
		}
		else if(result != 1){
			cout << result << endl;
		}
		else {
			cout << 2 << endl;
		}
	}
	else if (tag == 2) {
		x2 = 0;
		for (int i = 0; i < n2.size(); i++) {
			x2 = x2 * radix + (map_list[n2[i]]);
		}
		char k = '0';
		for (int i = 0; i < n1.size(); i++) {
			if (n1[i] > k) {
				k = n1[i];
			}
		}
		begin = map_list[k] + 1;
		end = x2 + 1;
		while (begin <= end) {
			mid = (begin + end) / 2;
			x1 = 0;
			for (int i = 0; i < n1.size(); i++) {
				x1 = x1 * mid + (map_list[n1[i]]);
			}
			if (x2 == x1) {
				result = mid;
				break;
			}
			else if (x1 > x2 || x1 < 0) {
				end = mid - 1;
			}
			else if (x2 > x1) {
				begin = mid + 1;
			}
		}
		if (result == 0) {
			cout << "Impossible" << endl;
		}
		else if (result == 1) {
			cout << 2 << endl;
		}
		else {
			cout << result << endl;
		}
	}
}

//1011
void WorldCupBetting(){
	vector<double> WorldCupBet_list(9, 0);
	for (int i = 0; i < 9; i++) {
		cin >> WorldCupBet_list[i];
	}
	double max = 0,z = 1.0;
	char a;
	map<int, char> m = { {0,'W'},{1,'T'},{2,'L'} };
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			if (WorldCupBet_list[j * 3 + i] > max) {
				max = WorldCupBet_list[j * 3 + i];
				a = m[i];
			}
		}
		cout << a << " ";
		z *= max;
		max = 0;
	}
	printf("%.2f\n", (z * 0.65 - 1) * 2);
}

//1012
class Student {
public:
	string ID;
	int C_grade, M_grade, E_grade, A_grade;
	Student(string id, int c, int m, int e, int a) {
		ID = id;
		C_grade = c;
		M_grade = m;
		E_grade = e;
		A_grade = a;
	}
};

void The_Best_Rank(){
	vector<int> C_list;
	vector<int> M_list;
	vector<int> E_list;
	vector<int> A_list;
	vector<Student> Student_list;
	map<string, int> ma;
	int N, M;
	cin >> N >> M;
	string id;
	int c, m, e, a;
	for (int i = 0; i < N; i++) {
		cin >> id >> c >> m >> e;
		a = (c + m + e) / 3;
		Student_list.push_back({ id,c,m,e,a });
		C_list.push_back(c);
		M_list.push_back(m);
		E_list.push_back(e);
		A_list.push_back(a);
		ma[id] = i;
	}
	sort(A_list.begin(), A_list.end(), greater<int>());
	sort(M_list.begin(), M_list.end(), greater<int>());
	sort(E_list.begin(), E_list.end(), greater<int>());
	sort(C_list.begin(), C_list.end(), greater<int>());
	int level = 101;
	int grade;
	char ch;
	for (int i = 0; i < M; i++) {
		cin >> id;
		if (ma.count(id) != 0) {
			grade = Student_list[ma[id]].A_grade;
			for (int j = 0; j < N; j++) {
				if (grade == A_list[j]) {
					level = j + 1;
					ch = 'A';
				}
			}
			grade = Student_list[ma[id]].C_grade;
			for (int j = 0; j < N; j++) {
				if (grade == C_list[j] && level > j + 1) {
					level = j + 1;
					ch = 'C';
				}
			}
			grade = Student_list[ma[id]].M_grade;
			for (int j = 0; j < N; j++) {
				if (grade == M_list[j] && level > j + 1) {
					level = j + 1;
					ch = 'M';
				}
			}
			grade = Student_list[ma[id]].E_grade;
			for (int j = 0; j < N; j++) {
				if (grade == E_list[j] && level > j + 1) {
					level = j + 1;
					ch = 'E';
				}
			}
			cout << level << " " << ch << endl;
			level = 101;
		}
		else {
			cout << "N/A" << endl;
		}
	}
}

//1014
string int_to_date(int time) {
	string h, m;
	if (time >= 600) {
		h = to_string(time / 60);
	}
	else if(time < 600){
		h = "0" + to_string(time / 60);
	}
	if (time % 60 >= 10) {
		m = to_string(time % 60);
	}
	else if (time % 60 > 0) {
		m = "0" + to_string(time % 60);
	}
	else if (time % 60 == 0) {
		m = "00";
	}
	return h + ":" + m;
}

class seat {
public:
	int x, y;
	seat(int a, int b) {
		x = a;
		y = b;
	}
	seat() {
	}
};

void Waiting_line(){
	int window_n, people_n, customer_n, queries_n;
	cin >> window_n >> people_n >> customer_n >> queries_n;
	vector<vector<string>> Time_list(window_n,vector<string>(customer_n));
	vector<int> time_list(window_n,480);
	vector<int> line_list(window_n, 0);
	vector<seat> seat_list(customer_n);
	int wait_time,min_time,min_window;
	for (; i < customer_n; ++i) {
		cin >> wait_time;
		min_time = time_list[0];
		min_window = 0;
		for (int j = 1; j < window_n; j++) {
			if (time_list[j] < min_time) {
				min_time = time_list[j];
				min_window = j;
			}
		}
		min_time += wait_time;
		time_list[min_window] = min_time;
		Time_list[min_window][line_list[min_window]] = int_to_date(min_time);
		seat_list[i] = { min_window ,line_list[min_window] };
		line_list[min_window]++;
	}
	int number;
	for (int i = 0; i < customer_n; i++) {
		cout << Time_list[seat_list[i].x][seat_list[i].y] << endl;
	}
}

//1015
void Reversiable(){
	int n, m, o =0;
	string x = "";
	cin >> n;
	vector<bool> Prime_list(100001, true);
	Prime_list[0] = Prime_list[1] = false;
	int k = 2;
	for (int i = 2; i < 320; i++) {
		while (k * i < 100001) {
			Prime_list[i * k] = false;
			k++;
		}
		k = 2;
	}
	while (true) {
		if (n < 0) {
			break;
		}
		cin >> m;
		o = n;
		while (n != 0){
			x += to_string(n % m);
			n /= m;
		}
		n = 0;
		for (int i = 0; i < x.size(); i++) {
			n += (x[i] - '0') * pow(m, x.size() - i - 1);
		}
		if (Prime_list[n] == false || Prime_list[o] == false) {
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
		x = "";
		cin >> n;
	}	
}

//1016
class phone_record {
public:
	bool Is_Line;
	int i_time,month,day,hour,mintues;
	phone_record(bool l,int m,int d,int h,int min,int i) {
		month = m;
		day = d;
		hour = h;
		mintues = min;
		Is_Line = l;
		i_time = i;
	}
};

class customer {
public:
	string name;
	vector<phone_record> record;
	vector<phone_record> legal_record;
	customer(string n) {
		name = n;
	}
};

bool cmptime(phone_record a, phone_record b) {
	if (a.i_time != b.i_time) {
		return a.i_time < b.i_time;
	}
}

bool cmpname(customer a, customer b) {
	return a.name < b.name;
}

double Spend_money(vector<int> money,phone_record a) {
	int day_money = 0,hour_money = 0;
	for (int i = 0; i < 24; i++) {
		day_money += money[i] * 60;
	}
	for (int i = 0; i < a.hour; i++) {
		hour_money += money[i] * 60;
	}
	return a.day * day_money + hour_money + a.mintues * money[a.hour];
}

void Phone_Bills(){
	vector<int> Time_Price_List(24);
	for (int i = 0; i < 24; i++) {
		cin >> Time_Price_List[i];
	}
	vector<customer> customer_list;
	customer_list.push_back({ "l" });
	int count = 1;
	map<string, int> m;
	int n;
	cin >> n;
	string name,state;
	int i_time;
	int month, day, hour, mintues;
	for (int i = 0; i < n; i++) {
		cin >> name;
		scanf_s("%d:%d:%d:%d", &month, &day, &hour, &mintues);
		i_time = day * 1440 + hour * 60 + mintues;
		cin >> state;
		if (m[name] == 0) {
			customer_list.push_back({ name });
			customer_list[count].record.push_back({ (state == "on-line"), month, day, hour, mintues, i_time });
			m[name] = count;
			count++;
		}
		else {
			customer_list[m[name]].record.push_back({ (state == "on-line"), month, day, hour, mintues, i_time });
		}
	}
	for (int i = 1; i < count; i++) {
		sort(customer_list[i].record.begin(), customer_list[i].record.end(), cmptime);
	}
	bool x = false;
	for (int i = 1; i < count; i++) {
		for (int j = 0; j < customer_list[i].record.size() - 1; j++) {
			if (customer_list[i].record[j].Is_Line == true && customer_list[i].record[j + 1].Is_Line == false) {
				customer_list[i].legal_record.push_back(customer_list[i].record[j]);
				customer_list[i].legal_record.push_back(customer_list[i].record[j + 1]);
			}
		}
	}
	sort(customer_list.begin() + 1, customer_list.end(), cmpname);
	double account = 0;
	for (int i = 1; i < count; i++) {
		if (customer_list[i].legal_record.size() != 0) {
			cout << customer_list[i].name << " ";
			printf("%02d\n", customer_list[i].record[0].month);
			for (int j = 0; j < customer_list[i].legal_record.size(); j += 2) {
				account += (Spend_money(Time_Price_List, customer_list[i].legal_record[j + 1]) - Spend_money(Time_Price_List, customer_list[i].legal_record[j])) / 100;
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", customer_list[i].legal_record[j].day, customer_list[i].legal_record[j].hour, customer_list[i].legal_record[j].mintues, customer_list[i].legal_record[j + 1].day, customer_list[i].legal_record[j + 1].hour, customer_list[i].legal_record[j + 1].mintues, customer_list[i].legal_record[j + 1].i_time - customer_list[i].legal_record[j].i_time, (Spend_money(Time_Price_List, customer_list[i].legal_record[j + 1]) - Spend_money(Time_Price_List, customer_list[i].legal_record[j])) / 100);
			}
			printf("Total amount: $%.2f\n", account);
			account = 0;
		}
	}
}


//1017
class customer {
public:
	int arrive_time, spend_time;
	customer() {
	}
	customer(int a, int s) {
		arrive_time = a;
		spend_time = s;
	}
};

bool cmp_arrive_time(customer a, customer b) {
	return a.arrive_time < b.arrive_time;
}

void Queue_at_Bank(){
	int people_n, windows_n,time,hour,minutes,second,length;
	vector<customer> customer_list;
	cin >> people_n >> windows_n;
	vector<int> window_time(windows_n, 28800);
	for (int i = 0; i < people_n; i++) {
		scanf("%d:%d:%d %d", &hour, &minutes, &second, &length);
		length = min(length, 60);
		time = hour * 3600 + minutes * 60 + second;
		if(time < 61200)
		customer_list.push_back({ time,length * 60 });
	}
	double wait_time = 0;
		sort(customer_list.begin(), customer_list.end(), cmp_arrive_time);
		for (int i = 0; i < customer_list.size(); i++) {
			int min_time = 9999999, min_index = 0,flag = 0;
			for (int j = 0; j < windows_n; j++) {
				if (window_time[j] < min_time) {
					min_time = window_time[j];
					min_index = j;
				}
			}
			if (window_time[min_index] > customer_list[i].arrive_time) {
				wait_time += min_time - customer_list[i].arrive_time;
				window_time[min_index] += customer_list[i].spend_time;
			}
			else if (window_time[min_index] <= customer_list[i].arrive_time) {
				window_time[min_index] = customer_list[i].arrive_time + customer_list[i].spend_time;
			}
		}
		if (customer_list.size())
			printf("%.1f\n", wait_time / (customer_list.size() * 60));
		else
			cout << "0.0" << endl;
	return 0;
}

//1019
void General_Palindromic_Number(){
	vector<long long> l_list;
	long long n;
	string M = "",N;
	long long base, number = 0;
	cin >> n >> base;
	int count = 0;
	if (n == 0) {
		cout << "Yes" << endl;
		cout << 0 << endl;
	}
	else {
		while (n != 0) {
			l_list.push_back(n % base);
			n /= base;
			count++;
		}
		N = "";
		bool flag = true;
		for (int i = 0; i < count; i++) {
			if (l_list[i] != l_list[count - i - 1]) {
				flag = false;
			}
		}
		if (!flag) {
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
		for (int i = 0; i < count; i++) {
			if (i == 0) {
				cout << l_list[count - i - 1];
			}
			else {
				cout << " " << l_list[count - i - 1];
			}
		}
		cout << endl;
	}
}

//1020
class Node {
public:
	int n;
	Node *left, *right;
	Node(int n, Node *l, Node *r) {
		this->n = n;
		left = l;
		right = r;
	}
	Node() {
		this->n = -1;
		left = NULL;
		right = NULL;
	}
};

Node* Build_Tree(vector<int> &InOrder, vector<int> &PostOrder,int begin,int endin ,int begpo,int endpo) {
	Node *root = new Node;
	root->n = PostOrder[endpo];
	root->left = NULL;
	root->right = NULL;
	if (begpo == endpo)
		return root;
	int index = begin;
	for (int i = begin; i <= endin; i++) {
		if (InOrder[i] == PostOrder[endpo]) {
			index = i;
			break;
		}
	}
	if (index > begin) {
		root->left = Build_Tree(InOrder, PostOrder, begin, index - 1, begpo, begpo + index - begin - 1);
	}
	if (index < endin) {
		root->right = Build_Tree(InOrder, PostOrder,index + 1, endin,begpo + index - begin, endpo - 1);
	}
	return root;
}

void Tree_Traversals(){
	int n,num;
	cin >> n;
	vector<int> InOrder_sequence;
	vector<int> PostOrder_sequence;
	for (int i = 0; i < n; i++) {
		cin >> num;
		PostOrder_sequence.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		cin >> num;
		InOrder_sequence.push_back(num);
	}
	Node *root;
	root = Build_Tree(InOrder_sequence, PostOrder_sequence, 0, n - 1, 0, n - 1);
	queue<Node*> q;
	q.push(root);
	cout << q.front()->n;
	while (!q.empty()) {
		if (q.front()->left != NULL) {
			q.push(q.front()->left);
		}
		if (q.front()->right != NULL) {
			q.push(q.front()->right);
		}
		q.pop();
		if(!q.empty())
			cout << " " << q.front()->n;
	}
	cout << endl;
}
//1022
void query(vector<string> a,map<string,set<string>> m,string key) {
	int count = 0;
	set<string> l;
	if (!m[key].empty()) {
		for (set<string>::iterator p = m[key].begin(); p != m[key].end(); p++) {
			l.insert(*p);
		}
		count++;
	}
	else {
		string x = "";
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < a[i].size(); j++) {
				if (a[i][j] != ' ') {
					x += a[i][j];
				}
				else if (a[i][j] == ' ') {
					if (x == key) {
						for (set<string>::iterator p = m[a[i]].begin(); p != m[a[i]].end(); p++) {
							l.insert(*p);
						}
						count++;
						break;
					}
					x = "";
				}
			}
			if (x == key) {
				for (set<string>::iterator p = m[a[i]].begin(); p != m[a[i]].end(); p++) {
					l.insert(*p);
				}
				count++;
			}
			x = "";
		}
		
	}
	if (count == 0) {
		cout << "Not Found" << endl;
	}
	else {
		for (set<string>::iterator p = l.begin(); p != l.end(); p++) {
			cout << *p << endl;
		}
	}
}

void Digital_Library(){
	map<string, set<string>> m;
	vector<string> title_list;
	vector<string> author_list;
	vector<string> keyword_list;
	vector<string> publisher_list;
	int n;
	cin >> n;
	string l;
	getchar();
	string ID, title, author, key_words, publisher, published_year;
	for (int i = 0; i < n; i++) {
		getline(cin, ID);
		getline(cin, title); 
		getline(cin, author);
		getline(cin, key_words);
		getline(cin, publisher);
		getline(cin,published_year);
		title_list.push_back(title);
		author_list.push_back(author);
		keyword_list.push_back(key_words);
		publisher_list.push_back(publisher);
		m[title].insert(ID);
		m[author].insert(ID);
		m[key_words].insert(ID);
		m[publisher].insert(ID);
		m[published_year].insert(ID);
		m[title].insert(ID);
	}
	int x,a;
	char ch;
	cin >> x;
	getchar();
	string name,r;
	for (int i = 0; i < x; i++) {
		cin >> a >> ch;
		getchar();
		getline(cin, name);
		cout << a << ch << " " << name << endl;;
		switch (a)
		{
		case 1:
			query(title_list, m, name);
			break;
		case 2:
			query(author_list, m, name);
			break;
		case 3:
			query(keyword_list, m, name);
			break;
		case 4:
			query(publisher_list, m, name);
			break;
		case 5:
			if (!m[name].empty()) {
				for (set<string>::iterator p = m[name].begin(); p != m[name].end(); p++) {
					cout << *p << endl;
				}
			}
			else {
				cout << "Not Found" << endl;
			}
			break;
		}
	}
}

//1023
void Have_Fun_with_Number(){
	string n1,n2 = "";
	cin >> n1;
	int flag = 0,m;
	for (int i = n1.size() - 1; i >= 0; i--) {
		m = 2 * (n1[i] - '0') + flag;
		if (m >= 10) {
			flag = 1;
		}
		else {
			flag = 0;
		}
		n2 = to_string(m % 10) + n2;
	}
	if (flag == 1) {
		n2 = "1" + n2;
	}
	if (multiset<char>(n1.begin(), n1.end()) == multiset<char>(n2.begin(), n2.end())) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	cout<< n2 <<endl;
}

//1024
bool Is_Parlindromic(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != str[str.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

string change_string(string str) {
	string new_string = "";
	for (int i = 0; i < str.size(); i++) {
		new_string = str[i] + new_string;
	}
	return new_string;
}

string add_string(string str1, string str2) {
	string str;
	int flag = 0,m;
	for (int i = str1.size() - 1;i >= 0; i--) {
		m = (str1[i] - '0') + (str2[i] - '0') + flag;
		if (m >= 10) {
			flag = 1;
		}
		else {
			flag = 0;
		}
		str = to_string(m % 10) + str;
	}
	if (flag == 1) {
		str = "1" + str;
	}
	return str;
}

void Parlindromic_Number(){
	string n1;
	int count;
	cin >> n1 >> count;
	int i = 1;
	if (Is_Parlindromic(n1)) {
		cout << n1 << endl;
		cout << 0 << endl;
	}
	else {
		while (true)
		{
			if (Is_Parlindromic(add_string(n1, change_string(n1)))) {
				cout << add_string(n1, change_string(n1)) << endl;
				cout << i << endl;
				break;
			}
			else {
				n1 = add_string(n1, change_string(n1));
			}
			if (count == 1) {
				cout << n1 << endl;
				cout << i << endl;
				break;
			}
			i++;
			count--;
		}
	}
}

//1025
class student {
public:
	string ID;
	int Location_number,grade;
	student(string id, int Ln, int g) {
		ID = id;
		Location_number = Ln;
		grade = g;
	}
};

bool studentcmp(student a,student b) {
	if (a.grade != b.grade) {
		return a.grade > b.grade;
	}
	else {
		return a.ID < b.ID;
	}
}

void Pat_ranking(){
int n,m;
	cin >> n;
	vector<student> student_list;
	vector<int> now_location_list(n, 0);
	vector<int> grade_list(n, 101);
	vector<int> fact_location_list(n, 0);
	string id;
	int grade;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> id >> grade;
			student_list.push_back({ id,i + 1,grade });
		}
	}
	int x = 1;
	sort(student_list.begin(), student_list.end(), studentcmp);
	cout << student_list.size() << endl;
	cout << student_list[0].ID << " " << 1 << " " << student_list[0].Location_number <<" " << 1 << endl;
	fact_location_list[student_list[0].Location_number - 1]++;
	if (student_list[0].grade < grade_list[student_list[0].Location_number - 1]) {
		grade_list[student_list[0].Location_number - 1] = student_list[0].grade;
		now_location_list[student_list[0].Location_number - 1] = fact_location_list[student_list[0].Location_number - 1];
	}
	for (int i = 1; i < student_list.size(); i++) {
		if (student_list[i].grade != student_list[i - 1].grade) {
			x = i + 1;
		}
		fact_location_list[student_list[i].Location_number - 1]++;
		if (student_list[i].grade < grade_list[student_list[i].Location_number - 1]) {
			grade_list[student_list[i].Location_number - 1] = student_list[i].grade;
			now_location_list[student_list[i].Location_number - 1] = fact_location_list[student_list[i].Location_number - 1];
		}
		cout << student_list[i].ID << " " << x << " " << student_list[i].Location_number << " " << now_location_list[student_list[i].Location_number - 1] << endl;
		
		
	}
}

//1026
class player {
public:
	int Time, Length,Is_VIP;
	player(int t, int l, int i) {
		Time = t;
		Length = l;
		Is_VIP = i;
	}
};

class play_time {
public:
	int arr_time,use_time,wait_long;
	play_time(int a, int u, int w) {
		arr_time = a;
		use_time = u;
		wait_long = w;
	}
};

bool cmpplayer(player a, player b) {
	return a.Time < b.Time;
}

bool cmp_play_time(play_time a, play_time b) {
	return a.use_time < b.use_time;
}

void table_tennis(){
	queue<player> normal_player;
	queue<player> vip_player;
	vector<player> player_list;
	vector<play_time> play_time_list;
	int n,hour,mintues,second,length,is_vip,time;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++) {
		scanf_s("%d:%d:%d", &hour, &mintues, &second);
		cin >> length >> is_vip;
		time = hour * 3600 + mintues * 60 + second;
		length = min(120, length);
		if (time < 75600) {
			player_list.push_back({ time,length,is_vip });
			count++;
		}
	}
	if(player_list.size() > 0)
	sort(player_list.begin(), player_list.end(), cmpplayer);

	for (int i = 0; i < count; i++) {
		if (player_list[i].Is_VIP == 1) {
			vip_player.push(player_list[i]);
		}
		else if(player_list[i].Is_VIP == 0){
			normal_player.push(player_list[i]);
		}
	}

	int table_n,vip_table_n,nu,first_table_n;
	cin >> table_n >> vip_table_n;
	vector<bool> table_list(table_n, false);
	vector<int> table_time(table_n, 28800);
	vector<int> table_number(table_n, 0);
	vector<int> vip_table_number(vip_table_n, 0);
	for (int i = 0; i < vip_table_n; i++) {
		cin >> nu;
		if (i == 0) {
			first_table_n = nu - 1;
		}
		vip_table_number[i] = nu - 1;
		table_list[nu - 1] = true;
	}

	int min, vip_min, table_nn;
	for (int i = 0; i < count; i++) {
		min = table_time[0];
		int flag = 0;
		table_nn = 0;
		int time_flag = 0;
		for (int j = 0; j < table_n; j++) {
			if (table_time[j] < 75600) {
				time_flag = 1;
			}
		}
		if (time_flag == 1) {
			if (normal_player.size() > 0 && vip_player.size() > 0) {
				if (normal_player.front().Time < vip_player.front().Time) {
					for (int j = 0; j < table_n; j++) {
						if (table_time[j] <= normal_player.front().Time) {
							table_nn = j;
							min = table_time[j];
							flag = 1;
							break;
						}
						if (table_list[j] == false || (table_list[j] == true && table_time[j] < vip_player.front().Time)) {
							if (table_time[j] < min) {
								table_nn = j;
								min = table_time[j];
							}
						}
					}
					if (flag == 1) {
						table_time[table_nn] = normal_player.front().Time + normal_player.front().Length * 60;
						play_time_list.push_back({ normal_player.front().Time ,normal_player.front().Time ,0});
						table_number[table_nn]++;
					}
					else if (flag == 0) {
						table_time[table_nn] = min + normal_player.front().Length * 60;
						play_time_list.push_back({ normal_player.front().Time ,min ,min - normal_player.front().Time });
						table_number[table_nn]++;
					}
					normal_player.pop();
				}
				else if (normal_player.front().Time > vip_player.front().Time) {
					for (int i = 0; i < vip_table_n; i++) {
						if (table_time[vip_table_number[i]] <= vip_player.front().Time) {
							table_nn = vip_table_number[i];
							min = vip_player.front().Time;
							flag = 1;
							break;
						}
					}
					if (flag == 1) {
						table_time[table_nn] = vip_player.front().Time + vip_player.front().Length * 60;
						play_time_list.push_back({ vip_player.front().Time ,vip_player.front().Time ,0 });
						table_number[table_nn]++;
					}
					else {
						for (int j = 0; j < table_n; j++) {
							if (table_time[j] < vip_player.front().Time) {
								table_nn = j;
								flag = 1;
								break;
							}
							if (table_time[j] < min) {
								table_nn = j;
								min = table_time[j];
							}
						}
						if (flag == 1) {
							table_time[table_nn] = vip_player.front().Time + vip_player.front().Length * 60;
							play_time_list.push_back({ vip_player.front().Time ,vip_player.front().Time ,0 });
							table_number[table_nn]++;
						}
						else {
							table_time[table_nn] = min + vip_player.front().Length * 60;
							play_time_list.push_back({ vip_player.front().Time ,min ,min - vip_player.front().Time });
							table_number[table_nn]++;
						}
					}
					vip_player.pop();
				}
			}
			else if (normal_player.size() == 0 && vip_player.size() != 0) {
				for (int i = 0; i < vip_table_n; i++) {
					if (table_time[vip_table_number[i]] <= vip_player.front().Time) {
						table_nn = vip_table_number[i];
						min = vip_player.front().Time;
						flag = 1;
						break;
					}
				}
				if (flag == 1) {
					table_time[table_nn] = vip_player.front().Time + vip_player.front().Length * 60;
					play_time_list.push_back({ vip_player.front().Time ,vip_player.front().Time ,0 });
					table_number[table_nn]++;
				}
				else {
					for (int j = 0; j < table_n; j++) {
						if (table_time[j] <= vip_player.front().Time) {
							table_nn = j;
							min = vip_player.front().Time;
							flag = 1;
							break;
						}
						if (table_time[j] < min) {
							table_nn = j;
							min = table_time[j];
						}
					}
					if (flag == 1) {
						table_time[table_nn] = vip_player.front().Time + vip_player.front().Length * 60;
						play_time_list.push_back({ vip_player.front().Time ,vip_player.front().Time ,0 });
						table_number[table_nn]++;
					}
					else if (flag == 0) {
						table_time[table_nn] = min + vip_player.front().Length * 60;
						play_time_list.push_back({ vip_player.front().Time ,min , min - vip_player.front().Time });
						table_number[table_nn]++;
					}
				}
				vip_player.pop();
			}
			else if (normal_player.size() != 0 && vip_player.size() == 0) {
				for (int j = 0; j < table_n; j++) {
					if (table_time[j] <= normal_player.front().Time) {
						table_nn = j;
						flag = 1;
						break;
					}
					if (table_time[j] < min) {
						table_nn = j;
						min = table_time[j];
					}
				}
				if (flag == 1) {
					table_time[table_nn] = normal_player.front().Time + normal_player.front().Length * 60;
					play_time_list.push_back({ normal_player.front().Time ,normal_player.front().Time ,0 });
					table_number[table_nn]++;
				}
				else if (flag == 0) {
					table_time[table_nn] = min + normal_player.front().Length * 60;
					play_time_list.push_back({ normal_player.front().Time ,min ,min - normal_player.front().Time });
					table_number[table_nn]++;
				}
				normal_player.pop();
			}
		}else if(time_flag == 0){
			break;
		}
	}
	if(play_time_list.size() > 0)
		sort(play_time_list.begin(),play_time_list.end(),cmp_play_time);
	for (int i = 0; i < play_time_list.size(); i++) {
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", play_time_list[i].arr_time / 3600, (play_time_list[i].arr_time % 3600) / 60, play_time_list[i].arr_time % 60, play_time_list[i].use_time / 3600, (play_time_list[i].use_time % 3600) / 60, play_time_list[i].use_time % 60, (play_time_list[i].use_time - play_time_list[i].arr_time + 30) / 60);
	}
	cout << table_number[0];
	for (int i = 1; i < table_n; i++) {
		cout << " " << table_number[i];
	}
	cout << endl;
}

//1027
string radix(int R) {
	string str = "";
	char a;
	if (R < 13) {
		if (R > 9) {
			a = 'A' + R - 10;
			str = "0";
			str += a;
		}
		else {
			str =  "0" + to_string(R);
		}
	}
	else {
		if ((R % 13) > 9) {
			a = 'A' + (R % 13) - 10;
			str = a;
		}
		else {
			str = to_string(R % 13);
		}
		if (R / 13 > 9) {
			a = 'A' + (R / 13) - 10;
			str = a + str;
		}
		else {
			str = to_string(R / 13) + str;
		}
	}
	return str;
}

void Color_int_Mars(){
	int R, G, B;
	cin >> R >> G >> B;
	string str = "";
	cout << "#";
	cout << radix(R) << radix(G) << radix(B) << endl;
}

//1028
struct  people
{
	int ID, grade;
	char name[10];
};

bool cmp_ID(people a,people b) {
	return a.ID < b.ID;
}

bool cmp_name(people a, people b) {
	if (strcmp(a.name, b.name) < 0) {
		return true;
	}
	else if (strcmp(a.name, b.name) == 0 && a.ID < b.ID) {
		return true;
	}
	return false;
}


bool cmp_grade(people a, people b) {
	if (a.grade != b.grade) {
		return a.grade < b.grade;
	}
	else {
		return a.ID < b.ID;
	}
}
void list_sort(){
	int n,m;
	cin >> n >> m;
	vector<people> people_list (n);
	for (int i = 0; i < n; i++) {
		scanf("%d%s%d", &people_list[i].ID, people_list[i].name, &people_list[i].grade);
	}
	switch (m)
	{
	case 1:
		sort(people_list.begin(), people_list.end(), cmp_ID);
		break;
	case 2:
		sort(people_list.begin(), people_list.end(), cmp_name);
		break;
	case 3:
		sort(people_list.begin(), people_list.end(), cmp_grade);
		break;
	}
	for (int i = 0; i < n; i++) {
		printf("%06d %s %d\n", people_list[i].ID, people_list[i].name, people_list[i].grade);
	}
}

//1029
void median(){
		deque<int> list1;
	int n1, num, n2, mid_n, flag;
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		scanf("%d", &num);
		list1.push_back(num);
	}
	cin >> n2;
	if ((n1 + n2) % 2 == 1) {
		mid_n = (n1 + n2) / 2;
		flag = 1;
	}
	else {
		mid_n = (n1 + n2) / 2 - 1;
		flag = 0;
	}
	int count = 0,count2 = 0,num2, count_f = 0;
	double median_n = 0;
	while (!list1.empty()) {
		scanf("%d", &num);
		count2++;
		while (num > list1.front()) {
			if (list1.empty()) {
				list1.push_front(num);
				break;
			}
			list1.pop_front();
			count++;
			if (count == mid_n) {
				count_f = 1;
				break;
			}
		}
		if (count_f == 1) {
			break;
		}
		cout << list1.front() << endl;
	}

	if (flag == 1) {
		if (num > list1.front()) {
			median_n = list1.front();
		}
		else {
			median_n = num;
		}
	}
	else {
		median_n += list1.front();
		list1.pop_front();
		if (list1.empty()) {
			cin >> num2;
			if (num < num2)
				median_n += num;
			else
				median_n += num2;
			count2++;
		}
		else {
			if (num > list1.front()) {
				median_n += list1.front();
			}
			else {
				median_n += num;
			}
		}
		median_n /= 2;
	}
	for (int i = 0; i < n2 - count2; i++) {
		scanf("%d", &num);
	}
	cout << median_n << endl;
} 

//1031
void hello_world_to_u(){
	string s;
	cin >> s;
	int n1 = (s.length() - 1) / 3 + 1;	
	int n2 = s.length() - 2 * n1 + 2;
	for (int i = 0; i < n1 - 1; i++)
	{
		cout << s[i];
		for (int j = 0; j < n2 - 2; j++)
		{
			cout << " ";
		}
		cout << s[s.length() - 1 - i];
		cout << endl;
	}

	for (int i = n1 - 1; i < n1 - 1 + n2; i++)
	{
		cout << s[i];
	}
}

//1032
class Node {
public:
	char x;
	int next_address,flag;
	Node(char i, int n) {
		x = i;
		next_address = n;
		flag = 0;
	}
	Node() {
		flag = 0;
	}
};

void Sharing(){
	vector<Node> Node_list(100000);
	int n, address, first_address1, first_address2, flag = 0;
	char a_x;
	int a_n;
	cin >> first_address1 >> first_address2 >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %c %d",&address, &a_x, &a_n);	
		Node_list[address].x = a_x;
		Node_list[address].next_address = a_n;
	}

	if (first_address1 == -1 || first_address2 == -1) {
		cout << -1 << endl;
	}
	else {
		while (Node_list[first_address1].next_address != -1) {
			Node_list[first_address1].flag = 1;
			first_address1 = Node_list[first_address1].next_address;
		}

		while (Node_list[first_address2].next_address != -1 && Node_list[first_address2].flag != 1) {
			first_address2 = Node_list[first_address2].next_address;
		}
		if (Node_list[first_address2].flag == 1) {
			printf("%05d\n", first_address2);
		}
		else {
			cout << -1 << endl;
		}
	}
}


//1035
class password {
public:
	string id, pass;
	password(string i, string p) {
		id = i;
		pass = p;
	}
};

void password(){
	int n;
	vector<password> password_list;
	map<char, char> m = { {'1','@'},{'0','%'},{'l','L'},{'O','o'} };
	cin >> n;
	string id, password;
	for (int i = 0; i < n; i++) {
		cin >> id >> password;
		int flag = 0;
		for (int j = 0; j < password.size(); j++) {
			if (m[password[j]] != 0) {
				password[j] = m[password[j]];
				flag = 1;
			}
		}
		if(flag == 1)
		password_list.push_back({id, password});
	}
	if (password_list.size() != 0) {
		cout << password_list.size() << endl;
		for (int i = 0; i < password_list.size(); i++) {
			cout << password_list[i].id << " " << password_list[i].pass << endl;
		}
	}
	else {
		if (n == 1) {
			cout << "There is 1 account and no account is modified" << endl;
		}
		else {
			cout << "There are "<<n<<" accounts and no account is modified" << endl;
		}
	}
}

//1033

class gas_station {
public:
	double price;
	int distance;
	gas_station(double p,int d) {
		price = p;
		distance = d;
	}
};

class car_state {
public:
	int index, now_gas;
	double spend;
	car_state() {
	}
	car_state(int i, int n, double s) {
		index = i;
		now_gas = n;
		spend = s;
	}
};

bool cmp_distance(gas_station a, gas_station b) {
	if (a.distance != b.distance)
		return a.distance < b.distance;
	else
		return a.price < b.price;
}

car_state choose_gas_station(vector<gas_station> a_list,int now_gas,int x,int max_distance,int all_distance,double spend) {
	int now_distance = a_list[x].distance, index = x + 1, min_index = x;
	double min_price = 100;
	car_state c;
	while (index < a_list.size() && a_list[index].distance <= now_distance + max_distance && a_list[index].distance < all_distance) {
		if (a_list[index].price <= min_price) {
			min_price = a_list[index].price;
			min_index = index;
		}
		if (a_list[index].price < a_list[x].price) {
			if (now_gas >= a_list[index].distance - a_list[x].distance) {
				x = index;
				now_gas = now_gas - (a_list[index].distance - a_list[x].distance);
			}
			else {
				spend += (a_list[index].distance - a_list[x].distance - now_gas) * a_list[x].price;
				x = index;
			}
			break;
		}
		index++;
	}
	if (a_list[x].distance == now_distance) {
		spend += a_list[x].price * (max_distance - now_gas);
		now_gas = max_distance - (a_list[min_index].distance - now_distance);
		x = min_index;
	}
	else {
		now_gas = 0;
	}
	c.index = x;
	c.now_gas = now_gas;
	c.spend = spend;
	return c;
}

void To_Fill_Or_Not_To_Fill(){
		int max_capacity, all_distance, single_distance, gas_station_n,distance;
	cin >> max_capacity >> all_distance >> single_distance >> gas_station_n;
	vector<gas_station> gas_station_list;
	double single_price;
	if (gas_station_n == 0) {
		cout << "The maximum travel distance = 0.00" << endl;
	}
	else {
		for (int i = 0; i < gas_station_n; i++) {
			cin >> single_price >> distance;
			gas_station_list.push_back({ single_price,distance });
		}
		sort(gas_station_list.begin(), gas_station_list.end(), cmp_distance);
		car_state c = { 0,0,0 };
		while (gas_station_list[c.index].distance + c.now_gas < all_distance && c.index != gas_station_list.size() - 1) {
			c = choose_gas_station(gas_station_list, c.now_gas, c.index, max_capacity * single_distance, all_distance, c.spend);
			if (c.index != gas_station_n - 1 && gas_station_list[c.index].distance + max_capacity * single_distance < gas_station_list[c.index + 1].distance) {
				break;
			}
		}
		int flag = 0;
		if (gas_station_list[c.index].distance + max_capacity * single_distance < all_distance) {
			flag = 1;
		}
		else {
			c.spend += (all_distance - gas_station_list[c.index].distance) * gas_station_list[c.index].price;
		}
		if (gas_station_list[0].distance != 0) {
			cout << "The maximum travel distance = 0.00" << endl;
		}
		else {
			if (flag == 1) {
				cout << "The maximum travel distance = ";
				double length = gas_station_list[c.index].distance + max_capacity * single_distance;
				printf("%.2f\n", length);
			}
			else {
				printf("%.2f\n", c.spend / single_distance);
			}
		}
	}
}	

//1036
void Boys_vs_Girls(){
			int n,min_male_grade = 101,max_female_grade = -1,grade;
	string min_male_name, min_male_id, max_female_name, max_female_id,name,id;
	char sex;
	int male_flag = 0, female_flag = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> sex >> id >> grade;
		if (sex == 'M') {
			if (grade < min_male_grade) {
				min_male_grade = grade;
				min_male_name = name;
				min_male_id = id;
				male_flag = 1;
			}
		}
		else if (sex == 'F') {
			if (grade > max_female_grade) {
				max_female_grade = grade;
				max_female_id = id;
				max_female_name = name;
				female_flag = 1;
			}
		}
	}
	if (female_flag == 1) {
		cout << max_female_name << " " << max_female_id << endl;
	}
	else {
		cout << "Absent" << endl;
	}
	if (male_flag == 1) {
		cout << min_male_name << " " << min_male_id << endl;
	}
	else {
		cout << "Absent" << endl;
	}
	if (male_flag == 1 && female_flag == 1) {
		cout << max_female_grade - min_male_grade << endl;
	}
	else {
		cout << "NA" << endl;
	}
}

//1037
void magic_coupon(){
	int n, m;
	cin >> n;
	vector<int> n1_list(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> n1_list[i];
	}
	cin >> m;
	vector<int> n2_list(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> n2_list[i];
	}
	sort(n1_list.begin(), n1_list.end(), greater<int>());
	sort(n2_list.begin(), n2_list.end(), greater<int>());
	long long y,z = 0;
	int a_index = 0, b_index = 0;
	while (true) {
		if (n1_list[a_index] > 0 && n2_list[a_index] > 0 || n1_list[n - 1 - b_index] < 0 && n2_list[m - 1 - b_index] < 0) {
			if (n1_list[a_index] * n2_list[a_index] >= n1_list[n - 1 - b_index] * n2_list[m - 1 - b_index]) {
				y = (long long)n1_list[a_index] * n2_list[a_index];
				z += y;
				a_index++;
			}
			else {
				y = (long long)n1_list[n - 1 - b_index] * n2_list[m - 1 - b_index];
				z += y;
				b_index++;
			}
		}
		else {
			break;
		}
	}
	cout << z << endl;
}

//1038
bool cmpstring(string a,string b) {
	return a + b < b + a;
}

void Recover_smallest_number(){
	int n;
	cin >> n;
	vector<string> number_list(n);
	for (int i = 0; i < n; i++) {
		cin >> number_list[i];
	}
	sort(number_list.begin(), number_list.end(), cmpstring);
	string str ="",str2 = "";
	for (int i = 0; i < n; i++) {
		str += number_list[i];
	}
	int flag = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '0' && flag != 0) {
			flag = 1;
			str2 += str[i];
		}
	}
	if (str2 == "") {
		str = "0";
	}
	cout << str2 << endl;
}

//1039
class student
{
public:
	int private_course_n;
	vector<int> class_list;
	student(int n) {
		private_course_n = 1;
		class_list.push_back(n);
	}
	student() {
		private_course_n = 0;
		class_list = {};
	}
};

int string_hash(string x) {
	int i = (((x[0] - 'A') * 26 + (x[1] - 'A')) * 26 + (x[2] - 'A')) * 10 + (x[3] - '0');
	return i;
}

void Course_List_for_Students(){
	int student_n, course_n;
	vector<student> student_list(26 * 26 * 26 * 10 + 1);
	int class_n, class_student_n,num;
	string name;
	cin >> student_n >> course_n;
	for (int i = 0; i < course_n; i++) {
		scanf("%d %d", &class_n, &class_student_n);
		for (int j = 0; j < class_student_n; j++) {
			name.resize(4);
			scanf("%s", &name[0]);
			num = string_hash(name);
			if (student_list[num].private_course_n != 0) {
				student_list[num].private_course_n++;
				student_list[num].class_list.push_back(class_n);
			}
			else {
				student_list[num] = { class_n };
			}
		}
	}
	for (int i = 0; i < student_n; i++) {
		name.resize(4);
		scanf("%s", &name[0]);
		num = string_hash(name);
		if (student_list[num].private_course_n == 0) {
			printf
			("%s 0\n",name.c_str());
		}
		else {
			printf("%s %d", name.c_str(), student_list[num].private_course_n);
			sort(student_list[num].class_list.begin(), student_list[num].class_list.end());
			for (vector<int>::iterator p = student_list[num].class_list.begin(); p != student_list[num].class_list.end(); p++) {
				printf(" %d", *p);
			}
			printf("\n");
		}
	}
}

//1040
void Longest_Symmetric_String(){
	string s;
	getline(cin, s);
	int max_length = 0;
	for (int i = 0; i < s.size(); i++) {
		int j;
		for (j = 1; i - j >= 0 && i + j < s.size() && s[i + j] == s[i - j]; j++);
		max_length = max(max_length, 2 * j - 1);
		for (j = 0; i - j >= 0 && i + j + 1<s.size() && s[i - j] == s[i + 1 + j]; j++);
		max_length = max(max_length, 2 * j);
	}
	cout << max_length << endl;
}


//1041
void Be_Unique(){
	int n,num;
	cin >> n;
	vector<int> number_list(10000);
	vector<int> n_list(n);
	for (int i = 0; i < n; i++) {
		cin >> num;
		n_list[i] = num;
		number_list[num]++;
	}
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (number_list[n_list[i]] == 1 && flag == 0) {
			flag = 1;
			cout << n_list[i];
			break;
		}
	}
	if (flag != 1) {
		cout << "None";
	}
	cout << endl;
}

//1042
vector<string> deal_with(vector<string> str_list, vector<int> rule) {
	vector<string> new_list(55);
	for (int i = 1; i < 55; i++) {
		new_list[rule[i]] = str_list[i];
	}
	return new_list;
}


void shuffling_Machine(){
	map<int, char> m{ {1,'S' },{2,'H'},{3,'C'},{4,'D'} };
	vector<string> poke_list(55);
	char a, b;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 13; j++) {
			a = m[i + 1];
			poke_list[i * 13 + j] = a;
			poke_list[i * 13 + j] += to_string(j);
		}
	}
	poke_list[53] = "J1";
	poke_list[54] = "J2";
	int n;
	cin >> n;
	vector<int> rule(55);
	for (int i = 1; i < 55; i++) {
		cin >> rule[i];
	}
	for (int i = 0; i < n; i++) {
		poke_list = deal_with(poke_list, rule);
	}
	cout << poke_list[1];
	for (int i = 2; i < 55; i++) {
		cout << " " << poke_list[i];
	}
	cout << endl;
}

//1044
void Mars_shopping(){
	int n, customer_pay;
	cin >> n >> customer_pay;
	vector<string> cut_list;
	vector<int> diamond_value_list(n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&diamond_value_list[i]);
	}
	int index1 = 0, index2 = 0, whole_price = 0, min_price = 1000000001,flag = 0,x = index1;
	while (index2 != n) {
		while (whole_price < customer_pay && index2 != n) {
			whole_price += diamond_value_list[index2];
			index2++;
		}
		if (whole_price < min_price && whole_price >= customer_pay) {
			min_price = whole_price;
			cut_list.clear();
			cut_list.push_back(to_string(index1 + 1) + "-" + to_string(index2));
		}else if (whole_price == min_price && whole_price >= customer_pay) {
			cut_list.push_back(to_string(index1 + 1) + "-" + to_string(index2));
		}
		x = index1;
		while(whole_price - diamond_value_list[index1] >= customer_pay){
			whole_price -= diamond_value_list[index1];
			index1++;
		}
		if (whole_price < min_price && whole_price >= customer_pay) {
			min_price = whole_price;
			cut_list.clear();
			cut_list.push_back(to_string(index1 + 1) + "-" + to_string(index2));
		}else if (whole_price == min_price && whole_price >= customer_pay && x != index1) {
			cut_list.push_back(to_string(index1 + 1) + "-" + to_string(index2));
		}
		whole_price -= diamond_value_list[index1];
		index1++;
	}
	if(cut_list.size() > 0)
		for (int i = 0; i < cut_list.size(); i++) {
			cout << cut_list[i] << endl;
	}
}

//1045
void Favorite_Color_Stripe(){
	int n,m,length;
	cin >> n >> m;
	vector<int> favorate_color_list(m + 1);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &favorate_color_list[i]);
	}
	cin >> length;
	vector<int> all_color_list(length + 1);
	for (int i = 1; i < length + 1; i++) {
		scanf("%d", &all_color_list[i]);
	}
	int max_length = 0,_max;
	vector<vector<int>> public_subsequence(length + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= length; i++) {
		for (int j = 1; j <= m; j++) {
			_max = public_subsequence[i - 1][j - 1];
			_max = max(public_subsequence[i - 1][j - 1],public_subsequence[i - 1][j],public_subsequence[i][j - 1]);
			if (all_color_list[i] == favorate_color_list[j]) {
				public_subsequence[i][j] = _max + 1;
			}
			else if (all_color_list[i] != favorate_color_list[j]) {
				public_subsequence[i][j] = _max;
			}
		}
	}
	cout << public_subsequence[length][m] << endl;
}

//1046
void Shortest_distance(){
	int place_n;
	cin >> place_n;
	vector<int> place(place_n + 1);
	vector<int> road_length(place_n + 1);
	road_length[0] = 0;
	for (int i = 1; i <= place_n; i++) {
		scanf("%d", &place[i]);
		road_length[i] = road_length[i - 1] + place[i];
	}
	int n,place1,place2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &place1, &place2);
		place1--;
		place2--;
		printf("%d\n", (abs(road_length[place1] - road_length[place2]) < road_length[place_n] - abs(road_length[place1] - road_length[place2]) ? abs(road_length[place1] - road_length[place2]) : road_length[place_n] - abs(road_length[place1] - road_length[place2])));
	}
}

//1047
int cal_hash(string x) {
	return ((((x[0] - 'A') * 26) + x[1] - 'A') * 26 + x[2] - 'A') * 10 + x[3] - '0';
}

string cal_to_string(int n) {
	string a;
	a = n / (26 * 26 * 10) + 'A';
	a += (n % (26 * 26 * 10)) / (26 * 10) + 'A';
	a += (n % (26 * 10)) / 10 + 'A';
	a += n % 10 + '0';
	return a;
}

void Student_list_for_C(){
	int student_n, course_n;
	cin >> student_n >> course_n;
	vector<vector<int>> stu_list(course_n);
	string name;
	int n, course,name_number;
	name.resize(4);
	for (int i = 0; i < student_n; i++) {
		scanf("%s", &name[0]);
		scanf("%d", &n);
		name_number = cal_hash(name);
		for (int j = 0; j < n; j++) {
			scanf("%d", &course);
			stu_list[course - 1].push_back(name_number);
		}
	}
	for (int i = 0; i < course_n; i++) {
		if (stu_list[i].size() >= 0) {
			printf("%d %d\n", i + 1, stu_list[i].size());
			sort(stu_list[i].begin(), stu_list[i].end());
			for (int j = 0; j < stu_list[i].size(); j++) {
				printf("%s\n", cal_to_string(stu_list[i][j]).c_str());
			}
		}
	}
}

//1048
void Find_Coin(){
	int n,sum,money;
	cin >> n >> sum;
	vector<int> money_list1(100002, 0);
	vector<int> money_list2;
	int count = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &money);
		money_list2.push_back(money);
		if(money <= sum)
		money_list1[sum - money] = 1;
		if (sum % 2 == 0 && money == sum/2) {
			count++;
		}
	}
	int flag = 0,min = 100001;
	if (sum % 2 == 0 && count > 1) {
		min = sum / 2;
		flag = 1;
	}
	for (int i = 0; i < n; i++) {
		if (money_list1[money_list2[i]] == 1 && (sum % 2 != 0 || sum % 2 == 0 && money_list2[i] != sum / 2)) {
			if (money_list2[i] < min) {
				min = money_list2[i];
			}
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << "No Solution" << endl;
	}
	else {
		cout << min <<" " << sum - min << endl;
	}
}

//1049
void count_ones(){
	long long n;
	cin >> n;
	long long left, right, a = 1,x,ones = 0;
	while (n / a > 0) {
		x = n / a % 10;
		left = n / a / 10;
		right = n % a;
		if (x == 0) ones += left * a;
		else if (x == 1) ones += left * a + right + 1;
		else if (x >= 2) ones += (left + 1) * a;
		a *= 10;
	}
	cout << ones << endl;
}

//1050
void string_subtraction(){
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	map<char, int> m;
	for (int i = 0; i < str2.length(); i++) {
		m[str2[i]]++;
	}
	for (int i = 0; i < str1.length(); i++) {
		if (!m[str1[i]]) cout << str1[i];
	}
	cout << endl;
}

//1051
void pop_sequence(){
	int n, len, max;
	cin >> max >> len >> n;
	vector<int> list1(len,0);
	vector<int> list2(len, 0);
	stack<int> s;
	int index,index2,s_len;
	for (int i = 0; i < n; i++) {
		index = 0;
		index2 = 0;
		s_len = 0;
		for (int j = 0; j < len; j++) {
			cin >> list1[j];
		}
		for (int j = 1; j <= len; j++) {
			s.push(j);
			s_len++;
			while(!s.empty() && s.top() == list1[index] || s_len == max) {
				list2[index2] = s.top();
				s.pop();
				s_len--;
				index++;
				index2++;
			}
		}
		if (list1 != list2) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
		while (!s.empty()) {
			s.pop();
		}
	}
}

//1064
void buildTree(int root, vector<int> &tree,vector<int> nums,int &pos) {
	if (tree[root] != -1) {
		buildTree(root * 2 + 1, tree, nums, pos);
		tree[root] = nums[pos];
		pos++;
		buildTree(root * 2 + 2, tree, nums, pos);
	}
}

void Compelete_Binary_Search_Tree(){
	int n;	
	cin >> n;
	vector<int> tree(2 * n + 1,-1);
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		tree[i] = 1;
	}
	sort(nums.begin(), nums.end());
	int pos = 0;
	buildTree(0, tree, nums, pos);
	printf("%d", tree[0]);
	for (int i = 1; i < n; i++) {
		printf(" %d", tree[i]);
	}
	cout << endl;
}	

//1079
void Total_Sale_Of_Supply_Chain(){
	queue<int> q;
	int n, len, n2;
	double root_price, percent_rate;
	cin >> n >> root_price >> percent_rate;
	vector<vector<int>> supply_chain_new(n);
	vector<int> level_list(n, 0);
	vector<int> price_list(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> len;
		if (len == 0) {
			cin >> price_list[i];
		}
		else {
			for (int j = 0; j < len; j++) {
				cin >> n2;
				supply_chain_new[i].push_back(n2);
			}
		}
	}
	q.push(0);
	int level = 1;
	while (!q.empty()) {
		if (supply_chain_new[q.front()].size() != 0) {
			for (int i = 0; i < supply_chain_new[q.front()].size(); i++) {
				level_list[supply_chain_new[q.front()][i]] = level_list[q.front()] + 1;
				q.push(supply_chain_new[q.front()][i]);
			}
		}
		q.pop();
	}
	double money = 0,rate = (100 + percent_rate) / 100;
	for (int i = 0; i < n; i++) {
		if (price_list[i] != 0) {
			money += price_list[i] * root_price * pow(rate,level_list[i]);
		}
	}
	printf("%.1f\n", money);
}
//1106
void Lowest_Price_Supply_Chain(){
	queue<int> q;
	int n,son_n,son;
	double root_money, rate;
	cin >> n >> root_money >> rate;
	rate /= 100;
	vector<vector<int>> supply_chain_list(n);
	vector<int> level_list(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> son_n;
		if (son_n != 0) {
			for (int j = 0; j < son_n; j++) {
				cin >> son;
				supply_chain_list[i].push_back(son);
			}
		}
	}
	q.push(0);
	while (!q.empty()) {
		if (supply_chain_list[q.front()].size() != 0) {
			for (int i = 0; i < supply_chain_list[q.front()].size(); i++) {
				level_list[supply_chain_list[q.front()][i]] = level_list[q.front()] + 1;
				q.push(supply_chain_list[q.front()][i]);
			}
		}
		q.pop();
	}
	int min = 1000000,count = 1;
	for (int i = 0; i < n; i++) {
		if (supply_chain_list[i].size() == 0 && level_list[i] < min) {
			min = level_list[i];
			count = 1;
		}
		else if (supply_chain_list[i].size() == 0 && level_list[i] == min) {
			count++;
		}
	}
	printf("%.4f %d", root_money * pow(1 + rate, min), count);
}
int main()
{
	system("pause");
	return 0;
}


vector<int> construct(vector<int> p, vector<int> in, vector<int> l, int begPost, int engPost, int begin, int endin) {
	int x = p[engPost - 1], index1, index2;
	l.push_back(x);
	for (int i = begin; i < endin; i++) {
		if (x == in[i]) {
			index1 = i;
			break;
		}
	}
	int i;
	for (i = begPost; i < engPost - 1; i++) {
		if (p[i] == in[index1 + 1]) {
			index2 = i;
			break;
		}
	}
	if (index1 != begin) {
		construct(p, in, l, begPost, index2, begin, index1);
	}
	else {
		l.push_back(p[begin]);
	}
	if (endin - index2 != 1) {
		construct(p, in, l, index2 + 1, engPost, index1 + 1, endin);
	}
	else {
		l.push_back(p[endin]);
	}
	return l;
}

vector<int> construct(vector<int> p, vector<int> in, vector<int> l) {
	return construct(p, in, l, 0, p.size() - 1, 0, in.size() - 1);
}

	vector<int> postorder_travelsal_list;
	vector<int> inorder_travelsal_list;
	vector<int> level_order_travelsal_list;
	int n,num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		postorder_travelsal_list.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		cin >> num;
		inorder_travelsal_list.push_back(num);
	}
	construct(postorder_travelsal_list, inorder_travelsal_list, level_order_travelsal_list);
	for (int i = 0; i < n; i++) {
		cout << level_order_travelsal_list[i] << " ";
	}



vector<int> DFS(vector<vector<int>> supply_chain_new, vector<int> level_list,int row,int level) {
	for (int i = 0; i < supply_chain_new[row].size(); i++) {
		level_list[supply_chain_new[row][i]] = level + 1;
		if(supply_chain_new[supply_chain_new[row][i]].size()!=0)
		level_list = DFS(supply_chain_new, level_list, supply_chain_new[row][i], level + 1);
	}
	return level_list;
}

vector<int> DFS(vector<vector<int>> supply_chain_new, vector<int> level_list) {
	return DFS(supply_chain_new, level_list, 0, 0);
}


void BFS(vector<vector<int>> supply_chain_new, vector<int> &level_list, vector<int> &now_level_list, int level) {
	vector<int> new_list;
	for (int i = 0; i < now_level_list.size(); i++) {
		for (int j = 0; j < supply_chain_new[now_level_list[i]].size(); j++) {
			level_list[supply_chain_new[now_level_list[i]][j]] = level + 1;
			new_list.push_back(supply_chain_new[now_level_list[i]][j]);
		}
	}
	if (new_list.size() > 0) {
		BFS(supply_chain_new, level_list, new_list, level + 1);
	}
}

void BFS(vector<vector<int>> supply_chain_new, vector<int> &level_list) {
	vector<int> new_list;
	for (int i = 0; i < supply_chain_new[0].size(); i++) {
		level_list[supply_chain_new[0][i]] = 1;
		new_list.push_back(supply_chain_new[0][i]);
	}
	BFS(supply_chain_new, level_list, new_list, 1);
}



class Node {
public:
	int n;
	Node *left, *right;
	Node(int n,Node *l,Node *r) {
		left = l;
		right = r;
	}
	Node() {
		n = -1;
		left = NULL;
		right = NULL;
	}
};

void PreOrder_Traversal(Node *root) {
	stack<Node *> s;
	Node *p = root;
	s.push(p);
	cout << p->n;
	while (!s.empty() || p != NULL) {
		while (p->left != NULL) {
			cout << " " << p->left->n;
			p = p->left;
			s.push(p);
		}
		if (p->right != NULL) {
			cout << " " << p->right;
		}
		else {
			s.pop();
		}
	}
}


1 2 4 8 
	int n,num;
	cin >> n;
	Node *root = NULL;
	vector<int> origin;
	for (int i = 0; i < n; i++) {
		cin >> num;
		origin.push_back(num);
		insert_Binary_Search_Tree(root, num);
	}
	vector<int> PreOrderSequence;
	vector<int> MirrorPreOrderSequence;

class Node {
public:
	int n;
	Node *left, *right;
	Node(int n, Node *l, Node * r) {
		this->n = n;
		left = l;
		right = r;
	}
	Node() {
		n = -1;
		left = NULL;
		right = NULL;
	}
};

void insert_Binary_Search_Tree(Node *root, int n) {
	if (root == NULL) {
		root = new Node;
		root->n = n;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if (root->n > n) {
		insert_Binary_Search_Tree(root->left, n);
	}
	else
	{
		insert_Binary_Search_Tree(root->right, n);
	}
}

void PreOrderTraverse(Node *root, vector<int> &preOrderSequence) {
	if (root == NULL) {
		return;
	}
	preOrderSequence.push_back(root->n);
	PreOrderTraverse(root->left, preOrderSequence);
	PreOrderTraverse(root->right, preOrderSequence);
}

void MirrorPreOrderTraverse(Node *root, vector<int> &MirrorPreOrderSequence) {
	if (root == NULL) {
		return;
	}
	MirrorPreOrderSequence.push_back(root->n);
	MirrorPreOrderTraverse(root->right, MirrorPreOrderSequence);
	MirrorPreOrderTraverse(root->left, MirrorPreOrderSequence);
}

//1081
int GCD(int a, int b) {
	if (a < b)
		std::swap(a, b);
	return b == 0 ? a : GCD(b, a%b);
}

int Rational_Sum()
{
	int n, gcd, devide, sum = 0;
	cin >> n;
	vector<int> numerator_list(n);
	vector<int> denominator_list(n);
	for (int i = 0; i < n; i++) {
		scanf("%d/%d",&numerator_list[i],&denominator_list[i]);
	}
	int denominator = denominator_list[0];
	for (int i = 1; i < n; i++) {
		gcd = GCD(denominator_list[i], denominator);
		denominator *= denominator_list[i];
		denominator /= gcd;
	}
	for (int i = 0; i < n; i++) {
		devide = denominator / denominator_list[i];
		numerator_list[i] *= devide;
	}
	for (int i = 0; i < n; i++) {
		sum += numerator_list[i];
	}
	
	if (sum%denominator == 0) {
		printf_s("%d\n", sum / denominator);
	}
	else {
		if (sum%denominator != 0 && sum / denominator != 0) {
			if (sum < 0) {
				printf_s("-%d %d/%d\n", abs(sum) / denominator, (abs(sum)%denominator) / GCD(abs(sum), denominator), denominator / GCD(abs(sum), denominator));
			}
			else {
				printf_s("%d %d/%d\n", abs(sum) / denominator, (abs(sum) % denominator) / GCD(abs(sum), denominator), denominator / GCD(abs(sum), denominator));
			}
		}
		else if (sum / denominator == 0) {
			printf_s("%d/%d\n", (sum%denominator) / GCD(sum, denominator), denominator / GCD(sum, denominator));
		}
	}
}