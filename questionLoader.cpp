//
//  questionLoader.cpp
//  gameKnightB
//
//  Created by Oluwatosin  Oseni on 26/04/2022.
//

#include "questionLoader.hpp"

#include <boost/serialization/vector.hpp>


void QuestionLoader::addToMem(Question question){
    mem.push_back(question);
};
vector<Question> QuestionLoader::getMem(){
    return mem;
};

void QuestionLoader::loadQuestionsFromTxt(){
        fstream newfile;
        newfile.open("/Users/elena/Downloads/clues.txt",ios::in); //open a file to perform read operation using file object
        if (newfile.is_open()){   //checking whether the file is open
            string tp;
            bool isQuestion = true;
            Question ques;
            while(getline(newfile, tp)){ //read data from file object and put it into string.
                tp.erase(remove(tp.begin(), tp.end(), '\r'), tp.end());

                if (isQuestion){
                    ques.setQuestion(tp);
                    isQuestion = false;
                }else{
                    ques.setAns(tp);
                    addToMem(ques);
//                    mem.push_back(ques);
                    Question ques;
                    isQuestion = true;

                    //we have found a question so we add it
                }
//                cout << tp << "\n"; //print the data of the string
            }
            newfile.close(); //close the file object.
        }
};

vector<Question> QuestionLoader:: loadQuestionsFromXML(){
//    ifstream fin("questions.xml");
//    xml_iarchive ia(fin);
    vector<Question> quest;
//    ia >> make_nvp("questions", quest);
//    fin.close();
    return  quest;

};

void QuestionLoader :: saveFromTxtToXml(){
//    QuestionLoader questionLoader;
//    loadQuestionsFromTxt();
//    vector<Question> questions = getMem();
//    
//    ofstream fout("questions.xml");
//    xml_oarchive oa(fout);
//    oa << make_nvp("questions", questions);
//    fout.close();
    

}
