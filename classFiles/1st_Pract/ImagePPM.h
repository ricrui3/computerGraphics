#ifndef IMAGE_PPM_H_
#define IMAGE_PPM_H_ 

class Image_PPM
{
private:
	int dimX;
	int dimY;
	int background;
public:
	Image_PPM();
	~Image_PPM();
	int getDimX(){
		return dimX;	
	}
	void setDimX(int dimx){
		dimX = dimx;
	}
	int getDimY(){
		return dimY;	
	}
	void setDimY(int dimy){
		dimY = dimy;
	}
	int getBackground(){
		return background;	
	}
	void setBackground(int bckg){
		background = bckg;
	}
};

#endif
