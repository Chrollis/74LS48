#include "preBool.h"

void SEVEN::progress() {
	newBOOL n_b = B.NOT();
	newBOOL n_c = C.NOT();
	newBOOL xn_bd = B.XNOR(D);
	newBOOL xn_cd = C.XNOR(D);
	newBOOL x_bc = B.XOR(C);
	newBOOL na_cd = C.NAND(D);
	newBOOL no_cd = C.NOR(D);
	newBOOL o_bc = B.OR(C);
	newBOOL o_ac = A.OR(C);
	newBOOL o_ab = A.OR(B);
	newBOOL no_bd = B.NOR(D);
	newBOOL na_bd = B.NAND(D);

	newBOOL a_an_b = A.AND(n_b);
	newBOOL no_n_bd = n_b.NOR(D);
	newBOOL o_an_c = A.OR(n_c);
	newBOOL o_an_b = A.OR(n_b);
	newBOOL a_bna_cd = B.AND(na_cd);
	newBOOL o_ano_cd = A.OR(no_cd);
	newBOOL o_n_cd = n_c.OR(D);
	newBOOL o_ano_bd = A.OR(no_bd);
	newBOOL a_cna_bd = C.AND(na_bd);
	newBOOL a_dx_bc = D.AND(x_bc);

	newBOOL o_a_an_bno_n_bd = a_an_b.OR(no_n_bd);
	newBOOL a_o_an_co_bc = o_an_c.AND(o_bc);
	newBOOL o_o_ano_bda_cna_bd = o_ano_bd.OR(a_cna_bd);


	a = o_ac.OR(xn_bd);//a = A + C + (B^D)'
	b = o_ano_cd.OR(a_bna_cd);//b = A + B(CD)' + (C+D)'
	c = o_an_b.OR(xn_cd);//c = A + B' + (C^D)'
	d = o_a_an_bno_n_bd.OR(x_bc);//d = AB' + (B'+D)' + B^C
	e = D.NOR(a_o_an_co_bc);//e = (D + (A+C')(B+C))'
	f = o_ab.OR(o_n_cd);//f = A + B + C' + D
	g = o_o_ano_bda_cna_bd.OR(a_dx_bc);//g = A + (B+D)' + C(BD)' + D(B^C)

	//total 33
}

int WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd) {
	initgraph(300, 550);
	BeginBatchDraw();
	DWORD start, delta;
	SEVEN seven;
	ExMessage msg;
	while (1) {
		start = clock();
		seven.draw();
		while (peekmessage(&msg)) {
			seven.inkey(msg);
		}
		seven.progress();
		delta = clock() - start;
		if (delta < 33) {
			Sleep(33 - delta);
		}
	}
	EndBatchDraw();
	return 0;
}