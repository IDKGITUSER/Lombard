#include "invoice.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

void Invoices::addInvoice(string number, int month, int day, vector<ProductTYPE> VectorProducts, double totalAmount) {
    InvoiceTYPE inv = { number, month, day, VectorProducts, totalAmount };
    this->VectorInvoices.push_back(inv);
}