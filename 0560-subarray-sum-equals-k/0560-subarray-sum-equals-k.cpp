class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefSum(n, 0);
        prefSum[0] = nums[0];

        for(int i=1; i<n; i++){
            prefSum[i]  = prefSum[i-1] + nums[i];
        }

        unordered_map<int, int> mp;
        int ans = 0;

        for(int j=0; j<n; j++){
            if(prefSum[j] == k) ans++;

            int val = prefSum[j] - k;
            if(mp.find(val) != mp.end()){
                ans+= mp[val];
            }
            
            if(mp.find(prefSum[j]) == mp.end()){
                mp[prefSum[j]]=0;
            }
            mp[prefSum[j]]++;
        }

        return ans;
    }
};