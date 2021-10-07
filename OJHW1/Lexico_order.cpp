#include<vector>
#include<string>
#include<iostream>
using namespace std;

long long factorial(int n){
    long long fact = 1;
    for (int i=1;i<n;i++){
        fact = fact*i;
    }
    return fact;
}
vector<int> findKthPermutation(int n, int k){
    long long fact = factorial(n);
    vector<int> numbersArray;
    vector<int> output;
    for (int i=0;i<n;i++){
        numbersArray.push_back(i+1);
    }
    k=k-1;
    while(numbersArray.size()>0){
         output.push_back(numbersArray[k/fact]);
        numbersArray.erase(numbersArray.begin()+k/fact);
        k=k%fact;
        if(numbersArray.size()!=0)
            fact = fact/numbersArray.size();
    }
    return output;
    
}

int countSmaller(vector<int> permutation,int position){
    if(position ==0)
        return permutation[position]-1;
    if(permutation[position]==1)
        return 0;
    int count =0;
    for(int i=0;i<position;i++){
        if(permutation[i]<permutation[position])
            count++;      
    } 

    return permutation[position]-count-1;
}

int findPermutation(vector<int> permutation,int n){
    int rank=0;
    int count=0;
    for(int i=0;i<n;i++){
        count=countSmaller(permutation,i);
        int shuffle = factorial(n-i);
        rank = rank+count*shuffle;
        cout<<"count"<< count <<"shuffle" <<shuffle <<endl;
    }
    cout <<rank;
    return rank+1;
}
int main(){
    int n;
    long a;
    cin >> n >> a;
    int input;
    vector <int> permutation;
    for(int i=0;i<n;i++){
        cin >> input;
        permutation.push_back(input);
    }

    int r= findPermutation(permutation,n);

    vector <int> output = findKthPermutation(n,r+a);
    for(int digit : output){
        cout << digit << ' ';
    }
    
    return 0;
}