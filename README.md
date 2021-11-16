# Canny-Edge-Detection

Canny edge detection is a popular multi-stage image processing algorithm that detects a range of edges in images. The process begins with converting the image to greyscale, and then smoothing the image through a Gaussian blur. The image is convolved with a Gaussian kernel (in this project, a 5x5) to create a blurring effect.

The next step is to obtain both intensity and edge detection matrices. This is accomplished through the use of a Sobel filter, which finds the intensity and direction gradients of an image.

After determining the intensity and directions of the image, a non-maximum suppression algorithm is applied to thin out the edges. Pixel with relative non-maximal intensity are set to black, while the most intense pixels are maintained.

A double-threshold is then applied to the image, which categorizes pixels into three different categories: strong, weak, and non-relevant. Strong pixels have an intensity so high that we know they contribute to the final edge, and non-relevant pixels have an intensity so low that they contribute in no way to the final image. Weak pixels have an intensity somewhere in-between the two. A high-threshold identifies the strong pixels, and a low-threshold picks out the weak ones (hence, "double-threshold"). Pixels that fall between these intensities are identified and passed through the hysteresis algorithm.

The final step is to apply a hysteresis algorithm, which converts weak pixels to strong if any of the pixels seated directly next to the currently observed pixel are considered strong.

The following display the process by which Canny edge detection finds the edges of an image:

Initial Image:
![desert](https://user-images.githubusercontent.com/38268188/142051931-e985f2b1-f730-44aa-bc34-43cc16501a6b.png)

Greyscale:
![1](https://user-images.githubusercontent.com/38268188/142051932-e7832d4a-b387-4f65-a194-9c0109210b80.png)

Gaussian Blur:
![2](https://user-images.githubusercontent.com/38268188/142051922-47e45ab7-1296-4e96-a1bb-9771c205bd51.png)

Sobel Filter (Intensity):
![3](https://user-images.githubusercontent.com/38268188/142051926-83082dff-40e8-49f0-b937-4e0d9ed29318.png)

Sobel Filter (Edge Direction):
![4](https://user-images.githubusercontent.com/38268188/142051927-9dd9d34e-c160-4232-9f07-8f8ec1a5863b.png)

Non-Maximum Suppression:
![5](https://user-images.githubusercontent.com/38268188/142051928-140662be-bfca-4e8a-aa7f-83a5f8796d0c.png)

Double Threshold:
![6](https://user-images.githubusercontent.com/38268188/142051929-57d41936-2df0-46a1-8ac0-4c916dcac705.png)

Hysteresis (output image):
![desert_edges](https://user-images.githubusercontent.com/38268188/142055980-f344da1c-1494-430b-88d9-4bfd6dc88b80.png)
