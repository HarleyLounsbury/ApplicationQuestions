// New Era interview questions
// Auteur: Harley Lounsbury
// Date: 2020-11-07

#include <iostream>
#include <string>

const double PRICE_APPLE = 0.6;
const double PRICE_ORANGE = 1.25;

// Simple link list node.
struct node
{
   node* next;
   std::string productName;

};

// Traverse the list and caluclate the total price.
double calculateTotal(node* head)
{
   // Always check raw-pointers. Always.
   if (head == nullptr)
      return 0.0;

   // QUESTION 3 ADDITION:
   int appleCounter = 0;
   int orangeCounter = 0;

   double total = 0.0;

   // Pointer to run through the list.
   node* runner = head;

   // Run through the list, adding to total as we go.
   while (runner)
   {
      if (runner->productName == "apple")
      {
         total += PRICE_APPLE;
         appleCounter++;
      }

      if (runner->productName == "orange")
      {
         total += PRICE_ORANGE;
         orangeCounter++;
      }

      runner = runner->next;
   }

   // Remove the 2 for 1 apples from total price.
   total -= (appleCounter / 2) * PRICE_APPLE;

   // Remove the 3 for 2 oranges from total price.
   total -= (orangeCounter / 3) * PRICE_ORANGE;

   return total;
}



// Driver
int main()
{
   // Lets make a few nodes.
   // To add more:
   // Create node
   // Inject data
   // Attach to previous node
   // delete before returning from main.
   node* apple1 = new node();
   apple1->productName = "apple";

   node* apple2 = new node();
   apple2->productName = "apple";
   apple1->next = apple2;

   node* apple3 = new node();
   apple3->productName = "apple";
   apple2->next = apple3;

   node* orange1 = new node();
   orange1->productName = "orange";
   apple3->next = orange1;

   std::cout << "The total price is: " << calculateTotal(apple1) << "\n";

   delete apple1;
   delete apple2;
   delete apple3;
   delete orange1;

   return 0;
}
