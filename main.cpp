#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <vector>
#include "g1_main.h"
#include "g2_main.h"
using namespace std;

// i will always close the close if not in use
int main()
{
    // login
    vector<int> score_v;
    string user_input, username, filename, past_user, game_mode;
    int total, score, p_total, point;
    bool status = false;
    total = score = 0;
    p_total = 0;
    cout << "********** Welcome to THE ADVENTURE GAME **********" << endl;
    cout << "Please login or register (Press: Login / Register)" << endl;
    cin >> user_input;
    while (true){
        if (user_input == "Login"){
            cout << "(Login) What is your username? (No space is allowed)" << endl;
            cin >> username;
            // check if the user has record or registered before
            ifstream all_user_login ("all_users.txt", ios::app);
            status = true;
            while (all_user_login >> past_user){
                if (past_user == username){
                    status = false;
                    break;
                }
            }
            if (status == true) {
                cout << "No such record. Please enter \"Register\" or \"Login\" to continue." << endl;
            }
            // have record
            else{
                filename = username + ".txt";
                ifstream my_file_p (filename.c_str());
                my_file_p >> total;
                cout << "Your past total score is " << total << endl;
                p_total = total;
                total = 0;
                my_file_p.close();
                break;
            }
        }

        //register
        else if (user_input == "Register") {
            status = false;
            while (status == false){
                cout << "(Register) What is your username? (No space is allowed)" << endl;
                cin >> username;
                // check if username is duplicated
                ifstream all_user ("all_users.txt", ios::app);
                status = true;
                while (all_user >> past_user){
                    if (past_user == username){
                        cout << "Please use a new username." << endl;
                        status = false;
                        break;
                    }
                }
                all_user.close();
            }
            // create a blank file for this user
            ofstream all_user_add ("all_users.txt", ios::app);
            all_user_add << username << endl;
            all_user_add.close();
            filename = username + ".txt";
            ofstream my_file_new (filename.c_str());
            my_file_new<<total<<endl;
            my_file_new.close();
            break;
        }
        else{
            cout << "Wrong input, please try again." << endl;
        }
        cin >> user_input;
    }

    cout << "In the 1st level, the player will be playing Black Jack." << endl;
	cout << "In the 2nd level, the player will be playing Scramble." << endl;
    cout << "Please choose \"1\" for game 1, \"2\" for game 2, \"Check\" for score checking and \"Quit\" for quitting this game." << endl;
    cin >> game_mode;
    while (game_mode != "Quit"){
        // game 1 - black jack
        if (game_mode == "1"){
            point = g1_main();
            score_v.push_back(point);
        }
        // game 2 - scramble
        else if (game_mode == "2"){
            point = g2_main();
            score_v.push_back(point);
        }
        // check score
        else if (game_mode == "Check") {
            total = 0;
            for (int i=0;i<score_v.size();i++){
                total = total + score_v[i];
            }
            cout << "Your total score is " << total << endl;
            if (p_total < total){
                ofstream my_file_new_score (filename.c_str());
                my_file_new_score << total<<endl;
            }
        }
        else{
            cout << "Wrong input, please try again." << endl;
        }
        cout << "Please choose \"1\" for game 1, \"2\" for game 2, \"Check\" for score checking and \"Quit\" for quitting this game." << endl;
        cin >> game_mode;
    }
    cout << "Bye! See you next time in this adventure!" << endl;
    return 0;
}
