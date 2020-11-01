#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "big-nums.h"

// for test
#include <assert.h>

using namespace std;

// input data 2 big num
// need add, diff, multiple
using TNumber = int;
using TVInt = vector<TNumber>;

void test_sum()
{
    cout << "Add test " << endl;
    string str1 = "12345";
    string str2 = "22222222";
    BigNumber bn1(str1);
    BigNumber bn2(str2);
    BigNumber etalon("22234567");
    BigNumber bn = bn1 + bn2;
    cout << "Add test " << (etalon == bn ? "Success" : "Fail") << endl;
}

void test_diff()
{
    string str1 = "12345";
    string str2 = "22222222";
    BigNumber bn1(str1);
    BigNumber bn2(str2);
    cout << "Diff test " << endl;
    BigNumber bn = bn1 - bn2;
    BigNumber etalon("22209877");
    cout << "Diff test " << (etalon == bn ? "Success" : "Fail") << endl;
}

void test_multiple()
{
    cout << "Multiple test " << endl;
    string str = string("999999");
    BigNumber bnm1(str);
    BigNumber bnm2(str);
    BigNumber bn = bnm1 * bnm2;
    BigNumber etalon("999998000001");
    cout << "Multiple test " << (etalon == bn ? "Success" : "Fail") << endl;
}

int main()
{
    // todo aggrement that input data is correct
    test_sum();
    test_diff();
    test_multiple();
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
        BigNumber bn = bn11 + bn22;
        bn.show();

        file.close();
    }
    else
        cout << "Unable to open input.txt file. Please create";
    return 0;
}