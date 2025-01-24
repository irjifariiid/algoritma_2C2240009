#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

class ATM {
private:
    string cardNumber;
    string pin;
    double saldo;
    string filename;

    void clearScreen() {
        for(int i = 0; i < 50; i++) {
            cout << endl;
        }
    }

public:
    ATM() {
        filename = "atm_data.txt";
        loadData(); // deklarasi file data txt
    }

    void loadData() {
        ifstream file(filename);
        file >> cardNumber >> pin >> saldo;
        file.close(); // Fungsi untuk membaca data dari file txt
    }

    void saveData() {
        ofstream file(filename);
        if (file.is_open()) {
            file << cardNumber << " " << pin << " " << saldo;
            file.close(); // Fungsi untuk menyimpan data terbaru ke file txt
        }
    }
    // Cek pin sesuai dengan data 
    bool checkPin(string inputPin) {
        return inputPin == pin;
    }
    // Fungsi-fungsi menu yang akan di panggil di fungsi utama/simulasi
    void showMenuBahasa() {
        cout << "=============================" << endl;
        cout << "Pilih Bahasa / Choose Language:" << endl;
        cout << "1. Indonesia" << endl;
        cout << "2. English" << endl;
        cout << "=============================" << endl;
        cout << "Pilihan / Choice: ";
    }

    void showMenuID() {
        cout << "=============================" << endl;
        cout << "Menu ATM:" << endl;
        cout << "1. Cek Saldo" << endl;
        cout << "2. Tarik Tunai" << endl;
        cout << "3. Transfer" << endl;
        cout << "4. Keluar" << endl;
        cout << "=============================" << endl;
        cout << "Pilihan: ";
    }

    void showMenuEN() {
        cout << "=============================" << endl;
        cout << "ATM Menu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Transfer" << endl;
        cout << "4. Exit" << endl;
        cout << "=============================" << endl;
        cout << "Choice: ";
    }

    void showWithdrawMenuID() {
        cout << "=============================" << endl;
        cout << "Pilih jumlah penarikan:" << endl;
        cout << "1. Rp 50.000" << endl;
        cout << "2. Rp 100.000" << endl;
        cout << "3. Rp 500.000" << endl;
        cout << "4. Rp 1.000.000" << endl;
        cout << "5. Jumlah lain" << endl;
        cout << "6. Kembali" << endl;
        cout << "=============================" << endl;
        cout << "Pilihan: ";
    }

    void showWithdrawMenuEN() {
        cout << "=============================" << endl;
        cout << "Choose withdrawal amount:" << endl;
        cout << "1. Rp 50,000" << endl;
        cout << "2. Rp 100,000" << endl;
        cout << "3. Rp 500,000" << endl;
        cout << "4. Rp 1,000,000" << endl;
        cout << "5. Other amount" << endl;
        cout << "6. Back" << endl;
        cout << "=============================" << endl;
        cout << "Choice: ";
    }
    // Algoritma untuk opsi penarikan tunai
    void processWithdrawal(double amount, bool isIndonesian) {
        if (amount > saldo) {
            if (isIndonesian)
                cout << "\nMaaf, saldo tidak mencukupi!" << endl;
            else
                cout << "\nSorry, insufficient balance!" << endl;
            return;
        }

        saldo -= amount;
        saveData();

        if (isIndonesian)
            cout << "\nSilahkan ambil uang Anda sejumlah Rp " << amount << endl;
        else
            cout << "\nPlease take your money Rp " << amount << endl;

        if (isIndonesian)
            cout << "\nApakah Anda ingin melihat saldo terbaru? (Y/T): ";
        else
            cout << "\nDo you want to check your updated balance? (Y/N): ";
        
        char choice;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            if (isIndonesian)
                cout << "\nSaldo Anda saat ini: Rp " << saldo << endl;
            else
                cout << "\nYour current balance: Rp " << saldo << endl;
        }

        if (isIndonesian)
            cout << "\nTerima kasih telah menggunakan ATM kami!" << endl;
        else
            cout << "\nThank you for using our ATM!" << endl;
        cout << "Kartu Anda telah dikembalikan." << endl;
    }
    // Algoritma untuk opsi Transfer
    void processTransfer(bool isIndonesian) {
        string recipientAccount;
        double transferAmount;

        if (isIndonesian) {
            cout << "Masukkan nomor rekening tujuan: ";
            cin >> recipientAccount;
            cout << "Masukkan jumlah transfer: ";
            cin >> transferAmount;
        } else {
            cout << "Enter recipient account number: ";
            cin >> recipientAccount;
            cout << "Enter transfer amount: ";
            cin >> transferAmount;
        }

        if (transferAmount > saldo) {
            if (isIndonesian)
                cout << "\nMaaf, saldo tidak mencukupi!" << endl;
            else
                cout << "\nSorry, insufficient balance!" << endl;
            return;
        }

        saldo -= transferAmount;
        saveData();

        if (isIndonesian)
            cout << "\nTransfer berhasil." << endl;
        else
            cout << "\nTransfer successful." << endl;

        if (isIndonesian)
            cout << "\nApakah Anda ingin melihat saldo terbaru? (Y/T): ";
        else
            cout << "\nDo you want to check your updated balance? (Y/N): ";
        
        char choice;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            if (isIndonesian)
                cout << "\nSaldo Anda saat ini: Rp " << saldo << endl;
            else
                cout << "\nYour current balance: Rp " << saldo << endl;
        }

        if (isIndonesian)
            cout << "\nTerima kasih telah menggunakan ATM kami!" << endl;
        else
            cout << "\nThank you for using our ATM!" << endl;
        cout << "Kartu Anda telah dikembalikan." << endl;
    }
    // Fungsi utama untuk simulasi Program Mesin ATM
    void run() {
        int languageChoice;
        bool isIndonesian;
        string inputCardNumber;
        string inputPin;
        int attempts = 0;
        const int MAX_ATTEMPTS = 3;

        do {
            clearScreen();
            showMenuBahasa();
            cin >> languageChoice;
            isIndonesian = (languageChoice == 1);

            clearScreen();
            if (isIndonesian)
                cout << "Masukkan nomor kartu: ";
            else
                cout << "Enter card number: ";
            cin >> inputCardNumber;

            if (inputCardNumber != cardNumber) {
                if (isIndonesian)
                    cout << "Nomor kartu tidak valid!" << endl;
                else
                    cout << "Invalid card number!" << endl;
                cout << "Press Enter to continue...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                continue;
            }

            if (isIndonesian)
                cout << "Masukkan PIN: ";
            else
                cout << "Enter PIN: ";
            cin >> inputPin;
            attempts++;

            if (!checkPin(inputPin)) {
                if (isIndonesian)
                    cout << "PIN salah!" << endl;
                else
                    cout << "Wrong PIN!" << endl;
                if (attempts >= MAX_ATTEMPTS) {
                    if (isIndonesian)
                        cout << "Kartu Anda terblokir. Silahkan hubungi bank." << endl;
                    else
                        cout << "Your card is blocked. Please contact the bank." << endl;
                    return;
                }
                cout << "Press Enter to continue...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                continue;
            }
            break;
        } while (attempts < MAX_ATTEMPTS);

        while (true) {
            clearScreen();
            if (isIndonesian)
                showMenuID();
            else
                showMenuEN();

            int choice;
            cin >> choice;

            switch (choice) {
                case 1: // Cek Saldo
                    if (isIndonesian)
                        cout << "\nSaldo Anda: Rp " << saldo << endl;
                    else
                        cout << "\nYour Balance: Rp " << saldo << endl;
                    break;

                case 2: // Penarikan Tunai
                    while (true) {
                        clearScreen();
                        if (isIndonesian)
                            showWithdrawMenuID();
                        else
                            showWithdrawMenuEN();

                        int withdrawChoice;
                        cin >> withdrawChoice;

                        double amount = 0;
                        switch (withdrawChoice) {
                            case 1: amount = 50000; break;
                            case 2: amount = 100000; break;
                            case 3: amount = 500000; break;
                            case 4: amount = 1000000; break;
                            case 5:
                                if (isIndonesian)
                                    cout << "Masukkan jumlah (kelipatan 50000): ";
                                else
                                    cout << "Enter amount (multiple of 50000): ";
                                cin >> amount;
                                if (static_cast<int>(amount) % 50000 != 0) {
                                    if (isIndonesian)
                                        cout << "Jumlah harus kelipatan 50000!" << endl;
                                    else
                                        cout << "Amount must be multiple of 50000!" << endl;
                                    cout << "Press Enter to continue...";
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cin.get();
                                    continue;
                                }
                                break;
                            case 6: continue;
                            default:
                                if (isIndonesian)
                                    cout << "Pilihan tidak valid!" << endl;
                                else
                                    cout << "Invalid choice!" << endl;
                                cout << "Press Enter to continue...";
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin.get();
                                continue;
                        }

                        if (amount > 0) {
                            processWithdrawal(amount, isIndonesian);
                            return; 
                        }
                        break;
                    }
                    break;

                case 3: // Transfer
                    processTransfer(isIndonesian);
                    return; 
                    break;

                case 4: // Keluar
                    if (isIndonesian)
                        cout << "\nTerima kasih telah menggunakan ATM kami!" << endl;
                    else
                        cout << "\nThank you for using our ATM!" << endl;
                    cout << "Kartu Anda telah dikembalikan." << endl;
                    return;

                default:
                    if (isIndonesian)
                        cout << "Pilihan tidak valid!" << endl;
                    else
                        cout << "Invalid choice!" << endl;
            }

            cout << "\nPress Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    }
};

// Menampilkan simulasi di output
int main() {
    ATM atm;
    atm.run();
    return 0;
}