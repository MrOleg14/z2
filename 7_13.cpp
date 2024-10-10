#include <iostream>
#include <vector>
#include <algorithm>  // Сортируем и объединяем
#include <limits>

// Функции для проверки значений (фильтруем значения)
bool isNegative(int x) {
    return x < 0;
}

bool isZero(int x) {
    return x == 0;
}

int main() {
    int n;

    while (true) {
        std::cout << "enter the number of elements (divisible by 3): ";
        std::cin >> n;

        if (std::cin.fail() || n <= 0 || n % 3 != 0) {
            std::cin.clear(); // Сбрасываем состояние
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 'n'); // Игнорим оставшийся ввод
            std::cout << "error: check the number " << std::endl;
        }
        else {
            break; 
        }
    }

    std::vector<int> V(n);

    for (int i = 0; i < n; ++i) {
        while (true) {
            std::cout << "enter number " << i + 1 << ": ";
            std::cin >> V[i];

            if (std::cin.fail()) {
                std::cin.clear(); // Сбрасываем состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 'n'); // Игнорируем оставшийся ввод
                std::cout << "error: enter an integer" << std::endl;
            }
            else {
                break; 
            }
        }
    }

    // Сортируем каждую треть вектора
    int third = n / 3;
    std::sort(V.begin(), V.begin() + third);
    std::sort(V.begin() + third, V.begin() + 2 * third);
    std::sort(V.begin() + 2 * third, V.end());

    // Объединеняем отсортированных частей
    std::inplace_merge(V.begin(), V.begin() + third, V.begin() + 2 * third);
    std::inplace_merge(V.begin(), V.begin() + 2 * third, V.end());

    // Перегруппируем элементы
    // auto it = std::stable_partition(V.begin(), V.end(), isNegative);
    // std::stable_partition(it, V.end(), isZero);

    std::cout << "result: ";
    for (const auto& val : V) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
