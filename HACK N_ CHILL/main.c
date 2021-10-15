#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>


void startScreen();
void endScreenWin();
void endScreenLose();
void printLevel(char level, char secret[11][11][11], char rpos, int label[], int trash[], int wordsSpacing, char history[20][20]);


int main()
{
    srand ( time(NULL) );
    int game = 1;
    char answer[99];
    int trash[384];

    char hp[4] = {'@', '@', '@', '@'};
    char level = 1;
    char rpos = (rand() % 2) + 3;
    int label[32] = {rand() % 0xFFFF};
    int wordsSpacing = (rand() % 8) + 10;
    char setSecret = rand() % 9;

    for(int x = 1; x < 32; x++)
    {
        label[x] = label[x-1] + ((rand() % 15) + 1);
    }

    for(int x = 0; x < 384; x++)
    {
        trash[x] = (rand()%93)+33;
        while((trash[x] > 47 && trash[x] < 58) || (trash[x] > 64 && trash[x] < 91) || (trash[x] > 96 && trash[x] < 123))
        {
            trash[x] = (rand()%63)+33;
        }
    }

    char history[20][20] =
    {
        {"              "},
        {"              "},
        {"              "},
        {"              "},
        {"              "},
        {"              "},
        {"              "},
        {"              "},
        {"              "},
        {"              "},
        {"              "},
        {"              "},
        {"              "},
        {"              "},
        {"              "},
        {"              "}
    };

    char secret[11][11][11] =
    {
        {"BORN", "TALE", "LIVE", "SURE", "CARE", "SOUL", "POOR", "ROLE", "ONES", "COAL"},
        {"SHOT", "HURT", "SELL", "SENT", "FIRE", "GLOW", "WEEK", "JAPY", "SICK", "HIRE"},
        {"LISTS", "PARTS", "KINDS", "VIEWS", "PILED", "FIFTH", "LIVES", "WINDS", "FACES", "PIPES"},
        {"EMPTY", "ENACT", "SWORE", "HELPS", "NAMES", "STAKE", "MARKS", "PRICE", "STARK", "TORCH"},
        {"HURTING", "FENCING", "PERSONA", "FEARING", "SEALANT", "ELEGANT", "READING", "HEIGHTS", "WEARING", "TESTING"},
        {"CLEANSE", "GROUPED", "GAINING", "WASTING", "DUSTERS", "LETTING", "ENDINGS", "FERTILE", "CERTAIN", "BANDITS"},
        {"SUDDENLY", "FEVERISH", "CITIZENS", "RESULTED", "SUPPLIED", "UNWANTED", "HUMANITY", "CONQUEST", "REPTILES", "SERVANTS"},
        {"BREAKING", "CREATING", "GUARDIAN", "DOCUMENT", "AGREEING", "GREENERY", "DYNAMITE", "FACILITY", "TRIPPING", "STEMMING"},
        {"RANSACKED", "TERRITORY", "INDICATED", "RENOVATED", "PENDELTON", "AFTERNOON", "PROLONGED", "DEDICATED", "UNPUZZLED", "PIZZALIKE"},
        {"APPEARANCE", "DISPLEASED", "BEFRIENDED", "SCIENTIFIC", "SCANDALOUS", "AUTOMOBILE", "ADRENALINE", "CEREMONIES", "STRONGHOLD", "SCAVENGING"}
    };


    startScreen();
    while(game)
    {
        printf("Welcome to FISHMAN Industries (TM) TermLink\n\n");
        printf("Password Required\n\n");
        printf("Level: %d\n", level);
        printf("Attempts Remaining: %c %c %c %c\n\n", hp[0], hp[1], hp[2], hp[3]);

        printLevel(level, secret, rpos, label, trash, wordsSpacing, history);
        scanf("%s", &answer);
        strupr(answer);

        if(strcmp(secret[level-1][setSecret],answer) == 0)
        {
            if(level >= 10)
            {
                endScreenWin();
                game = 0;
            }
            else
            {
               level++;
                hp[0] = '@';
                hp[1] = '@';
                hp[2] = '@';
                hp[3] = '@';


                rpos = (rand() % 2) + 3;
                label[0] = rand() % 0xFFFF;
                wordsSpacing = (rand() % 8) + 10;
                setSecret = rand() % 9;

                for(int x = 1; x < 32; x++)
                {
                    label[x] = label[x-1] + ((rand() % 15) + 1);
                }

                for(int x = 0; x < 384; x++)
                {
                    trash[x] = (rand()%93)+33;
                    while((trash[x] > 47 && trash[x] < 58) || (trash[x] > 64 && trash[x] < 91) || (trash[x] > 96 && trash[x] < 123))
                    {
                        trash[x] = (rand()%63)+33;
                    }
                }

                for(int x = 15; x > 0; x--)
                {
                    strcpy(history[x], history[x-1]);
                }

                strcpy(history[0], ">");
                strcat(history[0], answer);

                for(int x = 15; x > 0; x--)
                {
                    strcpy(history[x], history[x-1]);
                }

                strcpy(history[0], ">Access granted.");
            }
        }
        else if(hp[1] == ' ')
        {
            endScreenLose();
            game = 0;
        }
        else
        {
            unsigned int x = 3;
            unsigned int likeness = 0;
            char likenessStr[] = "0";

            for(; hp[x] != '@'; x--){}
            hp[x] = ' ';


            for(int x = 0; x < strlen(secret[level-1][setSecret]); x++)
            {
                if(answer[x] == secret[level-1][setSecret][x])
                {
                    likeness++;
                    switch(likeness)
                    {
                    case 1:
                        likenessStr[0] = '1';
                        break;
                    case 2:
                        likenessStr[0] = '2';
                        break;
                    case 3:
                        likenessStr[0] = '3';
                        break;
                    case 4:
                        likenessStr[0] = '4';
                        break;
                    case 5:
                        likenessStr[0] = '5';
                        break;
                    case 6:
                        likenessStr[0] = '6';
                        break;
                    case 7:
                        likenessStr[0] = '7';
                        break;
                    case 8:
                        likenessStr[0] = '8';
                        break;
                    default:
                        likenessStr[0] = '9';
                    }
                }
            }

            for(int x = 15; x > 0; x--)
            {
                strcpy(history[x], history[x-1]);
            }

            strcpy(history[0], ">");
            strcat(history[0], answer);

            for(int x = 15; x > 0; x--)
            {
                strcpy(history[x], history[x-1]);
            }

            strcpy(history[0], ">Entry denied.");

            for(int x = 15; x > 0; x--)
            {
                strcpy(history[x], history[x-1]);
            }

            strcpy(history[0], ">Likeness=");
            strcat(history[0], likenessStr);

        }

        system("cls");
    };

    return 0;
};


void startScreen()
{
    printf("                  '                      '                               \n");
    printf("         -----------------------------------------------------           \n");
    printf("  '      @  @  @@   @@@ @  @  @  @  @   @@@ @  @ @@@@ @@   @@   '        \n");
    printf("         @@@@ @  @ @@   @@@   @@ @  @  @@   @@@@  @   @@   @@            \n");
    printf("       ' @  @ @@@@ @@   @ @   @ @@     @@   @  @  @   @@   @@            \n");
    printf("         @  @ @  @  @@@ @  @  @  @      @@@ @  @ @@@@ @@@@ @@@@    '     \n");
    printf("   '     ------------------------------------------------------          \n");
    printf("         '                                                               \n");
    printf("                                '          '                             \n");
    printf("     '             '                               '          '          \n");
    printf("                                                                         \n");
    printf("         '              [PRESS ENTER TO BEGIN]                    '      \n");
    printf("'                                                                        \n");
    printf("                                       '                                 \n");
    printf("       '         '                                         '             \n");
    printf("   '                                              '                      \n");
    printf("                     '          '          '                     '       \n");
    getchar();
    system("cls");
}

void endScreenWin()
{
    system("cls");
    printf("                  '                      '                               \n");
    printf("         ----------------------------------------------------            \n");
    printf("  '          @@  @@ @@@@@@ @@  @@   @ @ @@ @@@@@@ @@  @@               ' \n");
    printf("              @@@@  @@  @@ @@  @@   @ @ @@ @@  @@ @@@ @@                 \n");
    printf("       '       @@   @@  @@ @@  @@   @ @ @@ @@  @@ @@@@@@                 \n");
    printf("               @@   @@  @@ @@  @@   @ @ @@ @@  @@ @@  @@                '\n");
    printf("   '           @@   @@@@@@ @@@@@@   @@@@@@ @@@@@@ @@  @@                 \n");
    printf("         -----------------------------------------------------           \n");
    printf("                                '          '                             \n");
    printf("     '             '                               '          '          \n");
    printf("                                                                         \n");
    printf("         '             [PRESS ENTER TO CELEBRATE!!]                      \n");
    printf("'                                                                        \n");
    printf("                                       '                                 \n");
    printf("       '         '                                         '             \n");
    printf("   '                                              '                      \n");
    printf("                     '          '          '                     '       \n");
    fflush(stdin);
    getchar();
}

void endScreenLose()
{
    system("cls");
    printf("                  '                      '                               \n");
    printf("         ----------------------------------------------------            \n");
    printf("  '      @@  @@ @@@@@@ @@  @@   @@@@@@ @@  @@ @@@@@@ @@  @@        '     \n");
    printf("          @@@@  @@  @@ @@  @@    @@    @@  @@ @@     @@ @@               \n");
    printf("       '   @@   @@  @@ @@  @@     @@   @@  @@ @@     @@@                 \n");
    printf("           @@   @@  @@ @@  @@      @@  @@  @@ @@     @@ @@          '    \n");
    printf("   '       @@   @@@@@@ @@@@@@   @@@@@@ @@@@@@ @@@@@@ @@  @@              \n");
    printf("         -----------------------------------------------------           \n");
    printf("                                '          '                             \n");
    printf("     '             '                               '          '          \n");
    printf("                                                                         \n");
    printf("         '             [PRESS ENTER TO LOSE]                      '      \n");
    printf("'                                                                        \n");
    printf("                                       '                                 \n");
    printf("       '         '                                         '             \n");
    printf("   '                                              '                      \n");
    printf("                     '          '          '                     '       \n");
    fflush(stdin);
    getchar();

}

void printLevel(char level, char secret[11][11][11], char rpos, int label[], int trash[], int wordsSpacing, char history[20][20])
{
    char wordnumber = 0;
    char rLabel = 16;
    unsigned char lLabel = 0;
    int trashNumber = 0;
    int wordLetter = 0;
    int sidePrinting;
    int lastPrint = 0;
    int printablePos = 1;
    int historyPrinter = 15;

    switch(level){

        case 1:

            for(int y = 0; y < 16; y++){

                for(int x = 0; x < 41; x++)
                {
                    if(x < 40)
                    {
                        if(x == 0)
                        {
                            printf("0x%04X", label[lLabel]);
                            sidePrinting = 0;
                            lLabel++;
                            x += 5;
                        }
                        else if(x == 20)
                        {
                            printf("0x%04X", label[rLabel]);
                            sidePrinting = 1;
                            rLabel++;
                            x += 5;
                        }
                        else if(x == 6 || x == 19 || x == 26 || x == 39)
                        {
                            printf(" ");
                        }
                        else if(((printablePos % wordsSpacing == 0 && (wordnumber < 10)) || wordLetter !=0) && sidePrinting == lastPrint)
                        {
                                lastPrint = sidePrinting;
                                printf("%c", secret[level-1][wordnumber][wordLetter]);
                                wordLetter++;
                                printablePos++;
                                if(wordLetter == 4){ wordLetter = 0; wordnumber++; if(lastPrint){lastPrint = 0;}else{lastPrint = 1;}};
                        }
                        else
                        {
                            printf("%c", trash[trashNumber++]);
                            printablePos++;

                        }
                    }
                    else
                    {
                        printf("%s", history[historyPrinter]);
                    }

                }
                historyPrinter--;
                printf("\n");
            }
            break;

        case 2:

                for(int y = 0; y < 16; y++){

                    for(int x = 0; x < 41; x++)
                    {
                        if(x < 40)
                        {
                            if(x == 0)
                            {
                                printf("0x%04X", label[lLabel]);
                                sidePrinting = 0;
                                lLabel++;
                                x += 5;
                            }
                            else if(x == 20)
                            {
                                printf("0x%04X", label[rLabel]);
                                sidePrinting = 1;
                                rLabel++;
                                x += 5;
                            }
                            else if(x == 6 || x == 19 || x == 26 || x == 39)
                            {
                                printf(" ");
                            }
                            else if(((printablePos % wordsSpacing == 0 && (wordnumber < 10)) || wordLetter !=0) && sidePrinting == lastPrint)
                            {
                                    lastPrint = sidePrinting;
                                    printf("%c", secret[level-1][wordnumber][wordLetter]);
                                    wordLetter++;
                                    printablePos++;
                                    if(wordLetter == 4){ wordLetter = 0; wordnumber++; if(lastPrint){lastPrint = 0;}else{lastPrint = 1;}};
                            }
                            else
                            {
                                printf("%c", trash[trashNumber++]);
                                printablePos++;

                            }
                        }
                        else
                        {
                            printf("%s", history[historyPrinter]);
                        }

                    }
                    historyPrinter--;
                    printf("\n");
                }
                break;

            case 3:

                for(int y = 0; y < 16; y++){

                    for(int x = 0; x < 41; x++)
                    {
                        if(x < 40)
                        {
                            if(x == 0)
                            {
                                printf("0x%04X", label[lLabel]);
                                sidePrinting = 0;
                                lLabel++;
                                x += 5;
                            }
                            else if(x == 20)
                            {
                                printf("0x%04X", label[rLabel]);
                                sidePrinting = 1;
                                rLabel++;
                                x += 5;
                            }
                            else if(x == 6 || x == 19 || x == 26 || x == 39)
                            {
                                printf(" ");
                            }
                            else if(((printablePos % wordsSpacing == 0 && (wordnumber < 10)) || wordLetter !=0) && sidePrinting == lastPrint)
                            {
                                    lastPrint = sidePrinting;
                                    printf("%c", secret[level-1][wordnumber][wordLetter]);
                                    wordLetter++;
                                    printablePos++;
                                    if(wordLetter == 5){ wordLetter = 0; wordnumber++; if(lastPrint){lastPrint = 0;}else{lastPrint = 1;}};
                            }
                            else
                            {
                                printf("%c", trash[trashNumber++]);
                                printablePos++;

                            }
                        }
                        else
                        {
                            printf("%s", history[historyPrinter]);
                        }

                    }
                    historyPrinter--;
                    printf("\n");
                }
                break;

            case 4:

                for(int y = 0; y < 16; y++){

                    for(int x = 0; x < 41; x++)
                    {
                        if(x < 40)
                        {
                            if(x == 0)
                            {
                                printf("0x%04X", label[lLabel]);
                                sidePrinting = 0;
                                lLabel++;
                                x += 5;
                            }
                            else if(x == 20)
                            {
                                printf("0x%04X", label[rLabel]);
                                sidePrinting = 1;
                                rLabel++;
                                x += 5;
                            }
                            else if(x == 6 || x == 19 || x == 26 || x == 39)
                            {
                                printf(" ");
                            }
                            else if(((printablePos % wordsSpacing == 0 && (wordnumber < 10)) || wordLetter !=0) && sidePrinting == lastPrint)
                            {
                                    lastPrint = sidePrinting;
                                    printf("%c", secret[level-1][wordnumber][wordLetter]);
                                    wordLetter++;
                                    printablePos++;
                                    if(wordLetter == 5){ wordLetter = 0; wordnumber++; if(lastPrint){lastPrint = 0;}else{lastPrint = 1;}};
                            }
                            else
                            {
                                printf("%c", trash[trashNumber++]);
                                printablePos++;

                            }
                        }
                        else
                        {
                            printf("%s", history[historyPrinter]);
                        }

                    }
                    historyPrinter--;
                    printf("\n");
                }
                break;

            case 5:

                for(int y = 0; y < 16; y++){

                    for(int x = 0; x < 41; x++)
                    {
                        if(x < 40)
                        {
                            if(x == 0)
                            {
                                printf("0x%04X", label[lLabel]);
                                sidePrinting = 0;
                                lLabel++;
                                x += 5;
                            }
                            else if(x == 20)
                            {
                                printf("0x%04X", label[rLabel]);
                                sidePrinting = 1;
                                rLabel++;
                                x += 5;
                            }
                            else if(x == 6 || x == 19 || x == 26 || x == 39)
                            {
                                printf(" ");
                            }
                            else if(((printablePos % wordsSpacing == 0 && (wordnumber < 10)) || wordLetter !=0) && sidePrinting == lastPrint)
                            {
                                    lastPrint = sidePrinting;
                                    printf("%c", secret[level-1][wordnumber][wordLetter]);
                                    wordLetter++;
                                    printablePos++;
                                    if(wordLetter == 7){ wordLetter = 0; wordnumber++; if(lastPrint){lastPrint = 0;}else{lastPrint = 1;}};
                            }
                            else
                            {
                                printf("%c", trash[trashNumber++]);
                                printablePos++;

                            }
                        }
                        else
                        {
                            printf("%s", history[historyPrinter]);
                        }

                    }
                    historyPrinter--;
                    printf("\n");
                }
                break;

            case 6:

                for(int y = 0; y < 16; y++){

                    for(int x = 0; x < 41; x++)
                    {
                        if(x < 40)
                        {
                            if(x == 0)
                            {
                                printf("0x%04X", label[lLabel]);
                                sidePrinting = 0;
                                lLabel++;
                                x += 5;
                            }
                            else if(x == 20)
                            {
                                printf("0x%04X", label[rLabel]);
                                sidePrinting = 1;
                                rLabel++;
                                x += 5;
                            }
                            else if(x == 6 || x == 19 || x == 26 || x == 39)
                            {
                                printf(" ");
                            }
                            else if(((printablePos % wordsSpacing == 0 && (wordnumber < 10)) || wordLetter !=0) && sidePrinting == lastPrint)
                            {
                                    lastPrint = sidePrinting;
                                    printf("%c", secret[level-1][wordnumber][wordLetter]);
                                    wordLetter++;
                                    printablePos++;
                                    if(wordLetter == 7){ wordLetter = 0; wordnumber++; if(lastPrint){lastPrint = 0;}else{lastPrint = 1;}};
                            }
                            else
                            {
                                printf("%c", trash[trashNumber++]);
                                printablePos++;

                            }
                        }
                        else
                        {
                            printf("%s", history[historyPrinter]);
                        }

                    }
                    historyPrinter--;
                    printf("\n");
                }
                break;

            case 7:

                for(int y = 0; y < 16; y++){

                    for(int x = 0; x < 41; x++)
                    {
                        if(x < 40)
                        {
                            if(x == 0)
                            {
                                printf("0x%04X", label[lLabel]);
                                sidePrinting = 0;
                                lLabel++;
                                x += 5;
                            }
                            else if(x == 20)
                            {
                                printf("0x%04X", label[rLabel]);
                                sidePrinting = 1;
                                rLabel++;
                                x += 5;
                            }
                            else if(x == 6 || x == 19 || x == 26 || x == 39)
                            {
                                printf(" ");
                            }
                            else if(((printablePos % wordsSpacing == 0 && (wordnumber < 10)) || wordLetter !=0) && sidePrinting == lastPrint)
                            {
                                    lastPrint = sidePrinting;
                                    printf("%c", secret[level-1][wordnumber][wordLetter]);
                                    wordLetter++;
                                    printablePos++;
                                    if(wordLetter == 8){ wordLetter = 0; wordnumber++; if(lastPrint){lastPrint = 0;}else{lastPrint = 1;}};
                            }
                            else
                            {
                                printf("%c", trash[trashNumber++]);
                                printablePos++;

                            }
                        }
                        else
                        {
                            printf("%s", history[historyPrinter]);
                        }

                    }
                    historyPrinter--;
                    printf("\n");
                }
                break;

            case 8:

                for(int y = 0; y < 16; y++){

                    for(int x = 0; x < 41; x++)
                    {
                        if(x < 40)
                        {
                            if(x == 0)
                            {
                                printf("0x%04X", label[lLabel]);
                                sidePrinting = 0;
                                lLabel++;
                                x += 5;
                            }
                            else if(x == 20)
                            {
                                printf("0x%04X", label[rLabel]);
                                sidePrinting = 1;
                                rLabel++;
                                x += 5;
                            }
                            else if(x == 6 || x == 19 || x == 26 || x == 39)
                            {
                                printf(" ");
                            }
                            else if(((printablePos % wordsSpacing == 0 && (wordnumber < 10)) || wordLetter !=0) && sidePrinting == lastPrint)
                            {
                                    lastPrint = sidePrinting;
                                    printf("%c", secret[level-1][wordnumber][wordLetter]);
                                    wordLetter++;
                                    printablePos++;
                                    if(wordLetter == 8){ wordLetter = 0; wordnumber++; if(lastPrint){lastPrint = 0;}else{lastPrint = 1;}};
                            }
                            else
                            {
                                printf("%c", trash[trashNumber++]);
                                printablePos++;

                            }
                        }
                        else
                        {
                            printf("%s", history[historyPrinter]);
                        }

                    }
                    historyPrinter--;
                    printf("\n");
                }
                break;

            case 9:

                for(int y = 0; y < 16; y++){

                    for(int x = 0; x < 41; x++)
                    {
                        if(x < 40)
                        {
                            if(x == 0)
                            {
                                printf("0x%04X", label[lLabel]);
                                sidePrinting = 0;
                                lLabel++;
                                x += 5;
                            }
                            else if(x == 20)
                            {
                                printf("0x%04X", label[rLabel]);
                                sidePrinting = 1;
                                rLabel++;
                                x += 5;
                            }
                            else if(x == 6 || x == 19 || x == 26 || x == 39)
                            {
                                printf(" ");
                            }
                            else if(((printablePos % wordsSpacing == 0 && (wordnumber < 10)) || wordLetter !=0) && sidePrinting == lastPrint)
                            {
                                    lastPrint = sidePrinting;
                                    printf("%c", secret[level-1][wordnumber][wordLetter]);
                                    wordLetter++;
                                    printablePos++;
                                    if(wordLetter == 9){ wordLetter = 0; wordnumber++; if(lastPrint){lastPrint = 0;}else{lastPrint = 1;}};
                            }
                            else
                            {
                                printf("%c", trash[trashNumber++]);
                                printablePos++;

                            }
                        }
                        else
                        {
                            printf("%s", history[historyPrinter]);
                        }

                    }
                    historyPrinter--;
                    printf("\n");
                }
                break;

            default:

                for(int y = 0; y < 16; y++){

                    for(int x = 0; x < 41; x++)
                    {
                        if(x < 40)
                        {
                            if(x == 0)
                            {
                                printf("0x%04X", label[lLabel]);
                                sidePrinting = 0;
                                lLabel++;
                                x += 5;
                            }
                            else if(x == 20)
                            {
                                printf("0x%04X", label[rLabel]);
                                sidePrinting = 1;
                                rLabel++;
                                x += 5;
                            }
                            else if(x == 6 || x == 19 || x == 26 || x == 39)
                            {
                                printf(" ");
                            }
                            else if(((printablePos % wordsSpacing == 0 && (wordnumber < 10)) || wordLetter !=0) && sidePrinting == lastPrint)
                            {
                                    lastPrint = sidePrinting;
                                    printf("%c", secret[level-1][wordnumber][wordLetter]);
                                    wordLetter++;
                                    printablePos++;
                                    if(wordLetter == 10){ wordLetter = 0; wordnumber++; if(lastPrint){lastPrint = 0;}else{lastPrint = 1;}};
                            }
                            else
                            {
                                printf("%c", trash[trashNumber++]);
                                printablePos++;

                            }
                        }
                        else
                        {
                            printf("%s", history[historyPrinter]);
                        }

                    }
                    historyPrinter--;
                    printf("\n");
                }
    }

};
