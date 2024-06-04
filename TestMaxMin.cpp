#include <iostream>
#include <cassert>
#include <functional>
#include <vector>

#define VOUT(x) cout << #x << "=" << x << endl;

using namespace std;
// -------------------------------------------------------------
/*
 * Get Max Min
 **/
void GetMaxMin(vector<int> v,  int &max, int &min, int from=0, int to=0){
	//int a_bak = func(from);
	if (to==0){
		to = v.size()-1;
	}
	max = v[from];
	min = v[from];
	for(int i=from+1; i<=to; i++){
		int a = v[i];
		if (a > max) { max = a; }
		if (a < min) { min = a; }
	}
}
/*
 * Get Slope
 **/
int GetSlope(vector<int> v){
	vector<int> vv;
	for(size_t i=1; i<v.size(); i++){
		vv.push_back(v[i]-v[i-1]);
	}
	int max;
	int min;
	GetMaxMin(vv,max,min);
	return(max-min);
}
// -------------------------------------------------------------

void main2(){
	int i = 123;
	try{
	assert(i+1==124);
	//assert(i-1==124);
	//auto f = 1; //[](int x){return(x+1000);}
	}
	catch(...){
	cerr << "** exception! **" << endl;
	}
	int v_[] = {1,1,1,3,1,1};
	vector<int> v(v_, v_+6);

	int v2_[] = {1,1,1,1,1,1};
	vector<int> v2(v2_, v2_+6);

	int v3_[] = {1,2,3,4,5,6};
	vector<int> v3(v3_, v3_+6);

	int max; int min;
	GetMaxMin(v, max, min);
	VOUT(max);
	VOUT(min);

	VOUT(GetSlope(v));
	VOUT(GetSlope(v2));
	VOUT(GetSlope(v3));

	cout << "OK" << endl;
}

