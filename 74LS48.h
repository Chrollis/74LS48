#pragma once
#include "util.h"

class C74LS48 {
private:
	bool output[7] = {1,1,1,1,1,1,1};
public:
	C74LS48() = default;
	~C74LS48() = default;
	
	void proceed(unsigned in);
	void draw()const {
		for (int i = 0; i < 7; i++) {
			setfillcolor(!output[i] ? 0xFFFFFF : 0x333333);
			solidpolygon(sides[i]);
		}
	}
	void enter() {
		draw();
		FlushBatchDraw();
		for (int i = 0; i < 7; i++) {
			output[i] = 1;
		}
		Sleep(300);
	}
};

void C74LS48::proceed(unsigned in) {
	bool A, B, C, D;
	A = in / 8;
	B = in % 8 / 4;
	C = in % 4 / 2;
	D = in % 2;

	bool& a = output[0];
	bool& b = output[1];
	bool& c = output[2];
	bool& d = output[3];
	bool& e = output[4];
	bool& f = output[5];
	bool& g = output[6];
	
	bool NOT_A = !A;
	bool NOT_B = !B;

	bool A_NOR_C = !(A || C);
	bool B_XOR_D = B != D;
	bool C_XOR_D = C != D;
	bool B_NOR_D = !(B || D);
	bool C_XNOR_D = C == D;
	bool A_NOR_B = !(A || B);
	bool B_NOR_C = !(B || C);
	bool B_AND_C = B && C;

	bool D_AND_NOT_B = D && NOT_B;
	bool C_NOR_NOT_B = !(C || NOT_B);
	bool D_OR_NOT_B = D || NOT_B;

	a = A_NOR_C && B_XOR_D;
	b = B && C_XOR_D;
	c = C && B_NOR_D;
	e = D || C_NOR_NOT_B;

	bool B_AND_C_XNOR_D = B && C_XNOR_D;
	bool C_AND_D_OR_NOT_B = C && D_OR_NOT_B;
	bool D_AND_A_NOR_B = D && A_NOR_B;
	bool D_AND_B_AND_C = D && B_AND_C;

	bool A_NOR_C_AND_D_AND_NOT_B = A_NOR_C && D_AND_NOT_B;
	bool B_NOR_C_OR_D_AND_B_AND_C = B_NOR_C || D_AND_B_AND_C;

	d = A_NOR_C_AND_D_AND_NOT_B || B_AND_C_XNOR_D;
	f = C_AND_D_OR_NOT_B || D_AND_A_NOR_B;
	g = NOT_A && B_NOR_C_OR_D_AND_B_AND_C;
	//total 26 gates
}
