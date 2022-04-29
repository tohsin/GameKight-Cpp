//
//  history.cpp
//  gameKnightB
//
//  Created by Oluwatosin  Oseni on 27/04/2022.
//

#include "history.hpp"

void History::setName(string name_){
    name = name_;
};
void History::setScore(string score_){
    score = score_;
};

void History::setdateDay(string dateDay_){
    dateDay = dateDay_;
}
void History::setdateMonth(string dateMonth_){
    dateMonth = dateMonth_;
}
void History::setdateYear(string dateYear_){
    dateYear = dateYear_;
}

string History::getName(){
    return name;
}
string History::getScore(){
    return score;
};
string History::getdateYear(){
    return dateYear;
}

string History::getdateDay(){
    return dateDay;
}

string History::getdateMonth(){
    return dateMonth;
    
}
