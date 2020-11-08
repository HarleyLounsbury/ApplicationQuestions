// New Era interview questions
// Auteur: Harley Lounsbury
// Date: 2020-11-07

#include <iostream>
#include <algorithm>

// Exchange the values of 2 character values.
void swap(char* value1, char* value2)
{
   char temp = *value1;
   *value1 = *value2;
   *value2 = temp;

   return;
}

// Determines the next possible greater value in a set of digits.
void findNextGreatestNumber(char number[], int numberOfDigits)
{
   int i;
   int j;

   // Traverse the array of digits from right to left to select a digit whos value is less than the previous.
   for (i = numberOfDigits - 1; i > 0; i--)
   {
      if (number[i] > number[i - 1])
         break;
   }
 
   // If no such number exists, it means the number is in descending order and no solution exists.
   if (i == 0)
   {
      std::cout << "Next number is not possible";
      return;
   }

   // Determine the smallest number to the right of the selected digit.
   // Swap this number with the selected digit.
   int numberToSwap = number[i - 1];
   int smallestToSwap = i;
   for (j = i + 1; j < numberOfDigits; j++)
      if (number[j] > numberToSwap && number[j] < number[smallestToSwap])
         smallestToSwap = j;
   swap(&number[smallestToSwap], &number[i - 1]);

   // Sort the numbers to right of the selected digit, the array now contains the next highest number.
   std::sort(number + i, number + numberOfDigits);

   return;
}


// Driver
// Does not sanitize or error check the input. 
int main()
{
   // Test size.
   char testNumber[20];

   // Get input
   std::cout << "Veuillez entrer un nombre: ";
   std::cin >> testNumber;

   // Process
   findNextGreatestNumber(testNumber, strlen(testNumber));

   // Output
   std::cout << "Le prochain nombre plus grand est: " << testNumber;


   return 0;
}
