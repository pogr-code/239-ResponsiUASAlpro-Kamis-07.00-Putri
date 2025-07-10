#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 100;

struct Produk{
	string kode;
	string nama;
	int harga;
	int jumlah;
	int totalp;
};

Produk data [MAX];
int n = 0;

void bacaFile(const string& namaFile){
	ifstream file(namaFile);
	if (!file){
		cout << "File tidak ditemukan!"<<endl;
		return;
	}
	while(getline(file,data[n].kode,',')){//baris ambil kode dari file
		getline(file,data[n].nama,',');//baris ambil nama 
		file >> data[n].jumlah;
		file.ignore();
		file >> data[n].harga;
		file.ignore();
		data[n].totalp=data[n].harga * data[n].jumlah;
		n++;
	}
	file.close();
	cout << "File berhasil dibaca !\n";// file punya format = kode, nama, jumlah, harga. kode disusun sesuai urutan
}

void cariKode(const string& kode) {
    for (int i = 0; i < n; ++i) {
        if (data[i].kode == kode) {
            cout << "Produk ditemukan: " << data[i].nama << ", Harga: " << data[i].harga << ", Jumlah: " << data[i].jumlah << endl;
            return;
        }
    }
    cout << "Produk dengan kode " << kode << " tidak ditemukan.\n";
}

void cariTermurah() {
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        if (data[i].harga < data[idx].harga) {
            idx = i;
            
        }
    }
    cout << "Produk termurah: " << data[idx].nama << ", Harga: " << data[idx].harga << endl;
}
void sortTermahal() {
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (data[i].harga < data[j].harga) {
                swap(data[i], data[j]);
                
            }
        }
    }
}

void sortTermurah() {
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (data[i].harga > data[j].harga) {
                swap(data[i], data[j]);
            }
        }
    }
}

int totalPendapatanSemua() {
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += data[i].totalp;
    }
    return total;
}

void tampil(){
	for (int i=0;i<n;i++){
		cout << data[i].harga<<",";
	}
}

int main(){//cara print ke file?? gatau dah
	bacaFile("data.txt");
	
	cout << "\nCari produk berdasarkan kode (kode : P001 - P010): ";
    string kode;
    cin >> kode;
    cariKode(kode);

    cout << "\nMencari produk termurah:\n";
    cariTermurah();

    cout << "\nUrutkan dari harga termahal ke termurah:\n";
    sortTermahal();
    tampil();

    cout << "\nUrutkan dari harga termurah ke termahal:\n";
    sortTermurah();
    tampil();

    cout << "\nTotal seluruh pendapatan: " << totalPendapatanSemua() << endl;
}

