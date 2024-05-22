//
// Created by abrik on 22.05.2024.
//
#include "hasOnlyDigits.h"

bool hasOnlyDigits(const string &str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}