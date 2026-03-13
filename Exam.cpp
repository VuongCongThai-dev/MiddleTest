/*
Example 01: Quan ly sach
Tạo class Sach
Thuộc tính
-maSach
-tenSach
-gia
Yêu cầu
+Constructor
+Destructor
+Setter / Getter
+Hàm xuat()
Main
Tạo mảng con trỏ đối tượng sách
Nhập n sách
In danh sách.
*/

#include <iostream>
using namespace std;

class VuongCongThai
{
private:
    string maSach;
    string tenSach;
    double gia;

public:
    VuongCongThai()
    {
        maSach = "";
        tenSach = "";
        gia = 0;
    }

    VuongCongThai(string maSach, string tenSach, double gia)
    {
        this->maSach = maSach;
        this->tenSach = tenSach;
        this->gia = gia;
    }

    ~VuongCongThai()
    {
        cout << "Da huy doi tuong sach " << tenSach << " co ma sach la: " << maSach << endl;
    }

    void setMaSach(string maSach) { this->maSach = maSach; }
    string getMaSach() { return this->maSach; }

    void setTenSach(string tenSach) { this->tenSach = tenSach; }
    string getTenSach() { return this->tenSach; }

    void setGia(double gia) { this->gia = gia; }
    double getGia() { return this->gia; }

    void nhap()
    {
        cout << "Nhap ma sach: ";
        cin.ignore();
        getline(cin, maSach);
        cout << "Nhap ten sach: ";
        getline(cin, tenSach);
        do
        {
            cout << "Nhap gia sach: ";
            cin >> gia;
            if (gia <= 0)
            {
                cout << "Gia sach phai lon hon 0. Vui long nhap lai!" << endl;
            }
        } while (gia <= 0);
    }

    void xuat()
    {
        cout << "Ma sach: " << maSach << endl;
        cout << "Ten sach: " << tenSach << endl;
        cout << "Gia: " << gia << endl;
    }
};

int main()
{
    int n;
    do
    {
        cout << "Nhap so luong sach: ";
        cin >> n;
        if (n < 0)
        {
            cout << "So luong sach phai lon hon 0. Vui long nhap lai." << endl;
        }
    } while (n < 0);

    VuongCongThai *sach[n];
    for (int i = 0; i < n; i++)
    {
        sach[i] = new VuongCongThai();
        sach[i]->nhap();
    }

    cout << "\nDanh sach sach" << endl;
    ;
    for (int i = 0; i < n; i++)
    {
        cout << "Sach " << i + 1 << endl;
        (*(sach + i))->xuat();
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete *(sach + i);
        cout << "Da xoa sach " << i + 1 << endl;
    }
    return 0;
}
