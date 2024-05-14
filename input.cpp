#include <iostream>
#include <fstream>

using namespace std;

// Ввод с клавиатуры (2 координаты, n точек)
void inputArray(int& n, float*& x, float*& y) {
    cout << "Введите количество точек: ";
    cin >> n;
    x = new float[n];
    y = new float[n];
    for (int i = 0; i < n; ++i) {
        cout << "Введите координаты точки " << i + 1 << ": ";
        cin >> x[i] >> y[i];
    }
}

// Ввод из файла
void inputArray(const char* fname, int& n, float*& x, float*& y) {
    ifstream file(fname);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }
    file >> n;
    x = new float[n];
    y = new float[n];
    for (int i = 0; i < n; ++i) {
        file >> x[i] >> y[i];
    }
    file.close();
}
