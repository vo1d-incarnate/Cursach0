//
// Created by abrik on 20.05.2024.
//

#ifndef CURSACH0_POSITION_H
#define CURSACH0_POSITION_H

#include <string> // Для работы со строками
#include <vector> // Для использования векторов

using namespace std;

class Position {
public:
    static vector<Position> readPositions(const string& filename);
    static void writePositions(const string& filename, const vector<Position>& positions);
    static void addPosition(const string& filename);
    static void displayPositions(const string& filename);
    static void updatePosition(const string& filename, int id);
    static void deletePosition(const string& filename, int id);
private:
    int id;
    string name;
    string department;
    int quantity;
};


#endif //CURSACH0_POSITION_H
