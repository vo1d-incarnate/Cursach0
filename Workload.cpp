//
// Created by abrik on 20.05.2024.
//

#include <fstream> // Для работы с файлами
#include <sstream> // Для работы с потоками строк
#include <iostream> // Для ввода/вывода данных через консоль
#include <iomanip> // Для форматирования вывода
#include <algorithm> // Для использования алгоритмов STL
#include "Workload.h" // Заголовочный файл класса

vector<Workload> Workload::readWorkloads(const string &filename) {
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

void Workload::writeWorkloads(const string &filename, const vector<Workload> &workloads) {
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

void Workload::addWorkload(const string &filename) {
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

// Функция для центрирования текста
std::string center(const std::string& text, int width) {
    int padding = width - text.size();
    int padLeft = padding / 2;
    int padRight = padding - padLeft;
    return std::string(padLeft, ' ') + text + std::string(padRight, ' ');
}

void Workload::displayWorkloads(const string &filename) {
    system("cls");
    vector<Workload> workloads = readWorkloads(filename);
    //
    std::vector<int> widths = {3, 40, 12, 5, 25, 25, 25, 25, 45, 8, 6};
    // Печать заголовков таблицы
    std::cout << "+";
    for (const auto& width : widths) {
        std::cout << std::setfill('-') << std::setw(width) << "" << "+";
    }
    std::cout << std::setfill(' ') << "\n";

    std::vector<std::string> headers = {"id", "FIO", "Phone", "Exp", "Degree", "Title", "Department", "Position", "Subject", "Workload", "Public"};
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
    for (const auto& workload : workloads) {
        std::cout << "|";
        std::cout << center(std::to_string(workload.id), widths[0]) << "|"
                  << center(workload.fio, widths[1]) << "|"
                  << center(workload.phone, widths[2]) << "|"
                  << center(std::to_string(workload.experience), widths[3]) << "|"
                  << center(workload.degree, widths[4]) << "|"
                  << center(workload.title, widths[5]) << "|"
                  << center(workload.department, widths[6]) << "|"
                  << center(workload.position, widths[7]) << "|"
                  << center(workload.subject, widths[8]) << "|"
                  << center(std::to_string(workload.workload), widths[9]) << "|"
                  << center(std::to_string(workload.publications), widths[10]) << "|\n";

        std::cout << "+";
        for (const auto& width : widths) {
            std::cout << std::setfill('-') << std::setw(width) << "" << "+";
        }
        std::cout << std::setfill(' ') << "\n";
    }
    //

    /*cout << "+"
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
    }*/
    system("pause");
}

void Workload::updateWorkload(const string &filename, int id) {
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

void Workload::deleteWorkload(const string &filename, int id) {
    system("cls");
    vector<Workload> workloads = readWorkloads(filename);
    workloads.erase(remove_if(workloads.begin(), workloads.end(), [id](const Workload& workload) {
        return workload.id == id;
    }), workloads.end());
    writeWorkloads(filename, workloads);
    system("pause");
}
