
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
        cout << "����������� ������" << endl;
    }
    ~Enter() {
        cout << "���������� ������" << endl;
    }

    void waitForEnter();

};

#endif // ENTER_H
