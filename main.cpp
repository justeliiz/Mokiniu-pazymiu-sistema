#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
    const int MAX_MOKINIAI = 100;
    const int MAX_PAZYMIAI = 10;

    string vardai[MAX_MOKINIAI];
    int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI] = {};
    int pazymiuKiekiai[MAX_MOKINIAI] = {};
    int mokiniuKiekis = 0;
    int veiksmas = 0;

    do {
        cout << "\n--- MOKINIU PAZYMIU SISTEMA ---\n";
        cout << "1. Ivesti mokini ir jo pazymius\n";
        cout << "2. Perziureti visu mokiniu pazymius\n";
        cout << "3. Perziureti konkretaus mokinio pazymius\n";
        cout << "4. Atnaujinti pazymi\n";
        cout << "5. Apskaiciuoti mokinio vidurki\n";
        cout << "6. Pasalinti mokini\n";
        cout << "7. Iseiti\n";
        cout << "Pasirinkite veiksma: ";

        if (!(cin >> veiksmas)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Klaida: reikia ivesti sveikaji skaiciu.\n";
            continue;
        }

        switch (veiksmas) {
            case 1: {
                if (mokiniuKiekis >= MAX_MOKINIAI) {
                    cout << "Pasiektas 100 mokiniu limitas.\n";
                    break;
                }

                cout << "Iveskite mokinio varda: ";
                cin >> vardai[mokiniuKiekis];

                int kiekis = 0;

                while (true) {
                    cout << "Kiek pazymiu norite ivesti (nuo 0 iki 10): ";

                    if (!(cin >> kiekis)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Klaida: reikia ivesti sveikaji skaiciu.\n";
                        continue;
                    }

                    if (kiekis < 0 || kiekis > MAX_PAZYMIAI) {
                        cout << "Neteisingas kiekis. Iveskite skaiciu nuo 0 iki 10.\n";
                        continue;
                    }

                    break;
                }

                for (int i = 0; i < kiekis; i++) {
                    int pazymys = 0;

                    while (true) {
                        cout << "Iveskite " << i + 1 << " pazymi (nuo 1 iki 10): ";

                        if (!(cin >> pazymys)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Klaida: reikia ivesti sveikaji skaiciu.\n";
                            continue;
                        }

                        if (pazymys < 1 || pazymys > 10) {
                            cout << "Neteisingas pazymys. Iveskite skaiciu nuo 1 iki 10.\n";
                            continue;
                        }

                        break;
                    }

                    pazymiai[mokiniuKiekis][i] = pazymys;
                }

                pazymiuKiekiai[mokiniuKiekis] = kiekis;
                mokiniuKiekis++;

                cout << "Mokinys sekmingai pridetas.\n";
                break;
            }

            case 2: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokiniu sarasas tuscias.\n";
                    break;
                }

                cout << "\n--- MOKINIU PAZYMIAI ---\n";

                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << ": ";

                    if (pazymiuKiekiai[i] == 0) {
                        cout << "pazymiu neturi";
                    } else {
                        for (int j = 0; j < pazymiuKiekiai[i]; j++) {
                            cout << pazymiai[i][j];

                            if (j < pazymiuKiekiai[i] - 1) {
                                cout << ", ";
                            }
                        }
                    }

                    cout << "\n";
                }

                break;
            }

            case 3:
                cout << "Pasirinkta vieno mokinio perziura.\n";
                break;

            case 4:
                cout << "Pasirinktas pazymio atnaujinimas.\n";
                break;

            case 5:
                cout << "Pasirinktas vidurkio skaiciavimas.\n";
                break;

            case 6:
                cout << "Pasirinktas mokinio pasalinimas.\n";
                break;

            case 7:
                cout << "Programa baigiama.\n";
                break;

            default:
                cout << "Neteisingas pasirinkimas. Iveskite nuo 1 iki 7.\n";
                break;
        }

    } while (veiksmas != 7);

    return 0;
}
