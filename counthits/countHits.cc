/*Time complexity:O(n^2)
 * Space complexity :O(n)*/
#include<vector>
#include<iostream>
#include"countHits.h"
using std::cout;
using std::endl;
using std::vector;
//using std::stack;
int countHits(vector<Asteroid> a){
    int countHits = 0;
    //Creating a stack space
    vector<int> s1;
    for (int i =0 ;  i < a.size(); i++){
      if (a[i].m<0){
      
      exit(-1);
      
      }
      else{
        if (a[i].d == right && a[i].m > 0) {
            s1.push_back(a[i].m);
        }
        else {

            int j = s1.size();

            while(j > 0) {
                int mass =  s1.at(j-1);
                if (a[i].m > mass){
                    // last element is eliminated
                    s1.pop_back();
                    j-- ;
                } else if(a[i].m < mass){
                    // A[i] is eliminated
                    break;            
                }
                else {
                    // Both are equal
                    s1.pop_back();
                    break;
                }
            }       

        }

    }
}
    countHits = s1.size();
    cout << countHits << endl;
    return countHits;
}



