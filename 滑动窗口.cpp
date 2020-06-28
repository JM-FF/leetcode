class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {

		deque<int> s;
		vector<int> result;
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			//判断双端队列中如果有大于目前的数字出队
			while (!s.empty() && nums[i] >= nums[s.back()])
			{
				s.pop_back();
			}
			//如果对头元素超过滑动窗口的大小出队
			if (!s.empty() && s.front() < i - k + 1)
			{
				s.pop_front();
			}
			s.push_back(i);

			//到达滑动窗口的大小时开始入队
			if (i >= k - 1)
				result.push_back(nums[s.front()]);
		}
		return result;
	}
};
