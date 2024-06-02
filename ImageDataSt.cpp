#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define VAROUT(v) cout << #v << "=" << v << endl;

typedef char px_type;

class ImageDataSt{
public:
	int width;
	int height;
	int realSize;
	vector<vector<vector<px_type>>> data;

	void setTestData(int width, int height)
	{
		this->width = width;
		this->height = height;
		for(int row=0; row<height; row++){
			vector<vector<px_type>> line;
			for(int col=0; col<width; col++){
				px_type r = (10*row + col)*10+ 1;
				px_type g = (10*row + col)*10+ 2;
				px_type b = (10*row + col)*10+ 3;
				vector<px_type>itm;
				itm.push_back(r);
				itm.push_back(g);
				itm.push_back(b);
				line.push_back(itm);
				//char* p = &data[row][col][0];
			}
			data.push_back(line);
		}

	}
	void setTestData2(int width, int height)
	{
		int i = 0;
		this->width = width;
		this->height = height;
		for(int row=0; row<height; row++){
			vector<vector<px_type>> line;
			for(int col=0; col<width; col++){
				px_type r = i*10+ 1;
				px_type g = i*10+ 2;
				px_type b = i*10+ 3;
				vector<px_type>itm;
				itm.push_back(r);
				itm.push_back(g);
				itm.push_back(b);
				line.push_back(itm);
				i++;
			}
			data.push_back(line);
		}

	}
	void output(const char* fname){
		FILE *f;
		f = fopen(fname, "wb"); // binary-mode
		fwrite(&width, 4, 1, f);
		fwrite(&height, 4, 1, f);
		for(int row=0; row<height; row++){
			//vector<vector<char>> line;
			for(int col=0; col<width; col++){
				//vector<char> itm;
				px_type* p = &data[row][col][0];
				//fwrite(&p, 3, 1, f);
				fwrite(p, 1, 3, f);
			}
		}
		fclose(f);
	}
	void input(const char* fname){
		FILE *f;
		unsigned int i;
		f = fopen(fname, "rb");
		fread(&i, 4, 1, f);
		width = i;
		fread(&i, 4, 1, f);
		height = i;
		data.clear();
		for(int row=0; row<height; row++){
			vector<vector<px_type>> line;
			for(int col=0; col<width; col++){
				//char* p = &data[row][col][0];
				px_type a[3];
				fread(a, 3, 1, f);
				vector<px_type> itm(a, a+3);
				line.push_back(itm);
			}
			data.push_back(line);
		}
		fclose(f);
	}
	void show(){
		//cout << 1 << endl;
		VAROUT(width);
		VAROUT(height);
		for(int row=0; row<height; row++){
			//vector<vector<char>> line;
			for(int col=0; col<width; col++){
				//cout << "[";
				//cout << (int)data[row][col][0] << "/";
				//cout << (int)data[row][col][1] << "/";
				//cout << (int)data[row][col][2];
				//cout << "]";
				printf("[%03d,%03d,%03d]",
				 (unsigned int)data[row][col][0],
				 (unsigned int)data[row][col][1],
				 (unsigned int)data[row][col][2] 
					);
			}
			cout << endl;
		}
		
	}
};
union U {
	int i;
	char a[4];
} u1;
int main(){
	const char* testFileName = "t:\\testImage.dat";
	ImageDataSt a;
	//a.setTestData(3,2);
	a.setTestData2(4,3);

	a.output(testFileName);
	a.input(testFileName);
	a.show();
}
int main1(){
	const char* fname = "t:\\temp1.dat";
	cout << "start!" << endl;
	u1.i = 0x01020304;
	printf("%x %x %x %x\n",
			u1.a[0],	
			u1.a[1],	
			u1.a[2],	
			u1.a[3]	
		);
	int j = 0x04050607;
	//void* q = static_cast<void *>(&j);
	char* p = static_cast<char*>(static_cast<void *>(&j));
	printf("%x %x %x %x\n",
			p[0],	
			p[1],	
			p[2],	
			p[3]	
		);
	return(0);
}