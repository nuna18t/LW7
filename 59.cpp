#include <iostream>
#include <vector>

using namespace std;

void mirrorMatrix(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return; // Перевірка на порожню матрицю
    }

    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m / 2; ++i) {
        swap(matrix[i], matrix[m - 1 - i]); // Поміняти рядки місцями
    }
}

int main() {
    // Приклад використання
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Оригінальна матриця:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    mirrorMatrix(matrix);

    cout << "Дзеркально відображена матриця:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
