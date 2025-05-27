#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<long long> arr(n+1, 0), arrSorted(n+1,0);
    for(int i = 1; i <= n; i++) cin>>arr[i];
    arrSorted = arr;
    sort(arrSorted.begin(), arrSorted.end());

    vector<long long> pref1(n+1, 0), pref2(n+1, 0);

    for(int i = 1; i <= n; i++){
        pref1[i] = pref1[i-1] + arr[i];
        pref2[i] = pref2[i-1] + arrSorted[i];
    }
    int times;
    cin>>times;

    while(times){
        int ch, l, r;
        long long sum;
        cin>>ch>>l>>r;
        switch (ch)
        {
            case 1:
                sum = pref1[r] - pref1[l-1];
                break;
            
            default:
                sum = pref2[r] - pref2[l-1];
                break;
        }
        cout<<sum<<endl;
        times--;
    }
    return 0;
}