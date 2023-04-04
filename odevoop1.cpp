#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Cube {
	private:
		
	public:
	    int length;
	    int width;
	    int height;
	    
	Cube();
 
	Cube(int,int,int);
	
	void print();
	int volume();
	~Cube();
};
Cube::Cube(){
	height=0;
	length=0;
	width=0;
}
bool operator> (Cube &s1,Cube &s2){
	if (s1.volume()>s2.volume()){
		return true;
	}
	else {
			return false;
	}
	}
	
Cube operator + (Cube s3,Cube s4 ){

Cube a;

a.height=s3.height+s4.height;
a.length=(s3.length>s4.length?s3.length:s4.length);
a.width=(s3.width>s4.width?s3.width:s4.width);

return a;


}

void Cube::print(){
	cout<<length<<"\t"<<width<<"\t"<<height<<"\t"<<volume()<<endl;
}
int Cube::volume(){
	int volum=height*width*length;
	return volum;
}
Cube::~Cube(){
//	cout<<"Object was destroyed"<<endl;
}
Cube::Cube(int length,int width,int height){
	this->length=length;
	this->width=width;
	this->height=height;
}
int main(){
	

	Cube b[10]={Cube(25,56,83),Cube(5,50,86),Cube(50,60,76),Cube(44,35,75),Cube(40,28,117),Cube(13,34,95),Cube(47,32,60),Cube(43,38,74),Cube(46,70,78),Cube(22,26,102)};
	
	cout<<"CUBES UNSORTED\n";
	cout<<"\tL\tW\tH\tVolume"<<endl;
	for (int i=0; i<10;i++){
		cout<<i+1<<".Cube"<<"\t";
		b[i].print();
		cout<<"\n";
		}
		
		
	for (int k=0;k<10;k++){
		  for (int y=0;y<10-k-1;y++){
		  
		if (b[y]>b[y+1]){
			Cube a1=b[y];
			b[y]=b[y+1];
			b[y+1]=a1;
			}
		}
	}
	cout<<"CUBES SORTED\n";
	cout<<"\tL\tW\tH\tVolume"<<endl;
	for (int r=0; r<10;r++){
		cout<<r+1<<".Cube"<<"\t";
		b[r].print();
		cout<<"\n";
		}
		
	Cube a2=b[0];	
	cout<<"CUMULATIVE SUMS OF CUBES AFTER SORTING\n";
	cout<<"                       \t\tL\tW\tH\tVolume"<<endl;
	for (int z=0;z<9;z++){
		cout<<"Number of cubes added= "<<z+2<<"\t";
		a2=a2+b[z+1];
		a2.print();
		cout<<"\n";
	}
		
   

	
	
	return 0;
}

