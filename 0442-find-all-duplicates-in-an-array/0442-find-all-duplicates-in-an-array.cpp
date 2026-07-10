class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            int value = abs(nums[i]);
            int idx = value-1;

            if(nums[idx]>0){
                nums[idx] = -nums[idx];
            }else {
                ans.push_back(value);
            }
        }

        return ans;
    }
};