//
// Created by abrik on 20.05.2024.
//

#ifndef CURSACH0_WORKLOAD_H
#define CURSACH0_WORKLOAD_H

#include <string> // Для работы со строками
#include <vector> // Для использования векторов

using namespace std;

class Workload {
public:
    static vector<Workload> readWorkloads(const string& filename);
    static void writeWorkloads(const string& filename, const vector<Workload>& workloads);
    static void addWorkload(const string& filename);
    static void displayWorkloads(const string& filename);
    static void updateWorkload(const string& filename, int id);
    static void deleteWorkload(const string& filename, int id);
private:
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


#endif //CURSACH0_WORKLOAD_H
