# miniRT

How to use (works on linux and mac) :
git clone this repo
cd into it
make
./miniRT "config file"

there is an example config file in examples/


This project was made for learning purpose not for performance, in fact this raytracer runs on cpu and on a single thread.
Could not have made this project without this ressource https://raytracing.github.io/ (raytracing in one weekend series).
My project is greatly inspired from this series, the main difference is that this one is written in C.

This raytracer is a phong reflection model I also implemented glass reflection, and +/- fuzzy metal reflection. 
But there will be examples below.

This project met his purposes for my learning at 42 but I will probably comeback to it someday and add/change some things:
- the different objects in the field are stored in linked lists, I would like to compare performance with array lists
- Adding bounding volume hierarchy
- Having a bigger sample of rays bouncing towards light sources
- work on the antialising part of the project



