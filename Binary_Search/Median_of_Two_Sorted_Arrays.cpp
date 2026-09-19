#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Initialization
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;

        // Always perform binary search on smaller array
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int partition = (n + 1) / 2;

        // Edge cases
        if (n1 == 0)
            return n2 % 2
                ? nums2[n2 / 2]
                : (nums2[n2 / 2] + nums2[n2 / 2 - 1]) / 2.0;

        if (n2 == 0)
            return n1 % 2
                ? nums1[n1 / 2]
                : (nums1[n1 / 2] + nums1[n1 / 2 - 1]) / 2.0;

        // Binary search partition
        int left1 = 0;
        int right1 = n1;

        while (left1 <= right1) {

            int cut1 = (left1 + right1) / 2;
            int cut2 = partition - cut1;

            // Left elements
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            // Right elements
            int r1 = (cut1 >= n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 >= n2) ? INT_MAX : nums2[cut2];

            // Correct partition
            if (l1 <= r2 && l2 <= r1) {

                if (n % 2 == 1)
                    return max(l1, l2);

                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            // Move partition
            if (l1 > r2)
                right1 = cut1 - 1;
            else
                left1 = cut1 + 1;
        }

        return 0.0;
    }
};

int main() {

    // Input arrays
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    Solution obj;

    double median = obj.findMedianSortedArrays(nums1, nums2);

    cout << "Median = " << median << endl;

    return 0;
}