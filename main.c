#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

  srand(time(NULL));  /* With this we make the random number different each time we execute the program */

  char PossibleColors[][16] = {
    "blue",
    "green",
    "red",
    "yellow",
    "white",
    "black"
  };

  int RandomColor = rand() % 6;  /* We divide by 6 to get a number between 0 to 5 so it selects the color */
  int NumberOfLives = 5;
  int CorrectAnswers = 0;
  int OldCorrectAnswer = 0;

  int LengthOfColor = strlen(PossibleColors[RandomColor]);

  int LetterGuessed[7] = { 0, 0, 0, 0, 0, 0, 0 }; /*These will be 1 when the participant selects right word */

  int LoopIndex = 0;
  int quit = 0;

  char guess[16]; /* User imput */
  char LetterEntered;


  while (CorrectAnswers < LengthOfColor)
    {
      printf ("\nNew Turn. Use it wisely...\nHangman Word:");

      for (LoopIndex = 0; LoopIndex < LengthOfColor; LoopIndex++)
        {
          if (LetterGuessed[LoopIndex] == 1)
            {
	      printf ("%c", PossibleColors[RandomColor][LoopIndex]);
            }
	  else
	    {
	      printf ("_ ");
	    }
        }

      printf ("\n");

      printf ("Number of correct letters so far: %d\n", CorrectAnswers);
      printf ("\nTry a letter:");
      fgets (guess, 10, stdin); /*It reads a line from the stream and stores it into the string pointed to by guess*/

      if (strncmp(guess, "quit", 4) == 0)
	{
	  quit = 1; /* This will work as a flag when decide to quit the game */
	  break;
	}
    
      LetterEntered = guess[0];

      OldCorrectAnswer = CorrectAnswers; /* This is used to keep the number of lives moving */

      for (LoopIndex = 0; LoopIndex < LengthOfColor; LoopIndex++)
	{
	  if (LetterGuessed[LoopIndex] == 1)
	    {
	      continue;
	    }

	  if (LetterEntered == PossibleColors[RandomColor][LoopIndex])
	    {
	      LetterGuessed[LoopIndex] = 1;
	      CorrectAnswers++;
	    }	    
	}

      if (OldCorrectAnswer == CorrectAnswers)
	{
	  NumberOfLives--;
	  printf ("\nNop. Wrong answer. Keep trying!\n");
	  if (NumberOfLives == 0)
	    {
	      break;
	    }	
	}
      else
	{
	  printf ("\nYES! Right answer. Keep going!\n");
	}
    }

  if (quit == 1)
  {
    printf ("\nYou decided this was too much for you\n");
  }
  else if (NumberOfLives == 0)
    {
      printf ("\nAnd by the way... GAME OVER. The right answer was: %s\n", PossibleColors[RandomColor]);
    }
  else
    {
      printf ("\nYES!! You just won! Congratulations!\n");
    }
  return (0);
}
