class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty()) return "";
        int n = s.size();
        long long prefix = 0;
        long long suffix = 0;
        int base = 29;
        int mod = 1e9 + 7;
        long long power = 1;
        int last_index = 0;

        for(int i = 0; i < n; i++){
            int ch = s[i] - 'a' + 1;
            prefix = (prefix * base) % mod;
            prefix = (prefix + ch) % mod;
            suffix = (suffix + ch * power) % mod;
            power = (power * base) % mod;

            if(prefix == suffix) last_index = i;
        }
        string suf = s.substr(last_index + 1);
        reverse(suf.begin(), suf.end());
        return suf + s;
    }
};