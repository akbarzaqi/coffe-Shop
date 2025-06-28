#include <iostream>
#include <string>
#include "User/user.h"
#include "Menu/menu.h"
#include "Payment/payment.h"
#include "OrderItem/orderitem.h"
using namespace std;

User user;
Menu menu;
OrderItem order;
Payment payment;

string g_uname, g_pass;
bool isLogin = false;
bool isAdmin = false;
bool isStaff = false;

int getPrice(int id);

int main() 
{

    
    user.addUser("akbar", "123", "92378374723");

    for(;;)
    {
        while(1)
        {
          
           char answer; 
           cout << "==== LOGIN KARYAWAN ====" << endl << endl;
           cout << "apakah sudah punya akun? (y/n) : ";
           cin >> answer;

           if(answer == 'y')
           {
            cin.ignore();
            cout << "masukan username : ";
            getline(cin, g_uname);
            cout << "masukan password : ";
            getline(cin, g_pass);
            cout << endl;
            if(g_uname == "admin" && g_pass == "admin")
            {
                isAdmin = true;
                break;
            }
            else 
            {
                if(user.isLogin(g_uname, g_pass))
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
                    else if (choose == 2)
                    {
                        int id;
                        order.showOrderItem();
                        cout << "\t\t\t\t === Hapus Item ===" << endl;
                        cout << "masukan id yang ingin dihapus : ";
                        cin >> id;
                        order.delOrderItem(id);
                        order.showOrderItem();
                    }
                    
                    else if(choose == 3)
                    {
                        order.showOrderItem();
                    }
                    else if(choose == 4)
                    {
                        break;
                    }
                    else 
                    {
                        cout << "pilihan yang anda masukan tidak sesuai" << endl;
                    }
                }
                break;
            
            case 2:
                while (1)
                {
                    int totalPrice = 0 ;
                    int choose;
                    int idUser = user.user[0].id_user;
                    int pay;
                    int payback;
                    char answer;
                    char input;
                    string staffName = g_uname;
                    string customerName;
                    string orderTime = "14-4-2025, 15.55";
                    string status = "success";
                    string paymentMethod;
                    
                    int idItem;
                    string menuName;
                    int qty;
                    int subtotal;

                    cout << "\t\t\t\t=== Menu Pembayaran ===" << endl;
                    order.showOrderItem();
                    cout << "------------------------------------------------------" << endl;
                    for(int i = 0; i < order.countData(); i++)
                    {
                        totalPrice += order.order[i].subtotal;
                    }
                    cout << "Total Pesanan : " << totalPrice;
                    cout << endl;
                    cout << "Masukan nama customer : ";
                    cin >> customerName;
                    cout << "1. Cash" << endl;
                    cout << "2. Virtual Account" << endl;
                    cout << "Pilih metode pembayaran : ";
                    cin >> choose;
                    if(choose == 1)
                    {
                        while(1)
                        {
                            cout << "masukan jumlah uang anda : ";
                            cin >> pay;
                            if(pay < totalPrice)
                            {
                                cout << "uang tidak mencukupi!" << endl << endl;
                                cout << "ingin melakukan pembayaran lagi? (y/n) : ";
                                cin >> answer;

                                if(answer == 'n')
                                    break;
                            }
                            else
                            {
                                payback = pay - totalPrice;
                                break;
                            }
                        }
                        
                        paymentMethod = "Cash";
                        
                    }
                    else if(choose == 2)
                    {
                        cout << "Masukan kode virtual account dibawah ini" << endl;
                        cout << "9837 1239 2390 9324" << endl;
                        
                        paymentMethod = "Virtual Account";
                    }
                     if(answer == 'n')
                        break; 

                    string test;
                    cin.ignore();
                    cout << "\nkonfirmasi pembayaran (Tekan enter!)";
                    getline(cin, test);

                    for(int i = 0; i < order.countData(); i++)
                    {
                         idItem =  order.order[i].idItem;
                         menuName = order.order[i].menuName;
                         qty = order.order[i].qty;
                         subtotal = order.order[i].subtotal;

                        payment.AddItem(idItem, menuName, qty, subtotal);
                       
                    }

                    payment.addItemToPayment();

                    payment.addPayment(idUser, staffName, customerName, orderTime, status, paymentMethod, totalPrice, payback);
                    break;
                }
                break;
            
            case 3:
                payment.showPaymentList();
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
                    cout << "2. Search menu" << endl;
                    cout << "3. Tambah menu baru" << endl;
                    cout << "4. Edit menu" << endl;
                    cout << "5. Hapus menu" << endl;
                    cout << "6. kembali ke menu utama" << endl;
                    cout << "masukan pilihan : ";
                    cin >> answer;
                    
                        if(answer == 1)
                        {
                            menu.showMenu();
                            while(1)
                            {
                                int choose;
                               
                                cout << " === Sorting ===" << endl;
                                cout << "1. Asccending" << endl;
                                cout << "2. Descending" << endl;
                                cout << "3. kembali ke menu utama" << endl;
                                cout << "masukan pilihan : ";
                                cin >> choose;

                                if(choose == 1)
                                {
                                    menu.selectionASC();
                                    menu.showMenu();
                                }
                                else if(choose == 2)
                                {
                                    menu.selectionDSC();
                                    menu.showMenu();
                                }
                                else if(choose == 3)
                                {
                                    break;
                                }
                            }
                        }
                        else if(answer == 2)
                        {
                            string menuName;
                            menu.showMenu();
                            cout << "\t\t\t\t=== Search Menu ===" << endl;
                            cout << "masukan nama menu : ";
                            cin >>  menuName;

                            menu.searchMenu(menuName);
                        }

                        else if(answer == 3)
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
                        else if(answer == 4)
                        {
                           int id; 
                           menu.showMenu();
                           cout << "=== Edit Menu ===" << endl << endl;
                           cout << "masukan id yang ingin diupdate : ";
                           cin >> id;
                           menu.updateMenu(id);
                           cout << endl;
                        }
                        else if(answer == 5)
                        {
                          int id;  
                          menu.showMenu();
                          cout << "=== Hapus Menu ===" << endl;
                          cout << "masukan id menu yang ingin dihapus : ";
                          cin >> id;
                          menu.delMenu(id);

                        }
                        else if(answer == 6)
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


// algoritma paymentt
// int main()
// {
//     // order.addItem(1, "jadsf", 2, 20000);
//     // order.addItem(2, "sdfsdf", 2, 30000);

//     // for(int i = 0; i < order.countData(); i++)
//     // {
//     //     payment.testAddItem(order.order[i].idItem);
//     // }

//     // payment.addItemToPayment();
//     // payment.addPayment(1);

//     // payment.showPaymentList();
//     menu.showMenu();
//     menu.selectionDSC();
//     menu.showMenu();
    

// }

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