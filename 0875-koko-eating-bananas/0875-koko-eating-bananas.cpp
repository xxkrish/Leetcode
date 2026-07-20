class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = INT_MIN;
        for(int i=0; i<piles.size(); i++){
            r = max(piles[i], r);
        }
        int ans = r;

        while(l<=r){
            int mid = l + (r-l)/2;
            long long actHr = 0;
            for(int &x: piles){
                int hrs = x/mid;

                if(x%mid != 0){
                    hrs++;
                }
                actHr += hrs;
            }

            if(actHr <= h){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;

    }
};