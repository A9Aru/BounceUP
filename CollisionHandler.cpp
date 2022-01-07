#include"CollisionHandler.hpp"
//constructor
CollisionHandler::CollisionHandler(Map* lev)
{
    m = lev;
}
//check collision overlap
bool CollisionHandler::checkCollision(SDL_Rect* a, SDL_Rect* b)
{
    bool x_overlap = (a->x < b->x + b->w) && (a->x + b->w > b->x);
    bool y_overlap = (a->y < b->y + b->h) && (a->y + b->h > b->y);
    return (x_overlap && y_overlap);
}
//check collision with coins
void CollisionHandler::checkMapCollision(SDL_Rect* a, Score* s)
{
    for (int i = 0; i < m->level_coins.size(); i++)
    {
        if (checkCircularCollision(a, m->level_coins[i]->getdrec()))
        {
            m->level_coins.erase(m->level_coins.begin() + i);
            s->updatescore(5);
            break;
        }
    }
}
//check collision with left wall
bool CollisionHandler::checkWallLeftCollision(SDL_Rect* a)
{
    bool ret = true;
    for (int i = 0; i < m->level_rocks.size(); i++)
    {
        m->rocks = m->level_rocks[i];
        if (m->rocks->getdrec()->x <= 160 && m->rocks->getdrec()->x >= 80)
        {
            if (SDL_HasIntersection(a, m->rocks->getdrec()))
                if (m->rocks->getdrec()->y >= a->y - 80 && m->rocks->getdrec()->y <= a->y + 80)
                {
                    ret = false;
                }
        }
    }
    return ret;
}
//check collision with right wall
bool CollisionHandler::checkWallRightCollision(SDL_Rect* a)
{
    bool ret = true;
    for (int i = 0; i < m->level_rocks.size(); i++)
    {
        m->rocks = m->level_rocks[i];
        if (m->rocks->getdrec()->x <= 240 && m->rocks->getdrec()->x >= 160)
        {
            if (SDL_HasIntersection(a, m->rocks->getdrec()))
                if (m->rocks->getdrec()->y >= a->y - 80 && m->rocks->getdrec()->y <= a->y + 80)
                {
                    ret = false;
                }
        }
    }
    return ret;
}
//check collision with the bottom wall
bool CollisionHandler::checkWallDownCollision(SDL_Rect* a)
{
    bool ret = true;
    for (int i = 0; i < m->level_rocks.size(); i++)
    {
        m->rocks = m->level_rocks[i];
        if (m->rocks->getdrec()->x <= 240 && m->rocks->getdrec()->x >= 80)
        {
            if (SDL_HasIntersection(a, m->rocks->getdrec()))
                if (a->y < m->rocks->getdrec()->y)
                {
                    ret = false;
                }
        }
    }
    return ret;
}
//check collision with top wall
bool CollisionHandler::checkWallUpCollision(SDL_Rect* a)
{
    bool ret = true;
    for (int i = 0; i < m->level_rocks.size(); i++)
    {
        m->rocks = m->level_rocks[i];
        if (m->rocks->getdrec()->x <= 240 && m->rocks->getdrec()->x >= 80)
        {
            if (SDL_HasIntersection(a, m->rocks->getdrec()))
                if (a->y > m->rocks->getdrec()->y)
                {
                    ret = false;
                }
        }
    }
    return ret;
}

//check collision with flag
bool CollisionHandler::checkFlag(SDL_Rect* a)
{
    return(checkCircularCollision(a, m->flag->getdrec()));
}
//check collision with obstacle
bool CollisionHandler::checkObstacle(SDL_Rect* a)
{
    for (int i = 0; i < m->level_obstacles.size(); i++)
    {
        if (checkCircularCollision(a, m->level_obstacles[i]->getdrec()))
        {
            return true;
        }
    }
    return false;
}
//check collisiosn with obstacle1
bool CollisionHandler::checkObstacle1(SDL_Rect* a)
{
    for (int i = 0; i < m->level_obstacles1.size(); i++)
    {
        if (checkCircularCollision(a, m->level_obstacles1[i]->getdrec()))
        {
            return true;
        }
    }
    return false;
}
//check collision with circular objects
bool CollisionHandler::checkCircularCollision(SDL_Rect* a, SDL_Rect* b) {
    int x1 = a->x + (a->w) / 2;
    int x2 = b->x + (b->w) / 2;
    int y1 = a->y + (a->h) / 2;
    int y2 = b->y + (b->h) / 2;
    int disc = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    int sumofr = ((a->h) / 2) + ((b->h) / 2);
    sumofr = sumofr * sumofr;

    if (disc <= sumofr) {
        return true;
    }
    return false;
}