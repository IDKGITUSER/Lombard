#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "invoice.h"
#include "finance.h"
#include "products.h"
#include "display.h"
#include "enter.h"

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

class UserInterface {
private:

    Finance finance;
    InvoiceTYPE invoice;
    Products StraightRefProducts;
    Display display;
    Enter enter;

    /* InvoiceTYPE* ptrInvoice;
     Finance* ptrFinance;
     Products* ptrProducts;
     Display* ptrDisplay;

     Enter* ptrEnter;
 */
public:

};

#endif // USERINTERFACE_H
