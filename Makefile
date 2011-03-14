GLFrame:GLFrame.cpp 
	g++ -Iusr/include/GL -Lusr/lib -lGLU -lGL -lglut -o GLFrame GLFrame.cpp 
clean : 
	rm -rf GLFrame
