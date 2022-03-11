# Text-Based Games

### Compilation and execution instructions
First, user have to download all the files. Then, user has to complie the game by typing "make adventure". Then type "./adventure". All of the compilations and executions have to be in X2Go (CS server).
Link for demonstration: https://drive.google.com/file/d/1rjVBJNk3E8FcVwl3HImbV0I-IoIEV9Nu/view?usp=sharing

### Description of the game:
This is an adventure game with 2 games to play. All players will first need to log in to their accounts to retrieve the game status. If there is no such user record, the user needs to register that username. All username is unique. Afterwards, player can choose to play any of the 2 games or to see the total score. For details of each game, please refer to the rules listed below.

##### 1. Black Jack
This game involves risk management. The player plays with the computer, namely dealer. The cards are randomly generated, from 1 to 13, meaning from A to K. (1 stands for A, 11 stands for J, 12 stands for Q, 13 stands for K) Both dealer and player will receive 1 card that is open to everyone to see and 1 card that is private to the player. Then the dealer and players can take turn to request for extra cards if they want and the card is public to all. The player simply types "Y" or "N" to indicate his/her preference. Based on the rules in offical games, the dealer must request for an extra card if the sum of his cards is less than 17. Player is allowed to take cards even he/she did not take an card in the previous round, but the maximum cards you can take is 5. But if the dealer and the player both do not request for extra card in that round, all cards will be shown to the public to calculate the sum of values of the cards. Number cards count as their number, the jack, queen, and king count as 10, ace card can be counted as 1 or 11. Points rewarded are the sum of your cards if you win, else no points will be rewarded. To win this game, you can to meet 1 out of these 3 criteria. 
1. The sum of both player and dealer are less than 21 and your sum is higher than the dealer. 
2. Your sum is 21. 
3. The sum of dealer is larger than 21, while your sum is not.

##### 2. Scramble
This is an educational game that requires player to input a wide range of vocabularies. The game starts by giving out random-generated letter and number. The rule is to enter a word that fits the length given and starts with the given alphabet. 1 point will be awarded for each correct answer. The game will continue by changing the letter and number everytime. The player loses the game if he/she fails to enter a correct input or a word that is not included in a 7777-word-database.

### Assumptions:
1. Our system can handle invlaid inputs.
2. The points are passed to the database file, it will be updated if the user breaks the record.
3. For users that choose "login", we assume there is a file (e.g. tom.txt) and this username (e.g. tom) is inside the all_user.txt.
4. The user need to download all the files above in order to run the game smoothly.

### Setting:
In this adventure game, it requires additional libraries. 
- We make use of vector to store all the points the user got, various input if he/she plays for more than once
- We make use of random to generate random sets of numbers and letters. As game 1 requires a large number of random numbers within a short period of time, making use of "random" is better.
- We also include string library for storing username, user's input and more.
- We also include fstream for getting username in main, reading words for game 3 and more. It is better to store words in a textfile for easier change. 

### A list of features that you have implemented: 
1.  There is a login system which players can register themselves.
2.  Random letters and number are generated in both game to fulfill coding requirment 1.
3.  An option 'Check result' - the result the player obtained in each game will be store into the a text file named under the player's username. (coding requiremnt 4)
4.  We used a text file to store all the scores the player obtained. In particular, we used vectors to store the points the player obtained in game 2, which is supported by    coding requirement to fulfill coding requirement 3.
5.  In both game, if the score of the player is larger than the previous record, the scores will be updated.
6.  A few files are used to ensure the development of the main game to fulfill coding requirement 5.

### Code requirement:
1. Generation of random game sets or events
- We make use of the library (random) to generate vlaues.
- In game 1, the values of cards are randomly generated. 
- In game 2, the number and letter are randomly generated. To further increase the number of game sets, we make use of online English word list to increase the number of correct answers.

2. Data structures for storing game status
- We used a vector, which is a one-dimensional data structure to store the data in our game.

3. Dynamic memory management
- We use vector to store correct answers of game 2, and it will be cleared after one round. 

4. File input/output (e.g., for loading/saving game status)
- There is 1 textfile for all username and we will input username after one registered, then the points gained by the user will be stored in the textfile.
- For loading past game status, past total score is showed for login user, but not register user.
- All the correct words for game 2.

5. Program codes in multiple files
- Overall: main.cpp / all_user.txt / Makefile
- Game 1: g1_main.cpp / g1_main.h
- Game 2: g2_main.cpp / g2_main.h / g2_word.txt

6. Proper indentation and naming styles
- We have proper indentation by using vs code to help us with the spacing. For the naming styles, all the variables are easy to understand by using commonly used English words or short forms with explanation.

7. In-code documentation
- Comments on description of code and a README.md

Credit: 
English words: https://github.com/openethereum/wordlist/blob/master/res/wordlist.txt
