class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int> tmp;
		sort(arr.begin(), arr.end());
		for (int i = 0; i < k; i++)
			tmp.push_back(arr[i]);
		return tmp;
	}
};
