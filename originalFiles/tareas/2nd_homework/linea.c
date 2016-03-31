#include "Naive.c"

main(){
	//Horizontal
	NaiveA(50,500,500,500);
	NaiveA(500,502,50,502);

	//Vertical
	NaiveA(767,100,767,1);
	NaiveA(769,1,769,100);

	//m < 0 && m > -1
	NaiveA(1,250,250,10);
	NaiveA(253,10,1,253);

	//m = 1
	NaiveA(1,100,100,1);
	NaiveA(102,1,1,102);

	//m < -1
	NaiveA(1,150,20,3);
	NaiveA(23,3,4,150);

	//m > 1
	NaiveA(1,20,3,150);
	NaiveA(5,150,3,20);

	//m < 1 && m > 0
	NaiveA(5,5,300,200);
	NaiveA(303,200,7,5);

	DrawTheDamnLine();
}