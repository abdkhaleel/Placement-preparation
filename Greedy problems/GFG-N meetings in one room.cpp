class Solution {
    public:
      int maxMeetings(vector<int>& start, vector<int>& end) {
          int count = 0;
          vector<pair<int, int>> arr;
          for(int i = 0; i < end.size(); i++) arr.push_back(make_pair(end[i], start[i]));
          sort(arr.begin(), arr.end());
          int end_time = -1;
          for(int i = 0; i < arr.size(); i++){
              if(arr[i].second > end_time){
                  count++;
                  end_time = arr[i].first;
              } 
          }
          return count;
      }
  };