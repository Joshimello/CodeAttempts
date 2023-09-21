#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

// func.h
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>

class Polynomial {

public:
    Polynomial(){

    }

    Polynomial(const int gp, const int ce[51]){
        greatestPower = gp;
        for(int i = gp; i >= 0; i--){
            coefficients[i] = ce[i];
        }
    }

    Polynomial add( const Polynomial b) const {

        Polynomial a;
        a.greatestPower = max(greatestPower, b.greatestPower);

        if(b.greatestPower > greatestPower){
            for(int i = 0; i <= greatestPower; i++){
                a.coefficients[i] = b.coefficients[i] + coefficients[i];
            }
            for(int i = greatestPower+1; i <= b.greatestPower; i++){
                a.coefficients[i] = b.coefficients[i];
            }
        } 

        else {
            for(int i = 0; i <= b.greatestPower; i++){
                a.coefficients[i] = b.coefficients[i] + coefficients[i];
            }
            for(int i = b.greatestPower+1; i <= greatestPower; i++){
                a.coefficients[i] = coefficients[i];
            }
        }

        return a;
    }

    Polynomial subtract( const Polynomial b ) const {

        Polynomial a;
        a.greatestPower = max(greatestPower, b.greatestPower);

        if(b.greatestPower > greatestPower){
            for(int i = 0; i <= greatestPower; i++){
                a.coefficients[i] = coefficients[i] - b.coefficients[i];
            }
            for(int i = greatestPower+1; i <= b.greatestPower; i++){
                a.coefficients[i] = b.coefficients[i] * -1;
            }
        } 

        else {
            for(int i = 0; i <= b.greatestPower; i++){
                a.coefficients[i] = coefficients[i] - b.coefficients[i];
            }
            for(int i = b.greatestPower+1; i <= greatestPower; i++){
                a.coefficients[i] = coefficients[i];
            }
        }

        return a;
    }

    Polynomial multiplication( const Polynomial b ) const {
        int arr[greatestPower + b.greatestPower + 1] = {};
        Polynomial a(greatestPower + b.greatestPower, arr);

        for(int i = 0; i <= greatestPower; i++){
            for(int j = 0; j <= b.greatestPower; j++){
                a.coefficients[(greatestPower-i)+(b.greatestPower-j)] += coefficients[greatestPower-i] * b.coefficients[b.greatestPower-j];
            }
        }

        return a;
    }

    void output() const {
        for(int i = greatestPower; i >= 0; i--){
            cout << coefficients[i] << (i?" ":"");
        }
    }
private:
    int coefficients[101]; // integer coefficients
    int greatestPower; // integer greatestPower
}; // end class Polynomial

#endif



int main()
{
    int greatestPower1, greatestPower2;
    int coefficient1[51], coefficient2[51];
    Polynomial ans;

    cin>>greatestPower1;
    for(int i = greatestPower1 ; i >= 0; i--)
    {
        cin>>coefficient1[i];
    }
    cin>>greatestPower2;
    for(int i = greatestPower2 ; i >= 0 ; i--)
    {
        cin>>coefficient2[i];
    }
    Polynomial a(greatestPower1, coefficient1), b(greatestPower2, coefficient2) ;

    ans = a.add( b );
    ans.output();
    cout << endl;

    ans = a.subtract( b );
    ans.output();
    cout << endl;

    ans = a.multiplication( b );
    ans.output();
    cout << endl;

} // end main
