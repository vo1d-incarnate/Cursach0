#include <iostream>  // Для ввода/вывода данных через консоль
#include <string>    // Для работы со строками
#include <Windows.h> // Для использования функций операционной системы (в данном случае для очистки экрана)
#include <limits> // Для работы с границами числовых типов
#include "Workload.h" // Заголовочный файл класса
#include "Position.h" // Заголовочный файл класса
#include "Subject.h" // Заголовочный файл класса

using namespace std;

void workloadMenu() {
    string filename = "workloads.txt";

    int choice;
    do {
        system("cls");
        cout << "Учебная нагрузка:\n";
        cout << "1. Добавить запись\n";
        cout << "2. Просмотреть записи\n";
        cout << "3. Обновить запись\n";
        cout << "4. Удалить запись\n";
        cout << "5. Назад\n";
        cout << "Выберите опцию: ";

        cin >> choice;
        if (cin.fail()) {
            cin.clear(); // Очистка состояния ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорирует остальную часть входных данных
            system("cls");
            cout << "Неверный выбор! Пожалуйста, введите цифру." << endl;
            system("pause");
            continue;
        }

        if (choice == 1) {
            Workload::addWorkload(filename);
        } else if (choice == 2) {
            Workload::displayWorkloads(filename);
        } else if (choice == 3) {
            int id;
            cout << "Введите ID записи для обновления: ";
            cin >> id;
            Workload::updateWorkload(filename, id);
        } else if (choice == 4) {
            int id;
            cout << "Введите ID записи для удаления: ";
            cin >> id;
            Workload::deleteWorkload(filename, id);
        } else if (choice == 5) {
            // Do nothing
        } else {
            cout << "Неверный выбор!\n";
        }
    } while (choice != 5);
}
void positionMenu() {
    string filename = "positions.txt";

    int choice;
    do {
        system("cls");
        cout << "Должности:\n";
        cout << "1. Добавить запись\n";
        cout << "2. Просмотреть записи\n";
        cout << "3. Обновить запись\n";
        cout << "4. Удалить запись\n";
        cout << "5. Назад\n";
        cout << "Выберите опцию: ";

        cin >> choice;
        if (cin.fail()) {
            cin.clear(); // Очистка состояния ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорирует остальную часть входных данных
            system("cls");
            cout << "Неверный выбор! Пожалуйста, введите цифру." << endl;
            system("pause");
            continue;
        }

        if (choice == 1) {
            Position::addPosition(filename);
        } else if (choice == 2) {
            Position::displayPositions(filename);
        } else if (choice == 3) {
            int id;
            cout << "Введите ID записи для обновления: ";
            cin >> id;
            Position::updatePosition(filename, id);
        } else if (choice == 4) {
            int id;
            cout << "Введите ID записи для удаления: ";
            cin >> id;
            Position::deletePosition(filename, id);
        } else if (choice == 5) {
            // Do nothing
        } else {
            cout << "Неверный выбор!\n";
        }
    } while (choice != 5);
}
void subjectMenu() {
    string filename = "subjects.txt";

    int choice;
    do {
        system("cls");
        cout << "Предметы:\n";
        cout << "1. Добавить запись\n";
        cout << "2. Просмотреть записи\n";
        cout << "3. Обновить запись\n";
        cout << "4. Удалить запись\n";
        cout << "5. Назад\n";
        cout << "Выберите опцию: ";

        cin >> choice;
        if (cin.fail()) {
            cin.clear(); // Очистка состояния ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорирует остальную часть входных данных
            system("cls");
            cout << "Неверный выбор! Пожалуйста, введите цифру." << endl;
            system("pause");
            continue;
        }

        if (choice == 1) {
            Subject::addSubject(filename);
        } else if (choice == 2) {
            Subject::displaySubjects(filename);
        } else if (choice == 3) {
            int id;
            cout << "Введите ID записи для обновления: ";
            cin >> id;
            Subject::updateSubject(filename, id);
        } else if (choice == 4) {
            int id;
            cout << "Введите ID записи для удаления: ";
            cin >> id;
            Subject::deleteSubject(filename, id);
        } else if (choice == 5) {
            // Do nothing
        } else {
            cout << "Неверный выбор!\n";
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
        cout << "Меню:\n";
        cout << "1. Учебная нагрузка\n";
        cout << "2. Должности\n";
        cout << "3. Предметы\n";
        cout << "4. Выход\n";
        cout << "Выберите опцию: ";

        cin >> choice;
        if (cin.fail()) {
            cin.clear(); // Очистка состояния ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорирует остальную часть входных данных
            system("cls");
            cout << "Неверный выбор! Пожалуйста, введите цифру." << endl;
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
            cout << "Неверный выбор!\n";
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
            default: cout << "Неверный выбор!\n"; break;
        }*/
    }
    return 0;
}