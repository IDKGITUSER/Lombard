#include "finance.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

void Finance::recordExpense(string category, double amount, Products& StraightRefProducts, Invoices& invoices) {
    ExpenseTYPE e = { category, amount };
    VectorExpenses.push_back(e);
    updateAssets(StraightRefProducts, invoices);
}

void Finance::recordIncome(string typeInc, double amount, Products& StraightRefProducts, Invoices& invoices) {
    IncomeTYPE i = { typeInc, amount };
    VectorIncomes.push_back(i);
    updateAssets(StraightRefProducts, invoices);
}

void Finance::updateAssets(Products& StraightRefProducts, Invoices& invoices) {
    totalAssets = 0.0;
    totalLiabilities = 0.0;

    for (const auto& p : StraightRefProducts.VectorProducts) {
        totalAssets += p.price * p.quantity;
    }

    for (const auto& inv : invoices.VectorInvoices) {
        totalLiabilities += inv.totalAmount;
    }

    for (const auto& e : VectorExpenses) {
        totalLiabilities -= e.amount;
    }

    for (const auto& i : VectorIncomes) {
        totalLiabilities += i.amount;
    }
}
