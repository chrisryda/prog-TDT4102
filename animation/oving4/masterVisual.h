#pragma once
#include "widgets/Button.h" 
#include "widgets/TextInput.h" 
#include "AnimationWindow.h"
#include <vector>

using namespace TDT4102;

constexpr int winW = 500; // velg vindu bredde
constexpr int winH = 500; // velg vindu hoyde

constexpr int padY = winH / (2*8+1);      // velg x skalering
constexpr int padX = winW / (2*5+1);      // velg y skalering
constexpr int radCircle = padX / 8; // velg sirkel radius

constexpr int btnW = padX+100;          //velg knapp bredde basert på padX
constexpr int btnH = padY;          //velg knapp høyde basert på padY
constexpr Point upperLeftCornerBtn = Point{winW - padX - btnW, padY};

constexpr int inBoxW = winW - 3 * padX - btnW;
constexpr int inBoxH = padY;
constexpr Point upperLeftCornerInBox = Point{padX, padY};

struct Guess {
    const std::string code; 
    const std::string guess; 
};

struct Feedback {
    const std::vector<int> feedback;
};

// Her defineres klassen MastermindWindow, som arver fra klassen AnimationWindow.
// Det betyr at alle medlemsvariable og medlemsfunksjoner i AnimationWindow, også er en
// del av MastermindWindow. Du kan lese mer om klasser i kapittel 9.4 og om arv
// i kapittel 14.3 i læreboka.
class MastermindWindow : public AnimationWindow
{
public:
    MastermindWindow(int x, int y, int w, int h, int size, const std::string &title);

    std::vector<Guess> guesses;
    std::vector<Feedback> feedbacks;

    void setCodeHidden(bool hidden);

    std::string getInput(unsigned int n, char lower, char upper);

    

private:
    std::string wait_for_guess();
    void newGuess() { button_pressed = true; }
    void drawCodeHider();
    bool button_pressed = false;
    bool code_hidden = true;
    Button guessBtn;
    TextInput guess;
    int size = 0;
};

void addGuess(MastermindWindow &mwin, const std::string code, const std::string guess);
void addFeedback(MastermindWindow &mwin, const std::vector<int> feedback);
void playMastermindVisual(int n, bool hide_code);
