#include "MinesweeperWindow.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <vector>
#include <cassert>

std::vector<int> getUniqueRandomNumbersInRange(int lower, int upper) {
	std::vector<int> numbers(upper-lower);
	std::iota(numbers.begin(), numbers.end(), lower);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));
    return numbers;
}

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	AnimationWindow{x, y, (width * cellSize) + 5, ((height + 1) * cellSize) + 50, title},
	width{width}, height{height}, mines{mines},
	gameInfo{{5,310}, 150, 70},
	restartBtn{{215, 305}, 100, 35, "Restart"},
	quitBtn{{215, 340}, 100, 35, "Quit"}
{
	add(gameInfo);
	gameInfo.setText("Mines left: " + std::to_string(mines));
	add(restartBtn);
	add(quitBtn);
	quitBtn.setCallback(std::bind(&MinesweeperWindow::cb_quit, this));
	restartBtn.setCallback(std::bind(&MinesweeperWindow::cb_restart, this));

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
			auto temp = tiles.back().get();
			add(*temp); 
		}
	}
	std::vector<int> range = getUniqueRandomNumbersInRange(0, tiles.size());
	int rand;
	for (int i = 0; i < mines; ++i) {
		rand = range.back();
		range.pop_back();
		tiles.at(rand).get()->setIsMine(true);
	}
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	if (at(xy).get()->getState() == Cell::closed) { 
		at(xy).get()->open();
		if (!at(xy).get()->getIsMine()) {
			openedTiles++;
			vector<Point> adjPoints = adjacentPoints(xy);
			int mines = countMines(adjPoints);
			if (mines > 0) {
				at(xy).get()->setAdjMines(mines);
			} else {
				for (Point p : adjPoints) {
					if (!at(p).get()->getIsMine())
						openTile(p);
				}
			}
		} else {
			hasLost = true;
			updateWindowOnLoss();
			gameInfo.setText("Game lost!\nTry again.");
		}
	}
	if (hasWon()) {
		updateWindowOnWin();
		gameInfo.setText("Game won!\nCongratulations!");
	}
}

void MinesweeperWindow::flagTile(Point xy) {
	if (at(xy).get()->getState() == Cell::closed) {
		at(xy).get()->flag();
		flaggedTiles++;
		gameInfo.setText("Mines left: " + std::to_string(mines-flaggedTiles));
	} else if (at(xy).get()->getState() == Cell::flagged) {
		at(xy).get()->flag();
		flaggedTiles--;
		gameInfo.setText("Mines left: " + std::to_string(mines-flaggedTiles));
	}
}

int MinesweeperWindow::countMines(std::vector<Point> coords) const {
	int mines = 0;
	for (Point p : coords) {
		if (at(p).get()->getIsMine()) {
			mines++;
		}
	}
	return mines;
}

void MinesweeperWindow::updateWindowOnWin() {
	for (auto t : tiles) {
		if (t.get()->getIsMine() && t.get()->getState() == Cell::closed) {
			t.get()->flag();
		}
	}
}

void MinesweeperWindow::updateWindowOnLoss() {
	for (auto t : tiles) {
		if (t.get()->getIsMine()) {
			t.get()->close();
			t.get()->open();
		}
	}
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click() {
	if (hasLost || hasWon()) {
		return;
	}
	Point xy{this->get_mouse_coordinates()};
	//std::cout << xy.x << " " << xy.y <<": " << xy.x / (cellSize) + (xy.y / cellSize) * width<<"\n";

	if (!inRange(xy)) {
		return;
	}
	if (this->is_left_mouse_button_down()) {
		openTile(xy);
	}
	else if(this->is_right_mouse_button_down()){
		flagTile(xy);
	}
}

void MinesweeperWindow::cb_restart() {
	hasLost = false;
	openedTiles = 0;
	flaggedTiles = 0;
	for (auto t : tiles) {
		t.get()->close();
		t.get()->setIsMine(false);
	}

	std::vector<int> range = getUniqueRandomNumbersInRange(0, tiles.size());
	int rand;
	for (int i = 0; i < mines; ++i) {
		rand = range.back();
		range.pop_back();
		tiles.at(rand).get()->setIsMine(true);
	}
	gameInfo.setText("Mines left: " + std::to_string(mines));
}

void MinesweeperWindow::cb_quit() {
	this->close();
}
