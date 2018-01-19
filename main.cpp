#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int main() {
	RenderWindow window(VideoMode(453,453), "The Chess!");

	Texture t1;
	t1.loadFromFile("figures.png");

	Sprite s(t1);

	while(window.isOpen()) {
		Event e;
		while(window.pollEvent(e)) {
			if (e.type == Event::Closed) 
				window.close();
		}
	// DRAW WINDOW
	window.clear();
	window.draw(s);
	window.display();	
	}
	return 0;
}