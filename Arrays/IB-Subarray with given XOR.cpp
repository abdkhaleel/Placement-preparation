int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> mp;
    int xors = 0;
    mp[xors]++;
    int n = A.size();
    int count = 0;
    for(int i = 0; i < n; i++){
        xors ^= A[i];
        int x = xors ^ B;
        count += mp[x];
        mp[xors]++;
    }
    return count;
}
