
#ifndef ENTER_H
#define ENTER_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

class Enter {
private:

public:

    Enter() {
        cout << "Конструктор вызван" << endl;
    }
    ~Enter() {
        cout << "Деструктор вызван" << endl;
    }

    void waitForEnter();

};

#endif // ENTER_H
