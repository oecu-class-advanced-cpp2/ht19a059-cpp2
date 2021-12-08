#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#define CPP2_PRIME_UPPER_LIMIT 1000000

// 3つの値を1つにまとめるクラス
class tri {
public:
	int a;
	int d;
	int n;
	tri(int ak = 0, int dk = 0, int nk = 0) { a = ak; d = dk; n = nk; }
};

// テストデータを格納するクラス
class Data {
public:
	std::map<tri, int> data;
	void import_testData(std::vector<int>& a, std::vector<int>& d, std::vector<int>& n, std::vector<int>& t);
	bool test(int nthpt, int a, int d, int n);
};

bool operator<(const tri& p, const tri& q){
	return std::tie(p.a, p.d, p.n) < std::tie(q.a, q.d, q.n);
}

int nth_prime(unsigned int a, unsigned int d, unsigned int n);
bool is_prime(unsigned int n);	// 入力した自然数が素数かどうか判定する

int main() {

	Data c;
	std::vector<int> a;
	std::vector<int> d;
	std::vector<int> n;
	std::vector<int> t;

	c.import_testData(a, d, n, t);

	for (unsigned int i = 0; i < t.size(); i++) {
		std::cout << nth_prime(a[i], d[i], n[i]) << " ";
		std::cout << std::boolalpha <<  c.test(nth_prime(a[i], d[i], n[i]), a[i], d[i], n[i]) << std::endl;
	};

	return 0;
}

/*    ---------------------------------------------------------------
import_testData
テキストファイルからテストデータのインポート
 ---------------------------------------------------------------*/
void Data::import_testData(std::vector<int>& a, std::vector<int>& d, std::vector<int>& n, std::vector<int>& t)
{
	std::string filename = "input.txt";
	std::ifstream file1(filename);
	if (!file1.is_open()) {
		std::cout << "Import Error" <<  std::endl;
		exit(EXIT_FAILURE);;
	};
	int w1 = 0;
	int w2 = 0;
	int w3 = 0;
	while (file1 >> w1 >> w2 >> w3) {
		a.push_back(w1);
		d.push_back(w2);
		n.push_back(w3);
	};
	filename = "output.txt";
	std::ifstream file2(filename);
	if (!file2.is_open()) {
		std::cout << "Import Error" << std::endl;
		exit(EXIT_FAILURE);;
	};
	int w4 = 0;
	while (file2 >> w4) {
		t.push_back(w4);
	};
	for (unsigned int i = 0; i < t.size(); i++) {
		//std::cout << a[i] << " " << d[i] << " " << n[i] << " ";
		tri q(a[i], d[i], n[i]);
		//std::cout << t[i] << std::endl;
		data.insert_or_assign(q, t[i]);
	};
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

	while (i < CPP2_PRIME_UPPER_LIMIT) {
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
	}
	else {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) {
				return false;
			};
		};
	};
	return true;
};

/*    ---------------------------------------------------------------
test
テストデータと出力結果が一致するか判定
一致する場合はtrue, 一致しない場合はfalseを返す
 ---------------------------------------------------------------*/

bool Data::test(int nthp, int a, int d, int n) {
	tri t(a, d, n);
	auto find = data.find(t);
	if (find == data.end()) {
		return false;
	}
	else {
		if (find->second == nthp) {
			return true;
		};
	};
}