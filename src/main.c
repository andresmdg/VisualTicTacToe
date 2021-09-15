// Header files
#include <ttt.h>

// Global variabales
int turn;
Texture2D board;
Texture2D token;
Camera2D camera = { 0 };
char map[3][3] = { "0" };
Vector2 mouse = { 0 };
Rectangle Cell = {  };

// Main funtion
int main(void){
	
	// Window resizable
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	// Init Window
	InitWindow(screen.w, screen.h, "Tic Tac Toe");
	
	// Loading texture
	board = LoadTexture("../../src/resources/board.png");
	token = LoadTexture("../../src/resources/token.png");
	
	// Camera settings
	camera.zoom = 5.0f;
	
	// Board initializer
	initBoard();
	
	
	// GameLoop
	while(!WindowShouldClose()){
		game();
	};
	
	UnloadTexture(board);
	UnloadTexture(token);
	
	return 0;
	
};

// Board initialization definition
void initBoard(void){
	
	int f, c;
	char pos;
	pos = '1';
	
	for (f = 0; f < 3; f++){
		for (c = 0; c < 3; c++){
			map[f][c] = pos++;
		};		
	};
	
};

// Game definition
void game(void){
	
	/* ---------------------------
				Updaters
	   ---------------------------
	*/
	
	// Getting Mouse Position
		mouse = GetMousePosition();
	
	// Checking the mouse if is clicked
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
		// system("cls");
		// printf("Position: %f, %f", mouse.x, mouse.y);
		
		// Check which cell is clicked and set a token into the cell clicked
		for (int y = 0; y < 3; y++){
			for (int x = 0; x < 3; x++){
				
				Rectangle cellRec = { 0 };
				cellRec.width = 22 * 5;
				cellRec.height = 22 * 5;
				cellRec.x = (float)((x * 24) + 29) * 5; 
				cellRec.y = (float)((y * 24) + 37) * 5;
				
				// Check if the same area as any cell was clicked
				if (CheckCollisionPointRec(mouse, cellRec)){
					// Check if the position is valid
					if (!validPos((Vector2){ x, y })){
						return;
					};
					turn++;
					// Setting a token into de board
					setToken('X', (Vector2){ x, y });
				};
			};			
		};
	};
	
	/* ---------------------------
				Drawing
	   ---------------------------
	*/
	
	// Enable drawing buffer
	BeginDrawing();
	// Background Blue
	ClearBackground((Color){ 138, 143, 196, 255 });
	// Enable Camera
	BeginMode2D(camera);
	
	// Drawing board
	draw();
	
	// End Mode 2DD and EndDrawing buffer
	EndMode2D();
	EndDrawing();
	
};

// Valid Position definition
int validPos(Vector2 position){
	
	if (map[(int)position.y][(int)position.x] == 'X' || map[(int)position.y][(int)position.x] == 'O') {
		return false;
	};
	
	return true;
	
};

// Set token definition
void setToken(char token, Vector2 position){
	
	// printf("Turn: %d", turn);
	
	map[(int)position.y][(int)position.x] = token;
	
	if (!winner() && turn == 9){
		CloseWindow();
		printf("\nSORRY THERE IS NO WINNER!!!\n\n");
		return;
	} else if (!winner() && token == 'X'){
		return cpu();
	} else if (!winner() && token == 'O'){
		return game();
	} else if (token == 'X'){
		CloseWindow();
		printf("\nYOU WON THE GAME!!!\n\n");
		return;
	} else if (token == 'O'){
		CloseWindow();
		printf("\nYOU LOST THE GAME!!!\n\n");
		return;
	};
	
};

// CPU definition
void cpu(void){
	
	int x, y, min = 1, max = 3;
	
	x = (rand() % (max - min + 1)) + min;
	y = (rand() % (max - min + 1)) + min;
	
	// printf("X : %d\nY: %d\n", x, y);

	if (!validPos((Vector2){ x - 1, y - 1})){
		return cpu();
	};
	turn++;
	setToken('O', (Vector2){ x - 1, y - 1});
};

// Winner definition
int winner(void){
	
	if ( ( map[0][0] == 'X' && map[0][1] == 'X' && map[0][2] == 'X' ) || ( map[0][0] == 'O' && map[0][1] == 'O' && map[0][2] == 'O' ) ){
		return true;
	} else if ( ( map[1][0] == 'X' && map[1][1] == 'X' && map[1][2] == 'X' ) || ( map[1][0] == 'O' && map[1][1] == 'O' && map[1][2] == 'O' ) ){
		return true;
	} else if ( ( map[2][0] == 'X' && map[2][1] == 'X' && map[2][2] == 'X' ) || ( map[2][0] == 'O' && map[2][1] == 'O' && map[2][2] == 'O' ) ){
		return true;
	} else if ( ( map[0][0] == 'X' && map[1][0] == 'X' && map[2][0] == 'X' ) || ( map[0][0] == 'O' && map[1][0] == 'O' && map[2][0] == 'O' ) ){
		return true;
	} else if ( ( map[0][1] == 'X' && map[1][1] == 'X' && map[2][1] == 'X' ) || ( map[0][1] == 'O' && map[1][1] == 'O' && map[2][1] == 'O' ) ){
		return true;
	} else if ( ( map[0][2] == 'X' && map[1][2] == 'X' && map[2][2] == 'X' ) || ( map[0][2] == 'O' && map[1][2] == 'O' && map[2][2] == 'O' ) ){
		return true;
	} else if ( ( map[0][0] == 'X' && map[1][1] == 'X' && map[2][2] == 'X' ) || ( map[0][0] == 'O' && map[1][1] == 'O' && map[2][2] == 'O' ) ){
		return true;
	} else if ( ( map[0][2] == 'X' && map[1][1] == 'X' && map[2][0] == 'X' ) || ( map[0][2] == 'O' && map[1][1] == 'O' && map[2][0] == 'O' ) ){
		return true;
	};
	
	return false;
	
};

// Draw definition
void draw(void){
	
	int f, c;
	
	Vector2 pos = { 0 };
	Rectangle tokenO = { 0, 0, token.width/2, token.height };
	Rectangle tokenX = { token.width/2, 0, token.width/2, token.height };
	
	// Drawing Text
	DrawText("Click to Draw", 32, 5, 5, (Color){ 249, 245, 239, 255 });
	// Board Background
	DrawRectangle(16, 16, 96, 96, (Color){ 249, 245, 239, 255 });
	// Drawing Board
	DrawTexture(board, 16, 24, (Color){ 249, 245, 239, 255 });
	
	// Drawing tokens
	for (f = 0; f < 3; f++){
		for (c = 0; c < 3; c++){
			pos.x = (float) ((c * 24) + 32);
			pos.y = (float) ((f * 24) + 32);
			if (map[f][c] == 'X'){
				DrawTextureRec(token, tokenX, pos, WHITE);
			} else if (map[f][c] == 'O'){
				DrawTextureRec(token, tokenO, pos, WHITE);
			};
		};		
	};
	
};