#define _CRT_SECURE_NO_WARNINGS

#include "products.h"
#include "userinterface.h"
#include "finance.h"
#include "display.h"
#include "enter.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

string inputStr() {

    string res = "";
    char ch;

    ch = getchar();

    do {

        ch = getchar();
        if (ch == '\n') {
            break;
        }
        res.push_back(ch);

    } while (ch != '\n');

    return res;
}

int main() {

    Finance finance;
    Products StraightRefProducts;
    Display display;
    Invoices invoices;
    Enter enter;

    int choice = 0;

    while (true) {
        system("cls");
        std::cout << "1. Add Product From New Customer\n";
        std::cout << "2. Add Invoice\n";
        std::cout << "3. Record Expense\n";
        std::cout << "4. Record External Income\n";
        std::cout << "5. Return Product Back To Customer\n";
        std::cout << "6. Display Summary\n";
        std::cout << "7. Show Product List\n";
        std::cout << "8. Exit\n";
        std::cout << "9. Predefined List Of Items\n";
        std::cout << "Enter choice: ";


        if (!(std::cin >> choice)) {
            std::cerr << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();  // Очистка ошибки
            std::cin.ignore(10000, '\n');  // Пропуск оставшихся символов
            continue;  // Переход к следующему итерации цикла
        }

        time_t now = time(0);
        tm* ltm = localtime(&now);

        switch (choice) {
        case 1: {
            system("cls");
            std::string name;
            std::string Fname;
            std::string Sname;
            double price;
            int quantity;
            double purchasePrice;
            double interestRate;
            int month;
            int day;
            int tm_mon;
            int tm_mday;


            std::cout << "Enter product name: ";
            
            name = inputStr();

            std::cout << "Enter client's first name: ";
            std::cin >> Fname;

            std::cout << "Enter client's second name: ";
            std::cin >> Sname;

            std::cout << "Enter purchase price: ";
            std::cin >> purchasePrice;

            std::cout << "Enter price: ";
            std::cin >> price;

            std::cout << "Enter quantity: ";
            std::cin >> quantity;

            std::cout << "Enter interest rate (%): ";
            std::cin >> interestRate;

            std::cout << "\nSuccess\n";

            std::cout << "\nToday is:\n";

            std::cout << ltm->tm_year + 1900 << "-"
                << ltm->tm_mon + 1 << "-"
                << ltm->tm_mday << "\n\n";

            month = ltm->tm_mon;
            day = ltm->tm_mday;

            StraightRefProducts.addProduct(name, Fname, Sname, price, quantity, purchasePrice, interestRate / 100, month, day);
            enter.waitForEnter();
            break;
        }

        case 2: {
            system("cls");
            std::string number, date;

            int quantity=0;
            int month;
            int day;
            int tm_mon=0;
            int tm_mday;
            double totalAmount = 0;


            std::cout << "\nToday is:\n";

            std::cout << ltm->tm_year + 1900 << "-"
                << ltm->tm_mon + 1 << "-"
                << ltm->tm_mday << "\n\n";

            month = ltm->tm_mon;
            day = ltm->tm_mday;

            std::cout << "Enter invoice number: ";
            std::cin >> number;

            int count;
            std::cout << "How many products on this invoice? ";
            std::cin >> count;

            for (int i = 0; i < count; i++) {
                std::string name;
                double price;
                int quantity;

                std::cout << "Enter product name: ";

                name = inputStr();

                std::cout << "Enter price: ";
                std::cin >> price;

                std::cout << "Enter quantity: ";
                std::cin >> quantity;

                totalAmount += quantity * price;
            }

            invoices.addInvoice(number, month, day, StraightRefProducts.VectorProducts, totalAmount);
            std::cout << "\nSuccess\n";
            enter.waitForEnter();
            break;
        }

        case 3: {
            system("cls");
            std::string category;
            double amount;

            std::cout << "Enter expense category: ";
            std::cin >> category;

            std::cout << "Enter amount of loss: ";
            std::cin >> amount;

            finance.recordExpense(category, amount, StraightRefProducts, invoices);
            std::cout << "\nSuccess\n";
            enter.waitForEnter();
            break;
        }

        case 4: {
            system("cls");
            std::string type;
            double amount;
            std::cout << "\n Here you must enter data on external additional revenues, such as subsidies, etc. \n\n";

            std::cout << "Enter income type: ";
            std::cin >> type;

            std::cout << "Enter amount of gain: ";
            std::cin >> amount;

            finance.recordIncome(type, amount, StraightRefProducts, invoices);
            std::cout << "\nSuccess\n";
            enter.waitForEnter();
            break;
        }

        case 5: {
            system("cls");
            std::string productName;
            int month = 0;
            int tm_mon = ltm->tm_mon;
            int quantity = 0;
            std::cout << "Enter product name to return: ";
       
            productName = inputStr();

            StraightRefProducts.returnProduct(productName, quantity, month, tm_mon);
            std::cout << "\nSuccess\n";
            enter.waitForEnter();
            break;
        }

        case 6: {
            system("cls");
            display.displaySummary(invoices.VectorInvoices, StraightRefProducts.VectorProducts, finance);
            std::cout << "\nSuccess\n";
            enter.waitForEnter();
            break;
        }
        case 7: {
            system("cls");
            display.displayProductslist(StraightRefProducts.VectorProducts);
            std::cout << "\nSuccess\n";
            enter.waitForEnter();
            break;
        }

        case 8:
            return 0;



        case 9: {
            system("cls");
            vector<ProductTYPE> predefinedProducts = {
                                                {"Test First", "Timur", "Shevchenko", 1500.00, 10, 1200.00, 5, 2, 30},
                                                {"Test Second", "Andrey", "Glazov", 800.00, 20, 700.00, 6, 10, 12},
                                                {"Test Third", "Victor", "Starozhil", 300.00, 30, 250.00, 7, 5, 2}
            };
            StraightRefProducts.addPredefinedProducts(predefinedProducts);
            std::cout << "\nSuccess\n\n";
            enter.waitForEnter();
            break;
        }

        default:
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}