%% rotation: rotates a matrix
function [matrixRotated] = rotation(ang,x,y,z)
	v = [x,y,z]
	u = v / norm(v)
	matrixRotated = u;
