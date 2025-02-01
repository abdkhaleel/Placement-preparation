#include <bits/stdc++.h>
using namespace std;
vector<int> repeatedNumber(const vector<int> &A) {
    long long n = A.size();
    long long sumN = (n * (n + 1)) / 2;
    long long sumNSquare = (n * (n + 1) * (2 * n + 1)) / 6;
    
    long long actualSum = 0;
    long long actualSumSquare = 0;
    
    for(int num : A) {
        actualSum += num;
        actualSumSquare += (long long)num * num;
    }
    
    
    long long diff1 = actualSum - sumN;       
    long long diff2 = actualSumSquare - sumNSquare;  
    long long sum = diff2/diff1;  
    
    int x = (diff1 + sum)/2;  
    int y = (sum - diff1)/2;  
    
    return {x, y};
}
