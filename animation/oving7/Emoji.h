#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

class Emoji {
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face : public Emoji {
private:
    Point c;
    int r;
public:
    Face (Point centre, int radius);
    void draw(AnimationWindow&) override;
};

class EmptyFace : public Face {
public:
    EmptyFace (Point centre, int radius);
    void draw(AnimationWindow&) override;
};

class SmilingFace : public EmptyFace {
public:
    SmilingFace (Point centre, int radius);
    void draw(AnimationWindow&) override;
};
