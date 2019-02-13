#include<iostream>

using namespace std;

//求1 + 2 + 3 + ... + n，要求不能使用乘除法、
//for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。

class Solution {
public:
	int Sum_Solution(int n) {
		int ans = n;
		ans && (ans += Sum_Solution(n - 1));
		return ans;
	}
};

//class Solution {
//public:
//	int Sum_Solution(int n) {
//		bool a[n][n + 1];
//		return sizeof(a) >> 1;
//	}
//};

void TestFunc(){
	Solution s;
	cout << s.Sum_Solution(3) << endl;
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}