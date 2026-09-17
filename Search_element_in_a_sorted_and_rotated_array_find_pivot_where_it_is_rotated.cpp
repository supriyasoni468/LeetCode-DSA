#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {

          
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[low] <= nums[mid]) {

                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {

                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    Solution obj;
    int result = obj.search(nums, target);

    cout << result << endl;

    return 0;
}