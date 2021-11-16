#include "gaussian.h"

void Gaussian::Apply(std::vector<Image*> original, std::vector<Image*> filter){
    *filter[0] = *original[0];

    unsigned char *pixel;
    unsigned char buffer[4]={0,0,0,0};
    unsigned char avgPixel[4]={0,0,0,255};
    double gaus_kernal[5][5];
    double sigma=2.0;
    double sum=0;
    //calcluate the values for the gaussian kernal
    for (int i=-2 ; i<=2 ; i++) {
        for (int j=-2 ; j<=2 ; j++) {
            gaus_kernal[i+2][j+2] = exp(-(i*i+j*j)/(2*sigma*sigma))/(2*M_PI*sigma*sigma);
            sum+=gaus_kernal[i+2][j+2];
        }
    }
    //standersdize the values in the kernal sum is equal to 1
    for (int i=-2 ; i<=2 ; i++) {
        for (int j=-2 ; j<=2 ; j++) {
            gaus_kernal[i+2][j+2] /= sum;
        }
    }
    //lloop through the image and multiply all the values of pixals by the kernal
    for (int x=0; x<original[0]->GetWidth(); x++){
        
        for (int y=0; y<original[0]->GetHeight(); y++){
           	double avg=0;
            for (int a=x-2; a<=x+2; a++){
                //loop to multipl the pixels witht eh gaussian kernal
                for (int b=y-2; b<=y+2; b++){
                    //in case the pixel is out of range for the photot we set it to zero as padding
                    if(a<0 || b<0 || a>original[0]->GetWidth() || b>original[0]->GetHeight()){ 
                        pixel = buffer;
                    }
                    else{
                        pixel = original[0]->GetPixel(a,b); 
                    }
                    avg += (pixel[0]*gaus_kernal[a-x+2][b-y+2]);
                }
            }
        //take the sum all the kernal multiplaication and assigne it to the RGB values
        avgPixel[0] = avg;
        avgPixel[1] = avg;
        avgPixel[2] = avg;
       
		filter[0]->SetPixel(x,y,avgPixel);  //set the pixel
        }
    }
}