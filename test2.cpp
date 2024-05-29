#include <string.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<char> charAr_ty;
typedef vector<vector<char>> charAr2_ty;
typedef vector<vector<vector<char>>> ImgDataAr_ty;

void serialize(){}

const int rgblen = 3;

class CnvImgData {
private:
    int height;
    int width;
    const int rgblen = 3;
    vector<char> buf;
public:
    CnvImgData(int width, int height)
        :width(width), height(height)
        {
        }
    void showStatistics(){
        cout << " **** statistics start ****" << endl;
        cout << "height=" << height << endl;
        cout << "width=" << width << endl;
        cout << "buf.size()=" << buf.size() << endl;
        cout << " **** statistics end ****" << endl;
    }
    void setBuf(const char* p, int len){
        vector<char> buf_(p, p+len);
        buf = buf_;
    }
    vector<char>& getBuf(){ return(this->buf); }
    void deserialize(ImgDataAr_ty &img);
    void serialize(ImgDataAr_ty &vv);
    void dump(ImgDataAr_ty &vv);
};

void CnvImgData::deserialize(ImgDataAr_ty &img){
    ImgDataAr_ty &vv = img;
    const char* a = &(this->buf[0]);
    vv.clear();
    for(int row=0; row<height; row++){
        vector<vector<char>> v_col;
        v_col.clear();
        for(int col=0; col<width; col++){
            int ix = col*rgblen + (width*rgblen*row);
            char r = a[ix+0];
            char g = a[ix+1];
            char b = a[ix+2];
            vector<char> rgb{r,g,b};
            v_col.push_back(rgb);
        }
        vv.push_back(v_col);
    }

}

void CnvImgData::serialize(ImgDataAr_ty &vv){
    this->height = vv.size();
    this->width = vv[0].size();
    buf.clear();
    for(int row=0; row<this->height; row++) {
        for(int col=0; col<this->width; col++){
            char r = vv[row][col][0];
            char g = vv[row][col][1];
            char b = vv[row][col][2];
            buf.push_back(r);
            buf.push_back(g);
            buf.push_back(b);
        }
    }
}

void CnvImgData::dump(ImgDataAr_ty &vv){
    for(int row=0; row<height; row++) {
        for(int col=0; col<width; col++){
            //int ix = col*rgblen + (width*rgblen*row);
            char r = vv[row][col][0];
            char g = vv[row][col][1];
            char b = vv[row][col][2];
            cout << r << g << b << " ";
        }
        cout << endl;
    }
}

int main(){
    // 10*5*3
    const int height = 5;
    const int width = 10;
    const int rgblen = 3;
    const char* a =
    "abcdefghijklmnopqrstuvwxyz1234"
    "abcdefghijklmnopqrstuvwxyz1234"
    "abcdefghijklmnopqrstuvwxyz1234"
    "abcdefghijklmnopqrstuvwxyz1234"
    "abcdefghijklmnopqrstuvwxyz1234";
    cout << "** start! **" << endl;
    //const char* p = "abcdefghijklmn";
    vector<char> v(a, a+strlen(a));
    cout << " ---------- &v[0] start ---------- " << endl;
    cout << &v[0] << endl;
    cout << " ---------- &v[0] end ---------- " << endl;

    cout << strlen(a) << endl;
    cout << strlen(&v[0]) << endl;

    ImgDataAr_ty vv;

    CnvImgData img(width, height);
    img.setBuf(a, strlen(a));
    img.showStatistics();
    img.deserialize(vv);

    img.dump(vv);

    img.serialize(vv);
    img.showStatistics();

    cout << "*** buf ***" << endl;
    vector<char> buf1 = img.getBuf();
    cout << "buf1.size()=" << buf1.size() << endl;
    buf1.push_back('\0');
    cout << "buf1.size()=" << buf1.size() << endl;
    cout << &buf1[0] << endl;

}
