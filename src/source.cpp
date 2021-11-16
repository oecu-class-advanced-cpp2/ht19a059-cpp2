#include <iostream>

#define CPP2 PRIME UPPER LIMIT 1000000	// ’Tõ‚·‚é’l‚ÌãŒÀ’l

int nth_prime(unsigned int a, unsigned int d, unsigned int n);
bool is_prime(unsigned int n);	// “ü—Í‚µ‚½©‘R”‚ª‘f”‚©‚Ç‚¤‚©”»’è‚·‚é

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
—^‚¦‚ç‚ê‚½³®”a ‚Æ d ‚Æ n ‚É‘Î‚µ‚ÄA‚±‚Ì“™·”—ñ‚ÉŠÜ‚Ü‚ê‚é n ”Ô–Ú‚Ì
‘f”‚ğ•Ô‚·
 ---------------------------------------------------------------*/

int nth_prime(unsigned int a, unsigned int d, unsigned int n)
{

	unsigned int i = 1;			// “™·”—ñ a + d(n - 1) ‚Ìn
	unsigned int count = 1;		// n”Ô–Ú‚Ì‘f”
	unsigned int item = 0;		// “™·”—ñ a + d(n - 1) ‚Ìn€–Ú‚ğŠi”[‚·‚é•Ï”

	while (i < CPP2 PRIME UPPER LIMIT) {
		do {
			item = a + (d * (i - 1));	// “™·”—ñ a + d(n - 1) ‚Ìn€–Ú
			if (is_prime(item)) {		// ‘f”‚©‚Ç‚¤‚©”»’è
				count++;
			};
			i++;
		} while (count <= n);	// n”Ô–Ú‚Ì‘f”
		return item;
	}
}

/*    ---------------------------------------------------------------
is_prime
—^‚¦‚ç‚ê‚½³®”num ‚ª‘f”‚©‚Ç‚¤‚©”»’è
‘f”‚È‚çtrue, ‘f”‚Å‚È‚¢ê‡‚Ífalse‚ğ•Ô‚·
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

