#include <iostream>
#include <iomanip>
#include <windows.h>

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double price;           
    double downPayment;     
    int years;              
    double interestRate;    

    std::cout << "Введите стоимость квартиры: ";
    std::cin >> price;

    std::cout << "Введите начальный взнос: ";
    std::cin >> downPayment;

    std::cout << "Введите число лет ипотеки: ";
    std::cin >> years;

    std::cout << "Введите процентную ставку: ";
    std::cin >> interestRate;

    double loan = price - downPayment;

    std::cout << "\nСумма кредита: " << std::fixed << std::setprecision(2)
              << loan << " руб.\n\n";

    double rate = interestRate / 100.0;

    double factor = 1.0;
    for (int i = 0; i < years; i++) {
        factor *= (1.0 + rate);
    }

    double annualPayment = loan * rate * factor / (factor - 1.0);
    double totalPaid = annualPayment * years;

    std::cout << "Ежегодный платёж: " << std::fixed << std::setprecision(2)
              << annualPayment << " руб.\n\n";

    double remaining = loan;
    for (int year = 1; year <= years; ++year) {
        double interestPart = remaining * rate;
        double principalPart = annualPayment - interestPart;
        remaining -= principalPart;

        if (remaining < 0) remaining = 0;

        std::cout << "Год "  << year << " | проценты = " << interestPart
                  << " | основной долг = " << principalPart
                  << " | остаток = " << remaining << "\n";
    }

    std::cout << "\nОбщая сумма выплат по ипотеке: "
              << std::fixed << std::setprecision(2)
              << totalPaid << " руб.\n";

    std::cout << "Переплата по процентам: "
              << (totalPaid - loan) << " руб.\n";

    std::cout << "Общая стоимость квартиры с учётом взноса и процентов: "
              << (downPayment + totalPaid) << " руб.\n";

    return 0;
}