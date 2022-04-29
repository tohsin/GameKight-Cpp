//
//  datehandle.cpp
//  gameKnightB
//
//  Created by Oluwatosin  Oseni on 28/04/2022.
//

#include "datehandle.hpp"

vector<string> dateHandler::getDateHandler(){
    std::time_t t = std::time(0);   // get time now
    tm* now = std::localtime(&t);
    vector<string> date;
    date.push_back(to_string(now->tm_year + 1900));
    date.push_back(to_string(now->tm_mon + 1));
    date.push_back(to_string(now->tm_mday));
    return date;
}
