#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


// This function checks if the generated strong password has not been generated previously by
// checkin all the previously generated passwords from a file.
int prev_check(char a[]);

// A function to check the strength of the password using a specific criteria
int checking_strength(char a[]);

// This function generates a random password that meets the criteria for 100% strength
void randomf(char a[]);



int checking_strength(char a[])
{
    // Criteria for different strength levels
    // The function returns a strength level and prints a corresponding message

    // Check for 50% strength
    int count = 0, star = 0;
    for (int i = 0; i < 10; i++)
    {
        if (isdigit(a[i]))
        {
            count++;
        }
    }
    if (count == 10)
    {
        printf("50%% strength\n");
        return 0;
    }

    // Check for 65% strength
    int b = 0,sun=0;
    for (int i = 0; i < 10; i++)
    {
        if (isdigit(a[i]) || islower(a[i]))
        {
            if (islower(a[i]))
            {
                star++;
            }
            if (isdigit(a[i]))
            {
                sun++;
            }
            b++;
        }
    }
    if (b == 10 && star >= 1 && sun>=1)
    {
        printf("65%% strength\n");
        return 0;
    }

    // Check for 75% strength
    int c = 0, d = 0, e = 0,fr=0;
    for (int i = 0; i < 10; i++)
    {
        if (isdigit(a[i]) || islower(a[i]) || isupper(a[i]))
        {
            c++;
            if (islower(a[i]))
            {
                d++;
            }
            if (isupper(a[i]))
            {
                e++;
            }
            if (isdigit(a[i]))
            {
                fr++;
            }
        }
    }

    if (c == 10 && d >= 1 && e >= 1 && fr>=1)
    {
        printf("75%% strength\n");
        return 0;
    }

    // Check for 85% strength
    int f = 0, g = 0, h = 0, hr = 0, k = 0;
    for (int i = 0; i < 10; i++)
    {
        if (isdigit(a[i]) || islower(a[i]) || isupper(a[i]) || a[i] == '?' || a[i] == '-' || a[i] == '+' || a[i] == '=' || a[i] == '@' || a[i] == '!' || a[i] == '#' || a[i] == '$' || a[i] == '^' || a[i] == '&' || a[i] == '*')
        {
            f++;
            if (islower(a[i]))
            {
                g++;
            }
            if (isupper(a[i]))
            {
                h++;
            }
            if (a[i] == '?' || a[i] == '-' || a[i] == '+' || a[i] == '=' || a[i] == '@' || a[i] == '!' || a[i] == '#' || a[i] == '$' || a[i] == '^' || a[i] == '&' || a[i] == '*')
            {
                k++;
            }
            if (isdigit(a[i]))
            {
                hr++;
            }
        }
    }

    if (f == 10 && (g < 2 || h < 2 || hr < 2 || k < 2) && (g > 0 && h>0 && hr>0 && k>0))
    {
        printf("85%% strength\n");
        return 0;
    }

    // Check for 100% strength
    int l = 0, m = 0, n = 0, o = 0,p=0;
    for (int i = 0; i < 10; i++)
    {
        if (isdigit(a[i]) || islower(a[i]) || isupper(a[i]) || a[i] == '?' || a[i] == '-' || a[i] == '+' || a[i] == '=' || a[i] == '!' || a[i] == '@' || a[i] == '#' || a[i] == '$' || a[i] == '^' || a[i] == '&' || a[i] == '*')
        {
            l++;
            if (islower(a[i]))
            {
                m++;
            }
            if (isupper(a[i]))
            {
                n++;
            }
            if (a[i] == '?' || a[i] == '-' || a[i] == '+' || a[i] == '=' || a[i] == '!' || a[i] == '@' || a[i] == '#' || a[i] == '$' || a[i] == '^' || a[i] == '&' || a[i] == '*')
            {
                o++;
            }
            if (isdigit(a[i]))
            {
                p++;
            }
        }
    }

    if (l == 10 && m >= 2 && n >= 2 && o >= 2 && p >= 2)
    {
        int q = prev_check(a);
        if (q != 3)
        {
            printf("100%% strength\n");
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // Check for less than 50% strength
    else
    {
        printf("<50%% strength\n");
        return 2;
    }
}


void randomf(char a[])
{
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char special[] = "?+-!@#$";
    char number[] = "0123456789";

    srand(time(NULL));

    a[0] = lower[rand() % 26];
    a[1] = special[rand() % 7];
    a[2] = upper[rand() % 26];
    a[3] = number[rand() % 10];
    a[4] = lower[rand() % 26];
    a[5] = special[rand() % 7];
    a[6] = upper[rand() % 26];
    a[7] = number[rand() % 10];
    a[8] = lower[rand() % 26];
    a[9] = special[rand() % 7];

    // this swaps any two characters randomly in the string so that the password is completely random
    int i = rand() % 10;
    int j = rand() % 10;
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


int prev_check(char a[])
{
    FILE *fp;
    fp = fopen("prev_pass.txt", "a+");
    if (fp == NULL)
    {
        printf("Unable to open the file\n");
        return 4;
    }
    else
    {
        int found = 0;
        char temp_str[11];
        while (!feof(fp))
        {
            // Check f the generated password has been generated previously
            fscanf(fp, "%s", temp_str);
            if (strcmp(a, temp_str) == 0)
            {
                printf("The password entered/generated has been already generated previously\n");
                found = 1;
                return 3;
            }
        }

        // If the password is unique, append it to the file
        if (!found)
        {
            fprintf(fp, "%s\n", a);
            return 15;
        }

        // Close the file
        fclose(fp);
    }
    return 34;
}

int main()
{
    char a[10];
    int play = 1;
    int b;
    while (play == 1)
    {
        printf("Enter Password: ");
        scanf("%s", a);
        int size = strlen(a);
        while(size != 10)
        {
            printf("Password should contains 10 characters\n");
            printf("Re-enter password: ");
            scanf("%s",a);
            size = strlen(a);
        }
        b = checking_strength(a);
        if (b == 0 || b == 2)
        {
            randomf(a);
            int y = prev_check(a);
            if (y == 15)
            {
                printf("New suggested password: ");
                printf("%s\n", a);
            }
            else
            {
                randomf(a);
                printf("New suggested password: ");
                printf("%s\n", a);
            }
        }
        else
        {
            printf("Your password is strong.\n");
        }

        // Loop to generate more than one password

        printf("Enter 1 if you want to re-enter password\nEnter 2 if you want to re-generate the password\nEnter 0 to exit : ");

        scanf("%d", &play);

        while (play == 2)
        {
            randomf(a);
            int u = prev_check(a);
            if (u == 15)
            {
                printf("New suggested password: ");
                printf("%s\n", a);
            }
            else
            {
                randomf(a);
                printf("New suggested password: ");
                printf("%s\n", a);
            }
            printf("Enter 1 if you want to re-enter password\n");
            printf("Enter 2 if you want to re-generate the password\n");
            printf("Enter 0 : ");
            scanf("%d", &play);
        }
    }
    printf("New password saved successfully and stored.");

    return 0;
}
