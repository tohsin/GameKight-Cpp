//
//  game.hpp
//  gameKnightB
//
//  Created by Oluwatosin  Oseni on 26/04/2022.
//

#ifndef game_hpp
#define game_hpp
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "history.hpp"
#include "quest.hpp"
using namespace std;
class Game{
public:
    
public:
    
    Game(vector<Question> questions_list, vector<History>& pastGamesPlayed);
   
    vector<History> mainQuestionLoop();
    void outputHints(vector<Question> quesions);
    
    vector<Question> gameQuestions;
    vector<History> pastGamesPlayed;
    vector<Question> generateQuestion(int& numberQuestions);
    vector<int> getAnswers(vector<Question> questions);
    
    string initialGameDisplay();
    bool getUserAnswers(vector<int> answers);
    int generaterandomMathOperations(int numberOperations);
    int  generateRandomNumberOfQuestions(int max_questions);
    char requestLeaderBoardCategory();
    char requestNewRound(string& playername);
    char requestQuestionGeneration(string& playername);
    void initialiseLeaderBoardAndDisplay(vector<History>& history, int maxPlayersToDisplay);
    
    
};
#endif /* game_hpp */


