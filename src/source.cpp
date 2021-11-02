#include <iostream>

#define CPP2 PRIME UPPER LIMIT 1000000//�T������l�̏���l

int nth_prime(unsigned int a, unsigned int d, unsigned int n);
bool check_number(unsigned int n);	// ���͂������R�����f�����ǂ������肷��

int main() {

	std::cout << nth_prime(367, 186, 151) << std::endl;



	return 0;
}

int nth_prime(unsigned int a, unsigned int d, unsigned int n)
{

	int i = 0;
	int count = 1;	// �������� a + d(n - 1) ��n
	int item = a;	// �������� a + d(n - 1) ��n���ڂ��i�[����ϐ�

	do {
		item = a + d * (count - 1);	// �������� a + d(n - 1) ��n����
		if (check_number(item)) {	// �f�����ǂ�������
			i++;
		};
		count++;
	} while (i < n);	// n�Ԗڂ̑f��

	return item;
}

bool check_number(unsigned int n)
{

	bool flag = false;	// ����؂ꂽ������
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

