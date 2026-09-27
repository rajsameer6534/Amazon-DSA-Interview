class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    int r;
    int c;
    bool valid(int i , int j){
        return i>=0 && i<r && j>=0 && j<c;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        r=grid.size();
        c=grid[0].size();
      
        queue<pair<int ,int>>q;
        int freshOranges = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        if (freshOranges == 0) return 0; // No fresh oranges at the beginning

        int time=0;
        while(!q.empty()){
            time++;
            int curr=q.size();
            while(curr--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    if(valid(i+row[k],j+col[k])&& grid[i+row[k]][j+col[k]]==1){
                        grid[i+row[k]][j+col[k]]=2;
                        q.push(make_pair(i+row[k],j+col[k]));
                         freshOranges--;
                    }
                }
            }
        }
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        if(grid[i][j]==1) return -1;
        
        return time-1;
    }
};