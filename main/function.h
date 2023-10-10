#pragma once
#pragma warning
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "struct.h"
using namespace std;
#define MAX 200
void docthongtindg(const char* filein, inforeader dg[MAX], int& n);
void docthongtinsach(const char* filein, infobooks sach[MAX], int& n);
void docthongtinphieumuon(const char* filein, phieumuonsach phieumuon[MAX], int& soluongphieumuon, int& soluongsachmuon);
void docthongtindgtrehan(const char* filein, string madgtrehan[MAX], int& n);
int menu();
int menu1();
void cau1a(inforeader dg[MAX], int& soluongdocgia);
void cau1b(const char* filein, inforeader dg[MAX], int& soluongdocgia);
void cau1c(const char* filein, inforeader dg[MAX], int& soluongdocgia);
void cau1d(const char* filein, inforeader dg[MAX], int& soluongdocgia);
void cau1e(inforeader dg[MAX], int& soluongdocgia);
void cau1f(inforeader dg[MAX], int& soluongdocgia);
int menu2();
void cau2a(infobooks sach[MAX], int& soluongsach);
void cau2b(const char* filein, infobooks sach[MAX], int& soluongsach);
void cau2c(const char* filein, infobooks sach[MAX], int& soluongsach);
void cau2d(const char* filein, infobooks sach[MAX], int& soluongsach);
void cau2e(infobooks sach[MAX], int& soluongsach);
void cau2f(infobooks sach[MAX], int& soluongsach);
void cau3(const char* filein, inforeader dg[MAX], int& soluongdocgia, infobooks sach[MAX], int soluongsach, phieumuonsach phieumuon[MAX], int& soluongphieumuon, int& soluongsachmuon);
void cau4(const char* filein, const char* filein2, const char* filein3, inforeader dg[MAX], int& soluongdocgia, infobooks sach[MAX], int soluongsach, phieumuonsach phieumuon[MAX], int& soluongphieumuon, int& soluongsachmuon, string madgtrehan[MAX], int& soluongdgtrehan);
int menu5();
void cau5b(infobooks sach[MAX], int n);
void cau5d(inforeader dg[MAX], int n);
void cau5e(phieumuonsach phieumuon[MAX], int soluongphieumuon, int soluongsachmuon);
void cau5f(int soluongdgtrehan, string dsdgtrehan[MAX], inforeader dg[MAX], int soluongdocgia);