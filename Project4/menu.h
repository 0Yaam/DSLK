void XuatMenu()
{
    cout << "0. Thoat chuong trinh" << endl;
    cout << "1. (2.0 d) Nhap danh sach nhan vien tu file." << endl;
    cout << "2. (1.5 d) Xuat danh sach nhan vien." << endl;
    cout << "3. (1.0 d) Dem so luong nhan vien co nam sinh >= 2000" << endl;
    cout << "4. (1.5 d) Tim kiem tuyen tinh: theo ten nhan vien, tra ve node cuoi cung." << endl;
    cout << "5. (1.0 d) Chen 1 nhan vien sau nhan vien co ma nhan vien=x (x nhap tu ban phim)." << endl;
    cout << "6. (1.5 d) Xoa tat ca nhan vien theo ten nhan vien." << endl;
    cout << "7. (1.0 d) Chon truc tiep" << endl;
    cout << "8. (1.0 d) Chen truc tiep" << endl;
    cout << "9. (1.0 d) Doi cho truc tiep" << endl;
    cout << "10. (1.0 d) Bubble sort" << endl;
    cout << "11. (1.0 d) Radix sort" << endl;
    cout << "12. (1.0 d) Binary search" << endl;
    cout << "13. (1.0 d) THong ke" << endl;
}


int ChonMenu(int soMenu)
{
    int stt;
    do
    {
        system("cls");
        XuatMenu();
        cout << "Nhap lua chon: "; cin >> stt;
    } while (stt < 0 || stt > soMenu);
    return stt;
}

void XuLyMenu(List& l, int menu)
{
    string maNV;
    string ten;
    Node* p = NULL;
    switch (menu)
    {
    case 0:cout << "Thoat" << endl;

        break;
    case 1:cout << "DocFile" << endl;
        DocFile(l, "data.txt");
        break;
    case 2:cout << "Xuat" << endl;
        XuatDSSV(l);
        break;
    case 5:
        XuatDSSV(l);
        cout << "Nhap ma nhan vien can chen: "; cin >> maNV;
        Chen(l, maNV);
        cout << "Sau khi chen " << endl;
        XuatDSSV(l);
        break;
    case 6:
        cout << "Danh sach nhan vien" << endl;
        XuatDSSV(l);
        cout << "Nhap ten can xoa: "; cin >> ten;
        Xoa(l, ten);
        cout << "\nDanh sach sau khi xoa\n";
        XuatDSSV(l);
        break;
    case 11:
        cout << "Bubble sort" << endl;
        XuatDSSV(l);
        RadixSort(l);
        cout << "Sau khi sap sep" << endl;
        XuatDSSV(l);
        break;
    case 12:
        XuatDSSV(l);
        cout << "Nhap ten can tim: "; cin >> ten;
        p = BinarySearch(l, ten);
        cout << "thong tin" << endl;
        Xuat1SV(p->info);
        break;
    case 13:
        XuatDSSV(l);
        cout << "thong tin" << endl;
        ThongKe(l);
        break;
    default:
        break;
    }
}