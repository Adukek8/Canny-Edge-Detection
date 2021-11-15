/*! \mainpage Edge Detection Filter
 *
 * \section intro_sec Introduction
 *
 * The goal of this project is to create an edge detection filter. This is done through several 
 * intermediate convolution filters, which are all driven by a central main method. These filters
 * can also be run independently, making it much more versatile. Due to the inheritance structure
 * of the software, new filters can easily be added on or removed. This is covered in more depth later.
 *
 *
 * \section quick_start Quick Start Guide
 *
 *  The usage of this software is as follows:
 *      -# Copy the image you are trying to manipulate into the "data" folder
 *      -# Run "make clean" in the folder on command line to clean the project before use
 *      -# Run "make" to compile the program
 *      -# Run the image filters by using the following format: 
 *          - ./image_processor <input_image_path> <filter> <output_image_path>
 *          - ex: ./image_processor data/statue.png hysteresis_filter data/statue_hysteresis.png
 *      -# The processed image will be available in the path you specify, and can have more filters applied to it. The possible filters are listed here:
 *          - greyscale
 *          - gaussian_blur
 *          - sobel
 *          - non_max_suppression
 *          - double_threshold
 *          - hysteresis
 *          - canny-edge-detect
 *          - night_vision
 *          - sharpen
 *
 * \section class_overview Class Overview
 * 
 * \subsection greyscale Greyscale Filter
 * 
 * The greyscale filter converts a color image to black and white, which is essential for the function of the edge detection. 
 * This filter goes through and sets each pixel to the luminosity value of that pixel, which will turn it to black and white. The algorithnm 
 * follows the process:
 *      - Copy image into a new image for the output
 *      - for each pixel in the original image, check the luminance
 *      - set the new pixel's RGB values each to the luminance of the pixel
 *      - return the filtered image
 * 
 * \subsection gaussian Gaussian Blur Filter
 * 
 * Gaussian blur was necessary to smooth out the image prior to running the other edge detection filters, as 
 * a means to remove image "noise". Future filters are exremely sensitive to noise, so to ensure that legitimate 
 * edges are demarcated by the canny edge detector, the entire image should be smoothed. This filter is implemented
 * througha a class which contains a constructor and an Apply method. The apply method takes the original image
 * and a filter as arguments, and constructs a blurred image to be passed through future algorithms. 
 * Algorithmically, the gaussian blur can be described by:
 *     - create matrix of the orginal image size
 *     - claculte the gaussian kernal of size 5 using the sigma=2.0
 *     - multiply every pixel of the image by the gaussian kernal
 *     - in case the pixel is outside the image it is considered to be the value of 0
 *     - return the proccesed image
 *
 *\subsection sobel Sobel Filter
 *
 * The next step of the canny edge detection process is to use a gradient step calculation to determine the
 * intensity and direction of the pixels of the smoothed over image. Derivatives indicative of intensities and
 * direction are derived from the smoothed matrix, for both horizontal and vertical components. These derivatives
 * are then output as direction and intsensity matrices. Algorithmically, this looks like:
 *     -create two matrices of the orginal image size
 *     -each pixel is multiplied by both X and Y direction matrices to get magnitude for X and Y
 *     -in case the pixel is outside the image it is considered to be the value of 0
 *     -calculating the second norm of those values we ge the pixel value of intensity matrix
 *     -calculating the arctan of their devision we get the direction matrix pixel value
 *     -return the intensity and direction pictures
 *
 * \subsection non_max Non-Max Suppression Filter
 * 
 * Non-max suppression was necessary to thin out the edges of the Sobel output. This class contains a constructor
 * and an Apply method. The apply method takes the intensity and edge-direction Sobel filter output as inputs, as well
 * as the original image. The algorithm then traverses all pixels in the gradient intensity matrix and determines each
 * pixel's maximum direction value. Algorithmically, this takes the form:
 *     - create a matrix of the size of the original image (initialize all matrix values to zero)
 *     - iterate through pixels and determine the angle value
 *     - check if the pixel in the direction of the angle has a value less than or greater than the current pixel
 *     - set pixels without high intensity to black. Keep high-intensity pixels
 *     - return the processed image
 *
 * \subsection double_threshold Double Threshold Filter
 *
 * The double threshold filter is necessary for the hysteresis filter to properly sharpen the edges. It is essentially two
 * thresholds which are both applied to an image.This class contains a constructor, max, getLuminance, and Apply methods.
 * The algorithm processes the image and sets pixels to either zero(black), weak(grey), or strong(white). These pixels are 
 * applied based on the luminance of the original image, and applied to the output image. Algorithmically, this takes the form:
 *      - create a copy of the original image to modify
 *      - loop through every image in the original image and find the one with maximum luminosity
 *      - calculate high and low threshold based on the max pixel value
 *      - for each pixel in the image, check if the luminosity of the pixel corresponds to zero(below low), weak(between low and high),
 *          or strong(above high) 
 *      - apply the appropriate value to the current pixel
 *      - return the filtered image
 * 
 * \subsection hysteresis Hysteresis Filter
 *
 * The hysteresis filter strengthens the sharpness of the edges by taking the double threshold and creating a single threshold essentially.
 * This class has getLuminance and Apply methods. The image is iterated through and if a "weak" pixel is located, it will check the 
 * surrounding pixels to see if there is a strong pixel neighboring the weak. If there is, the weak will be updated to be a strong pixel, 
 * otherwise it will be changed to a zero(black) pixel. The algorithm for this takes the form:  
 *      - create a copy of the original image to modify
 *      - for each pixel in the image, check the luminocity of the pixel
 *      - if the pixel's luminocity is weak, loop through the neighboring pixels
 *      - if there is a strong pixel neighboring, set the pixel to strong. Otherwise set it to weak
 *      - return the filtered image
 *
 *
 * \subsection canny_edge Canny Edge Detection Filter
 *
 * The Canny Edge Detection filter is a compilation of the six previous filters. It runs them all back to back on the same image, which will
 * end with a hysteresis filter and therefore edge detection. The order of the filters is as follows:
 *      - greyscale
 *      - gaussian blur
 *      - sobel
 *      - non-max suppression
 *      - double threshold
 *      - hysteresis
 *
 * \subsection inversion Image Inversion Filter
 *
 * Image inversion is a filter that was implemented as a supplement to the canny edge detection image. It can be used
 * to flip the pixel values of an image. This class contains a constructor and an Apply method. The apply method takes
 * in the original image and a filter image, and outputs an inverted image of the original matrix. Algorithmically, this
 * takes the form:
 *     - create a matrix of the size of the original image (initialize all matrix values to zero)
 *     - for each pixel in the image, determine the inverse of the RGB color scheme of the pixel
 *     - set the corresponding pixel in the filter image to be the value of the pixel inverse
 *     - return the filter image
 *
 *
 * \subsection nightvision Night Vision Filter
 *
 * Nightvision is a filter that was implemented as a supplement to the canny edge detection image. The human eye can 
 * see more shades of green than any other color, so it may be useful down the line to generate images with only green 
 * intensities. It can be used to derive an image comprised entirely of green pixels. This class contains a constructor 
 * and an Apply method. The apply method takes in the original image and a filter image, and outputs a "greenscaled" image 
 * of the original matrix. Algorithmically, this takes the form:
 *    - create a matrix of the size of the original image (initialize all matrix values to zero) 
 *    - for each pixel in the image, determine the inverse of the RGB color scheme of the pixel
 *    - set the corresponding pixel in the filter image to be (0, original green value, 0)
 *    - return the filter image
 *
 *
 * \section extension Extending the System with New Filters
 *
 * The design of this system allows for ease of addition of more filters by simpling using inheritance. In order to create a new filter,
 * create a new class for the filter and import "filter.h" and "image.h". This will allow you to inherit from the filter class, and you can
 * then implement the new algorithm. In order to run it from the command line, simply add on to the filters unique pointer and create a 
 * unique pointer for your new filter. Following the format "filters["<command_line_filter_name>"] = unique_ptr<Filter>(new <Filter_class_name>());"
 *
 *
 *
 *
 *
 *

 */