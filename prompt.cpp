#include "prompt.h"

/* Driver Class
this is where the user will interact with the program
also displays the message if the user is correct or not
calls helper functions*/
int main()
{
  srand(time(NULL)); // initialization, only called once
  char select = '1';
  // initialize times table
  initializeTable();

  // print menu
  while (select != 'q')
  {
    fflush(stdin);
    printMenu();
    std::cin >> select;
    if (select == '1')
    {
      printTable();
      std::cout << std::endl;
    }
    else if (select == '2')
    {
      printDailyQs();
      bool correct = getAnswers(); // call function to get user's answers
      if (correct)
      {
        std::cout << "Your answers are correct!\n";
        select = 'q';
        continue;
      }
      else
      {
        std::cout << "One or more of your answers are NOT correct!\n";
        select = 'q';
        continue;
      }
    }
    else if (select == 'q')
    {
      continue;
    }
    else
    {
      std::cout << "Error! Please select from the options below:\n";
    }
  }

  return 0;
}

void initializeTable()
{
  for (int i = 0; i < TSIZE; i++)
    for (int j = 0; j < TSIZE; j++)
      table[i][j] = i * j;
}

void printTable()
{
  for (int i = 0; i < TSIZE; i++)
  {
    std::cout << std::endl;
    for (int j = 0; j < TSIZE; j++)
    {
      std::cout << std::setw(2) << "| " << std::setw(3) << table[i][j];
    }
  }
}

void randomize(int left[QSIZE], int right[QSIZE])
{
  // assign one to left and one to right
  // received an ambiguous collision with using namespace std, so removed it
  for (int i = 0; i < QSIZE; i++)
  {
    left[i] = rand() % 16;
    right[i] = rand() % 16;
  }
  return;
}

void printMenu()
{
  std::cout << "(1) Print Table\n";
  std::cout << "(2) Daily Questions\n";
  std::cout << "(q) Exit\n";
}

void printDailyQs()
{
  // call a function to pick out 5 random numbers in the questions array twice
  randomize(left, right);

  // then query the user for left[i]*right[i], from 0->QSIZE position of left and right
  for (int i = 0; i < QSIZE; i++)
  {
    std::cout << "\n"
              << i + 1 << ". What is " << std::setw(2) << left[i] << "*"
              << std::setw(1) << right[i] << "?\n";
  }
  return;
}

bool getAnswers()
{
  bool iscorrect = true;
  std::cout << "Enter in your answers with a space between each one, starting with the first question\n\n";
  std::cin >> answers[0] >> answers[1] >> answers[2] >> answers[3] >> answers[4];
  for (int i = 0; i < QSIZE; i++)
  {
    if (answers[i] != left[i] * right[i])
    {
      iscorrect = false;
      break; // place break or else I would overwrite iscorrect for any cases where wrong answer is in the middle
    }
  }
  return iscorrect;
}