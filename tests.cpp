#include <iostream>
#include "main_view.h" 
#include "input.cpp"

// Функция для запуска тестов белого ящика
void runWhiteBoxTests() {
    // Тесты для checkSafetyInHoles
    std::cout << "Тесты для checkSafetyInHoles (белый ящик):" << std::endl;
    // Тест 1: собака достигает норки раньше суслика
    float x1[] = { 15 };
    float y1[] = { 15 };
    int result1 = checkSafetyInHoles(5, 5, 20, 20, 1, x1, y1);
    if (result1 == -1)
        std::cout << "Тест 1 пройден успешно" << std::endl;
    else
        std::cout << "Тест 1 не пройден" << std::endl;

    // Тест 2: суслик может спастись в норке
    float x2[] = { 15, 25 };
    float y2[] = { 15, 25 };
    int result2 = checkSafetyInHoles(20, 20, 10, 10, 2, x2, y2);
    if (result2 == 2)
        std::cout << "Тест 2 пройден успешно" << std::endl;
    else
        std::cout << "Тест 2 не пройден" << std::endl;

    // Тест 3: отсутствие норок
    int result3 = checkSafetyInHoles(10, 10, 30, 30, 0, nullptr, nullptr);
    if (result3 == -1)
        std::cout << "Тест 3 пройден успешно" << std::endl;
    else
        std::cout << "Тест 3 не пройден" << std::endl;

    // Тесты для chooseHoleForSafety
    std::cout << "\nТесты для chooseHoleForSafety (белый ящик):" << std::endl;
    // Тест 1: суслик может спастись
    int result4 = chooseHoleForSafety(2, 2);
    if (result4 == 2)
        std::cout << "Тест 1 пройден успешно" << std::endl;
    else
        std::cout << "Тест 1 не пройден" << std::endl;

    // Тест 2: суслик не может спастись
    int result5 = chooseHoleForSafety(0, -1);
    if (result5 == -1)
        std::cout << "Тест 2 пройден успешно" << std::endl;
    else
        std::cout << "Тест 2 не пройден" << std::endl;
}

// Функция для запуска тестов черного ящика
void runBlackBoxTests() {
    // Тесты для checkSafetyInHoles из черного ящика
    std::cout << "Тесты для checkSafetyInHoles из черного ящика:" << std::endl;
    // Тест 1
    float x1_ch[] = {15};
    float y1_ch[] = {15};
    if (runTest(1, 5, 5, 20, 20, 1, x1_ch, y1_ch, -1))
        std::cout << "Тест 1 пройден успешно" << std::endl;
    else
        std::cout << "Тест 1 не пройден" << std::endl;

    // Тест 2
    float x2_ch[] = {15, 25};
    float y2_ch[] = {15, 25};
    if (runTest(2, 20, 20, 10, 10, 2, x2_ch, y2_ch, 2))
        std::cout << "Тест 2 пройден успешно" << std::endl;
    else
        std::cout << "Тест 2 не пройден" << std::endl;

    // Тест 3
    float x3_ch[] = {15, 20, 25};
    float y3_ch[] = {15, 20, 25};
    if (runTest(3, 10, 10, 30, 30, 3, x3_ch, y3_ch, -1))
        std::cout << "Тест 3 пройден успешно" << std::endl;
    else
        std::cout << "Тест 3 не пройден" << std::endl;

    // Тест 4
    float x4_ch[] = {15};
    float y4_ch[] = {15};
    if (runTest(4, 10, 10, 10, 10, 1, x4_ch, y4_ch, -1))
        std::cout << "Тест 4 пройден успешно" << std::endl;
    else
        std::cout << "Тест 4 не пройден" << std::endl;

    // Тест 5
    float x5_ch[] = {6};
    float y5_ch[] = {6};
    if (runTest(5, 5, 5, 30, 30, 1, x5_ch, y5_ch, 1))
        std::cout << "Тест 5 пройден успешно" << std::endl;
    else
        std::cout << "Тест 5 не пройден" << std::endl;
}

int main() {
    runWhiteBoxTests(); // Запускаем тесты белого ящика
    std::cout << std::endl; 
    runBlackBoxTests(); // Запускаем тесты черного ящика
    return 0;
}
