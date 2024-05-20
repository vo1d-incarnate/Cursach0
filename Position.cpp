//
// Created by abrik on 20.05.2024.
//

#include <fstream> // ��� ������ � �������
#include <sstream> // ��� ������ � �������� �����
#include <iostream> // ��� �����/������ ������ ����� �������
#include <iomanip> // ��� �������������� ������
#include <algorithm> // ��� ������������� ���������� STL
#include "Position.h" // ������������ ���� ������

vector<Position> Position::readPositions(const string &filename) {
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

void Position::writePositions(const string &filename, const vector<Position> &positions) {
    system("cls");
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& position : positions) {
            file << position.id << "," << position.name << "," << position.department << "," << position.quantity << "\n";
        }
        file.close();
    }
}

void Position::addPosition(const string &filename) {
    system("cls");
    vector<Position> positions = readPositions(filename);
    Position position;
    cout << "������� ID: ";
    cin >> position.id;
    cin.ignore();
    cout << "������� ������������ ���������: ";
    getline(cin, position.name);
    cout << "������� �������: ";
    getline(cin, position.department);
    cout << "������� ����������: ";
    cin >> position.quantity;
    positions.push_back(position);
    writePositions(filename, positions);
    system("pause");
}

void Position::displayPositions(const string &filename) {
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

void Position::updatePosition(const string &filename, int id) {
    system("cls");
    vector<Position> positions = readPositions(filename);
    for (auto& position : positions) {
        if (position.id == id) {
            cout << "������� ����� ������������ ���������: ";
            cin.ignore();
            getline(cin, position.name);
            cout << "������� ����� �������: ";
            getline(cin, position.department);
            cout << "������� ����� ����������: ";
            cin >> position.quantity;
            writePositions(filename, positions);
            system("pause");
            return;
        }
    }
    cout << "������ � ����� ID �� �������.\n";
    system("pause");
}

void Position::deletePosition(const string &filename, int id) {
    system("cls");
    vector<Position> positions = readPositions(filename);
    positions.erase(remove_if(positions.begin(), positions.end(), [id](const Position& position) {
        return position.id == id;
    }), positions.end());
    writePositions(filename, positions);
    system("pause");
}
