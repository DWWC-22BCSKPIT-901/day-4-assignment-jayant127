#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1); // Initialize result with -1
        stack<int> stk; // Stack to store indices of elements

        // Traverse the array twice to simulate circular behavior
        for (int i = 0; i < 2 * n; ++i) {
            int currentIndex = i % n;
            while (!stk.empty() && nums[stk.top()] < nums[currentIndex]) {
                result[stk.top()] = nums[currentIndex];
                stk.pop();
            }
            if (i < n) {
                stk.push(currentIndex);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums = {1, 2, 1};
    vector<int> result = solution.nextGreaterElements(nums);

    cout << "Input: nums = [1, 2, 1]" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "]" : ", ");
    }
    cout << endl;

    return 0;
}
