class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r= 0, jump = 0 , n = nums.size();
        while(r < n-1){
            int max_val = INT_MIN;
            for(int i = l ; i<=r ; i++){
                max_val = max(max_val,i+nums[i]);
            }
            jump++;
            l = r+1;
            r= max_val;
        }
        return jump;
    }
};