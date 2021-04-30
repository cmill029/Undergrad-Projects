#include <iostream>
#include <ctime>
#include "DataTypes.h"

using namespace std;

/*
* this program prints a 10*10 board with positions like below :
* â•”â•â•â•â•â•¦â•â•â•â•â•¦â•â•â•â•â•¦â•â•â•â•â•¦â•â•â•â•â•¦â•â•â•â•â•¦â•â•â•â•â•¦â•â•â•â•â•¦â•â•â•â•â•¦â•â•â•â•â•—
* â•‘100 â•‘ 99 â•‘ 98 â•‘ 97 â•‘ 96 â•‘ 95 â•‘ 94 â•‘ 93 â•‘ 92 â•‘ 91 â•‘
* â• â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•£
* â•‘ 81 â•‘ 82 â•‘ 83 â•‘ 84 â•‘ 85 â•‘ 86 â•‘ 87 â•‘ 88 â•‘ 89 â•‘ 90 â•‘
* â• â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•£
* â•‘ 80 â•‘ 79 â•‘ 78 â•‘ 77 â•‘ 76 â•‘ 75 â•‘ 74 â•‘ 73 â•‘ 72 â•‘ 71 â•‘
* â• â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•£
* â•‘ 61 â•‘ 62 â•‘ 63 â•‘ 64 â•‘ 65 â•‘ 66 â•‘ 67 â•‘ 68 â•‘ 69 â•‘ 70 â•‘
* â• â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•£
* â•‘ 60 â•‘ 59 â•‘ 58 â•‘ 57 â•‘ 56 â•‘ 55 â•‘ 54 â•‘ 53 â•‘ 52 â•‘ 51 â•‘
* â• â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•£
* â•‘ 41 â•‘ 42 â•‘ 43 â•‘ 44 â•‘ 45 â•‘ 46 â•‘ 47 â•‘ 48 â•‘ 49 â•‘ 50 â•‘
* â• â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•£
* â•‘ 40 â•‘ 39 â•‘ 38 â•‘ 37 â•‘ 36 â•‘ 35 â•‘ 34 â•‘ 33 â•‘ 32 â•‘ 31 â•‘
* â• â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•£
* â•‘ 21 â•‘ 22 â•‘ 23 â•‘ 24 â•‘ 25 â•‘ 26 â•‘ 27 â•‘ 28 â•‘ 29 â•‘ 30 â•‘
* â• â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•£
* â•‘ 20 â•‘ 19 â•‘ 18 â•‘ 17 â•‘ 16 â•‘ 15 â•‘ 14 â•‘ 13 â•‘ 12 â•‘ 11 â•‘
* â• â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•¬â•â•â•â•â•£
* â•‘  1 â•‘  2 â•‘  3 â•‘  4 â•‘  5 â•‘  6 â•‘  7 â•‘  8 â•‘  9 â•‘ 10 â•‘
* â•šâ•â•â•â•â•©â•â•â•â•â•©â•â•â•â•â•©â•â•â•â•â•©â•â•â•â•â•©â•â•â•â•â•©â•â•â•â•â•©â•â•â•â•â•©â•â•â•â•â•©â•â•â•â•â•
*
* Students can use this and build the snake and ladders game as specified in the project description doc
*
*/

void displayIntInChar(int *arr, int sizeofarr, bool newLineRequired);
int playerPos(Player player1, Player player2, int roll, bool pTurn);
int rollDice();
void setSnakesLadders(Snake *snakes, Ladder *ladders);
int sOrLHit(Player player1, Player player2, Snake snakes, Ladder ladders, bool pTurn);
void levelStatus(Board *gameBoard, Player player1, Player player2, Snake *snakes, Ladder *ladders);

int main()
{
    int topl[] = {201,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,187};
    int midl[] = {204,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,185};
    int bottoml[] = {200,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,188};
    int arr[10][10] = {{100,99,98,97,96,95,94,93,92,91},
                        {81,82,83,84,85,86,87,88,89,90},
                        {80,79,78,77,76,75,74,73,72,71},
                        {61,62,63,64,65,66,67,68,69,70},
                        {60,59,58,57,56,55,54,53,52,51},
                        {41,42,43,44,45,46,47,48,49,50},
                        {40,39,38,37,36,35,34,33,32,31},
                        {21,22,23,24,25,26,27,28,29,30},
                        {20,19,18,17,16,15,14,13,12,11},
                        {1,2,3,4,5,6,7,8,9,10}};
    int x,y;
    Player player1, player2;
    srand(time(0));
    player1.position = 0;
    player2.position = 0;
    int rollIn=0;
    bool pTurn = true ; //if pTurn is true it is player 1s turn false it is player 2s
    char t= 'X';
    char q= 'Y';
    int roll;
    Board gameBoard;
    Snake snakes;
    Ladder ladders;


    cout << "This is a 2 player game please enter the names of the players: " << endl;
    cout << "-> Please enter the name of Player 1: " << endl;
    cin >> player1.name;
    cout << "-> Please enter the name of Player 2: " << endl;
    cin >> player2.name;
    cout << "<----------------------------------------------------->" << endl;


    cout << "-> Player 1 P1 " << player1.name << ": " << t << endl;
    cout << "-> Player 2 P2 " << player2.name << ": " << q << endl;

    gameBoard.setLevel1((rand()%10)+1);
    gameBoard.setLevel2((rand()%10)+11);
    gameBoard.setLevel3((rand()%20)+21);
    gameBoard.setLevel4((rand()%30)+41);
    gameBoard.setLevel5((rand()%30)+71);
    gameBoard.setflag1(false);
    gameBoard.setflag2(false);
    gameBoard.setflag3(false);
    gameBoard.setflag4(false);
    gameBoard.setflag5(false);

    setSnakesLadders(&snakes, &ladders);





    while (player1.position !=100 || player2.position !=100){


        cout << "Level 1 loctaion: " <<gameBoard.getLevel1() << endl;
        cout << "Level 2 loctaion: " <<gameBoard.getLevel2() << endl;
        cout << "Level 3 loctaion: " <<gameBoard.getLevel3() << endl;
        cout << "Level 4 loctaion: " <<gameBoard.getLevel4() << endl;
        cout << "Level 5 loctaion: " <<gameBoard.getLevel5() << endl;

        levelStatus(&gameBoard, player1, player2, &snakes, &ladders);
        cout << "<---------- Display Snakes and Ladders Position ------------>" << endl;
        cout << "Snake 1: Start: " << snakes.getsnakeButt1() << " End: " << snakes.getsnakeHead1() << endl;
        cout << "Snake 2: Start: " << snakes.getsnakeButt2() << " End: " << snakes.getsnakeHead2() << endl;
        cout << "Snake 3: Start: " << snakes.getsnakeButt3() << " End: " << snakes.getsnakeHead3() << endl;
        cout << "Snake 4: Start: " << snakes.getsnakeButt4() << " End: " << snakes.getsnakeHead4() << endl;
        cout << "Snake 5: Start: " << snakes.getsnakeButt5() << " End: " << snakes.getsnakeHead5() << endl << endl;

        cout << "Ladder 1: Start: " << ladders.getladderBot1() << " End: " << ladders.getladderTop1() << endl;
        cout << "Ladder 2: Start: " << ladders.getladderBot2() << " End: " << ladders.getladderTop2() << endl;
        cout << "Ladder 3: Start: " << ladders.getladderBot3() << " End: " << ladders.getladderTop3() << endl;
        cout << "Ladder 4: Start: " << ladders.getladderBot4() << " End: " << ladders.getladderTop4() << endl;
        cout << "Ladder 5: Start: " << ladders.getladderBot5() << " End: " << ladders.getladderTop5() << endl;

        // to print top row
        displayIntInChar(topl,51,true);
        for(x=0;x<10;x++){
            for(y=0;y<10;y++){
                if(y==0){
                    cout<<char(186);
                }
                if(arr[x][y] < 10){
                    if (player2.position==arr[x][y]){
                        cout<<char(32)<<char(32)<<arr[x][y] << q; // prints 2 spaces, position, space
                    }
                    else if (player1.position == arr[x][y]){
                        cout<<char(32)<<char(32)<<arr[x][y] << t; // prints 2 spaces, position, space
                    }

                    else{
                    cout<<char(32)<<char(32)<<arr[x][y]<<char(32); // prints 2 spaces, position, space
                    }
                }else if(arr[x][y] < 100){
                    if (player2.position==arr[x][y]){
                        cout<<char(32)<<arr[x][y] << q; // prints 2 spaces, position, space
                    }
                    else if (player1.position == arr[x][y]){
                        cout<<char(32)<<arr[x][y] << t; // prints 2 spaces, position, space
                    }
                    else{
                        cout<<char(32)<<arr[x][y]<<char(32);// prints space position and space
                    }
                }else{
                    cout<<arr[x][y]<<char(32); // prints position and space
                }
                cout<<char(186);
            }
            cout<<endl;
            if(x<9){
                //print middle row
                displayIntInChar(midl,51,true);
            }
        }
        //prints bottom border
        displayIntInChar(bottoml, 51, true);

        if(pTurn == true)
        {

            cout << "Player 1: " << player1.name << " turn ->" << endl;
            cout << "Please press 1 to roll the dice: " << endl;
            cin >> rollIn;
            if (rollIn == 1)
            {
                player1.position = playerPos(player1, player2, roll, pTurn);
                cout << "P1 pos pre ladder " << player1.position << endl;
                player1.position = sOrLHit(player1,player2,snakes,ladders,pTurn);
                cout << "P1 pos post ladder " << player1.position << endl;
                rollIn=0;
            }
            else
            {
                return 0;
            }


        }

        else if(pTurn == false)
        {
            cout << "Player 2: " << player2.name << " turn ->" << endl;
            cout << "Please press 1 to roll the dice: " << endl;
            cin >> rollIn;

            if (rollIn == 1)
            {
                player2.position = playerPos(player1, player2, roll, pTurn);
                player2.position = sOrLHit(player1,player2,snakes,ladders,pTurn);
                rollIn=0;
            }
            else
            {
                return 2;
            }

        }


        if (player2.position >= 100 || player1.position >= 100)
        {
            break;
        }

        if (pTurn == true)
        {
            pTurn = false;
        }
        else if (pTurn == false)
        {
            pTurn = true;
        }
    }



    if (player2.position >= 100 || player1.position>= 100)
    {
        if(player2.position>=100)
        {
            cout << "Congratulations " << player2.name << " on winning!" << endl;
        }

        else if(player1.position >= 100)
        {
            cout << "Congratulations " << player1.name << " on winning!" << endl;
        }
    }

    return 0;
}

void displayIntInChar(int *arr, int sizeofarr, bool newLineRequired){
    int aSize = sizeofarr;

    for(int i=0;i<aSize;i++){
        cout<<char(arr[i]);
    }
    if(newLineRequired){
        cout<<endl;
    }
}

int rollDice()
{
    int roll = (rand()%6)+1;
    return roll;
}

int playerPos(Player player1, Player player2, int roll, bool pTurn)
{
    roll = rollDice();
    cout << "Your roll was: " << roll << endl;
    if (pTurn)
    {
        player1.position = player1.position + roll;
        return player1.position;
    }

    else if(!pTurn)
    {
        player2.position = player2.position + roll;
        return player2.position;
    }
}

 int sOrLHit(Player player1, Player player2, Snake snakes, Ladder ladders, bool pTurn)
    {
        if(pTurn)
        {
            if(player1.position== snakes.getsnakeHead1())
            {
                 player1.position = snakes.getsnakeButt1();
            }
            else if(player1.position== snakes.getsnakeHead2())
            {
                player1.position = snakes.getsnakeButt2();
            }

            else if (player1.position == snakes.getsnakeHead3())
            {
                player1.position = snakes.getsnakeButt3();
            }
            else if(player1.position== snakes.getsnakeHead4())
            {
                player1.position = snakes.getsnakeButt4();
            }
            else if(player1.position == snakes.getsnakeHead5())
            {
                player1.position = snakes.getsnakeButt5();
            }
            else if( player1.position== ladders.getladderBot1())
            {
                player1.position= ladders.getladderTop1();
            }
            else if(player1.position==ladders.getladderBot2())
            {
                player1.position= ladders.getladderTop2();
            }
            else if(player1.position== ladders.getladderBot3())
            {
                player1.position= ladders.getladderTop3();
            }
            else if (player1.position== ladders.getladderBot4())
            {
                player1.position= ladders.getladderTop4();
            }
            else if (player1.position== ladders.getladderBot5())
            {
                player1.position= ladders.getladderTop5();
            }
            return player1.position;
        }

        else if(!pTurn)
        {
            if(player2.position== snakes.getsnakeHead1())
            {
                 player2.position = snakes.getsnakeButt1();
            }
            else if(player1.position== snakes.getsnakeHead2())
            {
                player2.position = snakes.getsnakeButt2();
            }

            else if (player2.position == snakes.getsnakeHead3())
            {
                player2.position = snakes.getsnakeButt3();
            }
            else if(player2.position== snakes.getsnakeHead4())
            {
                player2.position = snakes.getsnakeButt4();
            }
            else if(player2.position == snakes.getsnakeHead5())
            {
                player2.position = snakes.getsnakeButt5();
            }
            else if( player2.position== ladders.getladderBot1())
            {
                player1.position= ladders.getladderTop1();
            }
            else if(player2.position==ladders.getladderBot2())
            {
                player1.position= ladders.getladderTop2();
            }
            else if(player2.position== ladders.getladderBot3())
            {
                player2.position= ladders.getladderTop3();
            }
            else if (player2.position== ladders.getladderBot4())
            {
                player2.position= ladders.getladderTop4();
            }
            else if (player2.position== ladders.getladderBot5())
            {
                player2.position= ladders.getladderTop5();
            }
            return player2.position;
        }
    }


void levelStatus(Board *gameBoard, Player player1, Player player2, Snake *snakes, Ladder *ladders)
{
    string status1, status2, status3, status4, status5;
    int lev1, lev2, lev3, lev4, lev5;
    lev1 = gameBoard->getLevel1();
    lev2 = gameBoard->getLevel2();
    lev3 = gameBoard->getLevel3();
    lev4 = gameBoard->getLevel4();
    lev5 = gameBoard->getLevel5();
    if(player1.position < lev1 && player2.position < lev1)
    {
        status1 = "Not Crossed";
    }

    else
    {
        status1= "Crossed";
        if (!gameBoard->getflag1())
        {
            setSnakesLadders(snakes, ladders);
        }
        gameBoard->setflag1(true);
    }

    if(player1.position >= lev2 || player2.position >= lev2)
    {
        status2 = "Crossed";
        if (!gameBoard->getflag2())
        {
            setSnakesLadders(snakes, ladders);
        }
        gameBoard->setflag2(true);
    }

    else
    {
        status2 = "Not Crossed";
    }

    if (status2 == "Crossed")
    {
        status1= "Not Crossed";
    }

    if(player1.position >= lev3 || player2.position >= lev3)
    {
        status3 = "Crossed";
        if (!gameBoard->getflag3())
        {
            setSnakesLadders(snakes, ladders);
        }
        gameBoard->setflag3(true);
    }

    else
    {
        status3 = "Not Crossed";
    }

    if (status3 == "Crossed")
    {
        status2= "Not Crossed";
    }

    if(player1.position >= lev4 || player2.position >= lev4)
    {
        status4 = "Crossed";
        if (!gameBoard->getflag4())
        {
            setSnakesLadders(snakes, ladders);
        }
        gameBoard->setflag4(true);
    }

    else
    {
        status4 = "Not Crossed";
    }

    if(status4 == "Crossed")
    {
        status3= "Not Crossed";
    }

    if(player1.position >= lev5 || player2.position >= lev5)
    {
        status5 = "Crossed";
        if (!gameBoard->getflag5())
        {
            setSnakesLadders(snakes, ladders);
        }
        gameBoard->setflag5(true);
    }

    else
    {
        status5 = "Not Crossed";
    }

    if(status5 == "Crossed")
    {
        status4 = "Not Crossed";
    }
    cout << "<-- Level Status -->" << endl;
    cout << "Level 1: " << status1 << endl;
    cout << "Level 2: " << status2 << endl;
    cout << "Level 3: " << status3 << endl;
    cout << "Level 4: " << status4 << endl;
    cout << "Level 5: " << status5 << endl;
}

void setSnakesLadders(Snake *snakes, Ladder *ladders)
{

    snakes->setsnakeHead1((rand()%99)+1);
    snakes->setsnakeButt1((rand()%(snakes->getsnakeHead1()-1)+1));
    snakes->setsnakeHead2((rand()%99)+1);
    snakes->setsnakeButt2((rand()%(snakes->getsnakeHead2()-1)+1));
    snakes->setsnakeHead3((rand()%99)+1);
    snakes->setsnakeButt3((rand()%(snakes->getsnakeHead3()-1)+1));
    snakes->setsnakeHead4((rand()%99)+1);
    snakes->setsnakeButt4((rand()%(snakes->getsnakeHead4()-1)+1));
    snakes->setsnakeHead5((rand()%99)+1);
    snakes->setsnakeButt5((rand()%(snakes->getsnakeHead5()-1)+1));
    while(snakes->getsnakeHead2()== snakes->getsnakeButt1() || snakes->getsnakeHead2()== snakes->getsnakeHead1())
    {
        snakes->setsnakeHead2((rand()%99)+1);
    }
    while(snakes->getsnakeButt2()== snakes->getsnakeButt1() || snakes->getsnakeButt2()== snakes->getsnakeHead1())
    {
        snakes->setsnakeButt2((rand()%(snakes->getsnakeHead2()-1)+1));
    }
    while(snakes->getsnakeHead3()== snakes->getsnakeButt1() || snakes->getsnakeHead3()== snakes->getsnakeHead1() || snakes->getsnakeHead3()== snakes->getsnakeButt2() || snakes->getsnakeHead3()== snakes->getsnakeHead2())
    {
        snakes->setsnakeHead3((rand()%99)+1);
    }
    while(snakes->getsnakeButt3()== snakes->getsnakeButt1() || snakes->getsnakeButt3()== snakes->getsnakeHead1() || snakes->getsnakeButt3()== snakes->getsnakeButt2() || snakes->getsnakeButt3()== snakes->getsnakeHead2())
    {
        snakes->setsnakeButt3((rand()%(snakes->getsnakeHead3()-1)+1));
    }
    while(snakes->getsnakeHead4()== snakes->getsnakeButt1() || snakes->getsnakeHead4()== snakes->getsnakeHead1() || snakes->getsnakeHead4()== snakes->getsnakeButt2()
          || snakes->getsnakeHead4()== snakes->getsnakeHead2() || snakes->getsnakeHead4()== snakes->getsnakeButt3() || snakes->getsnakeHead4()== snakes->getsnakeHead3())
    {
        snakes->setsnakeHead4((rand()%99)+1);
    }
    while(snakes->getsnakeButt4()== snakes->getsnakeButt1() || snakes->getsnakeButt4()== snakes->getsnakeHead1() || snakes->getsnakeButt4()== snakes->getsnakeButt2()
          || snakes->getsnakeButt4()== snakes->getsnakeHead2() || snakes->getsnakeButt4()== snakes->getsnakeButt3() || snakes->getsnakeButt4()== snakes->getsnakeHead3())
    {
        snakes->setsnakeButt4((rand()%(snakes->getsnakeHead4()-1)+1));
    }
    while(snakes->getsnakeHead5()== snakes->getsnakeButt1() || snakes->getsnakeHead5()== snakes->getsnakeHead1() || snakes->getsnakeHead5()== snakes->getsnakeButt2()
          || snakes->getsnakeHead5()== snakes->getsnakeHead2() || snakes->getsnakeHead5()== snakes->getsnakeButt3() || snakes->getsnakeHead5()== snakes->getsnakeHead3()
          || snakes->getsnakeHead5()== snakes->getsnakeButt4() || snakes->getsnakeHead5()== snakes->getsnakeHead4())
    {
        snakes->setsnakeHead5((rand()%99)+1);
    }
    while(snakes->getsnakeButt5()== snakes->getsnakeButt1() || snakes->getsnakeButt5()== snakes->getsnakeHead1() || snakes->getsnakeButt5()== snakes->getsnakeButt2()
          || snakes->getsnakeButt5()== snakes->getsnakeHead2() || snakes->getsnakeButt5()== snakes->getsnakeButt3() || snakes->getsnakeButt5()== snakes->getsnakeHead3()
          || snakes->getsnakeButt5()== snakes->getsnakeButt4() || snakes->getsnakeButt5()== snakes->getsnakeHead4())
    {
        snakes->setsnakeButt5((rand()%(snakes->getsnakeHead5()-1)+1));
    }


    ladders->setladderTop1((rand()%99)+1);
    ladders->setladderBot1((rand()%(ladders->getladderTop1()-1)+1));
    ladders->setladderTop2((rand()%99)+1);
    ladders->setladderBot2((rand()%(ladders->getladderTop2()-1)+1));
    ladders->setladderTop3((rand()%99)+1);
    ladders->setladderBot3((rand()%(ladders->getladderTop3()-1)+1));
    ladders->setladderTop4((rand()%99)+1);
    ladders->setladderBot4((rand()%(ladders->getladderTop4()-1)+1));
    ladders->setladderTop5((rand()%99)+1);
    ladders->setladderBot5((rand()%(ladders->getladderTop5()-1)+1));
    while(ladders->getladderTop1()== snakes->getsnakeButt1() || ladders->getladderTop1()== snakes->getsnakeHead1() || ladders->getladderTop1()== snakes->getsnakeButt2()
          || ladders->getladderTop1()== snakes->getsnakeHead2() || ladders->getladderTop1()== snakes->getsnakeButt3() || ladders->getladderTop1()== snakes->getsnakeHead3()
          || ladders->getladderTop1()== snakes->getsnakeButt4() || ladders->getladderTop1()== snakes->getsnakeHead4() || ladders->getladderTop1()== snakes->getsnakeHead5()
          || ladders->getladderTop1()== snakes->getsnakeButt5())
    {
        ladders->setladderTop1((rand()%99)+1);
    }
    while(ladders->getladderBot1()== snakes->getsnakeButt1() || ladders->getladderBot1()== snakes->getsnakeHead1() || ladders->getladderBot1()== snakes->getsnakeButt2()
          || ladders->getladderBot1()== snakes->getsnakeHead2() || ladders->getladderBot1()== snakes->getsnakeButt3() || ladders->getladderBot1()== snakes->getsnakeHead3()
          || ladders->getladderBot1()== snakes->getsnakeButt4() || ladders->getladderBot1()== snakes->getsnakeHead4() || ladders->getladderBot1()== snakes->getsnakeHead5()
          || ladders->getladderBot1()== snakes->getsnakeButt5())
    {
        ladders->setladderBot1((rand()%(ladders->getladderTop1()-1)+1));
    }

    while(ladders->getladderTop2()== snakes->getsnakeButt1() || ladders->getladderTop2()== snakes->getsnakeHead1() || ladders->getladderTop2()== snakes->getsnakeButt2()
          || ladders->getladderTop2()== snakes->getsnakeHead2() || ladders->getladderTop2()== snakes->getsnakeButt3() || ladders->getladderTop2()== snakes->getsnakeHead3()
          || ladders->getladderTop2()== snakes->getsnakeButt4() || ladders->getladderTop2()== snakes->getsnakeHead4() || ladders->getladderTop2()== ladders->getladderTop1()
          || ladders->getladderTop2()== ladders->getladderBot1() || ladders->getladderTop2()== snakes->getsnakeHead5()
          || ladders->getladderTop2()== snakes->getsnakeButt5())
    {
        ladders->setladderTop2((rand()%99)+1);
    }
    while(ladders->getladderBot2()== snakes->getsnakeButt1() || ladders->getladderBot2()== snakes->getsnakeHead1() || ladders->getladderBot2()== snakes->getsnakeButt2()
          || ladders->getladderBot2()== snakes->getsnakeHead2() || ladders->getladderBot2()== snakes->getsnakeButt3() || ladders->getladderBot2()== snakes->getsnakeHead3()
          || ladders->getladderBot2()== snakes->getsnakeButt4() || ladders->getladderBot2()== snakes->getsnakeHead4() || ladders->getladderBot2()== ladders->getladderTop1()
          || ladders->getladderBot2()== ladders->getladderBot1() || ladders->getladderBot2()== snakes->getsnakeHead5()
          || ladders->getladderBot2()== snakes->getsnakeButt5())
    {
        ladders->setladderBot2((rand()%(ladders->getladderTop2()-1)+1));
    }
    while(ladders->getladderTop3()== snakes->getsnakeButt1() || ladders->getladderTop3()== snakes->getsnakeHead1() || ladders->getladderTop3()== snakes->getsnakeButt2()
          || ladders->getladderTop3()== snakes->getsnakeHead2() || ladders->getladderTop3()== snakes->getsnakeButt3() || ladders->getladderTop3()== snakes->getsnakeHead3()
          || ladders->getladderTop3()== snakes->getsnakeButt4() || ladders->getladderTop3()== snakes->getsnakeHead4() || ladders->getladderTop3()== ladders->getladderTop1()
          || ladders->getladderTop3()== ladders->getladderBot1()|| ladders->getladderTop3()== ladders->getladderBot2() || ladders->getladderTop3()== ladders->getladderTop2()
          || ladders->getladderTop3()== snakes->getsnakeHead5() || ladders->getladderTop3()== snakes->getsnakeButt5())
    {
        ladders->setladderTop3((rand()%99)+1);
    }
    while(ladders->getladderBot3()== snakes->getsnakeButt1() || ladders->getladderBot3()== snakes->getsnakeHead1() || ladders->getladderBot3()== snakes->getsnakeButt2()
          || ladders->getladderBot3()== snakes->getsnakeHead2() || ladders->getladderBot3()== snakes->getsnakeButt3() || ladders->getladderBot3()== snakes->getsnakeHead3()
          || ladders->getladderBot3()== snakes->getsnakeButt4() || ladders->getladderBot3()== snakes->getsnakeHead4() || ladders->getladderBot3()== ladders->getladderTop1()
          || ladders->getladderBot3()== ladders->getladderBot1() || ladders->getladderBot3()== ladders->getladderBot2() || ladders->getladderBot3()== ladders->getladderTop2()
          || ladders->getladderBot3()== snakes->getsnakeHead5() || ladders->getladderBot3()== snakes->getsnakeButt5())
    {
        ladders->setladderBot3((rand()%(ladders->getladderTop3()-1)+1));
    }
    while(ladders->getladderTop4()== snakes->getsnakeButt1() || ladders->getladderTop4()== snakes->getsnakeHead1() || ladders->getladderTop4()== snakes->getsnakeButt2()
          || ladders->getladderTop4()== snakes->getsnakeHead2() || ladders->getladderTop4()== snakes->getsnakeButt3() || ladders->getladderTop4()== snakes->getsnakeHead3()
          || ladders->getladderTop4()== snakes->getsnakeButt4() || ladders->getladderTop4()== snakes->getsnakeHead4() || ladders->getladderTop4()== ladders->getladderTop1()
          || ladders->getladderTop4()== ladders->getladderBot1()|| ladders->getladderTop4()== ladders->getladderBot2() || ladders->getladderTop4()== ladders->getladderTop2()
          || ladders->getladderTop4()== ladders->getladderBot3()|| ladders->getladderTop4()== ladders->getladderTop3() || ladders->getladderTop4()== snakes->getsnakeHead5()
          || ladders->getladderTop4()== snakes->getsnakeButt5())
    {
        ladders->setladderTop4((rand()%99)+1);
    }
    while(ladders->getladderBot4()== snakes->getsnakeButt1() || ladders->getladderBot4()== snakes->getsnakeHead1() || ladders->getladderBot4()== snakes->getsnakeButt2()
          || ladders->getladderBot4()== snakes->getsnakeHead2() || ladders->getladderBot4()== snakes->getsnakeButt3() || ladders->getladderBot4()== snakes->getsnakeHead3()
          || ladders->getladderBot4()== snakes->getsnakeButt4() || ladders->getladderBot4()== snakes->getsnakeHead4() || ladders->getladderBot4()== ladders->getladderTop1()
          || ladders->getladderBot4()== ladders->getladderBot1() || ladders->getladderBot4()== ladders->getladderBot2() || ladders->getladderBot4()== ladders->getladderTop2()
          || ladders->getladderBot4()== ladders->getladderBot3() || ladders->getladderBot4()== ladders->getladderTop3() || ladders->getladderBot4()== snakes->getsnakeHead5()
          || ladders->getladderBot4()== snakes->getsnakeButt5())
    {
        ladders->setladderBot4((rand()%(ladders->getladderTop4()-1)+1));
    }
    while(ladders->getladderTop5()== snakes->getsnakeButt1() || ladders->getladderTop5()== snakes->getsnakeHead1() || ladders->getladderTop5()== snakes->getsnakeButt2()
          || ladders->getladderTop5()== snakes->getsnakeHead2() || ladders->getladderTop5()== snakes->getsnakeButt3() || ladders->getladderTop5()== snakes->getsnakeHead3()
          || ladders->getladderTop5()== snakes->getsnakeButt4() || ladders->getladderTop5()== snakes->getsnakeHead4() || ladders->getladderTop5()== ladders->getladderTop1()
          || ladders->getladderTop5()== ladders->getladderBot1()|| ladders->getladderTop5()== ladders->getladderBot2() || ladders->getladderTop5()== ladders->getladderTop2()
          || ladders->getladderTop5()== ladders->getladderBot3()|| ladders->getladderTop5()== ladders->getladderTop3() || ladders->getladderTop5()== ladders->getladderTop4()
          || ladders->getladderTop5()== ladders->getladderBot4() || ladders->getladderTop5()== snakes->getsnakeHead5() || ladders->getladderTop5()== snakes->getsnakeButt5())
    {
        ladders->setladderTop5((rand()%99)+1);
    }
    while(ladders->getladderBot5()== snakes->getsnakeButt1() || ladders->getladderBot5()== snakes->getsnakeHead1() || ladders->getladderBot5()== snakes->getsnakeButt2()
          || ladders->getladderBot5()== snakes->getsnakeHead2() || ladders->getladderBot5()== snakes->getsnakeButt3() || ladders->getladderBot5()== snakes->getsnakeHead3()
          || ladders->getladderBot5()== snakes->getsnakeButt4() || ladders->getladderBot5()== snakes->getsnakeHead4() || ladders->getladderBot5()== ladders->getladderTop1()
          || ladders->getladderBot5()== ladders->getladderBot1()|| ladders->getladderBot5()== ladders->getladderBot2() || ladders->getladderBot5()== ladders->getladderTop2()
          || ladders->getladderBot5()== ladders->getladderBot3()|| ladders->getladderBot5()== ladders->getladderTop3() || ladders->getladderBot5()== ladders->getladderTop4()
          || ladders->getladderBot5()== ladders->getladderBot4() || ladders->getladderBot5()== snakes->getsnakeHead5() || ladders->getladderBot5
          ()== snakes->getsnakeButt5())
    {
        ladders->setladderBot5((rand()%(ladders->getladderTop5()-1)+1));
    }

}
