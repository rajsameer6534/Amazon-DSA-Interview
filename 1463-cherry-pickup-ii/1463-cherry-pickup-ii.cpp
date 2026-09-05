class Solution {
public:
    int f(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size(), m = grid[0].size();
        
        // boundary check
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e9;

        // base case
        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = INT_MIN;
        int dj[3] = {-1, 0, 1};

        for (int k = 0; k < 3; k++) {
            for (int k2 = 0; k2 < 3; k2++) {
                int nextVal = f(i + 1, j1 + dj[k], j2 + dj[k2], grid, dp);
                if (j1 == j2)
                    maxi = max(maxi, grid[i][j1] + nextVal);
                else
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] + nextVal);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(0, 0, m - 1, grid, dp);
    }
};
