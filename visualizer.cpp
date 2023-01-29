#include "visualizer.hpp"
#include "params.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
 
Visualizer::Visualizer() {
    mNbBars = WIN_WIDTH/BAR_WIDTH;
    mIndex = 0;
    std::srand(std::time(nullptr));
    for(int i = 0; i < mNbBars; i++)
    {
        
        mBars.push_back(Bar {rand()%(int)WIN_HEIGHT});

        if(i > 0)
            mBars.back().move(sf::Vector2f(BAR_WIDTH*i, 0));

    }
 }

void Visualizer::sort() {
    mBars.at(mIndex).setColor(sf::Color::Green);

    if(mIndex > 0)
        mBars.at(mIndex - 1).setColor(sf::Color::White);
    else
        mBars.at(mNbBars - 1).setColor(sf::Color::White);


    //Bubble Sort//
    if(mIndex+1 < mNbBars)
    {
        Bar &bar1 = mBars.at(mIndex);
        Bar &bar2 = mBars.at(mIndex + 1);

        int val1 = bar1.getValue();
        int val2 = bar2.getValue();

        std::cout << "A: " << val1 << ", B: " << val2 << " swap ?" << (val1 > val2) << std::endl;
        if(val1 > val2)
        {
            swap(mIndex,mIndex+1);
        }
    }

    ///////////////


    mIndex++;
    if(mIndex >= mNbBars)
        mIndex = 0;
}

void Visualizer::swap(int index1, int index2) {
    Bar &bar1 = mBars.at(index1); 
    Bar &bar2 = mBars.at(index2); 

    const sf::Vector2f tempPos = bar1.getPosition();
    bar1.setPosition(bar2.getPosition());
    bar2.setPosition(tempPos);
    
    Bar tempBar = bar1;
    bar1 = bar2;
    bar2 = tempBar;




}

void Visualizer::draw(sf::RenderWindow &window) {
    for(Bar bar : mBars)
    {
        bar.draw(window);
    }
}
