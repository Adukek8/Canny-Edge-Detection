#include "image.h"

// Needed for reading images
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Needed for writing images
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <string>

Image::Image(int widthC, int heightC): width(widthC), height(heightC), components(4){
    buffer= new unsigned char [width*height*components];
}

Image::Image(string filename){

    char *file=&*filename.begin();

    unsigned char *image = stbi_load(file, &width, &height, &components, STBI_rgb_alpha);
    components=4;

    buffer= new unsigned char [width*height*components];
    copy(image, image + width*height*components, buffer);
    stbi_image_free(image);
}

Image::Image(const Image& image){
    *this=image;
}

Image::~Image(){
    delete[] buffer;
}

int Image::GetHeight(){
    return height;
}

int Image::GetWidth(){
    return width;
}

int Image::GetComponentNum(){
    return components;
}

unsigned char* Image::GetPixel(int x, int y){
    static unsigned char pixel[4];
    for(int i=0; i<4; i++){
        pixel[i]=buffer[(y*width + x)*4+i];
    }
    return pixel;
}

void Image::SetPixel(int x, int y, unsigned char* pixel){
    for(int i=0; i<4; i++){
        buffer[(y*width + x)*4+i]=pixel[i];
    }
}

void Image::SaveAs(string filename){
    char *file=&*filename.begin();
    stbi_write_png(file, width, height, components, buffer, width*4);
}

void Image::operator=(const Image& image){
    delete[] buffer;
    buffer= new unsigned char[image.width*image.height*image.components];
    memcpy(buffer,image.buffer,image.width*image.height*image.components);
}

