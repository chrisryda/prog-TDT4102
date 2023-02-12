#include <iostream>
#include <string>
#include <vector>
#include "mastermind.h"
#include "utilities.h"

using namespace std;

void playMastermind(int n, bool hide_code) {
    constexpr int size = 4;
    constexpr int letters = 6;
    string code = randomizeString(size, 'A', 'A'+(letters-1));
    if (!hide_code)
        cout << "CODE IS: " << code << endl;
    
    int count_char_and_pos = 0;
    int count_char = 0;
    string guess;
    for (int i = 0; i < n; i++) {
        guess = readInputToString(size, 'A', 'A'+(letters-1));
        count_char_and_pos = checkCharactersAndPosition(code, guess);
        count_char = checkCharacters(code, guess);
        
        cout << "\nNumber of correct characters: " << count_char << endl;
        cout << "Number of correct characters in correct position: " << count_char_and_pos << "\n" << endl;
        if (count_char_and_pos == size) {
            cout << "*****Congratulatons, you have won!*****" << endl;
            return;
        }
    }
    cout << "Sorry, but you are out of tries - better luck next time!" << endl;
}

int checkCharactersAndPosition(string code, string guess) {
    int count = 0;
    for (size_t i = 0; i < code.size(); i++) {
        if (tolower(code[i]) == tolower(guess[i])) {
            count++;
        }
    }
    return count;
}

int checkCharacters(string code, string guess) {
    int count = 0;
    for (size_t i = 0; i < 6; i++) {
        char c = 'A'+i;
        int count_code = countChar(code, c);
        int count_guess = countChar(guess, c);
        if (count_code > 0 && count_guess > 0) {
            count++;
        }
    }
    return count;
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
