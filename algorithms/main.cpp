#include <iostream>
#include <vector>
#include <unordered_map>


/*DIVIDE_AND_CONQUER --- the basic algorithm*/
using std::vector;
class Solution
{
public :
	/*target == x + y*/
	vector<int> twoSum(vector<int> &nums, int target);
private:

	/*This hash_table will preserve the difference [target - x] as the key and index of the element [x] as the value type*/
	std::unordered_map<int, size_t> delta_id;
	int target_ = 0;
	vector<int> res;
	void find_sum(vector<int> &nums, size_t start, size_t end);
	void combine(vector<int> &nums, size_t start, size_t mid, size_t end);

};

vector<int> Solution::twoSum(vector<int> &nums, int target)
{
	target_ = target;
	find_sum(nums, 0, nums.size() - 1);
	return res;
}

void Solution::find_sum(vector<int> &nums, size_t start, size_t end)
{
	if (nums.empty())
		return;
	if (start == end)
		return;
	auto mid = static_cast<size_t>((end - start) / 2 );
	find_sum(nums, start, start + mid);
	if (res.size() == 2) return;
	find_sum(nums, start + mid + 1, end);
	if (res.size() == 2) return;
	combine(nums, start, start + mid + 1, end);
}

void Solution::combine(vector<int> &nums, size_t start, size_t mid, size_t end)
{
	size_t left_bound{mid - start};
	size_t right_bound{end - mid + 1};
	for (size_t i = 0; i < left_bound; ++i) {
		delta_id[target_ - nums[start + i]] = start + i;
	}
	for (int j = 0; j < right_bound; ++j) {
		auto it = delta_id.find(nums[mid + j]);
		if (it != delta_id.end()) {
			res.push_back(it->second);
			res.push_back(mid + j);
			return;
		}
	}

	delta_id.clear(); // this method has linear complexity depending on the size of the unordered_map (delta_id)
}

int main()
{

	Solution sl;
	vector<int> v{1, 3, 4, 2};
	vector<int> res = sl.twoSum(v, 6);
	std::cout << res[0] << " " << res[1] << std::endl;
	return 0;
}
