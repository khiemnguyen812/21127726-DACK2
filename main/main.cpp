#pragma once
#pragma warning
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include "function.h"
using namespace std;
#define MAX 200
int main() {
tryAgain:
	
	inforeader docgia[MAX];
	int soluongdocgia = 0;

	infobooks sach[MAX];
	int soluongsach = 0;

	phieumuonsach phieumuon[MAX];
	int soluongphieumuon = 0;
	int soluongsachmuon = 0;
	
	string madgtrehan[MAX];
	int soluongdgtrehan;

	docthongtindg("thongtindocgia.txt", docgia, soluongdocgia);
	docthongtinsach("thongtinsach.txt", sach, soluongsach);
	docthongtinphieumuon("phieumuon.txt", phieumuon, soluongphieumuon,soluongsachmuon);
	docthongtindgtrehan("thongtindgtrehan.txt", madgtrehan, soluongdgtrehan);


	int choice = menu();
	if (choice == 1) {
	restartcau1:
		docthongtindg("thongtindocgia.txt", docgia, soluongdocgia);
		int choice1 = menu1();
		if (choice1 == 1) {
			cau1a(docgia, soluongdocgia);
			cout << endl;
		}
		if (choice1 == 2) {
			cau1b("thongtindocgia.txt", docgia, soluongdocgia);
			cout << endl;
		}
		if (choice1 == 3) {
			cau1c("thongtindocgia.txt", docgia, soluongdocgia);
			cout << endl;
		}
		if (choice1 == 4) {
			cau1d("thongtindocgia.txt", docgia, soluongdocgia);
			cout << endl;
		}
		if (choice1 == 5) {
			cau1e(docgia, soluongdocgia);
			cout << endl;
		}
		if (choice1 == 6) {
			cau1f(docgia, soluongdocgia);
			cout << endl;
		}
		cout << endl;
		int ctn;
		cout << "Ban co muon tiep tuc thuc hien thao tac \"Quan li doc gia\" khong ? Neu co an phim 1, neu khong thi an phim 0: ";
		cin >> ctn;
		if (ctn == 1) goto restartcau1;
	}
	if (choice == 2) {
	restartcau2:
		int choice2 = menu2();
		if (choice2 == 1) {
			cau2a(sach, soluongsach);
			cout << endl;
		}
		if (choice2 == 2) {
			cau2b("thongtinsach.txt", sach, soluongsach);
			cout << endl;
		}
		if (choice2 == 3) {
			cau2c("thongtinsach.txt", sach, soluongsach);
			cout << endl;
		}
		if (choice2 == 4) {
			cau2d("thongtinsach.txt", sach, soluongsach);
			cout << endl;
		}
		if (choice2 == 5) {
			cau2e(sach, soluongsach);
			cout << endl;
		}
		if (choice2 == 6) {
			cau2f(sach, soluongsach);
			cout << endl;
		}
		cout << endl;
		int ctn;
		cout << "Ban co muon tiep tuc thuc hien thao tac \"Quan li sach\" khong ? Neu co an phim 1, neu khong thi an phim 0: ";
		cin >> ctn;
		if (ctn == 1) goto restartcau2;
	}
	if (choice == 3) {
		cau3("phieumuon.txt", docgia, soluongdocgia, sach, soluongsach, phieumuon, soluongphieumuon, soluongsachmuon);
		cout << endl;
	}
	if (choice == 4) {
		cau4("thongtinsach.txt", "phieumuon.txt", "thongtindgtrehan.txt", docgia, soluongdocgia, sach, soluongsach, phieumuon, soluongphieumuon, soluongsachmuon, madgtrehan, soluongdgtrehan);
		cout << endl;
	}
	if (choice == 5) {
	restartcau5:
		int choice5 = menu5();
		if (choice5 == 1) {
			int x = 0;
			for (int i = 0; i < soluongsach; i++) {
				x = x + atoi(sach[i].soquyensach.c_str());
			}
			cout << endl;
			cout << "So luong sach trong thu vien la: " << x << endl;
			cout << endl;
		}
		if (choice5 == 2) {
			cau5b(sach, soluongsach);
			cout << endl;
		}
		if (choice5 == 3) {
			cout << endl;
			cout << "So luong doc gia trong thu vien: " << soluongdocgia << endl;
			cout << endl;
		}
		if (choice5 == 4) {
			cout << endl;
			cau5d(docgia, soluongdocgia);
			cout << endl;
		}
		if (choice5 == 5) {
			cau5e(phieumuon, soluongphieumuon, soluongsachmuon);
			cout << endl;
		}
		if (choice5 == 6) {
			cau5f(soluongdgtrehan, madgtrehan, docgia, soluongdocgia);
		}
		int ctn;
		cout << "Ban co muon tiep tuc thuc hien thao tac \"Cac thong ke co ban\" khong ? Neu co an phim 1, neu khong thi an phim 0: ";
		cin >> ctn;
		cout << endl;
		if (ctn == 1) goto restartcau5;
	}
	int tieptuc;
	cout << "Ban co muon thuc hien chuc nang nao nua khong ? Neu co, nhan phim 1, neu khong, nhan nhim 0: ";
	cin >> tieptuc;
	cout << endl;
	if (tieptuc == 1) goto tryAgain;
	else cout << "THANKS YOU." << endl;
}