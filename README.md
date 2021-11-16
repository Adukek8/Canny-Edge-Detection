# Canny-Edge-Detection

Canny edge detection is a popular multi-stage image processing algorithm that detects a range of edges in images. The process begins with converting the image to greyscale, and then smoothing the image through a Gaussian blur. The image is convolved with a Gaussian kernel (in this project, a 5x5) to create a blurring effect.

The next step is to obtain both intensity and edge detection matrices. This is accomplished through the use of a Sobel filter, which finds the intensity and direction gradients of an image. After establishing two kernels (for the x and y direction), each pixel in the image is multiplied by the kernel to find the x and y magnitudes. Direction is then found and set by taking the arctangent and multiplying it by 180/pi.

After determining the intensity and directions of the image, a non-maximum suppression algorithm is applied to thin out the edges. Pixel with relative non-maximal intensity are set to black, while the most intense pixels are maintained.

A double-threshold is then applied to the image, which categorizes pixels into three different categories: strong, weak, and non-relevant. Strong pixels have an intensity so high that we know they contribute to the final edge, and non-relevant pixels have an intensity so low that they contribute in no way to the final image. Weak pixels have an intensity somewhere in-between the two. A high-threshold identifies the strong pixels, and a low-threshold picks out the weak ones (hence, "double-threshold"). Pixels that fall between these intensities are identified and passed through the hysteresis algorithm.

The final step is to apply a hysteresis algorithm, which converts weak pixels to strong if any of the pixels seated directly next to the currently observed pixel are considered strong.
