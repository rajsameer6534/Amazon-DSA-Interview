class Solution {
public:
    int r, c;
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    
    bool valid(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        r = mat.size();
        c = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(r, vector<int>(c, 0));
        vector<vector<int>> dist(r, vector<int>(c, 0));
        
        // Push all cells with value 0 into the queue
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        
        // Perform BFS to calculate distances
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            dist[i][j] = steps;
            
            for (int k = 0; k < 4; k++) {
                int ni = i + row[k];
                int nj = j + col[k];
                
                if (valid(ni, nj) && visited[ni][nj] == 0) {
                    visited[ni][nj] = 1;  // Mark as visited
                    q.push({{ni, nj}, steps + 1});
                }
            }
        }
        
        return dist;  // Return the distance matrix
    }
};
