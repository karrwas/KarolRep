/*
Quick project of dungeon type mini game, that I prepared during my studies of electronics and telecommunication at
Gdansk University of Technology

Player must find the vault. First he sees the whole dungeon, as he starts, only quarter of the map that he is
currently in, is visible for him. During his adventure, the player needs to avoid randomly hidden bombs.
Good time killer while traveling.

Karol Wasik
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct seeker {			
	int x;						//horizontal position of the player
	int y;						//vertical position of the player
	char d;						//character that represents the player
};


void drawMap(seeker player, char tab[][22], bool &game)
{
	int i, j, m, n, k, p;							//variables defining player's location and visible section of a map

	if (player.y >= 11 && player.x <= 10)
	{
		i = 11; j = 0; n = 22; m = 11;
	}

	else if (player.y >= 11 && player.x >= 11) 				//controling visible part of a map using the size of tab[] which contains it
	{
		i = 11; j = 11; n = 22; m = 22;
	}

	else if (player.y <= 10 && player.x <= 10)
	{
		i = 0; j = 0; n = 11; m = 11;
	}

	else if (player.y <= 10 && player.x >= 11)
	{
		i = 0; j = 11; n = 11; m = 22;
	}

	for (k = i; k < n; k++) {
		for (p = j; p < m; p++)
		{
			if (tab[k][p] == '*')			//covering the bombs while the game is on
				cout << " ";
			else
				cout << tab[k][p];
		}
		cout << endl;
	}
	
	if (tab[player.y][player.x] == tab[1][20] || tab[player.y][player.x] == 'X'){
		system("cls");
		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 22; j++)
				if (tab[i][j] == '*')
				cout << '*';                 //showing the bombs
			else 
				cout << tab[i][j];
				cout << endl;				
		}	
		}
		
	if (tab[player.y][player.x] == tab[1][20]) {
		game = false;									//in case of victory
		cout << "> Congratulations!\n";
	}
	
	else if (tab[player.y][player.x] == 'X')
		cout << "> You stepped on a bomb! GAME OVER." << endl;		//in case of stepping on a bomb
}


void movement(seeker &player, char tab[][22], int &steps, bool &game)
{
	player.d = '.';							//leaving footsteps
	tab[player.y][player.x] = player.d;
	
	if (tab[player.y][player.x + 1] == '*' ||
		tab[player.y + 1][player.x] == '*' ||
		tab[player.y][player.x - 1] == '*' ||				//warning the player that he is about to step on a bomb
		tab[player.y - 1][player.x] == '*')
			cout << "> Be careful! Bomb ahead." << endl;
			
	char move = getch();			
		
	int dx = 0;								//variables describing horizontal and vertical movement of the player
	int dy = 0;

	switch (move) {							//using WSAD to move the player
	case 'w': dy--; break;
			
	case 'a': dx--; break;
			
	case 's': dy++; break;
			
	case 'd': dx++; break;		
	}

	char cell = tab[player.y + dy][player.x + dx];					//defining current position of the player
	
	if (cell == ' ' || cell == '.' || cell == '*' || cell == '$') {			//enabling the player to step on a free spot/his own steps/bombs/the vault
		player.x += dx;
		player.y += dy;
		
		steps++;
	}

	if (cell == '*') {
		player.d = 'X';
		tab[player.y][player.x] = player.d;					//showing that the player is no more. He stepped on a bomb
		game = false; 
	}	
		else	
			player.d = '#';
			tab[player.y][player.x] = player.d;			//if the player avoids the bombs, he carries on
}


void setBombs(char tab[][22]) 
{	
	int max = rand() % 3 + 4;			//setting 4 to 6 bombs randomly
	int countBombs = 0;
	
	while (countBombs < max) {
		int x = rand() % 20 + 1;		//randomly picking places for bombs
		int y = rand() % 20 + 1;

		if (tab[y][x] != ' ') continue;		//avoiding putting the bombs in the walls or the vault

		tab[y][x] = '*';
		countBombs++;
	}
}


void instruction(char tab[][22])				//telling the player his task
{		
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 22; j++)
			if (tab[i][j] == '*')
				cout << ' ';                 //covering previously set bombs
			else 
				cout << tab[i][j];
				cout << endl;				
	}	
	cout << "> Take a quick look at The Dungeon..." << endl;
	cout << "> Get to the vault..." << endl;	
}


int main()
{
	srand(time(0));

	bool game = true;
	int steps = 0;

	char tab[22][22] = {
	{'+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+'} ,
	{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|'} ,
	{'|',' ','+','-','+','-','-','-','-','-','-','-','-','-','+',' ',' ',' ',' ',' ',' ','|'} ,
	{'|',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','+','-','+',' ','|'} ,
	{'|',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|'} ,
	{'|',' ',' ',' ','+',' ',' ','+','-','-','-','-','-','-','-','-','+',' ',' ','+',' ','|'} ,
	{'|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ','|'} ,
	{'|',' ','+','-','+',' ',' ','+',' ',' ',' ',' ',' ',' ',' ',' ','+','-','-','-','+','|'} ,
	{'|',' ',' ',' ',' ',' ',' ',' ',' ','+',' ',' ',' ','+',' ',' ',' ',' ',' ',' ',' ','|'} ,
	{'|',' ',' ',' ','+',' ',' ','+',' ','|',' ',' ',' ','|',' ',' ',' ','+','-','-','+','|'} ,
	{'|',' ',' ',' ','|',' ',' ','|',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'} ,
	{'|',' ','+','-','+','-','-','+',' ','+','-','-','-','+',' ',' ',' ','+','-','+',' ','|'} ,
	{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'} ,
	{'|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'} ,
	{'|','+',' ','+',' ',' ','+',' ',' ','+','-','-','-','-','-','+','-','-','+',' ',' ','|'} ,
	{'|',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|'} ,
	{'|',' ',' ','+','-','-','+',' ',' ','+',' ',' ',' ',' ',' ','|',' ','+',' ',' ',' ','|'} ,
	{'|',' ',' ',' ',' ',' ','|',' ',' ','|',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ','|'} ,
	{'|','-','-','-','-','-','+',' ',' ','+','-','-','-','+',' ','+',' ','+','-','-','-','|'} ,
	{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'} ,
	{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'} ,
	{'+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+'} };

	seeker player;

	player.x = 1;
	player.y = 20;                       //putting the player on a START
	player.d = '#';

	tab[player.y][player.x] = player.d;
	tab[1][20] = '$';						//marking the vault
	
	setBombs(tab);
	instruction(tab);
	
	while (game) {							// making the game happen until the player looses or wins
		movement(player, tab, steps, game);
		system("CLS");
		drawMap(player, tab, game);
	}
	cout << "> Steps count: " << steps << endl;		// showing results
	system("pause"); 							
	return 0;
}
