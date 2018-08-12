//Lab 2
//Universidad del Valle de Guatemala
//Christian Medina Armas


#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <iostream>
#include <sstream>
#include <cstdlib>


using namespace std;
using namespace cv;


//function prototypes
Mat& scanImage(Mat&, int);
int showImage(Mat, int);

int main( int argc, char *argv[]){

    // Verificamos los argumentos
    if (argc < 4){
        cout<< "Not enough arguments"<< endl;
        return -1;
    }

    // Cargamos la imagen a color o blanco y negro
    Mat source;
    ( !strcmp(argv[2],"c") ? source = imread(argv[1], IMREAD_COLOR) : source = imread(argv[1], IMREAD_GRAYSCALE) );
    showImage(source, (argv[3][0]+argv[3][1]));

}

int showImage(Mat img, int scale){
    
    // Verifcar que haya imagen
    if(img.empty()){
        cout << "The image" << img << " could not be loaded." << endl;
    return -1;
    }

    // Creamos la ventana para mostrar la imagen
    namedWindow( "Imagen", WINDOW_NORMAL);
    // Obtenemos la escala
    scale = scale / 100;
    // Cambiamos el tamaño de la imagen
    resizeWindow("Imagen", (img.rows * scale), (img.cols * scale));
    // Mostramos la imagen
    imshow("Imagen", img);
    //Esperamos la interrupcion
    waitKey(0);
    return 0;
}


//-----------------------------------------------------------
//
//-----------------------------------------------------------
Mat& scanImage(Mat& input, int k){

    //verify that the pixels are type CV_8U AKA 8-bit unsigned integers  0..255)
    CV_Assert(input.depth() == CV_8U);

    //get number of channels
    // IMREAD_GRAYSCALE = 1
    // IMREAD_COLOR = 3
    int channels = input.channels();

    int rows = input.rows;
    int cols = input.cols * channels;

    //test if image is stored in a continous memory space
    if (input.isContinuous()){
        cols *= rows;
        rows = 1;
    }


    switch(channels){

    case 1:{
        //declare pointer
        uchar* p;

        for( int i=0; i<rows; ++i){

	    //get pointer to image
            p = input.ptr<uchar>(i);

            for (int j=0; j<cols; ++j){
                p[j] = p[j] + k;
            }
        }
    }
    case 3:{
	//your code goes here
    }

    } 
    return input;
}
//-----------------------------------------------------------
