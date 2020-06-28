class MaxQueue {
public:
	MaxQueue() {

	}

	int max_value() {
		return !max.empty() ? max.front() : -1;
	}

	void push_back(int value) {
		tmp.push(value);
		while (!max.empty() && value > max.back())
		{
			max.pop_back();
		}
		max.push_back(value);
	}

	int pop_front() {
		if (tmp.empty())
			return -1;
		int m = tmp.front();
		tmp.pop();
		if (!max.empty() && m == max.front())
			max.pop_front();
		return m;
	}
private:
	queue<int> tmp;
	deque<int> max;
};
