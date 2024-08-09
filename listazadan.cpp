// zadanierekrutacyjne.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum Stan {
    Do_zrobienia,
    Zrobione,
    W_trakcie,
    Nieokreslono
};

struct Zadanie {
    string nazwa;
    string opis;
    Stan priorytet = Nieokreslono;
};


void wyswietlanie(vector<Zadanie>& taski);

vector<Zadanie> usuwanie(vector<Zadanie>& taski) {

    vector<Zadanie>::iterator it;
    if (taski.size() == 0) {
        cout << "Brak elementow na liscie. Kliknij enter, by wrocic do menu";
        
        return taski;
    }
    int n;
    wyswietlanie(taski);
    cout << "Wybierz numer zadania, ktore chcesz usunac : \n";
    cin >> n;
    if (n > taski.size() && n < 1) {
        cout << "Podano nieprawidlowy numer zadania. Po nacisnieciu przycisku powrocisz do menu\n";
        cin.ignore();
        cin.get();
        return taski;
    }
    it = taski.begin() + (n - 1);  //iterator to usuwania obiektow w wektorze
    taski.erase(it);
    return taski;
}


vector<Zadanie> dodawanie(vector<Zadanie>& taski) {
    Zadanie jakieszadanko;
    int n;
    cout << "Podaj nazwe zadania\n";
    cin.ignore();
    getline(cin, jakieszadanko.nazwa);
    cout << "Podaj opis\n";
    cin.ignore();
    getline(cin, jakieszadanko.opis);
    cout << "Podaj stan zadania\n1 - Do zrobienia\n2 - Zrobione\n3 - W trakcie";
    do {
        cin >> n;
        switch (n) {
        case 1:
            jakieszadanko.priorytet = Do_zrobienia;
            break;
        case 2:
            jakieszadanko.priorytet = Zrobione;
            break;
        case 3:
            jakieszadanko.priorytet = W_trakcie;
            break;

        }


    } while (n != 1 && n != 2 && n != 3);
    taski.insert(taski.begin(), jakieszadanko);
    system("cls");
    return taski;

}
void wyswietlanie(vector<Zadanie>& taski) {
    cout << "Lista zadan:";
    for (int i = 0; i < taski.size(); ++i) {

        cout << "\nNazwa: " << taski[i].nazwa;
        cout << "\nOpis: " << taski[i].opis;
        cout << "\nPriorytet: ";
        switch (taski[i].priorytet) {
        case 1:
            cout << "Do zrobienia";
            break;
        case 2:
            cout << "Zrobione";
            break;
        case 3:
            cout << "W trakcie";
            break;
        default:
            cout << "Nieokreslony";
            break;
        }
    }

    // cout << "\nNacisnij enter, by wrocic do menu";
    cin.ignore();
    cin.get();
    system("cls");
};



void menu(vector<Zadanie>& taski) {

    int wybor = 0;
    while (wybor != 4) {
        cout << "Witaj w liscie zarzadzania zadaniami! Wybierz jedna z ponizszych opcji\n";
        cout << "1. Wyswietlenie listy zadan.\n2. Dodanie zadania\n 3. Usuniecie zadania\n";
        cout << "4. Opusc program\n";
        cin >> wybor;
        system("cls");
        switch (wybor) {
        case 1:
            wyswietlanie(taski);
            break;
        case 2:
            dodawanie(taski);
            break;
        case 3:
            usuwanie(taski);
        }

    }

};


int main()
{

    vector<Zadanie> ListaZadan;
    menu(ListaZadan);
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
