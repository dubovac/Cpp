/**
 * 164. Maximum Gap
 * Medium
 * Topics
 * Companies
 *
 * Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
 *
 * You must write an algorithm that runs in linear time and uses linear extra space.
 *
 *
 *
 * Example 1:
 *
 *	Input: nums = [3,6,9,1]
 *	Output: 3
 *	Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
 *
 * Example 2:
 *
 *	Input: nums = [10]
 *	Output: 0
 *	Explanation: The array contains less than 2 elements, therefore return 0.
 *
 *
 *
 * Constraints:
 *
 *	1 <= nums.length <= 10^5
 *	0 <= nums[i] <= 10^9
 */ 



#include <iostream>
#include <vector>

using namespace std;

int compare(const void* a, const void* b) {

	return (*(int *) a - *(int *) b);
}

int maximumGap(vector<int>& nums) {
    if (nums.size() < 2)
        return 0;
    
    int max = 0;

    qsort(&nums[0], nums.size(), sizeof(int), compare);

    for (size_t i = 1; i < nums.size(); i++)
        if(nums[i] - nums[i - 1] > max)
            max = nums[i] - nums[i - 1];
        
    return max;
}

int main(void) {
	vector<int> nums0 = {3, 6, 9, 1};
	cout << (maximumGap(nums0)) << endl;
}
