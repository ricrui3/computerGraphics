%% rotation: rotates a matrix
function [MatrixTransf] = rotation(ang,x,y,Tx,Ty,Sx,Sy)
	v = [x;y;1]
	
	Ms = [Sx, 0, 0; 0, Sy, 0; 0, 0, 1]
	Mr = [cos(ang), sin(ang), 0; -sin(ang), cos(ang), 0; 0, 0, 1]
	Mt = [1, 0, Tx; 0, 1, Ty; 0, 0, 1]

	Mtr = Mt * Mr
	Mtrs = Mtr * Ms 
	MatrixTransf = Mtrs * v