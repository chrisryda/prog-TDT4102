#include "AnimationWindow.h"
#include "Emoji.h"


// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

	// EmptyFace e(Point{900, 100}, 100);
	SmilingFace s(Point{900, 100}, 100);
	// e.draw(win);
	s.draw(win);

	/* TODO:
	 *  - initialiser emojiene
	 *  - Tegn emojiene til vinduet
	 **/

	win.wait_for_close();

	return 0;
}
