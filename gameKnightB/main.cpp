//
//  main.cpp
//  gameKnightB
//
//  Created by Oluwatosin  Oseni on 25/04/2022.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <ctime>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/nvp.hpp>

#include "questionLoader.hpp"
#include "game.hpp"
#include "datehandle.hpp"
using namespace std;
vector<Question> loadQuestions(){
    vector<Question> quest;
  
    ifstream fin("/Users/elena/dev/gameKnightB/questionT.txt");
    text_iarchive ia(fin);
        
    ia >> make_nvp("questionT", quest);
    fin.close();
    return quest;

}



int main(int argc, const char * argv[]) {
//     insert code here...
    cout << "Starting program........\n";
//    QuestionLoader questionLoader;
//    questionLoader.loadQuestionsFromTxt();
//    vector<Question> questions = questionLoader.getMem();
//
//    ofstream fout("/Users/elena/dev/gameKnightB/questionT.txt");
//    text_oarchive oa(fout);
//    oa << make_nvp("questionT", questions);
//    fout.close();
//
//
    // Load questions

    vector<Question> quest = loadQuestions();

    // first we load the leaderboard from  memory
    vector<History> pastGamesPlayed;
    try{
        ifstream fin("/Users/elena/dev/gameKnightB/playerHistory.txt");
        text_iarchive ia(fin);
        ia >> make_nvp("gamesP", pastGamesPlayed);
        fin.close();

    }catch (const exception& e) {
        cout << e.what( ) << "";
        return EXIT_FAILURE;
     }



    Game game = Game(quest, pastGamesPlayed );
    vector<History> newGameHistory  = game.mainQuestionLoop();
    
    ofstream fout("/Users/elena/dev/gameKnightB/playerHistory.txt");
    text_oarchive oa(fout);
    oa << make_nvp("gamesP", newGameHistory);
    fout.close();



//     //initial set up to have file set up
//    vector<History> gamesPlayed;
//    History gameDummy;
//    gameDummy.setName("Bob");
//
//    gameDummy.setScore("7");
//    vector<string> dateToday;
//    dateToday = dateHandler::getDateHandler();
//    gameDummy.setdateDay(dateToday[2]);
//    gameDummy.setdateMonth(dateToday[1]);
//    gameDummy.setdateYear(dateToday[0]);
//    gamesPlayed.push_back(gameDummy);
//
//    ofstream fout("/Users/elena/dev/gameKnightB/playerHistory.txt");
//    text_oarchive oa(fout);
//    oa << make_nvp("gamesP", gamesPlayed);
//    fout.close();




    return 0;
};


