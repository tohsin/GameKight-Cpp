//
//  history.hpp
//  gameKnightB
//
//  Created by Oluwatosin  Oseni on 27/04/2022.
//

#ifndef history_hpp
#define history_hpp
#include <string>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/nvp.hpp>
using namespace boost::archive; // namespace for archives
using namespace boost::serialization; // namespace for make_nvp
using namespace std;

#include <stdio.h>
class History{
public:
    void setName(string name_);
    void setScore(string score_);
    void setdateDay(string dateDay_);
    void setdateMonth(string dateMonth_);
    void setdateYear(string dateYear_);
    
    string getName();
    string getScore();
    string getdateDay();
    string getdateMonth();
    string getdateYear();
   

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& archive, const unsigned int version){
        using boost::serialization::make_nvp;
        archive & make_nvp("name", name);
        archive & make_nvp("score", score);
        archive & make_nvp("date", dateDay);
        archive & make_nvp("date", dateMonth);
        archive & make_nvp("date", dateYear);
    }
           

    
    string name;
    string score;
    string dateDay;
    string dateMonth;
    string dateYear;
};
#endif /* history_hpp */
