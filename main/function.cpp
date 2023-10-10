#pragma once
#pragma warning
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "function.h"
#include "struct.h"
using namespace std;
#define MAX 200
int Ngay(int d, int m, int y) {
	int day = d;
	int i;
	if (y % 100 == 0) {
		if (y % 400 == 0) {
			y = 1;
		}
		else {
			y = 0;
		}
	}
	else if (y % 4 == 0) {
		y = 1;
	}
	else {
		y = 0;
	}
	if (y == 0) {
		for (i = 0; i <= m - 1; i++) {
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
				day = day + 31;
			}
			if (i == 2) day = day + 28;
			if (i == 4 || i == 6 || i == 9 || i == 11) day = day + 30;
		}
	}
	if (y == 1) {
		for (i = 0; i <= m - 1; i++) {
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
				day = day + 31;
			}
			if (i == 2) day = day + 29;
			if (i == 4 || i == 6 || i == 9 || i == 11) day = day + 30;
		}
	}
	return day;
}
int Namnhuan(int y) {
	if (y % 100 == 0) {
		if (y % 400 == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (y % 4 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
void ngaytrasach(int d1, int m1, int y1, int& d2, int& m2, int& y2) {
	d2 = 0;
	m2 = 0;
	y2 = 0;
	int tam = y1;
	if (tam % 100 == 0) {
		if (tam % 400 == 0) {
			tam = 1;
		}
		else {
			tam = 0;
		}
	}
	else if (tam % 4 == 0) {
		tam = 1;
	}
	else {
		tam = 0;
	}
	if (tam == 0) {
		d2 = d1 + 7;
		m2 = m1;
		y2 = y1;
		if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12) {
			if (d2 >= 32) {
				m2++;
				d2 = d2 - 31;
			}
			if (m2 == 13) {
				y2++;
				m2 = 1;
			}
		}
		if (m1 == 2) {
			if (d2 == 29) {
				m2++;
				d2 = d2 - 28;
			}
		}
		if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11) {
			if (d2 == 31) {
				m2++;
				d2 = d2 - 30;
			}
		}
	}
	if (tam == 1) {
		d2 = d1 + 7;
		m2 = m1;
		y2 = y1;
		if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12) {
			if (d2 == 32) {
				m2++;
				d2 = d2 - 31;
			}
			if (m2 == 13) {
				y2++;
				m2 = 1;
			}
		}
		if (m1 == 2) {
			if (d2 == 30) {
				m2++;
				d2 = d2 - 29;
			}
		}
		if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11) {
			if (d2 == 31) {
				m2++;
				d2 = d2 - 30;
			}
		}
	}
} //
// hàm tính ngày trả sách
int checktrasach(int d1, int m1, int  y1, int  d2, int  m2, int  y2) {
	double S1, S2;
	int i;
	S1 = Ngay(d1, m1, y1);
	for (i = 1; i <= y1 - 1; i++) {
		if (Namnhuan(i) == 0) S1 = S1 + 365;
		else S1 = S1 + 366;
	}
	S2 = Ngay(d2, m2, y2);
	for (i = 1; i <= y2 - 1; i++) {
		if (Namnhuan(i) == 0) S2 = S2 + 365;
		else S2 = S2 + 366;
	}
	return S1 - S2;
}
// hàm tính xem trả sách có đúng hạn hay không
void docthongtindg(const char* filein, inforeader dg[MAX], int& n) {
	int i = 0;
	ifstream file;
	file.open(filein, ios_base::in);
	while (file.eof() == false) {
		getline(file, dg[i].madocgia, ',');
		getline(file, dg[i].hotendg, ',');
		getline(file, dg[i].cmnd, ',');
		getline(file, dg[i].ngaysinh, '/');
		getline(file, dg[i].thangsinh, '/');
		getline(file, dg[i].namsinh, ',');
		getline(file, dg[i].gioitinh, ',');
		getline(file, dg[i].mail, ',');
		getline(file, dg[i].diachi, ',');
		getline(file, dg[i].ngaylap, '/');
		getline(file, dg[i].thanglap, '/');
		getline(file, dg[i].namlap, ',');
		getline(file, dg[i].ngayhh, '/');
		getline(file, dg[i].thanghh, '/');
		getline(file, dg[i].namhh);
		i++;
	}
	if (dg[0].madocgia == "") n = 0;
	else n = i;
	file.close();
}
void docthongtinsach(const char* filein, infobooks sach[MAX], int& n) {
	int i = 0;
	ifstream file;
	file.open(filein, ios_base::in);
	while (file.eof() == false) {
		getline(file, sach[i].isbn, ',');
		getline(file, sach[i].tensach, ',');
		getline(file, sach[i].tacgia, ',');
		getline(file, sach[i].nhaxuatban, ',');
		getline(file, sach[i].namxb, ',');
		getline(file, sach[i].theloai, ',');
		getline(file, sach[i].giasach, ',');
		getline(file, sach[i].soquyensach);
		i++;
	}
	if (sach[0].isbn == "") n = 0;
	else n = i;
	file.close();
}
void docthongtinphieumuon(const char* filein, phieumuonsach phieumuon[MAX], int& soluongphieumuon, int& soluongsachmuon) {
	int i = 0;
	char x;
	ifstream file;
	file.open(filein, ios_base::in);
	while (file.eof() == false) {
		getline(file, phieumuon[i].madgmuon, ',');
		file >> phieumuon[i].ngaymuon >> x >> phieumuon[i].thangmuon >> x >> phieumuon[i].nammuon >> x >> phieumuon[i].ngaytradukien >> x >> phieumuon[i].thangtradukien >> x >> phieumuon[i].namtradukien >> x;
		file >> phieumuon[i].soluongsachdgmuon >> x;
		for (int j = 0; j < phieumuon[i].soluongsachdgmuon; j++) {
			if (j < phieumuon[i].soluongsachdgmuon - 1) getline(file, phieumuon[i].sachduocmuontheodg[j], ' ');
			else getline(file, phieumuon[i].sachduocmuontheodg[j]);
		}
		soluongsachmuon = soluongsachmuon + phieumuon[i].soluongsachdgmuon;
		i++;
	}
	if (phieumuon[0].madgmuon == "") {
		soluongsachmuon = 0;
		soluongphieumuon = 0;
	}
	else soluongphieumuon = i;
	file.close();
}
void docthongtindgtrehan(const char* filein, string madgtrehan[MAX],int& n) {
	int i = 0;
	ifstream file;
	file.open(filein, ios_base::in);
	while (file.eof() == false) {
		getline(file, madgtrehan[i]);
		i++;
	}
	if (madgtrehan[0] == "") n = 0;
	else n = i;
	file.close();
}
// hàm đọc thông tin từ file để xử lý
void ngayhh(string& a, string& b) {
	int x = atoi(a.c_str());
	x = x + 4;
	b = to_string(x);
}
void themsach(string& a, int c) {
	int x = atoi(a.c_str());
	x = x + c;
	a = to_string(x);
}
int menu() {
	int choice;
	cout << "Ban muon thuc hien chuc nang gi ?" << endl;
	cout << "1. Quan li doc gia." << endl;
	cout << "2. Quan li sach." << endl;
	cout << "3. Lap phieu muon sach." << endl;
	cout << "4. Lap phieu tra sach." << endl;
	cout << "5. Cac thong ke co ban." << endl;
	cout << "Vui long chon phim chuc nang tuong ung voi thu tu tren: ";
	cin >> choice;
	return choice;
}
int menu1() {
	int choice;
	cout << endl;
	cout << "Ban da chon thao tac \"Quan li doc gia\"." << endl;
	cout << "Ban muon thuc hien chuc nang gi ?" << endl;
	cout << "1. Xem danh sach doc gia trong thu vien." << endl;
	cout << "2. Them doc gia." << endl;
	cout << "3. Chinh sua thong tin doc gia." << endl;
	cout << "4. Xoa thong tin mot doc gia." << endl;
	cout << "5. Tim kiem doc gia theo CMND." << endl;
	cout << "6. Tim kiem sach theo ho ten." << endl;
	cout << "Vui long chon phim chuc nang tuong ung voi thu tu tren: ";
	cin >> choice;
	return choice;
}
void cau1a(inforeader dg[MAX], int& soluongdocgia) {
	cout << endl;
	int i;
	if (soluongdocgia == 0) {
		cout << "Khong co doc gia nao trong danh sach.";
	}
	else {
		cout << setfill('-');
		cout << setw(210) << left << "-" << endl;
		cout << setfill(' ');
		cout << setw(12) << left << "MA DOC GIA" << setw(25) << left << "HO VA TEN" << setw(13) << left << "CMND" << setw(18) << left << "NGAY SINH" << setw(12) << left << "GIOI TINH" << setw(30) << left << "MAIL" << setw(60) << left << "DIA CHI " << setw(25) << left << "NGAY THANG LAP THE" << setw(25) << left << "NGAY HET HAN THE" << endl;
		cout << setfill('-');
		cout << setw(210) << left << "-" << endl;
		cout << setfill(' ');
		cout << endl;
		for (i = 0; i <= soluongdocgia; i++) {
			if (dg[i].madocgia != "") {
				cout << setw(12) << left << dg[i].madocgia << setw(25) << left << dg[i].hotendg << setw(13) << left << dg[i].cmnd << setw(2) << left << dg[i].ngaysinh << " " << setw(2) << left << dg[i].thangsinh << " " << setw(12) << left << dg[i].namsinh << setw(12) << left << dg[i].gioitinh << setw(30) << left << dg[i].mail << setw(60) << left << dg[i].diachi << setw(2) << left << dg[i].ngaylap << " " << setw(2) << left << dg[i].thanglap << " " << setw(19) << left << dg[i].namlap << setw(2) << left << dg[i].ngayhh << " " << setw(2) << left << dg[i].thanghh << " " << dg[i].namhh << endl;
				cout << endl;
			}
		}
	}
	cout << endl;
}
void cau1b(const char* filein, inforeader dg[MAX], int& soluongdocgia) {
	cout << endl;
	int k;
	cout << "Nhap so luong doc gia ban muon them: ";
	cin >> k;
	int i;
	cin.ignore(1000, '\n');
	for (i = soluongdocgia; i < soluongdocgia + k; i++) {
		cout << "Nhap ma doc gia: ";
		getline(cin, dg[i].madocgia);
		cout << "Nhap ho va ten doc gia: ";
		cin.ignore(0, '\n');
		getline(cin, dg[i].hotendg);
		cout << "Nhap CMND cua doc gia: ";
		getline(cin, dg[i].cmnd);
		cout << "Nhap ngay thang nam sinh (dd/mm/yyyy) cua doc gia: ";
		cin.ignore(0, '\n');
		getline(cin, dg[i].ngaysinh, '/');
		getline(cin, dg[i].thangsinh, '/');
		getline(cin, dg[i].namsinh);
		cout << "Nhap gioi tinh cua doc gia: ";
		cin.ignore(0, '\n');
		getline(cin, dg[i].gioitinh);
		cout << "Nhap dia chi email cua doc gia: ";
		cin.ignore(0, '\n');
		getline(cin, dg[i].mail);
		cout << "Nhap dia chi cua doc gia: ";
		cin.ignore(0, '\n');
		getline(cin, dg[i].diachi);
		cout << "Nhap ngay thanh lap the (dd/mm/yyyy): ";
		getline(cin, dg[i].ngaylap, '/');
		getline(cin, dg[i].thanglap, '/');
		getline(cin, dg[i].namlap);
		dg[i].ngayhh = dg[i].ngaylap;
		dg[i].thanghh = dg[i].thanglap;
		ngayhh(dg[i].namlap, dg[i].namhh);
		cout << endl;
	}
	soluongdocgia = soluongdocgia + k;
	ofstream file;
	file.open(filein, ios_base::beg); 
	for (i = 0; i < soluongdocgia; i++) {
		if (i == soluongdocgia - 1) {
			file << dg[i].madocgia << "," << dg[i].hotendg << "," << dg[i].cmnd << "," << dg[i].ngaysinh << "/" << dg[i].thangsinh << "/" << dg[i].namsinh << "," << dg[i].gioitinh << "," << dg[i].mail << "," << dg[i].diachi << "," << dg[i].ngaylap << "/" << dg[i].thanglap << "/" << dg[i].namlap << "," << dg[i].ngayhh << "/" << dg[i].thanghh << "/" << dg[i].namhh;
		}
		else {
			file << dg[i].madocgia << "," << dg[i].hotendg << "," << dg[i].cmnd << "," << dg[i].ngaysinh << "/" << dg[i].thangsinh << "/" << dg[i].namsinh << "," << dg[i].gioitinh << "," << dg[i].mail << "," << dg[i].diachi << "," << dg[i].ngaylap << "/" << dg[i].thanglap << "/" << dg[i].namlap << "," << dg[i].ngayhh << "/" << dg[i].thanghh << "/" << dg[i].namhh << endl;
		}
	}
	file.close();
}
void cau1c(const char* filein, inforeader dg[MAX], int& soluongdocgia) {
	cout << endl;
	cau1a(dg, soluongdocgia);
restart2:
	string x;
	cout << "Nhap ma so cua doc gia ma ban muon chinh su: ";
	cin.ignore(1000, '\n');
	getline(cin, x);
	bool timduoc = 0;
	for (int i = 0; i < soluongdocgia; i++) {
		if (dg[i].madocgia == x) {
			int choice;
			timduoc = 1;
		restart1:
			cout << endl;
			cout << "Ban muon chinh sua thu muc nao cua doc gia ?" << endl;
			cout << "1.Ma so cua doc gia." << endl;
			cout << "2.Ho ten cua doc gia." << endl;
			cout << "3.So CMND cua doc gia." << endl;
			cout << "4.Ngay thang nam sinh cua doc gia." << endl;
			cout << "5.Gioi tinh cua doc gia." << endl;
			cout << "6.Dia chi mail cua doc gia." << endl;
			cout << "7.Dia chi noi o cua doc gia." << endl;
			cout << "8.Ngay thang nam thanh lap the." << endl;
			cout << "Vui long chon phim chuc nang tuong ung voi thu tu tren: ";
			cin >> choice;
			if (choice == 1) {
				cout << "Nhap ma so moi cua doc gia: ";
				cin.ignore(1000, '\n');
				getline(cin, dg[i].madocgia);
			}
			if (choice == 2) {
				cout << "Nhap ho ten moi cua doc gia: ";
				cin.ignore(1000, '\n');
				getline(cin, dg[i].hotendg);
			}
			if (choice == 3) {
				cout << "Nhap so CMND moi cua doc gia: ";
				cin.ignore(1000, '\n');
				getline(cin, dg[i].cmnd);
			}
			if (choice == 4) {
				cout << "Nhap ngay thang nam sinh (dd/mm/yyyy) moi cua doc gia: ";
				cin.ignore(1000, '\n');
				getline(cin, dg[i].ngaysinh, '/');
				getline(cin, dg[i].thangsinh, '/');
				getline(cin, dg[i].namsinh);
			}
			if (choice == 5) {
				cout << "Nhap gioi tinh cua doc gia: ";
				cin.ignore(1000, '\n');
				getline(cin, dg[i].gioitinh);
			}
			if (choice == 6) {
				cout << "Nhap dia chi mail moi cua doc gia: ";
				cin.ignore(1000, '\n');
				getline(cin, dg[i].mail);
			}
			if (choice == 7) {
				cout << "Nhap dia chi moi cua tac gia: ";
				cin.ignore(1000, '\n');
				getline(cin, dg[i].diachi);
			}
			if (choice == 8) {
				cout << "Nhap ngay thang nam (dd/mm/yyyy) lap the moi: ";
				cin.ignore(1000, '\n');
				getline(cin, dg[i].ngaylap, '/');
				getline(cin, dg[i].thanglap, '/');
				getline(cin, dg[i].namlap);
				dg[i].ngayhh = dg[i].ngaylap;
				dg[i].thanghh = dg[i].thanglap;
				ngayhh(dg[i].namlap, dg[i].namhh);
			}
			cout << endl;
			cout << "Chinh sua cua ban da duoc luu thanh cong." << endl;
			cout << "Day la danh sach thong tin doc gia sau khi da chinh sua:" << endl;
			cau1a(dg, soluongdocgia);
			ofstream file;
			file.open(filein, ios_base::beg);
			for (i = 0; i < soluongdocgia; i++) {
				if (i == soluongdocgia - 1) {
					file << dg[i].madocgia << "," << dg[i].hotendg << "," << dg[i].cmnd << "," << dg[i].ngaysinh << "/" << dg[i].thangsinh << "/" << dg[i].namsinh << "," << dg[i].gioitinh << "," << dg[i].mail << "," << dg[i].diachi << "," << dg[i].ngaylap << "/" << dg[i].thanglap << "/" << dg[i].namlap << "," << dg[i].ngayhh << "/" << dg[i].thanghh << "/" << dg[i].namhh;
				}
				else {
					file << dg[i].madocgia << "," << dg[i].hotendg << "," << dg[i].cmnd << "," << dg[i].ngaysinh << "/" << dg[i].thangsinh << "/" << dg[i].namsinh << "," << dg[i].gioitinh << "," << dg[i].mail << "," << dg[i].diachi << "," << dg[i].ngaylap << "/" << dg[i].thanglap << "/" << dg[i].namlap << "," << dg[i].ngayhh << "/" << dg[i].thanghh << "/" << dg[i].namhh << endl;
				}
			}
			file.close();
			int ctn;
			cout << "Ban co muon tiep tuc chinh sua thong tin cua doc gia nay khong ? Neu co an phim 1, neu khong thi an phim 0: ";
			cin >> ctn;
			if (ctn == 1) goto restart2;
			else break;
		}
	}
	if (timduoc) {
		int ctn2;
		cout << "Ban co muon tiep tuc chinh sua thong tin doc gia ? Neu co an phim 1, neu khong thi an phim 0: ";
		cin >> ctn2;
		if (ctn2 == 1) goto restart2;
	}
	else {
		int ctn2;
		cout << endl;
		cout << "Khong tim duoc thong tin doc gia. Ban co muon tim lai khong ? Neu co an phim 1, neu khong thi an phim 0: ";
		cin >> ctn2;
		if (ctn2 == 1) goto restart2;
	}
}
void cau1d(const char* filein, inforeader dg[MAX], int& soluongdocgia) {
restart:
	cout << endl;
	if (soluongdocgia == 1) cout << "Khong con doc gia nao trong thu vien";
	else {
		string x;
		int i;
		cau1a(dg, soluongdocgia);
		cout << "Nhap ma so cua doc gia ma ban muon xoa: ";
		cin.ignore(1000, '\n');
		getline(cin, x);
		bool timduoc = 0;
		for (i = 0; i < soluongdocgia; i++) {
			if (dg[i].madocgia == x) {
				timduoc = 1;
				while (i < soluongdocgia) {
					dg[i].madocgia = dg[i + 1].madocgia;
					dg[i].hotendg = dg[i + 1].hotendg;
					dg[i].cmnd = dg[i + 1].cmnd;
					dg[i].ngaysinh = dg[i + 1].ngaysinh;
					dg[i].thangsinh = dg[i + 1].thangsinh;
					dg[i].namsinh = dg[i + 1].namsinh;
					dg[i].gioitinh = dg[i + 1].gioitinh;
					dg[i].mail = dg[i + 1].mail;
					dg[i].diachi = dg[i + 1].diachi;
					dg[i].ngaylap = dg[i + 1].ngaylap;
					dg[i].thanglap = dg[i + 1].thanglap;
					dg[i].namlap = dg[i + 1].namlap;
					dg[i].ngayhh = dg[i].ngaylap;
					dg[i].thanghh = dg[i].thanglap;
					ngayhh(dg[i].namlap, dg[i].namhh);
					i++;
				}
				soluongdocgia = soluongdocgia - 1;
				break;
			}
		}
		if (timduoc == 0) {
			cout << "Khong tim duoc doc gia." << endl;
			int ctn;
			cout << "Ban co muon tiep tuc xoa thong tin doc gia khac khong ? Neu co an phim 1, neu khong thi an phim 0: ";
			cin >> ctn;
			if (ctn == 1) goto restart;
		}
		else {
			if (soluongdocgia != 0) {
				int ctn;
				cout << endl;
				cout << "Thong tin doc gia da duoc xoa" << endl;
				cout << "Day la danh sach thong tin doc gia sau khi da chinh sua:" << endl;
				cau1a(dg, soluongdocgia);
				ofstream file;
				file.open(filein, ios_base::beg);
				for (i = 0; i < soluongdocgia; i++) {
					if (i == soluongdocgia - 1) {
						file << dg[i].madocgia << "," << dg[i].hotendg << "," << dg[i].cmnd << "," << dg[i].ngaysinh << "/" << dg[i].thangsinh << "/" << dg[i].namsinh << "," << dg[i].gioitinh << "," << dg[i].mail << "," << dg[i].diachi << "," << dg[i].ngaylap << "/" << dg[i].thanglap << "/" << dg[i].namlap << "," << dg[i].ngayhh << "/" << dg[i].thanghh << "/" << dg[i].namhh;
					}
					else {
						file << dg[i].madocgia << "," << dg[i].hotendg << "," << dg[i].cmnd << "," << dg[i].ngaysinh << "/" << dg[i].thangsinh << "/" << dg[i].namsinh << "," << dg[i].gioitinh << "," << dg[i].mail << "," << dg[i].diachi << "," << dg[i].ngaylap << "/" << dg[i].thanglap << "/" << dg[i].namlap << "," << dg[i].ngayhh << "/" << dg[i].thanghh << "/" << dg[i].namhh << endl;
					}
				}
				file.close();
				cout << "Ban co muon tiep tuc xoa thong tin doc gia khac khong ? Neu co an phim 1, neu khong thi an phim 0: ";
				cin >> ctn;
				if (ctn == 1) goto restart;
			}
		}
	}
}
void cau1e(inforeader dg[MAX], int& soluongdocgia) {
	cout << endl;
restart:
	int i;
	string x;
	cout << "Nhap ma so CMND cua doc gia ma ban muon tim kiem: ";
	cin.ignore();
	getline(cin, x);
	for (i = 0; i < soluongdocgia; i++) {
		if (dg[i].cmnd == x) {
			cout << setfill('-');
			cout << setw(210) << left << "-" << endl;
			cout << setfill(' ');
			cout << setw(12) << left << "MA DOC GIA" << setw(25) << left << "HO VA TEN" << setw(13) << left << "CMND" << setw(18) << left << "NGAY SINH" << setw(12) << left << "GIOI TINH" << setw(30) << left << "MAIL" << setw(60) << left << "DIA CHI " << setw(25) << left << "NGAY THANG LAP THE" << setw(25) << left << "NGAY HET HAN THE" << endl;
			cout << setfill('-');
			cout << setw(210) << left << "-" << endl;
			cout << setfill(' ');
			cout << endl;
			cout << setw(12) << left << dg[i].madocgia << setw(25) << left << dg[i].hotendg << setw(13) << left << dg[i].cmnd << setw(2) << left << dg[i].ngaysinh << " " << setw(2) << left << dg[i].thangsinh << " " << setw(12) << left << dg[i].namsinh << setw(12) << left << dg[i].gioitinh << setw(30) << left << dg[i].mail << setw(60) << left << dg[i].diachi << setw(2) << left << dg[i].ngaylap << " " << setw(2) << left << dg[i].thanglap << " " << setw(19) << left << dg[i].namlap << setw(2) << left << dg[i].ngayhh << " " << setw(2) << left << dg[i].thanghh << " " << dg[i].namhh << endl;
			cout << endl;
			break;
		}
	}
	if (i == soluongdocgia) cout << "Khong tim duoc doc gia trong thu vien." << endl;
	int ctn;
	cout << "Ban co muon tim them doc gia khong ? Neu co an phim 1, neu khong thi an phim 0: ";
	cin >> ctn;
	if (ctn == 1) goto restart;
}
void cau1f(inforeader dg[MAX], int& soluongdocgia) {
	cout << endl;
restart:
	string text;
	int i;
	cout << "Nhap ho ten doc gia ma ban muon tim kiem: ";
	cin.ignore();
	getline(cin, text);
	for (i = 0; i < soluongdocgia; i++) {
		if (dg[i].hotendg == text) {
			cout << setfill('-');
			cout << setw(210) << left << "-" << endl;
			cout << setfill(' ');
			cout << setw(12) << left << "MA DOC GIA" << setw(25) << left << "HO VA TEN" << setw(13) << left << "CMND" << setw(18) << left << "NGAY SINH" << setw(12) << left << "GIOI TINH" << setw(30) << left << "MAIL" << setw(60) << left << "DIA CHI " << setw(25) << left << "NGAY THANG LAP THE" << setw(25) << left << "NGAY HET HAN THE" << endl;
			cout << setfill('-');
			cout << setw(210) << left << "-" << endl;
			cout << setfill(' ');
			cout << endl;
			cout << setw(12) << left << dg[i].madocgia << setw(25) << left << dg[i].hotendg << setw(13) << left << dg[i].cmnd << setw(2) << left << dg[i].ngaysinh << " " << setw(2) << left << dg[i].thangsinh << " " << setw(12) << left << dg[i].namsinh << setw(12) << left << dg[i].gioitinh << setw(30) << left << dg[i].mail << setw(60) << left << dg[i].diachi << setw(2) << left << dg[i].ngaylap << " " << setw(2) << left << dg[i].thanglap << " " << setw(19) << left << dg[i].namlap << setw(2) << left << dg[i].ngayhh << " " << setw(2) << left << dg[i].thanghh << " " << dg[i].namhh << endl;
			cout << endl;
			break;
		}
	}
	int ctn;
	if (i == soluongdocgia) cout << "Khong tim thay doc gia." << endl;
	cout << "Ban co muon tim kiem them doc gia khong ? Neu co an phim 1, neu khong thi an phim 0: ";
	cin >> ctn;
	if (ctn == 1) goto restart;
}
int menu2() {
	int choice;
	cout << endl;
	cout << "Ban da chon thao tac \"Quan li sach\"." << endl;
	cout << "Ban muon thuc hien chuc nang gi ?" << endl;
	cout << "1. Xem danh sach cac sach trong thu vien." << endl;
	cout << "2. Them sach." << endl;
	cout << "3. Chinh sua thong tin mot quyen sach." << endl;
	cout << "4. Xoa thong tin sach." << endl;
	cout << "5. Tim kiem sach theo ISBN." << endl;
	cout << "6. Tim kiem sach theo ten sach." << endl;
	cout << "Vui long chon phim chuc nang tuong ung voi thu tu tren: ";
	cin >> choice;
	return choice;
}
void cau2a(infobooks sach[MAX], int& soluongsach) {
	cout << endl;
	if (soluongsach == 0) cout << "Thu vien khong co sach nao ca." << endl;
	else {
		int i;
		if (soluongsach == 0) {
			cout << "Khong co sach nao trong danh sach.";
		}
		else {
			cout << setw(20) << left << "ISBN (MA SACH)" << setw(40) << left << "TEN SACH" << setw(30) << left << "TAC GIA" << setw(40) << left << "NHA XUAT BAN" << setw(25) << left << "NAM XUAT BAN" << setw(20) << left << "THE LOAI" << setw(20) << "GIA SACH" << "SO QUYEN SACH";
			cout << endl;
			cout << setfill('-');
			cout << setw(200) << left << "-" << endl;
			cout << setfill(' ');
			for (i = 0; i < soluongsach; i++) {
				cout << setw(20) << left << sach[i].isbn << setw(40) << left << sach[i].tensach << setw(30) << left << sach[i].tacgia << setw(40) << left << sach[i].nhaxuatban << setw(25) << left << sach[i].namxb << setw(20) << left << sach[i].theloai << setw(20) << sach[i].giasach << sach[i].soquyensach << endl;
				cout << endl;
			}
			cout << endl;
		}
	}
	cout << endl;
}
void cau2b(const char* filein, infobooks sach[MAX], int& soluongsach) {
	cout << endl;
	int k; // so luong sach muon them
	int choice;
	cout << "Ban muon them sach da co trong thu vien hay chua ? Neu co, an phim 1, neu khong, an phim 0: ";
	cin >> choice;
	if (choice == 1) {
		string text;
		int i;
		cout << "Nhap ma cua sach ma ban muon them sach: ";
		cin.ignore(1000, '\n');
		getline(cin, text);
		cout << endl;
		cout << "Nhap so cuon sach doc gia muon them: ";
		cin >> k;
		for (i = 0; i < soluongsach; i++) {
			if (sach[i].isbn == text) {
				themsach(sach[i].soquyensach, k);
				break;
			}
		}
		if (i == soluongsach) cout << "KHONG TIM DUOC SACH." << endl;
		cout << endl;
	}
	else {
		int i;
		cout << "Nhap so luong sach ma ban muon them: ";
		cin >> k;
		cin.ignore(1000, '\n');
		for (i = soluongsach; i < soluongsach + k; i++) {
			cout << "Nhap ISBN (ma sach) cua sach: ";
			getline(cin, sach[i].isbn);
			cout << endl;
			cout << "Nhap ten cua sach: ";
			cin.ignore(0, '\n');
			getline(cin, sach[i].tensach);
			cout << endl;
			cout << "Nhap ten tac gia cua sach: ";
			cin.ignore(0, '\n');
			getline(cin, sach[i].tacgia);
			cout << endl;
			cout << "Nhap nha xuat ban cua sach: ";
			cin.ignore(0, '\n');
			getline(cin, sach[i].nhaxuatban);
			cout << endl;
			cout << "Nhap nam xuat ban cua sach: ";
			cin.ignore(0, '\n');
			getline(cin, sach[i].namxb);
			cout << endl;
			cout << "Nhap the loai cua sach: ";
			cin.ignore(0, '\n');
			getline(cin, sach[i].theloai);
			cout << endl;
			cout << "Nhap gia cua quyen sach: ";
			cin.ignore(0, '\n');
			getline(cin, sach[i].giasach);
			cout << endl;
			cout << "Nhap so quyen sach: ";
			cin.ignore(0, '\n');
			getline(cin, sach[i].soquyensach);
			cout << endl;
		}
		soluongsach = soluongsach + k;
	}
	cout << "Sach da duoc them." << endl;
	ofstream file;
	file.open(filein, ios_base::beg);
	for (int i = 0; i < soluongsach; i++) {
		if (i == soluongsach - 1) {
			file << sach[i].isbn << "," << sach[i].tensach << "," << sach[i].tacgia << "," << sach[i].nhaxuatban << "," << sach[i].namxb << "," << sach[i].theloai << "," << sach[i].giasach << "," << sach[i].soquyensach;
		}
		else {
			file << sach[i].isbn << "," << sach[i].tensach << "," << sach[i].tacgia << "," << sach[i].nhaxuatban << "," << sach[i].namxb << "," << sach[i].theloai << "," << sach[i].giasach << "," << sach[i].soquyensach << endl;
		}
	}
	file.close();
}
void cau2c(const char* filein, infobooks sach[MAX], int& soluongsach) {
	cout << endl;
	cau2a(sach, soluongsach);
restart2:
	string text;
	int i;
	cout << "Nhap ISBN (ma sach) cua sach ma ban muon chinh sua thong tin: ";
	cin.ignore(1000, '\n');
	getline(cin, text);
	bool timduoc = 0;
	for (i = 0; i < soluongsach; i++) {
		if (sach[i].isbn == text) {
			timduoc = 1;
		restart1:
			int choice;
			cout << endl;
			cout << "Ban muon chinh sua thong tin gi cua quyen sach ?" << endl;
			cout << "1. ISBN (ma sach)." << endl;
			cout << "2. Ten sach." << endl;
			cout << "3. Tac gia." << endl;
			cout << "4. Nha xuat ban." << endl;
			cout << "5. Nam xuat ban." << endl;
			cout << "6. The loai." << endl;
			cout << "7. Gia sach." << endl;
			cout << "8. So quyen sach." << endl;
			cout << "Vui long chon phim chuc nang tuong ung voi thu tu tren: ";
			cin >> choice;
			cout << endl;
			if (choice == 1) {
				cout << "Nhap ma moi cua sach: ";
				cin.ignore(1000, '\n');
				getline(cin, sach[i].isbn);
			}
			if (choice == 2) {
				cout << "Nhap ten moi cua sach: ";
				cin.ignore(1000, '\n');
				getline(cin, sach[i].tensach);
			}
			if (choice == 3) {
				cout << "Nhap tac gia moi cua sach: ";
				cin.ignore(1000, '\n');
				getline(cin, sach[i].tacgia);
			}
			if (choice == 4) {
				cout << "Nhap nha xuat ban moi cua sach: ";
				cin.ignore(1000, '\n');
				getline(cin, sach[i].nhaxuatban);
			}
			if (choice == 5) {
				cout << "Nhap nam xuat ban moi cua sach: ";
				cin.ignore(1000, '\n');
				getline(cin, sach[i].namxb);
			}
			if (choice == 6) {
				cout << "Nhap the loai moi cua sach: ";
				cin.ignore(1000, '\n');
				getline(cin, sach[i].theloai);
			}
			if (choice == 7) {
				cout << "Nhap gia ban ban moi cua sach: ";
				cin.ignore(1000, '\n');
				getline(cin, sach[i].giasach);
			}
			if (choice == 8) {
				cout << "Nhap so quyen sach moi cua sach: ";
				cin.ignore(1000, '\n');
				getline(cin, sach[i].soquyensach);
			}
			cout << endl;
			cout << "Chinh sua cua ban da duoc luu thanh cong." << endl;
			cout << "Day la danh sach sau khi chinh sua: " << endl;
			cau2a(sach, soluongsach);
			int ctn;
			cout << "Ban co muon tiep tuc chinh sua thong tin cua quyen sach nay khong ? Neu co an phim 1, neu khong thi an phim 0: ";
			cin >> ctn;
			if (ctn == 1) goto restart1;
			else break;
		}
	}
	if (timduoc) {
		int ctn2;
		cout << "Ban co muon tiep tuc chinh sua thong tin sach khong ? Neu co an phim 1, neu khong thi an phim 0: ";
		cin >> ctn2;
		if (ctn2 == 1) goto restart2;
	}
	else {
		int ctn2;
		cout << "Khong tim duoc thong tin sach, ban co muon tim lai khong ? Neu co an phim 1, neu khong thi an phim 0: ";
		cin >> ctn2;
		if (ctn2 == 1) goto restart2;
	}
	ofstream file;
	file.open(filein, ios_base::beg);
	for (int i = 0; i < soluongsach; i++) {
		if (i == soluongsach - 1) {
			file << sach[i].isbn << "," << sach[i].tensach << "," << sach[i].tacgia << "," << sach[i].nhaxuatban << "," << sach[i].namxb << "," << sach[i].theloai << "," << sach[i].giasach << "," << sach[i].soquyensach;
		}
		else {
			file << sach[i].isbn << "," << sach[i].tensach << "," << sach[i].tacgia << "," << sach[i].nhaxuatban << "," << sach[i].namxb << "," << sach[i].theloai << "," << sach[i].giasach << "," << sach[i].soquyensach << endl;
		}
	}
	file.close();
}
void cau2d(const char* filein, infobooks sach[MAX], int& soluongsach) {
restart:
	if (soluongsach == 1) cout << "Thu vien khong con sach nao.";
	else {
		string text;
		int i;
		cout << "Nhap ISBN (ma sach) cua sach ma ban muon xoa thong tin: ";
		cin.ignore(1000, '\n');
		getline(cin, text);
		bool timduoc = 0;
		for (i = 0; i < soluongsach; i++) {
			if (sach[i].isbn == text) {
				timduoc = 1;
				if (i == soluongsach - 1) {
					soluongsach = soluongsach - 1;
					break;
				}
				if (i < soluongsach - 1) {
					while (i < soluongsach) {
						sach[i].isbn = sach[i+1].isbn;
						sach[i].tensach = sach[i + 1].tensach;
						sach[i].tacgia = sach[i + 1].tacgia;
						sach[i].nhaxuatban = sach[i + 1].nhaxuatban;
						sach[i].namxb = sach[i + 1].namxb;
						sach[i].theloai = sach[i + 1].theloai;
						sach[i].giasach = sach[i + 1].giasach;
						sach[i].soquyensach = sach[i + 1].soquyensach;
						i++;
					}
					soluongsach = soluongsach - 1;
					break;
				}
			}
		}
		if (timduoc == 0) {
			cout << "Khong tim duoc doc gia." << endl;
			int ctn;
			cout << "Khong tim duoc thong tin sach, ban co muon tim lai khong ? Neu co an phim 1, neu khong thi an phim 0: ";
			cin >> ctn;
			if (ctn == 1) goto restart;
		}
		else {
			if (soluongsach != 0) {
				int ctn;
				cout << endl;
				cout << "Thong tin sach da duoc xoa" << endl;
				cout << "Day la danh sach thong tin sach gia sau khi da chinh sua:" << endl;
				cau2a(sach, soluongsach);
				cout << "Ban co muon tiep tuc xoa thong tin quyen sach khac khong ? Neu co an phim 1, neu khong thi an phim 0: ";
				cin >> ctn;
				if (ctn == 1) goto restart;
			}
		}
	}
	ofstream file;
	file.open(filein, ios_base::beg);
	for (int i = 0; i < soluongsach; i++) {
		if (i == soluongsach - 1) {
			file << sach[i].isbn << "," << sach[i].tensach << "," << sach[i].tacgia << "," << sach[i].nhaxuatban << "," << sach[i].namxb << "," << sach[i].theloai << "," << sach[i].giasach << "," << sach[i].soquyensach;
		}
		else {
			file << sach[i].isbn << "," << sach[i].tensach << "," << sach[i].tacgia << "," << sach[i].nhaxuatban << "," << sach[i].namxb << "," << sach[i].theloai << "," << sach[i].giasach << "," << sach[i].soquyensach << endl;
		}
	}
	file.close();
}
void cau2e(infobooks sach[MAX], int& soluongsach) {
restart:
	string text;
	int i;
	cout << "Nhap ISBN (ma sach) cua sach ma ban muon tim thong tin: ";
	cin.ignore(1000, '\n');
	getline(cin, text);
	for (i = 0; i < soluongsach; i++) {
		if (sach[i].isbn == text) {
			cout << endl;
			cout << setw(20) << left << "ISBN (MA SACH)" << setw(40) << left << "TEN SACH" << setw(30) << left << "TAC GIA" << setw(40) << left << "NHA XUAT BAN" << setw(25) << left << "NAM XUAT BAN" << setw(20) << left << "THE LOAI" << setw(20) << "GIA SACH" << "SO QUYEN SACH";
			cout << endl;
			cout << setfill('-');
			cout << setw(200) << left << "-" << endl;
			cout << setfill(' ');
			cout << setw(20) << left << sach[i].isbn << setw(40) << left << sach[i].tensach << setw(30) << left << sach[i].tacgia << setw(40) << left << sach[i].nhaxuatban << setw(25) << left << sach[i].namxb << setw(20) << left << sach[i].theloai << setw(20) << sach[i].giasach << sach[i].soquyensach << endl;
			cout << endl;
			cout << endl;
			break;
		}
	}
	int ctn;
	if (i == soluongsach) cout << "Khong tim duoc quyen sach nao." << endl;
	cout << "Ban co muon tim them sach khong ? Neu co an phim 1, neu khong thi an phim 0: ";
	cin >> ctn;
	if (ctn == 1) goto restart;
}
void cau2f(infobooks sach[MAX], int& soluongsach) {
restart:
	string text;
	int i;
	cout << "Nhap ten cua sach ma ban muon tim thong tin: ";
	cin.ignore(1000, '\n');
	getline(cin, text);
	for (i = 0; i < soluongsach; i++) {
		if (sach[i].tensach == text) {
			cout << endl;
			cout << setw(20) << left << "ISBN (MA SACH)" << setw(40) << left << "TEN SACH" << setw(30) << left << "TAC GIA" << setw(40) << left << "NHA XUAT BAN" << setw(25) << left << "NAM XUAT BAN" << setw(20) << left << "THE LOAI" << setw(20) << "GIA SACH" << "SO QUYEN SACH";
			cout << endl;
			cout << setfill('-');
			cout << setw(200) << left << "-" << endl;
			cout << setfill(' ');
			cout << setw(20) << left << sach[i].isbn << setw(40) << left << sach[i].tensach << setw(30) << left << sach[i].tacgia << setw(40) << left << sach[i].nhaxuatban << setw(25) << left << sach[i].namxb << setw(20) << left << sach[i].theloai << setw(20) << sach[i].giasach << sach[i].soquyensach << endl;
			cout << endl;
			cout << endl;
			break;
		}
	}
	int ctn;
	if (i == soluongsach) cout << "Khong tim duoc quyen sach nao." << endl;
	cout << "Ban co muon tim them sach khong ? Neu co an phim 1, neu khong thi an phim 0: ";
	cin >> ctn;
	if (ctn == 1) goto restart;
}
void cau3(const char* filein, inforeader dg[MAX], int& soluongdocgia, infobooks sach[MAX], int soluongsach, phieumuonsach phieumuon[MAX], int& soluongphieumuon, int& soluongsachmuon) {
	int i, j, k;
	cout << endl;
	cout << "Ban da chon thao tac \"Lap phieu muon sach\"." << endl;
	cout << endl;
	string text;
	cin.ignore(1000, '\n');
restart1:
	cout << "Nhap ma doc gia muon sach: ";
	getline(cin, text);
	bool tontai = 0;
	for (i = 0; i < soluongdocgia; i++) {
		if (text == dg[i].madocgia) tontai = 1;
	}
	if (tontai == 0) {
		int ctn;
		cout << "Khong tim duoc doc gia trong danh sach." << endl;
		goto restart1;
	}
	bool damuon = 0;
	int x = -1;
	for (i = 0; i < soluongphieumuon; i++) {
		if (text == phieumuon[i].madgmuon) {
			x = i;
		}
	}
	if (x != -1) {
		cout << "Nhap so cuon sach ma doc gia muon muon: ";
		cin >> k;
		if (k + phieumuon[x].soluongsachdgmuon > 7) {
			cout << "Quy dinh thu vien doc gia chi duoc muon toi da 5 cuon mot luc." << endl;
			cout << "Doc gia da muon " << phieumuon[x].soluongsachdgmuon << " nen khong duoc muon nua." << endl;
			cout << "Neu doc gia muon muon them, yeu cau tra sach dang muon." << endl;
		}
		else {
			int ngaymuon, thangmuon, nammuon;
			cout << "Nhap ngay thang nam (dd mm yyyy) muon sach: ";
			cin >> ngaymuon >> thangmuon >> nammuon;
			if (checktrasach(ngaymuon, thangmuon, nammuon, phieumuon[x].ngaytradukien, phieumuon[x].thangtradukien, phieumuon[x].namtradukien) > 0) {
				cout << "Doc gia da muon sach truoc do va chua tra dung han. Neu doc gia muon muon sach, yeu cau tra sach." << endl;
			}
			else {
				phieumuon[x].ngaymuon = ngaymuon;
				phieumuon[x].thangmuon = thangmuon;
				phieumuon[x].nammuon = nammuon;
				ngaytrasach(phieumuon[x].ngaymuon, phieumuon[x].thangmuon, phieumuon[x].nammuon, phieumuon[x].ngaytradukien, phieumuon[x].thangtradukien, phieumuon[x].namtradukien);
				cin.ignore(1000, '\n');
			back:
				for (i = phieumuon[x].soluongsachdgmuon; i < phieumuon[x].soluongsachdgmuon + k; i++) {
					cout << "Nhap isbn (ma sach) ma doc gia muon muon: ";
					getline(cin, phieumuon[x].sachduocmuontheodg[i]);
					for (j = 0; j < phieumuon[x].soluongsachdgmuon; j++) {
						if (phieumuon[x].sachduocmuontheodg[i] == phieumuon[x].sachduocmuontheodg[j]) {
							cout << "Doc gia da muon cuon sach nay nen khong duoc muon nua." << endl;
							cout << "Yeu cau doc gia nhap lai isbn (ma sach) muon muon tu dau." << endl;
							goto back;
						}
					}
					bool co = 0;
					for (j = 0; j < soluongsach; j++) {
						if (sach[j].isbn == phieumuon[x].sachduocmuontheodg[i] && atoi(sach[j].soquyensach.c_str()) > 0) co = 1;
					}
					if (co == 0) {
						cout << "Khong ton tai cuon sach nay trong thu vien." << endl;
						cout << "Yeu cau doc gia nhap lai isbn (ma sach) muon muon tu dau." << endl;
						goto back;
					}
				}
				cout << endl;
				cout << "MUON SACH THANH CONG." << endl;
				cout << "PHIEU MUON SACH:" << endl;
				cout << "MA DOC GIA: " << phieumuon[x].madgmuon << endl;
				cout << "NGAY MUON SACH: " << ngaymuon << "/" << thangmuon << "/" << nammuon << endl;
				cout << "NGAY TRA SACH (DU KIEN): " << phieumuon[x].ngaytradukien << "/" << phieumuon[x].thangtradukien << "/" << phieumuon[x].namtradukien << endl;
				cout << "DANH DACH ISBN CAC SANH DUOC MUON: ";
				for (i = 0; i < phieumuon[x].soluongsachdgmuon; i++) {
					cout << phieumuon[x].sachduocmuontheodg[i]<<" ";
				}
				phieumuon[x].soluongsachdgmuon = phieumuon[x].soluongsachdgmuon + k;
			}
		}
	}
	else {
		phieumuon[soluongphieumuon].madgmuon = text;
		cout << "Nhap so cuon sach ma doc gia muon muon: ";
		cin >> k;
		if (k > 5) cout << "Doc gia chi duoc muon toi da 7 cuon sach." << endl;
		else {
			phieumuon[soluongphieumuon].soluongsachdgmuon = k;
			cout << "Nhap ngay thang nam (dd mm yyyy) muon sach: ";
			cin >> phieumuon[soluongphieumuon].ngaymuon >> phieumuon[soluongphieumuon].thangmuon >> phieumuon[soluongphieumuon].nammuon;
			ngaytrasach(phieumuon[soluongphieumuon].ngaymuon, phieumuon[soluongphieumuon].thangmuon, phieumuon[soluongphieumuon].nammuon, phieumuon[soluongphieumuon].ngaytradukien, phieumuon[soluongphieumuon].thangtradukien, phieumuon[soluongphieumuon].namtradukien);
			cin.ignore(1000, '\n');
			back2:
			for (i = 0; i < k; i++) {
				cout << "Nhap isbn (ma sach) ma doc gia muon muon: ";
				getline(cin, phieumuon[soluongphieumuon].sachduocmuontheodg[i]);
				bool co = 0;
				for (j = 0; j < soluongsach; j++) {
					if (sach[j].isbn == phieumuon[soluongphieumuon].sachduocmuontheodg[i] && atoi(sach[j].soquyensach.c_str()) > 0) co = 1;
				}
				if (co == 0) {
					cout << "Khong ton tai cuon sach nay trong thu vien." << endl;
					cout << "Yeu cau doc gia nhap lai isbn (ma sach) muon muon tu dau." << endl;
					goto back2;
				}
			}
			cout << endl;
			cout << "MUON SACH THANH CONG." << endl;
			cout << "PHIEU MUON SACH:" << endl;
			cout << "MA DOC GIA: " << phieumuon[soluongphieumuon].madgmuon << endl;
			cout << "NGAY MUON SACH: " << phieumuon[soluongphieumuon].ngaymuon << "/" << phieumuon[soluongphieumuon].thangmuon << "/" << phieumuon[soluongphieumuon].nammuon << endl;
			cout << "NGAY TRA SACH (DU KIEN): " << phieumuon[soluongphieumuon].ngaytradukien << "/" << phieumuon[soluongphieumuon].thangtradukien << "/" << phieumuon[soluongphieumuon].namtradukien << endl;
			cout << "DANH DACH ISBN CAC SANH DUOC MUON: doc gia khong muon cuon nao. " << endl;
			soluongphieumuon++;
		}
	}
	ofstream file;
	file.open(filein, ios_base::beg);
	for (int i = 0; i < soluongphieumuon; i++) {
		if (i == soluongphieumuon - 1) {
			file << phieumuon[i].madgmuon << "," << phieumuon[i].ngaymuon << "/" << phieumuon[i].thangmuon << "/" << phieumuon[i].nammuon << "," << phieumuon[i].ngaytradukien << "/" << phieumuon[i].thangtradukien << "/" << phieumuon[i].namtradukien << "," << phieumuon[i].soluongsachdgmuon << ",";
			for (int j = 0; j < phieumuon[i].soluongsachdgmuon; j++) {
				if (j == phieumuon[i].soluongsachdgmuon - 1)	file << phieumuon[i].sachduocmuontheodg[j];
				else file << phieumuon[i].sachduocmuontheodg[j] << " ";
			}
		}
		else {
			file << phieumuon[i].madgmuon << "," << phieumuon[i].ngaymuon << "/" << phieumuon[i].thangmuon << "/" << phieumuon[i].nammuon << "," << phieumuon[i].ngaytradukien << "/" << phieumuon[i].thangtradukien << "/" << phieumuon[i].namtradukien << "," << phieumuon[i].soluongsachdgmuon << ",";
			for (int j = 0; j < phieumuon[i].soluongsachdgmuon; j++) {
				if (j == phieumuon[i].soluongsachdgmuon - 1)	file << phieumuon[i].sachduocmuontheodg[j];
				else file << phieumuon[i].sachduocmuontheodg[j] << " ";
			}
			file << endl;
		}
	}
	file.close();
	cout << endl;
}
void cau4(const char* filein, const char* filein2, const char* filein3, inforeader dg[MAX], int& soluongdocgia, infobooks sach[MAX], int soluongsach, phieumuonsach phieumuon[MAX], int& soluongphieumuon, int& soluongsachmuon, string madgtrehan[MAX], int& soluongdgtrehan) {
	string sachtra[MAX];
	int ngaytra, thangtra, namtra;
	string text;
	int i, j, k;
	int matsach;
	cout << endl;
	cout << "Ban da chon thao tac \"Lap phieu tra sach\"." << endl;
restart:
	cout << "Ban co bi mat sach khong ? Neu co, an phim 1, neu khong an phim 0: ";
	cin >> matsach;
	cout << endl;
	if (matsach) {
		int a;
		cout << endl;
		cin.ignore(1000, '\n');
		cout << "Nhap ma doc gia lam mat sach: ";
		getline(cin, text);
		bool timduoc = 0;
		for (i = 0; i < soluongdocgia; i++) {
			if (text == dg[i].madocgia) timduoc = 1;
		}
		if (timduoc == 0) {
			cout << "Khong tim duoc doc gia trong danh sach thu vien." << endl;
			cout << "Yeu cau nhap lai tu dau." << endl;
			cout << endl;
			goto restart;
		}
		timduoc = 0;
		for (i = 0; i < soluongphieumuon; i++) {
			if (text == phieumuon[i].madgmuon) {
				timduoc = 1;
				a = i;
			}
		}
		if (timduoc == 0) {
			cout << "Doc gia khong muon cuon sach nao." << endl;
			cout << "Yeu cau nhap lai tu dau." << endl;
			goto restart;
		}
		cout << endl;
		int tien, n;
		tien = 0;
		string sachmat[MAX];
		cout << "Nhap so quyen sach bi mat: ";
		cin >> n;
		for (i = 0; i < n; i++) {
			cout << "Nhap ISBN (ma sach) bi mat: ";
			cin.ignore(1000, '\n');
			getline(cin, sachmat[i]);
			timduoc = 0;
			for (j = 0; j < phieumuon[a].soluongsachdgmuon; j++) {
				if (phieumuon[a].sachduocmuontheodg[j] == sachmat[i]) {
					phieumuon[a].sachduocmuontheodg[j] = "";
					timduoc = 1;
				}
			}
			if (timduoc == 0) {
				cout << "Doc gia khong muon cuon sach nay." << endl;
				cout << "Yeu cau nhap lai tu dau." << endl;
				goto restart;
			}
			for (j = 0; j < soluongsach; j++) {
				if (sachmat[i] == sach[j].isbn) {
					tien = tien + atoi(sach[j].giasach.c_str()) * 2;
					sach[j].soquyensach = to_string(atoi(sach[j].soquyensach.c_str()) - 1);
				}
			}
		}
		cout << endl;
		cout << "SO TIEN PHAI DEN BU: " << tien << endl;
		cout << endl;
		ofstream file;
		file.open(filein, ios_base::beg);
		for (i = 0; i < soluongsach; i++) {
			if (i == soluongsach - 1) {
				file << sach[i].isbn << "," << sach[i].tensach << "," << sach[i].tacgia << "," << sach[i].nhaxuatban << "," << sach[i].namxb << "," << sach[i].theloai << "," << sach[i].giasach << "," << sach[i].soquyensach;
			}
			else {
				file << sach[i].isbn << "," << sach[i].tensach << "," << sach[i].tacgia << "," << sach[i].nhaxuatban << "," << sach[i].namxb << "," << sach[i].theloai << "," << sach[i].giasach << "," << sach[i].soquyensach << endl;
			}
		}
		file.close();
		ofstream file2;
		file2.open(filein2, ios_base::beg);
		for (i = 0; i < soluongphieumuon; i++) {
			if (phieumuon[i].soluongsachdgmuon != 0) {
				if (i == soluongphieumuon - 1) {
					file2 << phieumuon[i].madgmuon << "," << phieumuon[i].ngaymuon << "/" << phieumuon[i].thangmuon << "/" << phieumuon[i].nammuon << "," << phieumuon[i].ngaytradukien << "/" << phieumuon[i].thangtradukien << "/" << phieumuon[i].namtradukien << "," << phieumuon[i].soluongsachdgmuon - n << ",";
					for (int j = 0; j < phieumuon[i].soluongsachdgmuon; j++) {
						if (phieumuon[i].sachduocmuontheodg[j] != "") {
							if (j == phieumuon[i].soluongsachdgmuon - 1)	file2 << phieumuon[i].sachduocmuontheodg[j];
							else file2 << phieumuon[i].sachduocmuontheodg[j] << " ";
						}
					}
				}
				else {
					file2 << phieumuon[i].madgmuon << "," << phieumuon[i].ngaymuon << "/" << phieumuon[i].thangmuon << "/" << phieumuon[i].nammuon << "," << phieumuon[i].ngaytradukien << "/" << phieumuon[i].thangtradukien << "/" << phieumuon[i].namtradukien << "," << phieumuon[i].soluongsachdgmuon - n << ",";
					for (j = 0; j < phieumuon[i].soluongsachdgmuon; j++) {
						if (phieumuon[i].sachduocmuontheodg[j] != "") {
							if (j == phieumuon[i].soluongsachdgmuon - 1)	file2 << phieumuon[i].sachduocmuontheodg[j];
							else file2 << phieumuon[i].sachduocmuontheodg[j] << " ";
						}
					}
					file2 << endl;
				}
			}
		}
		file2.close();
		phieumuon[a].soluongsachdgmuon = phieumuon[a].soluongsachdgmuon - n;
	}
	else {
		int a;
		cout << endl;
		cin.ignore(1000, '\n');
		cout << "Nhap ma doc gia muon tra sach: ";
		getline(cin, text);
		bool timduoc = 0;
		for (i = 0; i < soluongdocgia; i++) {
			if (text == dg[i].madocgia) timduoc = 1;
		}
		if (timduoc == 0) {
			cout << "Khong tim duoc doc gia trong danh sach thu vien." << endl;
			cout << "Yeu cau nhap lai tu dau." << endl;
			cout << endl;
			goto restart;
		}
		timduoc = 0;
		for (i = 0; i < soluongphieumuon; i++) {
			if (text == phieumuon[i].madgmuon) {
				timduoc = 1;
				a = i;
			}
		}
		if (timduoc == 0) {
			cout << "Doc gia khong muon cuon sach nao." << endl;
			cout << "Yeu cau nhap lai tu dau." << endl;
			goto restart;
		}
		string sachtra[MAX];
		int ngaytra, thangtra, namtra;
		int n;
		cout << endl;
		cout << "Nhap so cuon sach ma doc gia muon tra: ";
		cin >> n;
		cout << endl;
		cout << "Nhap ngay thang nam (dd mm yyyy) muon sach: ";
		cin >> ngaytra >> thangtra >> namtra;
		cin.ignore(1000, '\n');
		for (i = 0; i < n; i++) {
			cout << endl;
			cout << "Nhap ISBN (ma sach) sach tra: ";
			getline(cin, sachtra[i]);
			timduoc = 0;
			for (j = 0; j < phieumuon[a].soluongsachdgmuon; j++) {
				if (phieumuon[a].sachduocmuontheodg[j] == sachtra[i]) {
					phieumuon[a].sachduocmuontheodg[j] = "";
					timduoc = 1;
				}
			}
			if (timduoc == 0) {
				cout << "Doc gia khong muon cuon sach nay." << endl;
				cout << "Yeu cau nhap lai tu dau." << endl;
				goto restart;
			}
		}
		cout << endl;
		cout << "TRA SACH THANH CONG." << endl;
		bool trehan = 0;
		if (checktrasach(ngaytra, thangtra, namtra, phieumuon[a].ngaytradukien, phieumuon[a].thangtradukien, phieumuon[a].namtradukien) > 0) {
			trehan = 1;
			cout << "DOC GIA DA TRA SACH TRE HAN." << endl;
			cout << "SO TIEN PHAI DEN BU: " << checktrasach(ngaytra, thangtra, namtra, phieumuon[a].ngaytradukien, phieumuon[a].thangtradukien, phieumuon[a].namtradukien) * 5000 << endl;
			timduoc = 0;
			for (i = 0; i < soluongdgtrehan; i++) {
				if (madgtrehan[i] == text)  timduoc = 1;
			}
		}
		if (timduoc == 0 && trehan == 1) {
			madgtrehan[soluongdgtrehan] = text;
			soluongdgtrehan++;
			ofstream file3;
			file3.open(filein3, ios_base::beg);
			for (i = 0; i < soluongdgtrehan; i++) {
				if (i == soluongdgtrehan - 1) file3 << madgtrehan[i];
				else file3 << madgtrehan[i] << endl;
			}
			file3.close();
		}
		ofstream file2;
		file2.open(filein2, ios_base::beg);
		for (i = 0; i < soluongphieumuon; i++) {
			if (i != a) {
				if (i == soluongphieumuon - 1) {
					file2 << phieumuon[i].madgmuon << "," << phieumuon[i].ngaymuon << "/" << phieumuon[i].thangmuon << "/" << phieumuon[i].nammuon << "," << phieumuon[i].ngaytradukien << "/" << phieumuon[i].thangtradukien << "/" << phieumuon[i].namtradukien << "," << phieumuon[i].soluongsachdgmuon << ",";
					for (j = 0; j < phieumuon[i].soluongsachdgmuon; j++) {
						if (phieumuon[i].sachduocmuontheodg[j] != "") {
							if (j == phieumuon[i].soluongsachdgmuon - 1)	file2 << phieumuon[i].sachduocmuontheodg[j];
							else file2 << phieumuon[i].sachduocmuontheodg[j] << " ";
						}
					}
				}
				else {
					file2 << phieumuon[i].madgmuon << "," << phieumuon[i].ngaymuon << "/" << phieumuon[i].thangmuon << "/" << phieumuon[i].nammuon << "," << phieumuon[i].ngaytradukien << "/" << phieumuon[i].thangtradukien << "/" << phieumuon[i].namtradukien << "," << phieumuon[i].soluongsachdgmuon << ",";
					for (j = 0; j < phieumuon[i].soluongsachdgmuon; j++) {
						if (phieumuon[i].sachduocmuontheodg[j] != "") {
							if (j == phieumuon[i].soluongsachdgmuon - 1)	file2 << phieumuon[i].sachduocmuontheodg[j];
							else file2 << phieumuon[i].sachduocmuontheodg[j] << " ";
						}
					}
					file2 << endl;
				}
			}
			else {
				if (phieumuon[a].soluongsachdgmuon - n != 0) {
					if (i == soluongphieumuon - 1) {
						file2 << phieumuon[i].madgmuon << "," << phieumuon[i].ngaymuon << "/" << phieumuon[i].thangmuon << "/" << phieumuon[i].nammuon << "," << phieumuon[i].ngaytradukien << "/" << phieumuon[i].thangtradukien << "/" << phieumuon[i].namtradukien << "," << phieumuon[i].soluongsachdgmuon - n << ",";
						for (j = 0; j < phieumuon[i].soluongsachdgmuon; j++) {
							if (phieumuon[i].sachduocmuontheodg[j] != "") {
								if (j == phieumuon[i].soluongsachdgmuon - 1)	file2 << phieumuon[i].sachduocmuontheodg[j];
								else file2 << phieumuon[i].sachduocmuontheodg[j] << " ";
							}
						}
					}
					else {
						file2 << phieumuon[i].madgmuon << "," << phieumuon[i].ngaymuon << "/" << phieumuon[i].thangmuon << "/" << phieumuon[i].nammuon << "," << phieumuon[i].ngaytradukien << "/" << phieumuon[i].thangtradukien << "/" << phieumuon[i].namtradukien << "," << phieumuon[i].soluongsachdgmuon - n << ",";
						for (j = 0; j < phieumuon[i].soluongsachdgmuon; j++) {
							if (phieumuon[i].sachduocmuontheodg[j] != "") {
								if (j == phieumuon[i].soluongsachdgmuon - 1)	file2 << phieumuon[i].sachduocmuontheodg[j];
								else file2 << phieumuon[i].sachduocmuontheodg[j] << " ";
							}
						}
						file2 << endl;
					}
				}
			}
		}
		file2.close();
		phieumuon[a].soluongsachdgmuon = phieumuon[a].soluongsachdgmuon - n;
	}
}
int menu5() {
	int choice;
	cout << endl;
	cout << "Ban da chon thao tac \"Cac thong ke co ban\"." << endl;
	cout << "Ban muon thuc hien chuc nang gi ?" << endl;
	cout << "1. Thong ke so luong sach trong thu vien." << endl;
	cout << "2. Thong ke so luong sach theo the loai." << endl;
	cout << "3. Thong ke so luong doc gia." << endl;
	cout << "4. Thong ke so luong doc gia theo gioi tinh." << endl;
	cout << "5. Thong ke so sach dang duoc muon." << endl;
	cout << "6. Thong ke danh sach doc gia bi tre han." << endl;
	cout << "Vui long chon phim chuc nang tuong ung voi thu tu tren: ";
	cin >> choice;
	return choice;
}
void cau5b(infobooks sach[MAX], int n) {
	string temp1[MAX];
	string temp2[MAX];
	cout << endl;
	int i, j;
	for (i = 0; i < n; i++) {
		temp1[i] = sach[i].theloai;
	}
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (temp1[i] == temp1[j]) temp1[j] = "";
		}
	}
	int dem1 = 0;
	int dem2 = 0;
	for (i = 0; i < n; i++) {
		if (temp1[i] != "") {
			temp2[dem1] = temp1[i];
			dem1++;
		}
	}
	cout << endl;
	cout << "THONG KE SACH THEO THE LOAI: " << endl;
	for (i = 0; i < dem1; i++) {
		dem2 = 0;
		for (j = 0; j < n; j++) {
			if (temp2[i] == sach[j].theloai) dem2++;
		}
		cout << setw(15) << left << temp2[i] << setw(10) << left << ": " << dem2 << endl;
	}
	cout << endl;
}
void cau5d(inforeader dg[MAX], int n) {
	cout << endl;
	int nam, nu, i;
	nam = 0;
	nu = 0;
	for (i = 0; i < n; i++) {
		if (dg[i].gioitinh == "Nam") nam++;
	}
	nu = n - nam;
	cout << setw(20) << left << "So doc gia nam la: " << nam << endl;
	cout << setw(20) << left << "So doc gia nu la: " << nu << endl;
	cout << endl;
}
void cau5e(phieumuonsach phieumuon[MAX], int soluongphieumuon,int soluongsachmuon) {
	cout << endl;
	if (soluongsachmuon == 0) cout << "KHONG CO CUON SACH NAO DUOC MUON." << endl;
	else {
		cout << "So cuon sach dang duoc muon: " << soluongsachmuon << endl;
		cout << endl;
		cout << "DANH SACH SACH DANG DUOC MUON THEO DOC GIA." << endl;
		cout << endl;
		cout << setw(20) << left << "MA DOC GIA" << "ISBN" << endl;
		for (int i = 0; i < soluongphieumuon; i++) {
			cout << setw(20) << left << phieumuon[i].madgmuon;
			for (int j = 0; j < phieumuon[i].soluongsachdgmuon; j++) {
				cout << phieumuon[i].sachduocmuontheodg[j];
			}
			cout << endl;
		}
	}
}
void cau5f(int soluongdgtrehan, string dsdgtrehan[MAX], inforeader dg[MAX], int soluongdocgia) {
	cout << endl;
	int i, j;
	if (soluongdgtrehan == 0) cout << "KHONG CO DOC GIA TRE HAN." << endl;
	else {
		cout << "DANH SACH DOC GIA BI TRE HAN" << endl;
		cout << setw(7) << left << "STT" << "HO VA TEN" << endl;;
		for (i = 0; i < soluongdgtrehan; i++) {
			for (j = 0; j < soluongdocgia; j++) {
				if (dsdgtrehan[i] == dg[j].madocgia) {
					cout << setw(7) << left << i + 1 << dg[j].hotendg;
				}
			}
		}
		cout << endl;
	}
}