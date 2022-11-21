#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Entity.h"

//#include "lib/sqlite/sqlitelib.h"
//using namespace sqlitelib;
//auto db = Sqlite("./game.db");

int main()
{
    const float heigh = 1680.f, width = 1050.f;
    sf::RenderWindow window(sf::VideoMode(heigh, width), "Dungeon", sf::Style::Fullscreen);
    window.setFramerateLimit(60);
    sf::View view(sf::FloatRect(0.f, 0.f, heigh, width));

    Player player;
    Entity entity;
    entity.setPosition(10, 50);
    entity.setRotation(45);

    while (window.isOpen())
    {
        //input
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        player.inputs(view);

        //draw
        window.clear(); 
        window.setView(view);
        player.draw(window);
        window.draw(entity);
        window.display();
        
    }

    return 0;
}
