%% rotation: rotates a matrix
function [matrixRotated] = rotation(ang,x,y,z)
	v = [x,y,z]
	u = v / norm(v)
	s = [0,-u(end),u(2);u(end),0,-u(1);-u(2),u(1),0]
	ut = u'
	i = eye(3)
	u * ut
	R = u * ut + cos(ang) * (i - u * ut) + sin(ang) * s
	FM = [R(1,1),R(1,2),R(1,end),0;R(2,1),R(2,2),R(2,end),0;R(end,1),R(end,2),R(end,end),0;0,0,0,1];
	matrixRotated = FM;