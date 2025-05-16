class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;
        string temp = "";

        for(char&c : version1){
            if(c == '.'){
                v1.push_back(stoi(temp));
                temp = "";
            }
            else{
                temp += c;
            }
        }
        v1.push_back(stoi(temp));

        temp = "";
        for(char&c : version2){
            if(c == '.'){
                v2.push_back(stoi(temp));
                temp = "";
            }
            else{
                temp += c;
            }
        }
        v2.push_back(stoi(temp));
        while(v1.size() > v2.size()) v2.push_back(0);
        while(v2.size() > v1.size()) v1.push_back(0);

        for(int i = 0; i < v1.size(); i++){
            if(v1[i] < v2[i]) return -1;
            else if(v2[i] < v1[i]) return 1;
        }
        return 0;
        
    }
};