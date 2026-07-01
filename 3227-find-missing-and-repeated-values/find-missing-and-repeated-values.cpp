class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;
        vector<int> ans;

        int n = grid.size() * grid[0].size();
        int total_sum = 0;
        int real_sum = (n*(n+1))/2;

        for(int i = 0; i< grid.size() ; i++){
            for(int j = 0 ; j<grid[0].size() ; j++){
                int num = grid[i][j];
                mp[num]++;
                total_sum += num;
                if(mp[num] > 1){
                    ans.push_back(num);
                }
            }   
        }
        int value = (real_sum - total_sum)+ (ans.at(0)) ;// 
        ans.push_back(value);
        return ans;
    }
};