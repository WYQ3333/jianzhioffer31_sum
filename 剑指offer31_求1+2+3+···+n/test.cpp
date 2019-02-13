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
		/*���ȿ�ʮ������������ģ� 5 + 7 = 12��������
		��һ������Ӹ�λ��ֵ�������λ���õ�2��
		�ڶ����������λֵ���õ�10.�����һ���Ľ�λֵΪ0����ô��һ���õ���ֵ�������ս����

		���������ظ�����������ֻ����ӵ�ֵ������������ĵõ��Ľ��2��10���õ�12��

		ͬ�����ǿ����������ߵķ�ʽ���������ֵ��ӣ� 5 - 101��7 - 111 ��һ������Ӹ�λ��ֵ��
		�����λ���õ�010��������ÿλ��Ӿ��൱�ڸ�λ����������101 ^ 111��

		�ڶ����������λֵ���õ�1010���൱�ڸ�λ��������õ�101����������һλ�õ�1010��
		(101 & 111) << 1��

		�������ظ����������� ��λ��� 010 ^ 1010 = 1000��
		��λֵΪ100 = (010 & 1010) << 1��
		�����ظ�����������1000 ^ 100 = 1100����λֵΪ0������ѭ����1100Ϊ���ս����*/

	//������+/*-���������ĺ�
	cout<<add(2, 3)<<endl;
	Solution_sum2 s;
	cout << s.Add(2, 3) << endl;
}

int main(){
	TestFunc2();
	system("pause");
	return 0;
}