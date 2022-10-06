#include<iostream>
#include<vector>
#include<string>
#include"BigInt.h"
using std::vector;
using std::string;
using std::cout;
using std::endl;
BigInt::BigInt(){
}
//constructor 1
BigInt::BigInt(vector<int> &bigint1){

    sign=true;
    int index = removezeros(bigint1,sign);
    bigint = checkvalidation(bigint1,sign,index);

}

//constructor 2
BigInt::BigInt(vector<char> &bigchar){
    //convert char in the form of vector
    vector<int> vector3;
    int size=bigchar.size();
    int index=0;
    bool sign1 = true;
    bool error = false;
    while(index<size){
        if(bigchar.at(index) == '-'){
            if (!sign1) {
                std::cerr<< "invalid input c2" <<endl;
                error = true;
                break;
            }
            sign1= false;
        } else {
            if(bigchar.at(index)<='0' && bigchar.at(index)>='9'){
                std::cerr<< "invalid input c2" <<endl;
                error = true;
                break;
            }
            int num = bigchar.at(index);
            num = num -'0';
            if(!sign1) {
                if(bigchar.at(index) >'0' && bigchar.at(index)<='9'){
                    num = num * -1;
                    sign1 = true;
                }
            }
            vector3.push_back(num);
        }
        index++;
    }

    if (error) {
        vector3.clear();
    }

    //call the vector    
    sign1=true;
    int index1 = removezeros(vector3,sign1);
    sign = sign1;
    bigint = checkvalidation(vector3,sign1,index1);

}


//constructor 3
BigInt::BigInt(char a[] , int size1){

    vector<int> vector3;
    int size=size1;
    int index=0;
    bool sign1 = true;
    bool error = false;
    while(index<size){
        if(a[index] == '-'){
            if (!sign1) {
                std::cerr<< "invalid input c2" <<endl;
                error = true;
                break;
            }
            sign1= false;
        } else {
            if(a[index]<='0' && a[index]>='9'){
                std::cerr<< "invalid input c2" <<endl;
                error = true;
                break;
            }
            int num = a[index];
            num = num -'0';
            if(!sign1) {
                if(a[index] >'0' && a[index]<='9'){
                    num = num * -1;
                    sign1 = true;
                }
            }
            vector3.push_back(num);
        }
        index++;
    }

    sign1=true;
    if (error) {
        vector3.clear();
    }

    //call the vector    
    int index1 = removezeros(vector3,sign1);
    sign = sign1;

    bigint = checkvalidation(vector3,sign,index1);


}


BigInt BigInt::operator+(BigInt const &B){
        BigInt result;
        
        if (sign && B.sign) {
            result.bigint = add(bigint, B.bigint);
            result.sign = true;
        } else if (!sign && !B.sign) {
            result.bigint = add(bigint, B.bigint);
            result.sign = false;

        } else if (sign && !B.sign) {
            bool res_sign;
            result.bigint = subtract(bigint, B.bigint, res_sign);
            result.sign = res_sign;
        } else {
            bool res_sign;
            result.bigint = subtract(B.bigint, bigint, res_sign);
            result.sign = res_sign;
        }
        return result;	
}




BigInt BigInt::operator-(const BigInt &B){
        BigInt result;
        
        if (sign && B.sign) {
            bool res_sign;
            result.bigint = subtract(bigint, B.bigint, res_sign);
            result.sign = res_sign;
        } else if (!sign && !B.sign) {
            bool res_sign;
            result.bigint = subtract(B.bigint, bigint, res_sign);
            result.sign = res_sign;
        } else if (sign && !B.sign) {
            result.bigint = add(B.bigint, bigint);
            result.sign = true;
        } else {
            result.bigint = add(B.bigint, bigint);
            result.sign = false;
        }
        return result;	
}

BigInt BigInt::operator*(const BigInt &B){

    int carry = 0;
    int shift = 0;
    int size = bigint.size();
    int size1 = B.bigint.size();
    vector<int> sum;

    if(size == 0 ||size1==0){
        BigInt result;
        result.sign = true;
        result.bigint = sum;
        return result;
    }

    for(int j = size-1; j >= 0; j--) //no member size in bigint
    {
        vector<int> vector3;
        for (int i = 0; i < shift; i++) {
            vector3.push_back(0);
        }
        carry = 0;
        for(int i=size1-1; i>=0; i--)
        {
            // bigint with value 0 and size: size + A.size
            int result = bigint[j]*B.bigint[i]+carry;
            int digit1=result%10;
            vector3.push_back(digit1);
            carry = result/10;
        }
        if (carry)
            vector3.push_back(carry);

        vector3 = reverse(vector3);
        sum = add(sum , vector3);
        shift++;
    }

    BigInt result;
    if(sign && !B.sign){
        result.sign = false;
    }
    else if(sign && B.sign){
        result.sign = true;
    } else if(!sign && B.sign){
        result.sign = false;
    } else{
        result.sign = true;
    }
    int index = 0;
    while(sum[index] == 0 && index < sum.size()){
        index++;
    }
    if (index == sum.size()) {
        sum.clear();
        result.sign = true;
    }
    result.bigint = sum;
    return result;
}

bool BigInt::operator!(){
    if (bigint.size() > 0) {
        return false;
    } else { 
        return true;
    }
}

bool BigInt::operator==(const BigInt &B){
    int size= bigint.size();
    int size1=B.bigint.size();
    if(sign && !B.sign){
        return false;
    }
    else if(sign && B.sign){
        if(size==size1){
            for (int i=0 ; i<size;i++){
                if(bigint.at(i) > B.bigint.at(i) ){
                    return false;
                } else if (bigint.at(i) < B.bigint.at(i) ){
                    return false;
                }
            }
            return true;
        } else if(size<size1){
            return false;
        } else{
            return false;
        }
    } else if(!sign && B.sign){
        return false;
    } else{
        if(size==size1){
            for (int i=0 ; i<size;i++){
                if(bigint.at(i) > B.bigint.at(i) ){
                    return false;
                } else if(bigint.at(i) < B.bigint.at(i) ){
                    return false;
                }
            }
            return true;
        } else if(size<size1){
            return false;
        } else{
            return false;
        }
    }
   
}
bool BigInt::operator>=(const BigInt &B){
    int size= bigint.size();
    int size1=B.bigint.size();
    if(sign && !B.sign){
        return true;
    }
    else if(sign && B.sign){
        if(size==size1){
            for (int i=0 ; i<size;i++){
                if(bigint.at(i) > B.bigint.at(i) ){
                    return true;
                } else if (bigint.at(i) < B.bigint.at(i) ){
                    return false;
                }
            }
            return true;
        } else if(size<size1){
            return false;
        } else{
            return true;
        }
    } else if(!sign && B.sign){
        return false;
    } else{
        if(size==size1){
            for (int i=0 ; i<size;i++){
                if(bigint.at(i) > B.bigint.at(i) ){
                    return false;
                } else if(bigint.at(i) < B.bigint.at(i) ){
                    return true;
                }
            }
            return true;
        } else if(size<size1){
            return true;
        } else{
            return false;
        }
    }
}

bool BigInt::operator>(const BigInt &B) {
    int size= bigint.size();
    int size1=B.bigint.size();
    if(sign && !B.sign){
        return true;
    }
    else if(sign && B.sign){
        if(size==size1){
            for (int i=0 ; i<size;i++){
                if(bigint.at(i) > B.bigint.at(i) ){
                    return true;
                } else if (bigint.at(i) < B.bigint.at(i) ){
                    return false;
                }
            }
            return false;
        } else if(size<size1){
            return false;
        } else{
            return true;
        }
    } else if(!sign && B.sign){
        return false;
    } else{
        if(size==size1){
            for (int i=0 ; i<size;i++){
                if(bigint.at(i) > B.bigint.at(i) ){
                    return false;
                } else if(bigint.at(i) < B.bigint.at(i) ){
                    return true;
                }
            }
            return false;
        } else if(size<size1){
            return true;
        } else{
            return false;
        }
    }
}


bool BigInt::operator<=(const BigInt &B){
    int size= bigint.size();
    int size1=B.bigint.size();
    if(sign && !B.sign){
        return false;
    }
    else if(sign && B.sign){
        if(size==size1){
            for (int i=0 ; i<size;i++){
                if(bigint.at(i) > B.bigint.at(i) ){
                    return false;
                } else if (bigint.at(i) < B.bigint.at(i) ){
                    return true;
                }
            }
            return true;
        } else if(size<size1){
            return true;
        } else{
            return false;
        }
    } else if(!sign && B.sign){
        return true;
    } else{
        if(size==size1){
            for (int i=0 ; i<size;i++){
                if(bigint.at(i) > B.bigint.at(i) ){
                    return true;
                } else if(bigint.at(i) < B.bigint.at(i) ){
                    return false;
                }
            }
            return true;
        } else if(size<size1){
            return false;
        } else{
            return true;
        }
    }
}

bool BigInt::operator<(const BigInt &B){

    int size= bigint.size();
    int size1=B.bigint.size();
    if(sign && !B.sign){
        return false;
    }
    else if(sign && B.sign){
        if(size==size1){
            for (int i=0 ; i<size1;i++){
                if(bigint.at(i) > B.bigint.at(i) ){
                    return false;
                } else if (bigint.at(i) < B.bigint.at(i) ){
                    return true;
                }
            }
            return false;
        } else if(size<size1){
            return true;
        } else{
            return false;
        }
    } else if(!sign && B.sign){
        return true;
    } else{
        if(size==size1){
            for (int i=0 ; i<size1;i++){
                if(bigint.at(i) > B.bigint.at(i) ){
                    return true;
                } else if (bigint.at(i) < B.bigint.at(i)){
                    return false;
                }
            }
            return false;
        } else if(size<size1){
         return false;
        } else{
            return true;
        }
    }
}

BigInt BigInt::operator++(){
    vector<int> temp{1};
    BigInt result;
    if (sign) {
        result.bigint = add(bigint, temp);
        result.sign = true;
        bigint = result.bigint;
    } else {
        bool res_sign;
        result.bigint = subtract(bigint, temp, res_sign);
        result.sign = res_sign;
        if (result.bigint.size() == 0) {
            result.sign = true;
        }
        bigint = result.bigint;
        sign = result.sign;
    }
    return result;	
}



BigInt  BigInt::operator++(int){
    vector<int> temp{1};
    BigInt result;
    result.bigint = bigint;
    result.sign = sign;
    if (sign) {
        bigint = add(bigint, temp);
        sign = true;
    } else {
        bool res_sign;
        bigint = subtract(bigint, temp, res_sign);
        sign = res_sign;
        if (bigint.size() == 0) {
            sign = true;
        }
    }
    return result;	
}

BigInt BigInt::operator--(){
    vector<int> temp{1};
    BigInt result;
    if (sign) {
        bool res_sign;
        result.bigint = subtract(bigint, temp, res_sign);
        result.sign = res_sign;
        if (result.bigint.size() == 0) {
            result.sign = true;
        }
        sign = result.sign;
        bigint = result.bigint;
    } else {
        result.bigint = add(bigint, temp);
        result.sign = false;
        bigint = result.bigint;
        sign = result.sign;
    }
    return result;	
}
BigInt BigInt::operator--(int){
    vector<int> temp{1};
    BigInt result;
    result.bigint = bigint;
    result.sign = sign;
    if (sign) {
        bool res_sign;
        bigint = subtract(bigint, temp, res_sign);
        sign = res_sign;
        if (bigint.size() == 0) {
            sign = true;
        }
    } else {
        bigint = add(bigint, temp);
        sign = false;
    }
    return result;	
}

std::ostream &operator<<(std::ostream &out, const BigInt &B){
    if (!B.sign) {
        out << '-';
    } 
    if (!B.bigint.size()) {
        out << '0';
    }
    for (int i = 0; i < B.bigint.size(); i++) {
        out << B.bigint[i];
    }
    return out;

}
std::istream &operator>>(std::istream &in, BigInt &B){
    std::string a;
    B.bigint.clear();
    in >> a;
    int index = 0;
    bool sign1 = true;
    int count = 0;
    int size= a.length();
    // Removing starting 0s and sign
    vector<int> vector3;
    bool error = false;
    while(index<size){
        if(a[index] == '-'){
            if (!sign1) {
                std::cerr<< "invalid input c2" <<endl;
                error = true;
                break;
            }
            sign1= false;
        } else {
            if(a[index]<='0' && a[index]>='9'){
                std::cerr<< "invalid input c2" <<endl;
                error = true;
                break;
            }
            int num = a[index];
            num = num -'0';
            if(!sign1) {
                if(a[index] >'0' && a[index]<='9'){
                    num = num * -1;
                    sign1 = true;
                }
            }
            vector3.push_back(num);
        }
        index++;
    }

    if (error) {
        vector3.clear();
    }

    //call the vector    
    int index1 = B.removezeros(vector3,sign1);

    B.sign= sign1;
    B.bigint = B.checkvalidation(vector3,sign1,index1);
    
    return in;
}

vector<int>
BigInt::subtract(vector<int> const& vector1, vector<int> const& vector2, bool &res_sign) {
    int size_vec1=vector1.size();
    int size_vec2=vector2.size();
    vector<int> vector3;
    bool vec1greater= false;
    if(size_vec1==size_vec2){
        bool equal = true;
        for (int i=0 ; i<size_vec1;i++){
            if(vector1.at(i) > vector2.at(i) ){
                vec1greater = true;
                equal = false;
                break;
            } else if (vector1.at(i) < vector2.at(i) ){
                equal = false;
                vec1greater = false;
                break;
            }
        }
        if (equal) {
            res_sign = true;
            return vector3;
        }
    } else if(size_vec1<size_vec2){
        vec1greater = false;
    } else{
        vec1greater = true;;
    }

    if(vector1.empty()){
        res_sign = false;
        return vector2;
    }
    if(vector2.empty()){
        res_sign = true;
        return vector1;
    }

    if (vec1greater){
        int borrow =0;
        int j = size_vec2 - 1;
        for (int i= (size_vec1-1) ; i >=0; i--){
            int diff;
            if(j >= 0){
                if ((vector1.at(i) - borrow) >= vector2.at(j)) {
                    diff = vector1.at(i)-vector2.at(j) - borrow;
                    borrow = 0;
                } else {
                    diff = 10 + vector1.at(i)-vector2.at(j) - borrow;
                    borrow = 1;
                }
            } else {
                if ((vector1.at(i) - borrow) >= 0) {
                    diff = vector1.at(i) - borrow;
                    borrow = 0;
                } else {
                    diff = 10 + vector1.at(i) - borrow;
                    borrow = 1;
                }
            }
            vector3.push_back(diff);
            j--;
        }
        res_sign = true;
    } else{
        int borrow =0;
        int j = size_vec1 - 1;
        for (int i= (size_vec2-1) ; i >=0; i--){
            int diff;
            if(j >= 0){
                if ((vector2.at(i) - borrow) >= vector1.at(j)) {
                    diff = vector2.at(i)-vector1.at(j) - borrow;
                    borrow = 0;
                } else {
                    diff = 10 + vector2.at(i)-vector1.at(j) - borrow;
                    borrow = 1;
                }
            } else {
                if ((vector2.at(i) - borrow) >= 0) {
                    diff = vector2.at(i) - borrow;
                    borrow = 0;
                } else {
                    diff = 10 + vector2.at(i) - borrow;
                    borrow = 1;
                }
            }
            vector3.push_back(diff);
            j--;
        }
        res_sign = false;
    }
    vector3 = reverse(vector3);
    int index = 0;
    while(vector3[index] == 0 && index < vector3.size()){
        index++;
    }
    if (index == vector3.size()) {
        res_sign = true;
        vector3.clear();
    }
    bool temp = true;
    index = removezeros(vector3, temp);
    vector3 = checkvalidation(vector3, temp, index);
    
    return vector3;
}
vector<int>
BigInt::add(vector<int>const &vector1, vector<int> const &vector2) {
    int size_vec1=vector1.size();
    int size_vec2=vector2.size();
    vector<int> vector3;
    if(vector1.empty()){
        if(vector2.empty()){
            vector3={0};
            return vector3;
        }
        return vector2;
    }

    if (size_vec1>size_vec2 || size_vec1==size_vec2){
        int carry =0;
        int j = size_vec2 - 1;
        for (int i= (size_vec1-1) ; i >=0; i--){
            int sum;
            if(j >= 0){
                sum = vector1.at(i)+vector2.at(j)+carry;
            } else {
                sum = vector1.at(i) + carry;
            }
            int digit1=sum%10;
            vector3.push_back(digit1);
            carry = sum/10;
            j--;
        }
    } else{
        int carry =0;

        int j = size_vec1 - 1;
        for (int i=size_vec2 -1 ; i >=0;i--){
            int sum;
            if(j >= 0){
                sum = vector1.at(j)+vector2.at(i)+carry;
            } else {
                sum = vector2.at(i) + carry;
            }
            int digit1=sum%10;
            vector3.push_back(digit1);
            carry = sum/10;
            j--;
        }
        if (carry) {
            vector3.push_back(carry);
        }

    }
    vector3 = reverse(vector3);
    return vector3;
}

vector<int>
BigInt::reverse(vector<int> const &vector1){
    vector<int> newvector;
    int size= vector1.size();
    for(int i= size - 1; i>=0;i--){
        newvector.push_back(vector1.at(i));
    }

    return newvector;
}

vector<int> BigInt::checkvalidation(vector<int> &bigint1,bool const sign1,int &index){
    bool first = true;
    vector<int> new_vector;
    bool error = false;
    for (int i = index; i < bigint1.size(); i++) {
        int num = bigint1[i];
        if (first) {
            if (!sign1) {
                num = num * -1;
            }
            first = false;
        }
        if (num < 0 || num > 9) {
            std::cerr<<"Invalid input" <<endl;
            error = true;
            break;
        } else {
            new_vector.push_back(num);
        }
    }
    if (error) {
        new_vector.clear();
    }

    return new_vector;
}

int BigInt::removezeros(vector<int> &bigint1,bool &sign1){

    int index = 0;
    sign1 = true;
    int size = bigint1.size();

    if (size > 0) {
        while(index <size && bigint1.at(index) == 0){
            index++;
        }
        if(index < size){
            if (bigint1[index] < 0 && bigint1[index] >= -9) {
                sign1 = false;
            }
        }
        else if (size==index){
            sign1=true;
        }
    } else {
        sign1 = true;
    }

    return index;

}
