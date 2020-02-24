#include "PolinomBF.hpp"
#include <iostream>
#include <vector>
#include<time.h>
using namespace std;

PolinomBF::PolinomBF(){
    //konstruktor

}

PolinomBF::PolinomBF(int n, bool random){
    //konstruktor dengan parameter
    int x;

    this->derajat = n;
    if (random){
        for (int i = 0; i<=n ; i++){
            x = rand() % 200 - 100 ;
            this->koefisien.push_back(x);
        }
    } else {
        for (int i = 0; i<=n ; i++){
            this->koefisien.push_back(0);
        }
    }
}

void PolinomBF::CetakPolinomBF(){
    //prosedur untuk mencetak polinom
    cout << this->koefisien[0] ;
    for (int i = 1 ; i <= this->derajat ; i++){
        if (this->koefisien[i] == 0){
            //do nothing
        } else if (this->koefisien[i] == 1){
            cout << " + " << "x^" << i;
        } else if (this->koefisien[i] == -1){
            cout << " - " << "x^" << i;
        } else if (this->koefisien[i] > 0) {
            cout << " + " << this->koefisien[i] << "x^" << i;
        } else {
            cout << " - " << this->koefisien[i]*-1 << "x^" << i;
        }
    }
    cout << endl;
}

PolinomBF BruteForce(const PolinomBF& A, const PolinomBF& B, int& count_kali, int& count_tambah){
    //fungsi untuk mengalikan polinom dengan metode brute force
    PolinomBF temp(A.derajat + B.derajat, false);
    count_kali = 0;
    count_tambah = 0;
    for (int i = 0 ; i <= A.derajat ; i++){
        for (int j = 0 ; j <= B.derajat ; j++){
            temp.koefisien[i+j] += A.koefisien[i] * B.koefisien[j];
            count_tambah ++;
            count_kali ++;
        }
    }
    return temp;
}