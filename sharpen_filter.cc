

#include "sharpen_filter.h"

void Sharpen::Apply(std::vector<Image*> og, std::vector<Image*> filtered){
    *filtered[0] = *og[0];
	unsigned char *pixel;
	unsigned char buffer[4] = {0,0,0,0};
	unsigned char avgPixel[4] = {0,0,0,255};

    for (int x=0; x<og[0]->GetWidth(); x++){
        for (int y=0; y<og[0]->GetHeight(); y++){

			// loop around surrounding pixels
			for (int a=x-1; a<=x+1; a++){
				for (int b=y-1; b<=y+1; b++){
                    
                    // edge detection
					if(a<0 || b<0 || a>og[0]->GetWidth() || b>og[0]->GetHeight()){ 
						pixel = buffer;
					}
					else{
						pixel = og[0]->GetPixel(a,b); 

					}

                    if (a==x && b==y){
                        avgPixel[0] += pixel[0]*(5);
                        avgPixel[1] += pixel[1]*(5);
                        avgPixel[2] += pixel[2]*(5);	                        
                    }
                    else if ( (a==x-1 && b==y) || (a==x && b==y+1) || (a==x && b==y-1) || (a==x+1 && b==y)){
                        avgPixel[0] += pixel[0]*(-1);
                        avgPixel[1] += pixel[1]*(-1);
                        avgPixel[2] += pixel[2]*(-1);
                    }
					else{
						avgPixel[0] += pixel[0]*(0);
                        avgPixel[1] += pixel[1]*(0);
                        avgPixel[2] += pixel[2]*(0);
					}
				}
			}
		filtered[0]->SetPixel(x,y,avgPixel);
		avgPixel[0] = 0;
		avgPixel[1] = 0;
		avgPixel[2] = 0;
        }
    }
}

/*
[ 0 -1  0]
[-1  5 -1]
[ 0 -1  0]
*/