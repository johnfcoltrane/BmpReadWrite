#ifndef __BITMAP_H_INCLUDED__
#define __BITMAP_H_INCLUDED__

#define FILEHEADERSIZE 14					//ファイルヘッダのサイズ
#define INFOHEADERSIZE 40					//情報ヘッダのサイズ
#define HEADERSIZE (FILEHEADERSIZE+INFOHEADERSIZE)

typedef struct{
	unsigned char b;
	unsigned char g;
	unsigned char r;
}Rgb;

//typedef 
struct Image_st{
	unsigned int height;
	unsigned int width;
	unsigned int size; 	// size=width*height
	Rgb *data; 			// Rgb data[width*height]
	Image_st();
	Image_st(Image_st& image);
	~Image_st();
	Rgb* indexRgb(int row, int col){
		Rgb* result;
		result = &data[row*width + col];
		return(result);
	}
	void setRgb(int row, int col, Rgb& rgb){
		data[row*width + col] = rgb;
	}
}; //Image;
typedef Image_st Image;

//取得に成功すればポインタを失敗すればNULLを返す
Image *Read_Bmp(char *filename);

//書き込みに成功すれば0を失敗すれば1を返す
int Write_Bmp(char *filename, Image *img);

//Imageを作成し、RGB情報もwidth*height分だけ動的に取得する。
//成功すればポインタを、失敗すればNULLを返す
Image *Create_Image(int width, int height);
//Imageを解法する
void Free_Image(Image *img);

#endif /*__BITMAP_H_INCLUDED__*/
