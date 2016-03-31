%% rotation: rotates a matrix
function [MatrixTransf] = rotation3D(angX,angY,angZ,x,y,z,Tx,Ty,Tz,Sx,Sy,Sz,FL)
	v = [x;y;z;1]
	
	Mrx = [1, 0, 0, 0; 0, cos(angX), sin(angX), 0; 0, -sin(angX), cos(angX), 0; 0, 0, 0, 1]
	Mry = [cos(angY), 0, sin(angY), 0; 0, 1, 0, 0; -sin(angY), 0, cos(angY), 0; 0, 0, 0, 1]
	Mrz = [cos(angZ), sin(angZ), 0, 0; -sin(angZ), cos(angZ), 0, 0; 0, 0, 1, 0; 0, 0, 0, 1]
	Ms = [Sx, 0, 0, 0; 0, Sy, 0, 0; 0, 0, Sz, 0; 0, 0, 0, 1]
	Mt = [1, 0, 0, Tx; 0, 1, 0, Ty; 0, 0, 1, Tz; 0, 0, 0, 1]
	Mp = [1, 0, 0, 0; 0, 1, 0, 0; 0, 0, 1, 0; 0, 0, (1/FL), 0]

	Mts = Mt * Ms
	Mtsz = Mts * Mrz
	Mtszy = Mtsz * Mry
	Mtszyx = Mtszy * Mrx
	puntotransformado = Mtszyx * v

	puntoProy = Mp * puntotransformado

	puntoProy(1) = puntoProy(1) / puntoProy(4)
	puntoProy(2) = puntoProy(2) / puntoProy(4)
	puntoProy(3) = puntoProy(3) / puntoProy(4)

	% rotation3D(10,10,10,1,1,0,250,250,0,2,2,2,1)