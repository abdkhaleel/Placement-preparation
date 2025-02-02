#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        long long t = n;
        if(t < 0) t *= -1;
        double ans = 1;
        while(t){
            if(t & 1){
                ans *= x;
                t--;
            }
            else{
                x *= x;
                t /= 2;
            }
        }
        return n < 0? (double)1/ans: ans;
        
    }
};