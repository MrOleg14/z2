#include <iostream>
#include <vector>
#include <map>  // Работа с ассоциативным массивом (мультиотображение)
#include <string>
#include <algorithm>  // Проверка символов

int main() {
    std::vector<std::string> V;  //  Хранение вводимого слова
    std::string input;

    std::cout << "enter english words (enter 'q' for finish):" << std::endl;

    while (true) {
        std::cin >> input;
        if (input == "q") break; 

        // Проверяем заглавные буквы
        if (!std::all_of(input.begin(), input.end(), [](char c) { return std::isupper(c); })) {
            std::cout << "error: enter only capital letters" << std::endl;
            continue;
        }
        V.push_back(input);  // Добавляем слова в вектор
    }

    // Мультиотображение для группировки слов
    std::multimap<char, std::string> M;

    // Группировка слов по последней букве
    for (const auto& word : V) {
        if (!word.empty()) {
            char lastChar = word.back(); // Берем последнюю букву
            M.insert({ lastChar, word }); // Вставка в мультиотображение
        }
    }

    std::cout << "grouping words by last letter:" << std::endl;
    for (const auto& pair : M) {
        std::cout << "key: " << pair.first << ", meaning: " << pair.second << std::endl;
    }
    return 0;
}
