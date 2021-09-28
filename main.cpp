//                                              ********* Writer: Matt Hamilton *********
 //                                             ******** Class: CO SCI 140      ******** 
 //                                              ******* Professor: Luis Flores  *******
 //                                               ***** Programming Assignment 13 *****
 //                                                **** ========================  ****
 //                                                 **  *** *** *** *** *** *** **
 //
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Below I declared a class named Question. The class will contain all the data from the text file
class Question
{
private:
string trivia_question;  // contains questions from the file
string poss_answer[4]; // contains 4 strings with possible answers and only one will be correct
int correct_answers; // contains the correct answer
public:

Question(){}//default constractor 

//6 mutators func that set data for the private class mambers 
void set_question(string qst){ trivia_question = qst;}
void set_poss_answ1(string poss_ans_1){ poss_answer[0] = poss_ans_1;}
void set_poss_answ2(string poss_ans_2){ poss_answer[1] = poss_ans_2;}
void set_poss_answ3(string poss_ans_3){ poss_answer[2] = poss_ans_3;}
void set_poss_answ4(string poss_ans_4){ poss_answer[3] = poss_ans_4;}
void set_correct_numb(int correct_number){correct_answers = correct_number;}

//7 accessors that uses data from the private memebrs of the class 
string get_question(){return trivia_question;}
string get_answ1(){return poss_answer[0];}
string get_answ2(){return poss_answer[1];}
string get_answ3(){return poss_answer[2];}
string get_answ4(){return poss_answer[3];}
int get_corrt_numb() { return correct_answers;}
string get_corrt_answer() { return poss_answer[correct_answers-1];}


};

void QuestionsArray(Question[], int); // a prototype of a func that will set all the data from the file to the class
void displayTriviaQuestion(Question qst); // a prototype of a func that will display answers from the file
int main()
{
    fstream trivia_file {"trivia.txt"};

    if (!trivia_file){ //first of all I check if an error occurred while opening a file
    cout << "ERROR: Cannot open trivia file.\n";
    system("pause");}
    
    else{
    const int NUMBER_QUESTIONS = 10; //a constant that holds number of questions. We have aonly 10 questions
    int Player1_Points {0};//holds points for player 1
    int Player2_Points {0};//holds points for player 2
    
    Question questions[NUMBER_QUESTIONS];// create a class object that holds an array of data
    
    QuestionsArray(questions, NUMBER_QUESTIONS); // here I call func that passes the data and set all the data from the file to the class
    
    int num_of_questin {0}; // a variavle that I need for my while loop
    
    while ( num_of_questin < 10){
        
        int PlayersAnswer {0};
        
        cout <<"Question for PLAYER 1: "<< endl;
        cout <<"----------------------" << endl;
        displayTriviaQuestion(questions[num_of_questin]);// call the func that displays the pssible answers 
        cout << "Enter the correct answer: ";
        cin >> PlayersAnswer;
        
        //if answer is correct 
        if (PlayersAnswer == questions[num_of_questin].get_corrt_numb()){
            cout << "Correct!" << endl << endl;
            Player1_Points++;
        //if answer is not correct 
        }else{
            cout << "Sorry, that's incorrect. The correct answer is " << questions[num_of_questin].get_corrt_numb() <<
            ". " << questions[num_of_questin].get_corrt_answer() << endl << endl;
        }
        num_of_questin++; // next question
        
        
        // below I am doing the same process with Player one, but with the next question 
         cout <<"Question for PLAYER 2: "<< endl;
         cout <<"----------------------" << endl;
         displayTriviaQuestion(questions[num_of_questin]);
         cout << "Enter the correct answer: ";
         cin >> PlayersAnswer;
         
         if (PlayersAnswer == questions[num_of_questin].get_corrt_numb()){
            cout << "Correct!" << endl << endl;
            Player2_Points++;
        }else{
            cout << "Sorry, that's incorrect. The correct answer is " << questions[num_of_questin].get_corrt_numb() <<
            ". " << questions[num_of_questin].get_corrt_answer() << endl << endl;
        }
        num_of_questin++; 
        
    }
    
    cout << "Game over. Here are the points: " << endl;
    cout << "PLAYER 1: " << Player1_Points  << endl;
    cout << "PLAYER 2: " << Player2_Points  << endl << endl;
    
    //here i deremine the winner 
    if (Player1_Points > Player2_Points) {
        cout << "PLAYER 1 WINS " << endl; 
    }
    else if (Player1_Points < Player2_Points){
        cout << "PLAYER 2 WINS " << endl;
    }
    else{
        cout << "It's a tie!" << endl;
    }
    
} 
trivia_file.close();
system("pause");
	return 0;
}

void displayTriviaQuestion(Question qst){
    //I call get_answ function that pass data from the class and show the questions from the file
    cout << qst.get_question() << endl;
    cout << "ANSWERS: " << endl;
    cout << "1. " << qst.get_answ1() << endl;
    cout << "2. " << qst.get_answ2() << endl;
    cout << "3. " << qst.get_answ3() << endl;
    cout << "4. " << qst.get_answ4() << endl;
    
}

void QuestionsArray(Question qst[], int size){
    const int SIZE = 500; //ensure enough storage for data 
    char array [SIZE]; // create an array with characters
    fstream trivia;// read the file 
    int index = 0; // needs for my while loop
  
    trivia.open("trivia.txt", ios::in);
   
        trivia.getline(array, SIZE);
        
        //the loop terminates when the file reaches its end
        while(!trivia.eof() && index < size){
            
            qst[index].set_question(array);//pass question to the classs
            
            //pass possible answers to the class 
            trivia.getline(array, SIZE);
            qst[index].set_poss_answ1(array);
            
            trivia.getline(array, SIZE);
            qst[index].set_poss_answ2(array);
        
            trivia.getline(array, SIZE);
            qst[index].set_poss_answ3(array);
            
            trivia.getline(array, SIZE);
            qst[index].set_poss_answ4(array);
            
            trivia.getline(array, SIZE);//store the correct answer 
            qst[index].set_correct_numb(atoi(array));
            
            index++;
            
            trivia.getline(array, SIZE);
        
    }
    trivia.close();
}
