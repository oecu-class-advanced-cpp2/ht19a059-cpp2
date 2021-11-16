#include <iostream>

#define CPP2 PRIME UPPER LIMIT 1000000	// �T������l�̏���l

int nth_prime(unsigned int a, unsigned int d, unsigned int n);
bool is_prime(unsigned int n);	// ���͂������R�����f�����ǂ������肷��

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
�^����ꂽ������a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ�
�f����Ԃ�
 ---------------------------------------------------------------*/

int nth_prime(unsigned int a, unsigned int d, unsigned int n)
{

	unsigned int i = 1;			// �������� a + d(n - 1) ��n
	unsigned int count = 1;		// n�Ԗڂ̑f��
	unsigned int item = 0;		// �������� a + d(n - 1) ��n���ڂ��i�[����ϐ�

	while (i < CPP2 PRIME UPPER LIMIT) {
		do {
			item = a + (d * (i - 1));	// �������� a + d(n - 1) ��n����
			if (is_prime(item)) {		// �f�����ǂ�������
				count++;
			};
			i++;
		} while (count <= n);	// n�Ԗڂ̑f��
		return item;
	}
}

/*    ---------------------------------------------------------------
is_prime
�^����ꂽ������num ���f�����ǂ�������
�f���Ȃ�true, �f���łȂ��ꍇ��false��Ԃ�
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

