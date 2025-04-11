class Solution {
    public:
      int findPlatform(vector<int>& arr, vector<int>& dep) {
          int n = arr.size();
          sort(arr.begin(), arr.end());
          sort(dep.begin(), dep.end());
          int i = 0, j = 0;
          int reserved_stations = 0;
          int used_stations = 0;
          while(i < n){
              if(arr[i] <= dep[j]){
                  i++;
                  reserved_stations++;
              }
              else{
                  j++;
                  reserved_stations--;
              }
              used_stations = max(used_stations, reserved_stations);
          }
          return used_stations;
      }
  };