////
////  main.cpp
////  gameNight
////
////  Created by Oluwatosin  Oseni on 09/04/2022.
////
//
//
//
//
//
//#include <iostream>
//#include <cmath>
//#include <string>
//#include <cstdlib>
//#include <ctime>
//// Command + Option + leftArrow to collapse the current block
////Command + Option + rightArrow to unfold the current block
//using namespace std;
//int main() {
//    srand(time(NULL));
//    cout <<"        DIMS SUMS "<<endl<<endl;
//    cout <<"        Question Generator " <<endl;
//    cout << "       ------------------- ";
//    cout <<endl<< "This a question generator for the Dim Sums Game from the series of Richard Osman's House of Games";
//    string playername;
//    cout <<endl << "Enter your name please : " ;
//    getline(cin,playername);
//    
//    cout<<endl<< "Welcome "<<playername<<endl<<endl<<" Assistance: If you want to accept press 'y' and if you want to refuse press 'n' ";
//    
//    
//    int i=1;
//    char letter;
//    
//    while (i==1){
//        cout <<endl <<endl<< playername<< " Do you want to generate a question ? ";
//        cin >>letter;
//        
//        if (letter=='y'|| letter=='Y'){
//            int question = rand()%10;
//            switch (question){
//            case 0:
//                cout<< endl<< "- Players in an ice hockey team" ;//6
//                cout <<endl<< "- Countries in australasia";//14
//                cout<<endl << "- Value of green ball in snooker";//3
//                cout <<endl<< "- Value of outer bull in darts";//25
//                cout <<endl << "Question : ? + ? = 17";
//                break;
//            case 1:
//                cout<< endl<< "- Number of pounds in a stone" ;//14
//                cout <<endl<< "- Legs on a scorpion";//8
//                cout<<endl << "- Fingers on a spder monkey's hand";//4
//                cout <<endl<< "- Winners jerseys in the Tour de France";//5
//                cout <<endl << "Question : ? + ? = 12";
//                break;
//            case 2:
//                cout<< endl<< "- Sides on a 50p coin" ;//7
//                cout <<endl<< "- Legal voting age in South Korea";//19
//                cout<<endl << "- Furlongs in a mile";//8
//
//                cout <<endl<< "- Number 1singles by the beattles";//17
//                cout <<endl << "Question : ? + ? = 24";
//                break;
//            case 3:
//                cout<< endl<< "- UK prime ministers this century" ;//5
//                cout <<endl<< "- Softmints in a standard packet";//13
//                cout<<endl << "- Moons of Uranus";//27
//                cout <<endl<< "- World cup finals Brazil have played in";//7
//                cout <<endl << "Question : ? + ? = 32";
//                break;
//            case 4:
//                cout<< endl<< "- Oceans on Earth" ;//5
//                cout <<endl<< "- Hands on a clock";//3
//                cout<<endl << "- Bits in a nibble";//4
//                cout <<endl<< "- UK modern pentathlon medals at Tokyo 2021";//2
//                cout <<endl << "Question : ? + ? = 6";
//                break;
//            case 5:
//                cout<< endl<< "- English hills above 3000ft" ;//6
//                cout <<endl<< "- Countries the Danube flows through";//10
//                cout<<endl << "- Actors to have played Dr Who";//13
//                cout <<endl<< "- Novels by Charles Dickens";//15
//                cout <<endl << "Question : ? + ? = 23";
//                break;
//            case 6:
//                cout<< endl<< "- Length of a basketball court in metres " ;//28
//                cout <<endl<< "- Gases on the periodic table";//11
//                cout<<endl << "- Episodes of the Sopranos";//86
//                cout <<endl<< "- Years between World War 1 and 2";//21
//                cout <<endl << "Question : ? + ? = 31";
//                break;
//            case 7:
//                cout<< endl<< "- Symphonies by Beethoven " ;//9
//                cout <<endl<< "- Cities in Luxembourg";//12
//                cout<<endl << "- UK Chancellor's house member";//11
//                cout <<endl<< "- Legal driving age in Zimbabwe";//16
//                cout <<endl << "Question : ? + ? = 21";
//                break;
//            case 8:
//                cout<< endl<< "- The answer to life, the Universe and Everything" ;//42
//                cout <<endl<< "- Teams to have played in the Premier League";//50
//                cout<<endl << "- UK bronze medals won at Tokyo Olympics";//45
//                cout <<endl<< "- UN member states in Asia";//49
//                cout <<endl << "Question : ? + ? = 87";
//                break;
//            case 9:
//                cout<< endl<< "- Mountains above 8000 metres in the world" ;//14
//                cout <<endl<< "- Longest Time name in Wales";//58
//                cout<<endl << "- Legal driving age in Zimbabwe";//16
//                cout <<endl<< "- Value of outer bull in darts";//25
//                cout <<endl << "Question : ? + ? = 30";
//            break;
//                
//        }
//            i=2;
//            while (i==2){
//                cout <<endl <<endl<<" Do you want to generate another question ? ";
//                cin >>letter;
//                if (letter=='y'|| letter=='Y'){
//                    int question = rand()%10;
//                    switch (question){
//                        case 0:
//                            cout<< endl<< "- Players in an ice hockey team" ;//6
//                            cout <<endl<< "- Countries in australasia";//14
//                            cout<<endl << "- Value of green ball in snooker";//3
//                            cout <<endl<< "- Value of outer bull in darts";//25
//                            cout <<endl << "Question : ? + ? = 17";
//                            break;
//                        case 1:
//                            cout<< endl<< "- Number of pounds in a stone" ;//14
//                            cout <<endl<< "- Legs on a scorpion";//8
//                            cout<<endl << "- Fingers on a spder monkey's hand";//4
//                            cout <<endl<< "- Winners jerseys in the Tour de France";//5
//                            cout <<endl << "Question : ? + ? = 12";
//                            break;
//                        case 2:
//                            cout<< endl<< "- Sides on a 50p coin" ;//7
//                            cout <<endl<< "- Legal voting age in South Korea";//19
//                            cout<<endl << "- Furlongs in a mile";//8
//                            cout <<endl<< "- Number 1singles by the beattles";//17
//                            cout <<endl << "Question : ? + ? = 24";
//                            break;
//                        case 3:
//                            cout<< endl<< "- UK prime ministers this century" ;//5
//                            cout <<endl<< "- Softmints in a standard packet";//13
//                            cout<<endl << "- Moons of Uranus";//27
//                            cout <<endl<< "- World cup finals Brazil have played in";//7
//                            cout <<endl << "Question : ? + ? = 32";
//                            break;
//                        case 4:
//                            cout<< endl<< "- Oceans on Earth" ;//5
//
//                            cout <<endl<< "- Hands on a clock";//3
//                            cout<<endl << "- Bits in a nibble";//4
//                            cout <<endl<< "- UK modern pentathlon medals at Tokyo 2021";//2
//                            cout <<endl << "Question : ? + ? = 6";
//                            break;
//                        case 5:
//                            cout<< endl<< "- English hills above 3000ft" ;//6
//                            cout <<endl<< "- Countries the Danube flows through";//10
//                            cout<<endl << "- Actors to have played Dr Who";//13
//                            cout <<endl<< "- Novels by Charles Dickens";//15
//                            cout <<endl << "Question : ? + ? = 23";
//                            break;
//                        case 6:
//                            cout<< endl<< "- Length of a basketball court in metres " ;//28
//                            cout <<endl<< "- Gases on the periodic table";//11
//                            cout<<endl << "- Episodes of the Sopranos";//86
//                            cout <<endl<< "- Years between World War 1 and 2";//21
//                            cout <<endl << "Question : ? + ? = 31";
//                            break;
//                        case 7:
//                            cout<< endl<< "- Symphonies by Beethoven " ;//9
//                            cout <<endl<< "- Cities in Luxembourg";//12
//                            cout<<endl << "- UK Chancellor's house member";//11
//                            cout <<endl<< "- Legal driving age in Zimbabwe";//16
//                            cout <<endl << "Question : ? + ? = 21";
//                            break;
//                        case 8:
//                            cout<< endl<< "- The answer to life, the Universe and Everything" ;//42
//                            cout <<endl<< "- Teams to have played in the Premier League";//50
//                            cout<<endl << "- UK bronze medals won at Tokyo Olympics";//45
//
//                            cout <<endl<< "- UN member states in Asia";//49
//                            cout <<endl << "Question : ? + ? = 87";
//                            break;
//                        case 9:
//                            cout<< endl<< "- Mountains above 8000 metres in the world" ;//14
//                            cout <<endl<< "- Longest Time name in Wales";//58
//                            cout<<endl << "- Legal driving age in Zimbabwe";//16
//                            cout <<endl<< "- Value of outer bull in darts";//25
//                            cout <<endl << "Question : ? + ? = 30";
//                            break;
//                    }
//                }else {
//                    i++;
//                }
//            }
//            
//        }
//        else{
//            i++;
//        };
//        
//    }
//    /*char startingletter;
//    cout <<endl <<endl <<"  Please "<<playername<<" press S and then Enter to
//    start the game!!!!"<<endl ;
//    cin >> startingletter; if (startingletter=='S'){
//    cout<< endl <<rand()%10; };*/
//    return 0;
//   
//
//}
