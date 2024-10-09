#include <iostream>
#include <vector>
#include <sstream>
#include <limits>

int main() {
    std::vector<int> L;  // Для динамического выделения памяти
    std::string input;

    while (true) {
        std::cout << "write numbers:" << std::endl;

        // Считываем ввод пользователя
        std::getline(std::cin, input);

        std::istringstream iss(input);
        int number;
        bool validInput = true;

        // Считываем числа из строки
        L.clear(); // Очищаем вектор перед новым вводом
        while (iss >> number) {
            L.push_back(number);  // Для динамического изменения размера
        }

        // Проверка на наличие некорректных данных
        if (iss.fail() && !iss.eof()) {
            std::cout << "error: write only numbers" << std::endl;
            validInput = false;
        }

        // Очищаем поток при ошибке
        iss.clear();
        iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Выходим из цикла, если все корректно
        if (validInput) {
            break;
        }
    }

    // Вывод элементов в исходном порядке
    std::cout << "original numbers:" << std::endl;
    for (int num : L) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Вывод элементов в обратном порядке
    std::cout << "nummbers in reverse order:" << std::endl;
    for (auto it = L.rbegin(); it != L.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
