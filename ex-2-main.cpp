#include <iostream>
#include <string>
#include <exception>

namespace cpp2 {

	/* --------------------------------------------------------------------- */
	/*
	   mcxi

	   mcxi �L�@����͂���N���X
	 */
	 /* --------------------------------------------------------------------- */
	class mcxi {
	public:
		/* ----------------------------------------------------------------- */
		/*
		   mcxi

		   �w�肳�ꂽ���������͂��āA�I�u�W�F�N�g�����������܂�
		   �ȉ��̏ꍇ�ɂ͗�O�����o����܂�

		   1. [2-9,m,c,x,i] �ȊO�̕������o�������ꍇ
		   2. 2 ���������Đ��� (2-9) ���o�������ꍇ
		   3. m, c, x, i �����̏����ŏo�����Ȃ������ꍇ
			  �������A�Ⴆ�� mx �̂悤�ɁA����̕������X�L�b�v���鎖�͋��e
			  ����܂��B
		 */
		 /* ----------------------------------------------------------------- */
		mcxi(const std::string& s) :value_(0) {
			int num = 0;
			//std::cout << std::endl;
			//std::cout << "input " << s << std::endl;
			//std::cout << std::boolalpha << mcix_regulation(s) << std::endl;
			if (mcix_regulation(s)) {
				for (auto pos = s.begin(); pos != s.end(); ++pos) {
					if (*pos >= '2' && *pos <= '9') {
						num = *pos - '0';
					}
					else {
						int u = unit(*pos);
						value_ += std::max(num, 1) * u;
						num = 0;
					};
				};
				//std::cout << std::endl;
			}
			else {
				std::cout << s << std::endl;
				throw std::invalid_argument("exception");
			};
		};

		/* ----------------------------------------------------------------- */
		/*
		   operator+

		   2 �̃I�u�W�F�N�g�̉��Z���ʂ��擾���܂�
		 */
		 /* ----------------------------------------------------------------- */
		mcxi operator+(const mcxi& rhs) {
			mcxi tc(rhs);
			tc.value_ = this->value_ + rhs.value_;
			return tc;
		};

		/* ----------------------------------------------------------------- */
		/*
		   to_string

		   ���݂̒l�� mcxi �L�@�ɕϊ����܂�
		 */
		 /* ----------------------------------------------------------------- */
		std::string to_string() const {
			std::string mcxi;

			int calc = value_;
			if (calc / 1000 >= 1) {
				if (calc / 1000 == 1) {
					mcxi += "m";
					calc = calc - 1000;
				}
				else {
					mcxi += std::to_string(calc / 1000) + "m";
					calc = calc - (calc / 1000) * 1000;
				}
			};
			if (calc / 100 >= 1) {
				if (calc / 100 == 1) {
					mcxi += "c";
					calc = calc - 100;
				}
				else {
					mcxi += std::to_string(calc / 100) + "c";
					calc = calc - (calc / 100) * 100;
				}
			};
			if (calc / 10 >= 1) {
				if (calc / 10 == 1) {
					mcxi += "x";
				}
				else {
					mcxi += std::to_string(calc / 10) + "x";
				}
			}
			if (calc % 10 >= 1) {
				if (calc % 10 == 1) {
					mcxi += "i";
				}
				else {
					mcxi += std::to_string(calc % 10) + "i";
				}
			};
			return mcxi;
		};

		/* ----------------------------------------------------------------- */
		/*
			mcxi�̋K���ɑ����Ă��邩�m�F����
			�����Ă���ꍇ�Ature�A�����Ă��Ȃ��ꍇ�Afalse��Ԃ�
		*/
		/* ----------------------------------------------------------------- */

		bool mcix_regulation(const std::string& s) {

			//�@[2-9,m,c,x,i] �ȊO�̕������o�����Ă��邩�𔻒�
			//�@���������Đ��� (2-9) ���o�����Ă��邩�𔻒�
			int number_dup = 0;
			for (auto pos = s.begin(); pos != s.end(); ++pos) {
				if (*pos == 'm' || *pos == 'c' || *pos == 'x' || *pos == 'i') {
					number_dup = 0;
				}
				else if (*pos >= '2' && *pos <= '9') {
					number_dup++;
				}
				else {
					return false;
				};
				if (number_dup >= 2) {
					return false;
				};
			};

			// m, c, x, i �������������ŏo�����Ă��邩�𔻒�
			int npos = std::string::npos;
			int m_place = s.find("m");
			int c_place = s.find("c");
			int x_place = s.find("x");
			int i_place = s.find("i");

			//m c
			if (m_place != npos && c_place != npos &&
				x_place == npos && i_place == npos) {
				if (!(m_place < c_place)) {
					return false;
				};
			};

			//m i
			if (m_place != npos && c_place == npos &&
				x_place == npos && i_place != npos
				) {
				if (!(m_place < i_place)) {
					return false;
				};
			};

			//m x
			if (
				m_place != npos && c_place == npos &&
				x_place != npos && i_place == npos
				) {
				if (!(m_place < x_place)) {
					return false;
				};
			};

			//c i
			if (
				m_place == npos && c_place != npos &&
				x_place == npos && i_place != npos
				) {
				if (!(c_place < i_place)) {
					return false;
				};
			};

			//c x
			if (
				m_place == npos && c_place != npos &&
				x_place != npos && i_place == npos
				) {
				if (!(c_place < x_place)) {
					return false;
				};
			};

			//x i
			if (
				m_place == npos && c_place == npos &&
				x_place != npos && i_place != npos
				) {
				if (!(x_place < i_place)) {
					return false;
				};
			}

			//m c i
			if (
				m_place != npos && c_place != npos &&
				x_place == npos && i_place != npos
				) {
				if (!(m_place < c_place && c_place < i_place)) {
					return false;
				};
			};

			//m c x
			if (
				m_place != npos && c_place != npos &&
				x_place != npos && i_place == npos
				) {
				if (!(m_place < c_place && c_place < x_place)) {
					return false;
				};
			};

			//m x i
			if (
				m_place != npos && c_place == npos &&
				x_place != npos && i_place != npos
				) {
				if (!(m_place < x_place && x_place < i_place)) {
					return false;
				};
			};

			//c x i
			if (
				m_place == npos && c_place != npos &&
				x_place != npos && i_place != npos
				) {
				if (!(c_place < x_place && x_place <i_place)) {
					return false;
				};
			};

			//m c x i
			if (
				m_place != npos && c_place != npos &&
				x_place != npos && i_place != npos
				) {
				if (!(m_place < c_place && c_place < x_place && x_place < i_place)) {
					return false;
				};
			};

			return true;
		};


		/* ----------------------------------------------------------------- */
		/*
			mcxi��int�ɕϊ�����ۂ̌v�Z�p
		 */
		/* ----------------------------------------------------------------- */
		int unit(char p) {
			switch (p) {
			case 'm': return 1000; break;
			case 'c': return 100;  break;
			case 'x': return 10;   break;
			case 'i': return 1;    break;
			}
			return -1;
		};


	private:
		int value_;
	};

	/* ----------------------------------------------------------------- */
	/*
		���ʂ����������ǂ������`�F�b�N����
	*/
	/* ----------------------------------------------------------------- */
	bool test(std::string s1, std::string s2) {
		if (s1 == s2) {
			return true;
		}
		else {
			return false;
		};
	};
}

int main() {

	//cpp2::mcxi c("ix");
	//std::cout << c.to_string() << std::endl;

	cpp2::mcxi a0("xi");
	cpp2::mcxi b0("x9i");
	cpp2::mcxi result0 = a0 + b0;
	std::cout << std::boolalpha << cpp2::test("3x", result0.to_string()) << std::endl;

	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	cpp2::mcxi result1 = a1 + b1;
	std::cout << std::boolalpha << cpp2::test("x" , result1.to_string()) << std::endl;

	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	cpp2::mcxi result2 = a2 + b2;
	std::cout << std::boolalpha << cpp2::test("6cx" , result2.to_string()) << std::endl;

	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	cpp2::mcxi result3 = a3 + b3;
	std::cout << std::boolalpha << cpp2::test("5m9c9x9i" , result3.to_string()) << std::endl;

	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	cpp2::mcxi result4 = a4 + b4;
	std::cout << std::boolalpha << cpp2::test("m" , result4.to_string()) << std::endl;

	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	cpp2::mcxi result5 = a5 + b5;
	std::cout << std::boolalpha << cpp2::test("9m9c9x9i" , result5.to_string()) << std::endl;

	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	cpp2::mcxi result6 = a6 + b6;
	std::cout << std::boolalpha << cpp2::test("mi" , result6.to_string()) << std::endl;

	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	cpp2::mcxi result7 = a7 + b7;
	std::cout << std::boolalpha << cpp2::test("mi" , result7.to_string()) << std::endl;

	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	cpp2::mcxi result8 = a8 + b8;
	std::cout << std::boolalpha << cpp2::test("mx" , result8.to_string()) << std::endl;

	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	cpp2::mcxi result9 = a9 + b9;
	std::cout << std::boolalpha << cpp2::test("9m9c9x9i" , result9.to_string()) << std::endl;

}