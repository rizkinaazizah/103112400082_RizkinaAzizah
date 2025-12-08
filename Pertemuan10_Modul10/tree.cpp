#include<iostream>
using namespace std;

int pangkat_2(intx){// x adalah pangkatnya
    if (x=0){//basis
        return 1;
    }else if(x>0){
        return 2 * pangkat_2(x-1);

    }
}

int main(){
    cout << "=== REKURSIF PANGKAT 2 ===" << endl;
    cin >> x;
    cout << endl;
    cout << "2 pangkat" << x << "adalah: " << pangkat_2(x);

    return 0;
}

//misal x=3
//pangkat_2(3)
//2 * pangkat_2