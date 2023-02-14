#include "masterVisual.h"
#include "std_lib_facilities.h"
#include "mastermind.h"
#include "utilities.h"
#include <vector>

using namespace std;

void playMastermindVisual(int n, bool hide_code) {
	constexpr int size = 4;
    constexpr int letters = 6;
    string code = randomizeString(size, 'A', 'A'+(letters-1));
    if (!hide_code)
        cout << "CODE IS: " << code << endl;
    MastermindWindow mwin{800, 20, winW, winH, size, "Mastermind"};
	mwin.setCodeHidden(true);
    
    int count_char_and_pos = 0;
    int count_char = 0;
    string guess;
    for (int i = 0; i < n; i++) {
		guess = mwin.getInput(size, 'A', 'A'+(letters-1));
		addGuess(mwin, code, guess);
		count_char_and_pos = checkCharactersAndPosition(code, guess);
		count_char = checkCharacters(code, guess);
		vector<int> feedback = getFeedback(code, guess);
		addFeedback(mwin, feedback);
		
		cout << "\nYour guess: " << guess << endl;
		cout << "Number of correct characters: " << count_char << endl;
		cout << "Number of correct characters in correct position: " << count_char_and_pos << "\n" << endl;
		if (count_char_and_pos == size) {
			cout << "*****Congratulatons, you have won!*****" << endl;
			return;
		}
    }
    cout << "Sorry, but you are out of tries - better luck next time!" << endl;
}

void addGuess(MastermindWindow &mwin, const std::string code, const string guess_str)
{
	Guess guess{code, guess_str};
	mwin.guesses.emplace_back(guess);
}

void addFeedback(MastermindWindow &mwin, const vector<int> fback)
{

	Feedback feedback{fback};
	mwin.feedbacks.emplace_back(feedback);
}

void MastermindWindow::drawCodeHider()
{
	if(code_hidden) {
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::black);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const std::string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
guess{{upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.setCallback(std::bind(&MastermindWindow::newGuess, this));
};

string MastermindWindow::wait_for_guess()
{

	std::map<int, Color> colorConverter{
    {1, Color::red},
    {2, Color::green},
    {3, Color::yellow},
    {4, Color::blue},
    {5, Color::blue_violet},
    {6, Color::dark_cyan}
	};

	while (!button_pressed && !should_close())
	{
		for(int guessIndex = 0; guessIndex < static_cast<int>(guesses.size()); guessIndex++) {
			{
                for (int i = 0; i < guesses[guessIndex].guess.size(); i++) {
					// Remove comments to draw code
					// int code_letter = guesses[guessIndex].code[i];
					// draw_rectangle(Point{100*i, 100}, padX, padY, colorConverter.at(code_letter-64));
					
					int letter = guesses[guessIndex].guess[i];
					draw_rectangle(Point{100*i, 400-(50*guessIndex)}, padX, padY, colorConverter.at(letter-64));

				}
			}
		}

		for(int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++) {
			for (int i = 0; i < size; i++)
			{
				int color = feedbacks[feedbackIndex].feedback[i];
				Color colorIndicator;
				switch (color) {
					case 0:
						colorIndicator = Color::red;
						break;
					case 1:
						colorIndicator = Color::grey;
						break;
					case 2:
						colorIndicator = Color::black;
						break;
				}
				draw_circle(Point{420+(20*i), 415-(50*feedbackIndex)}, radCircle, colorIndicator);
			}
		}
		// Burde tegnes sist siden den skal ligge på toppen
		drawCodeHider();
		next_frame();
	}
	button_pressed = false;

	string newGuess = guess.getText();
	guess.setText("");
	
	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) {
	code_hidden = hidden;
}

vector<int> getFeedback(string code, string guess) {
    vector<int> feedback(code.size());
    vector<int> char_vec(code.size());
    vector<int> char_and_pos_vec(code.size());

    for (size_t i = 0; i < code.size(); i++) {
        if (tolower(code[i]) == tolower(guess[i])) {
            char_and_pos_vec[i] = 1;
        }
    }
    for (size_t i = 0; i < code.size(); i++) {
        if (code.find(guess[i]) != string::npos) {
            char_vec[i] = 1;
        }
    }
    for (size_t i = 0; i < feedback.size(); i++) {
        feedback[i] = char_vec[i] + char_and_pos_vec[i];
    }
    return feedback;
}
