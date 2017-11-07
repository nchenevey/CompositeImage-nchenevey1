#include <iostream>
#include <vector>
#include <string>
#include "bitmap.h"

using namespace std;
//Asks the user for file names until Done or 10 files entered
vector<string> askUser(string);

//If an image does not meet the requirements then this will print out an error

//Combines the RGB values of two images
void combine( vector<string> );

//Prints a progress update if the current image is successfully combined
void progress(bool);

int main()
{
//Ask user for file name until DONE or max files have been entered (10)(function?)
//print an error for any file that doesn't work(function?)
//Combine the images provided to create a composite image
//print progress updates(function?)
//save the composite image file

vector<string> pictures;
Bitmap pic;
vector<vector<Pixel> > bmp;
Pixel rgb;
string temp;

for(int index = 0; index < 10; index++)
{
    cout<<"Please enter file name."<<endl;
    cin>>temp;
    pic.open(temp);
    bool validBmp = pic.isImage();
    if( validBmp == false)
    {
        cout<<"File either doesn't exist or is not a valid bitmap."<<endl;
        index--;
    }
    if( validBmp == true)
    {
        int height;
        int width;
        if(index = 0)
        {
            height = bmp.size();
            width = bmp[0].size();
        }
        else if( bmp.size() == height && bmp[0].size() == width)
        {
            pictures[index] = temp;
        }
        else
        {
        cout<<"Please make sure the image has the same dimensions as previous images"<<endl;
        index--;
        }
    }
}








 return 0;

}

