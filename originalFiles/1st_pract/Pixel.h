#ifndef PIXEL_H_
#define PIXEL_H_ 

class Pixel
{
private:
	int colorR;
	int colorG;
	int colorB;
public:
	Pixel(int = 0, int = 0, int = 0);
	~Pixel();
	int getColorR(){
		return colorR;	
	}
	void setColorR(int color){
		colorR = color;
	}
	int getColorG(){
		return colorG;	
	}
	void setColorG(int color){
		colorG = color;
	}
	int getColorB(){
		return colorB;	
	}
	void setColorB(int color){
		colorB = color;
	}
};

#endif