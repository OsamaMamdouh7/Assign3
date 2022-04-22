/*
// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: CS112-203-2ND-S13-20210061-2021713-2020439.cpp
// Last Modification Date: 2022/4/7
// Author1 and ID and Group: Osama Mamdouh - 20210061 - Group B - S13-S14
// Author2 and ID and Group: Mazin El-taher - 20210713 - Group B - S13-S14
// Author3 and ID and Group: Muhammed Hamed - 20200439 - Group B - S13-S14
// Teaching Assistant: Nesma Mohammed

*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;
int i,j,l,k,p,q,ch,ch2,chose;
char choose;
unsigned char image[SIZE][SIZE] , newimage[SIZE][SIZE];
void loadImage ();
void saveImage ();
void Rotate_Image ();
void Flip_Image_Horizontally ();
void Invert_Image ();
void Black_White ();
void Flip_Imagee_Vertically();
void Darken_Lighten();
void Detect_Image_Edges();
void Mirror_Image();
int main()
{
    loadImage ();
    cout<<"Please select a filter to apply or 0 to 13 : "<<endl
        <<"1- Black & White Filter"<<endl
        <<"2- Invert Filter"<<endl
        <<"3- Merge Filter"<<endl
        <<"4- Flip Image"<<endl
        <<"5- Darken and Lighten Image"<<endl
        <<"6- Rotate Image"<<endl
        <<"7-Detect Image Edges"<<endl
        <<"8- Enlarge Image"<<endl
        <<"9- Shrink Image"<<endl
        <<"(10)a- Mirror 1/2 Image"<<endl
        <<"(11)b- Shuffle Image"<<endl
        <<"(12)c- Blur Image"<<endl
        <<"(13)s- Save the image to a file"<<endl
        <<"0- Exit"<<endl;
    cin>>ch;

    switch(ch)
    {

        case 1:
            Black_White();
            break;
        case 2:
            Invert_Image();
            break;
        case 4:
            cout<<"Flip (1)horizontally or (2)vertically ";
            cin>>ch;
            if (ch==1)
                Flip_Image_Horizontally();
            else if (ch=2)
                Flip_Imagee_Vertically();
            break;
        case 5:
            Darken_Lighten();
            break;
        case 6:
            cout<<"Rotate (90), (180) or (270) degrees? : ";
            cin>>ch;
            if (ch==270)
                Rotate_Image();
                break;
        case 7:
            void Detect_Image_Edges();
            break;
        case 10:
             Mirror_Image();

            break;
        default:
            cout<<"Please enter 0 to 13 ";
    }
    saveImage ();
    return 0;
}
void loadImage ()
{
    char imageFileName[100];
    char newimageFileName[100];
    cout<<"Ahlan ya user ya habibi :) "<<endl
        <<"Please enter file name of the image to process :  ";
    cin>>imageFileName;
    strcat(imageFileName,".bmp");
    readGSBMP(imageFileName,image);
    readGSBMP(imageFileName,newimage);
}

void saveImage ()
{ char imageFileName[100];
    cout<<"Please enter (save) target file name :" ;
    cin>>imageFileName;
    strcat(imageFileName,".bmp");
    writeGSBMP(imageFileName,image);
//writeGSBMP(imageFileName,newimage);

}
void Rotate_Image ()
{


    for (i = 0; i <  SIZE ; i++)
    {
        for (j = 0; j <  SIZE ; j++)
        {
            newimage[i][j]==image[i][j];

        }
    }

    for (i = 0,p = 0; i < (SIZE) && p <( SIZE); i++ ,p++ )

    {
        for (j = 0, q = SIZE; j < SIZE && q >  0; j++, q--)
        {
            l=newimage[i][j];
            image[q][p] = l;


        }

    }
}
void Flip_Image_Horizontally (){
//flip 1
    for (i = 0; i <  SIZE ; i++)

    {
        for (j = 0, p = SIZE; j < (SIZE/2) && p >( SIZE/2); j++, p--)
        {
            l=image[i][j];
            k=image[i][p];
            image[i][j] = k;
            image[i][p] = l;


        }

    }
}

void  Invert_Image ()
{

    for ( i =0; i<SIZE;i++)
    { for ( j =0; j<SIZE;j++)
        {




            if(image[i][j]>127) //this mean ,those pixels are White
                image[i][j]=255-(image[i][j]);
            else
                image[i][j]=255-(image[i][j]);

        }
    }
}

void Black_White ()
{

    for ( i =0; i<SIZE;i++)
    { for ( j =0; j<SIZE;j++)
        {




            if(image[i][j]>127)
                image[i][j]=0;
            else
                image[i][j]=255;

        }
    }
}
void Flip_Imagee_Vertically (){

    for (i = 0; i <  SIZE ; i++)

    {
        for (j = 0, p = SIZE; j < (SIZE/2) && p >( SIZE/2); j++, p--)
        {
            l=image[i][j];
            k=image[i][p];
            image[i][j] = k;
            image[i][p] = l;


        }

    }

}
void Darken_Lighten()
{
    cout << "1- Darken"<< endl;
    cout << "2- Lighten" << endl;
    cin >> choose;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if(choose== 1)
                image[i][j] = (image[i][j])/2;
            else if (choose== 2)
                image[i][j] = ((image[i][j])/2)+ 127;
        }

    }
}

void Detect_Image_Edges()
{

  for ( i =0; i<SIZE;i++)
    { for ( j =0; j<SIZE;j++)
{
        if (((newimage[i+1][j])-(newimage[i-1][j]))>35)
            image[i][j]=0;
        else if (((newimage[i-1][j])-(newimage[i+1][j]))>35)
            image[i][j]=0;
        else if (((newimage[i][j-1])-(newimage[i][j+1]))>35)
            image[i][j]=0;
        else if (((newimage[i][j+1])-(newimage[i][j-1]))>35)
            image[i][j]=0;
        else
            image[i+1][j]=255;

}
  }
}

void Mirror_Image()
{
cout<<"Mirror (l)eft, (r)ight, (u)pper, (d)own side? : ";

cin>>choose;
int i=3;
while(i>2)
{


switch(choose){
  case 'l':
      for ( i =0; i<SIZE;i++)
    { for ( j =0,p=SIZE; j<SIZE && p>(SIZE/2); j++,p--)
{

image[i][p]=l;
l=image[i][j];



}
  }
  i=1;
  break;

  case 'r':
      for ( i =0; i<SIZE;i++)
    { for ( j =0,p=SIZE; j<SIZE && p>(SIZE/2); j++,p--)
{

image[i][j]=l;
l=image[i][p];



}
  }
  i=1;
  break;

  case 'u':
       for ( i =0; i<SIZE;i++)
    { for ( j =0,p=SIZE; j<SIZE && p>(SIZE/2); j++,p--)
{

image[p][i]=l;
l=image[j][i];



}
  }
  i=1;
  break;

  case 'd':
       for ( i =0; i<SIZE;i++)
    { for ( j =0,p=SIZE; j<SIZE && p>(SIZE/2); j++,p--)
{

image[j][i]=l;
l=image[p][i];



}
  }
i=1;
break;

  default:
    cout<<"Please choose l,r,u or d ! : ";

}
}




}
