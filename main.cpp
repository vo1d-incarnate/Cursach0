#include <iostream>  // Для ввода/вывода данных через консоль
#include <string>    // Для работы со строками
#include <Windows.h> // Для использования функций операционной системы (в данном случае для очистки экрана)
#include "Workload.h" // Заголовочный файл класса
#include "Position.h" // Заголовочный файл класса
#include "Subject.h" // Заголовочный файл класса

using namespace std;

void workloadMenu() {
    string filename = "workloads.txt";

    int choice;
    do {
        system("cls");
        cout << "1. Добавить запись\n";
        cout << "2. Просмотреть записи\n";
        cout << "3. Обновить запись\n";
        cout << "4. Удалить запись\n";
        cout << "0. Назад\n";
        cout << "Выберите опцию: ";
        cin >> choice;
        switch (choice) {
            case 1: Workload::addWorkload(filename); break;
            case 2: Workload::displayWorkloads(filename); break;
            case 3: {
                int id;
                cout << "Введите ID записи для обновления: ";
                cin >> id;
                Workload::updateWorkload(filename, id);
                break;
            }
            case 4: {
                int id;
                cout << "Введите ID записи для удаления: ";
                cin >> id;
                Workload::deleteWorkload(filename, id);
                break;
            }
            default: cout << "Неверный выбор!\n"; break;
        }
    } while (choice != 0);
}
void positionMenu() {
    string filename = "positions.txt";

    int choice;
    do {
        system("cls");
        cout << "1. Добавить запись\n";
        cout << "2. Просмотреть записи\n";
        cout << "3. Обновить запись\n";
        cout << "4. Удалить запись\n";
        cout << "0. Назад\n";
        cout << "Выберите опцию: ";
        cin >> choice;
        switch (choice) {
            case 1: Position::addPosition(filename); break;
            case 2: Position::displayPositions(filename); break;
            case 3: {
                int id;
                cout << "Введите ID записи для обновления: ";
                cin >> id;
                Position::updatePosition(filename, id);
                break;
            }
            case 4: {
                int id;
                cout << "Введите ID записи для удаления: ";
                cin >> id;
                Position::deletePosition(filename, id);
                break;
            }
            default: cout << "Неверный выбор!\n"; break;
        }
    } while (choice != 0);
}
void subjectMenu() {
    string filename = "subjects.txt";

    int choice;
    do {
        system("cls");
        cout << "1. Добавить запись\n";
        cout << "2. Просмотреть записи\n";
        cout << "3. Обновить запись\n";
        cout << "4. Удалить запись\n";
        cout << "0. Назад\n";
        cout << "Выберите опцию: ";
        cin >> choice;
        switch (choice) {
            case 1: Subject::addSubject(filename); break;
            case 2: Subject::displaySubjects(filename); break;
            case 3: {
                int id;
                cout << "Введите ID записи для обновления: ";
                cin >> id;
                Subject::updateSubject(filename, id);
                break;
            }
            case 4: {
                int id;
                cout << "Введите ID записи для удаления: ";
                cin >> id;
                Subject::deleteSubject(filename, id);
                break;
            }
            case 0: break;
            default: cout << "Неверный выбор!\n"; break;
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
        cout << "Меню:\n";
        cout << "1. Учебная нагрузка\n";
        cout << "2. Должности\n";
        cout << "3. Предметы\n";
        cout << "0. Выход\n";
        cout << "Выберите опцию: ";
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
            default: cout << "Неверный выбор!\n"; break;
        }
    }
    return 0;
}