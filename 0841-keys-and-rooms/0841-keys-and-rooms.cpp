class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        int v=rooms.size();
        vector<int>vis(v,0);
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto nei: rooms[node]){
                if(!vis[nei]){
                    vis[nei]=1;
                    q.push(nei);
                }
            }
        }
        for(auto ele:vis){
            if(ele==0) return false;
        }
        return true;

    }
};