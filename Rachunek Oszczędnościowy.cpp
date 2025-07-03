//Alicja Nowakowska

#include <iostream>

using namespace std;

class RachunekOszczednosciowy {
private:
	//Static variable is for global use, no matter the instance
	static double oprocentowanieRoczne;
	double stanKonta;
public:
	RachunekOszczednosciowy(double stanKonta)
	:stanKonta(stanKonta) {
	}
	void aktualizujStanKonta() {
		stanKonta += stanKonta * oprocentowanieRoczne / 12;
	}
	//Uses only static variables
	static void zmienOprocentowanie(static double _oprocentowanieRoczne) {
		oprocentowanieRoczne = _oprocentowanieRoczne;
	}
	void Drukuj() {
		cout << "Stan konta klienta po miesiacu z oprocentowaniem rownym " << oprocentowanieRoczne << " to " << stanKonta << " PLN." << endl;
	}
};

//globally changing the value of the static variable
double RachunekOszczednosciowy::oprocentowanieRoczne = 3;

int main() {
	RachunekOszczednosciowy klient1(2000);
	RachunekOszczednosciowy klient2(3000);
	klient1.aktualizujStanKonta(); klient2.aktualizujStanKonta();
	klient1.Drukuj(); klient2.Drukuj();
	cout << endl;
	//Therefore, outside the class, a static member should be accessed through the class scope rather than through an instance
	RachunekOszczednosciowy::zmienOprocentowanie(4.0);
	klient1.aktualizujStanKonta(); klient2.aktualizujStanKonta();
	klient1.Drukuj(); klient2.Drukuj();
}