#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; 
        int left = low;      
        int right = mid + 1;   

        
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

       
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return 0;
        int mid = (low + high) / 2 ;
        int count = mergeSort(arr, low, mid);  
        count += mergeSort(arr, mid + 1, high); 
        count += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);  
        return count;
    }

    int countPairs(vector<int>& arr, int low, int mid, int high){
        int right = mid+1;
        int count = 0;
        for(int i = low; i <= mid; i++){
            while(right <= high && arr[i]  > 2L*arr[right]) right++;
            count += (right - (mid + 1));
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int count = mergeSort(nums, 0, nums.size()-1);
        return count;
    }
};