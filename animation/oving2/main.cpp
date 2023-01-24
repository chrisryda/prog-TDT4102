#include "std_lib_facilities.h"
#include "AnimationWindow.h"

using namespace std;

void pythagoras() {
    AnimationWindow win;

    Point point1{400,300};
    Point point2{400,500};
    Point point3{600,500};
    win.draw_triangle(point1, point2, point3, Color::dim_gray);

    int cat_length = point3.x - point1.x;
    win.draw_quad(point1, Point{point1.x - cat_length, point1.y}, Point{point2.x - cat_length, point2.y}, point2, Color::light_sky_blue);
    win.draw_quad(point2, Point{point2.x, point2.y + cat_length}, Point{point3.x, point3.y + cat_length}, point3, Color::light_sky_blue);
    win.draw_quad(point1, Point{point1.x + cat_length, point1.y - cat_length}, Point{point3.x + cat_length, point3.y - cat_length}, point3, Color::light_salmon);
    
    win.wait_for_close();
} 

int main() {
    pythagoras();
    return 0;
}
