/*
 FCAI - Programming 1 - Assignment 3 - 2022
 Author 1: Abdelrhman Mohamed Ezzat  20210208
 Author 2: Youssef Emad el din Ali 20210479
 Author 3:
 Group B - S13-S14
 TA ->
 */
#include <bits/stdc++.h>
#include "bmplib.h"
#include "bmplib.cpp"
unsigned char image[SIZE][SIZE];
unsigned char outputImage[SIZE][SIZE];
void saveImage();
void InvertImage();
void RotateImage(int degree);
void EnlargeImage(int m);
string lower(string text);
void mergeImages();
void changeBrightness();
void readImage(bool imageNum = false);
using namespace std;

int main(){
    while(true){
        cout << "What do you want to do?\n";
        cout << "2.Invert Image\n" << "3.Merge two images\n" << "5.Rotate Image\n"
                << "6.Change Image brightness" << "8.Enlarge Image\n"
                << "s. save image\n" << "e. end\n";
        char k;
        cin >> k;
        if (k == '2'){
            readImage();
            InvertImage();
        }
        else if (k == '3'){
            readImage(true);
            mergeImages();
        }
        else if (k == '5'){
            readImage();
            cout << "Rotate Image by 90 or 180 or 270 degree clockwise?";
            int degree;
            cin >> degree;
            RotateImage(degree);
        }
        else if (k == '6'){
            readImage();
            changeBrightness();
        }
        else if (k == '8'){
            readImage();
            int m;
            cout << "Which quarter do you want to enlarge 1 or 2 or 3 or 4: ";
            cin >> m;
            EnlargeImage(m);
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
void readImage(bool imageNum ){
    char imageName[100];
    cout << "Enter image name: ";
    cin >> imageName;
    strcat(imageName, ".bmp");
    readGSBMP(imageName, image);
    cin.clear();
    cin.sync();
    if (imageNum)
    {
        char imageName2[100];
        cout << "Enter second image name: ";
        cin >> imageName2;
        cin.clear();
        cin.sync();
        strcat(imageName2, ".bmp");
        readGSBMP(imageName2, outputImage);
    }
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
string lower(string text){
    for (int i = 0; i < text.length(); i++){
        text[i] = tolower(text[i]);
    }
    return text;
}
void mergeImages(){

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            outputImage[i][j] = (image[i][j] + outputImage[i][j]) / 2;
        }
    }
}
void changeBrightness(){
    string func;
    int neg;
    while (true){
        cout << "What do you want to do Brighten / Darken: ";
        getline(cin, func);
        func = lower(func);
        if (func == "brighten" || func == "darken"){
            break;
        }
    }
    neg = (func == "brighten") ? 1 : -1;
    int average;
    int tempValue;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            average += image[i][j];
        }
    }
    average /= (256 * 256);
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            tempValue = image[i][j] + neg * average / 2;
            if (tempValue > 255){
                outputImage[i][j] = 255;
            }
            else if (tempValue < 0){
                outputImage[i][j] = 0;
            }
            else{
                outputImage[i][j] = tempValue;
            }
        }
    }
}
