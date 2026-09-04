class Solution {
public:
    long long hours(vector<int>& piles, int speed) {
        long long total = 0;

        for (int pile : piles) {
            total += (pile + speed - 1) / speed;
        }

        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (hours(piles, mid) <= h) {
                hi = mid - 1;
            } 
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};