#include "opencv\cv.h"
#include "opencv\highgui.h"

double camera[3][3] = 
{
//0
-500.0,    0.0, 320.0,
0.0,    -500.0,	240.0,
0.0,    0.0,	1.0,
};

double projection[3][3] = 
{
//0
0.0,  1.0, 0.0,
1.0,  0.0, 0.0,
0.0,  0.0, 1.0,
};

double object[3][3] = 
{
150, 0, 0,
200, 0, 0,
400, 0, 0,
};

int main() 
{
    CvMat* camera_matrix = cvCreateMat(3, 3, CV_32F); //
    CvMat* image_points = cvCreateMat(2, 1, CV_32F);
	CvMat* object_points = cvCreateMat(3, 3, CV_32F);
	CvMat* input_rotation_matrix = cvCreateMat(3, 3, CV_32F); //
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cvmSet(camera_matrix, i, j, camera[i][j]);
			cvmSet(input_rotation_matrix, i, j, projection[i][j]);
			cvmSet(object_points, i, j, object[i][j]);
		}
	}

	CvMat* output_rotation_vector = cvCreateMat(3, 1, CV_32F);
    int a = cvRodrigues2(input_rotation_matrix, output_rotation_vector);


    CvMat* translation = cvCreateMat(3, 1, CV_32F);
	cvmSet(translation, 0, 0, 70);
	cvmSet(translation, 1, 0, 95);
	cvmSet(translation, 2, 0, 120);

	CvMat* ab = cvCreateMat(3, 1, CV_32F);
	cvmSet(ab, 0, 0, 150);
	cvmSet(ab, 1, 0, 200);
	cvmSet(ab, 2, 0, 400);

    cvProjectPoints2(ab, output_rotation_vector, translation, camera_matrix, NULL, image_points);

	printf("Xw = [ %f , %f , %f ]\n",cvmGet(ab, 0, 0),cvmGet(ab, 1, 0),cvmGet(ab, 2, 0));
    printf("%f\n", cvmGet(image_points, 0, 0));
    printf("%f\n", cvmGet(image_points, 1, 0));

	// any char continues, and you can print debugging info with printf
	getchar();

    return 0;
}
