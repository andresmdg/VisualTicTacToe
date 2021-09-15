#pragma once

// Standard libraries
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

// Define TRUE FALSE
#define true 1
#define false 0

// Functions declaration
  // Game functions
void cpu(void);
void game(void);
void draw(void);
void initBoard(void);
void updateBoard(void);
void setToken(char token, Vector2 position);
  // Validators
int winner(void);
int validPos(Vector2 position);

// Structs
struct Screen {
	int w;
	int h;
}screen = { 640, 640 };