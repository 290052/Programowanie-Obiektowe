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

std::string Osoba::get_imie() {
  return imie;
}

std::string Osoba::get_nazwisko() {
  return nazwisko;
}

std::string Osoba::get_indeks() {
  return nr_indeksu;
}

int main() {
  /*Osoba os;

  os.set_imie("Jan");
  os.set_nazwisko("Kowalski");
  os.set_indeks("123456");

  std::cout << "Imie: " << os.get_imie() << std::endl;
  std::cout << "Nazwisko: " << os.get_nazwisko() << std::endl;
  std::cout << "Nr indeksu: " << os.get_indeks() << std::endl;*/

  Osoba tabOsoba[10];

  tabOsoba[0].set_imie("Jan");
  tabOsoba[0].set_nazwisko("Kowalski");
  tabOsoba[0].set_indeks("123456");

  std::cout << "Imie: " << tabOsoba[0].get_imie() << std::endl;
  std::cout << "Nazwisko: " << tabOsoba[0].get_nazwisko() << std::endl;
  std::cout << "Nr indeksu: " << tabOsoba[0].get_indeks() << std::endl;

  return 0;
}
