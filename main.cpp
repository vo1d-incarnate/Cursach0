#include <iostream>  // Для ввода/вывода данных через консоль
#include <fstream>   // Для работы с файлами
#include <vector>    // Для использования векторов
#include <sstream>   // Для работы с потоками строк
#include <string>    // Для работы со строками
#include <algorithm> // Для использования алгоритмов STL
#include <iomanip>   // Для форматирования вывода
#include <Windows.h> // Для использования функций операционной системы (в данном случае для очистки экрана)
#include "Workload.h" // Заголовочный файл класса
#include "Position.h" // Заголовочный файл класса
#include "Subject.h" // Заголовочный файл класса

using namespace std;
/*
// Структура для представления учебной нагрузки
struct Workload {
    int id;
    string fio;
    string phone;
    int experience;
    string degree;
    string title;
    string department;
    string position;
    string subject;
    int workload;
    int publications;
};

// Структура для представления должностей
struct Position {
    int id;
    string name;
    string department;
    int quantity;
};

// Структура для представления предметов
struct Subject {
    int id;
    string name;
    int hours;
};

// Функции для работы с учебной нагрузкой
vector<Workload> readWorkloads(const string& filename);
void writeWorkloads(const string& filename, const vector<Workload>& workloads);
void addWorkload(const string& filename);
void displayWorkloads(const string& filename);
void updateWorkload(const string& filename, int id);
void deleteWorkload(const string& filename, int id);

// Функции для работы с должностями
vector<Position> readPositions(const string& filename);
void writePositions(const string& filename, const vector<Position>& positions);
void addPosition(const string& filename);
void displayPositions(const string& filename);
void updatePosition(const string& filename, int id);
void deletePosition(const string& filename, int id);

// Функции для работы с предметами
vector<Subject> readSubjects(const string& filename);
void writeSubjects(const string& filename, const vector<Subject>& subjects);
void addSubject(const string& filename);
void displaySubjects(const string& filename);
void updateSubject(const string& filename, int id);
void deleteSubject(const string& filename, int id);*/

/*
// Вспомогательные функции
template <typename T>
vector<string> split(const string& s, char delimiter);
string join(const vector<string>& tokens, char delimiter);
template <typename T>
void updateEntityInFile(const string& filename, int id, const T& newEntity, const vector<T>& (*readFunc)(const string&), void (*writeFunc)(const string&, const vector<T>&));

*/


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
/*

// Чтение учебной нагрузки из файла
vector<Workload> readWorkloads(const string& filename) {
    system("cls");
    vector<Workload> workloads;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            Workload workload;
            string temp;
            getline(iss, temp, ',');
            workload.id = stoi(temp);
            getline(iss, workload.fio, ',');
            getline(iss, workload.phone, ',');
            getline(iss, temp, ',');
            workload.experience = stoi(temp);
            getline(iss, workload.degree, ',');
            getline(iss, workload.title, ',');
            getline(iss, workload.department, ',');
            getline(iss, workload.position, ',');
            getline(iss, workload.subject, ',');
            getline(iss, temp, ',');
            workload.workload = stoi(temp);
            getline(iss, temp, ',');
            workload.publications = stoi(temp);
            workloads.push_back(workload);
        }
        file.close();
    }
    return workloads;

}

// Запись учебной нагрузки в файл
void writeWorkloads(const string& filename, const vector<Workload>& workloads) {
    system("cls");
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& workload : workloads) {
            file << workload.id << "," << workload.fio << "," << workload.phone << ","
                 << workload.experience << "," << workload.degree << "," << workload.title << ","
                 << workload.department << "," << workload.position << "," << workload.subject << ","
                 << workload.workload << "," << workload.publications << "\n";
        }
        file.close();
    }
}

// Добавление учебной нагрузки
void addWorkload(const string& filename) {
    system("cls");
    vector<Workload> workloads = readWorkloads(filename);
    Workload workload;
    cout << "Введите ID: ";
    cin >> workload.id;
    cin.ignore();
    cout << "Введите ФИО: ";
    getline(cin, workload.fio);
    cout << "Введите телефон: ";
    getline(cin, workload.phone);
    cout << "Введите стаж: ";
    cin >> workload.experience;
    cin.ignore();
    cout << "Введите научную степень: ";
    getline(cin, workload.degree);
    cout << "Введите звание: ";
    getline(cin, workload.title);
    cout << "Введите кафедру: ";
    getline(cin, workload.department);
    cout << "Введите занимаемую должность: ";
    getline(cin, workload.position);
    cout << "Введите ведомую дисциплину: ";
    getline(cin, workload.subject);
    cout << "Введите нагрузку: ";
    cin >> workload.workload;
    cout << "Введите количество публикаций: ";
    cin >> workload.publications;
    workloads.push_back(workload);
    writeWorkloads(filename, workloads);
    system("pause");
}

// Отображение учебной нагрузки
void displayWorkloads(const string& filename) {
    system("cls");
    vector<Workload> workloads = readWorkloads(filename);

    cout << "+"
         << "---" << "+"
         << "----------------------------------------" << "+"
         << "------------" << "+"
         << "-----" << "+"
         << "-------------------------" << "+"
         << "-------------------------" << "+"
         << "-------------------------" << "+"
         << "-------------------------" << "+"
         << "-------------------------" << "+"
         << "--------" << "+"
         << "------" << "+"
         << "\n";
    cout << "|"
         << std::left << std::setw(3) << "id" << "|"
         << std::left << std::setw(40) << "FIO" << "|"
         << std::left << std::setw(12) << "Phone" << "|"
         << std::left << std::setw(5) << "Exp" << "|"
         << std::left << std::setw(25) << "Degree" << "|"
         << std::left << std::setw(25) << "Title" << "|"
         << std::left << std::setw(25) << "Department" << "|"
         << std::left << std::setw(25) << "Position" << "|"
         << std::left << std::setw(25) << "Subject" << "|"
         << std::left << std::setw(8) << "Workload" << "|"
         << std::left << std::setw(6) << "Public" << "|"
         << "\n";

    cout << "+"
         << "---" << "+"
         << "----------------------------------------" << "+"
         << "------------" << "+"
         << "-----" << "+"
         << "-------------------------" << "+"
         << "-------------------------" << "+"
         << "-------------------------" << "+"
         << "-------------------------" << "+"
         << "-------------------------" << "+"
         << "--------" << "+"
         << "------" << "+"
         << "\n";

    for (const auto& workload : workloads) {
        cout << "|"
            << std::left << std::setw(3) << workload.id << "|"
            << std::left << std::setw(40) << workload.fio << "|"
            << std::left << std::setw(12) << workload.phone << "|"
            << std::left << std::setw(5) << workload.experience << "|"
            << std::left << std::setw(25) << workload.degree << "|"
            << std::left << std::setw(25) << workload.title << "|"
            << std::left << std::setw(25) << workload.department << "|"
            << std::left << std::setw(25) << workload.position << "|"
            << std::left << std::setw(25) << workload.subject << "|"
            << std::left << std::setw(8) << workload.workload << "|"
            << std::left << std::setw(6) << workload.publications << "|"
            << "\n";
        cout << "+"
             << "---" << "+"
             << "----------------------------------------" << "+"
             << "------------" << "+"
             << "-----" << "+"
             << "-------------------------" << "+"
             << "-------------------------" << "+"
             << "-------------------------" << "+"
             << "-------------------------" << "+"
             << "-------------------------" << "+"
             << "--------" << "+"
             << "------" << "+"
             << "\n";
    }
    system("pause");
}

// Изменение учебной нагрузки
void updateWorkload(const string& filename, int id) {
    system("cls");
    vector<Workload> workloads = readWorkloads(filename);
    for (auto& workload : workloads) {
        if (workload.id == id) {
            cout << "Введите новое ФИО: ";
            cin.ignore();
            getline(cin, workload.fio);
            cout << "Введите новый телефон: ";
            getline(cin, workload.phone);
            cout << "Введите новый стаж: ";
            cin >> workload.experience;
            cin.ignore();
            cout << "Введите новую научную степень: ";
            getline(cin, workload.degree);
            cout << "Введите новое звание: ";
            getline(cin, workload.title);
            cout << "Введите новую кафедру: ";
            getline(cin, workload.department);
            cout << "Введите новую занимаемую должность: ";
            getline(cin, workload.position);
            cout << "Введите новую ведомую дисциплину: ";
            getline(cin, workload.subject);
            cout << "Введите новую нагрузку: ";
            cin >> workload.workload;
            cout << "Введите новое количество публикаций: ";
            cin >> workload.publications;
            writeWorkloads(filename, workloads);
            system("pause");
            return;
        }
    }
    cout << "Запись с таким ID не найдена.\n";
    system("pause");
}

// Удаление учебной нагрузки
void deleteWorkload(const string& filename, int id) {
    system("cls");
    vector<Workload> workloads = readWorkloads(filename);
    workloads.erase(remove_if(workloads.begin(), workloads.end(), [id](const Workload& workload) {
        return workload.id == id;
    }), workloads.end());
    writeWorkloads(filename, workloads);
    system("pause");
}

// Чтение должностей из файла
vector<Position> readPositions(const string& filename) {
    system("cls");
    vector<Position> positions;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            Position position;
            string temp;
            getline(iss, temp, ',');
            position.id = stoi(temp);
            getline(iss, position.name, ',');
            getline(iss, position.department, ',');
            getline(iss, temp, ',');
            position.quantity = stoi(temp);
            positions.push_back(position);
        }
        file.close();
    }
    return positions;
}

// Запись должностей в файл
void writePositions(const string& filename, const vector<Position>& positions) {
    system("cls");
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& position : positions) {
            file << position.id << "," << position.name << "," << position.department << "," << position.quantity << "\n";
        }
        file.close();
    }
}


// Добавление должности
void addPosition(const string& filename) {
    system("cls");
    vector<Position> positions = readPositions(filename);
    Position position;
    cout << "Введите ID: ";
    cin >> position.id;
    cin.ignore();
    cout << "Введите наименование должности: ";
    getline(cin, position.name);
    cout << "Введите кафедру: ";
    getline(cin, position.department);
    cout << "Введите количество: ";
    cin >> position.quantity;
    positions.push_back(position);
    writePositions(filename, positions);
    system("pause");
}

// Отображение должностей
void displayPositions(const string& filename) {
    system("cls");
    vector<Position> positions = readPositions(filename);
    cout << "+" << "---" << "+" << "-------------------------" << "+" << "-------------------" << "+" << "-----" << "+" << "\n";
    cout << "|"
        << std::left << std::setw(3) << "id"<< "|"
        << std::left << std::setw(25) << "Name" << "|"
        << std::left << std::setw(19) << "Department" << "|"
        << std::left << std::setw(5) << "Count" << "|"
        << "\n";
    cout << "+" << "---" << "+" << "-------------------------" << "+" << "-------------------" << "+" << "-----" << "+" << "\n";
    for (const auto& position : positions) {
        cout << "|"
            << std::left << std::setw(3) << position.id << "|"
            << std::left << std::setw(25) << position.name << "|"
            << std::left << std::setw(19) << position.department << "|"
            << std::left << std::setw(5) << position.quantity << "|"
            << "\n";
        // --------------------------------------------------
        cout << "+" << "---" << "+" << "-------------------------" << "+" << "-------------------" << "+" << "-----" << "+" << "\n";
    }
    system("pause");
}


// Изменение должности
void updatePosition(const string& filename, int id) {
    system("cls");
    vector<Position> positions = readPositions(filename);
    for (auto& position : positions) {
        if (position.id == id) {
            cout << "Введите новое наименование должности: ";
            cin.ignore();
            getline(cin, position.name);
            cout << "Введите новую кафедру: ";
            getline(cin, position.department);
            cout << "Введите новое количество: ";
            cin >> position.quantity;
            writePositions(filename, positions);
            system("pause");
            return;
        }
    }
    cout << "Запись с таким ID не найдена.\n";
    system("pause");
}

// Удаление должности
void deletePosition(const string& filename, int id) {
    system("cls");
    vector<Position> positions = readPositions(filename);
    positions.erase(remove_if(positions.begin(), positions.end(), [id](const Position& position) {
        return position.id == id;
    }), positions.end());
    writePositions(filename, positions);
    system("pause");
}

// Чтение предметов из файла
vector<Subject> readSubjects(const string& filename) {
    system("cls");
    vector<Subject> subjects;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            Subject subject;
            string temp;
            getline(iss, temp, ',');
            subject.id = stoi(temp);
            getline(iss, subject.name, ',');
            getline(iss, temp, ',');
            subject.hours = stoi(temp);
            subjects.push_back(subject);
        }
        file.close();
    }
    return subjects;
}

// Запись предметов в файл
void writeSubjects(const string& filename, const vector<Subject>& subjects) {
    system("cls");
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& subject : subjects) {
            file << subject.id << "," << subject.name << "," << subject.hours << "\n";
        }
        file.close();
    }
}

// Добавление предмета
void addSubject(const string& filename) {
    system("cls");
    vector<Subject> subjects = readSubjects(filename);
    Subject subject;
    cout << "Введите ID: ";
    cin >> subject.id;
    cin.ignore();
    cout << "Введите наименование предмета: ";
    getline(cin, subject.name);
    cout << "Введите количество часов: ";
    cin >> subject.hours;
    subjects.push_back(subject);
    writeSubjects(filename, subjects);
    system("pause");
}

// Отображение предметов
void displaySubjects(const string& filename) {
    system("cls");
    vector<Subject> subjects = readSubjects(filename);

    cout << "+"
        << "---" << "+"
        << "-------------------------" << "+"
        << "-------"<< "+"
         << "\n";

    cout << "|"
         << std::left << std::setw(3) << "id" << "|"
         << std::left << std::setw(25) << "Name" << "|"
         << std::left << std::setw(7) << "Hours" << "|"
         << "\n";

    cout << "+"
         << "---" << "+"
         << "-------------------------" << "+"
         << "-------"<< "+"
         << "\n";

    for (const auto& subject : subjects) {
        cout << "|"
            << std::left << std::setw(3) << subject.id << "|"
            << std::left << std::setw(25) << subject.name << "|"
            << std::left << std::setw(7) << subject.hours << "|"
            << "\n";

        cout << "+"
             << "---" << "+"
             << "-------------------------" << "+"
             << "-------"<< "+"
             << "\n";
    }
    system("pause");
}

// Изменение предмета
void updateSubject(const string& filename, int id) {
    system("cls");
    vector<Subject> subjects = readSubjects(filename);
    for (auto& subject : subjects) {
        if (subject.id == id) {
            cout << "Введите новое наименование предмета: ";
            cin.ignore();
            getline(cin, subject.name);
            cout << "Введите новое количество часов: ";
            cin >> subject.hours;
            writeSubjects(filename, subjects);
            system("pause");
            return;
        }
    }
    cout << "Запись с таким ID не найдена.\n";
    system("pause");
}

// Удаление предмета
void deleteSubject(const string& filename, int id) {
    system("cls");
    vector<Subject> subjects = readSubjects(filename);
    subjects.erase(remove_if(subjects.begin(), subjects.end(), [id](const Subject& subject) {
        return subject.id == id;
    }), subjects.end());
    writeSubjects(filename, subjects);
    system("pause");
}
*/
