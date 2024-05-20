#include <iostream>  // ��� �����/������ ������ ����� �������
#include <string>    // ��� ������ �� ��������
#include <Windows.h> // ��� ������������� ������� ������������ ������� (� ������ ������ ��� ������� ������)
#include "Workload.h" // ������������ ���� ������
#include "Position.h" // ������������ ���� ������
#include "Subject.h" // ������������ ���� ������

using namespace std;

void workloadMenu() {
    string filename = "workloads.txt";

    int choice;
    do {
        system("cls");
        cout << "1. �������� ������\n";
        cout << "2. ����������� ������\n";
        cout << "3. �������� ������\n";
        cout << "4. ������� ������\n";
        cout << "0. �����\n";
        cout << "�������� �����: ";
        cin >> choice;
        switch (choice) {
            case 1: Workload::addWorkload(filename); break;
            case 2: Workload::displayWorkloads(filename); break;
            case 3: {
                int id;
                cout << "������� ID ������ ��� ����������: ";
                cin >> id;
                Workload::updateWorkload(filename, id);
                break;
            }
            case 4: {
                int id;
                cout << "������� ID ������ ��� ��������: ";
                cin >> id;
                Workload::deleteWorkload(filename, id);
                break;
            }
            default: cout << "�������� �����!\n"; break;
        }
    } while (choice != 0);
}
void positionMenu() {
    string filename = "positions.txt";

    int choice;
    do {
        system("cls");
        cout << "1. �������� ������\n";
        cout << "2. ����������� ������\n";
        cout << "3. �������� ������\n";
        cout << "4. ������� ������\n";
        cout << "0. �����\n";
        cout << "�������� �����: ";
        cin >> choice;
        switch (choice) {
            case 1: Position::addPosition(filename); break;
            case 2: Position::displayPositions(filename); break;
            case 3: {
                int id;
                cout << "������� ID ������ ��� ����������: ";
                cin >> id;
                Position::updatePosition(filename, id);
                break;
            }
            case 4: {
                int id;
                cout << "������� ID ������ ��� ��������: ";
                cin >> id;
                Position::deletePosition(filename, id);
                break;
            }
            default: cout << "�������� �����!\n"; break;
        }
    } while (choice != 0);
}
void subjectMenu() {
    string filename = "subjects.txt";

    int choice;
    do {
        system("cls");
        cout << "1. �������� ������\n";
        cout << "2. ����������� ������\n";
        cout << "3. �������� ������\n";
        cout << "4. ������� ������\n";
        cout << "0. �����\n";
        cout << "�������� �����: ";
        cin >> choice;
        switch (choice) {
            case 1: Subject::addSubject(filename); break;
            case 2: Subject::displaySubjects(filename); break;
            case 3: {
                int id;
                cout << "������� ID ������ ��� ����������: ";
                cin >> id;
                Subject::updateSubject(filename, id);
                break;
            }
            case 4: {
                int id;
                cout << "������� ID ������ ��� ��������: ";
                cin >> id;
                Subject::deleteSubject(filename, id);
                break;
            }
            case 0: break;
            default: cout << "�������� �����!\n"; break;
        }
    } while(choice != 0);
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
        cout << "0. �����\n";
        cout << "�������� �����: ";
        cin >> choice;

        switch (choice) {
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
            case 0: return 0;
            default: cout << "�������� �����!\n"; break;
        }
    }
    return 0;
}