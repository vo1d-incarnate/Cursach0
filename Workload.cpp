//
// Created by abrik on 20.05.2024.
//

#include <fstream> // ��� ������ � �������
#include <sstream> // ��� ������ � �������� �����
#include <iostream> // ��� �����/������ ������ ����� �������
#include <iomanip> // ��� �������������� ������
#include <algorithm> // ��� ������������� ���������� STL
#include "Workload.h" // ������������ ���� ������
#include "center.h" // ������� ��� ������������� ������
#include "hasOnlyDigits.h" // ������� ��� �������� ����� �� ������ ������ �����

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
    string tmp;
    cout << "������� ID: ";
    cin.ignore();
    while (true) {
        getline(cin, tmp);
        if (tmp.empty()) {
            cout << "������ �����. ����������, ������� �������� ��������: ";
        } else {
            if (hasOnlyDigits(tmp)) {
                break;
            } else {
                std::cout << "� ������ ���� �������, �� ���������� �������. ������� �����: ";
            }
        }
    }
    workload.id = stoi(tmp);
    tmp.clear();
    cout << "������� ���: ";
    while (true) {
        getline(cin, workload.fio);
        if (workload.fio.empty()) {
            cout << "������ �����. ����������, ������� �������� ��������: ";
        } else break;
    }
    cout << "������� �������: ";
    getline(cin, workload.phone);
    cout << "������� ����: ";
    cin >> workload.experience;
    cin.ignore();
    cout << "������� ������� �������: ";
    getline(cin, workload.degree);
    cout << "������� ������: ";
    getline(cin, workload.title);
    cout << "������� �������: ";
    getline(cin, workload.department);
    cout << "������� ���������� ���������: ";
    getline(cin, workload.position);
    cout << "������� ������� ����������: ";
    getline(cin, workload.subject);
    cout << "������� ��������: ";
    cin >> workload.workload;
    cout << "������� ���������� ����������: ";
    cin >> workload.publications;
    workloads.push_back(workload);
    writeWorkloads(filename, workloads);
    system("pause");
}

void Workload::displayWorkloads(const string &filename) {
    system("cls");
    vector<Workload> workloads = readWorkloads(filename);
    // ������ � ������� �����
    std::vector<int> widths = {3, 40, 12, 5, 25, 25, 25, 25, 45, 8, 10};
    // ������ ���������� �������
    std::cout << "+";
    for (const auto& width : widths) {
        std::cout << std::setfill('-') << std::setw(width) << "" << "+";
    }
    std::cout << std::setfill(' ') << "\n";

    std::vector<std::string> headers = {"id", "���", "�������", "����", "������� �������", "������", "�������", "���������", "�������(�)", "��������", "����������"};
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
    // ������ ������ �������
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
    system("pause");
}

void Workload::updateWorkload(const string &filename, int id) {
    system("cls");
    vector<Workload> workloads = readWorkloads(filename);
    for (auto& workload : workloads) {
        if (workload.id == id) {
            cout << "������� ����� ���: ";
            cin.ignore();
            getline(cin, workload.fio);
            cout << "������� ����� �������: ";
            getline(cin, workload.phone);
            cout << "������� ����� ����: ";
            cin >> workload.experience;
            cin.ignore();
            cout << "������� ����� ������� �������: ";
            getline(cin, workload.degree);
            cout << "������� ����� ������: ";
            getline(cin, workload.title);
            cout << "������� ����� �������: ";
            getline(cin, workload.department);
            cout << "������� ����� ���������� ���������: ";
            getline(cin, workload.position);
            cout << "������� ����� ������� ����������: ";
            getline(cin, workload.subject);
            cout << "������� ����� ��������: ";
            cin >> workload.workload;
            cout << "������� ����� ���������� ����������: ";
            cin >> workload.publications;
            writeWorkloads(filename, workloads);
            system("pause");
            return;
        }
    }
    cout << "������ � ����� ID �� �������.\n";
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
