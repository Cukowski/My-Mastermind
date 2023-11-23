# Welcome to My Mastermind
Welcome to My Mastermind projeckt. 

Here we will try to explain basics of the program and how to make it work.

## Task
The task for us is to wrtie a code thar makes a number guessing world.

We recreated the mastermind game. The whole point of the game is to guess the secret code that has either already been
specified by the program or is randomly generated. The player has 10 attempts to solve the riddle by default.

In this game we will have 4 numbers we try to guess like 1234, 9340, 0482 ex. The game will revieve a code and atttempt 
number if it is declared, generate a random code otherwise and also make 10 attempts as default.

The goal is to find secret code in as less tries possible.

## Description
We walk through the problem step by step making it into smaller problems. Starting from main idea to how should we 
create necessary functions.

In order to solve the problem we created a few functions. First would check if the user input is correct according to 
game rules. Then we would check if the code the player entered corresponds to the secret code. If yes, user wins the 
game. If not, the terminal will display the amount of misplaced and well placed pieces of code.

Spending time and efforts (lot's of fail and error) we have a functioning code with it's Makefile folder.

## Installation
After creating my_mastermind.c and a Makefile for it, write the command 'make' in the terminal.

After the executable file is ready to be called type './my_mastermind' in the terminal. Now you are able to input your guess.
The game will be uploud to the GitHub.

You can access it via gitea. You can play this game in terminal too!

## Usage
Once everything is installed and ready simply input your guesses in the terminal.

In order to change the amount of attempts you can take type in ./my_mastermind -t "YourNumber"

In order to pass your own code as an argument type in ./my_mastermind -c "YourCode"

After make complited you can call the following command:
```
./my_mastermind 
./my_mastermind -c 1234
./my_mastermind -t 10

### The Core Team
Big team consisting of: Alisa Kalinina, Selcuk Ata Aksoy, Alexey Markov

<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
