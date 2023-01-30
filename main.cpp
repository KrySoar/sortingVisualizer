#include <iostream>
#include <SFML/Graphics.hpp>
#include "params.hpp"
#include "visualizer.hpp"
#include <vector>

void run();

int main()
{
    run();

    return 0;
}

void run()
{
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Sorting Algorithms Visualizer");
    window.setFramerateLimit(0);
    Visualizer visualizer;

    while (window.isOpen())
    {
        visualizer.sort();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        visualizer.draw(window);

        window.display();
    }
}