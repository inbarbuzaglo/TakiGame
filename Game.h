#pragma once
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
class Game {
private:

	std::vector<Player> vec_players;
	//private members and functions
public:
	//public members and functions
	 void start();
	 int Turn(Card &current, Player &p, int next_p, bool dir, int numofplayers);
	 int nextplayer1(int curr_p, bool dir, int numofplayers);
	 int nextplayer2(int curr_p, bool dir, int numofplayers);
};
#endif




