#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
#include <limits> // Для std::numeric_limits

//  Создаем функцию для запроса ввода от пользователя
void inputList(std::list<std::string>& myList, const std::string& listName) {
    int N;
    std::cout << "Enter the number of elements for " << listName << ": ";

    while (true) {
        std::cin >> N;
        if (std::cin.fail() || N <= 0) { // Проверка на корректный ввод
            std::cin.clear(); // Сброс ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 'n'); // Игнорируем неверный ввод
            std::cout << "Please enter a positive number: ";
        }
        else {
            break; // Ввод корректен
        }
    }

    std::cin.ignore(); // Очищаем ввод

    for (int i = 0; i < N; ++i) {
        std::string element;
        std::cout << "Enter element " << (i + 1) << " for " << listName << ": ";

        while (true) {
            std::getline(std::cin, element);
            if (!element.empty()) { // Проверка на пустую строку
                myList.push_back(element);
                break; // Выходим из цикла, если ввод корректен
            }
            else {
                std::cout << "Element cannot be empty. Please enter again: ";
            }
        }
    }
}

//  Создаем функцию для использования итераторов
void combineLists(std::list<std::string>& L1, std::list<std::string>& L2) {
    auto i1 = L1.begin();
    auto i2 = L2.begin();

    std::list<std::string> combinedList;  
    //  Комбинируем элементы в новый список
    while (i1 != L1.end() && i2 != L2.end()) {
        combinedList.push_back(*i1++);
        combinedList.push_back(*i2++);
    }

    // Добавляем оставшиеся элементы из L1
    while (i1 != L1.end()) {
        combinedList.push_back(*i1++);
    }

    // Добавляем оставшиеся элементы из L2
    while (i2 != L2.end()) {
        combinedList.push_back(*i2++);
    }

    L2 = combinedList; // Обновляем L2 с комбинированным списком
}

int main() {
    std::list<std::string> L1;
    std::list<std::string> L2;

    inputList(L1, "L1");
    inputList(L2, "L2");

    combineLists(L1, L2);  //  Комбинируем списки

    std::cout << "Combined list L2: ";
    for (const auto& element : L2) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
