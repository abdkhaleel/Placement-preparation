class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.size();
        string word;
        for(char& c: s){
            if(c != ' '){
                word += c;
            }
            else if(!word.empty()){
                st.push(word);
                word.clear();
            }
        }
        
        if(!word.empty()) st.push(word);

        string ans = "";
        if(!st.empty()){
            ans += st.top();
            st.pop();
        }
        while(!st.empty()){
            ans += " " + st.top();
            st.pop();
        }
        return ans;
    }
};