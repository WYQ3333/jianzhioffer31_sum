#include<iostream>

using namespace std;

//��1 + 2 + 3 + ... + n��Ҫ����ʹ�ó˳�����
//for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A ? B : C����

class Solution1 {
public:
	int Sum_Solution(int n) {
		int ans = n;
		ans && (ans += Sum_Solution(n - 1));
		return ans;
	}
};

//�˷���vs2013��֧�ֿɱ�����
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

//�����������½�һ���࣬ͨ����������ķ�ʽ��������Ĵ�С����
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

void TestFunc2(){
	//������+/*-���������ĺ�
	Solution_sum s;
	cout << s.Add(2, 3) << endl;
}

int main(){
	TestFunc2();
	system("pause");
	return 0;
}