#learnopengl
This repository contains some interesting OpenGL experiments I have done a few years ago in OpenGL 2.0 and just exported from Google Code. It's simply a backup and very unlikely to be updated.  
## Curves
[Bezier Spline](https://en.wikipedia.org/wiki/B%C3%A9zier_curve) and [Cubic Spline](https://en.wikipedia.org/wiki/Cubic_Hermite_spline) are implemented in [curves](https://github.com/v3c70r/learnopngl/tree/master/curves) folder. To compile from the source on Linux, use`g++ -DBEZIER -o bin *.cpp -lglut -lGL -lGLU ` for Bezier and `g++ -o bin *.cpp -lglut -lGL -lGLU ` for Cubic Spline.

### Bezier spline
![bezier](https://raw.githubusercontent.com/v3c70r/learnopngl/master/gifs/bezier.gif)
### Cubic spline
![cubic](https://raw.githubusercontent.com/v3c70r/learnopngl/master/gifs/spline.gif)
## Polygon Filling Algorithm
[Polygon Filling Algorithm](https://www.cs.uic.edu/~jbell/CourseNotes/ComputerGraphics/PolygonFilling.html) is placed in [polygon](https://github.com/v3c70r/learnopngl/tree/master/polygen) folder. Don't forget to link glut and GL when compile.
![poly](https://raw.githubusercontent.com/v3c70r/learnopngl/master/gifs/poly.gif)
## Clipping
[Clipping of line](http://www.cc.gatech.edu/grads/h/Hao-wei.Hsieh/Haowei.Hsieh/mm.html) is implemented in [cutLine](https://github.com/v3c70r/learnopngl/tree/master/cutLine) folder.

![cutline](https://raw.githubusercontent.com/v3c70r/learnopngl/master/gifs/cutline.gif)

