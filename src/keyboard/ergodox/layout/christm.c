/* ----------------------------------------------------------------------------
 * ChrisTM's modification of:
 * ergoDOX layout : QWERTY (modified from the Kinesis layout)
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */


#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

// LAYER 0
KB_MATRIX_LAYER(
0, // unused
// left hand
    KEY_Equal_Plus, KEY_1_Exclamation,     KEY_2_At,           KEY_3_Pound, KEY_4_Dollar, KEY_5_Percent, KEY_Escape,
KEY_Backslash_Pipe, KEY_q_Q,               KEY_w_W,            KEY_e_E,     KEY_r_R,      KEY_t_T,       1,
           KEY_Tab, KEY_a_A,               KEY_s_S,            KEY_d_D,     KEY_f_F,      KEY_g_G,
     KEY_LeftShift, KEY_z_Z,               KEY_x_X,            KEY_c_C,     KEY_v_V,      KEY_b_B,       1,
   KEY_LeftControl, KEY_GraveAccent_Tilde, KEY_Backslash_Pipe, KEY_LeftGUI, 1,

                       KEY_LeftControl, KEY_LeftAlt,
                  0,                 0,    KEY_Home,
KEY_DeleteBackspace, KEY_DeleteForward,     KEY_End,

// right hand
                        2, KEY_6_Caret,   KEY_7_Ampersand, KEY_8_Asterisk,     KEY_9_LeftParenthesis,  KEY_0_RightParenthesis, KEY_Dash_Underscore,
KEY_LeftBracket_LeftBrace, KEY_y_Y,       KEY_u_U,         KEY_i_I,            KEY_o_O,                KEY_p_P,                KEY_RightBracket_RightBrace,
                           KEY_h_H,       KEY_j_J,         KEY_k_K,            KEY_l_L,                KEY_Semicolon_Colon,    KEY_SingleQuote_DoubleQuote,
                        1, KEY_n_N,       KEY_m_M,         KEY_Comma_LessThan, KEY_Period_GreaterThan, KEY_Slash_Question,     KEY_RightShift,
                                          2,               KEY_LeftArrow,      KEY_DownArrow,          KEY_UpArrow,            KEY_RightArrow,

KEY_RightAlt, KEY_RightControl,
KEY_PageUp,   0,                0,
KEY_PageDown, KEY_ReturnEnter,  KEY_Spacebar
),

// LAYER 1
KB_MATRIX_LAYER(
 // unused
 0,
 // left hand
 0, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F11,
 KEYPAD_Plus, 0, KEY_7_Ampersand, KEY_8_Asterisk, KEY_9_LeftParenthesis, 0, 1,
 KEYPAD_Minus, 0, KEY_4_Dollar, KEY_5_Percent, KEY_6_Caret, 0,
 0, 0, KEY_1_Exclamation, KEY_2_At, KEY_3_Pound, 0, 0,
 0, 0, KEY_0_RightParenthesis, KEY_0_RightParenthesis, KEY_Period_GreaterThan,
 0, 0,
 0, 0, 0,
 0, 0, 0,
 // right hand
 KEY_F12, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_PrintScreen,
 0, KEY_VolumeUp, KEY_LeftBracket_LeftBrace, KEY_RightBracket_RightBrace, KEY_LeftBracket_LeftBrace, KEY_RightBracket_RightBrace, KEY_VolumeUp,
 KEY_VolumeDown, KEY_9_LeftParenthesis, KEY_0_RightParenthesis, KEY_GraveAccent_Tilde, 0, KEY_VolumeDown,
 0, 0, KEY_LeftBracket_LeftBrace, KEY_RightBracket_RightBrace, 0x36, 0x37, 0,
 KEY_F13, KEY_F14, KEY_F15, KEY_F16, KEY_F17,
 0, 0,
 0, 0, 0,
 0, 0, 0
),
// LAYER 2
KB_MATRIX_LAYER(
 // unused
 0,
 // left hand
 0, 0, 0, 0, 0, 0, 0,
 0, KEY_6_Caret, KEY_7_Ampersand, KEY_8_Asterisk, KEY_9_LeftParenthesis, KEY_0_RightParenthesis, 0,
 0, KEY_1_Exclamation, KEY_2_At, KEY_3_Pound, KEY_4_Dollar, KEY_5_Percent,
 0, KEY_UpArrow, KEY_Period_GreaterThan, KEY_Period_GreaterThan, KEY_Period_GreaterThan, KEY_Period_GreaterThan, 0,
 KEY_LeftArrow, KEY_DownArrow, KEY_RightArrow, 0, 0,
 0, 0,
 0, 0, 0,
 0, 0, 0,
 // right hand
 2, 0, KEYPAD_NumLock_Clear, KEYPAD_Slash, KEYPAD_Asterisk, KEYPAD_Minus, 0,
 0, 0, KEYPAD_7_Home, KEYPAD_8_UpArrow, KEYPAD_9_PageUp, KEYPAD_Plus, KEY_DeleteBackspace,
 0, KEYPAD_4_LeftArrow, KEYPAD_5, KEYPAD_6_RightArrow, KEYPAD_Plus, 0,
 0, 0, KEYPAD_1_End, KEYPAD_2_DownArrow, KEYPAD_3_PageDown, KEY_ReturnEnter, 0,
 KEYPAD_0_Insert, KEYPAD_0_Insert, KEYPAD_Period_Delete, KEY_ReturnEnter, 0,
 0, 0,
 0, 0, 0,
 0, 0, KEYPAD_0_Insert
),
};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// aliases

// basic
#define  kprrel  &kbfun_press_release
#define  ktog    &kbfun_toggle
#define  ktrans  &kbfun_transparent
// --- layer push/pop functions
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush5   &kbfun_layer_push_5
#define  lpush6   &kbfun_layer_push_6
#define  lpush7   &kbfun_layer_push_7
#define  lpush8   &kbfun_layer_push_8
#define  lpush9   &kbfun_layer_push_9
#define  lpush10  &kbfun_layer_push_10
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop5    &kbfun_layer_pop_5
#define  lpop6    &kbfun_layer_pop_6
#define  lpop7    &kbfun_layer_pop_7
#define  lpop8    &kbfun_layer_pop_8
#define  lpop9    &kbfun_layer_pop_9
#define  lpop10   &kbfun_layer_pop_10
// ---

// device
#define  dbtldr  &kbfun_jump_to_bootloader

// special
#define  sshprre  &kbfun_shift_press_release
#define  s2kcap   &kbfun_2_keys_capslock_press_release
#define  slpunum  &kbfun_layer_push_numpad
#define  slponum  &kbfun_layer_pop_numpad

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

KB_MATRIX_LAYER(
// unused
NULL,
// left hand
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, lpush1,
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, lpush1,
kprrel, kprrel, kprrel, kprrel, lpush1,
kprrel, kprrel,
NULL, NULL, kprrel,
kprrel, kprrel, kprrel,
// right hand
lpush2, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
lpush1, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
lpush2, kprrel, kprrel, kprrel, kprrel,
kprrel, kprrel,
kprrel, NULL, NULL,
kprrel, kprrel, kprrel
),
// LAYER 1
KB_MATRIX_LAYER(
// unused
NULL,
// left hand
NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
kprrel, NULL, kprrel, kprrel, kprrel, NULL, lpop1,
kprrel, NULL, kprrel, kprrel, kprrel, NULL,
NULL, NULL, kprrel, kprrel, kprrel, NULL, NULL,
NULL, NULL, kprrel, kprrel, kprrel,
ktrans, ktrans,
NULL, NULL, ktrans,
ktrans, ktrans, ktrans,
// right hand
kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
   NULL, kprrel, sshprre, sshprre,  kprrel,  kprrel, kprrel,
         kprrel, sshprre, sshprre,  kprrel,    NULL, kprrel,
NULL, NULL, kprrel, kprrel, sshprre, sshprre, NULL,
kprrel, kprrel, kprrel, kprrel, kprrel,
ktrans, ktrans,
ktrans, NULL, NULL,
ktrans, ktrans, ktrans
),
// LAYER 2
KB_MATRIX_LAYER(
// unused
NULL,
// left hand
dbtldr, NULL, NULL, NULL, NULL, NULL, NULL,
NULL, kprrel, kprrel, kprrel, kprrel, kprrel, NULL,
NULL, kprrel, kprrel, kprrel, kprrel, kprrel,
NULL, kprrel, kprrel, kprrel, kprrel, kprrel, NULL,
kprrel, kprrel, kprrel, NULL, NULL,
ktrans, ktrans,
NULL, NULL, ktrans,
ktrans, ktrans, ktrans,
// right hand
lpop2, NULL, kprrel, kprrel, kprrel, kprrel, NULL,
NULL, NULL, kprrel, kprrel, kprrel, kprrel, kprrel,
NULL, kprrel, kprrel, kprrel, kprrel, NULL,
NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL,
kprrel, kprrel, kprrel, kprrel, NULL,
ktrans, ktrans,
ktrans, NULL, NULL,
ktrans, ktrans, kprrel
),
};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

// LAYER 0
KB_MATRIX_LAYER(
 // unused
 NULL,
 // left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, NULL,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, lpop1,
 kprrel, kprrel, kprrel, kprrel, lpop1,
 kprrel, kprrel,
 NULL, NULL, kprrel,
 kprrel, kprrel, kprrel,
 // right hand
 NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 lpop1, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 lpop2, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel,
 kprrel, NULL, NULL,
 kprrel, kprrel, kprrel
),
// LAYER 1
KB_MATRIX_LAYER(
 // unused
 NULL,
 // left hand
 NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, NULL, kprrel, kprrel, kprrel, NULL, NULL,
 kprrel, NULL, kprrel, kprrel, kprrel, NULL,
 NULL, NULL, kprrel, kprrel, kprrel, NULL, NULL,
 NULL, NULL, kprrel, kprrel, kprrel,
 ktrans, ktrans,
 NULL, NULL, ktrans,
 ktrans, ktrans, ktrans,
 // right hand
 kprrel, kprrel,  kprrel,  kprrel,  kprrel,  kprrel, kprrel,
   NULL, kprrel, sshprre, sshprre,  kprrel,  kprrel, kprrel,
         kprrel, sshprre, sshprre,  kprrel,    NULL, kprrel,
   NULL, NULL,    kprrel,  kprrel, sshprre, sshprre,   NULL,
                  kprrel,  kprrel,  kprrel,  kprrel, kprrel,

 ktrans, ktrans,
 ktrans, NULL, NULL,
 ktrans, ktrans, ktrans
),
// LAYER 2
KB_MATRIX_LAYER(
 // unused
 NULL,
 // left hand
 NULL, NULL, NULL, NULL, NULL, NULL, NULL,
 NULL, kprrel, kprrel, kprrel, kprrel, kprrel, NULL,
 NULL, kprrel, kprrel, kprrel, kprrel, kprrel,
 NULL, kprrel, kprrel, kprrel, kprrel, kprrel, NULL,
 kprrel, kprrel, kprrel, NULL, NULL,
 ktrans, ktrans,
 NULL, NULL, ktrans,
 ktrans, ktrans, ktrans,
 // right hand
 NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL,
 NULL, NULL, kprrel, kprrel, kprrel, kprrel, kprrel,
 NULL, kprrel, kprrel, kprrel, kprrel, NULL,
 NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL,
 kprrel, kprrel, kprrel, kprrel, NULL,
 ktrans, ktrans,
 ktrans, NULL, NULL,
 ktrans, ktrans, kprrel
),

	KB_MATRIX_LAYER(  // release: layer 3: nothing (just making sure unused
			  // functions don't get compiled out)
// unused
NULL,
// other
 kprrel, lpush8,  lpop8,   NULL,   NULL,   NULL,   NULL,   NULL,
   ktog, lpush9,  lpop9,   NULL,   NULL,   NULL,   NULL,   NULL,
 ktrans,lpush10, lpop10,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush1,  lpop1,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush2,  lpop2, dbtldr,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush3,  lpop3,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush4,  lpop4, s2kcap,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush5,  lpop5,slpunum,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush6,  lpop6,slponum,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush7,  lpop7,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL )

};

