class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        int val;
        for(int i=0; i < n; i++){
            val = nums[i];
            int sum = 0;
            while(val != 0){
                sum += val%10;
                val = val/10;
            }
            if(sum == i){
                ans = i;
                break;
            }
        }
        return ans;
    }
};