#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  vector <vector <string> > wordGrid;

  /*
     do not edit this space
     where this comment is, the instructor will
     add the code that gets the user's input and
     inserts the input into every element of the
     matrix wordGrid
  */

  //PUT YOUR CODE BELOW THIS LINE
  int rows = wordGrid.size ();
  int cols = wordGrid[0].size ();
  int rowIndex = 0;
  int colIndex = 0;
  while (int index =0; index < rows; index++;)
  {
    cout << "Row " <<Index+1 << " Column " << colIndex+1 << " is: " << wordGrid [Index][colIndex]<<endl;
  }
  while (int columnIndex = 0; columnIndex < cols; columnIndex++;)
  {
    cout << "Row " <<rowIndex+1 << " Column " << columnIndex+1 << "is: " <<wordGrid [rowIndex][columnIndex]<<endl;
    
  }
  
  
  //that prints each element of the matrix in the
  //following format:
  //Row _ Column _ is _
  //the first and second blanks should be replaced with the coordinates
  //of the element's row and column and the third blank should be replaced
  //with the value of that element

  



 return 0;
}
