// Header files
#include <ttt.h>

// Global variabales
Texture2D board;
Camera2D camera = { 0 };

// Main funtion
int main(void){
	
	// Init Window
	InitWindow(screen.w, screen.h, "Tic Tac Toe");
	
	// Loading texture
	board = LoadTexture("../../src/resources/board.png");
	
	// Camera settings
	camera.zoom = 5.0f;
	
	// GameLoop
	while(!WindowShouldClose()){
		game();
	};
	
	UnloadTexture(board);
	
	// Closing windown after Game loop finished
	CloseWindow();
};

void game(void){
	
	// Enable drawing buffer
	BeginDrawing();
	// Background Blue
	ClearBackground((Color){ 138, 143, 196, 255 });
	// Enable Camera
	BeginMode2D(camera);
	
	// Drawing Text
	DrawText("Click to Draw", 32, 5, 5, (Color){ 249, 245, 239, 255 });
	// Board Background
	DrawRectangle(16, 16, 96, 96, (Color){ 249, 245, 239, 255 });
	// Drawing Board
	DrawTexture(board, 16, 24, (Color){ 249, 245, 239, 255 });
	
	// End Mode 2DD and EndDrawing buffer
	EndMode2D();
	EndDrawing();
	
};