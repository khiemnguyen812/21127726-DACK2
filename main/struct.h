#pragma once
#pragma warning
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct inforeader {
	string madocgia;
	string hotendg;
	string cmnd;
	string ngaysinh, thangsinh, namsinh;
	string gioitinh;
	string mail;
	string diachi;
	string ngaylap, thanglap, namlap;
	string ngayhh, thanghh, namhh;
};
struct infobooks {
	string isbn;
	string tensach;
	string tacgia;
	string nhaxuatban;
	string namxb;
	string theloai;
	string giasach;
	string soquyensach;
};
struct phieumuonsach {
	string madgmuon;
    int ngaymuon, thangmuon, nammuon;
	int ngaytradukien, thangtradukien, namtradukien;
	int soluongsachdgmuon;
	string sachduocmuontheodg[10];
};