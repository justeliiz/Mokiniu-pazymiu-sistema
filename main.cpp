#include <iostream>
#include <limits>
using namespace std;

int main() {
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
            case 1:
                cout << "Pasirinktas mokinio ivedimas.\n";
                break;

            case 2:
                cout << "Pasirinkta visu mokiniu perziura.\n";
                break;

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