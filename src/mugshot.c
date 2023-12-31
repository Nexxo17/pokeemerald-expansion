#include "global.h"
#include "blit.h"
#include "window.h"
#include "menu.h"
#include "palette.h"
#include "event_data.h"
#include "constants/mugshots.h"

#define MUGSHOT_PALETTE_NUM 13

struct Mugshot{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    const u32* image;
    const u16* palette;
};

void DrawMugshot(void);//VAR_0x8000 = mugshot id

void DrawMugshot2(void); //VAR_0x8000 = mugshot id

void DrawMugshotAtPos(void); //VAR_0x8000 = mugshot id, VAR_0x8001 = x, VAR_0x8002 = y
void ClearMugshot(void);

static const u32 sMugshotImg_Test[] = INCBIN_U32("graphics/mugshots/minis/mug_test.4bpp.lz");
static const u16 sMugshotPal_Test[] = INCBIN_U16("graphics/mugshots/minis/mug_test.gbapal");
static const u32 sMugshotImg_Chano[] = INCBIN_U32("graphics/mugshots/minis/mug_chano.4bpp.lz");
static const u16 sMugshotPal_Chano[] = INCBIN_U16("graphics/mugshots/minis/mug_chano.gbapal");
static const u32 sMugshotImg_Abuelo[] = INCBIN_U32("graphics/mugshots/minis/mug_abuelo.4bpp.lz");
static const u16 sMugshotPal_Abuelo[] = INCBIN_U16("graphics/mugshots/minis/mug_abuelo.gbapal");

static const struct Mugshot sMugshots[] = {
    [MUGSHOT_MINI_TEST] = {.x = 0, .y = 15, .width = 32, .height = 32, .image = sMugshotImg_Test, .palette = sMugshotPal_Test},
    [MUGSHOT_MINI_CHANO] = {.x = 0, .y = 15, .width = 32, .height = 32, .image = sMugshotImg_Chano, .palette = sMugshotPal_Chano},
    [MUGSHOT_MINI_ABUELO] = {.x = 0, .y = 15, .width = 32, .height = 32, .image = sMugshotImg_Abuelo, .palette = sMugshotPal_Abuelo},
};


//WindowId + 1, 0 if window is not open
static EWRAM_DATA u8 sMugshotWindow = 0;

void ClearMugshot(void){
    if(sMugshotWindow != 0){
        ClearStdWindowAndFrameToTransparent(sMugshotWindow - 1, 0);
        CopyWindowToVram(sMugshotWindow - 1, 3);
        RemoveWindow(sMugshotWindow - 1);
        sMugshotWindow = 0;
        FlagClear(FLAG_MUGSHOT_MSG);
        InitStandardTextBoxWindows();
    }
}

static void DrawMugshotCore(const struct Mugshot* const mugshot, int x, int y){
    struct WindowTemplate t;
    u16 windowId;
    
    if(sMugshotWindow != 0){
        ClearMugshot();
    }
    
    #if GAME_VERSION==VERSION_EMERALD
    SetWindowTemplateFields(&t, 0, x, y, mugshot->width/8, mugshot->height/8, MUGSHOT_PALETTE_NUM, 0x40);
    #else
    t = SetWindowTemplateFields(0, x, y, mugshot->width/8, mugshot->height/8, MUGSHOT_PALETTE_NUM, 0x40);
    #endif
    windowId = AddWindow(&t);
    sMugshotWindow = windowId + 1;
    
    LoadPalette(mugshot->palette, 16 * MUGSHOT_PALETTE_NUM, 32);
    CopyToWindowPixelBuffer(windowId, (const void*)mugshot->image, 0, 0);
    PutWindowRectTilemap(windowId, 0, 0, mugshot->width/8, mugshot->height/8);
    CopyWindowToVram(windowId, 3);
}

void DrawMugshot2(void){
    const struct Mugshot* const mugshot = sMugshots + VarGet(VAR_0x8000);
    FlagSet(FLAG_MUGSHOT_MSG);
    InitStandardTextBoxWindows();
    DrawMugshotCore(mugshot, mugshot->x, mugshot->y);
}

void DrawMugshot(void){
    const struct Mugshot* const mugshot = sMugshots + VarGet(VAR_0x8000);
    InitStandardTextBoxWindows();
    DrawMugshotCore(mugshot, mugshot->x, mugshot->y);
}

void DrawMugshotAtPos(void){
    DrawMugshotCore(sMugshots + VarGet(VAR_0x8000), VarGet(VAR_0x8001), VarGet(VAR_0x8002));
}