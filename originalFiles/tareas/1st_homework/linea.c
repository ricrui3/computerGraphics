#include "Naive.c"

main(){
	NaiveA(50,500,500,500);
	NaiveA(500,502,50,502);

	NaiveA(767,100,767,1);
	NaiveA(769,1,769,100);

	NaiveA(1,250,250,10);
	NaiveA(253,10,1,253);

	NaiveA(1,100,100,1);
	NaiveA(102,1,1,102);

	NaiveA(1,150,20,3);
	NaiveA(2,53,30,151);

	NaiveA(5,5,300,200);

	DrawTheDamnLine();
}