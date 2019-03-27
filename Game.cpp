#include "Game.h"
#include "Player.h"
#include <iostream>
#include <stdio.h>
#pragma once
using namespace std;

//the user input is a global vairable 
int num_players = 0;
int num_of_cards = 0;
int choice = 0;
bool flag = false;

void Game::start()
{
	string name;
	Card *c = new Card();
	Card current = c->generate_card();

	cout << "How many players ?";
	cin >> num_players;

	cout << "How many cards ?";
	cin >> num_of_cards;

	for (int i = 0; i < num_players; i++)
	{
		cout << std::endl << "Player number " << i + 1 << " name?";
		cin >> name;
		Player *p = new Player(name, num_of_cards);
		vec_players.push_back(*p);


		//insert and display cards for each player in his turn
		for (int j = 0; j < num_of_cards; j++)
		{
			vec_players[i].vec_cards.push_back(c->generate_card());
		}

	}
	int next_player = 0;
	int numofplayers = vec_players.size();
	bool direction = true; //from right to left.
	while (!flag)
	{
		cout <<"\n" << vec_players[next_player].get_name() << "  " << "your turn - ";
			cout << std::endl << "current : " << current << "\nyour cards :" << std::endl;
			for (int j = 0; j < vec_players[next_player].vec_cards.size(); j++)
			{
				cout << "(" << j + 1 << ")" << vec_players[next_player].vec_cards[j];
			}
			next_player = Turn(current, vec_players[next_player],next_player,direction, numofplayers);
			if (flag == false)//no winner yet
			{
				continue;
			}
			else
			{
				cout << "Player " << vec_players[next_player].get_name() << " wins!";

			}
		}
	}



int Game::Turn(Card &current,Player &p , int next_p, bool dir, int numofplayers)
{
	//const sign s = static_cast<sign>(rand() % 13);
	//const color co= static_cast<color>(rand()%4);

	Card *c = new Card();

		//choice needs to save the card position
		cin >> choice;

		//take new card if a the choice was out of the vector_cards bounds
		if ((choice > p.vec_cards.size()) || (choice < 1))
		{
			p.vec_cards.push_back(c->generate_card());
			next_p = nextplayer1(next_p, dir, numofplayers);
		}

		//if the card is +
		else if (p.vec_cards[choice - 1].get_sign() == sign(10))
		{
			current = p.vec_cards[choice - 1];
			p.vec_cards.erase(p.vec_cards.begin() + choice - 1);

			
		}

		//if the card is change direction
		else if (p.vec_cards[choice - 1].get_sign() == sign(12))
		{
			current = p.vec_cards[choice - 1];
			p.vec_cards.erase(p.vec_cards.begin() + choice - 1);
			dir = !dir;
			next_p = nextplayer1(next_p, dir, numofplayers);

		}

		//if the card is stop
		else if (p.vec_cards[choice - 1].get_sign() == sign(11))
		{
			current = p.vec_cards[choice - 1];
			p.vec_cards.erase(p.vec_cards.begin() + choice - 1);
			next_p = nextplayer2(next_p, dir, numofplayers);
		}

		//put legal card on the current card
		else if (current.is_legal(p.vec_cards[choice - 1]) == true)	
		{
				current = p.vec_cards[choice-1];
				p.vec_cards.erase(p.vec_cards.begin() + choice - 1);
				next_p = nextplayer1(next_p, dir, numofplayers);
				
		}

			//the player put illegal card on the current card
			else
			{
				cout << "You can't put " << p.vec_cards[choice - 1] << " on " << current;

				//waiting for another choice , should add what happend with that choice
				cin >> choice;
				p.vec_cards.erase(p.vec_cards.begin() + choice - 1);


			}
		return next_p;
		}

int Game::nextplayer1(int curr_p, bool dir, int numofplayers) //player++
{
	if ((dir) && (curr_p != numofplayers-1))
	{
		curr_p++;
		return curr_p;
	}
	else if ((dir) && (curr_p == numofplayers-1))
	{
		return 0;
	}
	else if ((!dir) && (curr_p != 0))
	{
	 curr_p--;
	 return curr_p;
	}
	else if ((!dir) && (curr_p == 0))
	{
		curr_p = numofplayers-1;
		return curr_p;
	}
	else
	{
		return -1;
	}

}


int Game::nextplayer2(int curr_p, bool dir, int numofplayers)//player+2
{

	if ((dir) && (curr_p != numofplayers) && (curr_p != numofplayers - 2))
	{
		 curr_p += 2;
		 return curr_p;
	}
	else if ((dir) && (curr_p == numofplayers - 2))
	{
		return 0;
	}
	else if ((dir) && (curr_p == numofplayers-1))
	{
		return 1;
	}
	else if ((!dir) && (curr_p != 0) && (curr_p != 1))
	{
		curr_p -= 2;
		return curr_p;
	}
	else if ((!dir) && (curr_p == 1))
	{
		numofplayers = -1;
		return numofplayers;
	}
	else if ((!dir) && (curr_p == 0))
	{

		numofplayers=-2;
		return numofplayers;
	}
	else
	{
		return -1;
	}
}
	

	
