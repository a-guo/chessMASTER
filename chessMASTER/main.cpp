//
//  main.cpp
//  chessMASTER
//
//  Created by Addie Guo on 2018-01-19.
//  Copyright © 2018 Addie Guo. All rights reserved.
//

#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    RenderWindow window (VideoMode (640, 480), "Awesome Game");
    
    while (window.isOpen()) {
        Event event;
        
        while (window.pollEvent(event)) {
            switch(event.type) {
                case Event::Closed:
                    window.close();
                    
                    break;
            }
        }
        
        window.clear();
        window.display();
        
    }
}
