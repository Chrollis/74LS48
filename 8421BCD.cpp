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
	void progress(){
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

	//total 32
	}
};

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
