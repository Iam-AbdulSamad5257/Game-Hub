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
            int loading();
            gamehub_menu();
            gamehub_menu_function();
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
int index = 0;

int ttt();
void menu();
void gameboard();
int reset_board(int gameboard);
void DECISION();
int start();
void help();
int gamers_turn();
int winning_condition(int turn);
int main_ttt();

// ROCK PAPER SCISSORS VARIABLES AND FUNTION DECLARATIONS
char rps_player[15];
int rps_intro();
int rps_game();
int rps_main();

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
    else if (win == 2 || win == 1 && draw == 2 || win == 3) // CONDITIONS FOR WINNING
    {
        sound();
        printf("\033[0;32m");
        printf("\t\t\t *CONGRATULATIONS, YOU HAVE WON THIS GAME WITH TOTAL OF POINTS %d*\n\n", win);
        printf("\033[0m");
    }
    else
    {
        sound();
        printf("\033[0;32m");
        printf("\t\t\t *OOPS! YOU LOST BETTER LUCK NEXT TIME*\n\n"); // PLAYER LOSES THE GAME
        printf("\033[0m");
    }

    while (1)
    {
        printf("\t\t\tDO YOU WANT TO PLAY AGAIN ? (Y/N): "); // REPETITION
        sound();
        char again = toupper(getch());
        if (again == 'Y')
        {
            system("cls");
            rps_game();
        }
        else if (again == 'N')
        {
            printf("\nTHANK YOU FOR PLAYING...\n\n");
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
