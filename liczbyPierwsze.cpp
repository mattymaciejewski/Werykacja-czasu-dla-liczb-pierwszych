#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
using namespace std;
using namespace chrono;

void naiwnaPetla1 (int n) {

  int ile = 0; 

  for(int i = 2; i <= n; i++) {

    int dzielnik = 1;

    for(int j = 2; j <= i; j++) {

      if(i % j == 0) {

        dzielnik++;

      }

      if(dzielnik > 2) {

        break;

      }

      }

    if(dzielnik == 2) {

    ile++;

    }

    }

  cout << "Ilosc liczb pierwszych dla n = " << n << " wynosi " << ile << endl;

}

void naiwnaPetla2 (int n) {

  int ile = 1; // 2 to liczba pierwsza

  for(int i = 3; i <= n; i++) {

    if(i % 2 == 0) {

      continue;

    }

    int dzielnik = 1;

    for(int j = 3; j <= i; j+=2) {

      if(i % j == 0) {

        dzielnik++;

      }

      if(dzielnik > 2) {

        break;

      }

      }

    if(dzielnik == 2) {

    ile++;

    }

    }

  cout << "Ilosc liczb pierwszych dla n = " << n << " wynosi " << ile << endl;

}

void naiwnaPetla3 (int n) {

  int ile = 1; // poniewaz 2 to liczba pierwsza, a 2 eliminuje continue

  for(int i = 2; i <= n; i++) {

    if(i % 2 == 0) {

      continue;

    }

    int dzielnik = 2; // dzielnik = 2, poniewaz 2 zostanie pochloniete przez continue

    for(int j = 2; j <= sqrt(i); j++) {

      if(i % j == 0) {

        dzielnik++;

      }

      if(dzielnik > 2) {

        break;

      }

    }

    if(dzielnik == 2) {

      ile++;

    }

  }

  cout << "Ilosc liczb pierwszych dla n = " << n << " wynosi " << ile << endl;

}

void eratostenes(int n) {

  vector <bool> pierwsze (n + 1, true);
  pierwsze [0] = 0;
  pierwsze [1] = 0;

  int ile = 0;

  for(int i = 2; i*i <= n; i++) {

    if(pierwsze[i]) {

      for(int j = i * i; j <= n; j+=i) {

        pierwsze[j] = false;

      }
    }

  }

  for(int i = 2; i <= n; i++) {

    if(pierwsze[i]) {

      ile++;

    }

  }

  cout << "Ilosc liczb pierwszych dla n = " << n << " wynosi " << ile << endl;

}

int main() {

  vector <int> wartosci = {1000, 10000, 100000, 1000000};

  for(int i = 0; i < wartosci.size(); i++) {

    int n = wartosci[i];

    for(int j = 1; j <= 4; j++) {

      auto start = high_resolution_clock::now();
      
      switch(j) {

        case 1:
        naiwnaPetla1(n);
        break;
        
        case 2:
        naiwnaPetla2(n);
        break;

        case 3:
        naiwnaPetla3(n);
        break;

        case 4:
        eratostenes(n);
        break;

      }

      auto stop = high_resolution_clock::now();
      auto czas = duration_cast<microseconds>(stop - start);

      cout << "Czas wykonania programu dla n = " << n << " wynosi " << czas.count() << " us." << endl;
      cout << "  ";
    }
    
  }
  
}
