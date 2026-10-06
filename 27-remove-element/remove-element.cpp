class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        int n = nums.size();
        if(n == 0) return 0;


        while(nums[j] != val){
            j++;
            if(j == n) return n;
        }
        
       
        for(int m = j ; m< n ; m++){
            if(nums[m] == val){
                continue;
            }else{
                swap(nums[j],nums[m]);
                j++;
            }
        }
        return j;
        
    }
};