#include "Emoji.h"

Face::Face(Point centre, int radius) : c{centre}, r{radius} {}

void Face::draw(AnimationWindow &win) {
    win.draw_circle(c, r, Color::yellow);
}

EmptyFace::EmptyFace(Point centre, int radius) : Face(centre, radius) {};

void EmptyFace::draw(AnimationWindow &win) {
    Face::draw(win);
    win.draw_circle(Point{850, 70}, 10, Color::black);
    win.draw_circle(Point{950, 70}, 10, Color::black);
}

SmilingFace::SmilingFace(Point centre, int radius) : EmptyFace(centre, radius) {};

void SmilingFace::draw(AnimationWindow &win) {
    EmptyFace::draw(win);
    win.draw_arc(Point{900, 125}, 40, 15, 0, 180);
}
