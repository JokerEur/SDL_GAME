#pragma once

#include "ECS.hpp"
#include "Components.hpp"

class PositionComponent : public Component
{

private:
    int xpos;
    int ypos;

public:
    void update() override
    {
        xpos++;
        ypos++;
    }

    inline int x() { return xpos; }
    void x(int x) { xpos = x; }
    inline int y() { return ypos; }
    void y(int y) { ypos = y; }
    void setPos(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
};