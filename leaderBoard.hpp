//
//  leaderBoard.hpp
//  gameKnightB
//
//  Created by Oluwatosin  Oseni on 27/04/2022.
//

#ifndef leaderBoard_hpp
#define leaderBoard_hpp
#include "history.hpp"
#include <stdio.h>
using namespace std;
#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <fstream>
//#include <priority_queue>

class LeaderBoard{
    // we need to load from memory and get leader board sorted
    //using queue for overall memory of games played
private:
    priority_queue<pair<int, string>>   mainCache;
   
public:
    LeaderBoard(vector<History>& history, int& maxPlayersToDisplay);
    char requestLeaderBoardCategory();
    vector<History>  history;
    int   maxPlayersToDisplay;
    void  displayLeaderBoard();
    priority_queue<pair<int, string>>   getTopPlayersOverall();
    priority_queue<pair<int, string>>   getTopPlayersMonth();
    priority_queue<pair<int, string>>   getTopPlayersWeek();
    priority_queue<pair<int, string>>   getTopPlayersToday();
    
};
#endif /* leaderBoard_hpp */
