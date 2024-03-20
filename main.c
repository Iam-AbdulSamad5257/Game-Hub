#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

void gamehub_menu();         // main menu - shows game hub with sign up and login option
int gamehub_menu_function(); // takes input for signup and login options
void takepass();             // take first time (or) new password from user with masking of '*'
int signup();                // take confirmation password from user with masking of '*'
int login();                 // not defined yet

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
    int ch = 177;   //space ascii value
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\tPLEASE WAIT, LOADING...\n\t\t\t\t");
    for (int i = 0; i < 80; i++)
    {
        green();
        printf("%c", ch); //prints coloured spaces
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
    char pass[9];
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
        if (ch == '1')
        {
            clear_screen();
            // loading();
            signup();
            break;
        }
        else if (ch == '2')
        {
            clear_screen();
            printf("bye");
            // login();
            while (1)
            {    
            printf("\n\n\t\tPRESS 'B' TO RETURN TO MAIN MENU : ");
            ch = toupper(getch());
             if (ch == 'B')
                {
                    // loading();
                    main();
                    break;
                }
                else
                {
                    printf("\n\t\tWRONG INPUT\n");
                }
            }
            // break;
        }
        else if (ch == '3')
        {
            clear_screen();
            printf("about us");
            // login();
            while (1)
            {    
            printf("\n\n\t\tPRESS 'B' TO RETURN TO MAIN MENU : ");
            ch = toupper(getch());
             if (ch == 'B')
                {
                    // loading();
                    main();
                    break;
                }
                else
                {
                    printf("\n\t\tWRONG INPUT\n");
                }
            }
            // break;
        }
        else if (ch == '4')
        {
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

    printf("\t\t ENTER GAMEHUB USERNAME [MAX 30 - CHARACTERS]: ");
    fflush(stdin);
    gets(gh.username);

    printf("\t\t ENTER GAMEHUB PASSWORD [MAX 8 - CHARACTERS] : ");
    fflush(stdin);
    takepass(gh.pass);
    while (1)
    {
        printf("\n\t\t CONFIRM PASSWORD : ");
        fflush(stdin);

        checkpass(check_pass);//confirming password
        if (strcmp(gh.pass, check_pass) != 0) //comparing both passwords
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
            FILE *ptr = NULL;
            ptr = fopen("gamehub.txt", "ab");
            fwrite(&gh, sizeof(struct details), 1, ptr);
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
