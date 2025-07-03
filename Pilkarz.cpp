//Alicja Nowakowska

#include <iostream>
using namespace std;

class Pilkarz {
  private:
	//Base data of the footballer
	string imie;
	string nazwisko;
	string klub;
	double wzrost;
	double waga;
	//Statistics
	double strzaly;
	double podania;
	double wytrzymalosc;
	double obrona;
	double skok;
	double wyglad;
	//Skills
	int krzyk;
	int walka;
	int sztuczki;
  public:
	Pilkarz();
	Pilkarz(string imie, string nazwisko, string klub, double wzrost, double waga);
	void Wypisz() const;
	void Wypisz_Ocene_koncowa();
	double Ocena_ogolna();
	void Ocena_zawodnika();
	void Trenuj(int trening);
};

//Default constructor
Pilkarz::Pilkarz() {
	imie = "Teozjusz";
	nazwisko = "Zlomiesny";
	klub = "Stowarzyszenie Ziezimieszkow";
	wzrost = rand() % 101 + 150;
	waga = rand() % 61 + 60;
	strzaly = rand() % 100 + 1;
	podania = rand() % 100 + 1;
	wytrzymalosc = rand() % 100 + 1;
	obrona = rand() % 100 + 1;
	skok = rand() % 100 + 1;
	wyglad = rand() % 100 + 1;
	krzyk = rand() % 6 + 1;
	walka = rand() % 6 + 1;
	sztuczki = rand() % 6 + 1;
}

//Overloading the constructor
Pilkarz::Pilkarz(string imie, string nazwisko, string klub, double wzrost, double waga)
:imie(imie), nazwisko(nazwisko), klub(klub), wzrost(wzrost), waga(waga) {
	strzaly = rand() % 100 + 1;
	podania = rand() % 100 + 1;
	wytrzymalosc = rand() % 100 + 1;
	obrona = rand() % 100 + 1;
	skok = rand() % 100 + 1;
	wyglad = rand() % 100 + 1;
	krzyk = rand() % 6 + 1;
	walka = rand() % 6 + 1;
	sztuczki = rand() % 6 + 1;
}

//Printing data
void Pilkarz::Wypisz() const {
	cout << "\n=====================| DANE ZAWODNIKA |=====================\n";
	cout << "imie: " << imie << endl;
	cout << "nazwisko: " << nazwisko << endl;
	cout << "klub: " << klub << endl;
	cout << "wzrost: " << wzrost << endl;
	cout << "waga: " << waga << endl;
	cout << "=======================| STATYSTYKI |=======================\n";
	cout << "strzaly: " << strzaly << endl;
	cout << "podania: " << podania << endl;
	cout << "wytrzymalosc: " << wytrzymalosc << endl;
	cout << "obrona: " << obrona << endl;
	cout << "skok: " << skok << endl;
	cout << "wyglad: " << wyglad << endl;
}

//Printing the final rating by categories
void Pilkarz::Wypisz_Ocene_koncowa() {
	cout << "=================| UMIEJETNOSCI SPECJALNE |=================\n";
	Pilkarz::Ocena_zawodnika();
	cout << "======================| OCENA OGOLNA |======================\n";
	cout << Ocena_ogolna();
	cout << "\n============================================================\n\n";
}

//General rating (by statistics
double Pilkarz::Ocena_ogolna() {
	return (strzaly + podania + wytrzymalosc + obrona + skok + wyglad) / 6;
}

//Printing as many stars as many points of a certain skill the footballer has  (skills rating)
void Pilkarz::Ocena_zawodnika() {
	cout << "krzyk: ";
	for (int i = 0; i < krzyk; i++) {
		cout << "*";
	}
	cout << endl;
	cout << "bezpodsrednie starcie: ";
	for (int i = 0; i < walka; i++) {
		cout << "*";
	}
	cout << endl;
	cout << "podbijanie pilki: ";
	for (int i = 0; i < sztuczki; i++) {
		cout << "*";
	}
	cout << endl;
}

//Printing simple menu to choose a statistic to rise
void Pilkarz::Trenuj(int trening) {
	cout << "=========================| TRENUJ |=========================\n";
	cout << "jaka umiejetnosc chcesz podniesc? Wprowadz numer:\n";
	cout << "[1] strzaly" << endl;
	cout << "[2] podania" << endl;
	cout << "[3] wytrzymalosc" << endl;
	cout << "[4] obrona" << endl;
	cout << "[5] skok" << endl;
	int odp;
	cin >> odp;
	switch (odp) {
	case 1: if (strzaly + trening < 100) { strzaly += trening; } else { strzaly = 100; }; 
		  break;
	case 2:	if (podania + trening < 100) { podania += trening; } else { strzaly = 100; };
		  break;
	case 3:	if (wytrzymalosc + trening < 100) { wytrzymalosc += trening; } else { wytrzymalosc = 100; };
		  break;
	case 4: if (obrona + trening < 100) { obrona += trening; } else { obrona = 100; };
		  break;
	case 5: if (skok + trening < 100) { skok += trening; } else { skok = 100; }; 
		  break;
	}
	cout << "============================================================\n\n";
}

int main() {
	Pilkarz p1;
	p1.Wypisz();
	p1.Wypisz_Ocene_koncowa();

	Pilkarz p2;
	p2.Wypisz();
	p2.Wypisz_Ocene_koncowa();

	Pilkarz p3("Jerzy", "Barachlo", "Spinka", 177, 120);
	p3.Wypisz();
	p3.Wypisz_Ocene_koncowa();
	p3.Trenuj(10);
	p3.Wypisz();
	p3.Wypisz_Ocene_koncowa();
}