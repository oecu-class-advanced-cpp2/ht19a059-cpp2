#include <iostream>

#define CPP2 PRIME UPPER LIMIT 1000000	// 探索する値の上限値

int nth_prime(unsigned int a, unsigned int d, unsigned int n);
bool is_prime(unsigned int n);	// 入力した自然数が素数かどうか判定する

int main() {

	std::cout << nth_prime(367, 186, 151) << " 92809" << std::endl;
	std::cout << nth_prime(179, 10, 203) << " 6709" << std::endl;
	std::cout << nth_prime(271, 37, 39) << " 12037" << std::endl;
	std::cout << nth_prime(103, 230, 1) << " 103" << std::endl;
	std::cout << nth_prime(27, 104, 185) << " 93523" << std::endl;
	std::cout << nth_prime(253, 50, 85) << " 14503" << std::endl;
	std::cout << nth_prime(1, 1, 1) << " 2" << std::endl;
	std::cout << nth_prime(9075, 337, 210) << " 899429" << std::endl;
	std::cout << nth_prime(307, 24, 79) << " 5107" << std::endl;
	std::cout << nth_prime(331, 221, 177) << " 412717" << std::endl;
	std::cout << nth_prime(259, 170, 40) << " 22699" << std::endl;
	std::cout << nth_prime(269, 58, 102) << " 25673" << std::endl;

	return 0;
}

/*    ---------------------------------------------------------------
nth_prime
与えられた正整数a と d と n に対して、この等差数列に含まれる n 番目の
素数を返す
 ---------------------------------------------------------------*/

int nth_prime(unsigned int a, unsigned int d, unsigned int n)
{

	unsigned int i = 1;			// 等差数列 a + d(n - 1) のn
	unsigned int count = 1;		// n番目の素数
	unsigned int item = 0;		// 等差数列 a + d(n - 1) のn項目を格納する変数

	while (i < CPP2 PRIME UPPER LIMIT) {
		do {
			item = a + (d * (i - 1));	// 等差数列 a + d(n - 1) のn項目
			if (is_prime(item)) {		// 素数かどうか判定
				count++;
			};
			i++;
		} while (count <= n);	// n番目の素数
		return item;
	}
}

/*    ---------------------------------------------------------------
is_prime
与えられた正整数num が素数かどうか判定
素数ならtrue, 素数でない場合はfalseを返す
 ---------------------------------------------------------------*/

bool is_prime(unsigned int n)
{
	if (n == 1) {
		return false;
	};
	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		};
	};
	return true;
}

