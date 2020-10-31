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

auto sum(TVInt v1, TVInt v2) {
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
    // cout << "Data - " << endl;
    // for (size_t i = 0; i < t.size(); i++) {
    //     t[i] = v1[i] + v2[i];
    //     cout << t[i];
    // }
    cout << endl;
    return move(t); 
}

void str_to_vec(TVInt& v, const string &s) {
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            char c = *it;
            cout << c;
            v.push_back(atoi(&c));
        }
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

        for (auto it: sum(v_num1, v_num2)) cout << it << "-";
        cout << endl;
        // file >> nums;
        // cout << "Long num is 1: " << nums << endl;
        // file >> nums;
        // cout << "Long num is 2: " << nums << endl;
        file.close();
    }
    else cout << "Unable to open input.txt file. Please create";
    return 0;
}