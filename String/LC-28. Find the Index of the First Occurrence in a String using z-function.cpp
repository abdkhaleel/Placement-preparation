class Solution {
public:
    vector<int> calculateZ(string s){
        int n = s.size();
        vector<int> z(n, 0);
        int left = 0, right = 0;
        for(int k = 1; k < n; k++){
            if(k > right){
                right = left = k;
                while(right < n && s[right] == s[right - left]){
                    right++;
                }
                z[k] = right - left;
                right--;
            }
            else{
                int k1 = k - left;
                if(z[k1] < right - k + 1){
                    z[k] = z[k1];
                }
                else{
                    left = k;
                    while(right < n && s[right] == s[right - left]){
                        right++;
                    }
                    z[k] = right - left;
                    right--;
                }
            }
        }
        return z;
    }
    int strStr(string haystack, string needle) {
        string s = needle + "$" + haystack;
        int k = needle.size();
        vector<int> z = calculateZ(s);
        int n = z.size();
        for(int i = 1; i < n; i++){
            if(z[i] == k) return i - k - 1;
        }
        return -1;
    }
};