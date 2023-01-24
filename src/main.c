//----------------------------------------------------------------------------------
// Raylib Template
//
// A basic template to quickly get up and running with Raylib.
//
// Developed by: lxmcf
//----------------------------------------------------------------------------------

#include <raylib.h>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Config Macro's
//----------------------------------------------------------------------------------
#define TARGET_FPS 60


//----------------------------------------------------------------------------------
// Helper Macro's
//----------------------------------------------------------------------------------
#define TRUE 1
#define FALSE 0


//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
// Window Variables
//----------------------------------------------------------------------------------
static const int windowWidth = 800;
static const int windowHeight = 600;
static const char* windowTitle = "Raylib Template";


//----------------------------------------------------------------------------------
// Global Variables
//----------------------------------------------------------------------------------



//----------------------------------------------------------------------------------
// Game Functions
//----------------------------------------------------------------------------------
static void InitGame (void);
static void UpdateGame (void);
static void DrawGame (void);

static void UpdateDrawFrame (void);     // Used for emscripten compatability


//----------------------------------------------------------------------------------
// Main Loop
//----------------------------------------------------------------------------------
int main (int argc, const char* argv[]) {
    InitWindow (windowWidth, windowHeight, windowTitle);

    InitAudioDevice ();

    InitGame ();

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop (UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS (TARGET_FPS);

    while (!WindowShouldClose ()) {
        UpdateDrawFrame ();
    }
#endif

    CloseAudioDevice ();

    CloseWindow ();

    return 0;
}

static void InitGame (void) {
    // Initialisation code here
}

static void UpdateGame (void) {
    // Update code here
}

static void DrawGame (void) {
    // Draw code here
}

static void UpdateDrawFrame (void) {
    UpdateGame ();

    BeginDrawing ();
    ClearBackground (RAYWHITE);

    DrawGame ();
    EndDrawing ();
}
