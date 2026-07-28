class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_can = INT_MIN;
        vector<bool> ans;
        for(int num : candies){
            max_can = max(max_can,num);
        }

        for(int i = 0; i<candies.size() ; i++){
            if(candies[i]+extraCandies >= max_can){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};