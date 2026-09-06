class Solution {
public:

    long long getMax(vector<vector<int>>& coins, long long k) {

        int n = coins.size();

        long long ans = 0;
        long long sum = 0;

        int right = 0;

        for (int left = 0; left < n; left++) {

            long long start = coins[left][0];
            long long carpetEnd = start + k - 1;

            // Add all intervals completely inside [start, carpetEnd]
            while (right < n && coins[right][1] <= carpetEnd) {

                long long len =
                    coins[right][1] - coins[right][0] + 1;

                sum += len * coins[right][2];

                right++;
            }

            // Current interval may be partially covered
            long long current = sum;

            if (right < n && coins[right][0] <= carpetEnd) {

                long long len =
                    carpetEnd - coins[right][0] + 1;

                current += len * coins[right][2];
            }

            ans = max(ans, current);

            // Remove left interval before moving left
            if (left < right) {

                long long len =
                    coins[left][1] - coins[left][0] + 1;

                sum -= len * coins[left][2];
            }

            // Keep right >= left
            if (right < left + 1)
                right = left + 1;
        }

        return ans;
    }


    long long maximumCoins(vector<vector<int>>& coins, int k) {

        sort(coins.begin(), coins.end());

        long long ans = getMax(coins, k);

        // Reverse the number line.
        // [l,r] becomes [-r,-l]
        for (auto &x : coins) {

            int l = x[0];
            int r = x[1];

            x[0] = -r;
            x[1] = -l;
        }

        sort(coins.begin(), coins.end());

        ans = max(ans, getMax(coins, k));

        return ans;
    }
};