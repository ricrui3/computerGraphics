format long
Vec1 = [0;0;0;1]
Vec2 = [500;500;0;1]

function FVT = fun2(VecAux)
	n = 0;
	f = 1;

	x = 0;
	y = 0;
	w = 1000;
	h = 1000;

	ox = x+(w/2);
	oy = y+(h/2);
	px = w;
	py = h;
	ModelVM = eye(4);
	ProjM = eye(4);
	eyeCoord = ModelVM * VecAux
	VertexClip = ProjM * eyeCoord
	val1 = VertexClip(1,1) / VertexClip(4,1);
	val2 = VertexClip(2,1) / VertexClip(4,1);
	val3 = VertexClip(3,1) / VertexClip(4,1);
	FVT = [val1, val2, val3]
	val1 = (px / 2) * FVT(1) + ox;
	val2 = (py / 2) * FVT(2) + oy;
	val3 = ((f - n) / 2) * FVT(3) + (n + f)/2;
	FVT = [val1, val2, val3];
endfunction

fun2(Vec1)
fun2(Vec2)
