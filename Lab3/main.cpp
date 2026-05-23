#include <cstdlib>
#include <iostream>
#include <string>

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
  // if (_imie.lenght > 2) {
  imie = _imie;
  //}
}

void Osoba::set_nazwisko(std::string _nazwisko) {
  // if (_nazwisko.lenght > 2) {
  nazwisko = _nazwisko;
  //}
}

void Osoba::set_indeks(std::string _nr_indeksu) {
  // if (_nr_indeksu.lenght = 6) {
  nr_indeksu = _nr_indeksu;
  //}
}

std::string Osoba::get_imie() { return imie; }
std::string Osoba::get_nazwisko() { return nazwisko; }
std::string Osoba::get_indeks() { return nr_indeksu; }

class Interfejs {
private:
  Osoba *listaStudentow;
  bool *tabObecnosc;
  int liczbaOsob;

  void dodajOsobe();
  void ustawObecnosc();
  void edytujOsobe();
  void usunOsobe();
  void drukujListe();

public:
  Interfejs();
  ~Interfejs();

  void menu();
};

Interfejs::Interfejs() {
  listaStudentow = new Osoba[10];
  tabObecnosc = new bool[10];
  liczbaOsob = 0;
}

Interfejs::~Interfejs() {
  delete[] listaStudentow;
  delete[] tabObecnosc;
}

void Interfejs::menu() {
  int wybor = 0;

  while (wybor != 6) {
    std::cout << "1. Dodaj osobe" << std::endl;
    std::cout << "2. Ustaw obecnosc" << std::endl;
    std::cout << "3. Drukuj liste" << std::endl;
    std::cout << "4. Edytuj osobe" << std::endl;
    std::cout << "5. Usun osobe" << std::endl;
    std::cout << "6. Koniec" << std::endl;
    std::cin >> wybor;

    system("clear");

    if (wybor == 1)
      dodajOsobe();
    if (wybor == 2)
      ustawObecnosc();
    if (wybor == 3)
      drukujListe();
    if (wybor == 4)
      edytujOsobe();
    if (wybor == 5)
      usunOsobe();
  }
}

void Interfejs::dodajOsobe() {
  if (liczbaOsob == 10) {
    std::cout << "Lista jest pełna" << std::endl;
    return;
  }

  std::string imie;
  std::string nazwisko;
  std::string indeks;

  std::cout << "Podaj nowe imie: ";
  std::cin >> imie;
  std::cout << "Podaj nowe nazwisko: ";
  std::cin >> nazwisko;
  std::cout << "Podaj nowy indeks: ";
  std::cin >> indeks;

  listaStudentow[liczbaOsob].set_imie(imie);
  listaStudentow[liczbaOsob].set_nazwisko(nazwisko);
  listaStudentow[liczbaOsob].set_indeks(indeks);
  tabObecnosc[liczbaOsob] = false;

  liczbaOsob++;
}

void Interfejs::ustawObecnosc() {
  std::string nazwisko;
  bool obecnosc;

  std::cout << "Podaj nazwisko przy ktorym chcesz zmienic obecnosc: ";
  std::cin >> nazwisko;
  std::cout << "Podaj obecnosc tej osoby(0/1): ";
  std::cin >> obecnosc;

  for (int i = 0; i < liczbaOsob; i++) {
    if (listaStudentow[i].get_nazwisko() == nazwisko)
      tabObecnosc[i] = obecnosc;
  }
}

void Interfejs::edytujOsobe() {
  int nrNaLiscie = -1;
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

  for (int i = 0; i < liczbaOsob; i++) {
    if (listaStudentow[i].get_indeks() == indeks)
      nrNaLiscie = i;
  }

  if (nrNaLiscie == -1) {
    std::cout << "Nie znaleziono osoby" << std::endl;
    return;
  }

  listaStudentow[nrNaLiscie].set_indeks(nowyIndeks);
  listaStudentow[nrNaLiscie].set_imie(imie);
  listaStudentow[nrNaLiscie].set_nazwisko(nazwisko);
}

void Interfejs::usunOsobe() {
  std::string indeks;
  int nrNaLiscie = -1;

  std::cout << "Wybierz indeks ktory chcesz usunac: ";
  std::cin >> indeks;

  for (int i = 0; i < liczbaOsob; i++) {
    if (listaStudentow[i].get_indeks() == indeks)
      nrNaLiscie = i;
  }

  if (nrNaLiscie == -1) {
    std::cout << "Nie znaleziono osoby" << std::endl;
    return;
  }

  for (int i = nrNaLiscie; i < liczbaOsob - 1; i++) {
    listaStudentow[i] = listaStudentow[i + 1];
    tabObecnosc[i] = tabObecnosc[i + 1];
  }

  tabObecnosc[liczbaOsob - 1] = 0;
  liczbaOsob--;
}

void Interfejs::drukujListe() {
  std::cout << "nr Indeksu" << "\t" << "Imie" << "\t" << "Nazwisko" << "\t"
            << "Obecnosc" << std::endl;

  for (int i = 0; i < liczbaOsob; i++) {
    std::cout << listaStudentow[i].get_indeks() << "\t"
              << listaStudentow[i].get_imie() << "\t"
              << listaStudentow[i].get_nazwisko() << "\t" << tabObecnosc[i]
              << std::endl;
  }
}

int main() {
  Interfejs aplikacja;
  aplikacja.menu();

  return 0;
}
