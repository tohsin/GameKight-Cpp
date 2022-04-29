//
//  questionLoader.hpp
//  gameKnightB
//
//  Created by Oluwatosin  Oseni on 26/04/2022.
//

#ifndef questionLoader_hpp
#define questionLoader_hpp
#include "game.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>


class QuestionLoader{
private:
    vector<Question> mem;
    
public:
    void loadQuestionsFromTxt();
    void saveFromTxtToXml();
    vector<Question> loadQuestionsFromXML();
    void addToMem(Question question);
    vector<Question> getMem();
};






#endif /* questionLoader_hpp */
