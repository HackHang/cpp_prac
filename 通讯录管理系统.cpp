#include<iostream>
using namespace std;
struct Person
{
	string name;
	int age;
	string address;
};
void showMenu();
void Add(Person *p,int s);
void Display(Person p[],int s);
void Delete(Person* p, int s);
void Find(Person p[],int s);
void Modify(Person* p, int s);
void DeleteAll(Person *p,int s);
int main() {
	int select = 0;
	Person p[10];
	int s = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			Add(p,s);
			s++;
			break;
		case 2:
			Display(p,s);
			break;
		case 3:
			Delete(p, s);
			s--;
			break;
		case 4:
			Find(p,s);
			break;
		case 5:
			Modify(p, s);
			break;
		case 6:
			DeleteAll(p, s);
			s = 0;
			break;
		case 0:
			exit(0);
		default:
			break;
		}
		//break;
	}
	return 0;
}
void showMenu() {
	cout << "1.Add" << endl;
	cout << "2.Display All" << endl;
	cout << "3.Delete someone" << endl;
	cout << "4.Find someone" << endl;
	cout << "5.Modify" << endl;
	cout << "6.Delete All" << endl;
	cout << "0.Exit" << endl;
	return;
}
void Add(Person *p,int s) {
	string name;
	int age = 0;
	string address;
	cout << "Please input name: " << endl;
	cin >> name;
	cout << "Please input age: " << endl;
	cin >> age;
	cout << "Please input address: " << endl;
	cin >> address;
	p[s].address = address;
	p[s].age = age;
	p[s].name = name;
	return;
}
void Display(Person p[], int s) {
	if (s == 0) {
		cout << "无数据！！！" << endl;
		return;
	}
	for (int i = 0;i < s;i++) {
		cout << "名字： " << p[i].name
			<< "   年龄： " << p[i].age  
			<< "   地址： " << p[i].address 
			<< endl;
	}
	return;
}
void Delete(Person* p, int s) {
	string WillDele;
	cout << "Please input delete name:" << endl;
	cin >> WillDele;
	int i = 0;
	for (i = 0;i < s;i++) {
		if (p[i].name == WillDele) {
			p[i] = {"",NULL,""};
			break;
		}
	}
	if (i == s-1) return;
	if (i < s && i>=0) {
		for (int j = i; j < s - 1; j++) {
			p[j] = p[j + 1];
		}
	}
	p[s-1] = { "",NULL,"" };
	return;
}
void Find(Person p[],int s) {
	string name;
	cout << "Please input find name: " << endl;
	cin >> name;
	int i;
	for (i = 0;i < s;i++) {
		if (p[i].name == name) {
			break;
		}
	}
	cout << "名字： " << p[i].name
		<< "   年龄： " << p[i].age
		<< "   地址： " << p[i].address
		<< endl;
	return;
}
void Modify(Person* p, int s) {
	string name;
	string Newname;
	int Newage = 0;
	string Newaddress;
	cout << "Please input modify name: " << endl;
	cin >> name;
	int i;
	for (i = 0;i < s;i++) {
		if (p[i].name == name) {
			break;
		}
	}
	cout << "Please input new name: " << endl;
	cin >> Newname;
	cout << "Please input new age: " << endl;
	cin >> Newage;
	cout << "Please input new address: " << endl;
	cin >> Newaddress;
	p[i].address = Newaddress;
	p[i].age = Newage;
	p[i].name = Newname;
	return;
}
void DeleteAll(Person *p,int s) {
	for (int i = 0;i < s;i++) {
		p[i] = { "",NULL,"" };
	}
}