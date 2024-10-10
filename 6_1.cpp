#include <iostream>
#include <vector>
#include <limits> // для std::numeric_limits

int main() {
    double A, B;

    std::cout << "enter meaning A: ";
    while (true) {
        std::cin >> A;
        if (std::cin.good()) {
            break; // Выходим из цикла, если все норм
        }
        else {
            std::cout << "error: enter number for A: ";
            std::cin.clear(); // Сброс состояния 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 'n'); // игнорим некорректный ввод
        }
    }

    // Ввод значения B с проверкой на корректность
    std::cout << "enter meaning B: ";
    while (true) {
        std::cin >> B;
        if (std::cin.good()) {
            break; // Выходим из цикла, если все норм
        }
        else {
            std::cout << "error: enter number for B: ";
            std::cin.clear(); // Сброс состояния 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 'n'); // игнорим некорректный ввод
        }
    }

    // Создаем вектора V1 и V2
    std::vector<double> V1(10);
    std::vector<double> V2(10);

    // Заполняем V1
    std::fill(V1.begin(), V1.begin() + 5, A); // Первые 5 элементов
    std::fill(V1.begin() + 5, V1.end(), B);   // Последние 5 элементов

    // Заполняем V2
    std::fill_n(V2.begin(), 5, A); // Первые 5 элементов
    std::fill_n(V2.begin() + 5, 5, B); // япоследние 5 элементов

    std::cout << "vector V1: ";
    for (const auto& val : V1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "vector V2: ";
    for (const auto& val : V2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
