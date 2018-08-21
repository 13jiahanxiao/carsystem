#include<string>
#include<iostream>
using namespace std;
const int k = 30;
class car {
	string license;
	string company;
	string time;
	string type;
	int km;
	int oil;
	double sum;
public:
	string number;
	car(string, string, string, string, string, int, int);
	void number1(string);
	void license1(string);
	void company1(string);
	void time1(string);
	void type1(string);
	void km1(int);
	void oil1(int);
	virtual double sum1();
	virtual string num() = 0;
	string com();
	string typ();
	virtual void show1();
	virtual void show();
	virtual void show2();
};
class bus :public car {
	int busload;
	int maintain;
	double sum;
public:
	bus(string number, string license, string company, string time, string type, int km, int oil, int busload);
	virtual void busload1(int);
	double sum1();
	virtual string num();
	virtual void show1();
	virtual void show();
	virtual void show2();
};
class salooncar :public car {
	int box;
	int maintain;
	double sum;
public:
	salooncar(string number, string license, string company, string time, string type, int km, int oil, int box);
	virtual void box1(int);
	double sum1();
	virtual string num();
	virtual void show1();
	virtual void show();
	virtual void show2();
};
class truck :public car {
	int load;
	int maintain;
	double sum;
public:
	truck(string number, string license, string company, string time, string type, int km, int oil, int load);
	void load1(int);
	double sum1();
	virtual string num();
	virtual void show1();
	virtual void show();
	virtual void show2();
};
class carsystem {
	car*A[k];
	int i;
public:
	carsystem();
	void add();
	void del();
	void find();
	void change();
	void show();
	void sumshow();
	void output();
};
