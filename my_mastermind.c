#include "my_mastermind.h"

void intialize();
int checkSpec(char* av0, char* av1, int * code);
int my_strcmp(char* p1, char*p2);
char* my_strcpy(char* param_1, char* param_2);
void checkCode(char *tempCode, int *code);
void randomNumber(int *code);
int attempCheck(int * code);
void checkAttempts(int *attempts, int *rounds);
int checkBuffer(int *numbers);
int checkPieces(int *numbers, int *code);

void intialize() // print the start display
{
    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");
}

int checkSpec(char* av0, char* av1, int * code) // check specific code or attempt
{
    char tempCode[CODE_LEN];

    if(!my_strcmp("-c", av0)) // checks -c for code
    {
        my_strcpy(tempCode, av1); // temp is av1
        // printf("Temp Code: %s\n", tempCode);
        checkCode(tempCode, code); // is av1 valid? if yes it is code
        return 0;
    }
    else if (!my_strcmp("-t", av0)) // checks -t attempt number
        attempts = atoi(av1);
    else
        randomNumber(code); // if there is no -c code given
    return 1;
}

int my_strcmp(char* p1, char*p2)
{
	int sum1, sum2 = 0;
  
  	for(int i = 0; p1[i]; i++) sum1 += p1[i];
  	for(int i = 0; p2[i]; i++) sum2 += p2[i];
  	
    if(p1[0] == p2[0] && p1[1] == p2[1] && p1[2] == p2[2]) return 0;
  
  	if (sum1 > sum2) return -1;
  	else if (sum1 < sum2) return 1;
  	else return 0;
}

char* my_strcpy(char* param_1, char* param_2)
{
    int i = 0;
    int len = strlen(param_2);

    while (i < len) 
    {
        param_1[i] = param_2[i];
        i++;
    }

    return param_1;
}


void checkCode(char *tempCode, int *code) // receives tempCode and transfers int code
{    
    for (int i = 0; i < CODE_LEN; i++)
    {
        if (tempCode[i] >= '0' && tempCode[i] <= '8') // checking for is number valid?
        { 
            if (tempCode[i] != '0') 
                code[i] = tempCode[i] - '0'; // we translate buffer to an int
            else 
                code[i] = 0;   
        } 
        else break;
    }
}

void randomNumber(int *code) // random number generator
{
    for (int i = 0; i < CODE_LEN; i++) 
        code[i] =  rand() % 8;
}

int attempCheck(int * code)
{
    int numbers[CODE_LEN] = {0}; // user input

    while (attempts) // checks if there's more attempts to make
    {
        printf("Round %d\n", rounds);

        checkAttempts(&attempts, &rounds);

        int cB = checkBuffer(numbers);
        if(cB == -1) // checks the input buffer is valid?
        {
            return 0;
        } 
        else
            if (checkPieces(numbers, code) == 1)  // cheks if buffer and code matches
                return 0;
    }
    return 1;
}

void checkAttempts(int *attempts, int *rounds)
{
    *attempts -= 1; // one less attempt
    *rounds += 1; // one more round
}

int checkBuffer(int* numbers) //checks  the player input (valid or Wrong input!)
{
    char c;
    int i = 0, ret;

    while ((ret = read(0, &c, 1)) == 1 && i < CODE_LEN) // reads characters one by one
    {
        if (c >= '0' && c <= '8') //checks if the numbers used correspond to the game rules
        {        
            if (c != '0') 
                numbers[i++] =  c - '0'; //get integer value (ASCII)
            else 
                numbers[i++] = 0;
        }
        else 
            return -1;
    }

    if (i != 4) // errors if less than 4 characters are entered              
        return -1;

    return 1;
}

int checkPieces(int *numbers, int *code)
{
    int misplacedPieces = 0;
    int correct = 0;

    for (int i = 0; i < 4; i++) // check for matches and misplaced numbers
    {
        if (numbers[i] == code[i]) 
            correct++;
        else if (numbers[i] != code[i] && (numbers[i] == code[(i+1)%4] || numbers[i] == code[(i+2)%4] || numbers[i] == code[(i+3)%4]))
            misplacedPieces++;
    }
    
    if (correct == 4) // print results
    {
        printf("Congratz! You did it!\n");
        return 1;
    } else 
        printf("Well placed pieces: %d\nMisplaced pieces: %d\n", correct, misplacedPieces); 

    return 0;
}

/*
void printCode(int * code) // print for test
{
    printf("code: %d", code[0]);
    printf("%d", code[1]);
    printf("%d", code[2]);
    printf("%d\n", code[3]);
}
void printNumbers(int * numbers) // print for test
{
    printf("numbers: %d", numbers[0]);
    printf("%d", numbers[1]);
    printf("%d", numbers[2]);
    printf("%d\n", numbers[3]);
}
*/

int main(int argc, char **av)
{
    int code[CODE_LEN] = {0}; // secret code

    intialize(); // print the start message

    if(argc == 0) return 0; // check for input

    for (int i = 0, c = -1; av[i] && c != 0; i++) // check -c or -t
        c = checkSpec(av[i], av[i+1], code);
    
    attempCheck(code);

    return EXIT_SUCCESS;
}

/*
done

 communicate_with("./my_mastermind -c 1234") do                                                                                                                                                                    
    send_command("5678")                                                                                                                                                                                          
    send_command("4321")                                                                                                                                                                                          
    send_command("1256")                                                                                                                                                                                          
    send_command("1243")   
                                             
                                             
["Well placed pieces: 0", "Misplaced pieces: 0", 
"Well placed pieces: 0", "Misplaced pieces: 4", 
"Well placed pieces: 2", "Misplaced pieces: 0", 
"Well placed pieces: 2", "Misplaced pieces: 2"]                                              

*/