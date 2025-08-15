class SegmentTree{
private:
    vector<int> tree;
    int size;
public:
    SegmentTree(int size){
        this->size = size;
        tree.resize(4*size, 0);
    }
    int query(int i, int j, int pos, int l, int r){
        if(i > r || j < l) return 0;
        if(i <= l && j >= r) return tree[pos];
        int mid = (l + r) / 2;
        return max(query(i, j, 2*pos+1, l, mid), query(i, j, 2*pos+2, mid+1, r));
    }
    void update(int idx, int val, int pos, int l, int r){
        if(l == r){
            tree[pos] = max(tree[pos], val);
            return;
        }
        int mid = (l + r) / 2;
        if(idx <= mid) update(idx, val, 2*pos+1, l, mid);
        else update(idx, val, 2*pos+2, mid+1, r);
        tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        SegmentTree* seg = new SegmentTree(maxVal);
        int ans = 0;
        for(int num: nums){
            int left = max(1, num - k);
            int best = seg->query(left, num-1, 0, 1, maxVal);
            int curr = best + 1;
            seg->update(num, curr, 0, 1, maxVal);
            ans = max(ans, curr);
        }
        return ans;
    }
};