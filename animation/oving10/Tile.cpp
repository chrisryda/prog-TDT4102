#include "Tile.h"
#include <map>

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

void Tile::open()
{
}

void Tile::flag()
{
}
