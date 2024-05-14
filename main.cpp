#include <iostream>
#include "main_view.h" 
#include "input.cpp" 

int main() {
    int sx, sy, dx, dy, n;
    float* x;
    float* y;

    displayMenu(); // Отображаем меню выбора типа ввода данных
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        inputArray(n, x, y); // Ввод с клавиатуры
    }
    else if (choice == 2) {
        const char* fname = "input.txt"; // Имя файла для ввода данных
        inputArray(fname, n, x, y); // Ввод из файла
    }
    else {
        std::cerr << "Ошибка: неверный выбор типа ввода данных!" << std::endl;
        return -1;
    }

    // Ввод координат суслика и собаки
    std::cout << "Введите координаты суслика: ";
    std::cin >> sx >> sy;
    std::cout << "Введите координаты собаки: ";
    std::cin >> dx >> dy;

    // Вызов функции для проверки возможности спасения суслика
    int result = checkSafetyInHoles(sx, sy, dx, dy, n, x, y);

    // Выбор норки для спасения суслика
    int chosenHole = chooseHoleForSafety(n, result);

    // Вывод результата
    if (chosenHole != -1)
        std::cout << "Суслик может спастись в норке под номером: " << chosenHole << std::endl;
    else
        std::cout << "NO" << std::endl;

    // Освобождаем выделенную память
    delete[] x;
    delete[] y;

    return 0;
}
