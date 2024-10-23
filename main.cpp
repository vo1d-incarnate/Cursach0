#include <iostream>  // Äëÿ ââîäà/âûâîäà äàííûõ ÷åðåç êîíñîëü
#include <string>    // Äëÿ ðàáîòû ñî ñòðîêàìè
#include <Windows.h> // Äëÿ èñïîëüçîâàíèÿ ôóíêöèé îïåðàöèîííîé ñèñòåìû (â äàííîì ñëó÷àå äëÿ î÷èñòêè ýêðàíà)
#include <limits> // Äëÿ ðàáîòû ñ ãðàíèöàìè ÷èñëîâûõ òèïîâ
#include "Workload.h" // Çàãîëîâî÷íûé ôàéë êëàññà
#include "Position.h" // Çàãîëîâî÷íûé ôàéë êëàññà
#include "Subject.h" // Çàãîëîâî÷íûé ôàéë êëàññà

using namespace std;

void workloadMenu(string filename) {
    //string filename = "workloads.txt";

    int choice;
    do {
        system("cls");
        cout << "Ó÷åáíàÿ íàãðóçêà:\n";
        cout << "1. Äîáàâèòü çàïèñü\n";
        cout << "2. Ïðîñìîòðåòü çàïèñè\n";
        cout << "3. Îáíîâèòü çàïèñü\n";
        cout << "4. Óäàëèòü çàïèñü\n";
        cout << "5. Íàçàä\n";
        cout << "Âûáåðèòå îïöèþ: ";

        cin >> choice;
        if (cin.fail()) {
            cin.clear(); // Î÷èñòêà ñîñòîÿíèÿ îøèáêè
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Èãíîðèðóåò îñòàëüíóþ ÷àñòü âõîäíûõ äàííûõ
            system("cls");
            cout << "Íåâåðíûé âûáîð! Ïîæàëóéñòà, ââåäèòå öèôðó." << endl;
            system("pause");
            continue;
        }

        if (choice == 1) {
            Workload::addWorkload(filename);
        } else if (choice == 2) {
            Workload::displayWorkloads(filename);
        } else if (choice == 3) {
            int id;
            cout << "Ââåäèòå ID çàïèñè äëÿ îáíîâëåíèÿ: ";
            cin >> id;
            Workload::updateWorkload(filename, id);
        } else if (choice == 4) {
            int id;
            cout << "Ââåäèòå ID çàïèñè äëÿ óäàëåíèÿ: ";
            cin >> id;
            Workload::deleteWorkload(filename, id);
        } else if (choice == 5) {
            // Do nothing
        } else {
            cout << "Íåâåðíûé âûáîð!\n";
        }
    } while (choice != 5);
}
void positionMenu() {
    string filename = "positions.txt";

    int choice;
    do {
        system("cls");
        cout << "Äîëæíîñòè:\n";
        cout << "1. Äîáàâèòü çàïèñü\n";
        cout << "2. Ïðîñìîòðåòü çàïèñè\n";
        cout << "3. Îáíîâèòü çàïèñü\n";
        cout << "4. Óäàëèòü çàïèñü\n";
        cout << "5. Íàçàä\n";
        cout << "Âûáåðèòå îïöèþ: ";

        cin >> choice;
        if (cin.fail()) {
            cin.clear(); // Î÷èñòêà ñîñòîÿíèÿ îøèáêè
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Èãíîðèðóåò îñòàëüíóþ ÷àñòü âõîäíûõ äàííûõ
            system("cls");
            cout << "Íåâåðíûé âûáîð! Ïîæàëóéñòà, ââåäèòå öèôðó." << endl;
            system("pause");
            continue;
        }

        if (choice == 1) {
            Position::addPosition(filename);
        } else if (choice == 2) {
            Position::displayPositions(filename);
        } else if (choice == 3) {
            int id;
            cout << "Ââåäèòå ID çàïèñè äëÿ îáíîâëåíèÿ: ";
            cin >> id;
            Position::updatePosition(filename, id);
        } else if (choice == 4) {
            int id;
            cout << "Ââåäèòå ID çàïèñè äëÿ óäàëåíèÿ: ";
            cin >> id;
            Position::deletePosition(filename, id);
        } else if (choice == 5) {
            // Do nothing
        } else {
            cout << "Íåâåðíûé âûáîð!\n";
        }
    } while (choice != 5);
}
void subjectMenu() {
    string filename = "subjects.txt";

    int choice;
    do {
        system("cls");
        cout << "Ïðåäìåòû:\n";
        cout << "1. Äîáàâèòü çàïèñü\n";
        cout << "2. Ïðîñìîòðåòü çàïèñè\n";
        cout << "3. Îáíîâèòü çàïèñü\n";
        cout << "4. Óäàëèòü çàïèñü\n";
        cout << "5. Íàçàä\n";
        cout << "Âûáåðèòå îïöèþ: ";

        cin >> choice;
        if (cin.fail()) {
            cin.clear(); // Î÷èñòêà ñîñòîÿíèÿ îøèáêè
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Èãíîðèðóåò îñòàëüíóþ ÷àñòü âõîäíûõ äàííûõ
            system("cls");
            cout << "Íåâåðíûé âûáîð! Ïîæàëóéñòà, ââåäèòå öèôðó." << endl;
            system("pause");
            continue;
        }

        if (choice == 1) {
            Subject::addSubject(filename);
        } else if (choice == 2) {
            Subject::displaySubjects(filename);
        } else if (choice == 3) {
            int id;
            cout << "Ââåäèòå ID çàïèñè äëÿ îáíîâëåíèÿ: ";
            cin >> id;
            Subject::updateSubject(filename, id);
        } else if (choice == 4) {
            int id;
            cout << "Ââåäèòå ID çàïèñè äëÿ óäàëåíèÿ: ";
            cin >> id;
            Subject::deleteSubject(filename, id);
        } else if (choice == 5) {
            // Do nothing
        } else {
            cout << "Íåâåðíûé âûáîð!\n";
        }
    } while(choice != 5);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP (1251);
    setlocale(LC_ALL, "Russian");

    sting filename;
    cout << "введите имя файла";
    cin >> filename;


    int choice;
    while (true) {
        system("cls");
        cout << "Ìåíþ:\n";
        cout << "1. Ó÷åáíàÿ íàãðóçêà\n";
        cout << "2. Äîëæíîñòè\n";
        cout << "3. Ïðåäìåòû\n";
        cout << "4. Âûõîä\n";
        cout << "Âûáåðèòå îïöèþ: ";

        cin >> choice;
        if (cin.fail()) {
            cin.clear(); // Î÷èñòêà ñîñòîÿíèÿ îøèáêè
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Èãíîðèðóåò îñòàëüíóþ ÷àñòü âõîäíûõ äàííûõ
            system("cls");
            cout << "Íåâåðíûé âûáîð! Ïîæàëóéñòà, ââåäèòå öèôðó." << endl;
            system("pause");
            continue;
        }

        if (choice == 1) {
            workloadMenu(filename);
        } else if (choice == 2) {
            positionMenu();
        } else if (choice == 3) {
            subjectMenu();
        } else if (choice == 4) {
            return 0;
        } else {
            cout << "Íåâåðíûé âûáîð!\n";
        }

        /*switch (choice) {
            case 1: {
                workloadMenu();
                break;
            }
            case 2: {
                positionMenu();
                break;
            }
            case 3: {
                subjectMenu();
                break;
            }
            case 4: return 0;
            default: cout << "Íåâåðíûé âûáîð!\n"; break;
        }*/
    }
    return 0;
}
