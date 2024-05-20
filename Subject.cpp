//
// Created by abrik on 20.05.2024.
//

#include <fstream> // ��� ������ � �������
#include <sstream> // ��� ������ � �������� �����
#include <iostream> // ��� �����/������ ������ ����� �������
#include <iomanip> // ��� �������������� ������
#include <algorithm> // ��� ������������� ���������� STL
#include "Subject.h" // ������������ ���� ������

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
    cout << "������� ID: ";
    cin >> subject.id;
    cin.ignore();
    cout << "������� ������������ ��������: ";
    getline(cin, subject.name);
    cout << "������� ���������� �����: ";
    cin >> subject.hours;
    subjects.push_back(subject);
    writeSubjects(filename, subjects);
    system("pause");
}

void Subject::displaySubjects(const string &filename) {
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

void Subject::updateSubject(const string &filename, int id) {
    system("cls");
    vector<Subject> subjects = readSubjects(filename);
    for (auto& subject : subjects) {
        if (subject.id == id) {
            cout << "������� ����� ������������ ��������: ";
            cin.ignore();
            getline(cin, subject.name);
            cout << "������� ����� ���������� �����: ";
            cin >> subject.hours;
            writeSubjects(filename, subjects);
            system("pause");
            return;
        }
    }
    cout << "������ � ����� ID �� �������.\n";
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
