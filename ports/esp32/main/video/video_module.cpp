extern "C" {
#include "py/obj.h"
#include "py/runtime.h"
}

#include <ESP_8_BIT_GFX.h>

// Create a single global instance of the video output
ESP_8_BIT_GFX videoOut(true /* NTSC */, 8 /* RGB332 */);

// Optional: initialize in C++ constructor or call from a Python wrapper
struct VideoInit {
    VideoInit() { videoOut.begin(); }
} video_init;

// -------------------- Python wrappers --------------------

// drawPixel(x, y, color)
mp_obj_t video_drawPixel(mp_obj_t x_obj, mp_obj_t y_obj, mp_obj_t color_obj) {
    int x = mp_obj_get_int(x_obj);
    int y = mp_obj_get_int(y_obj);
    int color = mp_obj_get_int(color_obj);
    videoOut.drawPixel(x, y, color);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_3(video_drawPixel_obj, video_drawPixel);

// fillScreen(color)
mp_obj_t video_fillScreen(mp_obj_t color_obj) {
    int color = mp_obj_get_int(color_obj);
    videoOut.fillScreen(color);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(video_fillScreen_obj, video_fillScreen);

// waitForFrame()
mp_obj_t video_waitForFrame(void) {
    videoOut.waitForFrame();
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(video_waitForFrame_obj, video_waitForFrame);

// -------------------- Module globals --------------------
static const mp_rom_map_elem_t video_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_videoOut) },
    { MP_ROM_QSTR(MP_QSTR_drawPixel), MP_ROM_PTR(&video_drawPixel_obj) },
    { MP_ROM_QSTR(MP_QSTR_fillScreen), MP_ROM_PTR(&video_fillScreen_obj) },
    { MP_ROM_QSTR(MP_QSTR_waitForFrame), MP_ROM_PTR(&video_waitForFrame_obj) },
};
STATIC MP_DEFINE_CONST_DICT(video_module_globals, video_module_globals_table);

// -------------------- Module definition --------------------
const mp_obj_module_t video_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&video_module_globals,
};

// Register the module with MicroPython
MP_REGISTER_MODULE(MP_QSTR_videoOut, video_module);
