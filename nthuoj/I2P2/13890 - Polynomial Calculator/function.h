#include <bits/stdc++.h>
using namespace std;

class Function{
    public:
    static Function *parse(stringstream &ss);
    virtual double eval(double) = 0;
};

