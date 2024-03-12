#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countSimilarRows(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0; // Перевірка на порожню матрицю
    }

    int m = matrix.size();
    int n = matrix[0].size();

    int count = 0; // Лічильник схожих рядків
    unordered_set<string> uniqueRows; // Множина для збереження унікальних рядків

    // Конвертуємо перший рядок в рядок символів для порівняння
    string firstRow = "";
    for (int j = 0; j < n; ++j) {
        firstRow += to_string(matrix[0][j]) + ",";
    }

    // Перевіряємо решту рядків на схожість з першим
    for (int i = 1; i < m; ++i) {
        string currentRow = "";
        for (int j = 0; j < n; ++j) {
            currentRow += to_string(matrix[i][j]) + ",";
        }

        if (currentRow == firstRow) {
            // Якщо рядок схожий, збільшуємо лічильник та додаємо його до множини
            ++count;
            uniqueRows.insert(currentRow);
        }
    }

    cout << "Схожі рядки: ";
    for (const string& row : uniqueRows) {
        cout << row << " ";
    }
    cout << endl;

    return count;
}

int main() {
    // Приклад використання
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {1, 2, 3},
        {7, 8, 9}
    };

    int result = countSimilarRows(matrix);

    cout << "Кількість схожих рядків: " << result << endl;

    return 0;
}
