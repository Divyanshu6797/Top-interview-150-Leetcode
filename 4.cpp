class Solution {
public:
   
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<int> adj[N];
        
        vector<int> indegree(N,0);

        for(vector<int> v : prerequisites) {
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        queue<int> q;
        for(int i=0;i<N;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }

        int count=0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for(auto it : adj[node]) {
                if(--indegree[it]==0) {
                    q.push(it);
                }
            }
        }

        return count ==N;
        
        
    }
};

























//course schedule
// use topo sort(bfs or dfs)
