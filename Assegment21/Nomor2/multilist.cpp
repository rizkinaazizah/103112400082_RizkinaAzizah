#include "multilist.h"
#include <iostream>

using namespace std;

void createListParent(listParent &LParent){
    LParent.first = LParent.last = NULL;
}

void createListChild(listChild &LChild){
    LChild.first = LChild.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idGenre, string namaGenre){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idGenre = idGenre;
    nodeBaruParent->namaGenre = namaGenre;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idFilm, string judulFilm, int durasiFilm, int tahunTayang, float ratingFilm){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idFilm = idFilm;
    nodeBaruChild->judulFilm = judulFilm;
    nodeBaruChild->durasiFilm = durasiFilm;
    nodeBaruChild->tahunTayang = tahunTayang;
    nodeBaruChild->ratingFilm = ratingFilm;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next= nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void inserFirstParent(listParent &LParent, NodeParent nodeBaruParent){
    if(LParent.first == NULL) {
        LParent.first = LParent.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LParent.last;
        LParent.last->next = nodeBaruParent;
        LParent.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertLastChild(listChild &LChild, NodeChild nodeBaruChild){
    if(LChild.first == NULL) {
        LChild.first = LChild.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LChild.last;
        LChild.last->next = nodeBaruChild;
        LChild.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void hapusLastchild(ListAnak &LAnak){
    if(LAnak.first == NULL){
        cout <<"List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if(nodeHapus->prev != NULL){
            LAnak.last = nodeHapus->prev;
            LAnak.last->next = NULL;
        } else {
            LAnak.first = LAnak.last = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node child terakhir berhasil dihapus!" << endl;
    }
}

void searchFilmByratingRange(ListInduk &LInduk, float minRating, float maxRating){
    if(LInduk.first==NULL){
        cout <<"List induk kosong!"<< endl;
    }else{
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent =1;
        bool ketemu = false;
        while(nodeBantuParent !=NULL){
            NodeChild nodeBantuChild = nodeBantuparent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->ratingFilm >= minRating && nodeBantuChild->ratingFilm <= maxRating){
                    cout << "data Film ditemukan pada list child dari node parent " << nodeBantuParent->namaGenre << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- data Film (Child)---" << endl;
                    cout << "Judul Film : " <<nodeBantuChild->judulFilm<< endl;
                    cout << "Posisi dalam list anak : " <<nodeBantuChild->ratingFilm<< endl;
                    cout << "ID Film : " <<nodeBantuChild->idFilm<< endl;
                    cout << "Durasi Film : " <<nodeBantuChild->durasiFilm<< endl;
                    cout << "Tahun Tayang : " <<nodeBantuChild->tahunTayang<< endl;
                    cout << "Rating Film : " <<nodeBantuChild->ratingFilm<<endl;
                    cout << "-----------------------------" << endl;
                    cout << "--- data Genre (Parent)---" << endl;
                    cout << "ID Genre : " <<nodeBantuParent->idGenre<< endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Genre : " <<nodeBantuParent->namaGenre<< endl;
                    ketemu = true;

                }
                nodeBantuChild = nodeBantuChild->next;
                indexChild++;
            }
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}