#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#define VAROUT(v) cout << #v << "=" << v << endl
using namespace std;

class Serialize{
private:
    const char* fname;
    FILE* fp;
public:
    void setFile(const char* fname){
        this->fname = fname;
    }
	void close(){
		fclose(fp);
	}
    void openForRead(){
        fp = fopen(fname, "rb");
    }
    void openForWrite(){
        fp = fopen(fname, "wb");
    }
    size_t GetBytes(int blksize, void* b){
        return(fread(b, blksize, 1, fp));
    }
    void PutBytes(int blksize, void* b){
        fwrite(b, blksize, 1, fp);
    }
    void dump(char* b, size_t blksize, int n, int sw=0)
    {
        size_t nn = n*blksize;
        cout << "n*blk_size=" << nn << endl;
        for(size_t i=0; i<nn; i++){
			if (sw==0){
				cout << "b[" << i << "]=" << (char)b[i] << endl;
			}
			else{
				cout << "b[" << i << "]=" << (int)b[i] << endl;
			}
        }

    }
};

//size_t GetBytes(FILE* fp, int blksize, void* b){
//    return(fread(b, blksize, 1, fp));
//}
//void PutBytes(FILE* fp, int blksize, void* b){
//    fwrite(b, blksize, 1, fp);
//}
void main2(){
const char* fname = "./test1.dat";
int buf1_ = 0x12345678;
void* buf1 = (void *)&buf1_;
	cout << "*buf1" << "=" << hex << (int *)buf1 << endl;
	Serialize sz;
	sz.setFile(fname);
	sz.openForWrite();
	sz.PutBytes(4, buf1);
	sz.close();

	sz.openForRead();
	sz.dump((char *)buf1,4,1,1);
	sz.close();

}
void main1(){
const char* fname = "./test1.dat";
//FILE* fp;
//int i = 0x01020304;
char buf1[] = "0123456789AB";
int blk_size = (sizeof(buf1))/(sizeof(buf1[0])) - 1;
	VAROUT(blk_size);
char buf2[40];

//char* q = _a;
//char* p = _b;

    Serialize sz;
	sz.setFile(fname);
	sz.openForWrite();

	sz.PutBytes(blk_size, buf1);
	sz.close();
//--------------------------------------------------
	Serialize sz2;	
	sz2.setFile(fname);
	sz2.openForRead();

    size_t n = sz2.GetBytes(blk_size, buf2);

    //int nn =  (int) (n * blk_size);   
    sz2.dump(buf2, blk_size, 1);
    sz2.close();

}
int main(){
	//main1();
	main2();
}

