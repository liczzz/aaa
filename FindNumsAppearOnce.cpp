#include <iostream>
#include <vector>
using namespace std;

/*
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请找出这两个只出现一次的数字。
 *思路:
 1）如果把数组中的所有数字都依次异或一遍，则可以消掉成对出现的数字，那么还有两个数字是单一的，肯定也不同，那么最终异或的结果肯定不是0。表示在二进制中肯定有一位是1，那么两个不同的数字，一定有一个在该位为1，另一个在该位为0。如果将整个数组按照该位是否为1分为两部分，那么这两部分各自包含一个单一数字。
 2）分为两部分的数组，分别异或，最终结果就是这两个数。
*/
void FindNumsAppearOnce(vector<int> nums, int& res1, int& res2) {
	int cur = 0;
	for (int num : nums)
		cur ^= num;

	int indexBit = 0;
	while ((cur & 1) == 0 && indexBit < 8 * sizeof (int)) {
		cur >>= 1;
		++indexBit;
	}

	res1 = 0;
	res2 = 0;
	for (int num : nums) {
		if ((num >> indexBit) & 1)
			res1 ^= num;
		else
			res2 ^= num;
	}
}

int main(void) {
	vector<int> nums {1,2,4,65,8,96,3,4,2,1,96,8};
	int res1, res2;
        FindNumsAppearOnce(nums, res1, res2);
	cout << res1 << ", " << res2 << endl;

	return 0;
}
