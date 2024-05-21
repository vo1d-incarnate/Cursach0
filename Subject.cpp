//
// Created by abrik on 20.05.2024.
//

#include <fstream> // Для работы с файлами
#include <sstream> // Для работы с потоками строк
#include <iostream> // Для ввода/вывода данных через консоль
#include <iomanip> // Для форматирования вывода
#include <algorithm> // Для использования алгоритмов STL
#include "Subject.h" // Заголовочный файл класса
#include "center.h" // Функция для центрирования текста

vector<Subject> Subject::readSubjects(const string &filename) {
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

void Subject::writeSubjects(const string &filename, const vector<Subject> &subjects) {
    system("cls");
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& subject : subjects) {
            file << subject.id << "," << subject.name << "," << subject.hours << "\n";
        }
        file.close();
    }
}

void Subject::addSubject(const string &filename) {
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

void Subject::displaySubjects(const string &filename) {
    system("cls");
    vector<Subject> subjects = readSubjects(filename);

    //
    // Массив с шириной полей
    std::vector<int> widths = {3, 25, 5};
    // Печать заголовков таблицы
    std::cout << "+";
    for (const auto& width : widths) {
        std::cout << std::setfill('-') << std::setw(width) << "" << "+";
    }
    std::cout << std::setfill(' ') << "\n";

    std::vector<std::string> headers = {"id", "Предмет", "Часы"};
    std::cout << "|";
    for (size_t i = 0; i < headers.size(); ++i) {
        std::cout << center(headers[i], widths[i]) << "|";
    }
    std::cout << "\n";

    std::cout << "+";
    for (const auto& width : widths) {
        std::cout << std::setfill('-') << std::setw(width) << "" << "+";
    }
    std::cout << std::setfill(' ') << "\n";
    // Печать данных таблицы
    for (const auto& subject : subjects) {
        std::cout << "|";
        std::cout << center(std::to_string(subject.id), widths[0]) << "|"
                  << center(subject.name, widths[1]) << "|"
                  << center(std::to_string(subject.hours), widths[2]) << "|\n";

        std::cout << "+";
        for (const auto& width : widths) {
            std::cout << std::setfill('-') << std::setw(width) << "" << "+";
        }
        std::cout << std::setfill(' ') << "\n";
    }
    //
    /*cout << "+"
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
    }*/
    system("pause");
}

void Subject::updateSubject(const string &filename, int id) {
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

void Subject::deleteSubject(const string &filename, int id) {
    system("cls");
    vector<Subject> subjects = readSubjects(filename);
    subjects.erase(remove_if(subjects.begin(), subjects.end(), [id](const Subject& subject) {
        return subject.id == id;
    }), subjects.end());
    writeSubjects(filename, subjects);
    system("pause");
}
