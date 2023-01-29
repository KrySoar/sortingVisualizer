#pragma once

#include <SFML/Graphics.hpp>

class Bar {
    int mValue;
    sf::RectangleShape mBar;

public:
    Bar(int);

    void move(sf::Vector2f);
    void setPosition(sf::Vector2f);
    sf::Vector2f getPosition() const;

    void setColor(sf::Color);

    int getValue() const;

    void draw(sf::RenderWindow &) const;

};