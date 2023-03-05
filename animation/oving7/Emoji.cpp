#include "Emoji.h"
#include <vector>
#include <memory>

Face::Face(Point centre, int radius) : c{centre}, r{radius} {}

void Face::draw(AnimationWindow &win) {
    win.draw_circle(c, r, Color::yellow);
}

EmptyFace::EmptyFace(Point centre, int radius) : Face(centre, radius) {};

void EmptyFace::draw(AnimationWindow &win) {
    Face::draw(win);
    win.draw_circle(Point{c.x - 50, c.y - 30}, 10, Color::black);
    win.draw_circle(Point{c.x + 50, c.y - 30}, 10, Color::black);
}

SmilingFace::SmilingFace(Point centre, int radius) : EmptyFace(centre, radius) {};

void SmilingFace::draw(AnimationWindow &win) {
    EmptyFace::draw(win);
    win.draw_arc(Point{c.x, c.y + 25}, r/2, 30, 180, 360);
}

SadFace::SadFace(Point centre, int radius) : EmptyFace(centre, radius) {};

void SadFace::draw(AnimationWindow &win) {
    EmptyFace::draw(win);
    win.draw_arc(Point{c.x, c.y + 50}, r/2, 30, 0, 180);
}

AngryFace::AngryFace(Point centre, int radius) :  EmptyFace(centre, radius) {};

void AngryFace::draw(AnimationWindow &win) {
    EmptyFace::draw(win);
    win.draw_arc(Point{c.x, c.y + 50}, r/2, 30, 0, 180);
    win.draw_line(Point{c.x - 60, c.y - 60}, Point{c.x - 40, c.y - 50}, Color::black);
    win.draw_line(Point{c.x + 60, c.y - 60}, Point{c.x + 40, c.y - 50}, Color::black);
}

SurprisedFace::SurprisedFace(Point centre, int radius) : EmptyFace(centre, radius) {};

void SurprisedFace::draw(AnimationWindow &win) {
    EmptyFace::draw(win);
    win.draw_circle(Point{c.x, c.y + 50}, 20, Color::black);
}

void testEmoji(AnimationWindow &win) {
    vector<std::unique_ptr<Emoji>> emojies;
    emojies.emplace_back(new EmptyFace(Point{900, 300}, 100));
    emojies.emplace_back(new SmilingFace(Point{700, 300}, 100));
    emojies.emplace_back(new SadFace(Point{500, 300}, 100));
    emojies.emplace_back(new AngryFace(Point{300, 300}, 100));
    emojies.emplace_back(new SurprisedFace(Point{100, 300}, 100));

    for (auto &e : emojies) {
        e->draw(win);
    }
}
