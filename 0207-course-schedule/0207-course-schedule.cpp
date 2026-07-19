class Solution {
public:
    bool cycleDetectDFS(int u, list<int> *li, vector<bool> &vis, vector<bool> &recStack, int n){
        vis[u] = true;
        recStack[u] = true;      

        for(int v: li[u]){
            if(!vis[v]){
                if(cycleDetectDFS(v, li, vis, recStack, n)){
                    return true;
                }
            }else if(recStack[v]){
                return true;
            }
        }
        recStack[u] = false;
        return false;
        
    }

    void addEdges(int u, int v, list<int> *li){
        li[u].push_back(v);
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> recStack(numCourses, false);

        list<int> *li = new list<int> [numCourses];

            for(int i=0; i<prerequisites.size(); i++){
               int ai = prerequisites[i][0];
               int bi = prerequisites[i][1];

               addEdges(bi, ai, li);
            }
        
        


        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(cycleDetectDFS(i, li, vis, recStack, numCourses)){
                    return false;
                }
            }
        }

        return true;

    }
};