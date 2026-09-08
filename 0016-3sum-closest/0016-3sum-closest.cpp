class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {

            int l = i + 1;
            int r = n - 1;

            while (l < r) {

                int sum = nums[i] + nums[l] + nums[r];

                // Update closest sum
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                // Exact match
                if (sum == target) {
                    return target;
                }

                // Need a larger sum
                if (sum < target) {
                    l++;
                }
                // Need a smaller sum
                else {
                    r--;
                }
            }
        }

        return closest;
    }
};