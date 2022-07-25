#include <bits/stdc++.h>
#include "bmplib.h"
#include "bmplib.cpp"
unsigned char image[SIZE][SIZE];
unsigned char outputImage[SIZE][SIZE];
void loadImage();
void saveImage();
void InvertImage();
void RotateImage(int degree);
void EnlargeImage(int m);
using namespace std;

int main(){
    while(true){
        cout << "What do you want to do?\n";
        cout << "2.Invert Image\n" << "5.Rotate Image\n" << "8.Enlarge Image\n" << "l. load image\n"
                << "s. save image\n" << "e. end\n";
        char k;
        cin >> k;
        if (k == '2'){
            InvertImage();
        }
        else if (k == '5'){
            cout << "Rotate Image by 90 or 180 or 270 degree clockwise?";
            int degree;
            cin >> degree;
            RotateImage(degree);
        }
        else if (k == '8'){
            int m;
            cout << "Which quarter do you want to enlarge 1 or 2 or 3 or 4: ";
            cin >> m;
            EnlargeImage(m);
        }
        else if(k == 'l'){
            loadImage();
        }
        else if(k == 's'){
            saveImage();
        }
        else if (k == 'e'){
            cout << "Program ends\n";
            break;
        }
    }

    return 0;
}
void loadImage(){
    char ImageFileName[100];
    cout << "Enter the source image file name: ";
    cin >> ImageFileName;
    strcat(ImageFileName,".bmp");
    readGSBMP(ImageFileName,image);
}

void saveImage(){
    char ImageFileName[100];
    cout << "Enter the image file name: ";
    cin >> ImageFileName;
    strcat(ImageFileName,".bmp");
    writeGSBMP(ImageFileName,outputImage);
}
void InvertImage(){
    for(int i = 0;i < SIZE;i++){
        for (int j = 0;j < SIZE;j++){
            outputImage[i][j] = 255 - image[i][j];
        }
    }
}
void RotateImage(int degree){
    if (degree == 90){
        for (int i = 0;i < SIZE;i++){
            for (int j = SIZE;j > 0;j--){
                outputImage[i][j] = image[SIZE - j][i];
            }
        }
    }
    else if (degree == 180){
        for (int i = 0;i < SIZE;i++){
            for (int j = 0;j < SIZE;j++){
                outputImage[i][j] = image[SIZE - i][SIZE - j];
            }
        }
    }
    else if (degree == 270){
        for (int i = 0;i < SIZE;i++){
            for (int j = 0;j < SIZE;j++){
                outputImage[SIZE - j][i] = image[i][j];
            }
        }
    }
}
void EnlargeImage(int m){
    if (m == 1){
        for (int i = SIZE;i > 0;i-=2){
            for (int j = SIZE;j > 0;j-=2){
                outputImage[i][j] = image[i / 2][j / 2];
                outputImage[i - 1][j] = image[i / 2][j / 2];
                outputImage[i][j - 1] = image[i/2][j/2];
                outputImage[i - 1][j - 1] = image[i / 2][j / 2];
            }
        }
    }
    else if (m == 2){
        for (int i = SIZE;i > 0;i-=2){
            for (int j = SIZE;j < 512;j+=2){
                outputImage[i][j - SIZE] = image[i / 2][j / 2];
                outputImage[i - 1][j - SIZE + 1] = image[i / 2][j / 2];
                outputImage[i][j - SIZE + 1] = image[i / 2][j / 2];
                outputImage[i - 1][j - SIZE] = image[i /2][j/2];
            }
        }
    }
    else if (m == 3){
        for (int i = SIZE;i < 512;i += 2){
            for (int j = SIZE;j > 0;j -= 2){
                outputImage[i - SIZE][j] = image[i / 2][j / 2];
                outputImage[i - SIZE + 1][j] = image[i / 2][j / 2];
                outputImage[i - SIZE + 1][j -1] = image[i / 2][j / 2];
                outputImage[i - SIZE][j - 1] = image[i / 2][j / 2];
            }
        }
    }
    else if(m == 4){
        for (int i = SIZE;i < 512;i+=2){
            for (int j = SIZE;j < 512;j+=2){
                outputImage[i - SIZE][j - SIZE] = image[i / 2][j / 2];
                outputImage[i - SIZE + 1][j - SIZE + 1] = image[i / 2][j / 2];
                outputImage[i - SIZE][j - SIZE + 1] = image[i / 2][j / 2];
                outputImage[i - SIZE + 1][j - SIZE] = image[i / 2][j / 2];
            }
        }
    }
}