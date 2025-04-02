#pragma once
#include <graphics.h>
#include <ctime>
#include <vector>

constexpr int side = 24;
constexpr int width = 7 * side;
constexpr int height = 13 * side;

std::vector<std::vector<std::pair<int, int>>> sides(7);
void initialize_sides() {
	sides[0] = {
		{side,side / 4 * 3},{side,side / 4}, { side / 2 * 3,0 },{side / 2 * 11,0},{side * 6,side / 4},{side * 6,side / 4 * 3}, { side / 2 * 11,side },{side / 2 * 3,side}
	};
	std::vector<std::pair<int, int>> temp;
	temp = sides[0];
	for (std::pair<int, int>& p : temp) {
		p = std::pair<int, int>(p.second, p.first);
	}
	sides[5] = temp;
	temp = sides[0];
	for (std::pair<int, int>& p : temp) {
		p = std::pair<int, int>(p.first, p.second + 6 * side);
	}
	sides[6] = temp;
	auto flip_vertical = [&](size_t a, size_t b) {
		temp = sides[a];
		for (std::pair<int, int>& p : temp) {
			p = std::pair<int, int>(p.first, height - p.second);
		}
		sides[b] = temp;
		};
	auto flip_horizontal = [&](size_t a, size_t b) {
		temp = sides[a];
		for (std::pair<int, int>& p : temp) {
			p = std::pair<int, int>(width - p.first, p.second);
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