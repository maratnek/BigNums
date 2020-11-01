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

void show(const TVInt &v) {
    for (auto it = v.rbegin(); it != v.rend(); ++it)
    {
        cout << *it;
    }
    cout << endl;
}
void str_to_vec(TVInt &v, const string &s)
{
    for (auto it = s.rbegin(); it != s.rend(); ++it)
    {
        char c = *it;
        cout << c;
        v.push_back(atoi(&c));
    }
}

auto add(const TVInt& v1, const TVInt& v2) {
    TVInt t;
    t.resize(v1.size() > v2.size() ? v1.size() : v2.size(), 0);
    TNumber mem = 0;    
    for (size_t i = 0; i < v1.size() || i < v2.size(); ++i)
    {
        // t[i] = (i < v1.size() ? (true ? v1[i] : -v1[i]) : 0) + (i < v2.size() ? (true ? v2[i] : -v2[i]) : 0);
        t[i] = (i < v1.size() ? v1[i] : 0) +  (i < v2.size() ? v2[i] : 0) + mem;
        mem = t[i] / 10;
        t[i] = t[i] % 10;
        cout << "ostat: " << t[i] << " " << mem << " ";
    }
    cout << t.size() << endl;
    cout << endl;
    return move(t); 
}

auto diff(TVInt v1, TVInt v2) {
    TVInt t;
    t.resize(v1.size() > v2.size() ? v1.size() : v2.size(), 0);
    TNumber mem = 0;    
    if (v1.size() > v2.size()) {
    for (size_t i = 0; i < v1.size(); ++i)
    {
        t[i] = (i < v1.size() ? v1[i] : 0) -  (i < v2.size() ? v2[i] : 0) + mem;
        if (t[i] < 0) {
            t[i] = 10 + t[i];
            mem = -1;
        } else {
            mem = 0;
        }
    }
    } else {
    for (size_t i = 0; i < v2.size(); ++i)
    {
        t[i] = (i < v2.size() ? v2[i] : 0) -  (i < v1.size() ? v1[i] : 0) + mem;
        if (t[i] < 0) {
            t[i] = 10 + t[i];
            mem = -1;
        } else {
            mem = 0;
        }
    }
    }
    cout << t.size() << endl;
    cout << endl;
    return move(t); 
}

auto diff(const string& str1, const string &str2) {
    cout << "Long num is 1: " << str1 << endl;
    vector<int> v_num1;
    str_to_vec(v_num1, str1);
    for (auto it : v_num1)
        cout << it << "-";
    cout << endl;
    cout << "Long num is 2: " << str2 << endl;
    vector<int> v_num2;
    str_to_vec(v_num2, str2);
    for (auto it : v_num2)
        cout << it << "-";
    cout << endl;
    return diff(v_num1, v_num2);
}

// n * m   i //  9345 * 5432 
//         1    2*5 = 10 1 0   -> t[0] = 0 . mem[1] = 1

//         2   30*5 = 150 1 5 
//         2 .  2*40= 80  0 8
// .       2 .  5 + 8 + mem[1] = 14 1 4 . -> t[1] = 4  mem[2] = 1
// .       2 .  1 + 0 + mem[2] = 1        -> mem[2] = 2

//         3 .  400 * 5 = 2000 2 0 . mem[3] = 2
//         3 .  30 * 40 = 1200 1 2   mem[3] = 2 + 1 = 3
//         3 .  2 * 300 = 600 0 6 .  mem[3] = 3 + 0 = 3 
// .       3 .  0 + 2 + 6 + mem[2] = 10 1 0 . -> t[2] = 0  mem[3] = 1 + 3 = 4

//         4 .  5000 * 5 = 25 2 5  mem[4] = 2 
//         4 .  400 * 40 = 16 1 6  mem[4] = 2 + 1 = 3
//         4 .  30 * 300 = 9  0 9  mem[4] = 3 + 0 = 3 
//         4 .  2 * 9000 = 18 1 8  mem[4] = 3 + 1 = 4 
// .       4 .  5 + 6 + 9 + 8 + mem[3] = 32 3 2 . -> t[3] = 2  mem[4] = 4 + 3 = 7 

//         5 .  0 * 5 = 0   mem[5] = 0 
//         5 .  5000 * 40 = 20 2 0  mem[5] = 2 
//         5 .  400 * 300 = 12 1 2  mem[5] = 2 + 1 = 3
//         5 .  30 * 9000 = 27 2 7  mem[5] = 3 + 2 = 5 
//         5 .  2 * 40000 = 18 0 8  mem[5] = 5 + 0 = 5 
// .       5 .  0+2+7+8 + mem[4] = 24 2 4 . -> t[3] = 4  mem[5] = 5 + 2 = 7 

// n * m   i //  149345 * 5432 
//         6 .  0 * 5 = 0   mem[6] = 0 
//         6 .  0 * 40 = 0 0  mem[6] = 0 
//         6 .  5000 * 300 = 15   mem[6] = 1 
//         6 .  400 * 9000 = 36   mem[6] = 4 
//         6 .  30 * 40000 = 12   mem[6] = 5 
//         6 .  2 * 100000 = 02   mem[6] = 5 
// .       6 .  5+6+2+2+ mem[5] = 22  -> t[4] = 2  mem[6] = 5 + 2 = 7 

// n * m   i //  149345 * 5432 
//         7 .  0 * 5 = 0   mem[6] = 0 
//         7 .  0 * 40 = 0 0  mem[6] = 0 
//         7 .  0 * 300 = 0   mem[6] = 1 
//         7 .  5000 * 9000 = 45   mem[6] = 4 
//         7 .  400 * 40000 = 16   mem[6] = 5 
//         7 .  30 * 100000 = 03   mem[6] = 5 
// .       7 .  ...+ mem[6] = 21  -> t[5] = 1  mem[7] = 5 + 2 = 7 
//         7 .  0 * 5 = 0   mem[6] = 0 

//         8 .  0 * 9000 = 0   mem[6] = 1 
//         8 .  5000 * 40000 = 20   mem[6] = 4 
//         8 .  400 * 100000 = 04   mem[6] = 5 
// .       8 .  ...+ mem[7] = 11  -> t[6] = 1  mem[8] = 3 

//         9 .  5000 * 100000 = 05   mem[6] = 5 
// .       9 .  ...+ mem[8] = 8  -> t[6] = 8  mem[9] = 0 

auto multiple(const TVInt& v1, const TVInt& v2) {
    TVInt t, t_mem;
    show(v1);
    show(v2);
    t.resize(v1.size() + v2.size(), 0);
    t_mem.resize(v1.size() + v2.size(), 0);
    size_t i = 0;
    for (; i < v1.size() + v2.size(); ++i)
    {
        for (size_t j = 0; j <= i; ++j)
        {
            TNumber t_num = (j < v1.size() ? v1[j] : 0) * ((i-j) < v2.size() ? v2[i - j] : 0);
            t[i] += t_num;

            cout << "calc i=" << i << " j=" << j << " =" << t_num << " t[i] = " << t[i] << " v1=" << v1[j] << " v2=" << v2[i-j] << endl; 
        }
        t[i] += t_mem[i];
        t_mem[i + 1] = t[i] / 10;
        t[i] = t[i] % 10;

        cout << "finish: " << t[i] << " t_mem = " << t_mem[i+1] << " " << endl;
    }
    for (; i < t_mem.size(); ++i) {
        cout << "t_mem " << t_mem[i] << endl; 
    }
    cout << t.size() << endl;
    cout << endl;
    return move(t); 
}

auto multiple(const string& str1, const string &str2) {
    cout << "Long num is 1: " << str1 << endl;
    vector<int> v_num1;
    str_to_vec(v_num1, str1);
    for (auto it : v_num1)
        cout << it << "-";
    cout << endl;
    cout << "Long num is 2: " << str2 << endl;
    vector<int> v_num2;
    str_to_vec(v_num2, str2);
    for (auto it : v_num2)
        cout << it << "-";
    cout << endl;
    return multiple(v_num1, v_num2);
}



int main() {
    // todo aggrement that input data is correct
    fstream file("input.txt");
    if (file.is_open())
    {
        cout << "File is open" << endl;
        long int num = 0;
        string str;
        file >> str;
        cout << "Long num is 1: " << str << endl;
        vector<int> v_num1;
        str_to_vec(v_num1, str);
        for (auto it: v_num1) cout << it << "-";
        cout << endl;
        file >> str;
        cout << "Long num is 2: " << str << endl;
        vector<int> v_num2;
        str_to_vec(v_num2, str);
        for (auto it: v_num2) cout << it << "-";
        cout << endl;

        for (auto it: add(v_num1, v_num2)) cout << it << "-";
        cout << endl;
        for (auto it: diff(v_num1, v_num2)) cout << it << "-";
        cout << endl;
        string str1 = "12345";
        string str2 = "22222222";
        // show(diff(str1, str2));
        BigNumber bn1(str1);
        bn1.show();
        BigNumber bn2(str2);
        bn2.show();
        BigNumber bn = bn1 + bn2;
        bn.show();
        bn = bn1 - bn2;
        bn.show();
        cout << 12345 - 22222222 << endl;
        cout <<  22222222 - 12345 << endl;
        // cout << "Multiple test " << endl;
        bn = BigNumber("999999") * BigNumber("999999");
        cout << "BigN: ";
        bn.show();

        cout <<"Real: " << (long)999999 * (long)999999 << endl;
        // show(multiple("123", "321"));
        // show(multiple("999999", "999999"));
        // show(multiple(v_num1, v_num2));
        file.close();
    }
    else cout << "Unable to open input.txt file. Please create";
    return 0;
}