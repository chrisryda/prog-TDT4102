#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

class Emoji {
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face : public Emoji {
public:
    Point c;
    int r;
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

class SadFace : public EmptyFace {
public:
    SadFace (Point centre, int radius);
    void draw(AnimationWindow&) override;
};

class AngryFace : public EmptyFace  {
public:
    AngryFace (Point centre, int radius);
    void draw(AnimationWindow&) override;
};

class SurprisedFace : public EmptyFace {
public:
    SurprisedFace (Point centre, int radius);
    void draw(AnimationWindow&) override;
};

void testEmoji(AnimationWindow &win);
