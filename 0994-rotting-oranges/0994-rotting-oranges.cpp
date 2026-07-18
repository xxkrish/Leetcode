class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue <pair<pair<int, int>, int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                }
            }
        }

        int ans=0;

        while(q.size()>0){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;

            ans = max(ans, time);

            q.pop();

            if(i-1 >=0  && grid[i-1][j] == 1){ //top
                grid[i-1][j] = 2;
                q.push({{i-1, j}, time+1});
            }

            if(j+1 < n && grid[i][j+1] == 1){ //right
                grid[i][j+1] = 2;
                q.push({{i, j+1}, time+1});
            }

            if(i+1 < m && grid[i+1][j] == 1){ //down
                grid[i+1][j] = 2;
                q.push({{i+1, j}, time+1});
            }

            if(j-1 >= 0 && grid[i][j-1] == 1){ //left
                grid[i][j-1] = 2;
                q.push({{i, j-1}, time+1});
            }

        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return ans;

    }
};