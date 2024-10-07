#ifndef INVOICE_H
#define INVOICE_H

#include "products.h"
// #include "finance.h"
// #include "display.h"

#include "producttype.h"

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

struct InvoiceTYPE {
    string number;
    int month;
    int day;
    vector<ProductTYPE> products;
    double totalAmount;
};

class Invoices {
private:

public:

    vector<InvoiceTYPE> VectorInvoices;

    // void addInvoice(string& number, int month, int day, const std::vector<ProductTYPE>& products, double totalAmount);

    void addInvoice(string number, int month, int day, vector<ProductTYPE> VectorProducts, double totalAmount);

};

#endif

