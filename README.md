# miniRT

How to use (works on linux and mac) :
- git clone this repo
- cd into it
- make
- ./miniRT "config file"
- there is an example config file in examples/

On linux you might have to download the GLFW library
- sudo apt-get update
- sudo apt-get install libglfw3
- sudo apt-get install libglfw3-dev


This project was made for learning purpose not for performance, in fact this raytracer runs on cpu and on a single thread.
Could not have made this project without this ressource https://raytracing.github.io/ (raytracing in one weekend series).
My project is greatly inspired from this series, the main difference is that this one is written in C (the book is in c++).

This raytracer is a phong reflection model I also implemented glass reflection, and +/- fuzzy metal reflection. 
But there will be examples below.

This project met his purposes for my learning at 42 but I will probably comeback to it someday and add/change some things:
- the different objects in the field are stored in linked lists, I would like to compare performance with array lists
- Adding bounding volume hierarchy
- Having a bigger sample of rays bouncing towards light sources
- work on the antialising part of the project

Here are some rendered examples with a large sample of rays shot per pixel (some of these can take minutes to render)
In this image you can see the 3 different shapes I implemented : spheres, planes, and cylinders(bare minimum to validate the project;)).
<img width="497" alt="complex" src="https://github.com/user-attachments/assets/88ca8166-a97e-4bac-89c5-565b189f28e0">

In this image we have 2 fully mirroring surfaces, and 2 additionnal light sources placed behind the camera

<img width="500" alt="specular_multi_day" src="https://github.com/user-attachments/assets/88ce2b37-7406-48f2-a5a0-6f56ddf045d5">




ps: this project syntax complies with the 42 norm (not more than 25 lines per function, not more than 4 arguments passed to a function, at most 5 functions per file,...) and even tho the 42 norm has its benefits to learn good syntax, I must say that for this project it just makes some functions a bit unreadable...
