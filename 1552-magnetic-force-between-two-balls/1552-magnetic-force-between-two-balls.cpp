class Solution {
public:

    int f(vector<int>& position, int val, int balls) {

        int cntball = 1;
        int last = position[0];

        for (int i = 1; i < position.size(); i++) {

            if (position[i] - last >= val) {
                cntball++;
                last = position[i];
            }
        }

        return cntball;
    }

    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int n = position.size();

        int lo = 1;
        int hi = position[n - 1] - position[0];

        int ans = 0;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            int ballcount = f(position, mid, m);

            if (ballcount >= m) {
                // mid is possible
                ans = mid;
                lo = mid + 1;
            }
            else {
                // mid is too large
                hi = mid - 1;
            }
        }

        return ans;
    }
};