# Text-Based Games

### Compilation and execution instructions
First, user have to download all the files. Then, user has to complie the game by typing "make adventure". Then type "./adventure". All of the compilations and executions have to be in X2Go (CS server).

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

Credit: 
English words: https://github.com/openethereum/wordlist/blob/master/res/wordlist.txt

Note: 
This is my course project.
