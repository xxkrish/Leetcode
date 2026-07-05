class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for(int &x: nums){
            s.insert(x);
        }
        int ans = 0;

        for(int val: s){

            int count = 1;
            if(s.find(val-1) == s.end()){
                int num = val;
                while(s.find(num+1) != s.end()){
                    count++;
                    num++;
                }
            }

            ans = max(ans, count);
        }

        return ans;
    }
};