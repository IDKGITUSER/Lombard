#ifndef FINANCE_H
#define FINANCE_H

#include "products.h"
#include "invoice.h"

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

struct ExpenseTYPE {
    string category;
    double amount;
};

struct IncomeTYPE {
    string typeInc;
    double amount;
};

class Finance {

public:
    vector<ExpenseTYPE> VectorExpenses;
    vector<IncomeTYPE> VectorIncomes;

    double totalAssets;
    double totalLiabilities;
    void recordExpense(string category, double amount, Products& StraightRefProducts, Invoices& invoices);
    void recordIncome(string typeInc, double amount, Products& StraightRefProducts, Invoices& invoices);
    void updateAssets(Products& StraightRefProducts, Invoices& invoices);

};

#endif
