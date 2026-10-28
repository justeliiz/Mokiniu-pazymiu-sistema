#include <iostream>
#include <iomanip>
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

            case 3: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokiniu sarasas tuscias.\n";
                    break;
                }

                cout << "Mokiniai:\n";
                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << "\n";
                }

                int mokinioNumeris = 0;

                while (true) {
                    cout << "Iveskite mokinio numeri nuo 1 iki " << mokiniuKiekis
                         << " (0 - grizti i meniu): ";

                    if (!(cin >> mokinioNumeris)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Klaida: reikia ivesti sveikaji skaiciu.\n";
                        continue;
                    }

                    if (mokinioNumeris == 0) {
                        break;
                    }

                    if (mokinioNumeris < 1 || mokinioNumeris > mokiniuKiekis) {
                        cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki "
                             << mokiniuKiekis << ".\n";
                        continue;
                    }

                    break;
                }

                if (mokinioNumeris == 0) {
                    break;
                }

                int mokinioIndeksas = mokinioNumeris - 1;
                cout << vardai[mokinioIndeksas] << ": ";

                if (pazymiuKiekiai[mokinioIndeksas] == 0) {
                    cout << "pazymiu neturi\n";
                } else {
                    for (int i = 0; i < pazymiuKiekiai[mokinioIndeksas]; i++) {
                        cout << pazymiai[mokinioIndeksas][i];

                        if (i < pazymiuKiekiai[mokinioIndeksas] - 1) {
                            cout << ", ";
                        }
                    }

                    cout << "\n";
                }

                break;
            }

            case 4: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokiniu sarasas tuscias.\n";
                    break;
                }

                cout << "Mokiniai:\n";
                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << "\n";
                }

                int mokinioNumeris = 0;

                while (true) {
                    cout << "Iveskite mokinio numeri nuo 1 iki " << mokiniuKiekis
                         << " (0 - grizti i meniu): ";

                    if (!(cin >> mokinioNumeris)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Klaida: reikia ivesti sveikaji skaiciu.\n";
                        continue;
                    }

                    if (mokinioNumeris == 0) {
                        break;
                    }

                    if (mokinioNumeris < 1 || mokinioNumeris > mokiniuKiekis) {
                        cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki "
                             << mokiniuKiekis << ".\n";
                        continue;
                    }

                    break;
                }

                if (mokinioNumeris == 0) {
                    break;
                }

                int mokinioIndeksas = mokinioNumeris - 1;

                if (pazymiuKiekiai[mokinioIndeksas] == 0) {
                    cout << "Mokinys " << vardai[mokinioIndeksas]
                         << " pazymiu neturi.\n";
                    break;
                }

                cout << vardai[mokinioIndeksas] << " pazymiai:\n";
                for (int i = 0; i < pazymiuKiekiai[mokinioIndeksas]; i++) {
                    cout << i + 1 << ". " << pazymiai[mokinioIndeksas][i] << "\n";
                }

                int pazymioNumeris = 0;

                while (true) {
                    cout << "Iveskite pazymio numeri nuo 1 iki "
                         << pazymiuKiekiai[mokinioIndeksas]
                         << " (0 - grizti i meniu): ";

                    if (!(cin >> pazymioNumeris)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Klaida: reikia ivesti sveikaji skaiciu.\n";
                        continue;
                    }

                    if (pazymioNumeris == 0) {
                        break;
                    }

                    if (pazymioNumeris < 1 ||
                        pazymioNumeris > pazymiuKiekiai[mokinioIndeksas]) {
                        cout << "Neteisingas pazymio numeris. Iveskite skaiciu nuo 1 iki "
                             << pazymiuKiekiai[mokinioIndeksas] << ".\n";
                        continue;
                    }

                    break;
                }

                if (pazymioNumeris == 0) {
                    break;
                }

                int naujasPazymys = 0;

                while (true) {
                    cout << "Iveskite nauja pazymi nuo 1 iki 10"
                         << " (0 - grizti i meniu): ";

                    if (!(cin >> naujasPazymys)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Klaida: reikia ivesti sveikaji skaiciu.\n";
                        continue;
                    }

                    if (naujasPazymys == 0) {
                        break;
                    }

                    if (naujasPazymys < 1 || naujasPazymys > 10) {
                        cout << "Neteisingas pazymys. Iveskite skaiciu nuo 1 iki 10.\n";
                        continue;
                    }

                    break;
                }

                if (naujasPazymys == 0) {
                    break;
                }

                pazymiai[mokinioIndeksas][pazymioNumeris - 1] = naujasPazymys;
                cout << "Pazymys sekmingai atnaujintas.\n";
                break;
            }

            case 5: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokiniu sarasas tuscias.\n";
                    break;
                }

                cout << "Mokiniai:\n";
                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << "\n";
                }

                int mokinioNumeris = 0;

                while (true) {
                    cout << "Iveskite mokinio numeri nuo 1 iki " << mokiniuKiekis
                         << " (0 - grizti i meniu): ";

                    if (!(cin >> mokinioNumeris)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Klaida: reikia ivesti sveikaji skaiciu.\n";
                        continue;
                    }

                    if (mokinioNumeris == 0) {
                        break;
                    }

                    if (mokinioNumeris < 1 || mokinioNumeris > mokiniuKiekis) {
                        cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki "
                             << mokiniuKiekis << ".\n";
                        continue;
                    }

                    break;
                }

                if (mokinioNumeris == 0) {
                    break;
                }

                int mokinioIndeksas = mokinioNumeris - 1;

                if (pazymiuKiekiai[mokinioIndeksas] == 0) {
                    cout << "Mokinys " << vardai[mokinioIndeksas]
                         << " pazymiu neturi.\n";
                    break;
                }

                int suma = 0;
                for (int i = 0; i < pazymiuKiekiai[mokinioIndeksas]; i++) {
                    suma += pazymiai[mokinioIndeksas][i];
                }

                double vidurkis = static_cast<double>(suma) /
                                  pazymiuKiekiai[mokinioIndeksas];

                cout << vardai[mokinioIndeksas] << " pazymiu vidurkis: "
                     << fixed << setprecision(2) << vidurkis << "\n";
                break;
            }

            case 6: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokiniu sarasas tuscias.\n";
                    break;
                }

                cout << "Mokiniai:\n";
                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << "\n";
                }

                int mokinioNumeris = 0;

                while (true) {
                    cout << "Iveskite salinamo mokinio numeri nuo 1 iki "
                         << mokiniuKiekis << " (0 - grizti i meniu): ";

                    if (!(cin >> mokinioNumeris)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Klaida: reikia ivesti sveikaji skaiciu.\n";
                        continue;
                    }

                    if (mokinioNumeris == 0) {
                        break;
                    }

                    if (mokinioNumeris < 1 || mokinioNumeris > mokiniuKiekis) {
                        cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki "
                             << mokiniuKiekis << ".\n";
                        continue;
                    }

                    break;
                }

                if (mokinioNumeris == 0) {
                    break;
                }

                int mokinioIndeksas = mokinioNumeris - 1;
                string pasalintoMokinioVardas = vardai[mokinioIndeksas];

                for (int i = mokinioIndeksas; i < mokiniuKiekis - 1; i++) {
                    vardai[i] = vardai[i + 1];
                    pazymiuKiekiai[i] = pazymiuKiekiai[i + 1];

                    for (int j = 0; j < MAX_PAZYMIAI; j++) {
                        pazymiai[i][j] = pazymiai[i + 1][j];
                    }
                }

                int paskutinisIndeksas = mokiniuKiekis - 1;
                vardai[paskutinisIndeksas] = "";
                pazymiuKiekiai[paskutinisIndeksas] = 0;

                for (int j = 0; j < MAX_PAZYMIAI; j++) {
                    pazymiai[paskutinisIndeksas][j] = 0;
                }

                mokiniuKiekis--;
                cout << "Mokinys " << pasalintoMokinioVardas
                     << " sekmingai pasalintas.\n";
                break;
            }

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
