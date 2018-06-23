#include <iostream>

using namespace std;

class DuzaLiczba {
    char* wartosc;
    bool minus;

public:
    DuzaLiczba();
    DuzaLiczba(const DuzaLiczba&);
    DuzaLiczba(int);
    DuzaLiczba(const char*);

    ~DuzaLiczba();

    DuzaLiczba operator-();
    DuzaLiczba operator!();
    bool operator==(int) const;
    bool operator!=(int) const;
    bool operator>(int) const;
    bool operator<(int) const;
    bool operator>=(int) const;
    bool operator<=(int) const;
    bool operator==(const char*) const;
    bool operator!=(const char*) const;
    bool operator>(const char*) const;
    bool operator<(const char*) const;
    bool operator>=(const char*) const;
    bool operator<=(const char*) const;
    bool operator==(const DuzaLiczba&) const;
    bool operator!=(const DuzaLiczba&) const;
    bool operator>(const DuzaLiczba&) const;
    bool operator<(const DuzaLiczba&) const;
    bool operator>=(const DuzaLiczba&) const;
    bool operator<=(const DuzaLiczba&) const;
    DuzaLiczba operator=(const DuzaLiczba&);
    DuzaLiczba operator+(const DuzaLiczba&) const;
    DuzaLiczba operator/(const DuzaLiczba&) const;
    DuzaLiczba operator-(const DuzaLiczba&) const;
    DuzaLiczba operator*(const DuzaLiczba&) const;
    DuzaLiczba& operator +=(const DuzaLiczba&);
    DuzaLiczba& operator -=(const DuzaLiczba&);
    DuzaLiczba& operator *=(const DuzaLiczba&);
    DuzaLiczba& operator /=(const DuzaLiczba&);
    DuzaLiczba operator=(const char*);
    DuzaLiczba operator+(const char*) const;
    DuzaLiczba operator/(const char*) const;
    DuzaLiczba operator-(const char*) const;
    DuzaLiczba operator*(const char*) const;
    DuzaLiczba& operator +=(const char*);
    DuzaLiczba& operator -=(const char*);
    DuzaLiczba& operator *=(const char*);
    DuzaLiczba& operator /=(const char*);
    DuzaLiczba operator=(int);
    DuzaLiczba operator+(int) const;
    DuzaLiczba operator/(int) const;
    DuzaLiczba operator-(int) const;
    DuzaLiczba operator*(int) const;
    DuzaLiczba& operator +=(int);
    DuzaLiczba& operator -=(int);
    DuzaLiczba& operator *=(int);
    DuzaLiczba& operator /=(int);

    int compareTo(const DuzaLiczba&) const;
    int compareWithoutS(const DuzaLiczba&) const;
    char* intToChar(int*, int) const;

    friend std::ostream& operator<<(std::ostream&, const DuzaLiczba&);
    friend std::istream& operator>>(std::istream&, DuzaLiczba&);
};