#include "Player.h"
using namespace std;

Player::Player()
{
	this->name = "";
	this->num_of_cards = 0;

	//vector<Card>::iterator it;

	//for (it = vec_cards.begin(); it < vec_cards.end(); it++)
	//{
	//	vec_cards.push_back(null);
	//}

}
Player::Player(string player_name, int num_cards)
{
	this->name = player_name;
	this->num_of_cards = num_cards;
}
string Player::get_name()
{
	return name;
}
int Player::get_numofcards()
{
	return num_of_cards;
}
void Player::set_name(string player_name)
{
	this->name = player_name;
}
void Player::set_numofcards(int num_cards)
{
	this->num_of_cards = num_cards;
}
vector<Card>Player::get_vec_card()
{
	return vec_cards;
}
void Player::set_vec_card(vector<Card> vec_card)
{
	this->vec_cards = vec_card;
}
