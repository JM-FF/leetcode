// 


class Solution {
public:
	int myAtoi(string str) {
	    long tmp = 0;
		int k = 0;
		while (k < str.size() && str[k] == ' ')
			k++;
		int flag = 1;
		if (str[k] == '-')
		{
			flag = -1;
			k++;
		}
		else if(str[k] == '+')
			k++;
		if (str[k] > '9' || str[k] < '0')
			return 0;
		while (k < str.size() && (str[k] >= '0' && str[k] <= '9'))
		{
			tmp = tmp * 10 + str[k] - '0';
			if (tmp - 1 > INT_MAX)break;
			k++;
		}
		tmp = flag * tmp;
		if (tmp > INT_MAX)
			return INT_MAX;
		if (tmp < INT_MIN)
			return INT_MIN;
		return tmp;
	}
};
