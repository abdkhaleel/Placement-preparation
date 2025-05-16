class Solution {
public:
    string rle(string s){
        string res = "";
        for(int i = 0; i < s.size(); i++){
            int count = 1;
            while(i < s.size()-1 && s[i] == s[i+1]){
                i++;
                count++;
            }

            res += to_string(count) + s[i];
        }
        return res;
    }
    string countAndSay(int n) {
        if(n == 1) return "1";
        string res = rle("1");
        for(int i = 2; i < n; i++) res = rle(res);
        return res;
    }
};