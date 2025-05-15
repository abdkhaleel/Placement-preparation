class Solution {
private:
    const int d = 256;
public:
    int repeatedStringMatch(string A, string B) {
        if(A == B) return 1;
        int count = 1;
        string source = A;
        while(source.size() < B.size()){
            count++;
            source+=A;
        }
        if(source == B) return count;
        if(f(source,B) != -1) return count;
        if(f(source+A,B) != -1) return count+1;
        return -1;
    }
    int f(string text,string pattern) {
        int n = text.size();
        int m = pattern.size();
        long long t = 0;
        long long p = 0;
        long long h = 1;
        int i, j;
        int q = 1e9 + 7;

        for(int i = 0; i < m-1; i++){
            h = (h * d) % q;
        }

        for(int i = 0; i < m; i++){
            p = (p * d + pattern[i]) % q;
            t = (t * d + text[i]) % q;
        }

        for(int i = 0; i <= n-m; i++){
            if(p == t){ 
                for (j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j])
                        break;
                    }

                if (j == m) return i;
            }
            if(i < n-m){
                t = (d * (t - text[i] * h) + text[i + m]) % q;

                if (t < 0) t = (t + q);
                
            }
        }

        return -1;
    }
};