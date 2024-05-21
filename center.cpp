//
// Created by abrik on 21.05.2024.
//

#include <string> // Для работы со строками

using namespace std;

// Функция для центрирования текста
string center(const string& text, int width) {
    int padding = width - text.size();
    int padLeft = padding / 2;
    int padRight = padding - padLeft;
    return string(padLeft, ' ') + text + string(padRight, ' ');
}