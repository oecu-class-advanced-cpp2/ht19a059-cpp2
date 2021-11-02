#include <iostream>

#define CPP2 PRIME UPPER LIMIT 1000000//’Tõ‚·‚é’l‚ÌãŒÀ’l

int nth_prime(unsigned int a, unsigned int d, unsigned int n);
bool check_number(unsigned int n);	// “ü—Í‚µ‚½©‘R”‚ª‘f”‚©‚Ç‚¤‚©”»’è‚·‚é

int main() {

	std::cout << nth_prime(367, 186, 151) << std::endl;



	return 0;
}

int nth_prime(unsigned int a, unsigned int d, unsigned int n)
{

	int i = 0;
	int count = 1;	// “™·”—ñ a + d(n - 1) ‚Ìn
	int item = a;	// “™·”—ñ a + d(n - 1) ‚Ìn€–Ú‚ğŠi”[‚·‚é•Ï”

	do {
		item = a + d * (count - 1);	// “™·”—ñ a + d(n - 1) ‚Ìn€–Ú
		if (check_number(item)) {	// ‘f”‚©‚Ç‚¤‚©”»’è
			i++;
		};
		count++;
	} while (i < n);	// n”Ô–Ú‚Ì‘f”

	return item;
}

bool check_number(unsigned int n)
{

	bool flag = false;	// Š„‚èØ‚ê‚½‚©”»’è
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

