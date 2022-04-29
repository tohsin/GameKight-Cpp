//
//  quest.cpp
//  gameKnightB
//
//  Created by Oluwatosin  Oseni on 27/04/2022.
//

#include "quest.hpp"


void Question::setAns(string a){
    ans = a;
};
void Question::setQuestion(string q){
    question = q;
};

string Question::getAns(){
    return ans;
};

string Question::getQuestion(){
    return question;
};
