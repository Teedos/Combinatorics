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
vector<int> fillVector(int n){
    vector<int> numbersArray;
    for (int i=0;i<n;i++){
        numbersArray.push_back(i+1);
    }
    return numbersArray;
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
    //vector<int> numbersArray = fillVector(n);
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
    /*int n;
    int a;
    cin >> n >> a;*/
    vector<int> permutation;
    permutation.push_back(3);
    permutation.push_back(5);
    permutation.push_back(1);
    permutation.push_back(4);
    permutation.push_back(2);
    int r= findPermutation(permutation,5);

    vector <int> output = findKthPermutation(5,r+2);
    for(int digit : output){
        cout << digit << ' ';
    }
    
    return 0;
}