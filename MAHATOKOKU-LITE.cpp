// Tugas membuat Ecommerce dengan memanfaatkan Struktur data Map
//  Program ini merupakan program simulasi e-commerce sederhana yang memiliki database produk.
//  Tiap produk memiliki kode, nama, stok, dan harga.
//  Anda sebagai pelanggan memiliki saldo awal.
//  Anda bisa memilih salah satu produk yang akan dibeli (berdasarkan kode) dan menginputkan jumlahnya yang akan dibeli.
//  Ketika anda sudah membeli produk, kurangi stok produk dengan jumlah yang anda beli. Sesuaikan juga saldo akhir anda.

#include <iostream>
#include <map>
#include <iomanip>
#include <string>
using namespace std;

struct Product
{
    string productName;
    int stok;
    int price;
};

void daftarBarang(map<string, Product> &database)
{
    cout << "\t\tDAFTAR PRODUK" << endl;
    cout << setw(5) << "Kode" << setw(22) << "Nama" << setw(10) << "Stok" << setw(10) << "Harga" << endl;
    cout << "-----------------------------------------------" << endl;
    for (const auto &pair : database)
    {
        const Product &barang = pair.second;
        cout << setw(5) << pair.first << setw(22) << barang.productName << setw(10) << barang.stok << setw(10) << barang.price << endl;
    }
    cout << endl;
}

int main()
{
    cout << "=======================================================================================\n";
    cout << "\t\t\t   SELAMAT DATANG DI E-MAHATOKOKU\n";
    cout << "\t\t< Toko Online Kebutuhan Mahasiswa no.1 di Pekalongan > \n\n";
    cout << "\t\t SEDIA : \n";
    cout << "\t\t - Peralatan Sekolah dan Kuliah\n\t\t - Perabotan Rumah tangga\n\t\t - Peralatan Olahraga\n";
    cout << "=======================================================================================\n";

    // LOGIN
    string username;
    cout << "Masukkan Nama Anda\t: ";
    getline(cin, username);

    int saldo;
    cout << "Masukkan Saldo Anda\t: Rp.";
    cin >> saldo;

    cout << "=======================================================================================\n";
    cout << "User  : " << username << endl;
    cout << "Saldo : Rp." << saldo << endl;

    int input;
    int totalBelanja = 0;

    map<string, Product> database = {
        {"A001", {"Laptop", 30, 5500000}},
        {"A002", {"Monitor 4K", 40, 2750000}},
        {"A003", {"Flashdisk 32 GB", 50, 100000}},
        {"A004", {"Kalkulator", 50, 50000}},
        {"A005", {"Study Lamp", 50, 45000}},
        {"A006", {"Tempat Pensil", 50, 20000}},
        {"A007", {"Meja Lipat", 50, 200000}},
        {"A008", {"Gunting", 50, 30000}},
        {"A009", {"Penggaris", 50, 10000}},
        {"A010", {"Lem", 50, 10000}},
        {"A011", {"Tas selempang", 50, 75000}},
        {"A012", {"Kabel USB", 50, 15000}},
        {"A013", {"Mouse", 50, 100000}},
        {"A014", {"Keyboard Eksternal", 50, 150000}},
        {"A015", {"Dompet", 50, 50000}},
        {"A016", {"Tabungan", 50, 30500}},
        {"A017", {"Notebook SIDU", 50, 15000}},
        {"A018", {"Notebook A5", 50, 13500}},
        {"A019", {"Pensil", 50, 3000}},
        {"A020", {"Polpen tinta biru", 50, 4000}},
        {"A021", {"Polpen tinta merah", 50, 4000}},
        {"A022", {"Polpen tinta hitam", 50, 4000}},
        {"A023", {"Casing HP", 50, 30000}},
        {"A024", {"Tumblr/Tempat Minum", 50, 40000}},
        {"A025", {"Kotak Makanan", 50, 45000}},
        {"A026", {"Sepatu", 50, 150000}},
        {"A027", {"Lap Meja", 50, 15000}},
        {"A028", {"Sandal", 50, 10000}},
        {"A029", {"Keset Lantai", 50, 12000}},
        {"A030", {"Sapu", 50, 14000}},
        {"A031", {"Kemoceng", 50, 14000}},
        {"A032", {"Magicom", 50, 120000}},
        {"A033", {"Termos Listrik", 50, 150000}},
        {"A034", {"Panci Listrik", 50, 150000}},
        {"A035", {"Sendok", 50, 3000}},
        {"A036", {"Garpu", 50, 3000}},
        {"A037", {"Piring", 50, 5000}},
        {"A038", {"Raket Badminton", 50, 50000}},
        {"A038", {"Raket Tenis", 50, 55000}},
        {"A038", {"Suttlecock", 50, 5000}},
        {"A038", {"Bola basket", 50, 45000}},
        {"A038", {"Bola", 50, 50000}},
        {"A038", {"Bola bekel", 50, 12000}},
        {"A038", {"Bola voli", 50, 65000}},
    };

    do
    {
        cout << endl;
        cout << "\tAYO BELANJA! PILIH JENIS KEBUTUHANMU!" << endl;

        daftarBarang(database);

        string codeProduct;
        int jumlahBeli;
        int count = 0;
        cout << "Masukkan Kode Produk yang akan dibeli : ";
        cin >> codeProduct;
        cout << "Masukkan Jumlah Produk yang akan dibeli : ";
        cin >> jumlahBeli;

        // find a product based on its code
        auto it = database.find(codeProduct);
        if (it != database.end())
        {
            Product &barang = it->second;
            if (barang.stok >= jumlahBeli)
            {
                barang.stok -= jumlahBeli;

                int totalHarga = jumlahBeli * barang.price;
                totalBelanja += totalHarga;
                if (saldo > totalBelanja)
                {
                    saldo -= totalHarga;

                    count++;
                    cout << endl;
                    cout << "PEMBELIAN BERHASIL" << endl;
                    cout << "Stok barang tersisa " << barang.stok << endl;
                    cout << "Total Harga Produk yang dibeli : " << totalHarga << endl;
                    cout << "Sisa saldo  : Rp." << saldo << endl;
                    cout << endl;
                }

                else if (saldo < totalBelanja)
                {
                    barang.stok += jumlahBeli;
                    totalBelanja -= totalHarga;
                    cout << "\nMaaf Saldo Anda tidak mencukupi\n"
                         << endl;
                    cout << "Saldo Anda : " << saldo << endl;
                    if (saldo == 0 && count == 0)
                    {
                        cout << "---------------------------------------------------------------------------------------\n";
                        cout << "\t\t\tTERIMA KASIH TELAH BERKUNJUNG :)" << endl;
                        return 0;
                    }
                    else if (saldo <= 0)
                    {
                        saldo = 0;
                        goto Nota;
                    }
                }
            }
            else
            {
                cout << "Maaf stok produk yang akan dibeli tidak mencukupi\n";
                cout << endl;
            }
        }
        else
        {
            cout << "Produk tidak ditemukan\n";
            cout << endl;
        }

        cout << "Ingin Belanja lagi? [1] IYA [0] TIDAK" << endl;
        cout << ">> ";
        cin >> input;
        cout << endl;

    } while (input == 1);

Nota:

    cout << "---------------------------------------------------------------------------------------\n";
    cout << "Username\t\t\t: " << username << endl;
    cout << "Total Belanja Anda\t\t: Rp." << totalBelanja << endl;
    cout << "Sisa Saldo yang dimiliki\t: Rp." << saldo << endl;
    cout << "=======================================================================================\n";
    cout << "\t\t\tTERIMA KASIH TELAH BELANJA DI E-MAHATOKOKU" << endl;
    cout << "=======================================================================================\n";

    return 0;
}