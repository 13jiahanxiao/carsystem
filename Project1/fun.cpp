#include<fstream>
#include<iomanip>
#include"car.h"
using namespace std;
int op = 5;
car::car(string number = "0", string license = "0", string company = "0", string time = "0", string type = "0", int km = 0, int oil = 0) {
	this->number = number;
	this->license = license;
	this->company = company;
	this->time = time;
	this->type = type;
	this->km = km;
	this->oil = oil;
	this->sum = this->oil * op;
}
void car::license1(string license) {
	this->license = license;
}
void car::number1(string number) {
	this->number = number;
}
void car::company1(string company) {
	this->company = company;
}
void car::time1(string time) {
	this->time = time;
}
void car::type1(string type) {
	this->type = type;
}
void car::km1(int km) {
	this->km = km;
}
void car::oil1(int oil) {
	this->oil = oil;
}
double car::sum1() {
	return sum;
}
string car::com() {
	return company;
}
string car::typ() {
	return type;
}
void car::show1() {
	cout<<"------------------------------------------------------------------------------------------------"<<endl
		<<left<<setw(12)<<"|*number*"<<setw(12)<<"|*license*"<<setw(12)<<"|*company*"<<setw(12)<<"|*time*"<<setw(12)<<"|*type*"<<setw(12)<<"|*km*"<<setw(12)<<"|*oil*"<<setw(12);
} 
void car::show() {
	cout <<left<<"|"<<setw(11)<< number << "|" <<setw(11)<< license << "|" <<setw(11)<< company << "|" <<setw(11)<< time << "|" <<setw(11)<< type << "|" <<setw(11)<< km << "|" <<setw(11)<< oil << "|"<<setw(11);
}
void car::show2() {
	ofstream outfile("car.txt", ios::app);
	outfile << number << " " << license << " " << company << " " << time << " " << type << " " << km << " " << oil << " ";
	outfile.close();
}
bus::bus(string number = "0", string license = "0", string company = "0", string time = "0", string type = "0", int km = 0, int oil = 0, int busload = 0) :car(number, license, company, time, type, km, oil) {
	this->busload = busload;
	maintain = 2000;
}
void bus::busload1(int busload) {
	this->busload = busload;
}
double bus::sum1() {
	return car::sum1() + maintain;
}
string bus::num() {
	return number;
}
void  bus::show1() {
	car::show1();
	cout << "|busload(people) " << endl;
}
void bus::show() {
	car::show();
	cout << busload << endl;
}
void bus::show2() {
	car::show2();
	ofstream outfile("car.txt", ios::app);
	outfile << busload << endl;
	outfile.close();
}
salooncar::salooncar(string number = "0", string license = "0", string company = "0", string time = "0", string type = "0", int km = 0, int oil = 0, int box = 0) :car(number, license, company, time, type, km, oil) {
	this->box = box;
	maintain = 1000;
}
void salooncar::box1(int box) {
	this->box = box;
}
double salooncar::sum1() {
	return car::sum1() + maintain;
}
string salooncar::num() {
	return number;
}
void salooncar::show1() {
	car::show1();
	cout << "|box" << endl;
}
void salooncar::show() {
	car::show();
	cout << box << endl;
}
void salooncar::show2() {
	car::show2();
	ofstream outfile("car.txt", ios::app);
	outfile << box << endl;
	outfile.close();
}
truck::truck(string number = "0", string license = "0", string company = "0", string time = "0", string type = "0", int km = 0, int oil = 0, int load = 0) :car(number, license, company, time, type, km, load) {
	this->load = load;
	maintain = 1500;
}
void truck::load1(int load) {
	this->load = load;
}
double truck::sum1() {
	return car::sum1() + maintain;
}
string truck::num() {
	return number;
}
void truck::show1() {
	car::show1();
	cout << "|load{ton)" << endl;
}
void truck::show() {
	car::show();
	cout << load << endl;
}
void truck::show2() {
	car::show2();
	ofstream outfile("car.txt", ios::app);
	outfile << load << endl;
	outfile.close();
}
carsystem::carsystem() {
	i = 0;
	ifstream infile("car.txt");
	char a[20] = { 0 };
	int b;
	string number, license, company, time, type;
	int km, oil, busload, box, load;
	while (!infile.eof()) {
		infile >> a;
		number = a;
		infile >> a;
		license = a;
		infile >> a;
		company = a;
		infile >> a;
		time = a;
		infile >> a;
		type = a;
		infile >> b;
		km = b;
		infile >> b;
		oil = b;
		if (type == "bus") {
			infile >> b;
			busload = b;
			bus *m = new bus(number, license, company, time, type, km, oil, busload);
			A[i] = m;
		}
		if (type == "salooncar") {
			infile >> b;
			box = b;
			salooncar *m = new salooncar(number, license, company, time, type, km, oil, box);
			A[i] = m;
		}
		if (type == "truck") {
			infile >> b;
			load = b;
			truck *m = new truck(number, license, company, time, type, km, oil, load);
			A[i] = m;
		}
		i++;
	}
	i = i - 1;
	infile.close();
}
void carsystem::add() {
	if (i == k) {
		cout << "the vehicle system is full" << endl
			<< "come back main interface" << endl;
		return;
	}
	string license, company, time, type, number;
	int km, oil, busload = 0, load = 0, box = 0;
	int x = 0, b = 0;
	while (b != 1) {
		int o = 0;
		cout << "************************************" << endl
			<< "* please import new vehicle number *" << endl
			<< "************************************" << endl;
		cin >> number;
		if (i != 0)for (x = 0; x < i; x++) {
			if (number == A[x]->num()) {
				cout << "!!!vehicle number repetition!!!" << endl
					<< "!!!please import again!!!" << endl;
				o = 1;
			}
		}
		if(o == 1) b=0;
		else b = 1;
	}
	cout << "*************************" << endl
		<< "* please import license *" << endl
		<< "*************************" << endl;
	cin >> license;
	cout << "*************************" << endl
		<< "* please import company *" << endl
		<< "*************************" << endl;
	cin >> company;
	cout << "**********************************" << endl
		<< "* please import manufacture data *" << endl
		<< "**********************************" << endl;
	cin >> time;
	int h, f = 0;
	while (f != 1) {
		cout << "***********************" << endl
			<< "*  please select type *" << endl
			<< "*  1.bus              *" << endl
			<< "*  2.saloon car       *" << endl
			<< "*  3.truck            *" << endl
			<< "***********************" << endl;
		cin >> h;
		if (h < 1 || h>3) {
			cout << "only 3 options" << endl
				<< "plese select again" << endl;
			continue;
		}
		switch (h) {
		case 1: {
			type = "bus";
			break;
		}
		case 2: {
			type = "salooncar";
			break;
		}
		case 3: {
			type = "truck";
			break;
		}
		}
		f = 1;
	}
	cout << "*****************************" << endl
		<< "* please import km traveled *" << endl
		<< "*****************************" << endl;
	cin >> km;
	cout << "*****************************************" << endl
		<< "* please import fuel consumption per km *" << endl
		<< "*****************************************" << endl;
	cin >> oil;
	if (type == "bus") {
		cout << "*************************" << endl
			<< "* please import busload *" << endl
			<< "*************************" << endl;
		cin >> busload;
		bus *a = new bus(number, license, company, time, type, km, oil, busload);
		A[i] = a;
	}
	if (type == "salooncar") {
		cout << "**********************" << endl
			<< "* please import boxs *" << endl
			<< "**********************" << endl;
		cin >> box;
		salooncar* a = new salooncar(number, license, company, time, type, km, oil, box);
		A[i] = a;
	}
	if (type == "truck") {
		cout << "**********************" << endl
			<< "* please import load *" << endl
			<< "**********************" << endl;
		cin >> load;
		truck* a = new truck(number, license, company, time, type, km, oil, load);
		A[i] = a;
	}
	i++;
}
void carsystem::del() {
	if (i == 0) {
		cout << "database is empty" << endl
			<< "come back to main interface" << endl;
		return;
	}
	string number;
	cout << "***********************************************************" << endl
		<< "* please import the number of date which you wanna delete *" << endl
		<< "***********************************************************" << endl;
	cin >> number;
	int q, k = -1, t;
	for (q = 0; q <i; q++) {
		if (A[q]->num() == number)
			k = q;
	}
	if (k != -1) {
		delete A[k];
		for (t = k; t <= q; t++) A[t] = A[t + 1];
		i--;
	}
	else cout << "not found" << endl
		<< "come back main interface" << endl;
}
void carsystem::find() {
	char d;
	if (i == 0) {
		cout << "database is empty" << endl
			<< "return to main interface" << endl;
		return;
	}
	int a;
	int p;
	string gg;
	int j = -1;
	cout << "******************************" << endl
		<< "*  please choose search way   *" << endl
		<< "*   1.number search           *" << endl
		<< "*   2.company search          *" << endl
		<< "*   3.type search             *" << endl
		<< "*   4.return                  *" << endl
		<< "*******************************" << endl;
	cin >> a;
	if (a < 1 || a>4) {
		cout << "please import 1-4" << endl
			<< "go back previous interface" << endl;
		return;
	}
	switch (a) {
	case 1: {
		cout << "*******************************************" << endl
			<< "* please import  number you wanna search  *" << endl
			<< "*******************************************" << endl;
		cin >> gg;
		for (p = 0; p < i; p++) {
			if (A[p]->num() == gg) {
				j = p;
				break;
			}
		}
		if (j != -1) {
			A[j]->show1();
			A[j]->show();
		}
		else {
			cout << "not found" << endl;
			return;
		}
		break;
	}
	case 2: {
		cout << "***********************************************" << endl
			<< "* please import company name you wanna search *" << endl
			<< "***********************************************" << endl;
		cin >> gg;
		for (p = 0; p < i; p++) {
			if (A[p]->com() == gg) {
				j = p;
				A[j]->show1();
				A[j]->show();
			}
		}
		break;
	}
	case 3: {
		cout << "*******************************************" << endl
			<< "* please import car type you wanna search *" << endl
			<< "*******************************************" << endl;
		cin >> gg;
		for (p = 0; p < i; p++) {
			if (A[p]->typ() == gg) {
				j = p;
				A[j]->show1();
				A[j]->show();
			}
		}
		break;
	}
	default:return;
	}
	if (j == -1 ) {
		cout << "not found" << endl;
		return;
	}
	
	}
void carsystem::change() {
	char d;
	if (i == 0) {
		cout << "database is empty" << endl
			<< "return to main interface" << endl;
		return;
	}
	int a;
	int p;
	string gg;
	int j = -1;
	cout << "*******************************************" << endl
		<< "* please import  number you wanna change  *" << endl
		<< "*******************************************" << endl;
	cin >> gg;
	for (p = 0; p < i; p++) {
		if (A[p]->num() == gg) {
			j = p;
			break;
		}
	}
	if (j != -1) {
		A[j]->show1();
		A[j]->show();
	}
	else {
		cout << "not found" << endl;
		return;
	}
	int r;
	cout << "**************************************" << endl
		<< "* select which data you wanna modify *" << endl
		<< "*      1.number                      *" << endl
		<< "*      2.license                     *" << endl
		<< "*      3.company                     *" << endl
		<< "*      4.time                        *" << endl
		<< "*      5.type                        *" << endl
		<< "*      6.km                          *" << endl
		<< "*      7.oil                         *" << endl;
	if (A[j]->typ() == "bus")cout << "*      8.busload                     *" << endl
		<< "**************************************" << endl;
	else if (A[j]->typ() == "salooncar")cout << "*      8.box                         *" << endl
		<< "**************************************" << endl;
	else if (A[j]->typ() == "truck")cout << "*      8.load                        *" << endl
		<< "**************************************" << endl;
	cin >> r;
	if (r < 1 || r>8) {
		cout << "you import wrong number" << endl;
		cout << "go back main interface" << endl;
		return;
	}
	string z;
	int s;
	switch (r) {
	case 1: {
		cout << "import numerical value" << endl;
		cin >> z;
		int u;
		for (u = 0; u <= i; u++) {
			if (A[u]->num() == z) {
				cout << "repetition" << endl
					<< "back" << endl;
				return;
			}
		}
		A[j]->number1(z);
		break;
	}
	case 2: {
		cout << "import numerical value" << endl;
		cin >> z;
		A[j]->license1(z);
		break;
	}
	case 3: {
		cout << "import numerical value" << endl;
		cin >> z;
		A[j]->company1(z);
		break;
	}
	case 4: {
		cout << "import numerical value" << endl;
		cin >> z;
		A[j]->time1(z);
		break;
	}
	case 5: {
		cout << "import numerical value" << endl;
		cin >> z;
		A[j]->type1(z);
		break;
	}
	case 6: {
		cout << "import numerical value" << endl;
		cin >> s;
		A[j]->km1(s);
		break;
	}
	case 7: {
		cout << "import numerical value" << endl;
		cin >> s;
		A[j]->oil1(s);
		break;
	}
	case 8: {
		cout << "import numerical value" << endl;
		cin >> s;
		if (A[j]->typ() == "bus") {
			dynamic_cast<bus*>(A[p])->busload1(s);
		}
		if (A[j]->typ() == "salooncar") {
			dynamic_cast<salooncar*>(A[p])->box1(s);
		}
		if (A[j]->typ() == "truck") {
			dynamic_cast<truck*>(A[p])->load1(s);
		}
		break;
	}
	}
}
void carsystem::show() {
	int a, b = 0, s = 0, t = 0;
	for (a = 0; a < i; a++) {
		if (A[a]->typ() == "bus")b++;
		if (A[a]->typ() == "salooncar")s++;
		if (A[a]->typ() == "truck")t++;
	}
	cout <<"************************************************** "<<endl
		<< "*   there are " << i << " car                              " << endl
		<< "*   there have  " << b << "  bus  " << s << "  salooncar  " << t << "  truck   " << endl
		<<"**************************************************"<<endl;
}
void carsystem::sumshow() {
	int a;
	for (a = 0; a < i; a++) {
		A[a]->show1();
		A[a]->show();
	}
}
void carsystem::output() {
	int a;
	ofstream outfile("car.txt");
	outfile.close();
	for (a = 0; a < i; a++) {
		A[a]->show2();
	}
}