#include <iostream>
#include <string>
#include "User/user.h"
#include "Menu/menu.h"
#include "OrderItem/orderitem.h"
using namespace std;

User user;
Menu menu;
OrderItem order;

int getPrice(int id);

int main() 
{
    bool isLogin = false;
    bool isAdmin = false;
    bool isStaff = false;
    
    user.addUser("akbar", "123", "92378374723");

    for(;;)
    {
        while(1)
        {
           string uname, pass;
           char answer; 
           cout << "==== LOGIN KARYAWAN ====" << endl << endl;
           cout << "apakah sudah punya akun? (y/n) : ";
           cin >> answer;

           if(answer == 'y')
           {
            cin.ignore();
            cout << "masukan username : ";
            getline(cin, uname);
            cout << "masukan password : ";
            getline(cin, pass);
            cout << endl;
            if(uname == "admin" && pass == "admin")
            {
                isAdmin = true;
                break;
            }
            else 
            {
                if(user.isLogin(uname, pass))
                {
                    isStaff = true;
                    break;
                }
                else 
                    cout << "username atau password yang anda masukan salah" << endl << endl;
            }
           
           }
        }
        while(isStaff)
        {
            int choise, choose;

            cout << "=== SELAMAT DATANG DI COFFE SHOP ===" << endl;
            cout << "1. Buat Pesanan" << endl;
            cout << "2. Pembayaran" << endl;
            cout << "3. Riwayat Transaksi" << endl;
            cout << "4. Logout" << endl;
            cout << "masukan pilihan : ";
            cin >> choise;
            
            switch (choise)
            {
            case 1:
                while (1)
                {
                    cout << "=== Menu Buat Pesanan ===" << endl;
                    cout << "1. Tambah item ke keranjang" << endl;
                    cout << "2. Hapus item dari keranjang" << endl;
                    cout << "3. Lihat keranjang" << endl;
                    cout << "4. kembali ke menu utama" << endl;
                    cout << "masukan pilihan : ";
                    cin >> choose;

                    if(choose == 1)
                    {
                        int id, idx;
                        int idItem;
                        string menuName;
                        int qty;
                        int subtotal;

                        menu.showMenu();
                        cout << "\t\t\t\t=== Keranjang ===" << endl;
                        cout << "masukan id yang ingin dimasukan ke keranjang : ";
                        cin >> id;

                        for(int i = 0; i < menu.countData(); i++)
                        {
                            if(id == menu.menu[i].id_menu)
                            {
                                idx = i;
                                break;
                            }
                        }

                        if(menu.menu[idx].stock != 0)
                        {
                            cout << "masukan jumlah menu : ";
                            cin >> qty;

                            if(qty > menu.menu[idx].stock)
                            {
                                cout << "maaf stok tidak mencukupi" << endl;
                            }
                            else 
                            {
                                idItem = menu.menu[idx].id_menu;
                                menuName = menu.menu[idx].menu_item;
                                subtotal = qty * menu.menu[idx].price;

                                menu.menu[idx].stock -= qty; 

                                order.addItem(idItem, menuName, qty, subtotal);
                                cout << "item berhasil dimasukan ke keranjang" << endl;
                            }
                        }
                        else 
                        {
                            cout << "maaf stok menu habis" << endl;
                        }
                    }
                    else if(choose == 3)
                    {
                        order.showOrderItem();
                    }
                }
                
               
                break;
            
            default:
                break;
            }

        }
        
        while(isAdmin)
        {
            int choise, answer;
            cout << "=== Selamat Datang di Halaman Admin ===" << endl;
            cout << "1. Kelola User" << endl;
            cout << "2. Kelola Menu" << endl;
            cout << "3. Riwayat Transaksi" << endl;
            cout << "4. Logout" << endl;
            cout << "masukan pilihan : ";
            cin >> choise;

            switch (choise)
            {
            case 1:
                while(1)
                {
                    cout << "=== Kelola User ===" << endl;
                    cout << "1. Lihat daftar user" << endl;
                    cout << "2. Tambah data user" << endl;
                    cout << "3. Edit data user" << endl;
                    cout << "4. Hapus data user" << endl;
                    cout << "5. Kembali ke menu utama" << endl;
                    cout << "masukan pilihan : ";
                    cin >> answer;
                    cout << endl;
                    
                        if(answer == 1)
                        {
                            user.showUser();
                            cout << endl;
                        }
                        else if(answer == 2)
                        {
                            string uname, pass, no_telp;

                            cout << "=== Tambah Data User ===" << endl << endl;
                            cin.ignore();
                            cout << "masukan username : ";
                            getline(cin, uname);
                            cout << "masukan password : ";
                            getline(cin, pass);
                            cout << "masukan no telp : ";
                            getline(cin, no_telp);
                            user.addUser(uname, pass, no_telp);
                            cout << endl;
                        }
                        else if(answer == 3)
                        {
                            int id;
                            cout << "=== Update Data User ===" << endl << endl;
                            user.showUser();
                            cout << "masukan id yang ingin diupdate : ";
                            cin >> id;
                            user.updateData(id);
                            cout << endl;
                        }
                        else if(answer == 4)
                        {
                            int id;
                            cout << "=== Hapus Data User ===" << endl;
                            user.showUser();

                            cout << "masukan id yang ingin dihapus : ";
                            cin >> id;
                            user.delUser(id);
                        }
                        else if(answer == 5)
                        {
                            break;
                        } 
                }

                break;
            case 2:
               while(1)
               {
                    string menu_item, category;
                    int price, stock, choose;

                    cout << "\t\t\t\t=== Kelola Menu ===" << endl;
                    cout << "1. Lihat semua menu" << endl;
                    cout << "2. Tambah menu baru" << endl;
                    cout << "3. Edit menu" << endl;
                    cout << "4. Hapus menu" << endl;
                    cout << "5. kembali ke menu utama" << endl;
                    cout << "masukan pilihan : ";
                    cin >> answer;
                    
                        if(answer == 1)
                        {
                            menu.showMenu();
                        }
                        else if(answer == 2)
                        {
                           cout << "=== Tambah Menu Baru ===" << endl << endl;
                           cin.ignore();
                           cout << "masukan nama menu : ";
                           getline(cin, menu_item);
                           cout << "masukan harga menu : ";
                           cin >> price;
                           cout << "masukan stock menu : ";
                           cin >> stock;
                           cout << "1. makanan" << endl;
                           cout << "2. minuman" << endl;
                           cout << "pilih kategori : ";
                           cin >> choose;
                           if(choose == 1)
                                category = "makanan";
                           else if(choose == 2)
                                category = "minuman";
                           else 
                                cout << "pilihan yang anda masukan tidak sesuai" << endl;
                            
                           menu.addMenu(menu_item, price, stock, category); 

                        }
                        else if(answer == 3)
                        {
                           int id; 
                           menu.showMenu();
                           cout << "=== Edit Menu ===" << endl << endl;
                           cout << "masukan id yang ingin diupdate : ";
                           cin >> id;
                           menu.updateMenu(id);
                           cout << endl;
                        }
                        else if(answer == 4)
                        {
                          int id;  
                          menu.showMenu();
                          cout << "=== Hapus Menu ===" << endl;
                          cout << "masukan id menu yang ingin dihapus : ";
                          cin >> id;
                          menu.delMenu(id);

                        }
                        else if(answer == 5)
                        {
                            break;
                        } 
               }

               break;
            
            default:
               cout << "inputan yang anda masukan tidak sesuai" << endl;
                break;
            }
        }
    }
    
}

int getPrice(int id)
{
    int idx;
    int price;
    for(int i = 0; i < menu.countData(); i++)
    {
        if(id == menu.menu[i].id_menu)
            idx = i;
    }

    price = menu.menu[idx].price;
    return price;
}