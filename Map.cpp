#include "Map.hpp"
#include "Texture.hpp"
//Map 
int lev1_map[64][9] = {
	{1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,2,0,0,1},
	{1,0,0,0,0,0,0,3,1},
	{1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,5,1},
	{1,0,0,0,0,0,0,0,1},
	{1,2,0,0,1,1,1,1,1},
	{1,0,0,3,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,1},
	{1,1,1,0,0,0,0,0,1},
	{1,1,1,1,1,0,0,5,1},
	{1,0,0,2,0,0,0,0,1},
	{1,0,0,0,0,0,0,5,1},
	{1,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,1,1,1,1},

	{1,0,0,2,1,1,1,1,1},
	{1,0,0,3,1,0,0,3,1},
	{1,0,0,0,1,2,0,5,1},
	{1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,3,1},
	{1,0,0,0,0,0,0,0,1},
	{1,0,0,3,1,1,1,1,1},
	{1,0,0,0,1,1,1,1,1},
	{1,1,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,0,3,1},
	{1,5,0,2,0,0,0,0,1},
	{1,2,0,0,0,0,0,3,1},
	{1,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,1,1,1,1},

	{1,0,0,5,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,2,0,0,1},
	{1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,3,1},
	{1,0,0,0,0,1,0,0,1},
	{1,0,0,0,3,1,0,0,1},
	{1,2,0,0,0,1,1,1,1},
	{1,1,0,0,0,1,1,1,1},
	{1,1,0,0,3,1,0,2,1},
	{1,0,0,0,0,1,0,0,1},
	{1,0,0,0,5,1,0,0,1},
	{1,0,0,2,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,3,1},
	{1,0,0,0,1,1,1,1,1},

	{1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,3,1},
	{1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,5,1},
	{1,0,0,0,3,1,2,0,1},
	{1,0,0,0,0,1,1,0,1},
	{1,0,0,0,0,1,1,0,1},
	{1,2,0,0,1,1,1,1,1},
	{1,0,0,0,3,1,1,1,1},
	{1,0,0,0,0,3,1,1,1},
	{1,0,0,0,0,0,0,1,1},
	{1,0,0,0,0,0,0,0,1},
	{1,0,0,2,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,4,1},
};
Map::Map()
{
	rock = Texture::LoadTexture("images/brick.png", Game::renderer);
	loadMap(lev1_map);
	src.x = src.y = 0;
	src.h = dest.h = 80;
	src.w = dest.w = 80;
	dest.x = dest.y = 0;
}
//load map
void Map::loadMap(int arr[64][9])
{
	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			map[i][j] = lev1_map[i][j];
		}
	}
}
//draw map based on array
void Map::drawMap()
{
	int type;
	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			type = map[i][j];
			dest.y = j * 80;
			dest.x = i * 80;
			switch (type)
			{
			case 1:
				cout << "creating rock for x " << dest.x << " " << dest.y << endl;
				create_rock(dest.x, dest.y);
				break;
			case 2:
				cout << "creating coin" << endl;
				create_coin(dest.x, dest.y);
				break;
			case 3:
				cout << "Creating obstacle" << endl;
				create_obstacle(dest.x, dest.y);
				break;
			case 4:
				cout << "Creating flag" << endl;
				flag = new FFlag("images/flag.png", dest.x, dest.y);
				break;
			case 5:
				cout << "Creating Obstacle" << endl;
				create_obstacle1(dest.x, dest.y);
				break;
			default:
				break;
			}
		}
	}

}
//create objs
void Map::create_rock(int x, int y)
{
	rocks = new Rock("images/brick.png", x, y);
	level_rocks.push_back(rocks);
}

void Map::create_obstacle(int x, int y)
{
	obstacles = new Obstacle("images/spike monster A.png", x, y);
	level_obstacles.push_back(obstacles);
}

void Map::create_obstacle1(int x, int y)
{
	obstacles1 = new Obstacle1("images/spike monster B.png", x, y);
	level_obstacles1.push_back(obstacles1);
}

void Map::create_coin(int x, int y)
{
	coins = new Coin("images/Coin1.png", x, y);
	level_coins.push_back(coins);
}
//render objects
void Map::render_objects()
{
	for (int i = 0; i < level_rocks.size(); i++)
	{
		rocks = level_rocks[i];
		rocks->Render();
	}

	for (int i = 0; i < level_coins.size(); i++)
	{
		coins = level_coins[i];
		coins->Render();
	}

	for (int i = 0; i < level_obstacles.size(); i++)
	{
		obstacles = level_obstacles[i];
		obstacles->Render();
	}
	for (int i = 0; i < level_obstacles1.size(); i++)
	{
		obstacles1 = level_obstacles1[i];
		obstacles1->Render();
	}
	flag->Render();


}
