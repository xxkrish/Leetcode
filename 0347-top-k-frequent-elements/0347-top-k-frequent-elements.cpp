class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int &x: nums){
            mp[x]++;
        }

        vector<vector<int>> bucket(n+1);

        for(auto &val: mp){
            bucket[val.second].push_back(val.first);
        }

        vector<int> ans;

        for(int i=n; i>=1; i--){
            for(auto &p: bucket[i]){
                ans.push_back(p);
                if(ans.size() == k){
                    return ans;
                }
            }
        }

        return ans;
    }
};