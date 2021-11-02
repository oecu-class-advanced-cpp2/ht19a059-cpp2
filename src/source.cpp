#include <iostream>

#define CPP2 PRIME UPPER LIMIT 1000000//探索する値の上限値

int nth_prime(unsigned int a, unsigned int d, unsigned int n);
bool check_number(unsigned int n);	// 入力した自然数が素数かどうか判定する

int main() {

	std::cout << nth_prime(367, 186, 151) << std::endl;



	return 0;
}

int nth_prime(unsigned int a, unsigned int d, unsigned int n)
{

	int i = 0;
	int count = 1;	// 等差数列 a + d(n - 1) のn
	int item = a;	// 等差数列 a + d(n - 1) のn項目を格納する変数

	do {
		item = a + d * (count - 1);	// 等差数列 a + d(n - 1) のn項目
		if (check_number(item)) {	// 素数かどうか判定
			i++;
		};
		count++;
	} while (i < n);	// n番目の素数

	return item;
}

bool check_number(unsigned int n)
{

	bool flag = false;	// 割り切れたか判定
	for (int i = 2;i < n; ++i) {
		if (n % i == 0) {
			flag = true;
			break;
		}
	};
	if (flag == true) {
		return false;
	}
	else {
		return true;
	};
}

