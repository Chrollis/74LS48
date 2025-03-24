#pragma once
#include <graphics.h>
#include <ctime>
#include <vector>

unsigned interstice_width = 2;
unsigned block_side_length = interstice_width * 30;

unsigned& iw = interstice_width;
unsigned& bsl = block_side_length;

std::vector<std::vector<std::pair<int, int>>> sides(7);
void initialize_sides() {
	sides[0] = {
			{bsl / 3 + iw,iw},{bsl / 3 * 17 - iw,iw},
			{bsl / 3 * 16 - iw,bsl + iw} ,{bsl / 3 * 2 + iw,bsl + iw}
	};
	sides[5] = {
		{iw,iw},{bsl / 3 - iw,iw},
		{bsl / 3 * 2 - iw,bsl + iw},{bsl / 3 * 2 + 5 * iw,bsl + 5 * iw},
		{bsl / 3 * 2 + 5 * iw,bsl * 5 - 5 * iw},{bsl / 3 * 2 - iw,bsl * 5 - iw},
		{bsl / 2 - iw,bsl / 2 * 11 - iw},{iw,bsl / 2 * 11 - iw}
	};
	sides[6] = {
		{bsl / 3 * 2 + iw,bsl * 5 - iw},{bsl / 3 * 16 - iw,bsl * 5 - iw},
		{bsl / 2 * 11 - iw,bsl / 2 * 11 - iw},{bsl / 2 * 11 - iw,bsl / 2 * 11 + iw},
		{bsl / 3 * 16 - iw,bsl * 6 + iw},{bsl / 3 * 2 + iw,bsl * 6 + iw},
		{bsl / 2 + iw,bsl / 2 * 11 + iw},{bsl / 2 + iw,bsl / 2 * 11 - iw}
	};
	std::vector<std::pair<int, int>> temp;
	auto flip_vertical = [&](size_t a, size_t b) {
		temp = sides[a];
		for (std::pair<int, int>& p : temp) {
			p = std::pair<int, int>(p.first, 11 * bsl - p.second);
		}
		sides[b] = temp;
		};
	auto flip_horizontal = [&](size_t a, size_t b) {
		temp = sides[a];
		for (std::pair<int, int>& p : temp) {
			p = std::pair<int, int>(6 * bsl - p.first, p.second);
		}
		sides[b] = temp;
		};
	flip_vertical(0, 3);
	flip_vertical(5, 4);
	flip_horizontal(5, 1);
	flip_horizontal(4, 2);
}
void solidpolygon(const std::vector<std::pair<int, int>>& pairs) {
	size_t num = pairs.size();
	POINT* points = new POINT[num];
	for (int i = 0; i < num; i++) {
		points[i] = { pairs[i].first,pairs[i].second };
	}
	solidpolygon(points, num);
	delete[] points;
}