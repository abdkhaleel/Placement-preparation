class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            for(char& c: s){
                if(!st.empty()){
                    if(c == ']' && st.top() == '[') {
                        st.pop();
                        continue;
                    }
    
                    else if(c == ')' && st.top() == '(') {
                        st.pop();
                        continue;
                    }
    
                    else if(c == '}' && st.top() == '{') {
                        st.pop();
                        continue;
                    }
                }
                st.push(c);
            }
            return st.empty();
        }
    };