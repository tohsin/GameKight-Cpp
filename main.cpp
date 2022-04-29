#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;
class Question{
public:
    string question;
    string ans;

};

class QuestionGenetator{
    vector<Question> mem;

    void loadQuestion(){
        fstream newfile;
        newfile.open("clues.txt",ios::in); //open a file to perform read operation using file object
        if (newfile.is_open()){   //checking whether the file is open
            string tp;
            bool isQuestion = true;
            while(getline(newfile, tp)){ //read data from file object and put it into string.
                if isQuestion{
                    
                }
                cout << tp << "\n"; //print the data of the string
                
            }
            newfile.close(); //close the file object.
        }
    }
}

int main() {
   
    return 0;
   

}