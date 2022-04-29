//
//  quest.hpp
//  gameKnightB
//
//  Created by Oluwatosin  Oseni on 27/04/2022.
//

#ifndef quest_hpp
#define quest_hpp

#include <stdio.h>
#include <string>
//#include <boost/archive/xml_oarchive.hpp>
//#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/nvp.hpp>
using namespace boost::archive; // namespace for archives
using namespace boost::serialization; // namespace for make_nvp
using namespace std;


class Question{
public:
    void setQuestion(string q);
    void setAns(string a);
    string getQuestion();
    string getAns();
   

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& archive, const unsigned int version){
        using boost::serialization::make_nvp;
        archive & make_nvp("question", question);
        archive & make_nvp("ans", ans);
    }
           

    
    string question;
    string ans;
};

#endif /* quest_hpp */
