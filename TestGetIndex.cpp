#include <iostream>
#include <vector>
#define VOUT(x) cout << #x << "=" << x << endl;

using namespace std;

/*
function getIndex($row, $col, $rgb, $realSize){

    ($col + ($realSize*$row)) * 3 + $rgb

}

function Bunkai($idx, $realsize){
    $rgb = $idx % 3
    $pixaddr = ($idx - $rgb) / 3
    $col = $pixaddr % $realsize
    $row = ($pixaddr - $col) / $realsize
    ($row,$col,$rgb)
}

function getRealsize($w){
    $w * 4 + $w % 4
}

$width = 30
$height = 20
for($row=0; $row -lt $height;$row++){
    for($col=0; $col -lt $width;$col++){
        $realsize = (getRealsize $width)
        #"realsize={0}" -f $realsize
        for($rgb=0; $rgb -lt 3; $rgb++){
            $ix = (getIndex $row  $col $rgb $realSize) 
            #"ix=$ix"
            ($row1,$col1,$rgb1) = (bunkai $ix $realsize)
            #"{0},{0},{0}" -f ($row1,$col1,$rgb1)
            $a = (($row -eq $row1),($col -eq $col1),($rgb -eq $rgb1))
            if (($a|Measure-Object -sum).Sum -ne 3){ "*** NG ***";break }
            #"$row $col $rgb $a"
            #Read-Host "pause"
        }
    }
}
"OK"
*/
/*
 * calc index from (row, col, rgb-index)
 * 
**/
int getIndex(int row, int col, int rgb, int realSize)
{
    return((col*3 + (realSize*row)) + rgb);
}
/**
 *  --> row, col, rgb
 *
 */
void Bunkai(int idx, int realsize, int &row, int &col, int &rgb)
{
#if 0
    rgb = idx % 3;
    int pixaddr = (idx - rgb) / 3;
    col = pixaddr % realsize;
    row = (pixaddr - col) / realsize;
#endif
    row = idx / realsize;
	col = (idx % realsize) / 3;
	rgb = (idx % realsize) % 3;
	//($row,$col,$rgb)
}
/**
 * calc real linesize
 */
int getRealsize(int w)
{
    return(w * 3 + w % 4);
}
int main(){
vector<int> v;
int width = 40;
int height = 20;
	int realsize = getRealsize (width);
	for(int row=0; row < height;row++){
		for(int col=0; col < width;col++){
			//#"realsize={0}" -f $realsize
			for(int rgb=0; rgb < 3; rgb++){
				int ix = getIndex(row,  col, rgb, realsize) ;
				if (ix==360){
					do{}while(0);
				}
				v.push_back(ix);
				//#"ix=$ix"
				//($row1,$col1,$rgb1) = (bunkai $ix $realsize)
				int row1, col1, rgb1;
				Bunkai(ix, realsize, row1, col1, rgb1);
				//#"{0},{0},{0}" -f ($row1,$col1,$rgb1)
				//$a = (($row -eq $row1),($col -eq $col1),($rgb -eq $rgb1))
				int sum = (row == row1)+(col==col1)+(rgb==rgb1);
				if (sum != 3){
					cerr << "*** NG ***" << endl;
				}
				//if (($a|Measure-Object -sum).Sum -ne 3){ "*** NG ***";break }
				//#"$row $col $rgb $a"
				//#Read-Host "pause"
			}
		}
	}
	cout << "OK" << endl;
	VOUT(v.size());
}