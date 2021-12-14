//
//  main.cpp
//  BeatThat
//
//

#include <iostream>
#include <string>
#include <cassert>
#include "RandomNumber.h"
#include "Die.h"
#include "Player.h"
#include "Board.h"
#include "BeatThat.h"

int main()
{
       using namespace std;
       using namespace cs31;
       // test code
  

    BeatThat game;
    Die d1;
    d1.setValue( 1 );
    Die d2;
    d2.setValue( 2 );
    Die d3;
    d3.setValue( 3 );
    Die d4;
    d4.setValue( 4 );
    Die d5;
    d5.setValue( 5 );
    Die d6;
    d6.setValue( 6 );
    
    game.humanPlay( d1, d2 );
    game.computerPlay( d1, d2 );
    game.endTurn( );
    assert( game.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game.humanPlay( d4, d4 );
    game.computerPlay( d6, d1 );
    game.endTurn( );
    assert( game.getComputer( ).getRoundsWon( ) == 1 );
    game.humanPlay( d3, d4 );
    game.computerPlay( d3, d2 );
    assert( game.getHuman().largestDie( ).getValue( ) == 4 );
    assert( game.getComputer().largestDie().getValue( ) == 3 );
    game.endTurn( );
    assert( game.isGameOver() == false );
    assert( game.getHuman( ).getRoundsWon( ) == 1 );
    game.humanPlay( d3, d3 );
    game.computerPlay( d3, d3 );
    game.endTurn( );
    assert( game.getComputer( ).getRoundsWon( ) == 1 );
    assert( game.getHuman( ).getRoundsWon( ) == 1 );
    game.humanPlay( d5, d4 );
    game.computerPlay( d4, d5 );
    game.endTurn( );
    assert( game.isGameOver() == true );
    assert( game.getHuman( ).getRoundsWon( ) == 1 );
    assert( game.getComputer( ).getRoundsWon( ) == 1 );
    assert( game.determineGameOutcome( ) == cs31::BeatThat::TIEDGAME );
    cout << "all tests passed!" << endl;
    return 0;

 }
    
