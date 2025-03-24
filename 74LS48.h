#pragma once
#include "util.h"

class C74LS48 {
private:
	bool output[7] = {1,1,1,1,1,1,1};
public:
	C74LS48() = default;
	~C74LS48() = default;
	
	void decode(bool A, bool B, bool C, bool D);
	void proceed(unsigned in) {
		bool A, B, C, D;
		A = in / 8;
		B = in % 8 / 4;
		C = in % 4 / 2;
		D = in % 2;
		decode(A, B, C, D);
	}
	void draw()const {
		for (int i = 0; i < 7; i++) {
			setfillcolor(output[i] ? 0xFFFFFF : 0x333333);
			solidpolygon(sides[i]);
		}
	}
	void enter() {
		draw();
		FlushBatchDraw();
		for (int i = 0; i < 7; i++) {
			output[i] = 0;
		}
		Sleep(300);
	}
};

void C74LS48::decode(bool A, bool B, bool C, bool D) {
	bool& a = output[0];
	bool& b = output[1];
	bool& c = output[2];
	bool& d = output[3];
	bool& e = output[4];
	bool& f = output[5];
	bool& g = output[6];
	
	//8421BCD code
	bool NOT_A = !A;
	bool NOT_B = !B;
	bool NOT_C = !C;
	bool NOT_D = !D;

	bool B_XNOR_D = B == D;
	bool C_NAND_D = !(C && D);
	bool C_NOR_D = !(C || D);
	bool B_XOR_C = B != C;
	bool C_XNOR_D = C == D;
	bool A_OR_C = A || C;
	bool A_NOR_B = !(A || B);

	bool C_AND_NOT_D = C && NOT_D;
	bool C_OR_NOT_B = C || NOT_B;
	bool A_OR_NOT_B = A || NOT_B;

	bool B_AND_C_NAND_D = B && C_NAND_D;
	bool A_OR_C_NOR_D = A || C_NOR_D;
	bool D_AND_B_XOR_C = D && B_XOR_C;
	e = NOT_D && C_OR_NOT_B;

	bool A_OR_C_AND_NOT_D = A || C_AND_NOT_D;
	bool A_OR_NOT_D_AND_C_OR_NOT_B = A || e;

	a = A_OR_C || B_XNOR_D;
	f = A_OR_C_NOR_D || B_AND_C_NAND_D;
	b = A_OR_NOT_B || C_XNOR_D;
	g = A_OR_C_AND_NOT_D || B_XOR_C;
	c = !(A_NOR_B && C_AND_NOT_D);
	d = A_OR_NOT_D_AND_C_OR_NOT_B || D_AND_B_XOR_C;
	//total 26 gates
}