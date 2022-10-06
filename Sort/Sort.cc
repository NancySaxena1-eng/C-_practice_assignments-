
#include <iostream>
#include<algorithm>

using namespace std;
/* function with the integer as paramter*/
void Sort(int a[],int sz){
	if (sz>1){
/*sorting integer in ascending order */
	sort(a, a + sz);
  }
}


/* function with char as parameter */
void Sort(char c[],int sz){
/*Sorting Character in ASCII,So A<a (in ascending order) */
	if(sz>1){
	sort(c, c + sz);
    }
}
