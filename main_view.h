#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <cmath>

// Функция проверки возможности спасения суслика
int checkSafetyInHoles(int sx, int sy, int dx, int dy, int n, float* x, float* y) {
    int minDogDist = INT_MAX;
    int holeIdx = -1;
    for (int i = 0; i < n; ++i) {
        int distToHole = abs(sx - x[i]) + abs(sy - y[i]);
        int distToDog = abs(dx - x[i]) + abs(dy - y[i]);
        std::cout << "distToHole: " << distToHole << ", distToDog: " << distToDog << std::endl;
        if (distToDog <= distToHole * 2) {
            return -1;
        }
        if (distToDog < minDogDist) {
            minDogDist = distToDog;
            holeIdx = i + 1;
        }
    }
    return holeIdx;
}



// Функция выбора норки для спасения суслика
int chooseHoleForSafety(int n, int result) {
    if (result != -1)
        return result;
    else
        return -1;
}

// Функция для выполнения теста
bool runTest(int testNumber, int sx, int sy, int dx, int dy, int n, float* x, float* y, int expected) {
    int result = checkSafetyInHoles(sx, sy, dx, dy, n, x, y);
    if (result == expected) {
        std::cout << "Тест " << testNumber << " пройден успешно" << std::endl;
        return true;
    }
    else {
        std::cout << "Тест " << testNumber << " не пройден. Ожидаемый результат: " << expected << ", Фактический результат: " << result << std::endl;
        return false;
    }
}

#endif
