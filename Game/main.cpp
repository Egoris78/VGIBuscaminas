/*

- BUSCAMINES 3D -
Made on C++ OpenGL


Controls:
Left click - Open tile
Right click - Flag tile

WASD - Move
Shift - Run

Q - Zoom in
E - Zoom out
C - Alternate first/third person

Esc - Open esc menu

Made by:
Jose Francisco Aguilera
Samya Karzazi
Sergio Barranco
Adrian Vargas
Pau Bermúdez

Main reference:
C++ OpenGL 3D Game Tutorial Series From Scratch by Pard - https://www.youtube.com/playlist?list=PLv8DnRaQOs5-TyYnF56YghOxQBNr1VVmF

MIT License

C++ OpenGL 3D Game Tutorial Series (https://github.com/PardCode/OpenGL-3D-Game-Tutorial-Series)

Copyright (c) 2021-2022, PardCode

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/


#include "MyGame.h"
#include <iostream>

int main()
{
	try
	{
		MyGame game;
		game.run();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return -1;
	}

	return 0;
}