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

void TestFunc(){
	Solution s;
	cout << s.Sum_Solution(3) << endl;
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}