#include <iostream>
#include <string>
#include <cstdlib>

void dodajOsobe(std::string *tab, std::string nazwisko, int &wielkosc) {
  tab[wielkosc] = nazwisko;
  wielkosc++;
}

void ustawObecnosc(std::string *tabNazwisko, bool *tabObecnosc, std::string nazwisko, bool obecnosc) {
  for (int i = 0; i < 10; i++) {
    if (tabNazwisko[i] == nazwisko) tabObecnosc[i] = obecnosc; 
  }
}

void drukujListe(std::string *tabNazwisko, bool *tabObecnosc) {
  std::cout << "Nazwisko" << "\t" << "Obecnosc" << std::endl;
  
  for (int i = 0; i < 10; i++) {
    std::cout << tabNazwisko[i] << "\t" << tabObecnosc[i] << std::endl;
  }
}

int main() {
  std::string tabNazwisko[10];
  bool tabObecnosc[10];
  int wielkosc = 0;

  for (int i = 0; i < 10; i++) {
    tabNazwisko[i] = "";
    tabObecnosc[i] = 0;
  }

  int wybor = 0;

  while ( wybor != 4) {
    std::cout << "1. Dodaj osobe" << std::endl;
    std::cout << "2. Ustaw obecnosc" << std::endl;
    std::cout << "3. Drukuj liste" << std::endl;
    std::cout << "4. Koniec" << std::endl;
    std::cin >> wybor;

    system("clear");

    if (wybor == 1) {
      std::string nazwisko;

      std::cout << "Podaj nowe nazwisko: ";
      std::cin >> nazwisko;

      dodajOsobe(tabNazwisko, nazwisko, wielkosc);
    }
    if (wybor == 2) {
      std::string nazwisko;
      bool obecnosc;

      std::cout << "Podaj nazwisko przy ktorym chcesz zmienic obecnosc: ";
      std::cin >> nazwisko;
      std::cout << "Podaj obecnosc tej osoby(0/1): ";
      std::cin >> obecnosc;

      ustawObecnosc(tabNazwisko, tabObecnosc, nazwisko, obecnosc);
    }
    if (wybor == 3) drukujListe(tabNazwisko, tabObecnosc);
  }

  return 0;
}