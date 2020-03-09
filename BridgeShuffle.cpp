//###########################################################################
//---------------------------------------------------------------------------
//Programmer: 	  Scott Tyson
//Date: 		  12th October 2016
//Reference:	  Assignment 12, Exercise 30
//Folder:		
//Description:    Create a deck of cards, shuffle the deck and deal them to
//                four players, in the style of bridge
//Guarantee:      Program works to full specifications
#include<iostream>
#include<conio.h>
#include<iomanip>
#pragma hdrstop
using namespace std;

struct Card
{
	char suit;
	char value[ 4 ];
	int position;
};

void createDeck( Card [] );
void displayDeck( Card [] );
void shuffleDeck( Card [] );
void sortHand( Card [] );
void dealHand( Card [] );
//---------------------------------------------------------------------------
#pragma argsused
int _tmain(int argc, char* argv[])
{
	Card deck [ 52 ];
	char choice;

	createDeck( deck );

	srand( time( 0 ) );

	cout << "Select Function:" << endl << "Press 'A' to display deck" << endl
		  << "Press 'S' to shuffle deck" << endl << "Press 'D' to deal hands"
		  << endl << "Press 'ESC' to exit";
	choice = toupper( getch() );

	while ( choice != 27 )
	{
		switch ( choice )
		{
			case 'A' :
				displayDeck( deck );
				break;

			case 'S' :
				shuffleDeck( deck );
				break;

			case 'D' :
				dealHand( deck );
				break;

			case 'R' :
				createDeck( deck );
				cout << endl << endl << "Deck Reset!" << endl;
				break;

			default :
				clrscr();
				cout << "Invalid Input" << endl;
				break;
		}
		cout << endl << "Press any key to continue";
		getch();
		clrscr();

		cout << "Select Function:" << endl << "Press 'A' to display deck" << endl
			  << "Press 'S' to shuffle deck" << endl << "Press 'D' to deal hands"
			  << endl << "Press 'R' to reset deck" << endl
			  << "Press 'ESC' to exit";

		choice = toupper( getch() );
	}
	return 0;
}
//---------------------------------------------------------------------------
//createDeck( Card deck[] )
//Purpose: create an unshuffled deck, assign the cards their values
//Input: the deck
//Output: a deck of cards
//---------------------------------------------------------------------------
void createDeck( Card deck[] )
{
	char suits[ 4 ] = { 6, 3, 4, 5 };
	char values[ 13 ] [ 4 ] = { "2", "3", "4", "5", "6", "7", "8", "9", "10",
	"J", "Q", "K", "A" };

	for ( int i = 0; i < 52; i++ )
	{
		deck[ i ].suit = suits[ i / 13 ];
		strcpy( deck[ i ].value, values[ i % 13 ] );
		deck[ i ].position = i;
	}
}
//---------------------------------------------------------------------------
//displayDeck( Card deck[] )
//Purpose: print the deck of cards
//Input: the deck
//Output: printed card suits and values
//---------------------------------------------------------------------------
void displayDeck( Card deck[] )
{
	cout << endl;

	for ( int i = 0; i < 4; i++ )
	{
		for ( int j = 0; j < 13; j++ )
		{
			cout << ( ( j % 8 != 0 && j != 0 ) ? "\t" : "\n" )
				  << deck[ j + 13 * i ].value << deck[ j + 13 * i ].suit;
		}
		cout << endl << endl;
	}
}
//---------------------------------------------------------------------------
//shuffleDeck( Card deck[] )
//Purpose: shuffle the deck
//Input:
//Output:
//---------------------------------------------------------------------------
void shuffleDeck( Card deck[] )
{
	Card temp;

	for ( int i = 0; i < 52; i++ )
	{
		int j = rand() % 52;
		temp = deck[ i ];
		deck[ i ]= deck[ j ];
		deck[ j ] = temp;
	}

	cout << endl << endl << "Shuffled!" << endl;
}
//---------------------------------------------------------------------------
//sortHand( card dealtHand ) different name for each hand
//Purpose: sort the cards in descending order of value
//Input: north/west/east/southHand
//Output: north/west/east/southHand in order
//---------------------------------------------------------------------------
void sortHand( Card dealtHand[] )
{
	Card temp;

	for ( int i = 0; i < 12; i++ )
	{
		for ( int j = i; j < 13; j++ )
		{
			if ( dealtHand[ i ].position < dealtHand[ j ].position )
			{
				temp = dealtHand[ j ];
				dealtHand[ j ] = dealtHand[ i ];
				dealtHand[ i ] = temp;
			}
		}
	}
}
//---------------------------------------------------------------------------
//dealHand( Card deck[] )
//Purpose: deal the hands to the four players, in bridge format
//Input: Card deck[]
//Output: the printed hands
//---------------------------------------------------------------------------
void dealHand( Card deck[] )
{
	Card northHand[ 13 ];
	Card eastHand[ 13 ];
	Card southHand[ 13 ];
	Card westHand[ 13 ];
	char suits[ 4 ] = { 6, 3, 4, 5 };

	for ( int i = 0; i < 13; i++ )
	{
		northHand[ i ] = deck[ i ];
		westHand[ i ] = deck[ i + 13 ];
		eastHand[ i ] = deck[ i + 26 ];
		southHand[ i ] = deck[ i + 39 ];
	}

	sortHand( northHand );
	sortHand( westHand );
	sortHand( eastHand );
	sortHand( southHand );

	cout << endl << endl;

	cout << "NORTH" << endl;
	for ( int i = 0; i < 4; i++ )
	{
		cout << suits[ i ] << "  ";
		for ( int j = 0; j < 13; j++ )
		{
			if ( northHand[ j ].suit == suits[ i ] )
				cout << northHand[ j ].value << "  ";
		}
		cout << endl;
	}

	cout << endl << endl;

	cout << "WEST" << endl;
	for ( int i = 0; i < 4; i++ )
	{
		cout << suits[ i ] << "  ";
		for ( int j = 0; j < 13; j++ )
		{
			if ( westHand[ j ].suit == suits[ i ] )
				cout << westHand[ j ].value << "  ";
		}
		cout << endl;
	}

	cout << endl << endl;

	cout << "EAST" << endl;
	for ( int i = 0; i < 4; i++ )
	{
		cout << suits[ i ] << "  ";
		for ( int j = 0; j < 13; j++ )
		{
			if ( eastHand[ j ].suit == suits[ i ] )
				cout << eastHand[ j ].value << "  ";
		}
		cout << endl;
	}

	cout << endl << endl;

	cout << "SOUTH" << endl;
	for ( int i = 0; i < 4; i++ )
	{
		cout << suits[ i ] << "  ";
		for ( int j = 0; j < 13; j++ )
		{
			if ( southHand[ j ].suit == suits[ i ] )
				cout << southHand[ j ].value << "  ";
		}
		cout << endl;
	}
}
//---------------------------------------------------------------------------