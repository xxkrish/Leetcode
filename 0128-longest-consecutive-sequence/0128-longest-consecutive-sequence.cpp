class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if(nums.size() == 1){
            return 1;
        }

        if(nums.size() == 0){
            return 0;
        }

        int count = 1;
        int ans = 1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] == nums[i]) continue;
            int val = nums[i];
            if(nums[i-1] == val-1){
                count++;
            }else{
                count = 1;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};