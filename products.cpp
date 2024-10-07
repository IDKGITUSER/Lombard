#include "products.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

void Products::addProduct(string name, string Fname, string Sname, double price, int quantity, double purchasePrice, double interestRate, int month, int day) {
    ProductTYPE p = { name, Fname, Sname, price, quantity, purchasePrice, interestRate, month, day };
    this->VectorProducts.push_back(p);
    // finance.updateAssets();
}

void Products::returnProduct(string productName, int quantity, int month, int tm_mon) {
    auto it = find_if(this->VectorProducts.begin(), this->VectorProducts.end(),
        [&productName](const ProductTYPE& p) { return p.name == productName; });

    if (it != this->VectorProducts.end()) {
        if (it->month <= tm_mon) {  // Compare with tm_mon, not month

            std::cout << "Enter quantity to return: ";
            std::cin >> quantity;

            if (it->quantity >= quantity) {
                it->quantity -= quantity;
                cout << "Product returned successfully." << endl;
                if (it->quantity == 0) {
                    this->VectorProducts.erase(it);  // Erase the element
                    it = this->VectorProducts.end();  // Set it to the end iterator
                }
            }
            else {
                cout << "Not enough quantity available." << endl;
            }
        }
        else {
            cout << "\nDate isn't valid for returning.\n" << endl;
        }
    }
    else {
        cout << "Product not found." << endl;
    }
}

void Products::addPredefinedProducts(const vector<ProductTYPE>& predefinedProducts) {
    for (const auto& product : predefinedProducts) {
        this->VectorProducts.push_back(product);
    }
    // finance.updateAssets();
}
