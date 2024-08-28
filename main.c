#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>

// GAME HUB VARIABLES AND FUNCTION DECLARATIONS

int signup_count = 0; // this checks the no of sign ups in game hub
struct details        // signup variables are located
{
    char first_name[50];
    char last_name[50];
    int dob[11];
    char gender[7];
    char email[30];
    char username[30];
    char pass[30];
};

void gamehub_menu();         // main menu - shows game hub with sign up and login option
int gamehub_menu_function(); // takes input for signup and login options
void takepass();
void checkpass(); // take first time (or) new password from user with masking of '*'
int signup();     // take confirmation password from user with masking of '*'
int login();      // not defined yet
void login_menu();
int login_menu_function();
void about_us() // ABOUT US MENU
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

// EXTRA GAMEHUB FUNTIONS

void clear_screen() // clear screen function
{
    system("cls");
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
void sound() // beep(800,300);
{
    Beep(800, 300);
}

// TIC TAC TOE GLOBAL VARIABLES AND FUNCTION DECLARATIONS

char player1[15];             // store the player 1 name
char player2[15];             // store the player 2 name
char choice1, choice2;        // store the choice of two players( X - O )
char decision;                //
char choice;                  // takes the choice of the user from menu
int turn_s;                   // stores the turns of the game
char OPTION_1, OPTION_2;      // stores the choice1 and choice2
char box[11] = {"123456789"}; // print on the board
int index_ = 0;

int ttt();
void menu();
void gameboard();
int reset_board(int gameboard);
void DECISION();
int start();
void help();
int gamers_turn();
int winning_condition(char turn);
int main_ttt();

// ROCK PAPER SCISSORS VARIABLES AND FUNTION DECLARATIONS
char rps_player[15];
int rps_intro();
int rps_game();
int rps_main();

// SNAKE AND LADDER GAME VARIABLES AND FUNCTIONS

void snl_board();
int snl_Die();
int snl_gamer_1(int);
int snl_gamer_2(int);
int snl_computer(int);
int snl_menu();
int snl_menu_2();
void snl_help();
int snl_main();

// QUIZ GAME VARIABLES AND FUNCTIONS

int Quiz_help();
int Quiz_start();
int Quiz_q_time();
int Quiz_main();

// WORD GUESSING GAME VARIABLES AND FUNCTIONS

int word_guess_randint(int a, int b);
char *word_guess_get_random_word();
int word_guess_main();

// GAMEHUB WORKING FUNCTIONS

int main() // MAIN
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
        // printf("\n\t\tENTER HERE : ");
        ch = getch();
        sound();
        Sleep(500);
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
            printf("\n\n\t\t\t\t   THANK YOU FOR VISITING GAME-HUB\n\n\n");
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
            printf("\033[0;31m");
            printf("\n\t\t PASSWORD TOO SHORT\n");
            printf("\033[0m");
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
            printf("\033[0;31m");
            printf("\n\t\t INCORRECT PASSWORD\n");
            printf("\033[0m");
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
                    printf("\033[0;31m");
                    printf("\n\t\t WRONG INPUT\n");
                    printf("\033[0m");
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

            printf("\n\n\t\t ================ ");
            printf("\033[0;32m");
            printf("SUCCESSFULLY SIGNED - IN");
            printf("\033[0m");
            printf(" =================\n\n");
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
                    printf("\033[0;31m");
                    printf("\t\t USERNAME NOT FOUND\n");
                    printf("\033[0m");
                }
                else
                {
                here:
                    printf("\t\t ENTER GAMEHUB PASSWORD : "); // confirming user name
                    fflush(stdin);
                    takepass(login_pass);
                    if (strcmp(login_pass, gh.pass) != 0)
                    {
                        printf("\033[0;31m");
                        printf("\n\t\t PASSWORD NOT MATCHED\n");
                        printf("\033[0m");
                        goto here;
                    }
                    else
                    {
                        printf("\n\n\t\t ==================== ");
                        printf("\033[0;32m");
                        printf("LOGIN SUCCESSFULL ");
                        printf("\033[0m");
                        printf("====================\n");
                        Sleep(1000);
                        sound();
                        loading();
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
        // printf("\n\t\tENTER HERE : ");
        ch = getch();
        if (ch == '1')
        {
            printf("tic-tac-toe");
            ttt();
            break;
        }
        else if (ch == '2')
        {

            snl_main();

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
            // printf("word_guessing coming soon");
            word_guess_main();
            while (1)
            {
                printf("\n\n\t\tPRESS 'B' TO RETURN TO MENU : ");
                printf("\t\t\tPRESS 'P' TO PLAY AGAIN : ");
                ch = toupper(getch());
                if (ch == 'B')
                {
                    login_menu();
                    login_menu_function();
                    break;
                }
                else if (ch == 'P')
                {
                    word_guess_main();
                    // break;
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
            // printf("quiz coming soon");
            Quiz_main();
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

            rps_main();
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
                    Sleep(2000);
                    loading();
                    main();
                    break;
                }
                else if (sure == 'N')
                {
                    printf("LOGGING OUT CANCELLED !");
                    Sleep(2000);
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

// TIC TAC TOE  WORKING FUNTIONS

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
    printf("\033[0;36m");
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
    printf("\033[0m");
}
int reset_board(int gameboard)
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
    return 0;
}
void DECISION()
{
    Sleep(1000);
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
            reset_board((int)gameboard);
            gamers_turn();
        }
        else if (decision == 'B')
        {
            reset_board((int)gameboard);
            ttt();
            break;
        }
        else if (decision == 'Q')
        {
            reset_board((int)gameboard);
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
            Sleep(500);
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
            Sleep(1000);
        }
    }
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
int winning_condition(char turn) // check the winning condition of players
{
    for (int cell = 0; cell < 10; cell++)
    {

        if (box[cell] == turn && box[cell += 1] == turn && box[cell + 1] == turn)
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
    }
    for (int cell = 0; cell < 10; cell++)
    {
        if (box[cell] == turn && box[cell += 3] == turn && box[cell + 3] == turn)
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
    }
    for (int cell = 0; cell < 10; cell++)
    {
        if (box[cell] == turn && box[cell += 4] == turn && box[cell + 4] == turn)
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
    }
    for (int cell = 2; cell < 10; cell++)
    {
        if (box[cell] == turn && box[cell += 2] == turn && box[cell + 2] == turn)
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

// ROCK PAPER SCISSORS WORKING FUNCTIONS

int rps_intro()
{
    printf("\n\t\t\t**************************************************\n");
    printf("\t\t\t*     Welcome to the ROCK PAPER SCISSOR game     *\n");
    printf("\t\t\t**************************************************\n");
    printf("\n\t\t\tREAD THE INSTRUCTIONS BEFORE STARTING THE GAME:\n\n");
    printf("\t\t\t-You are playing against computer-\n\t\t\t-You have 3 chances and 1 point for each win-\n\t\t\t-Choose numbers as per options-\n\t\t\t\t0 - ROCK\n\t\t\t\t1 - PAPER\n\t\t\t\t2 - SCISSORS\n\t\t\t-All the best-");

    while (1)
    {
        char key;
        printf("\n\nPRESS 'C' TO CONTINUE :");
        sound();
        key = toupper(getch());
        if (key == 'C')
        {
            break;
        }
        else
        {
            printf("\nPRESS THE ENTER KEY...\n");
        }
    }
    clear_screen();
    printf("\n\n\t\t\t<------------Let's get started------------>\n\n");
    printf("\t\t\t\tENTER YOUR NAME: ");
    fflush(stdin);
    gets(rps_player);
    printf("\n\t\t\t\tOPPONENT : COMPUTER\n\n");
    Sleep(1000);
    return 0;
}
int rps_game()
{
    clear_screen();
    static int win = 0;
    static int loose = 0;
    static int draw = 0;

    // opening

    for (int i = 0, j = 1; i < 3; i++, j++)
    {
        srand(time(NULL) + i);
        char comp_choice[] = {'R', 'P', 'S'}; // COMPUTERS RANDOM CHOICE SELECTION OPTIONS
        char r = comp_choice[rand() % 3];
        int rps_choice;

        printf("\n\t\t\t\t------------ ROUND %d ------------\n\n", j);
        while (1)
        {
            // printf("\033[0;31m");
            printf("\n\t\t\t\tR-ROCK ? ");
            // printf("\033[0m");

            // printf("\033[0;34m");
            printf("P-PAPER ? ");
            // printf("\033[0m");

            // printf("\033[0;32m");
            printf("S-SCISSOR ? ==> ");
            // printf("\033[0m");

            fflush(stdin);

            rps_choice = toupper(getc(stdin));

            if (rps_choice == 'R' || rps_choice == 'P' || rps_choice == 'S')
            {
                printf("\n\t\t\t\t%s'S CHOICE: %c", strupr(rps_player), rps_choice);
                break;
            }
            else
            {
                printf("\033[0;33m");
                printf("\n\t\t\t\tWRONG INPUT !\n");
                printf("\033[0m");
            }
        }

        printf(" \n\n\t\t\t\tCOMPUTER'S CHOICE: %c\n", r); // COMPUTERS RANDOM CHOICE

        if (rps_choice == r) // chance results
        {
            printf("\033[0;33m");
            printf("\n\t\t\t\t* DRAW - NO POINTS *\n\n"); // NO POINTS
            printf("\033[0m");
            draw++;
        }
        else if (rps_choice == 'R' && r == 'S' || rps_choice == 'S' && r == 'P' || rps_choice == 'P' && r == 'R') // POINT TO PLAYER
        {
            printf("\033[0;33m");
            printf("\n\t\t\t\t* 1 POINT FOR %s *\n\n", strupr(rps_player));
            printf("\033[0m");
            win++;
        }
        else if (r == 'R' && rps_choice == 'S' || r == 'P' && rps_choice == 'R' || r == 'S' && rps_choice == 'P') // POINT FOR COMPUTER
        {
            printf("\033[0;33m");
            printf("  \n\t\t\t\t* 1 POINT FOR COMPUTER *\n\n");
            printf("\033[0m");
            loose++;
        }
    }
    printf("\v"); // Full round result

    if (win == 1 && draw == 1 && loose == 1 || draw == 3) // CONDITIONS FOR DRAW
    {
        sound();
        printf("\033[0;32m");
        printf("\t\t\t *THIS GAME IS DRAWN, PLEASE TRY AGAIN!*\n\n");
        printf("\033[0m");
    }
    else if (win == 2 && draw == 1 || win == 2 && loose == 1 || win == 1 && draw == 2 || win == 3) // CONDITIONS FOR WINNING
    {
        printf("\033[0;32m");
        printf("\t\t\t *CONGRATULATIONS, YOU HAVE WON THIS GAME WITH TOTAL OF POINTS %d*\n\n", win);
        printf("\033[0m");
        sound();
    }
    else if (loose == 3 || loose == 2 && win == 1 || loose == 2 && draw == 1 || draw == 2 && loose == 1)
    {
        fflush(stdin);
        sound();
        printf("\033[0;32m");
        printf("\t\t\t *OOPS! YOU LOST BETTER LUCK NEXT TIME*\n\n"); // PLAYER LOSES THE GAME
        printf("\033[0m");
    }
    else
    {
        printf(" ");
    }

    while (1)
    {
        printf("\t\t\tDO YOU WANT TO PLAY AGAIN ? (Y/N): "); // REPETITION
        sound();
        char again = toupper(getch());
        if (again == 'Y')
        {
            win = 0;
            loose = 0;
            draw = 0;
            system("cls");
            rps_game();
        }
        else if (again == 'N')
        {
            printf("\n\n\t\t\tTHANK YOU FOR PLAYING...\n\n");
            Sleep(2000);
            login_menu();
            login_menu_function();
        }
        else
            printf("WRONG INPUT !\n");
    }

    return 0;
}
int rps_main()
{
    clear_screen();
    rps_intro();
    rps_game();
    return 0;
}

// SNAKE AND LADDER GAME WHOLE FUNCTIONS

// SNAKE AND LADDER STARTS HERE

int snl_main()
{
    char player_1[30];
    char player_2[30];
    int score_1 = 0;
    int score_2 = 0;
    int score_3 = 0;
    int option;
    int position_1 = 0;
    int position_2 = 0;
    int position_3 = 0;
    int i;
    option = snl_menu();
    system("color 9");
    if (option == 1)
    {
        printf("\t\tENTER THE PLAYER NAME: ");
        scanf(" %s", player_1);
        printf("\n\n\tTHE OPPONENT PLAYER IS COMPUTER.");
        system("cls");
        while (score_1 <= 100 && score_3 <= 100)
        {
            system("color 3");
            snl_board();
            printf("\n%s TURN :\n\n", player_1);
            printf("\t\t\tYOUR CURRENT POSITION:%d\n\n", score_1);
            score_1 = snl_gamer_1(position_1);
            position_1 = score_1;
            if (score_1 == 100)
            {
                printf("CONGRATULATION'S %s . YOU HAVE WIN THE GAME..\n", player_1);
                break;
            }
            printf("COMPUTER TURN :\n\n");
            printf("\t\t\tYOUR CURRENT POSITION:%d\n\n", score_3);
            score_3 = snl_computer(position_3);
            position_3 = score_3;
            if (score_3 == 100)
            {
                printf("COMPUTER WON THE MATCH!\n");
                printf("\nTRY NEXT TIME!!");
                break;
            }
            system("cls");
        } // }
    }
    else if (option == 2)
    {
        printf("\t\tENTER THE PLAYER-1 NAME:");
        scanf("%s", player_1);
        printf("\n\n\t\tENTER THE PLAYER-2 NAME:");
        scanf("%s", player_2);
        system("cls");
        while (score_1 <= 100 && score_2 <= 100)
        {
            system("color d");
            snl_board();
            printf("\n%s TURN :\n\n", player_1);
            printf("\t\t\tYOUR CURRENT POSITION:%d\n\n", score_1);
            score_1 = snl_gamer_1(position_1);
            Sleep(1500);
            position_1 = score_1;
            if (score_1 == 100)
            {
                printf("CONGRATULATION'S %s . YOU HAVE WIN THE GAME..\n", player_1);
                break;
            }
            printf("%s TURN :\n\n", player_2);
            printf("\t\t\tYOUR CURRENT POSITION:%d\n\n", score_2);
            score_2 = snl_gamer_2(position_2);
            Sleep(1500);
            position_2 = score_2;
            if (score_2 == 100)
            {
                printf("CONGRATULATION'S %s . YOU HAVE WIN THE GAME..\n", player_2);
                break;
            }
            system("cls");
        }
    }
    else if (option == 3)
    {
        snl_menu();
    }
    else
    {
        printf("\n\n\t\t\tENTER THE RIGHT KEY...");
        Sleep(1000);
        snl_menu();
    }
    return 0;
}
int snl_menu()
{
    system("cls");
    system("color 0");
    printf("\n\n\t\t\t* * * * * * * * * * * WELCOME TO SNAKE AND LADDER GAME * * * * * * * * * * * \n\n");
    int i;
    char choice;
    int Option;
    char title[3][50] = {"ENTER 'S' TO PLAY THE GAME.", "ENTER 'H' FOR HELP.", "ENTER 'Q' TO QUIT THE GAME."};
    for (i = 0; i < 3; i++)
    {
        printf("\t\t\t\t\t\t");
        printf("%s\t\t\n\n", title[i]);
    }
    printf("\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    printf("\t\t\t\tENTER YOUR OPTION: ");
    choice = toupper(fgetc(stdin));
    fflush(stdin);
    if (choice == 'S')
    {
        Option = snl_menu_2();
    }
    else if (choice == 'H')
    {
        snl_help();
    }
    else if (choice == 'Q')
    {
        exit(1);
    }
    else
    {
        printf("\n\n\t\t\t\tENTER THE RIGHT KEY...");
        Sleep(1500);
        snl_menu();
    }
    return Option;
}
int snl_menu_2()
{
    int option;
    char Option[3][25] = {"1.PLAY WITH COMPUTER", "2.PLAY WITH FRIEND", "3.GO TO BACK"};
    int i;
    system("cls");
    printf("\t\t\t- - - - - - - - - - - - - - - - - - - - - - - -\n\n");
    for (i = 0; i < 3; i++)
    {
        printf("\t\t\t\t\t");
        printf("%s\n\n", Option[i]);
    }
    printf("\t\t\t- - - - - - - - - - - - - - - - - - - - - - - -\n\n");
    printf("\t\t\t ENTER THE OPTION:(1/2/3):");
    scanf("%d", &option);
    system("cls");
    return option;
}
void snl_help()
{
    char home;
    system("cls");
    system("color a");
    printf("\t\t\tWELCOME TO SNAKE AND LADDER GAME\n\n");
    snl_board();
    printf("\n\tHERE YOU CAN PLAY WITH COMPUTER AND ALSO WITH YOUR FRIEND.\n");
    printf("\tYOU CAN SEE THE GAME BOARD  :\n");
    printf("\t---> '(<<)' INDICATES THE SNAKE HEAD \n\t---> '(..>/<..)' INDICATES THE SNAKE TAIL.\n");
    printf("\n\n\t\t\tBEST OF LUCK\n\n");
    printf("\t- - - ENTER 'ENTER KEY' TO GO HOME: - - -");
    home = getch();
    if (home == 13)
    {
        snl_menu();
    }
    else
    {
        printf("\n\tENTER THE RIGHT KEY!!");
        Sleep(1500);
        snl_help();
    }
}
void snl_board()
{
    printf("\t ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ \n");
    printf("\t|      |      |      |      |      |      |      |<<*+  |      |      |\n");
    printf("\t| 100  |  99  |  98  |  97  |  96  |  95  |  94  |  93* |  92  |  91  |\n");
    printf("\t|______|______|_.*>>_|______|______|______|______|____*_|______|______|\n");
    printf("\t|      |      |  *   |      |      |      |      |    *.|      |      |\n");
    printf("\t|  81  |  82  |  *83 |  84  |  85  |  86  |  87  |  88  |+ 89  |  90  |\n");
    printf("\t|______|______| __*__|______|______|______|______|______|_*____|______|\n");
    printf("\t|      | <<**.|   *+.|      |      |      |      |      | .*   |      |\n");
    printf("\t|  80  |  79*.|  78  |*+ 77 |  76  |  75  |  74  |  73  |* 72  |  71  |\n");
    printf("\t|______|______|*_____|___*__|______|______|_+--+_|______|_*____|______|\n");
    printf("\t|      |      | .*   |    +*|      |      | +--+ |      |  *.. |      |\n");
    printf("\t|  61  |  62  |*.63  |  64* |  65  |  66  | +67+ |  68  |  69 *|  70  |\n");
    printf("\t|______|______|__*.__|____*_|______|______|_+--+_|______|______|*_____|\n");
    printf("\t|      |  .*>>|  <..*|     +|      |      | +--+ |      |      | .*   |\n");
    printf("\t|  60  | .59  |  58  |  57 *|  56  |  55  | +54+ | +53+ |  52  | * 51 |\n");
    printf("\t|______|__*.__|______|____*_|______|______|_+--+_|_+--+_|______|__*.__|\n");
    printf("\t|      |   *. |      |<..*  |      |      | +--+ | +--+ |      |   *. |\n");
    printf("\t|  41  |  42 *|  43  |  44  |  45  |  46  | +47+ | +48+ |  49  |  50 *|\n");
    printf("\t|______|_____*|______|______|______|______|_+--+_|_+--+_|______|____*_|\n");
    printf("\t|      |     *|      |      |      |      | +--+ | +--+ |      | <..* |\n");
    printf("\t|  40  |  39 *|  38  |  37  |  36  |  35  | +34+ |  33  |  32  |  31  |\n");
    printf("\t|______|_+--+*|______|______|______|______|_+--+_|______|______|______|\n");
    printf("\t|      | +--+ |*     |      |      |      | +--+ |      |      |      |\n");
    printf("\t|  21  | +22+ |* 23  |  24  |  25  |  26  |  27  |  28  |  29  |  30  |\n");
    printf("\t|______|_+--+_|_*____|______|___.>>|______|______|______|_+--+_|______|\n");
    printf("\t|      | +--+ |  *..>|      |    *.|      |      |      | +--+ |      |\n");
    printf("\t|  20  |  19  |  18  |  17  |  16 *|  15  |  14  |  13  | +12+ |  11  |\n");
    printf("\t|______|______|______|______|_____*|______|______|______|_+--+_|______|\n");
    printf("\t|      |      |      |      |    .*|      |      |      | +--+ |      |\n");
    printf("\t|  01  |  02  |  03  |  04  |  05 *|. 06  |  07  |  08  |  09  |  10  |\n");
    printf("\t|______|______|______|______|______|_*..>_|______|______|______|______|\n");
}
int snl_Die()
{
    srand(time(NULL));
    return rand() % 6 + 1;
}
int snl_gamer_1(int position_1)
{
    char roll;
    int dieroll;
    printf("\t\t- - - ENTER 'ENTER KEY' TO ROLL THE DIE: - - -");
    roll = getch();
    if (roll == 13)
    {
        dieroll = snl_Die();
        printf("\n\t\tYOU ROLLED %d ON YOUR DIE\n\n", dieroll);
        Sleep(1000);
    }
    else
    {
        printf("\n\t\tTURN SKIPPED!!\n\n");
    }
    if (position_1 + dieroll <= 100)
    {
        position_1 += dieroll;
        printf("\t\tPLAYER-1 MOVED TO POSITION %d.\n\n", position_1);
        if (position_1 == 93)
        {
            printf("\n\t\tPLAYER-1 ENCOUNTERED A SNAKE! MOVING DOWN...\"\n");
            position_1 = 31;
        }
        else if (position_1 == 25)
        {
            printf("\n\t\tPLAYER-1 ENCOUNTERED A SNAKE! MOVING DOWN...\"\n");
            position_1 = 6;
        }
        else if (position_1 == 79)
        {
            printf("\n\t\tPLAYER-1 ENCOUNTERED A SNAKE! MOVING DOWN...\"\n");
            position_1 = 58;
        }
        else if (position_1 == 59)
        {
            printf("\n\t\tPLAYER-1 ENCOUNTERED A SNAKE! MOVING DOWN...\"\n");
            position_1 = 18;
        }
        else if (position_1 == 98)
        {
            printf("\n\t\tPLAYER-1 ENCOUNTERED A SNAKE! MOVING DOWN...\"\n");
            position_1 = 44;
        }
        else if (position_1 == 33)
        {
            printf("\n\t\t\"PLAYER-1 FOUND A LADDER! MOVING UP...\"\n");
            position_1 = 53;
        }
        else if (position_1 == 9)
        {
            printf("\n\t\t\"PLAYER-1 FOUND A LADDER! MOVING UP...\"\n");
            position_1 = 29;
        }
        else if (position_1 == 27)
        {
            printf("\n\t\t\"PLAYER-1 FOUND A LADDER! MOVING UP...\"\n");
            position_1 = 74;
        }
        else if (position_1 == 19)
        {
            printf("\n\t\t\"PLAYER-1 FOUND A LADDER! MOVING UP...\"\n");
            position_1 = 42;
        }
    }
    else
    {
        printf("\n\t\t\"PLAYER-1 NEEDS %d TO WIN, BUT ROLLED %d. TURN SKIPPED.\"\n", 100 - position_1, dieroll);
    }
    Sleep(2500);
    return position_1;
}
int snl_gamer_2(int position_2)
{
    char roll;
    int dieroll;
    printf("\t\t- - - ENTER 'ANY KEY' TO ROLL THE DIE: - - -");
    roll = getch();
    if (roll == 13)
    {
        dieroll = snl_Die();
        printf("\n\t\tYOU ROLLED %d ON YOUR DIE\n\n", dieroll);
        Sleep(1000);
    }
    else
    {
        printf("\n\t\tTURN SKIPPED!!\n\n");
    }
    if (position_2 + dieroll <= 100)
    {
        position_2 += dieroll;
        printf("\t\tPLAYER-2 MOVED TO POSITION %d.\n", position_2);
        if (position_2 == 93)
        {
            printf("\n\t\tPLAYER-2 ENCOUNTERED A SNAKE! MOVING DOWN...\"\n");
            position_2 = 31;
        }
        else if (position_2 == 25)
        {
            printf("\n\t\tPLAYER-2 ENCOUNTERED A SNAKE! MOVING DOWN...\"\n");
            position_2 = 6;
        }
        else if (position_2 == 79)
        {
            printf("\n\t\tPLAYER-2 ENCOUNTERED A SNAKE! MOVING DOWN...\"\n");
            position_2 = 58;
        }
        else if (position_2 == 59)
        {
            printf("\n\t\tPLAYER-2 ENCOUNTERED A SNAKE! MOVING DOWN...\"\n");
            position_2 = 18;
        }
        else if (position_2 == 98)
        {
            printf("\n\t\tPLAYER-2 ENCOUNTERED A SNAKE! MOVING DOWN...\"\n");
            position_2 = 44;
        }
        else if (position_2 == 33)
        {
            printf("\n\t\t\"PLAYER-2 FOUND A LADDER! MOVING UP...\"\n");
            position_2 = 53;
        }
        else if (position_2 == 9)
        {
            printf("\n\t\t\"PLAYER-2 FOUND A LADDER! MOVING UP...\"\n");
            position_2 = 29;
        }
        else if (position_2 == 27)
        {
            printf("\n\t\t\"PLAYER-2 FOUND A LADDER! MOVING UP...\"\n");
            position_2 = 74;
        }
        else if (position_2 == 19)
        {
            printf("\n\t\t\"PLAYER-2 FOUND A LADDER! MOVING UP...\"\n");
            position_2 = 42;
        }
    }
    else
    {
        printf("\n\t\t\"PLAYER-2 NEEDS %d TO WIN, BUT ROLLED %d. TURN SKIPPED.\"\n", 100 - position_2, dieroll);
    }
    Sleep(2500);
    return position_2;
}
int snl_computer(int position_3)
{
    int dieroll = snl_Die();
    printf("\n\t\tCOMPUTER ROLLED %d ON HIS DIE\n\n", dieroll);
    Sleep(1500);
    if (position_3 + dieroll <= 100)
    {
        position_3 += dieroll;
        printf("\t\tCOMPUTER MOVED TO %d.\n", position_3);
        if (position_3 == 93)
        {
            printf("\n\t\t\"COMPUTER ENCOUNTERED A SNAKE! MOVING DOWN...\"\n");
            position_3 = 31;
        }
        else if (position_3 == 98)
        {
            printf("\n\t\t\"COMPUTER ENCOUNTERED A SNAKE! MOVING DOWN...\"\n");
            position_3 = 44;
        }
        else if (position_3 == 25)
        {
            printf("\n\t\tCOMPUTER ENCOUNTERED A SNAKE! MOVING DOWN...\"\n");
            position_3 = 6;
        }
        else if (position_3 == 79)
        {
            printf("\n\t\tCOMPUTER ENCOUNTERED A SNAKE! MOVING DOWN...\"\n");
            position_3 = 58;
        }
        else if (position_3 == 59)
        {
            printf("\n\t\tCOMPUTER ENCOUNTERED A SNAKE! MOVING DOWN...\"\n");
            position_3 = 18;
        }
        else if (position_3 == 27)
        {
            printf("\n\t\t\"COMPUTER HAD FOUND A LADDER! MOVING UP...\"\n");
            position_3 = 74;
        }
        else if (position_3 == 19)
        {
            printf("\n\t\t\"COMPUTER HAD FOUND A LADDER! MOVING UP...\"\n");
            position_3 = 42;
        }

        else if (position_3 == 33)
        {
            printf("\n\t\t\"COMPUTER FOUND A LADDER! MOVING UP...\"\n");
            position_3 = 53;
        }
        else if (position_3 == 9)
        {
            printf("\n\t\t\"COMPUTER FOUND A LADDER! MOVING UP...\"\n");
            position_3 = 29;
        }
    }
    else
    {
        printf("\n\t\t\"COMPUTER NEEDS %d TO WIN, BUT ROLLED %d. TURN SKIPPED.\"\n", 100 - position_3, dieroll);
    }
    Sleep(3000);

    return position_3;
}

// QUIZ GAME STARTS HERE

// HERE ARE ALL FUNCTIONS OF QUIZ GAME

// FOLLOW THROUGH

int Quiz_main()
{
    char choice;
    char player[100];
    int point = 0;
    char d;
HOME:
    system("cls");
    printf("\n\n\n\t\t\t          WELCOME TO MENTAL ABILITY GAME  \n\n\n");
    printf("\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
    printf("\t\t\t\t  ENTER 'S' TO START THE GAME.\n\n");
    printf("\t\t\t\t  ENTER 'H' FOR HELP.\n\n");
    printf("\t\t\t\t  ENTER 'Q' TO QUIT THE GAME.\n\n");
    printf("\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
    printf("\t\t\t          ENTER THE KEY...");
    choice = toupper(getch());
    if (choice == 'S')
    {
        system("cls");
        printf("\t\tENTER YOUR NAME...(one word)\n\n\t\t");
        scanf("%s", &player);
    play:
        point = Quiz_start();
    view:
        if (point > 80)
        {
            printf("\n\n\t\t\tYOU HAVE SECURED : %d POINTS", point);
            printf("\n\t\t\tEXCELLENT.");
        }
        else if (point <= 80 && point > 60)
        {
            printf("\n\n\t\t\tYOU HAVE SECURED : %d POINTS", point);
            printf("\n\t\t\tGOOD! BUT YOU NEED TO KNOW MORE.");
        }
        else if (point <= 60 && point > 40)
        {
            printf("\n\n\t\t\tYOU HAVE SECURED : %d POINTS", point);
            printf("\n\t\t\tWORK HARD TO REACH UPTO THE MARK.");
        }
        else if (point <= 40 && point > 20)
        {
            printf("\n\n\t\t\tYOU HAVE SECURED : %d POINTS", point);
            printf("\n\t\t\tSATISFACTORY RESULT (NOT UP TO THE MARK).");
        }
        else
        {
            printf("\n\n\t\t\tYOU HAVE SECURED : %d POINTS", point);
            printf("\n\t\t\tYOU ARE VERY POOR IN MENTAL ABILITY.");
        }
        printf("\n\n\t\t\tENTER 'L' KEY TO GO HOME ..\n\t\t\tENTER 'N' KEY TO PLAY AGIAN ..");
        d = toupper(getch());
        if (d == 'L')
        {
            goto HOME;
        }
        else if (d == 'N')
        {
            goto play;
        }
        else
        {
            printf("...\n\n\n\t\t\t..ENTER THE RIGHT KEY..");
            Sleep(1000);
            system("cls");
            goto view;
        }
    }
    else if (choice == 'H')
    {
        Quiz_help();
    }
    else if (choice == 'Q')
    {

        login_menu();
    }
    else
    {
        printf("...\n\n\n\t\t\t\t\t\t..ENTER THE RIGHT KEY..");
        Sleep(1000);
        goto HOME;
    }

    return 0;
}
int Quiz_help()
{
    char l;
help:
    system("cls");
    printf("\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
    printf("\t\t\t   HELLO!\n\n\t\t\t   WELCOME TO MENTAL ABILITY GAME...\n\n");
    printf("\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
    printf("\n\n\tHERE YOU ARE GOING TO GET 5 QUESTIONS.\n\n");
    printf("\tFOR EVERY QUESTION U ARE GOING TO GET 120 SECONDS IT IS FOR ANALYSING THE PROBLEM.\n\n");
    printf("\tYOU SHOULD ANSWER THE QUESTION BEFORE THE COMPLETION OF THE TIME GIVEN('120' SECONDS).\n\n");
    printf("\t\"DON'T ENTER ANY KEY DURING THE TIME IT MAY RECOGNISE AS YOUR OPTION.\"\n\n");
    printf("\tFOR EVERY CORRECT ANSWER U ARE GOING TO SCORE '20' POINTS.\n\n");
    printf("\tIF U SKIP THE QUESTION U WILL LOOSE '1' POINT.\n\n");
    printf("\tFOR WRONG ANSWER YOU ARE GOING TO LOOSE '5' POINTS.\n\n\n");
    printf("\t\t\t\t---ALL THE BEST---\t\n\n");
    printf("\t\t\t     ENTER 'L' KEY TO GO HOME..");
    l = toupper(getch());
    if (l == 'L')
    {
        Quiz_main();
    }
    else
    {
        printf("...\n\n\n\n\t\t\t     ..ENTER THE RIGHT KEY..");
        Sleep(1000);
        goto help;
    }
    return 0;
}
int Quiz_start()
{
    int number, key;
    char option;
    int score = 0;
    int i = 0;
start:
    system("cls");
    srand(time(NULL));
    number = (rand() % (25 - 1 + 1)) + 1;
    if (key == number)
    {
        goto start;
    }
    key = number;
    switch (key)
    {
    case 1:
        printf("\tQ.IF '*' STANDS FOR - , '/' STANDS FOR + , '+' STANDS FOR / , AND '-' STANDS FOR * THEN, WHICH ONE OF THE FOLLOWING IS CORRECT?\n\n");
        printf("\tA : 15 - 5 / 5 * 20 + 16 = 6\n\n\tB : 8 / 10 - 3 + 5 * 6 = 8\n\n\tC : 6 * 2 + 3 = 10\n\n\tD : SKIP");
        key = 1;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'B')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'D')
        {
            printf("\n\n\t OPTION 'B' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'B' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 2:
        printf("\tQ.IF Q MEANS 'ADD TO', J MEANS 'MULTIPLY BY', T MEANS 'SUBTRACT FROM' AND K MEANS 'DIVIDE BY', THEN \"26 K 2 Q 3 J 6 T 4\" = ?\n\n");
        printf("\tA : 27\n\n\tB : SKIP\n\n\tC : 28\n\n\tD : 30");
        key = 2;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'A')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'B')
        {
            printf("\n\n\t OPTION 'A' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'A' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 3:
        printf("\tQ.IF '*' MEANS + , '-' MEANS * , '/' MEANS + , '+' MEANS -, THEN \"(4 - 15 + 12) * 8 + 9 = ?\n\n");
        printf("\tA : 1\n\n\tB : SKIP\n\n\tC : 28\n\n\tD : 0");
        key = 3;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'D')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'B')
        {
            printf("\n\n\t OPTION 'D' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'D' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 4:
        printf("\tQ.IF 'L' DENOTES /, 'M' DENOTES *, 'P' DENOTES + AND 'Q' DENOTES -, THEN WHICH OF THE FOLLOWING STATEMENT IS TRUE ?\n\n");
        printf("\tA : 32 P 8 L 16 Q 4 = -2/3\n\n\tB : SKIP\n\n\tC : 9 P 9 L 9 Q 9 M 9 = -71\n\n\tD : 2 M 2 Q 2 L 2 P 2 = -8");
        key = 4;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'C')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'B')
        {
            printf("\n\n\t OPTION 'C' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'C' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 5:
        printf("\tQ.WHICH OF THE FOLLOWING EXPRESSIONS WILL BE TRUE IF THE EXPRESSION \" K = L > M =N \" IS DEFINITELY FALSE ?\n\n");
        printf("\tA : N = M\n\n\tB : K = L\n\n\tC : SKIP\n\n\tD : M = K");
        key = 5;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'D')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'C')
        {
            printf("\n\n\t OPTION 'D' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'D' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 6:
        printf("\tQ.'A' IS BROTHER OF 'B'.'C' IS SISTER OF 'A'.'D' IS BROTHER OF 'E'.'E' IS DAUGHTER OF 'B'.WHO IS UNCLE OF D ?\n\n");
        printf("\tA : 'A'\n\n\tB : 'B'\n\n\tC : SKIP\n\n\tD : 'C'");
        key = 6;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'B')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'D')
        {
            printf("\n\n\t OPTION 'B' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'B' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 7:
        printf("\tQ.'C' IS THE MOTHER OF A AND B. IF D IS THE HUSBAND OF 'B', THEN WHAT IS 'C' TO 'D' ?\n\n");
        printf("\tA : MOTHER\n\n\tB : SKIP\n\n\tC : MOTHER IN LAW\n\n\tD : SISTER");
        key = 7;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'C')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'B')
        {
            printf("\n\n\t OPTION 'C' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'C' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 8:
        printf("\tQ.'A' IS C's SON. 'C' AND 'Q' ARE SISTERS. 'Z' IS Q's MOTHER. P IS SON OF 'Z'. HOW IS 'P' RELATED TO 'A' ?\n\n");
        printf("\tA : MOTHER\n\n\tB : SKIP\n\n\tC : MOTHER-IN-LAW\n\n\tD : UNCLE");
        key = 8;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'D')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'B')
        {
            printf("\n\n\t OPTION 'D' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'D' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 9:
        printf("\tQ.'P' IS THE FATHER OF 'Q' AND 'R' IS SON OF 'S'.'T' IS THE BROTHER OF 'P'.'Q' IS THE SISTER OF 'R'. HOW IS S RELATED TO T ?\n\n");
        printf("\tA : DAUGHER-IN-LAW\n\n\tB : SKIP\n\n\tC : BROTHER-IN-LAW\n\n\tD : CAN'T DETERMINED");
        key = 9;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'D')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'B')
        {
            printf("\n\n\t OPTION 'D' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'D' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 10:
        printf("\tQ.'A' IS THE BROTHER OF 'B'.'B' IS THE BROTHER OF 'C'.'C' IS THE HUSBAND OF 'D'.'E' IS THE FATHER OF 'A', THEN HOW IS 'D' RELATED TO 'E' ?\n\n");
        printf("\tA : DAUGHTER-IN-LAW\n\n\tB : MOTHER-IN-LAW\n\n\tC : SKIP\n\n\tD : MOTHER");
        key = 10;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'A')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'C')
        {
            printf("\n\n\t OPTION 'A' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'A' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 11:
        printf("\tQ.FIND OUT HE NEXT SERIES NUMBER \"4 , 27 , 16 , 125 , 36 , ____ \" = ?\n\n");
        printf("\tA : 49\n\n\tB : 216\n\n\tC : SKIP\n\n\tD : 343");
        key = 11;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'D')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'C')
        {
            printf("\n\n\t OPTION 'D' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'D' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 12:
        printf("\tQ.FIND OUT HE NEXT SERIES NUMBER \"2 , 3 , 8 , 27 , ____\" = ?\n\n");
        printf("\tA : 216\n\n\tB : 106\n\n\tC : 112\n\n\tD : SKIP");
        key = 12;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'B')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'D')
        {
            printf("\n\n\t OPTION 'B' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'B' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 13:
        printf("\tQ.FIND OUT HE NEXT SERIES NUMBER \"3 , 15 , 75 , 375 , ____\" = ?\n\n");
        printf("\tA : 1875\n\n\tB : 1874\n\n\tC : SKIP\n\n\tD : 1873");
        key = 13;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'A')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'C')
        {
            printf("\n\n\t OPTION 'A' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'A' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 14:
        printf("\tQ.FIND OUT HE NEXT SERIES NUMBER \"63 , 124 , 215 , 342 , ____\" = ?\n\n");
        printf("\tA : 511\n\n\tB : SKIP\n\n\tC : 711\n\n\tD : 811");
        key = 14;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'A')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'B')
        {
            printf("\n\n\t OPTION 'A' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'A' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 15:
        printf("\tQ.FIND OUT HE NEXT SERIES NUMBER \"23 , 24 , 32 , 59 , ____\" = ?\n\n");
        printf("\tA : 143\n\n\tB : SKIP\n\n\tC : 69\n\n\tD : 123");
        key = 15;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'D')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'B')
        {
            printf("\n\n\t OPTION 'D' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'D' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 16:
        printf("\tQ.HOW MANY SQUARES ARE IN THE GIVEN FINGURE?\n\n");
        printf("\t    ____ ____ ____ ____    \n");
        printf("\t   |    |    |    |    |   \n");
        printf("\t   |||||   \n");
        printf("\t   |    |    |    |    |   \n");
        printf("\t   |||||   \n");
        printf("\t   |    |    |    |    |   \n");
        printf("\t   |||||   \n");
        printf("\t   |    |    |    |    |   \n");
        printf("\t   |||||   \n\n");
        printf("\tA : 17\n\n\tB : SKIP\n\n\tC : 30\n\n\tD : 25");
        key = 16;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'C')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'B')
        {
            printf("\n\n\t OPTION 'C' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'C' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 17:
        printf("\tQ.HOW MANY RECTANGLES ARE IN THE GIVEN FINGURE?\n\n");
        printf("\t ______________________ \n");
        printf("\t|          |     |     |\n");
        printf("\t||     |     |\n");
        printf("\t|          |     |     |\n");
        printf("\t||||\n");
        printf("\t|    |     |           |\n");
        printf("\t|    |     |_|\n");
        printf("\t|    |     |           |\n");
        printf("\t||||\n\n");
        printf("\tA : 16\n\n\tB : 21\n\n\tC : SKIP\n\n\tD : 2O");
        key = 17;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'A')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'C')
        {
            printf("\n\n\t OPTION 'A' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'A' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 18:
        printf("\tQ.HOW MANY SQUARES ARE IN THE GIVEN FINGURE?\n\n");
        printf("\t _____________ ____________ \n");
        printf("\t|             |            |\n");
        printf("\t|    ________|_______    |\n");
        printf("\t|   |         |        |   |\n");
        printf("\t|   |     ___|___    |   |\n");
        printf("\t|   |    |    |    |   |   |\n");
        printf("\t||||||_|\n");
        printf("\t|   |    |    |    |   |   |\n");
        printf("\t|   |    |||   |   |\n");
        printf("\t|   |         |        |   |\n");
        printf("\t|   ||_|   |\n");
        printf("\t|             |            |\n");
        printf("\t||_|\n\n");
        printf("\tA : 17\n\n\tB : 15\n\n\tC : SKIP\n\n\tD : 19");
        key = 18;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'B')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'C')
        {
            printf("\n\n\t OPTION 'B' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'B' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 19:
        printf("\tQ.HOW MANY QUADRILATERALS ARE THERE IN THESE GIVEN FIGURE?\n\n");
        printf("\t                  ________________________ \n");
        printf("\t                 |                        |\n");
        printf("\t                 |                        |\n");
        printf("\t            ____|______________         |\n");
        printf("\t           |     |     |         |        |\n");
        printf("\t           |     |     |         |        |\n");
        printf("\t _________|||||\n");
        printf("\t|          |     |     |         |        |\n");
        printf("\t|          |     ||||\n");
        printf("\t|          |           |         |\n");
        printf("\t|          |||\n");
        printf("\t|          |           |\n");
        printf("\t|          |           |\n");
        printf("\t|          |           |\n");
        printf("\t||_|\n\n");
        printf("\tA : 21\n\n\tB : SKIP\n\n\tC : 20\n\n\tD : 17");
        key = 19;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'D')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'B')
        {
            printf("\n\n\t OPTION 'D' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'D' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 20:
        printf("\tQ.THE RATIO OF BOYS AND GIRLS IN A SCHOOL IS 2:3.IF 30 % OF GIRLS IN \"6\" MORE THAN THE 30 % OF BOYS, THEN FIND THE TOTAL NUMBER OF STUDENTS IN THE SCHOOL ?\n\n");
        printf("\tA : 100\n\n\tB : SKIP\n\n\tC : 1000\n\n\tD : 1001");
        key = 20;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'C')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'B')
        {
            printf("\n\n\t OPTION 'C' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'C' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 21:
        printf("\tQ.THE AVERAGE OF '7' CONSECUTIVE NUMBERS IS 34, THEN FIND THE LAGEST OF THESE NUMBERS ?\n\n");
        printf("\tA : SKIP\n\n\tB : 69\n\n\tC : 137\n\n\tD : 37");
        key = 21;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'D')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'A')
        {
            printf("\n\n\t OPTION 'D' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'D' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 22:
        printf("\tQ.ONE DAY, RAVI LEFT HOME AND CYCLED 10KM SOUTHWARDS, TURNED RIGHT AND CYCLED 5KM AND TURNED RIGHT AND CYCLED 10 KM AND TURNED LEFT AND CYCLED 10KM.\n\tHOW MANY KILOMETERS WILL HE HAVE TO CYCLE TO REACH THIS HOME Straight ?\n\n");
        printf("\tA : 15\n\n\tB : skip\n\n\tC : 11\n\n\tD : 10");
        key = 22;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'A')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'A')
        {
            printf("\n\n\t OPTION 'A' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'A' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 23:
        printf("\tQ.KUNAL WALKS 10 KM TOWARDS NORTH. FROM THERE HE WALKS 6 KM TOWARDS SOUTH. THEN, HE WALKS 3KM TOWARDS EAST.\n\tHOW FAR AND IN WHICH DIRECTION IS HE WITH REFERENCE TO HIS STARTING POINT ?\n\n");
        printf("\tA : SKIP\n\n\tB : 7 KM NORTH-EAST\n\n\tC : 5 KM WEST-SOUTH\n\n\tD : 5 KM NORTH-EAST");
        key = 23;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'D')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'A')
        {
            printf("\n\n\t OPTION 'D' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'D' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 24:
        printf("\tQ.A RIVER FLOWS WEST TO EST AND ON THE WAY TURNS LEFT AND GOES IN A SEMI-CIRCLE ROUND A HILLOCK, AND THEN TURNS LEFT AT RIGHT ANGLES.\nN WHICH DIRECTION IS THE RIVER FINALLY FLOEING ?\n\n");
        printf("\tA : NORTH\n\n\tB :EAST \n\n\tC :WEST \n\n\tD : SKIP");
        key = 24;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'B')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'D')
        {
            printf("\n\n\t OPTION 'B' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'B' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    case 25:
        printf("\tQ.FIND OUT HE MISSING LETTER SEQUENCE:\"EG , ____ , KM , NP , QS\" = ?\n\n");
        printf("\tA : FH\n\n\tB : JH\n\n\tC : SKIP\n\n\tD : HJ");
        key = 25;
        Quiz_q_time();
        printf("\n\n\t ENTER THE OPTION:");
        option = toupper(getch());
        if (option == 'D')
        {
            printf("\n\n\t CORRECT!");
            score += 20;
        }
        else if (option == 'C')
        {
            printf("\n\n\t OPTION 'D' IS CORRECT.");
            score -= 1;
        }
        else
        {
            printf("\n\n\t WRONG!.OPTION 'D' IS CORRECT.");
            score -= 5;
        }
        Sleep(2000);
        system("cls");
        break;
    }
    i++;
    if (i < 5)
    {
        goto start;
    }
    return score;
}
int Quiz_q_time()
{
    int n;
    int c = 1;
    printf("\n\n\t\t\t------------------------------------\n\n");
home:
    if (c >= 0)
    {
        if (c == 120)
        {
            printf("\t\t\t\t\t");
        }
        printf("%d", c);
        Sleep(1000);
        if (c < 10)
        {
            printf("\b");
        }
        else if (c >= 100)
        {
            printf("\b\b\b");
        }

        else
        {
            printf("\b\b");
        }
        c--;
        goto home;
    }
    printf("\n\n\t\t\t------------------------------------\n\n");
    return 0;
}

// WORD GUESSING GAME

int word_guess_randint(int a, int b)
{
    /* return a random integer between the range a and b (b is exclusive). */
    int randomi = rand();
    // float per = ((float)randomi) / ((float)RAND_MAX);
    // return (int)(per * (b-a)) + a;
    return randomi % (b - a) + a;
}

char *word_guess_get_random_word()
{

    char words[][15] = {"abandon", "ability", "able", "abortion", "about", "above", "abroad", "absence", "absolute", "absolutely", "absorb", "abuse", "academic", "accept", "access", "accident", "accompany", "accomplish", "according", "account", "accurate", "accuse", "achieve", "achievement", "acid", "acknowledge", "acquire", "across", "action", "active", "activist", "activity", "actor", "actress", "actual", "actually", "adapt", "addition", "additional", "address", "adequate", "adjust", "adjustment", "administration", "administrator", "admire", "admission", "admit", "adolescent", "adopt", "adult", "advance", "advanced", "advantage", "adventure", "advertising", "advice", "advise", "adviser", "advocate", "affair", "affect", "afford", "afraid", "after", "afternoon", "again", "against", "agency", "agenda", "agent", "aggressive", "agree", "agreement", "agricultural", "ahead", "aide", "aircraft", "airline", "airport", "album", "alcohol", "alive", "alliance", "allow", "ally", "almost", "alone", "along", "already", "also", "alter", "alternative", "although", "always", "amazing", "among", "amount", "analysis", "analyst", "analyze", "ancient", "anger", "angle", "angry", "animal", "anniversary", "announce", "annual", "another", "answer", "anticipate", "anxiety", "anybody", "anymore", "anyone", "anything", "anyway", "anywhere", "apart", "apartment", "apparent", "apparently", "appeal", "appear", "appearance", "apple", "application", "apply", "appoint", "appointment", "appreciate", "approach", "appropriate", "approval", "approve", "approximately", "architect", "area", "argue", "argument", "arise", "armed", "army", "around", "arrange", "arrangement", "arrest", "arrival", "arrive", "article", "artist", "artistic", "aside", "asleep", "aspect", "assault", "assert", "assess", "assessment", "asset", "assign", "assignment", "assist", "assistance", "assistant", "associate", "association", "assume", "assumption", "assure", "athlete", "athletic", "atmosphere", "attach", "attack", "attempt", "attend", "attention", "attitude", "attorney", "attract", "attractive", "attribute", "audience", "author", "authority", "auto", "available", "average", "avoid", "award", "aware", "awareness", "away", "awful", "baby", "back", "background", "badly", "bake", "balance", "ball", "band", "bank", "barely", "barrel", "barrier", "base", "baseball", "basic", "basically", "basis", "basket", "basketball", "bathroom", "battery", "battle", "beach", "bean", "bear", "beat", "beautiful", "beauty", "because", "become", "bedroom", "beer", "before", "begin", "beginning", "behavior", "behind", "being", "belief", "believe", "bell", "belong", "below", "belt", "bench", "bend", "beneath", "benefit", "beside", "besides", "best", "better", "between", "beyond", "bike", "bill", "billion", "bind", "biological", "bird", "birth", "birthday", "bite", "black", "blade", "blame", "blanket", "blind", "block", "blood", "blow", "blue", "board", "boat", "body", "bomb", "bombing", "bond", "bone", "book", "boom", "boot", "border", "born", "borrow", "boss", "both", "bother", "bottle", "bottom", "boundary", "bowl", "boyfriend", "brain", "branch", "brand", "bread", "break", "breakfast", "breast", "breath", "breathe", "brick", "bridge", "brief", "briefly", "bright", "brilliant", "bring", "broad", "broken", "brother", "brown", "brush", "buck", "budget", "build", "building", "bullet", "bunch", "burden", "burn", "bury", "business", "busy", "butter", "button", "buyer", "cabin", "cabinet", "cable", "cake", "calculate", "call", "camera", "camp", "campaign", "campus", "cancer", "candidate", "capability", "capable", "capacity", "capital", "captain", "capture", "carbon", "card", "care", "career", "careful", "carefully", "carrier", "carry", "case", "cash", "cast", "catch", "category", "cause", "ceiling", "celebrate", "celebration", "celebrity", "cell", "center", "central", "century", "ceremony", "certain", "certainly", "chain", "chair", "chairman", "challenge", "chamber", "champion", "championship", "chance", "change", "changing", "channel", "chapter", "character", "characteristic", "characterize", "charge", "charity", "chart", "chase", "cheap", "check", "cheek", "cheese", "chef", "chemical", "chest", "chicken", "chief", "child", "childhood", "chip", "chocolate", "choice", "cholesterol", "choose", "church", "cigarette", "circle", "circumstance", "cite", "citizen", "city", "civil", "civilian", "claim", "class", "classic", "classroom", "clean", "clear", "clearly", "client", "climate", "climb", "clinic", "clinical", "clock", "close", "closely", "closer", "clothes", "clothing", "cloud", "club", "clue", "cluster", "coach", "coal", "coalition", "coast", "coat", "code", "coffee", "cognitive", "cold", "collapse", "colleague", "collect", "collection", "collective", "college", "colonial", "color", "column", "combination", "combine", "come", "comedy", "comfort", "comfortable", "command", "commander", "comment", "commercial", "commission", "commit", "commitment", "committee", "common", "communicate", "communication", "community", "company", "compare", "comparison", "compete", "competition", "competitive", "competitor", "complain", "complaint", "complete", "completely", "complex", "complicated", "component", "compose", "composition", "comprehensive", "computer", "concentrate", "concentration", "concept", "concern", "concerned", "concert", "conclude", "conclusion", "concrete", "condition", "conduct", "conference", "confidence", "confident", "confirm", "conflict", "confront", "confusion", "congressional", "connect", "connection", "consciousness", "consensus", "consequence", "conservative", "consider", "considerable", "consideration", "consist", "consistent", "constant", "constantly", "constitute", "constitutional", "construct", "construction", "consultant", "consume", "consumer", "consumption", "contact", "contain", "container", "contemporary", "content", "contest", "context", "continue", "continued", "contract", "contrast", "contribute", "contribution", "control", "controversial", "controversy", "convention", "conventional", "conversation", "convert", "conviction", "convince", "cook", "cookie", "cooking", "cool", "cooperation", "cope", "copy", "core", "corn", "corner", "corporate", "corporation", "correct", "correspondent", "cost", "cotton", "couch", "could", "council", "counselor", "count", "counter", "country", "county", "couple", "courage", "course", "court", "cousin", "cover", "coverage", "crack", "craft", "crash", "crazy", "cream", "create", "creation", "creative", "creature", "credit", "crew", "crime", "criminal", "crisis", "criteria", "critic", "critical", "criticism", "criticize", "crop", "cross", "crowd", "crucial", "cultural", "culture", "curious", "current", "currently", "curriculum", "custom", "customer", "cycle", "daily", "damage", "dance", "danger", "dangerous", "dare", "dark", "darkness", "data", "date", "daughter", "dead", "deal", "dealer", "dear", "death", "debate", "debt", "decade", "decide", "decision", "deck", "declare", "decline", "decrease", "deep", "deeply", "deer", "defeat", "defend", "defendant", "defense", "defensive", "deficit", "define", "definitely", "definition", "degree", "delay", "deliver", "delivery", "demand", "democracy", "democratic", "demonstrate", "demonstration", "deny", "department", "depend", "dependent", "depending", "depict", "depression", "depth", "deputy", "derive", "describe", "description", "desert", "deserve", "design", "designer", "desire", "desk", "desperate", "despite", "destroy", "destruction", "detail", "detailed", "detect", "determine", "develop", "developing", "development", "device", "devote", "dialogue", "diet", "differ", "difference", "different", "differently", "difficult", "difficulty", "digital", "dimension", "dining", "dinner", "direct", "direction", "directly", "director", "dirt", "dirty", "disability", "disagree", "disappear", "disaster", "discipline", "discourse", "discover", "discovery", "discrimination", "discuss", "discussion", "disease", "dish", "dismiss", "disorder", "display", "dispute", "distance", "distant", "distinct", "distinction", "distinguish", "distribute", "distribution", "district", "diverse", "diversity", "divide", "division", "divorce", "doctor", "document", "domestic", "dominant", "dominate", "door", "double", "doubt", "down", "downtown", "dozen", "draft", "drag", "drama", "dramatic", "dramatically", "draw", "drawing", "dream", "dress", "drink", "drive", "driver", "drop", "drug", "during", "dust", "duty", "each", "eager", "early", "earn", "earnings", "earth", "ease", "easily", "east", "eastern", "easy", "economic", "economics", "economist", "economy", "edge", "edition", "editor", "educate", "education", "educational", "educator", "effect", "effective", "effectively", "efficiency", "efficient", "effort", "eight", "either", "elderly", "elect", "election", "electric", "electricity", "electronic", "element", "elementary", "eliminate", "elite", "else", "elsewhere", "embrace", "emerge", "emergency", "emission", "emotion", "emotional", "emphasis", "emphasize", "employ", "employee", "employer", "employment", "empty", "enable", "encounter", "encourage", "enemy", "energy", "enforcement", "engage", "engine", "engineer", "engineering", "enhance", "enjoy", "enormous", "enough", "ensure", "enter", "enterprise", "entertainment", "entire", "entirely", "entrance", "entry", "environment", "environmental", "episode", "equal", "equally", "equipment", "error", "escape", "especially", "essay", "essential", "essentially", "establish", "establishment", "estate", "estimate", "ethics", "ethnic", "evaluate", "evaluation", "even", "evening", "event", "eventually", "ever", "every", "everybody", "everyday", "everyone", "everything", "everywhere", "evidence", "evolution", "evolve", "exact", "exactly", "examination", "examine", "example", "exceed", "excellent", "except", "exception", "exchange", "exciting", "executive", "exercise", "exhibit", "exhibition", "exist", "existence", "existing", "expand", "expansion", "expect", "expectation", "expense", "expensive", "experience", "experiment", "expert", "explain", "explanation", "explode", "explore", "explosion", "expose", "exposure", "express", "expression", "extend", "extension", "extensive", "extent", "external", "extra", "extraordinary", "extreme", "extremely", "fabric", "face", "facility", "fact", "factor", "factory", "faculty", "fade", "fail", "failure", "fair", "fairly", "faith", "fall", "false", "familiar", "family", "famous", "fantasy", "farm", "farmer", "fashion", "fast", "fate", "father", "fault", "favor", "favorite", "fear", "feature", "federal", "feed", "feel", "feeling", "fellow", "female", "fence", "fewer", "fiber", "fiction", "field", "fifteen", "fifth", "fifty", "fight", "fighter", "fighting", "figure", "file", "fill", "film", "final", "finally", "finance", "financial", "find", "finding", "fine", "finger", "finish", "fire", "firm", "first", "fish", "fishing", "fitness", "five", "flag", "flame", "flat", "flavor", "flee", "flesh", "flight", "float", "floor", "flow", "flower", "focus", "folk", "follow", "following", "food", "foot", "football", "force", "foreign", "forest", "forever", "forget", "form", "formal", "formation", "former", "formula", "forth", "fortune", "forward", "found", "foundation", "founder", "four", "fourth", "frame", "framework", "free", "freedom", "freeze", "frequency", "frequent", "frequently", "fresh", "friend", "friendly", "friendship", "from", "front", "fruit", "frustration", "fuel", "full", "fully", "function", "fund", "fundamental", "funding", "funeral", "funny", "furniture", "furthermore", "future", "gain", "galaxy", "gallery", "game", "gang", "garage", "garden", "garlic", "gate", "gather", "gaze", "gear", "gender", "gene", "general", "generally", "generate", "generation", "genetic", "gentleman", "gently", "gesture", "ghost", "giant", "gift", "gifted", "girl", "girlfriend", "give", "given", "glad", "glance", "glass", "global", "glove", "goal", "gold", "golden", "golf", "good", "government", "governor", "grab", "grade", "gradually", "graduate", "grain", "grand", "grandfather", "grandmother", "grant", "grass", "grave", "gray", "great", "greatest", "green", "grocery", "ground", "group", "grow", "growing", "growth", "guarantee", "guard", "guess", "guest", "guide", "guideline", "guilty", "habit", "habitat", "hair", "half", "hall", "hand", "handful", "handle", "hang", "happen", "happy", "hard", "hardly", "hate", "have", "head", "headline", "headquarters", "health", "healthy", "hear", "hearing", "heart", "heat", "heaven", "heavily", "heavy", "heel", "height", "helicopter", "hell", "hello", "help", "helpful", "here", "heritage", "hero", "herself", "hide", "high", "highlight", "highly", "highway", "hill", "himself", "hire", "historian", "historic", "historical", "history", "hold", "hole", "holiday", "holy", "home", "homeless", "honest", "honey", "honor", "hope", "horizon", "horror", "horse", "hospital", "host", "hotel", "hour", "house", "household", "housing", "however", "huge", "human", "humor", "hundred", "hungry", "hunter", "hunting", "hurt", "husband", "hypothesis", "idea", "ideal", "identification", "identify", "identity", "ignore", "illegal", "illness", "illustrate", "image", "imagination", "imagine", "immediate", "immediately", "immigrant", "immigration", "impact", "implement", "implication", "imply", "importance", "important", "impose", "impossible", "impress", "impression", "impressive", "improve", "improvement", "incentive", "incident", "include", "including", "income", "incorporate", "increase", "increased", "increasing", "increasingly", "incredible", "indeed", "independence", "independent", "index", "indicate", "indication", "individual", "industrial", "industry", "infant", "infection", "inflation", "influence", "inform", "information", "ingredient", "initial", "initially", "initiative", "injury", "inner", "innocent", "inquiry", "inside", "insight", "insist", "inspire", "install", "instance", "instead", "institution", "institutional", "instruction", "instructor", "instrument", "insurance", "intellectual", "intelligence", "intend", "intense", "intensity", "intention", "interaction", "interest", "interested", "interesting", "internal", "international", "interpret", "interpretation", "intervention", "interview", "into", "introduce", "introduction", "invasion", "invest", "investigate", "investigation", "investigator", "investment", "investor", "invite", "involve", "involved", "involvement", "iron", "island", "issue", "item", "itself", "jacket", "jail", "join", "joint", "joke", "journal", "journalist", "journey", "judge", "judgment", "juice", "jump", "junior", "jury", "just", "justice", "justify", "keep", "kick", "kill", "killer", "killing", "kind", "king", "kiss", "kitchen", "knee", "knife", "knock", "know", "knowledge", "label", "labor", "laboratory", "lack", "lady", "lake", "land", "landscape", "language", "large", "largely", "last", "late", "later", "latter", "laugh", "launch", "lawn", "lawsuit", "lawyer", "layer", "lead", "leader", "leadership", "leading", "leaf", "league", "lean", "learn", "learning", "least", "leather", "leave", "left", "legacy", "legal", "legend", "legislation", "legitimate", "lemon", "length", "less", "lesson", "letter", "level", "liberal", "library", "license", "life", "lifestyle", "lifetime", "lift", "light", "like", "likely", "limit", "limitation", "limited", "line", "link", "list", "listen", "literally", "literary", "literature", "little", "live", "living", "load", "loan", "local", "locate", "location", "lock", "long", "look", "loose", "lose", "loss", "lost", "lots", "loud", "love", "lovely", "lover", "lower", "luck", "lucky", "lunch", "lung", "machine", "magazine", "mail", "main", "mainly", "maintain", "maintenance", "major", "majority", "make", "maker", "makeup", "male", "mall", "manage", "management", "manager", "manner", "manufacturer", "manufacturing", "many", "margin", "mark", "market", "marketing", "marriage", "married", "marry", "mask", "mass", "massive", "master", "match", "material", "math", "matter", "maybe", "mayor", "meal", "mean", "meaning", "meanwhile", "measure", "measurement", "meat", "mechanism", "media", "medical", "medication", "medicine", "medium", "meet", "meeting", "member", "membership", "memory", "mental", "mention", "menu", "mere", "merely", "mess", "message", "metal", "meter", "method", "middle", "might", "military", "milk", "million", "mind", "mine", "minister", "minor", "minority", "minute", "miracle", "mirror", "miss", "missile", "mission", "mistake", "mixture", "mode", "model", "moderate", "modern", "modest", "moment", "money", "monitor", "month", "mood", "moon", "moral", "more", "moreover", "morning", "mortgage", "most", "mostly", "mother", "motion", "motivation", "motor", "mount", "mountain", "mouse", "mouth", "move", "movement", "movie", "much", "multiple", "murder", "muscle", "museum", "music", "musical", "musician", "must", "mutual", "myself", "mystery", "myth", "naked", "name", "narrative", "narrow", "nation", "national", "native", "natural", "naturally", "nature", "near", "nearby", "nearly", "necessarily", "necessary", "neck", "need", "negative", "negotiate", "negotiation", "neighbor", "neighborhood", "neither", "nerve", "nervous", "network", "never", "nevertheless", "newly", "news", "newspaper", "next", "nice", "night", "nine", "nobody", "noise", "nomination", "none", "nonetheless", "normal", "normally", "north", "northern", "nose", "note", "nothing", "notice", "notion", "novel", "nowhere", "nuclear", "number", "numerous", "nurse", "object", "objective", "obligation", "observation", "observe", "observer", "obtain", "obvious", "obviously", "occasion", "occasionally", "occupation", "occupy", "occur", "ocean", "odds", "offense", "offensive", "offer", "office", "officer", "official", "often", "okay", "once", "ongoing", "onion", "online", "only", "onto", "open", "opening", "operate", "operating", "operation", "operator", "opinion", "opponent", "opportunity", "oppose", "opposite", "opposition", "option", "orange", "order", "ordinary", "organic", "organization", "organize", "orientation", "origin", "original", "originally", "other", "others", "otherwise", "ought", "ourselves", "outcome", "outside", "oven", "over", "overall", "overcome", "overlook", "owner", "pace", "pack", "package", "page", "pain", "painful", "paint", "painter", "painting", "pair", "pale", "palm", "panel", "pant", "paper", "parent", "park", "parking", "part", "participant", "participate", "participation", "particular", "particularly", "partly", "partner", "partnership", "party", "pass", "passage", "passenger", "passion", "past", "patch", "path", "patient", "pattern", "pause", "payment", "peace", "peak", "peer", "penalty", "people", "pepper", "perceive", "percentage", "perception", "perfect", "perfectly", "perform", "performance", "perhaps", "period", "permanent", "permission", "permit", "person", "personal", "personality", "personally", "personnel", "perspective", "persuade", "phase", "phenomenon", "philosophy", "phone", "photo", "photograph", "photographer", "phrase", "physical", "physically", "physician", "piano", "pick", "picture", "piece", "pile", "pilot", "pine", "pink", "pipe", "pitch", "place", "plan", "plane", "planet", "planning", "plant", "plastic", "plate", "platform", "play", "player", "please", "pleasure", "plenty", "plot", "plus", "pocket", "poem", "poet", "poetry", "point", "pole", "police", "policy", "political", "politically", "politician", "politics", "poll", "pollution", "pool", "poor", "popular", "population", "porch", "port", "portion", "portrait", "portray", "pose", "position", "positive", "possess", "possibility", "possible", "possibly", "post", "potato", "potential", "potentially", "pound", "pour", "poverty", "powder", "power", "powerful", "practical", "practice", "pray", "prayer", "precisely", "predict", "prefer", "preference", "pregnancy", "pregnant", "preparation", "prepare", "prescription", "presence", "present", "presentation", "preserve", "president", "presidential", "press", "pressure", "pretend", "pretty", "prevent", "previous", "previously", "price", "pride", "priest", "primarily", "primary", "prime", "principal", "principle", "print", "prior", "priority", "prison", "prisoner", "privacy", "private", "probably", "problem", "procedure", "proceed", "process", "produce", "producer", "product", "production", "profession", "professional", "professor", "profile", "profit", "program", "progress", "project", "prominent", "promise", "promote", "prompt", "proof", "proper", "properly", "property", "proportion", "proposal", "propose", "proposed", "prosecutor", "prospect", "protect", "protection", "protein", "protest", "proud", "prove", "provide", "provider", "province", "provision", "psychological", "psychologist", "psychology", "public", "publication", "publicly", "publish", "publisher", "pull", "punishment", "purchase", "pure", "purpose", "pursue", "push", "qualify", "quality", "quarter", "quarterback", "question", "quick", "quickly", "quiet", "quietly", "quit", "quite", "quote", "race", "racial", "radical", "radio", "rail", "rain", "raise", "range", "rank", "rapid", "rapidly", "rare", "rarely", "rate", "rather", "rating", "ratio", "reach", "react", "reaction", "read", "reader", "reading", "ready", "real", "reality", "realize", "really", "reason", "reasonable", "recall", "receive", "recent", "recently", "recipe", "recognition", "recognize", "recommend", "recommendation", "record", "recording", "recover", "recovery", "recruit", "reduce", "reduction", "refer", "reference", "reflect", "reflection", "reform", "refugee", "refuse", "regard", "regarding", "regardless", "regime", "region", "regional", "register", "regular", "regularly", "regulate", "regulation", "reinforce", "reject", "relate", "relation", "relationship", "relative", "relatively", "relax", "release", "relevant", "relief", "religion", "religious", "rely", "remain", "remaining", "remarkable", "remember", "remind", "remote", "remove", "repeat", "repeatedly", "replace", "reply", "report", "reporter", "represent", "representation", "representative", "reputation", "request", "require", "requirement", "research", "researcher", "resemble", "reservation", "resident", "resist", "resistance", "resolution", "resolve", "resort", "resource", "respect", "respond", "respondent", "response", "responsibility", "responsible", "rest", "restaurant", "restore", "restriction", "result", "retain", "retire", "retirement", "return", "reveal", "revenue", "review", "revolution", "rhythm", "rice", "rich", "ride", "rifle", "right", "ring", "rise", "risk", "river", "road", "rock", "role", "roll", "romantic", "roof", "room", "root", "rope", "rose", "rough", "roughly", "round", "route", "routine", "rule", "running", "rural", "rush", "sacred", "safe", "safety", "sake", "salad", "salary", "sale", "sales", "salt", "same", "sample", "sanction", "sand", "satellite", "satisfaction", "satisfy", "sauce", "save", "saving", "scale", "scandal", "scared", "scenario", "scene", "schedule", "scheme", "scholar", "scholarship", "school", "science", "scientific", "scientist", "scope", "score", "scream", "screen", "script", "search", "season", "seat", "second", "secret", "secretary", "section", "sector", "secure", "security", "seed", "seek", "seem", "segment", "seize", "select", "selection", "self", "sell", "senator", "send", "senior", "sense", "sensitive", "sentence", "separate", "sequence", "series", "serious", "seriously", "serve", "service", "session", "setting", "settle", "settlement", "seven", "several", "severe", "sexual", "shade", "shadow", "shake", "shall", "shape", "share", "sharp", "sheet", "shelf", "shell", "shelter", "shift", "shine", "ship", "shirt", "shit", "shock", "shoe", "shoot", "shooting", "shop", "shopping", "shore", "short", "shortly", "shot", "should", "shoulder", "shout", "show", "shower", "shrug", "shut", "sick", "side", "sigh", "sight", "sign", "signal", "significance", "significant", "significantly", "silence", "silent", "silver", "similar", "similarly", "simple", "simply", "since", "sing", "singer", "single", "sink", "sister", "site", "situation", "size", "skill", "skin", "slave", "sleep", "slice", "slide", "slight", "slightly", "slip", "slow", "slowly", "small", "smart", "smell", "smile", "smoke", "smooth", "snap", "snow", "soccer", "social", "society", "soft", "software", "soil", "solar", "soldier", "solid", "solution", "solve", "some", "somebody", "somehow", "someone", "something", "sometimes", "somewhat", "somewhere", "song", "soon", "sophisticated", "sorry", "sort", "soul", "sound", "soup", "source", "south", "southern", "space", "speak", "speaker", "special", "specialist", "species", "specific", "specifically", "speech", "speed", "spend", "spending", "spin", "spirit", "spiritual", "split", "spokesman", "sport", "spot", "spread", "spring", "square", "squeeze", "stability", "stable", "staff", "stage", "stair", "stake", "stand", "standard", "standing", "star", "stare", "start", "state", "statement", "station", "statistics", "status", "stay", "steady", "steal", "steel", "step", "stick", "still", "stir", "stock", "stomach", "stone", "stop", "storage", "store", "storm", "story", "straight", "strange", "stranger", "strategic", "strategy", "stream", "street", "strength", "strengthen", "stress", "stretch", "strike", "string", "strip", "stroke", "strong", "strongly", "structure", "struggle", "student", "studio", "study", "stuff", "stupid", "style", "subject", "submit", "subsequent", "substance", "substantial", "succeed", "success", "successful", "successfully", "such", "sudden", "suddenly", "suffer", "sufficient", "sugar", "suggest", "suggestion", "suicide", "suit", "summer", "summit", "super", "supply", "support", "supporter", "suppose", "supposed", "sure", "surely", "surface", "surgery", "surprise", "surprised", "surprising", "surprisingly", "surround", "survey", "survival", "survive", "survivor", "suspect", "sustain", "swear", "sweep", "sweet", "swim", "swing", "switch", "symbol", "symptom", "system", "table", "tablespoon", "tactic", "tail", "take", "tale", "talent", "talk", "tall", "tank", "tape", "target", "task", "taste", "taxpayer", "teach", "teacher", "teaching", "team", "tear", "teaspoon", "technical", "technique", "technology", "teen", "teenager", "telephone", "telescope", "television", "tell", "temperature", "temporary", "tend", "tendency", "tennis", "tension", "tent", "term", "terms", "terrible", "territory", "terror", "terrorism", "terrorist", "test", "testify", "testimony", "testing", "text", "than", "thank", "thanks", "that", "theater", "their", "them", "theme", "themselves", "then", "theory", "therapy", "there", "therefore", "these", "they", "thick", "thin", "thing", "think", "thinking", "third", "thirty", "this", "those", "though", "thought", "thousand", "threat", "threaten", "three", "throat", "through", "throughout", "throw", "thus", "ticket", "tight", "time", "tiny", "tire", "tired", "tissue", "title", "tobacco", "today", "together", "tomato", "tomorrow", "tone", "tongue", "tonight", "tool", "tooth", "topic", "toss", "total", "totally", "touch", "tough", "tour", "tourist", "tournament", "toward", "towards", "tower", "town", "trace", "track", "trade", "tradition", "traditional", "traffic", "tragedy", "trail", "train", "training", "transfer", "transform", "transformation", "transition", "translate", "transportation", "travel", "treat", "treatment", "treaty", "tree", "tremendous", "trend", "trial", "tribe", "trick", "trip", "troop", "trouble", "truck", "true", "truly", "trust", "truth", "tube", "tunnel", "turn", "twelve", "twenty", "twice", "twin", "type", "typical", "typically", "ugly", "ultimate", "ultimately", "unable", "uncle", "under", "undergo", "understand", "understanding", "unfortunately", "uniform", "union", "unique", "unit", "universal", "universe", "university", "unknown", "unless", "unlike", "unlikely", "until", "unusual", "upon", "upper", "urban", "urge", "used", "useful", "user", "usual", "usually", "utility", "vacation", "valley", "valuable", "value", "variable", "variation", "variety", "various", "vary", "vast", "vegetable", "vehicle", "venture", "version", "versus", "very", "vessel", "veteran", "victim", "victory", "video", "view", "viewer", "village", "violate", "violation", "violence", "violent", "virtually", "virtue", "virus", "visible", "vision", "visit", "visitor", "visual", "vital", "voice", "volume", "volunteer", "vote", "voter", "vulnerable", "wage", "wait", "wake", "walk", "wall", "wander", "want", "warm", "warn", "warning", "wash", "waste", "watch", "water", "wave", "weak", "wealth", "wealthy", "weapon", "wear", "weather", "wedding", "week", "weekend", "weekly", "weigh", "weight", "welcome", "welfare", "well", "west", "western", "what", "whatever", "wheel", "when", "whenever", "where", "whereas", "whether", "which", "while", "whisper", "white", "whole", "whom", "whose", "wide", "widely", "widespread", "wife", "wild", "will", "willing", "wind", "window", "wine", "wing", "winner", "winter", "wipe", "wire", "wisdom", "wise", "wish", "with", "withdraw", "within", "without", "witness", "woman", "wonder", "wonderful", "wood", "wooden", "word", "work", "worker", "working", "works", "workshop", "world", "worried", "worry", "worth", "would", "wound", "wrap", "write", "writer", "writing", "wrong", "yard", "yeah", "year", "yell", "yellow", "yesterday", "yield", "young", "your", "yours", "yourself", "youth", "zone"};
    int len = 2746;
    int index = word_guess_randint(0, len);
    char *word = words[index];
    return word;
}

int word_guess_main()
{

    // start
    srand(time(NULL));
    system("cls");
    printf("Welcome to the Best Guessing Game!\n");
    printf("Presss Enter to Start:\n");
    getch();
    fflush(stdin);
    printf("\n");

    int round = 0;

    // get guess word.
    char *word = word_guess_get_random_word();
    int len = strlen(word);
    char *guess = (char *)malloc((len + 1) * sizeof(char));
    char *curr_guess = (char *)malloc((len + 1) * sizeof(char));

    // fill with "_"
    for (int i = 0; i < len; i++)
    {
        guess[i] = '_';
    }
    guess[len] = '\0';

    while (1)
    {

        // round start
        round++;
        printf("\nRound: %d\n", round);
        printf("Your word is:\n>> %s\n", guess);
        printf("Enter guess:\n>> ");
        fgets(curr_guess, len + 1, stdin);
        fflush(stdin);

        // check guess
        if (stricmp(word, curr_guess) == 0)
        {
            printf("\nCongrats You Guess it correctly!!!\n");
            float score = ((float)len) / ((float)round) * 10;
            printf("Your Score is: %f\n", score);
            printf("Thanks for Playing!\n");
            break;
        }
        else
        {
            printf("Wrong Guess :(, Try again.\n");
        }

        // add hint
        if (round >= len)
        {
            continue;
        }
        while (1)
        {

            int index = word_guess_randint(0, len);
            char target = guess[index];
            if (target == '_')
            {
                guess[index] = word[index];
                break;
            }
        }
    }
}