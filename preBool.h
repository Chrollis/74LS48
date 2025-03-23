#pragma once
#include <graphics.h>
#include <iostream>

class newBOOL {
public:
	bool x;

	newBOOL(bool a) {
		x = a;
	}
	~newBOOL() = default;
	newBOOL(const newBOOL& obj) {
		x = obj.x;
	}

	newBOOL AND(newBOOL a) {
		newBOOL c(x & a.x);
		return c;
	}
	newBOOL OR(newBOOL a) {
		newBOOL c(x | a.x);
		return c;
	}
	newBOOL NOT() {
		newBOOL c(!x);
		return c;
	}
	newBOOL NAND(newBOOL a) {
		newBOOL c(!(x & a.x));
		return c;
	}
	newBOOL NOR(newBOOL a) {
		newBOOL c(!(x | a.x));
		return c;
	}
	newBOOL XOR(newBOOL a) {
		newBOOL c((!x & a.x) | (x & !a.x));
		return c;
	}
	newBOOL XNOR(newBOOL a) {
		newBOOL c((x & a.x) | (!x & !a.x));
		return c;
	}
	bool operator()() {
		return (bool)x;
	}
	void operator[](bool a) {
		x = a;
	}
};

static void solidrectangle(RECT a, int edge = 2) {
	solidrectangle(a.left + edge, a.top + edge, a.right - edge, a.bottom - edge);
}

class SEVEN {
	RECT lines[7] = {
	{50,0,250,50},
	{0,50,50,250},
	{250,50,300,250},
	{50,250,250,300},
	{0,300,50,500},
	{250,300,300,500},
	{50,500,250,550}
	};
	newBOOL bits[7] = {
		newBOOL(0),newBOOL(0),newBOOL(0),newBOOL(0),newBOOL(0),newBOOL(0),newBOOL(0)
	};
	newBOOL& a = bits[0];
	newBOOL& b = bits[1];
	newBOOL& c = bits[2];
	newBOOL& d = bits[3];
	newBOOL& e = bits[4];
	newBOOL& f = bits[5];
	newBOOL& g = bits[6];
	newBOOL input[4] = {
		newBOOL(0),newBOOL(0),newBOOL(0),newBOOL(0)
	};
	newBOOL& A = input[0];
	newBOOL& B = input[1];
	newBOOL& C = input[2];
	newBOOL& D = input[3];
public:
	SEVEN() {
		for (int i = 0; i < 7; i++) {
			setfillcolor(0xFFFFFF);
			solidrectangle(lines[i]);
		}
		FlushBatchDraw();
		Sleep(500);
	}
	~SEVEN() = default;
	void draw() {
		cleardevice();
		for (int i = 0; i < 7; i++) {
			if (bits[i]()) {
				setfillcolor(0xFFFFFF);
			}
			else {
				setfillcolor(0x1F1F1F);
			}
			solidrectangle(lines[i]);
		}
		FlushBatchDraw();
	}
	void inkey(ExMessage msg) {
		switch (msg.vkcode) {
		case '0':
			A[0];
			B[0];
			C[0];
			D[0];
			break;
		case '1':
			A[0];
			B[0];
			C[0];
			D[1];
			break;
		case '2':
			A[0];
			B[0];
			C[1];
			D[0];
			break;
		case '3':
			A[0];
			B[0];
			C[1];
			D[1];
			break;
		case '4':
			A[0];
			B[1];
			C[0];
			D[0];
			break;
		case '5':
			A[0];
			B[1];
			C[0];
			D[1];
			break;
		case '6':
			A[0];
			B[1];
			C[1];
			D[0];
			break;
		case '7':
			A[0];
			B[1];
			C[1];
			D[1];
			break;
		case '8':
			A[1];
			B[0];
			C[0];
			D[0];
			break;
		case '9':
			A[1];
			B[0];
			C[0];
			D[1];
			break;
		default:
			break;
		}
	}
	void progress();
};