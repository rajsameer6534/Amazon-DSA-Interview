class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {

        sort(tiles.begin(), tiles.end());

        int n = tiles.size();

        int left = 0;
        int right = 0;

        long long covered = 0;
        long long ans = 0;

        while (left < n) {

            long long carpetEnd =
                1LL * tiles[left][0] + carpetLen - 1;

            // Add completely covered tiles
            while (right < n && tiles[right][1] <= carpetEnd) {

                covered +=
                    tiles[right][1] - tiles[right][0] + 1;

                right++;
            }

            // Partial coverage of the next tile
            long long partial = 0;

            if (right < n && tiles[right][0] <= carpetEnd) {

                partial =
                    carpetEnd - tiles[right][0] + 1;
            }

            ans = max(ans, covered + partial);

            // Remove the left tile
            if (left < right) {

                covered -=
                    tiles[left][1] - tiles[left][0] + 1;
            }

            left++;

            // Very important
            if (right < left)
                right = left;
        }

        return ans;
    }
};