//
// Created by abrik on 20.05.2024.
//

#include <fstream> // ��� ������ � �������
#include <sstream> // ��� ������ � �������� �����
#include <iostream> // ��� �����/������ ������ ����� �������
#include <iomanip> // ��� �������������� ������
#include <algorithm> // ��� ������������� ���������� STL
#include "Position.h" // ������������ ���� ������
#include "center.h" // ������� ��� ������������� ������


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
    //
    // ������ � ������� �����
    std::vector<int> widths = {3, 25, 40, 6};
    // ������ ���������� �������
    std::cout << "+";
    for (const auto& width : widths) {
        std::cout << std::setfill('-') << std::setw(width) << "" << "+";
    }
    std::cout << std::setfill(' ') << "\n";

    std::vector<std::string> headers = {"id", "���������", "�������", "���-��"};
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
    for (const auto& position : positions) {
        std::cout << "|";
        std::cout << center(std::to_string(position.id), widths[0]) << "|"
                  << center(position.name, widths[1]) << "|"
                  << center(position.department, widths[2]) << "|"
                  << center(std::to_string(position.quantity), widths[3]) << "|\n";

        std::cout << "+";
        for (const auto& width : widths) {
            std::cout << std::setfill('-') << std::setw(width) << "" << "+";
        }
        std::cout << std::setfill(' ') << "\n";
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
