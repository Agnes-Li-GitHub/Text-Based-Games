#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include <vector>
#include "g1_main.h"
using namespace std;

// calculate the sum of my cards, the input is the my_card arry or pc_card arry, output is the total sum of the cards
int g1_sum_cards(int card[]){
    int sum, a_count;
    sum = a_count = 0;
    for (int i=0;i<5;i++){
        // for J, Q, K cards
        if (card[i] == 11 || card[i] == 12 || card[i] == 13){
            sum += 10;
        }
        // for ace card
        else if (card[i] == 1){
            a_count += 1;
        }
        // for normal numbers
        else{
            sum += card[i];
        }
    }

    // as player can only take at least 1 ace card as 11
    if (a_count != 0){
        // treat all as 1
        if ((21-sum < 11) || ((sum+10+a_count)>21)){
            sum += a_count;
        }
        // take one ace as 11
        else {
            sum += a_count + 10;
        }
    }
    return sum;
}

// this part is for generating random cards, inputs are the blank my_card and pc_card array, outputs are values of my_card and pc_card
int g1_random_cards(int my_card[], int pc_card[]){
    char pc_reply, my_reply;
    random_device randomDevice;
    cout << "Game starts!" << endl;
    pc_card[0] = randomDevice() % 13+1;
    cout << "Dealer's 1st card is ? " <<endl;
    pc_card[1] = randomDevice() % 13+1;
    cout << "Dealer's 2nd card is " << pc_card[1] << endl;
    my_card[0] = randomDevice() % 13+1;
    cout << "Your 1st card is " << my_card[0] << endl;
    my_card[1] = randomDevice() % 13+1;
    cout << "Your 2nd card is " << my_card[1] << endl;

    // max 5 cards is the rule, so they can only get 3 extra cards
    for (int round=2;round<5;round++){
        if (g1_sum_cards(pc_card)<17){
            pc_card[round] = randomDevice() % 13+1;
            cout << "Dealer is getting an extra card." << endl;
        }
        else{
            pc_reply = 'N';
            cout << "Dealer is not getting an extra card." << endl;
        }
        // print all the dealer cards, the ? stands for the face down card
        cout << "Dealer cards are: ? ";
        for (int i=1;i<5;i++){
            if (pc_card[i]==0){
                break;
            }
            else{
                cout << pc_card[i] << " ";
            }
        }
        cout << endl;

        cout << "Player, do you want an extra card? (Press: Y/N)" << endl;
        cin >> my_reply;
            if (my_reply == 'Y'){
                my_card[round] = randomDevice() % 13+1;
            }
            else {
                my_reply = 'N'; // useless
            }

            // print all the player cards,
            cout << "Player cards are: ";
            for (int i=0;i<5;i++){
                if (my_card[i]==0){
                    break;
                }
                else{
                    cout << my_card[i] << " ";
                }
            }
            cout << endl;

            // check sum if both is not getting extra cards
            if ((pc_reply == 'N')  && (my_reply == 'N')) {
                cout << "No one is gettig an extra card, so let's see the result!" << endl;
                cout << "Your cards are: ";
                for (int j=0;j<5;j++){
                    if (my_card[j]==0){
                        break;
                    }
                    else{
                        cout << my_card[j] << " ";
                    }
                }
                cout << endl;
                cout << "Dealer cards are: ";
                for (int j=0;j<5;j++){
                    if (pc_card[j]==0){
                        break;
                    }
                    else{
                        cout << pc_card[j] << " ";
                    }
                }
                cout << endl;
                return 0;
            }
        }
    return 0;
}

// this is the main function of the game, it will call functions, ask if the user wants to continue or not and input score to the user's file
// the inputs are the vector for storing user's data and filename
int g1_main(){
    cout<< "-----------------------------------------------" << endl;
    cout<< "*********Welcome to the Black Jack*********" << endl;
    cout<< "-----------------------------------------------" << endl;
    cout<< "Here are the rules:" << endl;
    cout<< "Each player will be given 2 cards, one is visible to others and one is not." << endl;
    cout<< "Number cards count as their number, the jack (11), queen (12), and king (13) count as 10, ace card can be counted as 1 or 11." << endl;
    cout<< "Your goal is to request for 1 cards per round until the sum off the cards is equal to 21." << endl;
    cout<< "You can choose to take cards or not in each round. But the maximum cards you can take is 5." << endl;
    cout<< "There are 2 ways for you to win the game. You either get 21 for the sum or if the sum of both player are smaller than 21, your sum must be greater than the dealer's one in order to win." << endl;
    cout<< "Are You Ready? (Press: Y/N)" << endl;
    string input;
    int me_sum, pc_sum;
    int my_card[5]={0};
    int pc_card[5]={0};
    cin >> input;
    if (input == "Y"){
        cout<< "Welcome to the world of Black Jack." << endl;
        g1_random_cards(my_card, pc_card);
        me_sum = g1_sum_cards(my_card);
        pc_sum = g1_sum_cards(pc_card);
        cout << "The sum of your cards is " << me_sum << endl;
        cout << "The sum of the dealer's cards is " << pc_sum << endl;
        if ((me_sum==21) || ((me_sum>=pc_sum)&&(pc_sum<=21)&&(me_sum<=21)) || (pc_sum>21) && (me_sum<21)){
            cout<< "Congratulations! You win the computer!" << endl;
            cout<< "You can move on to the second round or play again." << endl;
            return me_sum;
        }
        else {
            cout<< "Sorry to see you losing the game" << endl;
            return 0;
        }
    }
    else{
        cout<< "See you next time" << endl;
        return 0;
    }
}
