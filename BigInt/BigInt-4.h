#ifndef BIGINT_H
#define BIGINT_H
#include<iostream>
#include<vector>
#include<string>
using std::string;
using std::vector;
using std::cout;
using std::endl;

class BigInt{
    private:
        vector<int> add(vector<int> const &vector1, vector<int> const&vector2);
        vector<int> reverse(vector<int> const &vector1);
        vector<int> subtract(vector<int> const &vector1,vector<int> const &vector2, bool &res_sign);
    public:
        int removezeros(vector<int> &vector1, bool &sign);
        vector<int>checkvalidation(vector<int> &vector1,bool sign,int &index);
        vector<int> bigint;
        bool sign;
        BigInt(vector<int> &bigint);
        BigInt();
        BigInt(vector<char> &bigchar);
        BigInt(char a[] , int size);
        BigInt operator+(const BigInt &B);
        
        BigInt operator-(const BigInt &B);
        BigInt operator*(const BigInt &B);
        bool  operator!();
        bool operator==(const BigInt &B);
        bool operator>=(const BigInt &B);
        bool operator>(const BigInt &B);
        bool operator<(const BigInt &B);
        bool operator<=(const BigInt &B); 
        BigInt operator++();
        BigInt operator++(int);
        BigInt operator--();
        BigInt operator--(int);
        friend std::ostream &operator<<(std::ostream &out, const BigInt &B);
        friend std::istream &operator>>(std::istream &in, BigInt &B);
};
#endif
