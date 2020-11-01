#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "big-nums.h"

using namespace std;

// input data 2 big num
// need add, diff, multiple
using TNumber = int;
using TVInt = vector<TNumber>;

int main() {
    // todo aggrement that input data is correct
    fstream file("input.txt");
    if (file.is_open())
    {
        cout << "File is open" << endl;
        long int num = 0;
        string str;
        file >> str;
        BigNumber bn11(str);
        bn11.show();
        file >> str;
        BigNumber bn22(str);
        bn22.show();
        if (bn11 == bn22)
            cout << "bn11 == bn22" << endl;
        else
            cout << "bn11 != bn22" << endl;

        string str1 = "12345";
        string str2 = "22222222";
        BigNumber bn1(str1);
        bn1.show();
        BigNumber bn2(str2);
        bn2.show();
        cout << "Add test " << endl;
        BigNumber bn = bn1 + bn2;
        bn.show();
        cout << "Diff test " << endl;
        bn = bn1 - bn2;
        bn.show();
        cout << 12345 - 22222222 << endl;
        cout <<  22222222 - 12345 << endl;
        cout << "Multiple test " << endl;
        BigNumber bnm1("999999");
        BigNumber bnm2("999999");
        BigNumber bn_assert("999998000001");
        bn =  bnm1 * bnm2;
        cout << " assert : " << (bn_assert == bn? "true": "false") << endl;
        cout << "BigN: ";
        bn.show();

        cout <<"Real: " << (long)999999 * (long)999999 << endl;
        file.close();
    }
    else cout << "Unable to open input.txt file. Please create";
    return 0;
}