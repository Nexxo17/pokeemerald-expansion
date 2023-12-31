#include "global.h"
#include "blit.h"
#include "window.h"
#include "menu.h"
#include "palette.h"
#include "event_data.h"
#include "m4a.h"
#include "sprite.h"
#include "main.h"
#include "graphics.h"
#include "task.h"
#include "bg.h"
#include "malloc.h"
#include "palette.h"
#include "scanline_effect.h"
#include "menu.h"
#include "menu_helpers.h"
#include "gpu_regs.h"
#include "decompress.h"
#include "sound.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "constants/event_objects.h"
#include "random.h"


void HandsGameDraw(void);

static const u16 handsGamePal[] = INCBIN_U16("graphics/oam_sprites/hands_game/hands_game_0.gbapal");
static const u16 handsGameSprite_0[] = INCBIN_U16("graphics/oam_sprites/hands_game/hands_game_0.4bpp");
static const u16 handsGameSprite_1[] = INCBIN_U16("graphics/oam_sprites/hands_game/hands_game_1.4bpp");

static EWRAM_DATA u8 hands0EWRAM = 0;
static EWRAM_DATA u8 hands1EWRAM = 0;

#define TAG_HANDS_SPRITES 0x2222
#define TAG_HANDS_SPRITES1 0x2223

static const struct OamData spriteNameOamData =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0, 
    .mosaic = 0, 
    .bpp = 0,
    .shape = 0, 
    .x = 0, 
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0, 
    .paletteNum = 0, 
    .affineParam = 0, 
};

static const union AnimCmd handsGame_s1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const nameSpriteAnimTable[] =
{
    handsGame_s1,
};

static const struct SpriteSheet spriteSheet0 =
{
    .data = handsGameSprite_0,
    .size = 2048,
    .tag = TAG_HANDS_SPRITES, //Este es lugar en que el sistema dibujará el sprite en la OAM
};

static const struct SpriteSheet spriteSheet1 =
{
    .data = handsGameSprite_1,
    .size = 2048,
    .tag = TAG_HANDS_SPRITES1, //Este es lugar en que el sistema dibujará el sprite en la OAM
};

static const struct SpritePalette spritePalette =
{
    .data = handsGamePal,
    .tag = TAG_HANDS_SPRITES, //Este es lugar en que el sistema dibujará el sprite en la OAM
};
static const struct SpriteTemplate spriteTemplate =
{
    .tileTag = TAG_HANDS_SPRITES, //Este es lugar en que el sistema dibujará el sprite en la OAM
    .paletteTag = TAG_HANDS_SPRITES, //Este es lugar en que el sistema dibujará el sprite en la OAM
    .oam = &spriteNameOamData,
    .anims = nameSpriteAnimTable,
    .images = NULL, //Lo dejaremos siempre como NULL
    .affineAnims = gDummySpriteAffineAnimTable, //Esto es para las animaciones afines, de nuevo, si no las usamos, dejaremos esto por defecto
    .callback = SpriteCallbackDummy, //Esto es para las animaciones, si no las usaremos, también se quedará así
};

static const struct SpriteTemplate spriteTemplate1 =
{
    .tileTag = TAG_HANDS_SPRITES1, //Este es lugar en que el sistema dibujará el sprite en la OAM
    .paletteTag = TAG_HANDS_SPRITES, //Este es lugar en que el sistema dibujará el sprite en la OAM
    .oam = &spriteNameOamData,
    .anims = nameSpriteAnimTable,
    .images = NULL, //Lo dejaremos siempre como NULL
    .affineAnims = gDummySpriteAffineAnimTable, //Esto es para las animaciones afines, de nuevo, si no las usamos, dejaremos esto por defecto
    .callback = SpriteCallbackDummy, //Esto es para las animaciones, si no las usaremos, también se quedará así
};


void HandsGameDraw(void){

    LoadSpriteSheet(&spriteSheet0);
    LoadSpritePalette(&spritePalette);
    hands0EWRAM = CreateSprite(&spriteTemplate, 96, 102, 0);


    LoadSpriteSheet(&spriteSheet1);
    LoadSpritePalette(&spritePalette);
    hands1EWRAM = CreateSprite(&spriteTemplate1, 96 + 64, 102, 0);
}


void HandsGameClean(void){
    DestroySpriteAndFreeResources(&gSprites[hands0EWRAM]);
    DestroySpriteAndFreeResources(&gSprites[hands1EWRAM]);
}