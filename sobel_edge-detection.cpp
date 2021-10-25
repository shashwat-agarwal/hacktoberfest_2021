// Sobel Edge-Detection using C++

void sobelEdgeDetection(Mat & image, const unsigned char threshold)
{
        vector xKernel = { -1, 0, 1, -2, 0, 2, -1, 0, 1 }; // Define the x values

        vector yKernel = { -1, -2, -1, 0, 0, 0, 1, 2, 1 }; // Define the y values

        edgeDetection(image, xKernel, yKernel);

        image = image > threshold;
}
