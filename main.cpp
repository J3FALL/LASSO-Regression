#include <iostream>
#include "DataSet.h"

using namespace std;


int main() {
    DataSet dataSet;

    for (double &it : dataSet.target) {
        cout << " " << it << endl;
    }
    return 0;
}