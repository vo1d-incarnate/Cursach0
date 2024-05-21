#include <iostream>  // ��� �����/������ ������ ����� �������
#include <string>    // ��� ������ �� ��������
#include <Windows.h> // ��� ������������� ������� ������������ ������� (� ������ ������ ��� ������� ������)
#include <limits> // ��� ������ � ��������� �������� �����
#include "Workload.h" // ������������ ���� ������
#include "Position.h" // ������������ ���� ������
#include "Subject.h" // ������������ ���� ������

using namespace std;

void workloadMenu() {
    string filename = "workloads.txt";

    int choice;
    do {
        system("cls");
        cout << "������� ��������:\n";
        cout << "1. �������� ������\n";
        cout << "2. ����������� ������\n";
        cout << "3. �������� ������\n";
        cout << "4. ������� ������\n";
        cout << "5. �����\n";
        cout << "�������� �����: ";

        cin >> choice;
        if (cin.fail()) {
            cin.clear(); // ������� ��������� ������
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���������� ��������� ����� ������� ������
            system("cls");
            cout << "�������� �����! ����������, ������� �����." << endl;
            system("pause");
            continue;
        }

        if (choice == 1) {
            Workload::addWorkload(filename);
        } else if (choice == 2) {
            Workload::displayWorkloads(filename);
        } else if (choice == 3) {
            int id;
            cout << "������� ID ������ ��� ����������: ";
            cin >> id;
            Workload::updateWorkload(filename, id);
        } else if (choice == 4) {
            int id;
            cout << "������� ID ������ ��� ��������: ";
            cin >> id;
            Workload::deleteWorkload(filename, id);
        } else if (choice == 5) {
            // Do nothing
        } else {
            cout << "�������� �����!\n";
        }
    } while (choice != 5);
}
void positionMenu() {
    string filename = "positions.txt";

    int choice;
    do {
        system("cls");
        cout << "���������:\n";
        cout << "1. �������� ������\n";
        cout << "2. ����������� ������\n";
        cout << "3. �������� ������\n";
        cout << "4. ������� ������\n";
        cout << "5. �����\n";
        cout << "�������� �����: ";

        cin >> choice;
        if (cin.fail()) {
            cin.clear(); // ������� ��������� ������
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���������� ��������� ����� ������� ������
            system("cls");
            cout << "�������� �����! ����������, ������� �����." << endl;
            system("pause");
            continue;
        }

        if (choice == 1) {
            Position::addPosition(filename);
        } else if (choice == 2) {
            Position::displayPositions(filename);
        } else if (choice == 3) {
            int id;
            cout << "������� ID ������ ��� ����������: ";
            cin >> id;
            Position::updatePosition(filename, id);
        } else if (choice == 4) {
            int id;
            cout << "������� ID ������ ��� ��������: ";
            cin >> id;
            Position::deletePosition(filename, id);
        } else if (choice == 5) {
            // Do nothing
        } else {
            cout << "�������� �����!\n";
        }
    } while (choice != 5);
}
void subjectMenu() {
    string filename = "subjects.txt";

    int choice;
    do {
        system("cls");
        cout << "��������:\n";
        cout << "1. �������� ������\n";
        cout << "2. ����������� ������\n";
        cout << "3. �������� ������\n";
        cout << "4. ������� ������\n";
        cout << "5. �����\n";
        cout << "�������� �����: ";

        cin >> choice;
        if (cin.fail()) {
            cin.clear(); // ������� ��������� ������
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���������� ��������� ����� ������� ������
            system("cls");
            cout << "�������� �����! ����������, ������� �����." << endl;
            system("pause");
            continue;
        }

        if (choice == 1) {
            Subject::addSubject(filename);
        } else if (choice == 2) {
            Subject::displaySubjects(filename);
        } else if (choice == 3) {
            int id;
            cout << "������� ID ������ ��� ����������: ";
            cin >> id;
            Subject::updateSubject(filename, id);
        } else if (choice == 4) {
            int id;
            cout << "������� ID ������ ��� ��������: ";
            cin >> id;
            Subject::deleteSubject(filename, id);
        } else if (choice == 5) {
            // Do nothing
        } else {
            cout << "�������� �����!\n";
        }
    } while(choice != 5);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP (1251);
    setlocale(LC_ALL, "Russian");

    int choice;
    while (true) {
        system("cls");
        cout << "����:\n";
        cout << "1. ������� ��������\n";
        cout << "2. ���������\n";
        cout << "3. ��������\n";
        cout << "4. �����\n";
        cout << "�������� �����: ";

        cin >> choice;
        if (cin.fail()) {
            cin.clear(); // ������� ��������� ������
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���������� ��������� ����� ������� ������
            system("cls");
            cout << "�������� �����! ����������, ������� �����." << endl;
            system("pause");
            continue;
        }

        if (choice == 1) {
            workloadMenu();
        } else if (choice == 2) {
            positionMenu();
        } else if (choice == 3) {
            subjectMenu();
        } else if (choice == 4) {
            return 0;
        } else {
            cout << "�������� �����!\n";
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
            default: cout << "�������� �����!\n"; break;
        }*/
    }
    return 0;
}