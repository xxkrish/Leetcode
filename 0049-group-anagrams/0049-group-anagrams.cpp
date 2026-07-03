class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        vector<vector<string>> ans;

        for(string &s: strs){
            string sSorted = s;
            sort(sSorted.begin(), sSorted.end());
            mp[sSorted].push_back(s);
        }

        for(auto &val: mp){
            ans.push_back(val.second);
        }

        return ans;
    }
};