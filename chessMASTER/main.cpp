#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

using namespace sf;

int size = 56;

Sprite f[32]; // figures

int board[8][8] =
{-1, -2, -3, -4, -5, -3, -2, -1,
    -6, -6, -6, -6, -6, -6, -6, -6,
    0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,
    6,  6,  6,  6,  6,  6,  6,  6,
    1,  2,  3,  4,  5,  3,  2,  1,
};

void loadPosition() {
    int k = 0;
    for (int i = 0; i < 8; i ++)
        for (int j = 0; j < 8; j++) {
            int n = board[i][j];
            if (!n) continue;
            int x = abs(n) - 1;
            int y = n > 0? 1 : 0;
            f[k].setTextureRect(IntRect(size * x, size * y, size, size));
            f[k].setPosition(size * j, size * i);
            k++;
        }
}

int main() {
    RenderWindow window (VideoMode (453, 453), "chessMASTER");
    
    Texture t1, t2;
    t1.loadFromFile("images/figures.png");
    t2.loadFromFile("images/board0.png");
    
    Sprite s(t1, IntRect(60, 60, 50, 50));
    Sprite sBoard(t2);
    
    for (int i = 0; i < 32; i++) f[i].setTexture(t1);
    
    loadPosition();
    
    bool isMove = false;
    float dx = 0, dy = 0;
    int n = 0;
    
    while (window.isOpen()) {
        Vector2i pos = Mouse::getPosition(window);
        
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed)
                window.close();
            
            //drag & drop//
            if (e.type == Event::MouseButtonPressed)
                if (e.mouseButton.button == Mouse::Left)
                    for (int i = 0; i < 32; i++)
                        if (f[i].getGlobalBounds().contains(pos.x, pos.y))
                        {
                            isMove = true;
                            n = i;
                            dx = pos.x - f[i].getPosition().x;
                            dy = pos.y - f[i].getPosition().y;
                        }
            if (e.type == Event::MouseButtonReleased)
                if (e.mouseButton.button == Mouse::Left)
                {
                    isMove = false;
                    Vector2f p = f[n].getPosition() + Vector2f(size/2, size/2);
                    Vector2f newPos = Vector2f(size * int(p.x/size), size * int(p.y/size));
                    f[n].setPosition(newPos);
                }
        }
        
        if (isMove) f[n].setPosition(pos.x - dx, pos.y - dy);
        
        // draw //
        window.clear();
        window.draw(sBoard);
        for (int i = 0; i < 32; i++) window.draw(f[i]);
        window.display();
    }
    
    return 0;
}

