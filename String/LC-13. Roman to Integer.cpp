class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int res = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(i < n-1 && m[s[i]] < m[s[i+1]]) res -= m[s[i]];
            else res += m[s[i]];
        }
        return res;
    }
};