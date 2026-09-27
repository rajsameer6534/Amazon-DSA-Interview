class Solution {
public:

    void dfs(int node,vector<vector<int>>&adjList, vector<bool>&visited){
        visited[node]=1;
        for(auto it:adjList[node]){
           if (!visited[it]) dfs(it, adjList, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int v=isConnected.size();
        vector<vector<int>>adjList(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int provinces=0;
        vector<bool>visited(v,0);
        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfs(i,adjList,visited);
                provinces++;;
            }
        }
        return provinces;
    }
};