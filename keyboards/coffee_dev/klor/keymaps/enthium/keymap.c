/*

                                        █         █    █            ▄▄▄▀▀▀▀▀▀▄▄▄        █▀▀▀▀▀▀▀▀▀▀█
                                        █        █     █          ▄▀            ▀▄      █          █
                                        █       █      █        ▄▀                ▀▄    █          █
                                        █      █       █        █                  █    █          █
                                        █     █        █       █                    █   █          █
                                        █    █         █       █                    █   █▄▄▄▄▄▄▄▄▄▄█
                                        █   █ █        █       █                    █   █      █
                                        █  █   █       █        █                  █    █       █
                                        █ █     █      █        ▀▄                ▄▀    █        █
                                        ██       █     █          ▀▄            ▄▀      █         █
                                        █         █    █▄▄▄▄▄▄▄▄    ▀▀▀▄▄▄▄▄▄▀▀▀        █          █

                                        ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
                                        E N T H I U M

*/
#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include "klor.h"

#ifdef HAPTIC_ENABLE
#include "drivers/haptic/drv2605l.h"
#endif


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                                      │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                                 │
// └───────────────────────────────────────────────────────────┘

enum klor_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _ALPHA,
    _SYMBOL,
    _CURSOR,
    _NUMPAD,
    _SYSFN,
    _GUI,
    _GAME,
    _GAME_ALT,
    _TYPING,
};

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                             │
// └───────────────────────────────────────────────────────────┘

enum custom_keycodes {
    OS_SWAP = SAFE_RANGE,
    SW_APP,
    SW_WIN,
    ARROW,
    RD_UE,
    RD_OA,
    RD_NF,
    RD_YI,
    SD_EDASH,
    SD_SW,
    RD_ADOT,
    RD_HM,
    RD_TG,
    COMB_ARC_SPC,
    COMB_ARC_R,
};

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s                         │
// └───────────────────────────────────────────────────────────┘

// LEFT HAND HOME ROW MODS ├───────────────────────────────────┐

#define GUI_C MT(MOD_LGUI, KC_C)
#define ALT_I MT(MOD_LALT, KC_I)
#define CTRL_A MT(MOD_LCTL, KC_A)
#define SFT_E MT(MOD_LSFT, KC_E)

// RIGHT HAND HOME ROW MODS ├───────────────────────────────────┐

#define SFT_H MT(MOD_RSFT, KC_H)
#define CTRL_T MT(MOD_LCTL, KC_T)
#define ALT_N MT(MOD_LALT, KC_N)
#define GUI_S MT(MOD_LGUI, KC_S)

// THUMB LAYER TAPS ├───────────────────────────────────┐

#define GUI_UNDS LT(_GUI, KC_NO)
#define CRSR_SPC LT(_CURSOR, KC_SPC)
#define NUM_ARCL LT(_NUMPAD, KC_NO)
#define SYS_ESC LT(_SYSFN, KC_ESC)

#define SYM_R LT(_SYMBOL, KC_R)

#define GALT_ENT LT(_GAME_ALT, KC_ENTER)

// OTHER LAYER HOME ROW MODS ├───────────────────────────────────┐

#define SFT_BSP MT(MOD_RSFT, KC_BSPC)
#define CTRL_TB MT(MOD_LCTL, KC_TAB)
#define ALT_SPC MT(MOD_LALT, KC_SPC)
#define GUI_ENT MT(MOD_LGUI, KC_ENT)

// OTHER MACROS ├───────────────────────────────────┐

#define BASE_LYR TO(_ALPHA)

#define M_CUT C(KC_X)
#define M_COPY C(KC_C)
#define M_PASTE C(KC_V)

#define M_UNDO C(KC_Z)
#define M_REDO C(KC_Y)

#define M_SELALL C(KC_A)

#define M_FIND C(KC_F)
#define M_FNDNXT C(KC_G)
#define M_FNDPRV C(S(KC_G))
#define M_FNDRPL C(KC_H)

#define M_SFTTAB S(KC_TAB)

#define M_ADRBAR C(KC_L)

#define M_LOCK G(KC_L)

#define M_CA_DEL A(C(KC_DEL))

#define M_GUI_1 G(KC_1)
#define M_GUI_2 G(KC_2)
#define M_GUI_3 G(KC_3)
#define M_GUI_4 G(KC_4)
#define M_GUI_5 G(KC_5)
#define M_GUI_6 G(KC_6)
#define M_GUI_7 G(KC_7)
#define M_GUI_8 G(KC_8)
#define M_GUI_9 G(KC_9)

#define M_G_UP   G(KC_UP)
#define M_G_DOWN G(KC_DOWN)
#define M_G_LEFT G(KC_LEFT)
#define M_G_RGHT G(KC_RIGHT)

#define M_SGUP   LSG(KC_UP)
#define M_SGDOWN LSG(KC_DOWN)
#define M_SGLEFT LSG(KC_LEFT)
#define M_SGRGHT LSG(KC_RIGHT)

#define M_CALEFT LCA(KC_LEFT)
#define M_CARGHT LCA(KC_RIGHT)

#define M_SCALFT S(LCA(KC_LEFT))
#define M_SCARGT S(LCA(KC_RIGHT))

#define M_ALTTAB A(KC_TAB)
#define M_GUITAB G(KC_TAB)
#define M_ALT_F4 A(KC_F4)

#define M_CA_TAB LCA(KC_TAB)

// USE COMBO DICTIONARY ├───────────────────────────────────┐

#include "g/keymap_combo.h"

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   s o u n d s                                 │
// └───────────────────────────────────────────────────────────┘

#ifdef AUDIO_ENABLE
  #define WINXP_SOUND W__NOTE(_DS6), Q__NOTE(_DS5), H__NOTE(_AS5), H__NOTE(_GS5), H__NOTE(_DS5), H__NOTE(_DS6), H__NOTE(_AS5)
  #define MAC_SOUND S__NOTE(_CS5), B__NOTE(_C5)

  float winxp_song[][2] = SONG(WINXP_SOUND);
  float mac_song[][2] = SONG(MAC_SOUND);
#endif // AUDIO_ENABLE

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   v a r i a b l e s                           │
// └───────────────────────────────────────────────────────────┘

bool sw_app_active = false;
bool sw_win_active = false;

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_polydactyl(
  //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
                  'L',      'L',      'L',      'L',      'L',                           'R',      'R',      'R',      'R',      'R',
        'L',      'L',      'L',      'L',      'L',      'L',                           'R',      'R',      'R',      'R',      'R',      'R',
        'L',      'L',      'L',      'L',      'L',      'L',      '*',       '*',      'R',      'R',      'R',      'R',      'R',      'R',
                                      'L',      'L',      'L',      'L',       'R',      'R',      'R',      'R'
  );

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ a l p h a   ( E n t h i u m   v 1 4 )                     │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    Q    │    Y    │    O    │    U    │    =    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    X    │    L    │    D    │    P    │    Z    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │    B    │    C    │    I    │    A    │    E    │    -    ├─╯                ╰─┤    K    │    H    │    T    │    N    │    S    │    W    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │   TAB   │    '    │    `    │    .    │    ;    │    /    ││  MUTE  ││PLY/PSE ││    J    │    M    │    G    │    F    │    V    │  ENTER  │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │    _    │  SPACE  │ARCANE L │   ESC   ││  BSPCE  │ARCANE R │    R    │   OSS   │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */

   [_ALPHA] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
               KC_Q,     KC_Y,     KC_O,     KC_U,     KC_EQL,                        KC_X,     KC_L,     KC_D,     KC_P,     KC_Z,
     KC_B,     GUI_C,    ALT_I,    CTRL_A,   SFT_E,    KC_MINS,                       KC_K,     SFT_H,    CTRL_T,   ALT_N,    GUI_S,    KC_W,
     KC_TAB,   KC_QUOT,  KC_GRV,   KC_DOT,   KC_SCLN,  KC_SLSH,  KC_MUTE,   KC_MPLY,  KC_J,     KC_M,     KC_G,     KC_F,     KC_V,     KC_ENT,
                                   GUI_UNDS, CRSR_SPC, NUM_ARCL, SYS_ESC,   KC_BSPC,  ARC_R,    SYM_R,    OS_LSFT
),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ s y m b o l                                               │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    {    │    (    │    )    │    }    │    ?    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    .    │    [    │    &    │    +    │    ]    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │    #    │    ^    │    =    │    _    │    $    │    *    ├─╯                ╰─┤    ,    │  BSPCE  │   TAB   │  SPACE  │  ENTER  │   OSS   │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │    ~    │    <    │    |    │    -    │    >    │    /    ││  MUTE  ││PLY/PSE ││    ;    │    "    │    '    │    `    │    \    │    !    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │    %    │    :    │    @    │    \    ││         │    →    │         │  LLCK   │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */

   [_SYMBOL] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
               KC_LCBR,  KC_LPRN,  KC_RPRN,  KC_RCBR,  KC_QUES,                       KC_DOT,   KC_LBRC,  KC_AMPR,  KC_PLUS,  KC_RBRC,
     KC_HASH,  KC_CIRC,  KC_EQL,   KC_UNDS,  KC_DLR,   KC_ASTR,                       KC_COMM,  SFT_BSP,  CTRL_TB,  ALT_SPC,  GUI_ENT,  OS_LSFT,
     KC_TILD,  KC_LT,    KC_PIPE,  KC_MINS,  KC_GT,    KC_SLSH,  KC_MUTE,   KC_MPLY,  KC_SCLN,  KC_DQT,   KC_QUOT,  KC_GRV,   KC_BSLS,  KC_EXLM,
                                   KC_PERC,  KC_COLN,  KC_AT,    KC_BSLS,   _______,  ARROW,    _______,  QK_LLCK
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ c u r s o r                                               │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │ADDR BAR │  REDO   │  UNDO   │FIND+REPL│   CUT   │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │   CUT   │ SFT TAB │  UNDO   │  REDO   │   TAB   │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │FIND PREV│  ENTER  │  SPACE  │   TAB   │  BSPCE  │  COPY   ├─╯                ╰─┤  COPY   │  LEFT   │   UP    │  DOWN   │  RIGHT  │   OSS   │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │FIND NEXT│ SEL ALL │ SELLINE │ SELWORD │  FIND   │  PASTE  ││  MUTE  ││PLY/PSE ││  PASTE  │  HOME   │  PG UP  │ PG DOWN │   END   │   APP   │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │  LLCK   │         │         │         ││   ESC   │ SELWORD │ SELLINE │ SEL ALL │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */

   [_CURSOR] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
               M_ADRBAR, M_REDO,   M_UNDO,   M_FNDRPL, M_CUT,                         M_CUT,    M_SFTTAB, M_UNDO,   M_REDO,   KC_TAB,
     M_FNDPRV, GUI_ENT,  ALT_SPC,  CTRL_TB,  SFT_BSP,  M_COPY,                        M_COPY,   KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT, OS_LSFT,
     M_FNDNXT, M_SELALL, SELLINE,  SELWORD,  M_FIND,   M_PASTE,  KC_MUTE,   KC_MPLY,  M_PASTE,  KC_HOME,  KC_PGUP,  KC_PGDN,  KC_END,   KC_APP,
                                   QK_LLCK,  _______,  _______,  _______,   KC_ESC,   SELWORD,  SELLINE,  M_SELALL
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ n u m p a d                                               │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    (    │    [    │    ]    │    )    │    ~    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    G    │    7    │    8    │    9    │    :    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │   OSS   │  ENTER  │  SPACE  │   TAB   │  BSPCE  │    x    ├─╯                ╰─┤    k    │    1    │    2    │    3    │    -    │    +    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │    a    │    b    │    c    │    d    │    e    │    f    ││  MUTE  ││PLY/PSE ││    j    │    4    │    5    │    6    │    /    │    *    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │    _    │  FIND   │         │  LLCK   ││    =    │    ,    │    0    │    .    │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */

   [_NUMPAD] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
               KC_LPRN,  KC_LBRC,  KC_RBRC,  KC_RPRN,  KC_TILD,                       S(KC_G),  KC_7,     KC_8,     KC_9,     KC_COLN,
     OS_LSFT,  GUI_ENT,  ALT_SPC,  CTRL_TB,  SFT_BSP,  KC_X,                          KC_K,     KC_1,     KC_2,     KC_3,     KC_MINS,  KC_PLUS,
     KC_A,     KC_B,     KC_C,     KC_D,     KC_E,     KC_F,     KC_MUTE,   KC_MPLY,  KC_J,     KC_4,     KC_5,     KC_6,     KC_SLSH,  KC_ASTR,
                                   KC_UNDS,  M_FIND,   _______,  QK_LLCK,   KC_EQL,   KC_COMM,  KC_0,     KC_DOT
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ s y s t e m   /   f n u m                                 │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │  POWER  │  WAKE   │  SLEEP  │ C+A+DEL │  MAKE   │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │SCRL LOCK│   F7    │   F8    │   F9    │   F12   │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │   OSS   │  LGUI   │  LALT   │  LCTRL  │  LSHFT  │  LOCK   ├─╯                ╰─┤CAPS LOCK│   F1    │   F2    │   F3    │   F10   │BRIGHT UP│
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │STOPDMREC│REC DM 2 │REC DM 1 │PLAY DM 2│PLAY DM 1│ OS SWAP ││  MUTE  ││PLY/PSE ││NUM LOCK │   F4    │   F5    │   F6    │   F11   │BRIGHT DN│
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │  LLCK   │         ││GAME LAYR│  PAUSE  │PRINTSCRN│KEY LOCK │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */

   [_SYSFN] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
               KC_PWR,   KC_WAKE,  KC_SLEP,  M_CA_DEL, QK_MAKE,                       KC_SCRL,  KC_F7,    KC_F8,    KC_F9,    KC_F12,
     OS_LSFT,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  M_LOCK,                        KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F10,   KC_BRIU,
     DM_RSTP,  DM_REC2,  DM_REC1,  DM_PLY2,  DM_PLY1,  OS_SWAP,  KC_MUTE,   KC_MPLY,  KC_NUM,   KC_F4,    KC_F5,    KC_F6,    KC_F11,   KC_BRID,
                                   _______,  _______,  QK_LLCK,  _______,   TO(_GAME),KC_PAUS,  KC_PSCR,  QK_LOCK
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ g u i                                                     │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │<MVWIN2WS│< WRKSPCE│WRKSPCE >│MVWIN2WS>│ GUI+TAB │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │ SW WIN  │  GUI+7  │  GUI+8  │  GUI+9  │SYS CTRL │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │   OSS   │  ENTER  │  SPACE  │   TAB   │  BSPCE  │ ALT+TAB ├─╯                ╰─┤ SW APP  │  GUI+1  │  GUI+2  │  GUI+3  │WINDOW ^ │MONITOR ^│
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │   F11   │  LEFT   │  DOWN   │   UP    │  RIGHT  │PRINTSCRN││  MUTE  ││PLY/PSE ││ ALT+F4  │  GUI+4  │  GUI+5  │  GUI+6  │WINDOW v │MONITOR v│
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │  LLCK   │         │         ││< MONITOR│< WINDOW │WINDOW > │MONITOR >│
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */

   [_GUI] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
               M_SCALFT, M_CALEFT, M_CARGHT, M_SCARGT, M_GUITAB,                      SW_WIN,   M_GUI_7,  M_GUI_8,  M_GUI_9,  M_CA_TAB,
     OS_LSFT,  GUI_ENT,  ALT_SPC,  CTRL_TB,  SFT_BSP,  M_ALTTAB,                      SW_APP,   M_GUI_1,  M_GUI_2,  M_GUI_3,  M_G_UP,   M_SGUP,
     KC_F11,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_PSCR,  KC_MUTE,   KC_MPLY,  M_ALT_F4, M_GUI_4,  M_GUI_5,  M_GUI_6,  M_G_DOWN, M_SGDOWN,
                                   _______,  QK_LLCK,  _______,  _______,   M_SGLEFT, M_G_LEFT, M_G_RGHT, M_SGRGHT
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ g a m i n g                                               │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │   TAB   │    Q    │    W    │    E    │    R    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    Y    │    U    │    I    │    O    │    P    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │    G    │  SHIFT  │    A    │    S    │    D    │    F    ├─╯                ╰─┤    H    │    J    │    K    │    L    │    ;    │    '    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │    B    │  CTRL   │    Z    │    X    │    C    │    V    ││  MUTE  ││PLY/PSE ││    N    │    M    │    ,    │    .    │    /    │    \    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │  LALT   │  SPACE  │  ENTER  │   ESC   ││BASE LAYR│  BSPCE  │    T    │   DEL   │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */

   [_GAME] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
               KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,                          KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
     KC_G,     KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,                          KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
     KC_B,     KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_MUTE,   KC_MPLY,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_BSLS,
                                   KC_LALT,  KC_SPC,   GALT_ENT, KC_ESC,    BASE_LYR, KC_BSPC,  KC_T,     KC_DEL
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ g a m i n g   a l t                                       │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │         │    9    │    8    │    7    │    =    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │   F2    │   F1    │   UP    │   F4    │   F5    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │  PG UP  │         │    3    │    2    │    1    │  SPACE  ├─╯                ╰─┤   F3    │  LEFT   │  DOWN   │  RIGHT  │   F6    │   F11   │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │ PG DOWN │         │    6    │    5    │    4    │    -    ││  MUTE  ││PLY/PSE ││    `    │   F7    │   F8    │   F9    │   F10   │   F12   │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         │  LLCK   ││  HOME   │  ENTER  │    0    │   END   │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */

   [_GAME_ALT] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
               _______,  KC_9,     KC_8,     KC_7,     KC_EQL,                        KC_F2,    KC_F1,    KC_UP,    KC_F4,    KC_F5,
     KC_PGUP,  _______,  KC_3,     KC_2,     KC_1,     KC_SPC,                        KC_F3,    KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_F6,    KC_F11,
     KC_PGDN,  _______,  KC_6,     KC_5,     KC_4,     KC_MINS,  KC_MUTE,   KC_MPLY,  KC_GRV,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F12,
                                   _______,  _______,  _______,  QK_LLCK,   KC_HOME,  KC_ENT,   KC_0,     KC_END
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ t y p i n g   p r a c t i c e   ( E n t h i u m   v 1 4 ) │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    Q    │    Y    │    O    │    U    │    =    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    X    │    L    │    D    │    P    │    Z    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │    B    │    C    │    I    │    A    │    E    │    -    ├─╯                ╰─┤    K    │    H    │    T    │    N    │    S    │    W    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │   TAB   │    '    │    `    │    .    │    ;    │    /    ││  MUTE  ││PLY/PSE ││    J    │    M    │    G    │    F    │    V    │  ENTER  │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │    _    │  SPACE  │ARCANE L │   ESC   ││BASE LAYR│ARCANE R │    R    │   OSS   │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘ */

   [_TYPING] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
               KC_Q,     KC_Y,     KC_O,     KC_U,     KC_EQL,                        KC_X,     KC_L,     KC_D,     KC_P,     KC_Z,
     KC_B,     KC_C,     KC_I,     KC_A,     KC_E,     KC_MINS,                       KC_K,     KC_H,     KC_T,     KC_N,     KC_S,     KC_W,
     KC_TAB,   KC_QUOT,  KC_GRV,   KC_DOT,   KC_SCLN,  KC_SLSH,  KC_MUTE,   KC_MPLY,  KC_J,     KC_M,     KC_G,     KC_F,     KC_V,     KC_ENT,
                                   KC_UNDS,  KC_SPC,   ARC_L,    KC_ESC,    BASE_LYR, ARC_R,    KC_R,     OS_LSFT
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ t e m p l a t e   p o l y d a c t y l                     │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │         │         │         │         │         │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │         │         │         │         │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │         │         │         │         │         ├─╯                ╰─┤         │         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         │         ││        ││        ││         │         │         │         │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         │         ││         │         │         │         │
                                 └─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┘

   [_TEMPLATE] = LAYOUT_polydactyl(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷         ╷
               _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,
                                   _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______
 )

 */
};


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ H A P T I C   F E E D B A C K                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

//void keyboard_post_init_user(void) {
//  // Call the post init code.
//  #if HAPTIC_ENABLE
//    haptic_disable(); // disables per key haptic feedback by default
//  #endif //HAPTIC ENABLE
//}

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ O L E D                                                                                                                                    │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

#ifdef OLED_ENABLE

// ┌───────────────────────────────────────────────────────────┐
// │ d y n a m i c   m a c r o                                 │
// └───────────────────────────────────────────────────────────┘

char layer_state_str[24];
char o_text[24] = "";
int dmacro_num = 0;

#ifdef DYNAMIC_MACRO_ENABLE
    char dmacro_text[4][24] = { "", "RECORDING", "STOP RECORDING",  "PLAY RECORDING"};
    static uint16_t dmacro_timer;
    const char PROGMEM rec_ico[] = {0xD1, 0xE1, 0};
    const char PROGMEM stop_ico[] = {0xD3, 0xE1, 0};
    const char PROGMEM play_ico[] = {0xD2, 0xE1, 0};


    // DYNMACRO RECORD ├─────────────────────────────────────────────────────────────┐
    bool dynamic_macro_record_start_user(int8_t direction) {
          dmacro_num = 1;
        return false;
    }

    // DYNMACRO STOP RECORDING ├─────────────────────────────────────────────────────┐
    bool dynamic_macro_record_end_user(int8_t direction) {
          dmacro_num = 2;
          dmacro_timer = timer_read();
        return false;
    }

    // DYNMACRO PLAY RECORDING ├─────────────────────────────────────────────────────┐
    bool dynamic_macro_play_user(int8_t direction) {
          dmacro_num = 3;
          dmacro_timer = timer_read();
        return false;
    }
#endif //DYNAMIC_MACRO_ENABLE


void matrix_scan_user(void) {
  #ifdef DYNAMIC_MACRO_ENABLE
    // DynMacroTimer
    if(dmacro_num > 0){
        if (timer_elapsed(dmacro_timer) < 3000) {
            strcpy ( o_text, dmacro_text[dmacro_num] );
          }
        else {
            if (dmacro_num == 1) {
                strcpy ( o_text, dmacro_text[1] );
              }
            else {
                strcpy ( o_text, layer_state_str );
                dmacro_num = 0;
              }
          }
      }
   #endif //DYNAMIC_MACRO_ENABLE
}


// ┌───────────────────────────────────────────────────────────┐
// │ o l e d   g r a p h i c s                                 │
// └───────────────────────────────────────────────────────────┘

void render_os_lock_status(void) {
    static const char PROGMEM sep_v[] = {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0};
    static const char PROGMEM sep_h1[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
//    static const char PROGMEM sep_h1[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM sep_h2[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM face_1[] = {0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0xE1, 0};
    static const char PROGMEM face_2[] = {0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xE1, 0};
    static const char PROGMEM face_3[] = {0xE1, 0xE1, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xE1, 0};
//    static const char PROGMEM face_1[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xE1, 0};
//    static const char PROGMEM face_2[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xE1, 0};
    static const char PROGMEM os_m_1[] = {0x95, 0x96, 0};
    static const char PROGMEM os_m_2[] = {0xB5, 0xB6, 0};
    static const char PROGMEM os_w_1[] = {0x97, 0x98, 0};
    static const char PROGMEM os_w_2[] = {0xB7, 0xB8, 0};
    static const char PROGMEM s_lock[] = {0x8F, 0x90, 0};
    static const char PROGMEM n_lock[] = {0x91, 0x92, 0};
    static const char PROGMEM c_lock[] = {0x93, 0x94, 0};
    static const char PROGMEM b_lock[] = {0xE1, 0xE1, 0};
    #ifdef AUDIO_ENABLE
      static const char PROGMEM aud_en[] = {0xAF, 0xB0, 0};
      static const char PROGMEM aud_di[] = {0xCF, 0xD0, 0};
    #endif
    #ifdef HAPTIC_ENABLE
      static const char PROGMEM hap_en[] = {0xB1, 0xB2, 0};
      static const char PROGMEM hap_di[] = {0xCF, 0xD0, 0};
    #endif

// os mode status ────────────────────────────────────────┐

    oled_write_ln_P(sep_v, false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_1, false); // ──── MAC
    } else {
        oled_write_P(os_w_1, false); // ──── WIN
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_1, false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_2, false); // ──── MAC
    } else {
        oled_write_P(os_w_2, false); // ──── WIN
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_2, false);
    oled_write_P(sep_h1, false);
    oled_write_P(face_3, false);
//    oled_write_ln_P(sep_v, false);


// lock key layer status ─────────────────────────────────┐

    led_t led_usb_state = host_keyboard_led_state();

    if (led_usb_state.num_lock) {
        oled_write_P(n_lock, false); // ──── NUMLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.caps_lock) {
        oled_write_P(c_lock, false); // ─── CAPSLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.scroll_lock) { // ─ SCROLLLOCK
        oled_write_P(s_lock, false);
    } else {
        oled_write_P(b_lock, false);
    }

// hardware feature status ──────────────────────────────┐

    oled_write_P(sep_h2, false);

    #ifndef AUDIO_ENABLE
        oled_write_P(b_lock, false);
    #endif
    #ifndef HAPTIC_ENABLE
        oled_write_P(b_lock, false);
    #endif

    #ifdef AUDIO_ENABLE // ────────────────── AUDIO
        if (is_audio_on()) {
            oled_write_P(aud_en, false);
        } else {
            oled_write_P(aud_di, false);
        }
    #endif // AUDIO ENABLE

     #ifdef HAPTIC_ENABLE // ─────────────── HAPTIC
//        oled_write_P(hap_en, false);
        if (haptic_get_enable()) {
            oled_write_P(hap_en, false);
        } else {
            oled_write_P(hap_di, false);
        }

     #endif // HAPTIC ENABLE
}


// layer status ──────────────────────────────────────────┐

layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);
    switch (get_highest_layer(state)) {
        case _ALPHA:
            strcpy ( layer_state_str, "BASE ENTHIUM");
            break;
        case _SYMBOL:
            strcpy ( layer_state_str, "SYMBOLS");
            break;
        case _CURSOR:
            strcpy ( layer_state_str, "CURSOR");
            break;
        case _NUMPAD:
            strcpy ( layer_state_str, "NUMPAD");
            break;
        case _SYSFN:
            strcpy ( layer_state_str, "SYSTEM / FNUM");
            break;
        case _GUI:
            strcpy ( layer_state_str, "GUI");
            break;
        case _GAME:
            strcpy ( layer_state_str, "GAMING");
            break;
        case _GAME_ALT:
            strcpy ( layer_state_str, "GAMING ALT");
            break;
        case _TYPING:
            strcpy ( layer_state_str, "TYPING PRACTICE");
            break;
        default:
            strcpy ( layer_state_str, "XXXXXX");
    }
    if (dmacro_num < 1) {
        strcpy ( o_text, layer_state_str );
    }
    return state;
}


// ┌───────────────────────────────────────────────────────────┐
// │ w r i t e   t o   o l e d                                 │
// └───────────────────────────────────────────────────────────┘

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {  // ────────────────────────── PRIMARY SIDE

        // layer status ──────────────────────────────────────────────────┐
        #ifdef DYNAMIC_MACRO_ENABLE
            if(dmacro_num == 1){ oled_write_P(rec_ico, false); }
            if(dmacro_num == 2){ oled_write_P(stop_ico, false); }
            if(dmacro_num == 3){ oled_write_P(play_ico, false); }
        #endif //DYNAMIC_MACRO_ENABLE

        oled_write_ln(o_text, false);
        render_os_lock_status();

    } else {  // ─────────────────────────────────────────── SECONDARY SIDE

        // KLOR face ─────────────────────────────────────────────────────┐

        static const char PROGMEM klor_face[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x80, 0x60, 0x30, 0x18, 0x88, 0xf0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x60, 0x30, 0x0c, 0xc6,
0xe3, 0xfa, 0xdc, 0x80, 0x40, 0x40, 0x40, 0x20, 0x20, 0xa0, 0xa0, 0xe0, 0xc0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x20,
0x18, 0x8c, 0xc3, 0xf1, 0xf8, 0xfe, 0xff, 0xff, 0xf7, 0xf2, 0xf2, 0xfb, 0xf9, 0xf9, 0xfd, 0xfc,
0xfc, 0xff, 0x7f, 0x06, 0x00, 0x00, 0x20, 0x70, 0x88, 0x86, 0xc3, 0xf0, 0xf8, 0xfe, 0xff, 0xff,
0xff, 0x7f, 0xfc, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x07, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04,
0x0e, 0x07, 0x07, 0x07, 0x07, 0x87, 0xe3, 0x9b, 0xef, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0x83, 0x80, 0x80, 0xc0, 0x40, 0x40, 0x40, 0x40, 0x41, 0x41, 0x41, 0x40, 0x40, 0x20, 0x38,
0xfc, 0x73, 0x7c, 0xbf, 0x3f, 0x3f, 0x3f, 0xbf, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0xfa, 0xfa, 0xf3,
0xe3, 0xe3, 0xc3, 0xc1, 0x81, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x18, 0x0c, 0x04, 0x06, 0x06, 0x06, 0x86, 0xc6, 0x3c, 0x1c, 0x8e, 0xc3,
0xf1, 0xf8, 0xfe, 0x97, 0x90, 0x98, 0xc8, 0xcf, 0xcf, 0xe7, 0xe4, 0xe4, 0xf8, 0x78, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0xf8, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0,
0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x12, 0x21, 0x70, 0x3c, 0x3e, 0x3f, 0x3f,
0x3f, 0x1f, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
0x04, 0x09, 0x19, 0x13, 0xb3, 0xa7, 0xcf, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xdf, 0xbf, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0x80,
0xf0, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x1f, 0x11, 0x19, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x08, 0x08,
0x08, 0x08, 0x05, 0x00, 0x0f, 0x1f, 0x33, 0x27, 0x47, 0xcf, 0x9f, 0x9f, 0x3f, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0x1f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x2c, 0x24, 0x26, 0x27, 0x27, 0x27, 0x27, 0x27,
0x27, 0x27, 0x27, 0x23, 0x23, 0x33, 0x13, 0x13, 0x1f, 0x03, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x3f,
0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

//            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//            0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0,
//            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
//            0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0,
//            0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff,
//            0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        oled_write_raw_P(klor_face, sizeof(klor_face));
    }
    return false;
}
#endif // OLED_ENABLE


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ P R O C E S S I N G                                                                                                                        │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_ON_STATE(state, _GAME) || IS_LAYER_ON_STATE(state, _GAME_ALT)){
        combo_disable();
        sentence_case_off();
        socd_cleaner_enabled = true;
    } else {
        combo_enable();
        sentence_case_on();
        socd_cleaner_enabled = false;
    }
    if (sw_app_active) {
        unregister_mods(MOD_MASK_ALT);
        sw_app_active = false;
    }
    if (sw_win_active) {
        unregister_mods(MOD_MASK_GUI);
        sw_win_active = false;
    }
    return state;
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KC_UP:
            case KC_DOWN:
            case KC_LEFT:
            case KC_RIGHT:
            case SFT_BSP:
                break;
            default:
                if (sw_app_active && keycode != SW_APP) {
                    unregister_mods(MOD_MASK_ALT);
                    sw_app_active = false;
                }
                if (sw_win_active && keycode != SW_WIN) {
                    unregister_mods(MOD_MASK_GUI);
                    sw_win_active = false;
                }
        }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mods = get_mods();
    uint8_t all_mods = (mods | get_weak_mods()
#ifndef NO_ACTION_ONESHOT
                            | get_oneshot_mods()
#endif  // NO_ACTION_ONESHOT
    );
    const uint8_t shift_mods = all_mods & MOD_MASK_SHIFT;
    const bool alt = all_mods & MOD_BIT_LALT;

    if (record->event.pressed) {
        switch (keycode) {

// ┌───────────────────────────────────────────────────────────┐
// │ m a c r o                                                 │
// └───────────────────────────────────────────────────────────┘

            case OS_SWAP:
                if (!keymap_config.swap_lctl_lgui) {
                  keymap_config.swap_lctl_lgui = true;  // ─── MAC
                  set_unicode_input_mode(UNICODE_MODE_MACOS);
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(mac_song);
                  #endif // AUDIO_ENABLE
                }
                else {
                  keymap_config.swap_lctl_lgui = false; // ─── WIN
                  set_unicode_input_mode(UNICODE_MODE_LINUX);
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(winxp_song);
                  #endif // AUDIO_ENABLE
                }
//              #ifdef HAPTIC_ENABLE
//                drv2605l_pulse(52);
//              #endif // HAPTIC_ENABLE
                eeconfig_update_keymap(&keymap_config);
                clear_keyboard();  // ──── clear to prevent stuck keys
                return false;

            case ARROW:
                send_unicode_string(alt ? (shift_mods
                                            ? "\xe2\x87\x94"     // <=>
                                            : "\xe2\x86\x94")    // <->
                                            : (shift_mods
                                            ? "\xe2\x87\x92"     // =>
                                            : "\xe2\x86\x92"));  // ->
                return false;

            case SW_APP:
                add_mods(MOD_MASK_ALT);
                sw_app_active = true;
                tap_code(KC_TAB);
                return false;

            case SW_WIN:
                add_mods(MOD_MASK_GUI);
                sw_win_active = true;
                tap_code(KC_GRV);
                return false;

// ┌───────────────────────────────────────────────────────────┐
// │ r a k e d o w n  &  s l i d e                             │
// └───────────────────────────────────────────────────────────┘

            case RD_UE:     SEND_STRING("ue"); break;
            case RD_OA:     SEND_STRING("oa"); break;
            case RD_NF:     SEND_STRING("nf"); break;
            case RD_YI:     SEND_STRING("yi"); break;
            case SD_EDASH:  SEND_STRING("e-"); break;
            case SD_SW:     SEND_STRING("sw"); break;
            case RD_ADOT:   SEND_STRING("a."); break;
            case RD_HM:     SEND_STRING("hm"); break;
            case RD_TG:     SEND_STRING("tg"); break;
        }
    }

    switch (keycode) {

// ┌───────────────────────────────────────────────────────────┐
// │ l a y e r                                                 │
// └───────────────────────────────────────────────────────────┘

        case GUI_UNDS:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_UNDS);
                return false;
            }
            break;

        case NUM_ARCL:
            if (record->tap.count) {
                process_record_arcane(ARC_L, record);
                return false;
            }
            break;

// ┌───────────────────────────────────────────────────────────┐
// │ a r c a n e   c o m b o s                                 │
// └───────────────────────────────────────────────────────────┘

        case COMB_ARC_SPC:
            process_record_arcane(ARC_L, record);
            record->keycode = KC_SPC;
            process_record(record);
            remember_last_key_arcane(keycode, record, &all_mods);
            return false;
        case COMB_ARC_R:
            process_record_arcane(ARC_R, record);
            record->keycode = KC_R;
            process_record(record);
            remember_last_key_arcane(keycode, record, &all_mods);
            return false;
    }

    return true;
}

bool is_spacelike_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CRSR_SPC:
            return record->tap.count;
    }
    return false;
}

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ A R C A N E                                                                                                                                │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        case KC_ESC:
        case KC_BSPC:
        case KC_DEL:
        case KC_MUTE:
        case KC_MPLY:
        case SKP_MGC:
        case GUI_UNDS:
        case NUM_ARCL:
        case COMB_ARC_SPC:
        case COMB_ARC_R:
            return false;
    }
    return remember_last_key_arcane(keycode, record, remembered_mods);
}

char get_last_hand_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case RD_UE:
        case RD_OA:
        case RD_YI:
        case SD_EDASH:
        case RD_ADOT:
        case COMB_ARC_SPC:
            return 'L';
        case RD_NF:
        case SD_SW:
        case RD_HM:
        case RD_TG:
        case COMB_ARC_R:
            return 'R';
    }
    return '*';
}

void process_arcane_same_hand(uint16_t keycode, keyrecord_t* record) {
    uint16_t last_keycode = get_last_keycode();

    switch (last_keycode) {
        case KC_A:
        case CTRL_A: set_last_keycode(KC_O); break;
        case KC_E:
        case SFT_E: set_last_keycode(KC_U); break;
        case KC_H:
        case SFT_H: set_last_keycode(KC_L); break;
        case KC_J: set_last_keycode(KC_K); break;
        case KC_K: set_last_keycode(KC_L); break;
        case KC_Q: if (record->event.pressed) { SEND_STRING("ua"); return; }
        case KC_R:
        case SYM_R: if (record->event.pressed) { SEND_STRING("ing"); return; }
        case KC_V: set_last_keycode(KC_S); break;
        case KC_W: set_last_keycode(KC_S); break;
        case KC_X: set_last_keycode(KC_H); break;
        case KC_Y: set_last_keycode(KC_QUOT); break;

        case KC_SPC:
        case CRSR_SPC: if (record->event.pressed) { SEND_STRING("the "); return; }
    }
    repeat_key_invoke(&record->event);
    set_last_keycode(last_keycode);
}

void process_arcane_opposite_hand(uint16_t keycode, keyrecord_t* record) {
  skip_magic_invoke(&record->event);
}

uint16_t get_skip_magic_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_A:
        case CTRL_A: return KC_O;
        case KC_B: return KC_C;
        case KC_C:
        case GUI_C: return KC_B;
        case KC_D: return KC_T;
//      case SFT_E:
        case KC_F: return KC_N;
        case KC_G: return KC_T;
        case KC_H:
        case SFT_H: return KC_L;
//      case ALT_I:
        case KC_J: return KC_K;
        case KC_K: return KC_L;
        case KC_L: return KC_M;
        case KC_M: return KC_L;
//      case ALT_N:
        case KC_O: return KC_A;
        case KC_P: return KC_N;
        case KC_Q: return KC_I;
//      case SYM_R:
//      case GUI_S:
        case KC_T:
        case CTRL_T: return KC_D;
        case KC_U: return KC_E;
        case KC_V: return KC_S;
        case KC_W: return KC_S;
        case KC_X: return KC_M;
        case KC_Y: return KC_I;
        case KC_Z: return KC_S;
    }
    return KC_TRNS;
}

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ E N C O D E R                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_ALPHA]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_SYMBOL]   = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),          ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_CURSOR]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_NUMPAD]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_SYSFN]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_GUI]      = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_GAME]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_GAME_ALT] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_TYPING]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ S O C D                                                                                                                                    │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

socd_cleaner_t socd_opposing_pairs[] = {
  {{KC_W, KC_S}, SOCD_CLEANER_LAST},
  {{KC_A, KC_D}, SOCD_CLEANER_LAST},
  {{KC_UP, KC_DOWN}, SOCD_CLEANER_LAST},
  {{KC_LEFT, KC_RIGHT}, SOCD_CLEANER_LAST},
};
/*

                                                       ▐█    ▟▛ ▐█     ▄▆▀▀▀▀▀▀▆▄  ▐█▀▀▀▀▀█▌
                                                       ▐█   ▟▛  ▐█    ▟▛        ▜▙ ▐█     █▌
                                                       ▐█  ▟▛   ▐█   ▐█          █▋▐█     █▌
                                                       ▐█ ▟█▙   ▐█   ▐█          █▋▐█▀▀▜█▀▀▘
                                                       ▐█▟▛ ▜▙  ▐█    ▜▙        ▟▛ ▐█   ▜▙
                                                       ▐█▛   ▜▙ ▐█▄▄▄▄ ▀▜▆▄▄▄▄▆▛▀  ▐█    ▜▙

                                                                 ▄██████████████▄
                                                                 ████████████████
                                                            ▄██████▀  ▀████▀  ▀██████▄
                                                            ███████▄  ▄████▄  ▄███████
                                                            ███████████▀▀▀▀███████████
                                                            ▀█████████▀ ▄▄ ▀█████████▀
                                                                 ████▀ ▄██▄ ▀████
                                                                 ████▄▄████▄▄████

*/
