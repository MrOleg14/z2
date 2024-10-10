#include <iostream>
#include <vector>

int main() {
    int n;

    std::cout << "enter the number of vector elements (even number): ";
    std::cin >> n;

    if (n <= 0 || n % 2 != 0) {  // Проверка на четность
        std::cerr << "error: enter a positive even number" << std::endl;
        return 1;
    }

    std::vector<int> V(n);

    std::cout << "enter " << n << " vector elements:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> V[i];
    }

    int mid = n / 2;  // Находим середину вектора

    V.insert(V.begin() + mid, 5, 0);  // Добавляем 5 нулевых элементов в середину

    std::cout << "new vector: ";
    for (const auto& elem : V) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
