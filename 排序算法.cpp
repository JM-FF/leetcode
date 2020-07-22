//冒泡排序
void BubbleSort(vector<int>& array, int len)
{
	int i = 0;
	int j = 0;
	int flag = 1;
	for ( i = 0;i < len&&flag==1;i++)
	{
		flag = 0;
		for ( j = len - 1;j > i;j--)
		{
			if (array[j] < array[j - 1])
			{
				int tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
				flag = 1;
			}
		}
	}
}

//插入算法
void InertionSort(vector<int>& array, int len)
{
	int i = 0;
	int j = 0;
	int k = -1;
	int tmp = -1;
	for (i = 1;i < len;i++)
	{
		k = i;
		tmp = array[k];
		for (j = i - 1;j >= 0;j--)
		{
			if (array[j] > tmp)
			{
				array[j + 1] = array[j];
				k = j;
			}
		}
		array[k] = tmp;
	}
}
//希尔排序



//快速排序
void swap1(vector<int> &tmp, int low, int high)
{
	int cur = tmp[low];
	tmp[low] = tmp[high];
	tmp[high] = cur;
}

int partition(vector<int>& array, int low, int high)
{
	int pv = array[low];
	while (low < high)
	{
		while ((low < high) && (array[high] >= pv))
		{
			high--;
		}
		swap1(array, low, high);
		while ((low < high) && (array[low] <= pv))
		{
			low++;
		}
		swap1(array, low, high);
	}
	return low;
}

void QSort(vector<int>& tmp, int low, int high)
{
	if (low < high)
	{
		int pos = partition(tmp, low, high);
		QSort(tmp, low, pos - 1);
		QSort(tmp, pos + 1, high);
	}
}
