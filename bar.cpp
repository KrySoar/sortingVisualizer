#include "bar.hpp"
#include "params.hpp"

Bar::Bar(int value) {
    mValue = value;
    mBar.setSize(sf::Vector2f(BAR_WIDTH, value));
    mBar.setFillColor(sf::Color::White);
    mBar.rotate(180);
    mBar.move(sf::Vector2f(10,WIN_HEIGHT));
}

void Bar::move(sf::Vector2f relativePos) {
    mBar.move(relativePos);
}

void Bar::setPosition(sf::Vector2f position) {
    mBar.setPosition(position);
}

sf::Vector2f Bar::getPosition() const {
    return mBar.getPosition();
}

void Bar::setColor(sf::Color color) {
    mBar.setFillColor(color);
}

int Bar::getValue() const{
    return mValue;
}

void Bar::draw(sf::RenderWindow &window) const {
    window.draw(mBar);
}