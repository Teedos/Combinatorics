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
    long long result =1;
    for(int i=1;i<=k;i++){
        result =(result % CONSTANT)*1LL* ((n+1-i)%CONSTANT);
        result = result/i;
    }
    
    cout << result%CONSTANT;
    return 0;
}