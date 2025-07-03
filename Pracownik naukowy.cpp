//Alicja Nowakowska

#include <iostream>

using namespace std;

class Osoba {
private:
	//Personal data variables, name and surname
	string imie;
	string nazwisko;
public:
	//Default constructor
	Osoba() :imie("Jaroslaw"), nazwisko("Gesty") {}
	//Constructor with arguments
	Osoba(string imie, string nazwisko)
		:imie(imie), nazwisko(nazwisko) {
	}
	//Copying constructor, referncing to an existing instance of this class
	Osoba(const Osoba& inna) {
		this->imie = inna.imie;
		this->nazwisko = inna.nazwisko;
	}
	//Destructor
	virtual ~Osoba() {}
	//Getters, functions
	string GetNazwisko() const {
		return nazwisko;
	}
	string GetImie() const {
		return imie;
	}
	//Setter
	void UstawDane(const string& imie, const string& nazwisko) {
		this->imie = imie;
		this->nazwisko = nazwisko;
	}
	//Wypisz() to print all the personal data of the person
	virtual void Wypisz() const {
		cout << "\n------------------------------";
		cout << "\nImie: " << imie << "\nNazwisko: " << nazwisko << endl;
	}
};

//Worker inheriting after Person
class Pracownik :public Osoba {
	//Data specific for a worker
private:
	string NIP;
	double zasadniczaPlacaNetto;
public:
	Pracownik()
		:Osoba(), NIP("43264134"), zasadniczaPlacaNetto(8700) {
		cout << "Tworze pracownika " << GetImie() << " " << GetNazwisko() << endl;
	}
	Pracownik(string imie, string nazwisko, string NIP, double zasadniczaPlacaNetto)
		:Osoba(imie, nazwisko), NIP(NIP), zasadniczaPlacaNetto(zasadniczaPlacaNetto) {
		cout << "Tworze pracownika " << GetImie() << " " << GetNazwisko() << endl;
	}
	Pracownik(const Pracownik& inny)
		:Osoba(inny) {
		this->NIP = inny.NIP;
		this->zasadniczaPlacaNetto = inny.zasadniczaPlacaNetto;
		cout << "Tworze kopie pracownika " << GetImie() << " " << GetNazwisko() << endl;
	}
	virtual ~Pracownik() {}
	string GetNIP() {
		return NIP;
	}
	double GetZasadniczaPlacaNetto() const {
		return zasadniczaPlacaNetto;
	}
	void SetNIP(string NIP) {
		this->NIP = NIP;
	}
	void SetZasadniczaPlacaNetto(double zasadniczaPlacaNetto) {
		this->zasadniczaPlacaNetto = zasadniczaPlacaNetto;
	}
	//Overriding parent functions
	void UstawDane(const string& imie, const string& nazwisko, string NIP, double zasadniczaPlacaNetto) {
		Osoba::UstawDane(imie, nazwisko);
		this->NIP = NIP;
		this->zasadniczaPlacaNetto = zasadniczaPlacaNetto;
	}
	void Wypisz() const {
		Osoba::Wypisz();
		cout << "NIP: " << NIP << endl;
		cout << "Zarobki: " << zasadniczaPlacaNetto << endl;
	}
	//To be implemented in children classes. This makes "Worker" an abstract class
	virtual double Koszty() = 0;
};

//Scientist inheriting after Worker
class PracownikNaukowy :public Pracownik {
private:
	string tytulNaukowy;
	string specjalnosc;
public:
	PracownikNaukowy(string tytulNaukowy, string specjalnosc)
	:Pracownik(), tytulNaukowy(tytulNaukowy), specjalnosc(specjalnosc) {}
	PracownikNaukowy(string imie, string nazwisko, string NIP, double zasadniczaPlacaNetto, string tytulNaukowy, string specjalnosc)
	:Pracownik(imie, nazwisko, NIP, zasadniczaPlacaNetto), tytulNaukowy(tytulNaukowy), specjalnosc(specjalnosc) {}
	PracownikNaukowy(const PracownikNaukowy& kopiaPracownika)
	:Pracownik(kopiaPracownika) {
		this->tytulNaukowy = kopiaPracownika.tytulNaukowy;
		this->specjalnosc = kopiaPracownika.specjalnosc;
	}
	virtual ~PracownikNaukowy() {}
	void Wypisz() const {
		Pracownik::Wypisz();
		cout << "Tytul naukowy: " << tytulNaukowy << endl;
		cout << "Specjalnosc: " << specjalnosc << endl;
		cout << "------------------------------\n";
	}
};

//Specific titles 
class Magister :public PracownikNaukowy {
public:
	Magister()
		:PracownikNaukowy("Magister", "Edukacja wy?sza") {}
	Magister(string imie, string nazwisko, string NIP, double zasadniczaPlacaNetto, string tytulNaukowy, string specjalnosc)
		:PracownikNaukowy(imie, nazwisko, NIP, zasadniczaPlacaNetto, tytulNaukowy, specjalnosc) {}
	Magister(const Magister& kopia)
		:PracownikNaukowy(kopia) {}
	void Wypisz() const {
		PracownikNaukowy::Wypisz();
	}
	double Koszty() {
		return GetZasadniczaPlacaNetto() * 0.5;
	}
};

class Doktor :public PracownikNaukowy {
public:
	Doktor()
	:PracownikNaukowy("Doktor", "Chirurgia") {}
	Doktor(string imie, string nazwisko, string NIP, double zasadniczaPlacaNetto, string tytulNaukowy, string specjalnosc)
	:PracownikNaukowy(imie, nazwisko, NIP, zasadniczaPlacaNetto, tytulNaukowy, specjalnosc) {}
	Doktor(const Doktor& kopia)
	:PracownikNaukowy(kopia) {}
	void Wypisz() const {
		PracownikNaukowy::Wypisz();
	}
	double Koszty() {
		return GetZasadniczaPlacaNetto() * 0.6;
	}
};


class DoktorHIProfesor :public PracownikNaukowy {
public:
	DoktorHIProfesor()
		:PracownikNaukowy("Profesor", "Psychologia") {}
	DoktorHIProfesor(string imie, string nazwisko, string NIP, double zasadniczaPlacaNetto, string tytulNaukowy, string specjalnosc)
		:PracownikNaukowy(imie, nazwisko, NIP, zasadniczaPlacaNetto, tytulNaukowy, specjalnosc) {}
	DoktorHIProfesor(const DoktorHIProfesor& kopia)
		:PracownikNaukowy(kopia) {}
	void Wypisz() const {
		PracownikNaukowy::Wypisz();
	}
	double Koszty() {
		return GetZasadniczaPlacaNetto() * 0.7;
	}
};

//Distinct class to print a document for any worker (this means any class inheriting after Worker)
//Because all have this same function, wheter it is overriden or not
class Ksiegowosc {
public:
	void DrukujPIT(Pracownik& P) const {
		cout << endl << "=== PIT-21 ===";
		cout << endl << "Dane podatnika: ";
		P.Wypisz();
		cout << endl << "Wysokosc kosztow uzyskania przychodu: " << P.Koszty();
		cout << endl;
	}
};

int main() {
	Ksiegowosc ksiegowosc;
	Doktor p1;

	Magister p2("Hieronim", "Twardowski", "43534512", 8700, "Magister", "Edukacja wczesnoszkolna");
	DoktorHIProfesor p3;
	ksiegowosc.DrukujPIT(p1);
	ksiegowosc.DrukujPIT(p2);
	ksiegowosc.DrukujPIT(p3);
}