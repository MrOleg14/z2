#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iomanip> // Для std::setprecision форматирование ввода/вывода

int main() {
    std::list<double> L;
    std::string input;

    std::cout << "enter real numbers (enter 'q' for finish):" << std::endl;
    while (true) {
        std::cin >> input;
        if (input == "q") {
            break;
        }
        try {
            L.push_back(std::stod(input)); // Преобразуем строку в число
        }
        catch (const std::invalid_argument&) {
            std::cout << "error: enter again" << std::endl;
        }
    }

    // Проверяем ввод
    if (L.size() < 2) {
        std::cout << "the list must have at least 2 elements" << std::endl;
        return 1;
    }

    // Вектор для хранения ср арифмет
    std::vector<double> V;

    // Используем итераторы для вычисления ср арифмет
    auto it = L.begin();
    auto next_it = std::next(it);

    while (next_it != L.end()) {
        V.push_back((*it + *next_it) / 2.0); // Считаем ср арифмет
        ++it;
        ++next_it;
    }

    std::cout << std::fixed << std::setprecision(2); // Устанавливаем фиксированное количество знаков после запятой

    std::cout << "vector of arithmetic means:" << std::endl;
    for (const auto& value : V) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
