#include <iostream>

#define CPP2 PRIME UPPER LIMIT 1000000	// �T������l�̏���l

int nth_prime(unsigned int a, unsigned int d, unsigned int n);
bool is_prime(unsigned int n);	// ���͂������R�����f�����ǂ������肷��

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

	unsigned int i = 1;			// �������� a + d(n - 1) ��n
	unsigned int count = 1;		// n�Ԗڂ̑f��
	unsigned int item = 0;		// �������� a + d(n - 1) ��n���ڂ��i�[����ϐ�

	do {
		item = a + (d * (i - 1));	// �������� a + d(n - 1) ��n����
		if (is_prime(item)) {		// �f�����ǂ�������
			count++;
		};
		i++;
	} while (count <= n);	// n�Ԗڂ̑f��

	return item;
}

bool is_prime(unsigned int n)
{
	bool flag = false;	// ����؂ꂽ���𔻒�
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

