#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// input data 2 big num
// need add, diff, multiple

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
        vector<int8_t> num1;
        for (const char ch: str) {
            num1.push_back(atoi(&ch));
        }
        for (auto it: num1) cout << it << "-";
        cout << endl;
        file >> str;
        vector<int8_t> num2;
        for (const char ch: str) {
            num2.push_back(atoi(&ch));
        }
        for (auto it: num2) cout << it << "-";
        cout << endl;
        cout << "Long num is 2: " << str << endl;
        // file >> nums;
        // cout << "Long num is 1: " << nums << endl;
        // file >> nums;
        // cout << "Long num is 2: " << nums << endl;
        file.close();
    }
    else cout << "Unable to open input.txt file. Please create";
    return 0;
}