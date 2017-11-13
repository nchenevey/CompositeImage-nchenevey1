#include <iostream>
#include <vector>
#include <string>
#include "bitmap.h"

using namespace std;
//Asks the user for file names until Done or 10 files entered
vector<string> askUser(int, int, vector<string>);


vector< vector <int> > instaResize( vector< vector <int> >, vector< vector <Pixel> >);

vector< vector <Pixel> > pixelResize( vector< vector <Pixel> >, vector< vector <Pixel> >);

//Accepts a vector of bitmap file names and combines them into a matrix
vector< vector <Pixel> > rgbAverages(vector <string> );

//Prints a progress update if the current image is successfully combined
void progress(bool);

int main()
{
//Ask user for file name until DONE or max files have been entered (10)(function?)
//print an error for any file that doesn't work(function?)
//Combine the images provided to create a composite image
//print progress updates(function?)
//save the composite image file
Bitmap image;
vector< vector <Pixel> > pmb;
Pixel rgb;
int rows1;
int cols1;
vector<string> cocoa;
string sweet;
bool validBmp;
cocoa.resize(1);

do
{
cout<<"Please enter the file name of a valid bitmap."<<endl;
cin>>sweet;
image.open(sweet);
validBmp = image.isImage();

if(validBmp == false)
{
cout<<"This file either does not exist or is not a valid bitmap."<<endl;
}

}while(validBmp == false);

pmb = image.toPixelMatrix();
rows1 = pmb.size();
cols1 = pmb[0].size();
cocoa[0] = sweet;
vector<string> test1;

test1 = askUser(rows1, cols1, cocoa );
cout<<"Test 1 complete"<<endl;

vector< vector <Pixel> > test2;
test2 = rgbAverages(test1);
cout<<"Test 2 complete"<<endl;

image.fromPixelMatrix( test2 );
image.save("composite-nchenevey1.bmp");

/*
image.fromPixelMatrix( rgbAverages( askUser( rows1, cols1, cocoa ) ) );
image.save("composite-nchenevey1.bmp");
*/



return 0;
}
//Functions
vector<string> askUser(int height, int width, vector<string> pumpkin)
{
    string temper;
    Bitmap img;
    vector< vector <Pixel> > bmp;
    Pixel rgb;
    int num = 1;

    do
    {
    cout<<"Please enter the file name of a bitmap or enter 'done' to continue."<<endl;
    cin>>temper;
    if( temper == "DONE" || temper == "done" )
    {
        break;
    }
    img.open(temper);
    bool validBmp = img.isImage();
    if(validBmp == false)
    {
        cout<<"This file doesn't exist or is not a valid bitmap."<<endl;
    }
    else if(validBmp == true)
    {
        bmp = img.toPixelMatrix();

        if(bmp.size() != height && bmp[0].size() != width)
        {
            cout<<"This bitmap does not have the same dimensions as the first image"<<endl;
        }
        else
        {
           num++;
           pumpkin.resize(num);
           pumpkin[num-1] = temper; 
           

        }
    }

    }while(temper != "DONE" && temper != "done" && pumpkin.size() < 10 );
return pumpkin;
}


vector< vector <Pixel> > rgbAverages(vector <string> namae)
{  
    vector< vector <int> > temporalRed;
    vector< vector <int> > temporalGreen;
    vector< vector <int> > temporalBlue;

    Bitmap pic;

    vector< vector <Pixel> > bmp;
    vector< vector <Pixel> > neko;

    temporalRed = instaResize(temporalRed, bmp);
    temporalGreen = instaResize(temporalGreen, bmp);
    temporalBlue = instaResize(temporalBlue, bmp);
    
    neko = pixelResize(neko, bmp);

    Pixel rgb;
    for(int i = 0; i < namae.size(); i++)
    {
        pic.open(namae[i]);
        bmp = pic.toPixelMatrix();
        for(int rows = 0; rows < bmp.size(); rows++)
        {
            for(int cols = 0; cols < bmp[0].size(); cols++)
            {
              rgb = bmp[rows][cols];
              temporalRed[rows][cols] = temporalRed[rows][cols] + rgb.red;
              temporalGreen[rows][cols] = temporalGreen[rows][cols] + rgb.green;
              temporalBlue[rows][cols] = temporalBlue[rows][cols] + rgb.blue;
              /*
              rgb.red = temporalRed[rows][cols];
              rgb.green = temporalGreen[rows][cols];
              rgb.blue = temporalBlue[rows][cols];
              neko[rows][cols] = rgb;
              */
            }
        }
    cout<<"Image "<<i<<" of "<<(namae.size()-1)<<" done."<<endl;
    }

    for(int r = 0; r < neko.size(); r++)
    {
        for(int c = 0; c < neko[0].size(); c++)
        {
        rgb = neko[r][c];
        rgb.red = (temporalRed[r][c]/namae.size());
        rgb.green = (temporalGreen[r][c]/namae.size());
        rgb.blue = (temporalBlue[r][c]/namae.size());
        neko[r][c] = rgb;
        }
    }
return neko;
}

vector< vector <int> > instaResize( vector< vector <int> > inst1, vector< vector <Pixel> > inst2)
{
int tempting = inst2.size();
int templar = inst2[0].size();
for(int box1 = 0; box1 < inst2.size(); box1++)
{
    inst1.resize(tempting);
    for(int box2 = 0; box2 < inst2[0].size(); box2++)
    {
        inst1[box1].resize(templar);
    }
}

return inst1;
}

vector< vector <Pixel> > pixelResize( vector< vector <Pixel> > romeo, vector< vector <Pixel> > juliet)
{
int temperature = juliet.size();
int temptress = juliet[0].size();
for(int box = 0; box < juliet.size(); box++)
{
    romeo.resize(temperature);
    for(int boxbox = 0; boxbox < juliet[0].size(); boxbox++)
    {
        romeo[box].resize(temptress);
    }
}
}







