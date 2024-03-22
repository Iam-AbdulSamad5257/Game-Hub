#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

int signup_count = 0; // this checks the no of sign ups in game hub

// TIC TAC TOE GLOBAL VARIABLES
char player1[15];             // store the player 1 name
char player2[15];             // store the player 2 name
char choice1, choice2;        // store the choice of two players( X - O )
char decision;                //
char choice;                  // takes the choice of the user from menu
int turn_s;                   // stores the turns of the game
char OPTION_1, OPTION_2;      // stores the choice1 and choice2
char box[11] = {"123456789"}; // print on the board
int index = 0;

void gamehub_menu();         // main menu - shows game hub with sign up and login option
int gamehub_menu_function(); // takes input for signup and login options
void takepass();
void checkpass(); // take first time (or) new password from user with masking of '*'
int signup();     // take confirmation password from user with masking of '*'
int login();      // not defined yet
void about_us()   // ABOUT US MENU
{
    char ch;
    printf("\n\t\t================== ABOUT GAME-HUB ==================\n");
    printf("\n\t\twelcome to the (Game-Hub) program.\n\t\tGame-Hub is a console project. Here,\n\t\tThe user is going to create an account and can play many games,\n\t\tand this activity will be saved here with lot of information.\n\t\tThis project is build in c language.\n");
    printf("\n\t\t====================================================\n");
    while (1)
    {
        printf("\n\n\t\tPRESS 'B' TO RETURN TO MAIN MENU : ");
        ch = toupper(getch());
        if (ch == 'B')
        {
            loading();
            main();
            break;
        }
        else
        {
            printf("\n\t\tWRONG INPUT\n");
        }
    }
}
void login_menu();
int login_menu_function();

// TIC TAC TOE FUNCTIONS
int ttt();
void menu();
void gameboard();
void reset_board(gameboard);
void DECISION();
int start();
void help();
int gamers_turn();
int winning_condition(int turn);
int main_ttt();

clear_screen() // clear screen function
{
    system("cls");
}
sound() // beep(800,300);
{
    Beep(800, 300);
}

void blue() // text color
{
    system("color 1");
}
void red() // text color
{
    system("color 4");
}
void green() // text color
{
    system("color 2");
}
void yellow() // text color
{
    system("color 6");
}
void white() // text color white
{
    system("color 7");
}
int loading() // loading view
{
    clear_screen();
    int ch = 177; // space ascii value
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\tPLEASE WAIT, LOADING...\n\t\t\t\t");
    for (int i = 0; i < 80; i++)
    {
        green();
        printf("%c", ch); // prints coloured spaces
        Sleep(5);
    }
    printf("\n\t\t");
    white();
    return 0;
}

struct details // signup variables are located
{
    char first_name[50];
    char last_name[50];
    int dob[11];
    char gender[7];
    char email[30];
    char username[30];
    char pass[30];
};

int main()
{
    gamehub_menu();
    gamehub_menu_function();

    return 0;
}
void gamehub_menu() // main menu - shows game hub with sign up and login option
{
    clear_screen();
    printf("\t\t O ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| O \n");
    printf("\t\t||                                                                     ||\n");
    printf("\t\t||\t     ______       ______       ___    ___   ________           ||\n");
    printf("\t\t||\t   /  _____|     /  __  \\     |   \\__/   | |   _____|          ||\n");
    printf("\t\t||\t  |  |          /  (__)  \\    |          | |  |___             ||\n");
    printf("\t\t||\t  |  |   __    /   ____   \\   |  |\\__/|  | |   ___|            ||\n");
    printf("\t\t||\t  |  |__|  |  /  /      \\  \\  |  |    |  | |  |_____           ||\n");
    printf("\t\t||\t   \\_______| /__/        \\__\\ |__|    |__| |________|          ||\n");
    printf("\t\t||                                                                     ||\n");
    printf("\t\t||\t\t   __      __   __      __   _______                   ||\n");
    printf("\t\t||\t\t  |  |    |  | |  |    |  | |   __  \\                  ||\n");
    printf("\t\t||\t\t  |  |____|  | |  |    |  | |  |__|  )                 ||\n");
    printf("\t\t||\t\t  |    __    | |  |    |  | |  _____/                  ||\n");
    printf("\t\t||\t\t  |   ____   | |  |    |  | |   __  \\                  ||\n");
    printf("\t\t||\t\t  |  |    |  | |   \\__/   | |  |__|  )                 ||\n");
    printf("\t\t||\t\t  |__|    |__|  \\________/  |_______/                  ||\n");
    printf("\t\t||                                                                     ||\n");
    printf("\t\t||                                                                     ||\n");
    printf("\t\t||                                                                     ||\n");
    printf("\t\t||=====================================================================||\n");
    printf("\t\t||\t\t      WELCOME   TO   GAME  -  HUB                      ||\n");
    printf("\t\t||=====================================================================||\n");
    printf("\t\t||                                                                     ||\n");
    printf("\t\t||\t -------------------------      -------------------------      ||\n");
    printf("\t\t||\t|  PRESS '1' TO SIGN UP  |      |  PRESS '2' TO LOG IN  |      ||\n");
    printf("\t\t||\t -------------------------      -------------------------      ||\n");
    printf("\t\t||                                                                     ||\n");
    printf("\t\t||   -------------------------------    ----------------------------   ||\n");
    printf("\t\t||  |  PRESS '3' WHAT IS GAME HUB ? |  | PRESS '4' TO QUIT GAME-HUB |  ||\n");
    printf("\t\t||   -------------------------------    ----------------------------   ||\n");
    printf("\t\t||                                                                     ||\n");
    printf("\t\t O ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| O \n\n");
}
int gamehub_menu_function() // takes input for signup and login options
{
    char ch;
    while (1)
    {
        printf("\n\t\tENTER HERE : ");
        ch = getch();
        sound();
        sleep(0.5);
        if (ch == '1') // SIGNUP
        {
            clear_screen();
            signup();
            break;
        }
        else if (ch == '2') // LOGIN
        {
            clear_screen();
            login();
            login_menu_function();
            break;
        }
        else if (ch == '3') // about us
        {
            clear_screen();
            about_us();
        }
        else if (ch == '4') // Quit game-hub
        {
            printf("\n\n\t\tTHANK YOU FOR VISITING GAME-HUB\n\n");
            exit(1);
            break;
        }
        else
        {
            printf("WRONG INPUT !\n");
        }
    }
}
void takepass(char pass[]) // take first time (or) new password from user with masking of '*'
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            pass[i] = '\0';
            break;
        }
        else if (ch == 8)
        {
            printf("\b \b");
        }
        else if (ch == 9 || ch == 32)
        {
            continue;
        }
        else
        {
            pass[i++] = ch;
            printf("*");
        }
    }
}
void checkpass(char check_pass[]) // take confirmation password from user with masking of '*'
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            check_pass[i] = '\0';
            break;
        }
        else if (ch == 8)
        {
            printf("\b \b");
        }
        else if (ch == 9 || ch == 32)
        {
            continue;
        }
        else
        {
            check_pass[i++] = ch;
            printf("*");
        }
    }
}
int signup() // sign up function - take details and store in "gamehub.txt" file in 'write' mode
{
    struct details gh;
    char check_pass[9]; // local variable for confirmation password
    char ch;            // variable for input for returning to main menu
    printf("\t\t ================== GAMEHUB SIGN-IN PAGE ==================\n\n");

    printf("\t\t ENTER YOUR FIRST NAME : ");
    fflush(stdin);
    gets(gh.first_name);

    printf("\t\t ENTER YOUR LAST NAME : ");
    fflush(stdin);
    gets(gh.last_name);

    printf("\t\t ENTER D.O.B [DD-MM-YYYY] : ");
    fflush(stdin);
    scanf("%d", gh.dob);

    printf("\t\t ENTER GENDER : ");
    fflush(stdin);
    gets(gh.gender);

    printf("\t\t ENTER E-MAIL : ");
    fflush(stdin);
    gets(gh.email);

    while (1)
    {
        printf("\t\t ENTER GAMEHUB USERNAME [MAX 30 - CHARACTERS]: ");
        fflush(stdin);
        gets(gh.username);
        if (strlen(gh.username) > 30) // checks the length of username
        {
            printf("\t\t USERNAME TOO LONG\n");
        }
        else
        {
            break;
        }
    }

    while (1)
    {
        printf("\t\t ENTER GAMEHUB PASSWORD [MIN 4 - CHARACTERS] : ");
        fflush(stdin);
        takepass(gh.pass);
        if (strlen(gh.pass) < 4) // checks the length of password
        {
            printf("\n\t\t PASSWORD TOO SHORT\n");
        }
        else
        {
            break;
        }
    }

    while (1)
    {
        printf("\n\t\t CONFIRM PASSWORD : ");
        fflush(stdin);

        checkpass(check_pass);                // confirming password
        if (strcmp(gh.pass, check_pass) != 0) // comparing both passwords
        {
            printf("\n\t\t INCORRECT PASSWORD\n");
            while (1)
            {
                printf("\t\t PRESS 'R' RETRY, PRESS 'B' TO RETURN TO MAIN MENU : ");
                ch = toupper(getch());
                if (ch == 'R')
                {
                    break;
                }
                else if (ch == 'B')
                {
                    main();
                    break;
                }
                else
                {
                    printf("\n\t\t WRONG INPUT\n");
                }
            }
        }
        else
        {
            FILE *ptr = NULL;                 // storing in file gamehub.txt
            ptr = fopen("gamehub.txt", "wb"); // opening file in write in binary mode
            fwrite(&gh, sizeof(struct details), 1, ptr);
            signup_count++;
            fclose(ptr);

            printf("\n\n\t\t ================ SUCCESSFULLY SIGNED - IN =================\n\n");
            while (1)
            {
                printf("\n\n\t\tPRESS 'B' TO RETURN TO MAIN MENU : ");
                ch = toupper(getch());
                if (ch == 'B')
                {
                    loading();
                    main();
                    break;
                }
                else
                {
                    printf("\n\t\tWRONG INPUT\n");
                }
            }
            break;
        }
    }
    return 0;
}
int login()
{
    struct details gh;
    char check_pass[9];                    // local variable for confirmation password
    char ch, username[30], login_pass[30]; // variable for input for returning to main menu
    FILE *ptr = NULL;
    ptr = fopen("gamehub.txt", "rb");
    if (signup_count != 0)
    {

        printf("\t\t ================== GAMEHUB LOGIN-IN PAGE ==================\n\n");
        while (fread(&gh, sizeof(struct details), 1, ptr))
        {

            while (1)
            {
                printf("\t\t ENTER GAMEHUB USERNAME : "); // confirming user name
                fflush(stdin);
                gets(username);
                if (strcmp(gh.username, username) != 0)
                {
                    printf("\t\t USERNAME NOT FOUND\n");
                }
                else
                {
                here:
                    printf("\t\t ENTER GAMEHUB PASSWORD : "); // confirming user name
                    fflush(stdin);
                    takepass(login_pass);
                    if (strcmp(login_pass, gh.pass) != 0)
                    {
                        printf("\n\t\t PASSWORD NOT MATCHED\n");
                        goto here;
                    }
                    else
                    {
                        printf("\n\n\t\t ==================== LOGIN SUCCESSFULL ====================\n");
                        sleep(1);
                        sound();
                        login_menu();
                    }
                    break;
                }
            }
            break;
        }
        fclose(ptr);
    }
    else
    {
        printf("\n\t\tTHERE ARE NO ACCOUNTS TO LOG INTO GAMEHUB, PLEASE FIRST SIGN UP IN GAMEHUB");
        while (1)
        {
            printf("\n\n\t\tPRESS 'B' TO RETURN TO MAIN MENU : ");
            ch = toupper(getch());
            if (ch == 'B')
            {
                loading();
                main();
                break;
            }
            else
            {
                printf("\n\t\tWRONG INPUT\n");
            }
        }
    }
    return 0;
}
void login_menu()
{
    clear_screen();
    printf("\n\t\t O |||||||||||||||||||||||||||||||||||||||||||||||||||||||| O \n");
    printf("\t\t||\t       WELCOME   TO   GAME-HUB MENU                 ||\n");
    printf("\t\t O |||||||||||||||||||||||||||||||||||||||||||||||||||||||| O \n");
    printf("\t\t||                                                          ||\n");
    printf("\t\t||\t   -----------------------------                    ||\n");
    printf("\t\t||\t  |  PRESS '1' FOR TIC-TAC-TOE  |                   ||\n");
    printf("\t\t||\t   -----------------------------                    ||\n");
    printf("\t\t||                                                          ||\n");
    printf("\t\t||\t   ----------------------------------               ||\n");
    printf("\t\t||\t  |  PRESS '2' FOR SNAKE AND LADDER  |              ||\n");
    printf("\t\t||\t   ----------------------------------               ||\n");
    printf("\t\t||                                                          ||\n");
    printf("\t\t||\t   ------------------------------------             ||\n");
    printf("\t\t||\t  |  PRESS '3' FOR WORD GUESSING GAME  |            ||\n");
    printf("\t\t||\t   ------------------------------------             ||\n");
    printf("\t\t||                                                          ||\n");
    printf("\t\t||\t   --------------------------                       ||\n");
    printf("\t\t||\t  |  PRESS '4' FOR QUIZ GAME |                      ||\n");
    printf("\t\t||\t   --------------------------                       ||\n");
    printf("\t\t||                                                          ||\n");
    printf("\t\t||\t   ------------------------------------             ||\n");
    printf("\t\t||\t  |  PRESS '5' FOR ROCK PAPER SCISSORS |            ||\n");
    printf("\t\t||\t   ------------------------------------             ||\n");
    printf("\t\t||                                                          ||\n");
    printf("\t\t||\t   --------------------------                       ||\n");
    printf("\t\t||\t  |  PRESS '6' TO LOG OUT    |                      ||\n");
    printf("\t\t||\t   --------------------------                       ||\n");
    printf("\t\t||                                                          ||\n");
    printf("\t\t O |||||||||||||||||||||||||||||||||||||||||||||||||||||||| O \n\n");
}
int login_menu_function()
{
    int ch;
    char sure;
    while (1)
    {
        printf("\n\t\tENTER HERE : ");
        ch = getch();
        if (ch == '1')
        {
            printf("tic-tac-toe");
            ttt();
            break;
        }
        else if (ch == '2')
        {
            printf("snake and ladder coming soon");
            while (1)
            {
                printf("\n\n\t\tPRESS 'B' TO RETURN TO MENU : ");
                ch = toupper(getch());
                if (ch == 'B')
                {
                    login_menu();
                    login_menu_function();
                    break;
                }
                else
                {
                    printf("\n\t\tWRONG INPUT\n");
                }
            }
            break;
            // snake_ladder();
        }
        else if (ch == '3')
        {
            printf("word_guessing coming soon");
            while (1)
            {
                printf("\n\n\t\tPRESS 'B' TO RETURN TO MENU : ");
                ch = toupper(getch());
                if (ch == 'B')
                {
                    login_menu();
                    login_menu_function();
                    break;
                }
                else
                {
                    printf("\n\t\tWRONG INPUT\n");
                }
            }
            break;
            // word_guessing();
        }
        else if (ch == '4')
        {
            printf("quiz coming soon");
            while (1)
            {
                printf("\n\n\t\tPRESS 'B' TO RETURN TO MENU : ");
                ch = toupper(getch());
                if (ch == 'B')
                {
                    login_menu();
                    login_menu_function();
                    break;
                }
                else
                {
                    printf("\n\t\tWRONG INPUT\n");
                }
            }
            break;
            // quiz();
        }
        else if (ch == '5')
        {
            printf("rock paper scissors coming soon");
            while (1)
            {
                printf("\n\n\t\tPRESS 'B' TO RETURN TO MENU : ");
                ch = toupper(getch());
                if (ch == 'B')
                {
                    login_menu();
                    login_menu_function();
                    break;
                }
                else
                {
                    printf("\n\t\tWRONG INPUT\n");
                }
            }
            break;
            // rockpaper();
        }
        else if (ch == '6')
        {
            while (1)
            {
                printf("ARE YOU SURE ? (Y/N) : ");
                fflush(stdin);
                sure = toupper(getch());
                sound();
                if (sure == 'Y')
                {
                    printf("LOGGED OUT SUCCESSFULLY\n");
                    sleep(2);
                    main();
                    break;
                }
                else if (sure == 'N')
                {
                    printf("LOGGING OUT CANCELLED !");
                    sleep(2);
                    login_menu();
                    login_menu_function();
                    break;
                }
                else
                {
                    printf("WRONG INPUT !\n");
                }
            }

            break;
        }
        else
        {
            printf("WRONG INPUT!\n");
        }
    }
}

// TIC TAC TOE FUNTIONS

void menu() // menu of the game
{
    clear_screen();
    printf("\t\t\tX - O - X - O - X - O - X - O - X - O - X - O - X - O - X - O - X - O - X - O\n");
    printf("\t\t\t|                                                                           |\n");
    printf("\t\t\tO       X - O - X - O - X - O - X - O - X - O - X - O - X - O - X - O       X\n");
    printf("\t\t\t|       |                                                           |       |\n");
    printf("\t\t\tX       O                WELCOME TO TIC - TAC - TOE                 O       O\n");
    printf("\t\t\t|       |                                                           |       |\n");
    printf("\t\t\tO       X                                                           O       X\n");
    printf("\t\t\t|       |               ENTER \" S \" TO START THE GAME               |       |\n");
    printf("\t\t\tX       O                                                           X       O\n");
    printf("\t\t\t|       |               ENTER \" H \" GET HELP                        |       |\n");
    printf("\t\t\tO       X                                                           O       X\n");
    printf("\t\t\t|       |               ENTER \" Q \" QUIT THE GAME                   |       |\n");
    printf("\t\t\tX       O                                                           X       O\n");
    printf("\t\t\t|       |                                                           |       |\n");
    printf("\t\t\tO       X - O - X - O - X - O - X - O - X - O - X - O - X - O - X - O       X\n");
    printf("\t\t\t|                                                                           |\n");
    printf("\t\t\tX - O - X - O - X - O - X - O - X - O - X - O - X - O - X - O - X - O - X - O\n\n");
    printf("ENTER THE OPTION : ");
    fflush(stdin);
    choice = toupper(getch());
    Beep(800, 500);
    fflush(stdin);
}
void gameboard() // game board
{
    printf("\n");
    printf("\t\t\t\t\t\t\t        |     |     \n");
    Sleep(150);
    printf("\t\t\t\t\t\t\t     %c  |  %c  |  %c  \n", box[0], box[1], box[2]);
    Sleep(150);
    printf("\t\t\t\t\t\t\t   _____|_____|_____\n");
    Sleep(150);
    printf("\t\t\t\t\t\t\t        |     |     \n");
    Sleep(150);
    printf("\t\t\t\t\t\t\t     %c  |  %c  |  %c  \n", box[3], box[4], box[5]);
    Sleep(150);
    printf("\t\t\t\t\t\t\t   _____|_____|_____\n");
    Sleep(150);
    printf("\t\t\t\t\t\t\t        |     |     \n");
    Sleep(150);
    printf("\t\t\t\t\t\t\t     %c  |  %c  |  %c  \n", box[6], box[7], box[8]);
    Sleep(150);
    printf("\t\t\t\t\t\t\t        |     |     \n");
}
void reset_board(gameboard)
{
    box[0] = '1';
    box[1] = '2';
    box[2] = '3';
    box[3] = '4';
    box[4] = '5';
    box[5] = '6';
    box[6] = '7';
    box[7] = '8';
    box[8] = '9';
}
void DECISION()
{
    sleep(1);
    Beep(700, 700);
    Beep(700, 1000);
    fflush(stdin);
    printf("\v\v\t\t\t\t -------------------------      -----------------------------        -------------------\n");
    printf("\t\t\t\t| PRESS 'P' TO PLAY AGAIN |    | PRESS 'B' TO RETURN TO MENU |      | PRESS 'Q' TO QUIT |\n");
    printf("\t\t\t\t -------------------------      -----------------------------        -------------------\n");
    while (1)
    {
        printf("\n\n\t\t\t\tENTER THE OPTION ----->> "); // taking input from user
        fflush(stdin);
        decision = toupper(getch()); // captalising input
        Beep(800, 600);
        if (decision == 'P')
        {
            clear_screen();
            reset_board(gameboard);
            // fflush(stdout);
            gamers_turn();
        }
        else if (decision == 'B')
        {
            reset_board(gameboard);
            ttt();
            break;
        }
        else if (decision == 'Q')
        {
            reset_board(gameboard);
            ttt();
            break;
        }
        else
        {
            printf("\n\n\tPLEASE ENTER THE CORRECT OPTION");
            Sleep(500);
        }
    }
}
int start()
{
    printf("\tENTER PLAYER 1 NAME : ");
    fflush(stdin);
    gets(player1); // take the player 1 name
    while (1)
    {
        printf("\tENTER YOUR CHOICE ('X' OR 'O'): ");
        choice1 = toupper(fgetc(stdin)); // take the player 1 choice
        fflush(stdin);
        OPTION_1 = choice1; // store the choice1 in option 1
        if (choice1 == 'X' || choice1 == 'O')
        {
            printf("\n\t\tPLAYER 1 ( %s ) CHOICE CONFIRMED --> \"%c\"\n\n", strupr(player1), choice1); // player 1 choice conformation
            Beep(800, 400);
            sleep(0.5);
            printf("\tENTER PLAYER 2 NAME : ");
            fflush(stdin);
            gets(player2); // take the player 2 name
            Beep(800, 400);
            if (choice1 == 'X')
            {
                choice2 = 'O';
                OPTION_2 = choice2;                                                                      // store the choice2 in option 2
                printf("\n\t\tPLAYER 2 ( %s ) CHOICE CONFIRMED --> \"%c\"\n", strupr(player2), choice2); // player 2 choice conformation
                Beep(800, 400);
                break;
            }
            else
            {
                choice2 = 'X';
                OPTION_2 = choice2;                                                                      // store the choice2 in option 2
                printf("\n\t\tPLAYER 2 ( %s ) CHOICE CONFIRMED --> \"%c\"\n", strupr(player2), choice2); // player 2 choice conformation
                Beep(800, 400);
                break;
            }
            break;
        }
        else
        {
            printf("\n\t\tWRONG CHOICE!, TRY AGAIN!!\n\n"); // if the choice is not ( X - O )
            Beep(800, 400);
            sleep(1);
        }
    }
    // sleep(1.5);
    // sleep(0.3);
    gamers_turn();
    return 0;
}
void help()
{
    char back; // stores input from user
    printf("THIS IS A TWO PLAYER GAME.\nYOU HAVE SELECT 'X' OR 'O' AT YOUR TURN\nIF THREE 'X' OR THREE 'O' ARE MARKED VERITCALLY, HORIZONTALLY OR DIAGONALLY AT THE END THEN THE PLAYER WINS");
    while (1)
    {
        printf("\n\vPRESS 'B' TO GO BACK...");
        fflush(stdin);
        back = toupper(getch()); // taking input from user and captalising the character
        Beep(800, 600);
        if (back == 'B') // checking if user entered letter 'B'
        {
            fflush(stdout);
            ttt();
            break;
        }
        else
        {
            printf("\n\n\tENTER THE CORRECT KEY...."); // if 'B' is not entered again taking the input
            // sleep(0.6);
        }
    }
}
int gamers_turn() //  switch the player turn according to game
{
    char turn;   // it is a local variable
    int BOX = 0; // store the number of box/cell are full
    turn = 'X';  // TURN IS FIXED TO 'X' SO GAME START FROM X
    int num;     // store the number to mark on the board
    if (turn || turn)
    {
        if (choice1 == turn)
        {
            turn_s = 0; // even turns = player 1
        }
        else
        {
            turn_s = 1; // odd turns = player 2
        }
        while (1)
        {
            if (turn_s % 2 == 0) // even turn
            {
                system("cls");
                printf("\n\n\t\t\t\t\t---------------------- LET'S START ----------------------\n\n");
                gameboard();
                printf("\n\t\t\t\t\t\t\t     \" %s's TURN \"\n\n\t\t\t\tYOUR CHOICE ' %c '\n", player1, choice1);
                while (1)
                {
                    printf("\t\t\t\tENTER THE NUMBER TO MARK ON THE BOARD : ");
                    fflush(stdin);
                    scanf("%d", &num);
                    Beep(800, 600);
                    if (num > 0 && num < 10) // check 0 < num < 10
                    {
                        if (box[num - 1] != 'X' && box[num - 1] != 'O') // check weeather the box is filled or not
                        {
                            box[num - 1] = turn;
                        }
                        else // if the board is occuipied
                        {
                            printf("\n\n\tTHE BOX IS ALREADY OCCUPIED\n\n");
                            Sleep(900);
                            turn_s = turn_s + 2; // to get an even turn again
                            continue;
                        }
                        winning_condition(turn); // check the winning conditions
                        BOX = BOX + 1;           // add 1 as box filled
                        Sleep(500);
                        turn = OPTION_2; // change turn to option 2 i.e choice 2
                        turn_s++;        // to get an odd turn
                        break;
                    }
                    else // if the number is invalid ( 0 or more than 10 )
                    {
                        printf("\n\n\tINVALID BOX NUMBER ( 1 - 9 )\n\n");
                        Sleep(900);
                        // break;
                    }
                }
                if (BOX == 9) // if box = 9 ends the game
                {
                    break;
                }
            }
            else
            {
                system("cls");
                printf("\n\n\t\t\t\t\t---------------------- LET'S START ----------------------\n\n");
                gameboard();
                printf("\n\t\t\t\t\t\t\t     \" %s's TURN \"\n\n\t\t\t\tYOUR CHOICE ' %c '\n", player2, choice2);
                while (1)
                {
                    printf("\t\t\t\tENTER THE NUMBER TO MARK ON THE BOARD : ");
                    fflush(stdin);
                    scanf("%d", &num);
                    Beep(800, 600);
                    if (num > 0 && num < 10) // check 0 < num < 10
                    {
                        if (box[num - 1] != 'X' && box[num - 1] != 'O') // check weeather the box is filled or not
                        {
                            box[num - 1] = turn;
                        }
                        else // if the board is occuipied
                        {
                            printf("\n\n\tTHE BOX IS ALREADY OCCUPIED\n\n");
                            Sleep(900);
                            turn_s = turn_s + 2; // to get an odd turn again
                            continue;
                        }
                        winning_condition(turn); // check the winning conditions
                        BOX = BOX + 1;           // add 1 as box filled
                        Sleep(500);
                        turn = OPTION_1; // change turn to option 2 i.e choice 2
                        turn_s++;        // to get an even turn
                        break;
                    }
                    else // if the number is invalid ( 0 or more than 10 )
                    {
                        printf("\n\n\tINVALID BOX NUMBER ( 1 - 9 )\n\n");
                        Sleep(900);
                        // break;
                    }
                }
                if (BOX == 9) // if box = 9 ends the game
                {
                    break;
                }
            }
        }
        printf("\n\n\tMATCH HAD BEEN DRAWN\n\n");
        turn_s = 0;
        Sleep(800);
        DECISION();
    }
    return 0;
}
int winning_condition(int turn) // check the winning condition of players
{
    if (box[0] == turn && box[1] == turn && box[2] == turn) // chek the following boxes with followed turn
    {
        if (turn == OPTION_1) // if turn = option 1 where option 1 is choice 1 so player 1 wins
        {
            printf("\n\n\t\t\t\t\t  [][][][][] PLAYER - 1 '%s' WINS !!! [][][][][]", player1);
        }
        else // other wise player 2 wins
        {
            printf("\n\n\t\t\t\t\t\t  [][][][][] PLAYER - 2 '%s' WINS !!! [][][][][]", player2);
        }
        DECISION();
        // exit(1);
    }
    else if (box[3] == turn && box[4] == turn && box[5] == turn) // cond - 2
    {
        if (turn == OPTION_1)
        {
            printf("\n\n\t\t\t\t\t\t  [][][][][] PLAYER - 1 '%s' WINS !!! [][][][][]", player1);
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t  [][][][][] PLAYER - 2 '%s' WINS !!! [][][][][]", player2);
        }
        DECISION();
        // exit(1);
    }
    else if (box[6] == turn && box[7] == turn && box[8] == turn) // cond - 3
    {
        if (turn == OPTION_1)
        {
            printf("\n\n\t\t\t\t\t\t  [][][][][] PLAYER - 1 '%s' WINS !!! [][][][][]", player1);
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t  [][][][][] PLAYER - 2 '%s' WINS !!! [][][][][]", player2);
        }
        DECISION();
        // exit(1);
    }
    else if (box[0] == turn && box[3] == turn && box[6] == turn) // cond - 4
    {
        if (turn == OPTION_1)
        {
            printf("\n\n\t\t\t\t\t  [][][][][] PLAYER - 1 '%s' WINS !!! [][][][][]", player1);
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t  [][][][][] PLAYER - 2 '%s' WINS !!! [][][][][]", player2);
        }
        DECISION();
        // exit(1);
    }
    else if (box[1] == turn && box[4] == turn && box[7] == turn) // cond - 5
    {
        if (turn == OPTION_1)
        {
            printf("\n\n\t\t\t\t\t\t  [][][][][] PLAYER - 1 '%s' WINS !!! [][][][][]", player1);
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t  [][][][][] PLAYER - 2 '%s' WINS !!! [][][][][]", player2);
        }
        DECISION();
        // exit(1);
    }
    else if (box[2] == turn && box[5] == turn && box[8] == turn) // cond - 6
    {
        if (turn == OPTION_1)
        {
            printf("\n\n\t\t\t\t\t\t  [][][][][] PLAYER - 1 '%s' WINS !!! [][][][][]", player1);
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t  [][][][][] PLAYER - 2 '%s' WINS !!! [][][][][]", player2);
        }
        DECISION();
        // exit(1);
    }
    else if (box[2] == turn && box[4] == turn && box[6] == turn) // cond - 7
    {
        if (turn == OPTION_1)
        {
            printf("\n\n\t\t\t\t\t\t  [][][][][] PLAYER - 1 '%s' WINS !!! [][][][][]", player1);
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t  [][][][][] PLAYER - 2 '%s' WINS !!! [][][][][]", player2);
        }
        DECISION();
        // exit(1);
    }
    else if (box[0] == turn && box[4] == turn && box[8] == turn) // cond - 8
    {
        if (turn == OPTION_1)
        {
            printf("\n\n\t\t\t\t\t\t  [][][][][] PLAYER - 1 '%s' WINS !!! [][][][][]", player1);
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t  [][][][][] PLAYER - 2 '%s' WINS !!! [][][][][]", player2);
        }
        DECISION();
        // exit(1);
    }
    return 0;
}
int ttt()
{
    while (1)
    {
        menu();
        if (choice == 'S')
        {
            clear_screen();
            start();
            break;
        }
        else if (choice == 'H')
        {
            clear_screen();
            help();
            break;
        }
        else if (choice == 'Q')
        {
            login_menu();
            login_menu_function();
            break;
        }
        else
        {
            printf("WRONG INPUT !\n");
        }
    }
    return 0;
}
