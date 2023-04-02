#include "Tile.h"
#include <map>
#include <cassert>

// For aa sette labelfarge i henhold til hvor mange miner som er rundt
const std::map<int, TDT4102::Color> minesToColor {
	{1, TDT4102::Color::blue},
	{2, TDT4102::Color::red},
	{3, TDT4102::Color::dark_green},
	{4, TDT4102::Color::dark_magenta},
	{5, TDT4102::Color::dark_blue},
	{6, TDT4102::Color::dark_cyan},
	{7, TDT4102::Color::dark_red},
	{8, TDT4102::Color::gold}
};

// For aa sette Tilelabel i henhold til state
const std::map<Cell, std::string> cellToSymbol {
	{Cell::closed, ""},
	{Cell::open, ""},
	{Cell::flagged, "|>"}
};

Tile::Tile(TDT4102::Point pos, int size) : Button({pos.x, pos.y}, 1.5*size, size, "") {
	setButtonColor(TDT4102::Color::silver);
}

void Tile::setIsMine(bool m) {
	isMine = m;
}

void Tile::open() {
	if (state == Cell::open || state == Cell::flagged) {
		return;
	}
	state = Cell::open;
	setButtonColor(TDT4102::Color::white);
	if (isMine) {
		set_label("X");
		set_label_color(TDT4102::Color::red);
	}
}

void Tile::close() {
	if (state == Cell::closed) {
		return;
	}
	state = Cell::closed;
	setButtonColor(TDT4102::Color::silver);
	set_label(cellToSymbol.at(Cell::closed));
}

void Tile::flag() {
	if (state == Cell::flagged) {
		state = Cell::closed;
		set_label(cellToSymbol.at(Cell::closed));
	} else {
		state = Cell::flagged;
		set_label(cellToSymbol.at(Cell::flagged));
		set_label_color(TDT4102::Color::black);
	}
}

void Tile::setAdjMines(int n) {
	assert(n > 0 && n < 9);
	set_label(std::to_string(n));
	set_label_color(TDT4102::Color::blue); // TODO: minesToColor not working
}
