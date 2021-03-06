#include "sobel.h"

void  Sobel::Apply(std::vector<Image*> original, std::vector<Image*> filter){
    *filter[0] = *original[0];
    *filter[1] = *original[0];

    unsigned char *pixel;
    unsigned char buffer[4]={0,0,0,0};
    unsigned char avgPixel[4]={0,0,0,255};
    double kernelx[3][3] = { { -1, 0, 1 },{ -2, 0, 2 },{ -1, 0, 1 } }; //kernel for X diection

    double kernely[3][3] = { { -1, -2, -1 },{ 0,  0,  0 },{ 1,  2,  1 } }; //kernel for Y direction

    //loops through the image and multiply each pixel by X and Y values
    for (int x=0; x<original[0]->GetWidth(); x++){
        
        for (int y=0; y<original[0]->GetHeight(); y++){
           	
		double magnitudeX=0; //the value of pixel when multiplying with kernal X
        double magnitudeY=0; //the value of pixel when multiplying with kernal Y
            for (int a=x-1; a<=x+1; a++){
                //loop that multiplies sincle pixel by the kernal
                for (int b=y-1; b<=y+1; b++){
                    //in case the pixel is out of image we padd it as 0
                    if(a<0 || b<0 || a>original[0]->GetWidth() || b>original[0]->GetHeight()){ 
                        pixel = buffer;
                    }
                    else{
                        pixel = original[0]->GetPixel(a,b); 
                    }
                    //calcululation for mag X and Y
                    magnitudeX+=pixel[0]*kernelx[a-x+1][b-y+1];
                    magnitudeY+=pixel[0]*kernely[a-x+1][b-y+1];
                }
            }

        //for intetnsity we calculate the second norm of mag X and Y and assign it to the filter
        avgPixel[0] = ceil(sqrt(pow(magnitudeX,2) + pow(magnitudeY,2)));
        avgPixel[1] = avgPixel[0];
        avgPixel[2] = avgPixel[0];
       
		filter[0]->SetPixel(x,y,avgPixel);


        //for direction we take the arctan multiplied by 180/pi to get the desicred direction value

        double direction = atan2(magnitudeY,magnitudeX);
        if(direction>0){
            direction=abs(direction*180/3.1415);
        }
        else{
            direction=abs(direction*90/3.1415);
        }
        avgPixel[0] = direction;
        avgPixel[1] = avgPixel[0];
        avgPixel[2] = avgPixel[0];
        filter[1]->SetPixel(x,y,avgPixel);
        }
    }
}