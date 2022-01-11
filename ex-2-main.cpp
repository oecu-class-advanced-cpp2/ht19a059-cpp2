#include <iostream>
#include <string>

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

           �w�肳�ꂽ���������͂��āA�I�u�W�F�N�g�����������܂��B
           �ȉ��̏ꍇ�ɂ͗�O���n�o����܂��B

           1. [2-9,m,c,x,i] �ȊO�̕������o�������ꍇ
           2. 2 ���������Đ��� (2-9) ���o�������ꍇ
           3. m, c, x, i �����̏����ŏo�����Ȃ������ꍇ
              �������A�Ⴆ�� mx �̂悤�ɁA����̕������X�L�b�v���鎖�͋��e
              ����܂��B
         */
         /* ----------------------------------------------------------------- */
        mcxi(const std::string& s) :value_(0) {
            int num = 0;
            for (auto pos = s.begin(); pos != s.end(); ++pos) {
                if (*pos >= '2' && *pos <= '9') {
                    num = *pos - '0';
                }
                else {
                    int u = unit(*pos);
                    value_ += std::max(num, 1) * u;
                    num = 0;
                }
                //std::cout << s << std::endl;
            }
        }


        /* ----------------------------------------------------------------- */
        /*
           operator+

           2 �̃I�u�W�F�N�g�̉��Z���ʂ��擾���܂��B
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

           ���݂̒l�� mcxi �L�@�ɕϊ����܂��B
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
                if (calc % 10 == 1) {
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

    private:
        int unit(char p) {
            switch (p) {
            case 'm': return 1000; break;
            case 'c': return 100;  break;
            case 'x': return 10;   break;
            case 'i': return 1;    break;
            }
            return -1;
        };

        int calc(std::string &mcxi, int &calc, std::string& ) {

            if (calc / 10 >= 1) {
                if (calc / 10 == 1) {
                    mcxi += "x";
                    calc = calc - 10;
                }
                else {
                    mcxi += std::to_string(calc / 10) + "x";
                    calc = calc - (calc / 10) * 10;
                }
            };
        };

        int value_;
    };
}

int main() {

    cpp2::mcxi a0("xi");
    cpp2::mcxi b0("x9i");
    cpp2::mcxi result0 = a0 + b0;
    std::cout << "3x" << " " << result0.to_string() << std::endl;

    cpp2::mcxi a1("i");
    cpp2::mcxi b1("9i");
    cpp2::mcxi result1 = a1 + b1;
    std::cout << "x" << " " << result1.to_string() << std::endl;

    cpp2::mcxi a2("c2x2i");
    cpp2::mcxi b2("4c8x8i");
    cpp2::mcxi result2 = a2 + b2;
    std::cout << "6cx" << " " << result2.to_string() << std::endl;

    cpp2::mcxi a3("m2ci");
    cpp2::mcxi b3("4m7c9x8i");
    cpp2::mcxi result3 = a3 + b3;
    std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;

    cpp2::mcxi a4("9c9x9i");
    cpp2::mcxi b4("i");
    cpp2::mcxi result4 = a4 + b4;
    std::cout << "m" << " " << result4.to_string() << std::endl;

    cpp2::mcxi a5("i");
    cpp2::mcxi b5("9m9c9x8i");
    cpp2::mcxi result5 = a5 + b5;
    std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;

    cpp2::mcxi a6("m");
    cpp2::mcxi b6("i");
    cpp2::mcxi result6 = a6 + b6;
    std::cout << "mi" << " " << result6.to_string() << std::endl;

    cpp2::mcxi a7("i");
    cpp2::mcxi b7("m");
    cpp2::mcxi result7 = a7 + b7;
    std::cout << "mi" << " " << result7.to_string() << std::endl;

    cpp2::mcxi a8("m9i");
    cpp2::mcxi b8("i");
    cpp2::mcxi result8 = a8 + b8;
    std::cout << "mx" << " " << result8.to_string() << std::endl;

    cpp2::mcxi a9("9m8c7xi");
    cpp2::mcxi b9("c2x8i");
    cpp2::mcxi result9 = a9 + b9;
    std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;

}