#include <iostream>

using namespace std;

int main(){
	int tinggi = 3;
	
	for (int i = tinggi; i >=0; i--){
		for (int j = 0; j < tinggi-i; j++) {
			cout <<" ";
		}
		for(int s=i;s>=1;s--){
			cout<<s;
		}
		cout << "*";

		for(int s=1; s<=i; s++){
			cout<<s;
			}
		cout<< endl;
			
	}
	}
	
