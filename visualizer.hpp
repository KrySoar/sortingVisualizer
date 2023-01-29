#pragma once

#include "bar.hpp"
#include <vector>

class Visualizer {
    std::vector<Bar> mBars;
    int mNbBars;
    int mIndex;

public:
    Visualizer();

    void sort();
    void swap(int index1, int index2);

    void draw(sf::RenderWindow &);
};