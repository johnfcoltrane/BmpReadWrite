#include"bitmap.h"
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 3){
		fprintf(stderr, "Usage: program <inputfile> <outputfile>\n");
		exit(1);
	}

	Image *colorimg;

	if((colorimg = Read_Bmp(argv[1])) == NULL){
		exit(1);
	}

	Image img2(*colorimg);

	//for(int row=0; row<colorimg->height; row++){
	for(int row=colorimg->height-1; row>-1; row--){ // 9,8,7,...,0
		for(int col=0; col<colorimg->width; col++){
			int row1 = colorimg->height - 1 - row;
				//row*width + col
				int width = img2.width;
				img2.data[row1*width + col] = colorimg->data[row*width + col];
		}
	}

	//if(Write_Bmp(argv[2], colorimg)){
	if(Write_Bmp(argv[2], &img2)){
		exit(1);
	}

	Free_Image(colorimg);
	//Free_Image(&img2);

	return 0;
}

