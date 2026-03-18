#include <bits/stdc++.h>

class GF2Calculator {
private:
    uint16_t mod_poly;
    int get_degree(uint16_t poly) {
        if (poly == 0) return -1;
        int degree = 0;
        while (poly >>= 1) {
            degree++;
        }
        return degree;
    }

public:
    GF2Calculator(uint16_t mod_poly) : mod_poly(mod_poly) {}

    //Print in common polynomial form
    std::string poly_to_string(uint16_t poly) {
        if (poly == 0) return "0";
        std::string res = "";
        int degree = get_degree(poly);
        bool first = true;

        for (int i = degree; i >= 0; --i) {
            if ((poly >> i) & 1) {
                if (!first) res += " + ";
                if (i == 0) res += "1";
                else if (i == 1) res += "x";
                else res += "x^" + std::to_string(i);
                first = false;
            }
        }
        return res;
    }

    //Multiplying polynomials in GF(2)
    uint16_t multiply(uint16_t a, uint16_t b) {
        uint16_t res = 0;
        while (b > 0) {
            if (b & 1) res ^= a;
            a <<= 1;
            b >>= 1;
        }
        return res;
    }

    //Dividing polynomials in GF(2)
    void divide(uint16_t a, uint16_t b, uint16_t &q, uint16_t &r) {
        q = 0;
        r = a;
        int deg_b = get_degree(b);
        while (r > 0 && get_degree(r) >= deg_b) {
            int d = get_degree(r) - deg_b;
            q ^= (1 << d);
            r ^= (b << d);
        }
    }

    //Expanded Euclidean
    uint16_t find_inverse(uint16_t a) {
        if (a == 0) {
            std::cerr << "Error: 0 has no inverse multiplyer" << std::endl;
            return 0;
        }
        uint16_t r1 = mod_poly, r2 = a;
        uint16_t t1 = 0, t2 = 1;

        std::cout << "ALGORITHM STARTING" << std::endl;
        std::cout << "[Initializing]" << std::endl;
        std::cout << "r1 = " << poly_to_string(r1) << std::endl;
        std::cout << "r2 = " << poly_to_string(r2) << std::endl;
        std::cout << "t1 = " << poly_to_string(t1) << std::endl;
        std::cout << "t2 = " << poly_to_string(t2) << "\n\n";

        int step = 1;
        while (r2 > 0) {
            uint16_t q, r;
            divide(r1, r2, q, r);
            uint16_t q_times_t2 = multiply(q, t2);
            uint16_t t = t1 ^ q_times_t2;

            std::cout << "--- Step " << step << " ---" << std::endl;
            std::cout << "Quotient q  = " << poly_to_string(q) << std::endl;
            std::cout << "Remaining r = " << poly_to_string(r) << std::endl;
            std::cout << "Coeffient t = " << poly_to_string(t) << "\n\n";

            r1 = r2;
            r2 = r;
            t1 = t2;
            t2 = t;
            step++;
        }

        std::cout << "ALGORITHM ENDING" << std::endl;
        if (r1 != 1) {
            std::cout << "Polynomial has no inverse multiplyer." << std::endl;
            return 0;
        }

        std::cout << "=> Inverse multiplyer: " << poly_to_string(t1) << std::endl;
        return t1;
    }
};

int main() {
    // Đa thức tối giản m(x) = x^10 + x^3 + 1 -> nhị phân: 10000001001
    uint16_t m_x = 0b10000001001;

    // Khởi tạo đối tượng
    GF2Calculator calc(m_x);

    // Tìm nghịch đảo của a(x) = x^9 + x^3 + x + 1 -> nhị phân: 1000001011
    uint16_t a_x = 0b1000001011;

    // Tìm nghịch đảo của b(x) = x^9 + x^8 + x^7 + x^6 + x^5 + x^4 + x^2 + x + 1 -> nhị phân: 1111110111
    uint16_t b_x = 0b1111110111;

    std::cout << "Finding inverse multiplyer of: " << calc.poly_to_string(a_x) << "\n\n";
    calc.find_inverse(a_x);

    std::cout << "Finding inverse multiplyer of: " << calc.poly_to_string(b_x) << "\n\n";
    calc.find_inverse(b_x);

    return 0;
}
