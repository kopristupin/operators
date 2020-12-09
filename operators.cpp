
#include <iostream>
#include<vector>

using namespace std;

class c2 {
private: 
    double id, jd, kd;
public:
    c2(double i, double j, double k) : id(i), jd(j), kd(k) {};
    c2(double i) : id(i), jd(0), kd(0) {};
    void getDoubleParameters();
};

class c1 {
private:
    int i, j, k;
    vector<int> vec{ 1,2,3,4,5,6 };
public:
    c1(int i, int j, int k) : i(i), j(j), k(k) {};
    c1(int i): i(i), j(0), k(0) {};
    void getParameters() const;
    c1 operator+(c1) const;
    void operator+=(c1);
    operator c2() const;
    operator int() const;
   int& operator[](int n);
};
int main()
{
    c1 obj1(1, 2, 3);
    c1 obj2(6);
    c1 objRes = obj1 + obj2;
    objRes.getParameters();
    c2 objc2 = obj2;
    objc2.getDoubleParameters();
    int i = obj1;
    cout << i << "\n";
    obj1 += obj2+objRes;
    obj1[1] = 75;
     obj1.getParameters();
}

int& c1::operator[](int n){
    if (n < vec.size())
        return vec[n];
}

void c1::getParameters() const {
    cout << i << " " << j << " " << k << "\n";
    for (auto it : vec)
        cout << it << " ";
    cout << "\n";
}
c1 c1::operator+(c1 obj) const{
    int resI = i + obj.i;
    int resJ = j + obj.j;
    int resK = k + obj.k;
    return c1(resI, resJ, resK);
}

c1::operator c2() const{
    return c2(i, j, k);
}
c1::operator int()const {
    int result = i;
    return result;
}
void c1::operator+=(c1 arg) {
    i += arg.i;
    j += arg.j;
    k += arg.k;
}

void c2::getDoubleParameters() {
    cout << id << " " << jd << " " << kd << "\n";
}