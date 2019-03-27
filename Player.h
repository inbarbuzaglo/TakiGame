#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include "Card.h"

using namespace std;

class Player {
private:
	string name;
	int num_of_cards;
public:
	 vector<Card> vec_cards;
	//private members
	

public:
	//constructors
	Player();
	Player(string name, int num_of_cards);

	//getters and setters
	string get_name();
	int get_numofcards();
	vector<Card> get_vec_card();
	void set_name(string player_name);
	void set_numofcards(int num_cards);
	void set_vec_card(vector<Card> vec_card);

	//public members
	bool play(Card&);

};
#endif
