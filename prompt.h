#include <iostream>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <iomanip> // used to set width
#include <random>
#include <time.h>

#define TSIZE 16 // no semicolon because reads literally from define statement, preprocessor
#define QSIZE 5  // changes number of questions to ask the user each run through

int table[TSIZE][TSIZE];
int left[QSIZE], right[QSIZE]; // needed to define this at the top, globally
int answers[QSIZE] = {0, 0, 0, 0, 0};

/* initializeTable
creates the table from scratch to store in memory*/
void initializeTable();
/* printMenu
prints the menu for user to select from options*/
void printMenu();
/* printTable
prints the times table so user can study*/
void printTable();
/* randomize
randomly grabs 5 left and 5 right numbers*/
void randomize(int left[QSIZE], int right[QSIZE]);
/*printDailyQs
calls randomize and prompts user with QSIZE questions*/
void printDailyQs();
/* getAnswers
asks for user input as a string, and checks if user is correct*/
bool getAnswers();