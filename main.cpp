#include "74LS48.h"

int WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd) {

	initgraph(6 * bsl, 11 * bsl);
	initialize_sides();
	DWORD start, delta;
	C74LS48 seven;
	ExMessage msg;

	BeginBatchDraw();
	seven.enter();

	while (1) {
		start = clock();
		while (peekmessage(&msg)) {
			if (msg.message == WM_KEYDOWN &&
				msg.vkcode >= '0' &&
				msg.vkcode <= '9') {
				seven.proceed(msg.vkcode - '0');
			}
			else if (msg.message == WM_KEYDOWN &&
				msg.vkcode == VK_ESCAPE) {
				exit(0);
			}
		}
		cleardevice();
		seven.draw();
		FlushBatchDraw();
		delta = clock() - start;
		if (delta < 33) {
			Sleep(33 - delta);
		}
	}

	EndBatchDraw();
	closegraph();
	return 0;
}