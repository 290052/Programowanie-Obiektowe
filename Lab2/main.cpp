#include <iostream>
#include <string>
#include <cstdlib>

class Osoba {
private:
  std::string imie;
  std::string nazwisko;
  std::string nr_indeksu;

public:
  void set_imie(std::string);
  void set_nazwisko(std::string);
  void set_indeks(std::string);
  std::string get_imie();
  std::string get_nazwisko();
  std::string get_indeks();
};

void Osoba::set_imie(std::string _imie) {
  //if (_imie.lenght > 2) {
    imie = _imie;
  //}
}

void Osoba::set_nazwisko(std::string _nazwisko) {
  //if (_nazwisko.lenght > 2) {  
    nazwisko = _nazwisko;
  //}
}

void Osoba::set_indeks(std::string _nr_indeksu) {
  //if (_nr_indeksu.lenght = 6) {
    nr_indeksu = _nr_indeksu;
  //}
}

std::string Osoba::get_imie() { return imie; }
std::string Osoba::get_nazwisko() { return nazwisko; }
std::string Osoba::get_indeks() { return nr_indeksu; }

void dodajOsobe(Osoba *listaStudentow, std::string imie, std::string nazwisko, std::string indeks) {
  int wielkosc = sizeof(listaStudentow);
  std::cout << wielkosc << std::endl;
  listaStudentow[wielkosc].set_imie(imie);
  listaStudentow[wielkosc].set_nazwisko(nazwisko);
  listaStudentow[wielkosc].set_indeks(indeks);
}

void ustawObecnosc(Osoba *listaStudentow, bool *tabObecnosc, std::string nazwisko, bool obecnosc) {
  for (int i = 0; i < 10; i++) {
    if (listaStudentow[i].get_nazwisko() == nazwisko) tabObecnosc[i] = obecnosc; 
  }
}

void edytujOsobe(Osoba *listaStudentow) {
  int nrNaLiscie;
  std::string indeks;
  std::string nowyIndeks;
  std::string imie;
  std::string nazwisko;
  
  std::cout << "Podaj indeks ktory chcesz zmienic: ";
  std::cin >> indeks;
  std::cout << "Podaj nowy numer indeksu: ";
  std::cin >> nowyIndeks;
  std::cout << "Podaj nowe imie: ";
  std::cin >> imie;
  std::cout << "Podaj nowe nazwisko: ";
  std::cin >> nazwisko;

  for (int i = 0; i < 10; i++) {
    if (listaStudentow[i].get_indeks() == indeks) nrNaLiscie = i;
  }

  listaStudentow[nrNaLiscie].set_indeks(nowyIndeks);
  listaStudentow[nrNaLiscie].set_imie(imie);
  listaStudentow[nrNaLiscie].set_nazwisko(nazwisko);
}

void usunOsobe(Osoba *listaStudentow, bool *tabObecnosc) {
  std::string indeks;
  int nrNaLiscie = 0;

  std::cout << "Wybierz indeks ktory chcesz usunac: ";
  std::cin >> indeks;

  for (int i = 0; i < 10; i++) {
    if (listaStudentow[i].get_indeks() == indeks) nrNaLiscie = i;
  }

  for (int i = nrNaLiscie; i < 9; i++) {
    listaStudentow[i] = listaStudentow[i + 1];
    tabObecnosc[i] = tabObecnosc[i + 1];
  }

  tabObecnosc[9] = 0;
}

void drukujListe(Osoba *listaStudentow, bool *tabObecnosc) {
  std::cout << "nr Indeksu" << "\t" << "Imie" << "\t" << "Nazwisko" << "\t" << "Obecnosc" << std::endl;
  
  for (int i = 0; i < 10; i++) {
    std::cout << listaStudentow[i].get_indeks() << "\t" << listaStudentow[i].get_imie() << "\t" << listaStudentow[i].get_nazwisko() << "\t" << tabObecnosc[i] << std::endl;
  }
}

int main() {
  // Tworzenie tablic oraz przypisanie danych testowych
  Osoba listaStudentow[10];
  std::cout << sizeof(listaStudentow) << std::endl;
  bool tabObecnosc[10];// = {1, 1, 1, 0, 1, 1, 0, 0, 1, 1};

  int wybor = 0;

  while ( wybor != 6) {
    std::cout << "1. Dodaj osobe" << std::endl;
    std::cout << "2. Ustaw obecnosc" << std::endl;
    std::cout << "3. Drukuj liste" << std::endl;
    std::cout << "4. Edytuj osobe" << std::endl;
    std::cout << "5. Usun osobe" << std::endl;
    std::cout << "6. Koniec" << std::endl;
    std::cin >> wybor;

    system("clear");

    if (wybor == 1) {
      std::string imie;
      std::string nazwisko;
      std::string indeks;

      std::cout << "Podaj nowe imie: ";
      std::cin >> imie;
      std::cout << "Podaj nowe nazwisko: ";
      std::cin >> nazwisko;
      std::cout << "Podaj nowy indeks: ";
      std::cin >> indeks;

      dodajOsobe(listaStudentow, imie, nazwisko, indeks);
    }

    if (wybor == 2) {
      std::string nazwisko;
      bool obecnosc;

      std::cout << "Podaj nazwisko przy ktorym chcesz zmienic obecnosc: ";
      std::cin >> nazwisko;
      std::cout << "Podaj obecnosc tej osoby(0/1): ";
      std::cin >> obecnosc;

      ustawObecnosc(listaStudentow, tabObecnosc, nazwisko, obecnosc);
    }

    if (wybor == 3) drukujListe(listaStudentow, tabObecnosc);

    if (wybor == 4) edytujOsobe(listaStudentow);

    if (wybor == 5) usunOsobe(listaStudentow, tabObecnosc);
  }

  return 0;
}
