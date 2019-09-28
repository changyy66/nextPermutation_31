// nextPermutation_31.cpp : 定义控制台应用程序的入口点。
//
/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

void nextPermutation(vector<int>& nums) {
	if (nums.size() < 2)return;
	if (nums.size() == 2)
	{
		int n = nums[0];
		nums[0] = nums[1];
		nums[1] = n;
		return;
	}
	int i;
	int temp;
	for (i=nums.size()-1;i>0;i--)
	{
		if (nums[i]>nums[i-1])
		{
			int j = i - 1;
			int k = i + 1;
			while (k < nums.size() && nums[k]>nums[j])k++;
			k--;
			temp = nums[j];
			nums[j] = nums[k];
			nums[k] = temp;
			break;
		}
	}
	int left = i;
	int right = nums.size() - 1;
	while (left < right)
	{
		temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
		left++;
		right--;
	}
}

int main()
{
	vector<int> nums = { 1,2,6,8,7,3,2 };
	nextPermutation(nums);
	for each (auto var in nums)
	{
		cout << var << " ";
	}
    return 0;
}

