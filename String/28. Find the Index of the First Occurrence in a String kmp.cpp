class Solution {
public:
    vector<int> calculateLPS(string s){
        int n = s.size();
        vector<int> lps(n, 0);
        int i = 1, prevLps = 0;
        while(i < n){
            if(s[i] == s[prevLps]){
                lps[i] = prevLps + 1;
                i++;
                prevLps++;
            }
            else if(prevLps == 0){
                lps[i] = 0;
                i++;
            }
            else{
                prevLps = lps[prevLps-1];
            }
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        vector<int> lps = calculateLPS(needle);
        int i = 0, j = 0;
        int n = haystack.size(), m = needle.size();
        while(i < n){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            else if(j == 0){
                i++;
            }
            else{
                j = lps[j-1];
            }
            
            if(j == m) return i - m;
        }
        return -1;
    }
};