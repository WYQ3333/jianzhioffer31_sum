#include<iostream>

using namespace std;

//求1 + 2 + 3 + ... + n，要求不能使用乘除法、
//for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。

class Solution1 {
public:
	int Sum_Solution(int n) {
		int ans = n;
		ans && (ans += Sum_Solution(n - 1));
		return ans;
	}
};

//此方法vs2013不支持可变数组
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		bool a[n][n + 1];
//		return sizeof(a) >> 1;
//	}
//};

typedef int(*func)(int);

class Solution {
public:
	static int Solution1(int n)
	{
		return 0;
	}
	static int Sum_Solution(int n) {
		static func f[2] = { Solution1, Sum_Solution };
		return n + f[!!n](n - 1);
	}
};

//聪明：利用新建一个类，通过开辟数组的方式，将数组的大小返回
class Temp
{
public:
	Temp(){ N++; sum += N; }

	static void Reset(){ N = 0; sum = 0; }
	static int GetSum() { return sum; }
private:
	static int N;
	static int sum;
};

int Temp::N = 0;
int Temp::sum = 0;

class Solution2 {
public:
	int Sum_Solution(int n)
	{
		Temp::Reset();

		Temp *a = new Temp[n];
		delete[]a;
		a = NULL;

		return Temp::GetSum();
	}
};

void TestFunc(){
	Solution2 s;
	cout << s.Sum_Solution(3) << endl;
}

class Solution_sum{
public:
	int Add(int num1, int num2){
		while (num2 != 0){
			int temp = num1^num2;
			num2 = (num1&num2) << 1;
			num1 = temp;
		}
		return num1;
	}
};

class Solution_sum2 {
public:
	int Add(int num1, int num2)
	{
		return num2 ? Add(num1^num2, (num1&num2) << 1) : num1;

	}
};


int add(int a, int b)
{
	_asm
	{
		MOV EAX, a
			MOV ECX, b
			ADD EAX, ECX
	}
}

void TestFunc2(){
		/*首先看十进制是如何做的： 5 + 7 = 12，三步走
		第一步：相加各位的值，不算进位，得到2。
		第二步：计算进位值，得到10.如果这一步的进位值为0，那么第一步得到的值就是最终结果。

		第三步：重复上述两步，只是相加的值变成上述两步的得到的结果2和10，得到12。

		同样我们可以用三步走的方式计算二进制值相加： 5 - 101，7 - 111 第一步：相加各位的值，
		不算进位，得到010，二进制每位相加就相当于各位做异或操作，101 ^ 111。

		第二步：计算进位值，得到1010，相当于各位做与操作得到101，再向左移一位得到1010，
		(101 & 111) << 1。

		第三步重复上述两步， 各位相加 010 ^ 1010 = 1000，
		进位值为100 = (010 & 1010) << 1。
		继续重复上述两步：1000 ^ 100 = 1100，进位值为0，跳出循环，1100为最终结果。*/

	//不适用+/*-求两个数的和
	cout<<add(2, 3)<<endl;
	Solution_sum2 s;
	cout << s.Add(2, 3) << endl;
}

int main(){
	TestFunc2();
	system("pause");
	return 0;
}