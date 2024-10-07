#ifndef PRODUCTS_H
#define PRODUCTS_H

#include "producttype.h"

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

class Products {
private:

public:

    vector<ProductTYPE> VectorProducts;
    // Products& RefToProduct = VectorProducts;
    void addProduct(string name, string Fname, string Sname, double price, int quantity, double purchasePrice, double interestRate, int month, int day);
    void returnProduct(string productName, int quantity, int month, int tm_mon);
    void addPredefinedProducts(const vector<ProductTYPE>& predefinedProducts);

};

#endif


