class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		result.push_back(binary_search_left(nums, target));
		result.push_back(binary_search_right(nums, target));
		return result;
	}
private:
	int binary_search_left(vector<int>&sort_array, int target)
	{
		int begin = 0;
		int end = sort_array.size() - 1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (target == sort_array[mid])
			{
				if (mid == 0 || sort_array[mid-1]<target)
					return mid;
				end = mid - 1;
			}
			else if (target < sort_array[mid]){
				end = mid - 1;
			}
			else if (target >sort_array[mid]){
				begin = mid + 1;
			}
		}
		return -1;
	}
	int  binary_search_right(vector<int>&sort_array, int target)
	{
		int begin = 0;
		int end = sort_array.size() - 1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (target == sort_array[mid])
			{
				if (mid == sort_array.size()-1 || sort_array[mid +1]>target)
					return mid;
				begin = mid + 1;
			}
			else if (target < sort_array[mid]){
				end = mid - 1;
			}
			else if (target >sort_array[mid]){
				begin = mid + 1;
			}
		}
		return -1;
	}
};
