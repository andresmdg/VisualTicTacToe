#pragma once

// Standard libraries
#include <stdio.h>
#include <raylib.h>

// Define TRUE FALSE
#define true 1
#define false 0

// Functions declaration
void game(void);
void initBoard(void);

// Structs
struct Screen {
	int w;
	int h;
}screen = { 640, 640 };