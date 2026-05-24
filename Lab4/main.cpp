#include <cstdlib>
#include <iostream>
#include <string>

class Osoba {
private:
  std::string imie;
  std::string nazwisko;

public:
  Osoba(std::string, std::string);
  virtual ~Osoba() {}

  void set_imie(std::string);
  void set_nazwisko(std::string);
  std::string get_imie();
  std::string get_nazwisko();

  virtual std::string get_indeks() { return ""; }
  virtual void set_indeks(std::string){};
  virtual std::string przedstawSie() = 0;
};

Osoba::Osoba(std::string _imie, std::string _nazwisko) {
  imie = _imie;
  nazwisko = _nazwisko;
}

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

std::string Osoba::get_imie() { return imie; }
std::string Osoba::get_nazwisko() { return nazwisko; }

class Student : public Osoba {
private:
  std::string nr_indeksu;

public:
  Student(std::string, std::string, std::string);

  void set_indeks(std::string _indeks);
  std::string get_indeks();
  std::string przedstawSie() override;
};

Student::Student(std::string _imie, std::string _nazwisko, std::string _indeks)
    : Osoba(_imie, _nazwisko) {
  nr_indeksu = _indeks;
}

void Student::set_indeks(std::string _nr_indeksu) {
  // if (_nr_indeksu.lenght = 6) {
  nr_indeksu = _nr_indeksu;
  //}
}

std::string Student::get_indeks() { return nr_indeksu; }
std::string Student::przedstawSie() { return "Jestem Studentem"; };

class StudentZaoczny : public Student {
public:
  StudentZaoczny(std::string, std::string, std::string);
  std::string przedstawSie() override { return "Jestem Studentem zaocznym"; };
};

StudentZaoczny::StudentZaoczny(std::string _imie, std::string _nazwisko,
                               std::string _indeks)
    : Student(_imie, _nazwisko, _indeks) {}

class Pracownik : public Osoba {
public:
  Pracownik(std::string, std::string);
  std::string przedstawSie() override { return "Jestem Pracownikiem"; };
};

Pracownik::Pracownik(std::string _imie, std::string _nazwisko)
    : Osoba(_imie, _nazwisko) {}

class Interfejs {
private:
  Osoba **listaOsob;
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
  listaOsob = new Osoba *[10];
  tabObecnosc = new bool[10]();
  liczbaOsob = 0;
}

Interfejs::~Interfejs() {
  for (int i = 0; i < liczbaOsob; i++) {
    delete listaOsob[i];
  }

  delete[] listaOsob;
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
  int rola;

  std::cout << "Kim ma być nowa osoba (1 - Pracownik, 2 - Student, 3 - Student "
               "zaoczny): ";
  std::cin >> rola;
  std::cout << "Podaj nowe imie: ";
  std::cin >> imie;
  std::cout << "Podaj nowe nazwisko: ";
  std::cin >> nazwisko;

  if (rola == 1) {
    listaOsob[liczbaOsob] = new Pracownik(imie, nazwisko);
  }

  if (rola == 2) {
    std::cout << "Podaj nowy indeks: ";
    std::cin >> indeks;
    listaOsob[liczbaOsob] = new Student(imie, nazwisko, indeks);
  }

  if (rola == 3) {
    std::cout << "Podaj nowy indeks: ";
    std::cin >> indeks;
    listaOsob[liczbaOsob] = new StudentZaoczny(imie, nazwisko, indeks);
  }

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
    if (listaOsob[i]->get_nazwisko() == nazwisko)
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
    if (listaOsob[i]->get_indeks() == indeks)
      nrNaLiscie = i;
  }

  if (nrNaLiscie == -1) {
    std::cout << "Nie znaleziono osoby" << std::endl;
    return;
  }

  listaOsob[nrNaLiscie]->set_indeks(nowyIndeks);
  listaOsob[nrNaLiscie]->set_imie(imie);
  listaOsob[nrNaLiscie]->set_nazwisko(nazwisko);
}

void Interfejs::usunOsobe() {
  std::string indeks;
  int nrNaLiscie = -1;

  std::cout << "Wybierz indeks ktory chcesz usunac: ";
  std::cin >> indeks;

  for (int i = 0; i < liczbaOsob; i++) {
    if (listaOsob[i]->get_indeks() == indeks)
      nrNaLiscie = i;
  }

  if (nrNaLiscie == -1) {
    std::cout << "Nie znaleziono osoby" << std::endl;
    return;
  }

  delete listaOsob[nrNaLiscie];

  for (int i = nrNaLiscie; i < liczbaOsob - 1; i++) {
    listaOsob[i] = listaOsob[i + 1];
    tabObecnosc[i] = tabObecnosc[i + 1];
  }

  tabObecnosc[liczbaOsob - 1] = 0;
  liczbaOsob--;
}

void Interfejs::drukujListe() {
  std::cout << "nr Indeksu\t" << "Imie\t" << "Nazwisko\t"
            << "Obecnosc\t" << "Rola" << std::endl;

  for (int i = 0; i < liczbaOsob; i++) {
    std::cout << listaOsob[i]->get_indeks() << "\t" << listaOsob[i]->get_imie()
              << "\t" << listaOsob[i]->get_nazwisko() << "\t" << tabObecnosc[i]
              << "\t" << listaOsob[i]->przedstawSie() << std::endl;
  }
}

int main() {
  Interfejs aplikacja;
  aplikacja.menu();

  return 0;
}
