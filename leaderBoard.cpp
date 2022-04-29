//
//  leaderBoard.cpp
//  gameKnightB
//
//  Created by Oluwatosin  Oseni on 27/04/2022.
//

#include "leaderBoard.hpp"
#include "datehandle.hpp"
LeaderBoard::LeaderBoard(vector<History>& history_, int& maxPlayersToDisplay){
    history = history_;
    maxPlayersToDisplay = maxPlayersToDisplay;
}

priority_queue<pair<int, string>> LeaderBoard::getTopPlayersOverall(){
    priority_queue<pair<int, string>>   memCache;
    for(auto historyItem :history){
        History hist = historyItem;
        int priority_ = -1 * stoi(hist.getScore());
        string playerDetail = hist.getName() + " " +hist.getdateDay() + "/" + hist.getdateMonth() + "/" + hist.getdateYear();
        memCache.push(make_pair(priority_, playerDetail));

        if (memCache.size()>10){
            memCache.pop();
        }

    }
    return memCache;
}

priority_queue<pair<int, string>>   LeaderBoard::getTopPlayersMonth(){
    
    priority_queue<pair<int, string>>   memCache;
    string currMonth  = dateHandler::getDateHandler()[1];
    for(auto historyItem :history){
        History hist = historyItem;
        // if item belongs to the same month
        if (hist.getdateMonth()==currMonth){
            int priority_ = -1 * stoi(hist.getScore());
            string playerDetail = hist.getName() + " " +hist.getdateDay() + "/" + hist.getdateMonth() + "/" + hist.getdateYear();
            memCache.push(make_pair(priority_, playerDetail));

            if (memCache.size()>10){
                memCache.pop();
            }
        }
       

    }
    return memCache;
}
priority_queue<pair<int, string>> LeaderBoard::getTopPlayersWeek(){
    priority_queue<pair<int, string>>   memCache;
    int currDay  = stoi(dateHandler::getDateHandler()[2]);
    
    for(auto historyItem :history){
        History hist = historyItem;
        // if item belongs to the same month
        int date_diff = abs(stoi(hist.getdateDay())-currDay);
        if (date_diff<=7){
            int priority_ = -1 * stoi(hist.getScore());
            string playerDetail = hist.getName() + " " +hist.getdateDay() + "/" + hist.getdateMonth() + "/" + hist.getdateYear();
            memCache.push(make_pair(priority_, playerDetail));

            if (memCache.size()>10){
                memCache.pop();
            }
        }
       

    }
    return memCache;

    
}

priority_queue<pair<int, string>> LeaderBoard::getTopPlayersToday(){
    priority_queue<pair<int, string>>   memCache;
    string currDay  = dateHandler::getDateHandler()[2];
    
    for(auto historyItem :history){
        History hist = historyItem;
        // if item belongs to the same month
       
        if (currDay== hist.getdateDay()){
            int priority_ = -1 * stoi(hist.getScore());
            string playerDetail = hist.getName() + " " +hist.getdateDay() + "/" + hist.getdateMonth() + "/" + hist.getdateYear();
            memCache.push(make_pair(priority_, playerDetail));

            if (memCache.size()>10){
                memCache.pop();
            }
        }
       

    }
    return memCache;

    
}


void  LeaderBoard::displayLeaderBoard(){
    cout <<"        Top best players ever"<< endl;
    cout << "       ------------------- "<<endl;
    
    char option;
    priority_queue<pair<int, string>> scorePriority;
    option = requestLeaderBoardCategory();
    switch (option) {
        case 'O':
            scorePriority = getTopPlayersOverall();
            break;
        case 'M':
            scorePriority = getTopPlayersMonth();
            break;
        case 'W':
            scorePriority = getTopPlayersWeek();
            break;
        case 'T':
            scorePriority = getTopPlayersToday();
            break;
        default:
            cout << "       Nothing to see here"<<endl;
            break;
    }
    
    while(!scorePriority.empty()){
        cout << " "<< endl;
        pair<int,string> historyItem = scorePriority.top();
        cout << -1 * historyItem.first << "/ 10 name: "<< historyItem.second<< endl;
        cout << " "<< endl;
        scorePriority.pop();
    }
    cout << "       ------------------- "<<endl;
    cout << ""<<endl;
}


char LeaderBoard::requestLeaderBoardCategory(){
    cout << " So you wanna view the leaderboard to feel deppressed yh? "<< endl;
    cout <<" O for overall best, M for leader this month, T for leaders of the day ,and W for leaders in the week and anything else to quit"<< endl;
    char option;
    cin >> option;
    option = toupper(option);
    return option;
}
