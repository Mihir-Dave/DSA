class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_Index = 0;
        for(int i = 0; i<nums.size() ; i++){
            if(i > max_Index){
                return false;
            }
            max_Index = max(max_Index,(i)+(nums[i]));
        }
        return true;
    }
};