#include <iostream>
#include <string>
#include <cstdlib>

void dodajOsobe(std::string *tabImie, std::string *tabNazwisko, std::string imie, std::string nazwisko) {
  int wielkosc = sizeof(tabImie);
  tabImie[wielkosc] = imie;
  tabNazwisko[wielkosc] = nazwisko;
}

void ustawObecnosc(std::string *tabNazwisko, bool *tabObecnosc, std::string nazwisko, bool obecnosc) {
  for (int i = 0; i < 10; i++) {
    if (tabNazwisko[i] == nazwisko) tabObecnosc[i] = obecnosc; 
  }
}

void edytujOsobe(int *tabIndeks, std::string *tabImie, std::string *tabNazwisko) {
  int indeks;
  int nrNaLiscie;
  int nowyIndeks;
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
    if (tabIndeks[i] == indeks) nrNaLiscie = i;
  }

  tabIndeks[nrNaLiscie] = nowyIndeks;
  tabImie[nrNaLiscie] = imie;
  tabNazwisko[nrNaLiscie] = nazwisko;
}

void usunOsobe(int *tabIndeks, std::string *tabImie, std::string *tabNazwisko, bool *tabObecnosc) {
  int indeks;
  int nrNaLiscie = 0;

  std::cout << "Wybierz indeks ktory chcesz usunac: ";
  std::cin >> indeks;

  for (int i = 0; i < 10; i++) {
    if (tabIndeks[i] == indeks) nrNaLiscie = i;
  }

  for (int i = nrNaLiscie; i < 9; i++) {
    tabIndeks[i] = tabIndeks[i + 1];
    tabImie[i] = tabImie[i + 1];
    tabNazwisko[i] = tabNazwisko[i + 1];
    tabObecnosc[i] = tabObecnosc[i + 1];
  }

  tabIndeks[9] = 0;
  tabImie[9] = "";
  tabNazwisko[9] = "";
  tabObecnosc[9] = 0;
}

void drukujListe(int *tabIndex, std::string *tabImie, std::string *tabNazwisko, bool *tabObecnosc) {
  std::cout << "nr Indeksu" << "\t" << "Imie" << "\t" << "Nazwisko" << "\t" << "Obecnosc" << std::endl;
  
  for (int i = 0; i < 10; i++) {
    std::cout << tabIndex[i] << "\t" << tabImie[i] << "\t" << tabNazwisko[i] << "\t" << tabObecnosc[i] << std::endl;
  }
}

int main() {
  // Tworzenie tablic oraz przypisanie danych testowych
  int tabIndeks[10];
  std::string tabImie[10] = {"Jan", "Grzegorz", "Krzysztof", "Paweł", "Tomasz", "Piotr", "Aleksandra", "Julia", "Franciszek", "Marta"};
  std::string tabNazwisko[10] = {"Nowak", "Brzęczyszczykiewicz", "Kowalski", "Wajda", "Kuliński", "Strzelecki", "Kowalczyk", "Gajowicz", "Góra", "Różycka"};
  bool tabObecnosc[10] = {1, 1, 1, 0, 1, 1, 0, 0, 1, 1};

  // Dane testowe
  for (int i = 0; i < 10; i++) {
    tabIndeks[i] = i + 1;
    //tabImie[i] = "";
    //tabNazwisko[i] = "";
    //tabObecnosc[i] = 0;
  }

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

      std::cout << "Podaj nowe imie: ";
      std::cin >> imie;
      std::cout << "Podaj nowe nazwisko: ";
      std::cin >> nazwisko;

      dodajOsobe(tabImie, tabNazwisko, imie, nazwisko);
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

    if (wybor == 3) drukujListe(tabIndeks, tabImie, tabNazwisko, tabObecnosc);

    if (wybor == 4) edytujOsobe(tabIndeks, tabImie, tabNazwisko);

    if (wybor == 5) usunOsobe(tabIndeks, tabImie, tabNazwisko, tabObecnosc);
  }

  return 0;
}