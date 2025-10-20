#include <iostream>

using namespace std;

const int MAX = 10;
    struct rapot{
        string nama, nim;
        float uts, uas, tugas, nilaiAkhir;
    
    };

    float hitungnilaiAkhir(float uts, float uas, float tugas){
        return 0.3*uts+0.4*uas+0.3*tugas;
    }
    
int main(){
    
    rapot siswa [MAX];

    cout<<"==============DATA MAHASISWA=================="<<endl;

    for(int i = 0; i < MAX; i++){
        
        cout << "NAMA: ";
        cin >> siswa[i].nama;
        cout << "NIM: ";
        cin >> siswa[i].nim;
        cout << "Nilai UTS: ";
        cin >> siswa[i].uts;
        cout << "Nilai UAS: ";
        cin >> siswa[i].uas;
        cout << "Nilai Tugas: ";
        cin >> siswa[i].tugas;

        siswa[i].nilaiAkhir = hitungnilaiAkhir(siswa[i].uts, siswa[i].uas, siswa[i].tugas);

        cout << "Hasil Nilai Akhir: " << siswa[i].nilaiAkhir << endl;
        cout << endl;
    }
    
    int j = 0;
    while(j< MAX ){
        cout << "NAMA: " << siswa[j].nama << ", NIM: " << siswa[j].nim<< ", Nilai UTS: " << siswa[j].uts << ", Nilai UAS: " << siswa[j].uas<< ", Nilai Tugas: " << siswa[j].tugas<<", Hasil Nilai Akhir: " << siswa[j].nilaiAkhir<<endl;
        j++;
    }
}