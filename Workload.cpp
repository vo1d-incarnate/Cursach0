//
// Created by abrik on 20.05.2024.
//

#include <fstream> // ��� ������ � �������
#include <sstream> // ��� ������ � �������� �����
#include <iostream> // ��� �����/������ ������ ����� �������
#include <iomanip> // ��� �������������� ������
#include <algorithm> // ��� ������������� ���������� STL
#include "Workload.h" // ������������ ���� ������

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
    cout << "������� ID: ";
    cin >> workload.id;
    cin.ignore();
    cout << "������� ���: ";
    getline(cin, workload.fio);
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