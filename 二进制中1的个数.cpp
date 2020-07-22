//思想一：每一个二进制-1以后，从右往下左第一个1的后面的数都会变为1，然后与原二进制数与以后后面就都会变为0，能这样操作几次就代表有几个1

1100-1=1011

int number_1(int n)
{
	int count = 0;
	while(n!=0)
	{
		count++;
		n = n&(n-1);
	}
	return count;
}


//思想二//按位与
int number2_1(int n)
{
	int count = 0;
	int flag = 1;
	while(n!=0)
	{
		if((n&flag)!=0)
			count++;
		n = n<<1;
	}
	return count;
}
