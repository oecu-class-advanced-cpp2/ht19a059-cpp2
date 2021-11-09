#include <iostream>

#define CPP2 PRIME UPPER LIMIT 1000000//探索する値の上限値

int nth_prime(unsigned int a, unsigned int d, unsigned int n);
bool is_prime(unsigned int n);	// 入力した自然数が素数かどうか判定する

int main() {

	std::cout << nth_prime(367, 186, 151) << std::endl;
	std::cout << nth_prime(179, 10, 203) << std::endl;
	std::cout << nth_prime(271, 37, 39) << std::endl;
	std::cout << nth_prime(103, 230, 1) << std::endl;
	std::cout << nth_prime(27, 104, 185) << std::endl;
	std::cout << nth_prime(253, 50, 85) << std::endl;
	std::cout << nth_prime(1, 1, 1) << std::endl;
	std::cout << nth_prime(9075, 337, 210) << std::endl;
	std::cout << nth_prime(307, 24, 79) << std::endl;
	std::cout << nth_prime(331, 221, 177) << std::endl;
	std::cout << nth_prime(259, 170, 40) << std::endl;
	std::cout << nth_prime(269, 58, 102) << std::endl;

	return 0;
}

int nth_prime(unsigned int a, unsigned int d, unsigned int n)
{

	unsigned int i = 1;		// 等差数列 a + d(n - 1) のn
	unsigned int count = 1;	// n番目の素数
	unsigned int item = 0;	// 等差数列 a + d(n - 1) のn項目を格納する変数

	do {
		item = a + (d * (i - 1));	// 等差数列 a + d(n - 1) のn項目
		if (is_prime(item)) {	// 素数かどうか判定
			count++;
		};
		i++;
	} while (count <= n);	// n番目の素数

	return item;
}

bool is_prime(unsigned int n)
{
	bool flag = false;	// 割り切れたかを判定
	for (int i = 2; i < n; i++) {
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

