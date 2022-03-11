#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include "g2_main.h"
using namespace std;

// this is the main function of the game, the inputs are the status and point
// output are the status to see if he can continue to input words
char g2_mode(char status, int &point){
    int length;
    char letter;
    string user_ans, word;

    // open the file
    ifstream word_file ("g2_word.txt");
    if (word_file.fail()){
		cout << "Error in file opening!" << endl;
 		exit(1);}

    // to find min and max word length in the 7777-word-file
    int max = 0;
    int min = 100;
    while (word_file>>word){
        if (word.length()<min){
            min = word.length();
        }
        else if (word.length()>max){
            max = word.length();
        }
    }
    word_file.close();

    // create vectors to store all valid answers
    vector<string> correct;

    // add words to correct vector
    while (correct.empty()){
        random_device randomDevice;
        letter = 'a' + randomDevice() % 26; // a-z
        length = randomDevice() % (max-min+1)+min;
        ifstream word_file ("g2_word.txt");
        while (word_file>>word){
            if ((word[0] == letter) && (word.length() == length)){
                correct.push_back(word);
            }
        }
        word_file.close();
    }
    // now there is content is correct vector

 // this part is for easier playing
    cout << "correct answers for easier playing: " << endl;
    for (int i=0;i<correct.size();i++){
        cout << correct[i] << " ";
    }
    cout << endl;

    // check if input is within the vector
    cout << "The word should starts with letter " << letter << " with a length of " << length << endl;
    cout << "Your answer is: ";
    status = 'l';
    cin >> user_ans;
    for (int i=0;i < correct.size();i++) {
        if (user_ans == correct[i]) {
            point += 1;
            status = 'w';
            cout << "You are correct! 1 point is added! " << endl;
            cout << "Your total points in this game are " << point << endl;
            correct.clear();
            word_file.close();
        }
    }

    // no match, so player lose
    if (status == 'l'){
        status = 'l';
        cout << "Sorry, you lose the game." << endl;
        cout << "Your total points in this game are " << point << endl;
        word_file.close();
    }
    return status;
}

// this is the main() of game 2, it will call the above function to run the game, it will return points for calculation
int g2_main(){
    cout<< "-----------------------------------------------" << endl;
    cout<< "*********Welcome to Scramble*********" << endl;
    cout<< "-----------------------------------------------" << endl;
    cout<< "Here are the rules:" << endl;
    cout<< "The game starts by giving out random-generated letter (e.g. c) and number within the range of 3 to 10 (e.g. 5)." << endl;
    cout<< "You are required to enter a word that starts with the given letter in the length of the given number." << endl;
    cout<< "In this case, the answer can be China." << endl;
    cout<< "No worries, the letter and number will change everytime." << endl;
    cout<< "Are You Ready? (Press: Y/N)" << endl;
    char input, win_lose;
    int point = 0;
    win_lose = 'w';
    cin >> input;
    if (input == 'Y'){
      cout << "Game starts!" << endl;
    }
    else {
      cout<< "See you next time. " << endl;
      return 0;
    }

    while (win_lose=='w'){
        win_lose = g2_mode(win_lose, point);
    }
    return point;
}
