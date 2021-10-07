#define CONSTANT 1000000007
#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin >> n >>k;
    if(k>n-k)
        k = n-k;
    if(k>n)
        cout << 0;
    long long multiplier =1; 
    long long denominator=1;
    for(int i=1;i<=k;i++){
        multiplier =(multiplier % CONSTANT)* ((n+1-i)%CONSTANT);
        denominator = (denominator%CONSTANT)*  (i%CONSTANT);
    }
    
    cout << (multiplier/denominator)%CONSTANT;
    return 0;
}