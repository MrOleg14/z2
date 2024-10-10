#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

bool isValidInput(const std::string& input) {
    std::istringstream iss(input);
    int number;
    while (iss >> number) {
    }
    return iss.eof(); // Проверяем, что весь ввод был обработан
}

int main() {
    std::vector<int> V;
    std::string input;

    std::cout << "enter an even number of integers separated by spaces: ";
    std::getline(std::cin, input);

    if (!isValidInput(input)) {
        std::cerr << "error: enter only integers separated " << std::endl;
        return 1;
    }

    std::istringstream iss(input);
    int number;
    while (iss >> number) {
        V.push_back(number);
    }

    // Проверка на четность количества элементов
    if (V.size() % 2 != 0) {
        std::cerr << "the number of elements must be even" << std::endl;
        return 1;
    }

    // Разделяем вектор на две половины
    size_t mid = V.size() / 2;
    std::vector<int> firstHalf(V.begin(), V.begin() + mid);
    std::vector<int> secondHalf(V.begin() + mid, V.end());

    // Находим последний элемент первой половины, который есть во второй половине
    auto it = std::find_first_of(firstHalf.rbegin(), firstHalf.rend(), secondHalf.begin(), secondHalf.end());

    if (it != firstHalf.rend()) {
        // Если найден элемент, вставляем 0 перед ним
        auto pos = it.base(); // Получаем итератор для вставки
        firstHalf.insert(pos - 1, 0); // Вставляем 0 
    }

    // Соединяем части вектора обратно
    V.clear();
    V.insert(V.end(), firstHalf.begin(), firstHalf.end());
    V.insert(V.end(), secondHalf.begin(), secondHalf.end());

    std::cout << "new vector: ";
    for (const auto& elem : V) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
