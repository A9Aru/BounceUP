#include"CollisionHandler.hpp"

CollisionHandler::CollisionHandler(Map *lev)
{
	m = lev;
}

bool CollisionHandler::checkCollision(SDL_Rect *a, SDL_Rect *b)
{
	bool x_overlap = (a->x < b->x + b->w) && (a->x + b->w > b->x);
	bool y_overlap = (a->y < b->y + b->h) && (a->y + b->h > b->y);
	return (x_overlap && y_overlap);
}

void CollisionHandler::checkMapCollision(SDL_Rect *a)
{
	for (int i=0; i<m->level_coins.size(); i++)
	{
		if (checkCollision(a, m->level_coins[i]->getdrec()))
		{
			m->level_coins.erase(m->level_coins.begin() + i);
			break;
		}
	}
}