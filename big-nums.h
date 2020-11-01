#pragma once
#include <string>
#include <vector>

// input data 2 big num
// need add, diff, multiple
// the sign for the number is ignored

using std::string;
using TNumber = int;
using TVInt = std::vector<TNumber>;
class BigNumber
{
private:
    /* data */
    // enum sign {positive, negative};
    TVInt v;
    void str_to_vec(TVInt &v, const string &s);

public:
    BigNumber(){};
    BigNumber(const string &s);
    BigNumber(const TVInt &v) { this->v = v; }
    BigNumber(const BigNumber &bn) {this->v = bn.v;}
    // BigNumber(const BigNumber &&bn) {this->v = std::move(bn.v);}
    void show() const;
    BigNumber operator+(const BigNumber &bn) const;
    BigNumber operator-(const BigNumber &bn) const;
    BigNumber operator*(const BigNumber &bn) const;
    // BigNumber operator/(const BigNumber &_v) const;
    // BigNumber operator%(const BigNumber &_v) const;
    bool operator==(const BigNumber &bn) const;
    bool operator!=(const BigNumber &bn) const;
    ~BigNumber() {}
};

BigNumber::BigNumber(const string &s)
{
    this->str_to_vec(v, s);
}

void BigNumber::str_to_vec(TVInt &v, const string &s)
{
    for (auto it = s.rbegin(); it != s.rend(); ++it)
    {
        char c = *it;
        v.push_back(atoi(&c));
    }
}

void BigNumber::show() const
{
    for (auto it = v.rbegin(); it != v.rend(); ++it)
    {
        std::cout << *it;
    }
    std::cout << std::endl;
}

BigNumber BigNumber::operator+(const BigNumber &r_bn) const
{
    BigNumber t;
    t.v.resize(this->v.size() > r_bn.v.size() ? this->v.size() : r_bn.v.size(), 0);
    TNumber mem = 0;
    for (size_t i = 0; i < this->v.size() || i < r_bn.v.size(); ++i)
    {
        // t[i] = (i < v1.size() ? (true ? v1[i] : -v1[i]) : 0) + (i < v2.size() ? (true ? v2[i] : -v2[i]) : 0);
        t.v[i] = (i < this->v.size() ? this->v[i] : 0) + (i < r_bn.v.size() ? r_bn.v[i] : 0) + mem;
        mem = t.v[i] / 10;
        t.v[i] = t.v[i] % 10;
    }
    return std::move(t);
}

BigNumber BigNumber::operator-(const BigNumber &r_bn) const
{
    TVInt t;
    t.resize(this->v.size() > r_bn.v.size() ? this->v.size() : r_bn.v.size(), 0);
    auto diff = [&](const TVInt &v1, const TVInt &v2) {
        TNumber mem = 0;
        for (size_t i = 0; i < v1.size(); ++i)
        {
            t[i] = (i < v1.size() ? v1[i] : 0) - (i < v2.size() ? v2[i] : 0) + mem;
            if (t[i] < 0)
            {
                t[i] = 10 + t[i];
                mem = -1;
            }
            else
            {
                mem = 0;
            }
        }
        std::cout << t.size() << std::endl;
    };

    if (this->v.size() > r_bn.v.size())
        diff(this->v, r_bn.v);
    else
        diff(r_bn.v, this->v);
    return BigNumber(t);
}

BigNumber BigNumber::operator*(const BigNumber &r_bn) const 
{
    TVInt t, t_mem;
    t.resize(this->v.size() + r_bn.v.size(), 0);
    t_mem.resize(this->v.size() + r_bn.v.size(), 0);
    size_t i = 0;
    for (; i < this->v.size() + r_bn.v.size(); ++i)
    {
        for (size_t j = 0; j <= i; ++j)
        {
            TNumber t_num = (j < this->v.size() ? this->v[j] : 0) * ((i-j) < r_bn.v.size() ? r_bn.v[i - j] : 0);
            t[i] += t_num;
        }
        t[i] += t_mem[i];
        t_mem[i + 1] = t[i] / 10;
        t[i] = t[i] % 10;
    }
    return BigNumber(t);
}

bool BigNumber::operator==(const BigNumber &bn) const {
    if (v.size() != bn.v.size())
        return false;
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (v[i] != bn.v[i])
            return false;
    }
    
    return true;
}

bool BigNumber::operator!=(const BigNumber &bn) const {
    return !(*this == bn); 
}