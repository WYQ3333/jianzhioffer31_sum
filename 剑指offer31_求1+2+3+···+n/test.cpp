#include<iostream>

using namespace std;

//��1 + 2 + 3 + ... + n��Ҫ����ʹ�ó˳�����
//for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A ? B : C����

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