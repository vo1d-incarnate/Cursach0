//
// Created by abrik on 20.05.2024.
//

#ifndef CURSACH0_SUBJECT_H
#define CURSACH0_SUBJECT_H

#include <string> // Для работы со строками
#include <vector> // Для использования векторов

using namespace std;

class Subject {
public:
    static vector<Subject> readSubjects(const string& filename);
    static void writeSubjects(const string& filename, const vector<Subject>& subjects);
    static void addSubject(const string& filename);
    static void displaySubjects(const string& filename);
    static void updateSubject(const string& filename, int id);
    static void deleteSubject(const string& filename, int id);
private:
    int id;
    string name;
    int hours;
};


#endif //CURSACH0_SUBJECT_H
