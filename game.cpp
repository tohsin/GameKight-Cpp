//
//  game.cpp
//  gameKnightB
//
//  Created by Oluwatosin  Oseni on 26/04/2022.
//

#include "game.hpp"
#include "leaderBoard.hpp"
#include "datehandle.hpp"
using namespace std;

Game::Game(vector<Question> questions_list, vector<History>& gamesPlayed){
    gameQuestions = questions_list;
    pastGamesPlayed = gamesPlayed;
    
}

void Game::initialiseLeaderBoardAndDisplay(vector<History>& history, int maxPlayersToDisplay ){
    LeaderBoard leaderboard = LeaderBoard( history, maxPlayersToDisplay);
    leaderboard.displayLeaderBoard();
    
}

vector<History> Game::mainQuestionLoop(){

    string playername = initialGameDisplay();
    int score = 0;
    char option;
    cin >> option;
    if (option =='y'|| option =='Y'){
        while (true){
            //to start a new round
            option = requestNewRound(playername);
            if (option =='Y'){
                for(int i = 0; i<10; i++ ) {
                    option = requestQuestionGeneration(playername);
                    
                    if (option =='Y'){
                        // we have to randomise  number of questions
                        int numberQuestions = generateRandomNumberOfQuestions(4);
                        vector<Question> roundQuestions = generateQuestion(numberQuestions);
                            
                        outputHints(roundQuestions);
                        
                        vector<int> answers = getAnswers(roundQuestions);
                        
                        if (getUserAnswers(answers)){
                            score+=1;
                            cout <<endl << score <<"/ 10";
                            cout << "game" <<i+1;
                        }
                        else{
                            cout <<endl << score <<"/ 10";
                            cout<<endl<< "You didnt get that one !!";
                            cout << "game" <<i+1;
           
                        }
                    }else{
                        //player does press yess
                        cout <<endl <<endl<< playername<< " Quiting Game";
                        break;
                        }
                }
           
                // the loop is done and 10 questions are finished
                History currentGameHistoryItem;
                vector<string> dateToday;
                currentGameHistoryItem.setName(playername);
                currentGameHistoryItem.setScore(to_string(score));
                dateToday = dateHandler::getDateHandler();
                
                currentGameHistoryItem.setdateDay(dateToday[2]);
                currentGameHistoryItem.setdateMonth(dateToday[1]);
                currentGameHistoryItem.setdateYear(dateToday[0]);
                
                pastGamesPlayed.push_back(currentGameHistoryItem);
                
                cout <<endl << "Your final score is";
                cout <<endl << score <<"/ 10";
                if (score>=5){
                    cout <<endl << "You did well for a mere human";
                }else{
                    cout <<endl << "Boy do you need to read more";
                }
                   
       
       
            }
            else if (option =='L'){
                // display leader board
                
                initialiseLeaderBoardAndDisplay(pastGamesPlayed, 5 );
            }
            else{
                cout <<endl <<endl<< playername<< " Quiting Game";
                return pastGamesPlayed;
            }
            
        }
    }
    return pastGamesPlayed;
    

       
}

bool Game::getUserAnswers(vector<int> answers) {
            cout <<endl << " Pick between the options and enter 1 to 4 order doesn't matter";
            string option1;
            string option2;
    
            cout <<endl << "Enter option 1: ";
            cin >> option1;
    
            cout <<endl << "Enter option 2: ";
            cin >> option2;
    
            int answer1 = answers[0];
            int answer2 = answers[1];
            int op1Convert = stoi(option1)-1;
            int op2Convert = stoi(option2)-1;
    
            if ( ((answer1==op1Convert) || (answer1==op2Convert)) && ((answer2==op1Convert) || (answer2==op2Convert)) ){
                return  true;
            }
            return false;
}

vector<Question> Game:: generateQuestion(int& numberQuestions){
        unordered_set<int> usedQuestions;
        vector<Question> generated_questions;
        srand(time(0));

//        int numberQuestions = 4;
        // get random and unique keys for questions
        while (usedQuestions.size() != numberQuestions){
            int key = (rand() % gameQuestions.size());

            if (usedQuestions.find(key) == usedQuestions.end()){
                // key not found question safe to use
                generated_questions.push_back(gameQuestions[key]);
                usedQuestions.insert(key) ;
            }
        }

        return generated_questions;
}

void Game:: outputHints(vector<Question> quesions){
        // since the questions are generated randomly its safe to say taking the first two question from the four would also be random questions
    for(int i = 0;i<quesions.size();i++){
        cout<< endl<< to_string(i+1) +" " + quesions[i].getQuestion() ;
    }
}
    
vector<int> Game::getAnswers(vector<Question> questions){
    unordered_set<int> usedAnswers;
    int mathOperation;
    vector<int> answerIndexs;
    int questionResult;
    srand(time(0));
    // get the two questions that are likely the answers

    int numberOfAnswers = 2;
    
    // generates the questions to be answered randomly and uniquely so same option isnt used
    while (usedAnswers.size() != numberOfAnswers){
            int key = (rand() % questions.size());

            if (usedAnswers.find(key) == usedAnswers.end()){
                // key not found question safe to use
                answerIndexs.push_back(key);
                usedAnswers.insert(key);
            }
    }
    
    mathOperation = generaterandomMathOperations(4);
    
    switch (mathOperation) {
        case 0:
            // 0 will be addition
            questionResult = stoi(questions[answerIndexs[0]].getAns()) +  stoi(questions[answerIndexs[1]].getAns());
            cout<< endl<< "Question : ? + ? = " +to_string(questionResult);
            break;
        case 1:
            questionResult = stoi(questions[answerIndexs[0]].getAns()) * stoi(questions[answerIndexs[1]].getAns());
            cout<< endl<< "Question : ? * ? = " +to_string(questionResult);
            break;
        case 2:
            questionResult = abs(stoi(questions[answerIndexs[0]].getAns()) - stoi(questions[answerIndexs[1]].getAns()));
            cout<< endl<< "Question : ? - ? = " +to_string(questionResult);
            break;
        case 3:
            questionResult = max(stoi(questions[answerIndexs[0]].getAns()), stoi(questions[answerIndexs[1]].getAns())) % min(stoi(questions[answerIndexs[0]].getAns()), stoi(questions[answerIndexs[1]].getAns()));
            cout<< endl<< "Question : ? % ? = " +to_string(questionResult);
            break;
            
        default:
            break;
    }
               
    return answerIndexs;

}

int Game::generaterandomMathOperations(int numberOperations){
    // this function generate math operations between +, - , x
    //using integers  0 , 1 ,2
    srand(time(0));
    int operation = (rand() % numberOperations);
    return operation;
};


string Game::initialGameDisplay(){
    cout <<"        DIMS SUMS "<<endl<<endl;
    cout <<"        Question Generator " <<endl;
    cout << "       ------------------- ";
    cout <<endl<< "This a question generator for the Dim Sums Game from the series of Richard Osman's House of Games";
    string playername;
    cout <<endl << "Enter your name please : " ;
    getline(cin,playername);
    cout<<endl<< "Welcome "<<playername<<endl<<endl<<" Assistance: If you want to accept press 'y' and if you want to refuse press 'n' ";
    return  playername;
};


char Game::requestNewRound(string& playername){
    cout <<endl <<endl<< playername<< " Begin new round ? "<< endl;
    cout <<" Y to confirm, L to see leader board and  anything else to quit "<< endl;
    char option;
    cin >> option;
    option = toupper(option);
    return option;
};



char Game::requestQuestionGeneration(string& playername){
    cout <<endl <<endl<< playername<< " Do you want to generate a question ? "<< endl;
    cout <<" Y to confirm and anything  else to quit "<< endl;
    char option;
    cin >> option;
    option = toupper(option);
    return option;
};




int Game::generateRandomNumberOfQuestions(int max_questions){
    srand(time(0));
    int num_questions = (rand() % 3) + max_questions ;
    return  num_questions;

}
