#include"car.h"
using namespace std;
int main() {
	carsystem f;
	int c = 0;
	while (c != 7) {
		cout << "welcome to the vehicle management system" << endl
			<< "**********************************" << endl
			<< "*     please choose function     *" << endl
			<< "*     1.add new vehicle          *" << endl
			<< "*     2.remove the vehicle       *" << endl
			<< "*     3.find                     *" << endl
			<< "*     4.vehicle imformation      *" << endl
			<< "*     5.statistical information  *" << endl
			<< "*     6.modify                   *" << endl
			<< "*     7.quit&save                *" << endl
			<< "**********************************" << endl;
		cin >> c;
		if (c < 1 || c>7) {
			cout << "please import 1-7" << endl;
			continue;
		}
		switch (c) {
		case 1: {
			f.add();
			break;
		}
		case 2: {
			f.del();
			break;
		}
		case 3: {
			f.find();
			break;
		}
		case 4: {
			f.sumshow();
			break;
		}
		case 5: {
			f.show();
			break;
		}
		case 6: {
			f.change();
			break;
		}
		case 7: {
			cout << "thanks for you using" << endl;
			break;
		}
		}
	}
	f.output();
	return 0;
}