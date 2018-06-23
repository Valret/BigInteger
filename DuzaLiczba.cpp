#include "DuzaLiczba.h"
#include <iostream>

using namespace std;

DuzaLiczba::DuzaLiczba() {
    wartosc = new char[2];
    wartosc[0] = '0';
    wartosc[1] = '\0';
    minus = false;
}

DuzaLiczba::DuzaLiczba(const char *input) {
    int size = strlen(input) + 1;
    minus = false;
    if(input[0] == '-') {
        input++;
        minus = true;
    }
    wartosc = new char[size];
    strcpy(wartosc, input);
}

DuzaLiczba::DuzaLiczba(int num) {
    minus = false;
    if(num < 0) {
        num *= -1;
        minus = true;
    }
    int size = 2,
        ind = 1;
    while(num / (ind *= 10)) size++;
    wartosc = new char[size];
    for(int i = 0; i < size - 1; i++) {
        wartosc[size - i - 2] = (num % 10) + '0';
        num /= 10;
    } wartosc[size - 1] = '\0';
}

DuzaLiczba::DuzaLiczba(const DuzaLiczba &l2) {
    int size = strlen(l2.wartosc) + 1;
    this->wartosc = new char[size];
    minus = l2.minus;
    strcpy(wartosc, l2.wartosc);
}

DuzaLiczba::~DuzaLiczba() {
    delete[] wartosc;
}

DuzaLiczba DuzaLiczba::operator=(const DuzaLiczba&l2) {
    int size = strlen(l2.wartosc) + 1;
    this->wartosc = new char[size];
    minus = l2.minus;
    strcpy(wartosc, l2.wartosc);
    return *this;
}

DuzaLiczba DuzaLiczba::operator=(int l2) {
    *this = DuzaLiczba(l2);
    return *this;
}

DuzaLiczba DuzaLiczba::operator=(const char* l2) {
    *this = DuzaLiczba(l2);
    return *this;
}

bool DuzaLiczba::operator<(const DuzaLiczba &b) const {
    return compareTo(b) < 0;
}

bool DuzaLiczba::operator>(const DuzaLiczba &b) const {
    return compareTo(b) > 0;
}

bool DuzaLiczba::operator<=(const DuzaLiczba &b) const {
    return compareTo(b) <= 0;
}

bool DuzaLiczba::operator>=(const DuzaLiczba &b) const {
    return compareTo(b) >= 0;
}

bool DuzaLiczba::operator==(const DuzaLiczba &b) const {
    return compareTo(b) == 0;
}

bool DuzaLiczba::operator!=(const DuzaLiczba &b) const {
    return compareTo(b) != 0;
}

bool DuzaLiczba::operator==(const char* b) const {
    return compareTo(DuzaLiczba(b)) == 0;
}

bool DuzaLiczba::operator!=(const char* b) const {
    return compareTo(DuzaLiczba(b)) <= 0;
}

bool DuzaLiczba::operator>(const char* b) const {
    return compareTo(DuzaLiczba(b)) > 0;
}

bool DuzaLiczba::operator<(const char* b) const {
    return compareTo(DuzaLiczba(b)) < 0;
}

bool DuzaLiczba::operator>=(const char* b) const {
    return compareTo(DuzaLiczba(b)) >= 0;
}

bool DuzaLiczba::operator<=(const char* b) const {
    return compareTo(DuzaLiczba(b)) <= 0;
}

bool DuzaLiczba::operator==(int b) const {
    return compareTo(DuzaLiczba(b)) == 0;
}

bool DuzaLiczba::operator!=(int b) const {
    return compareTo(DuzaLiczba(b)) <= 0;
}

bool DuzaLiczba::operator>(int b) const {
    return compareTo(DuzaLiczba(b)) > 0;
}

bool DuzaLiczba::operator<(int b) const {
    return compareTo(DuzaLiczba(b)) < 0;
}

bool DuzaLiczba::operator>=(int b) const {
    return compareTo(DuzaLiczba(b)) >= 0;
}

bool DuzaLiczba::operator<=(int b) const {
    return compareTo(DuzaLiczba(b)) <= 0;
}

int DuzaLiczba::compareTo(const DuzaLiczba &b) const {
    int s1 = strlen(wartosc),
        s2 = strlen(b.wartosc);
    if(minus && !b.minus) return -1;
    if(!minus && b.minus) return 1;
    if(!minus) {
        if(s1 > s2) return 1;
        if(s1 < s2) return -1;
        for(int i = 0; i < s1; i++) {
            if(wartosc[i] > b.wartosc[i]) return 1;
            if(wartosc[i] < b.wartosc[i]) return -1;
        }
    } else {
        if(s1 > s2) return -1;
        if(s1 < s2) return 1;
        for(int i = 0; i < s1; i++) {
            if(wartosc[i] > b.wartosc[i]) return -1;
            if(wartosc[i] < b.wartosc[i]) return 1;
        }
    } return 0;
}

int DuzaLiczba::compareWithoutS(const DuzaLiczba &b) const{
    int s1 = strlen(wartosc),
        s2 = strlen(b.wartosc);
    if(s1 > s2) return 1;
    if(s1 < s2) return -1;
    for(int i = 0; i < s1; i++) {
        if(wartosc[i] > b.wartosc[i]) return 1;
        if(wartosc[i] < b.wartosc[i]) return -1;
    }
    return 0;
}

DuzaLiczba DuzaLiczba::operator+(const DuzaLiczba &b) const {
    int compare = this->compareWithoutS(b);
    DuzaLiczba          smallest = (compare <= 0) ? *this : b,
                        biggest  = (compare > 0) ? *this : b;
    if(smallest.minus != biggest.minus) {
        if(!compare) return DuzaLiczba("0");
        return biggest - -smallest;
    }

    int     bSize = strlen(biggest.wartosc),
            sSize = strlen(smallest.wartosc),
            *tab = new int[bSize + 1];

    tab[0] = 0;
    for(int i = bSize; i > 0; i--) tab[i] = biggest.wartosc[i - 1] - '0';
    for(int i = bSize; bSize - i < sSize; i--) {
            int tmp = tab[i] + (smallest.wartosc[i - ((bSize + 1) - sSize)] - '0');
            if(tmp >= 10) tab[i - 1]++;
            tab[i] = tmp % 10;
    }
    DuzaLiczba d(intToChar(tab, bSize + 1));
    delete[] tab;
    d.minus = biggest.minus;
    return d;
}

DuzaLiczba DuzaLiczba::operator-(const DuzaLiczba &b) const {
    int compare = this->compareWithoutS(b);
    DuzaLiczba          smallest = (compare <= 0) ? *this : b,
                        biggest  = (compare > 0) ? *this : b;
    if (smallest == b) smallest.minus = !smallest.minus;
    else biggest.minus = !biggest.minus;
    if(biggest.minus == smallest.minus) return biggest + smallest;
    if(!compare) return DuzaLiczba("0");

    int     bSize = strlen(biggest.wartosc),
            sSize = strlen(smallest.wartosc),
            *tab = new int[bSize];

    for(int i = bSize - 1; i >= 0; i--) tab[i] = biggest.wartosc[i] - '0';
    for(int i = bSize - 1; bSize - i -1 < sSize; i--) {
        int tmp = tab[i] - (smallest.wartosc[i - (bSize - sSize)] - '0');
        if(tmp < 0) {
            if(i == 0) {
                tab[i] = tmp * -1;
            } else {
                int ind = 1;
                while(tab[i - ind] == 0) {
                    tab[i - ind] = 9;
                    ind++;
                }
                tab[i - ind]--;
                tab[i] = 10 + tmp;
            }
        } else tab[i] = tmp;
    }

    DuzaLiczba d(intToChar(tab, bSize));
    delete[] tab;
    d.minus = biggest.minus;
    return d;
}

DuzaLiczba DuzaLiczba::operator-() {
    DuzaLiczba d(*this);
    d.minus = !minus;
    return d;
}

DuzaLiczba DuzaLiczba::operator*(const DuzaLiczba &b) const {
    int s1 = strlen(wartosc),
        s2 = strlen(b.wartosc),
        *tab = new int[s1 + s2];

    for(int i = 0; i < (s1 + s2); i++) tab[i] = 0;

    for(int i = s1 - 1; i >= 0; i--) {
        for(int j = s2 - 1; j >= 0; j--) {
            int ind = i + j + 1;
            tab[ind] += (wartosc[i] - '0') * (b.wartosc[j] - '0');
            if(tab[ind] >= 10) {
                tab[i + j] += tab[ind] / 10;
                tab[ind] %= 10;
            }
        }
    }
    DuzaLiczba d(intToChar(tab, s1 + s2));
    delete[] tab;
    if(minus != b.minus) d.minus = true;
    return d;
}

DuzaLiczba DuzaLiczba::operator/(const DuzaLiczba &b) const {
    int r = this->compareWithoutS(b);
    if(r < 0) return DuzaLiczba(0);
    if(r == 0) {
        DuzaLiczba d("1");
        if(minus != b.minus) d.minus = true;
        return d;
    }
    int s2 = strlen(b.wartosc),
        *tab = new int[s2];

    DuzaLiczba A(*this),
               B(b),
               res("0"),
               ten("10");
    B.minus = A.minus = false;
    while(A.compareWithoutS(B) >= 0) {
        int tmp = 0;
        for(int i = 1; i <= (strlen(A.wartosc) - s2); i++) tmp++;
        for(int i = 0; i < s2; i++) tab[i] = A.wartosc[i] - '0';
        DuzaLiczba a1(intToChar(tab, s2));
        int sym = a1.compareWithoutS(B);
        if(sym < 0) {
            a1 *= ten;
            a1.wartosc[s2] = A.wartosc[s2];
            tmp--;
        }
        int ind = 0;
        DuzaLiczba _tmp("1");
        for(int i = 0; i < tmp; i++) _tmp *= DuzaLiczba("10");
        while (ind < 10 && (B * DuzaLiczba(ind)) <= a1) ind++;
        A -= _tmp * (B * DuzaLiczba(--ind));
        res += DuzaLiczba(ind) * _tmp;
    }
    if(this->minus != b.minus) res.minus = true;
    else res.minus = false;
    delete[] tab;
    return res;
}

DuzaLiczba& DuzaLiczba::operator+=(const DuzaLiczba &b) {
    *this = *this + b;
    return *this;
}

DuzaLiczba& DuzaLiczba::operator-=(const DuzaLiczba &b) {
    *this = *this - b;
    return *this;
}

DuzaLiczba& DuzaLiczba::operator*=(const DuzaLiczba &b) {
    *this = *this * b;
    return *this;
}

DuzaLiczba& DuzaLiczba::operator/=(const DuzaLiczba &b) {
    *this = *this / b;
    return *this;
}

char* DuzaLiczba::intToChar(int *input, int size) const {
    int start = 0;
    for(; start < size - 1 && input[start] == 0; ++start);
    char *r = new char[(size -= start) + 1];
    for(int i = 0; i < size; i++) {
        r[i] = (char)(input[i + start] + '0');
    } r[size] = '\0';
    return r;
}

DuzaLiczba DuzaLiczba::operator!() {
    if(minus) return 0;
    if(*this == DuzaLiczba("0")) return DuzaLiczba("1");
    DuzaLiczba one("1"),
               inc(*this - one),
               result(*this);
    while(inc > one) {
        result = result * inc;
        inc = inc - one;
    } return result;
}

DuzaLiczba DuzaLiczba::operator+(int n) const {
    return *this + DuzaLiczba(n);
}
DuzaLiczba DuzaLiczba::operator-(int n) const {
    return *this - DuzaLiczba(n);
}
DuzaLiczba DuzaLiczba::operator*(int n) const {
    return *this * DuzaLiczba(n);
}
DuzaLiczba DuzaLiczba::operator/(int n) const {
    return *this / DuzaLiczba(n);
}

DuzaLiczba& DuzaLiczba::operator+=(int n) {
    return *this += DuzaLiczba(n);
}

DuzaLiczba& DuzaLiczba::operator-=(int n) {
    return *this -= DuzaLiczba(n);
}

DuzaLiczba& DuzaLiczba::operator*=(int n) {
    return *this *= DuzaLiczba(n);
}

DuzaLiczba& DuzaLiczba::operator/=(int n) {
    return *this += DuzaLiczba(n);
}

DuzaLiczba DuzaLiczba::operator+(const char* n) const {
    return *this + DuzaLiczba(n);
}
DuzaLiczba DuzaLiczba::operator-(const char* n) const {
    return *this - DuzaLiczba(n);
}
DuzaLiczba DuzaLiczba::operator*(const char* n) const {
    return *this * DuzaLiczba(n);
}
DuzaLiczba DuzaLiczba::operator/(const char* n) const {
    return *this / DuzaLiczba(n);
}

DuzaLiczba& DuzaLiczba::operator+=(const char* n) {
    return *this += DuzaLiczba(n);
}

DuzaLiczba& DuzaLiczba::operator-=(const char* n) {
    return *this -= DuzaLiczba(n);
}

DuzaLiczba& DuzaLiczba::operator*=(const char* n) {
    return *this *= DuzaLiczba(n);
}

DuzaLiczba& DuzaLiczba::operator/=(const char* n) {
    return *this += DuzaLiczba(n);
}


ostream& operator<<(ostream &out, const DuzaLiczba &liczba) {
    if(liczba.minus) out << "-";
    out << liczba.wartosc << endl;
    return out;
}

istream& operator>>(istream &in, DuzaLiczba &liczba) {
    char *str = new char[0];
    in >> str;
    DuzaLiczba *tmp = new DuzaLiczba(str);
    liczba = *tmp;
    return in;
}
