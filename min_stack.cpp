class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		tmp.push(x);
		if (min_s.empty() || x < min_s.top()){
			min_s.push(x);
		}
		else{
			min_s.push(min_s.top());
		}

	}

	void pop() {
		min_s.pop();
		tmp.pop();
	}

	int top() {
		return tmp.top();
	}

	int min() {
		return min_s.top();
	}

private:
	stack<int> tmp;
	stack<int> min_s;
};
