#include QMK_KEYBOARD_H

enum unigo66_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _MOUSE,
};

enum unigo66_keycodes {
    QWERTY = SAFE_RANGE,
    MOUSE,
};


#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define LWR_BSP LT(_LOWER, KC_BSPC)     // Turn on _LOWER layer when held, Backspace when tapped
#define RSE_HOM LT(_RAISE, KC_HOME)     // Turn on _RAISE layer when held; Home when tapped
#define RSE_END LT(_RAISE, KC_END)      // Turn on _RAISE layer when held; End when tapped
#define MOU_SCL LT(_MOUSE, KC_SCLN)     // Turn on _MOUSE layer when held, ; when tapped
#define CTL_ESC LCTL_T(KC_ESC)          // Left Control when held, Esc when tapped
#define CTL_Z   LCTL_T(KC_Z)            // Left Control when held, z when tapped
#define CTL_SLS LCTL_T(KC_SLSH)         // Left Control when held, / when tapped
#define CTL_GRV LCTL_T(KC_GRV)          // Left Control when held, ` when tapped
#define SFT_ENT RSFT_T(KC_ENT)          // Right Shift when held, Enter when tapped
#define GUI_QUO RGUI_T(KC_QUOT)         // Right Gui when held, " when tapped


const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /*
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   =    |   1  |   2  |   3  |   4  |   5  | Del  |           | Esc  |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  Tab   |   Q  |   W  |   E  |   R  |   T  | PgUp |           |  [   |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
     * |--------+------+------+------+------+------| PgDn |           |  ]   |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
     * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
     *   | Ctrl |  Gui |  Alt |                                                                   | Gui  | Alt  | Ctrl |
     *   `--------------------'                                                                   `--------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      | Home |
     *                                        |Space |BckSpc|       |Enter |------|
     *                                        |      |      |       |      | End  |
     *                                        `-------------'       `-------------'
     */
    [_QWERTY] = LAYOUT(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_DEL,       KC_ESC,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_PGUP,      KC_LBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    MOU_SCL, GUI_QUO,
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_PGDN,      KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, SFT_ENT,
        CTL_GRV, KC_LALT, KC_LGUI,                                                                              KC_RGUI, KC_RALT, KC_RCTL,
                                                     KC_SPC,  LWR_BSP,      KC_ENT,  RSE_HOM,
                                                     KC_SPC,  LWR_BSP,      KC_ENT,  RSE_END
    ),

    /*
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ~    |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |  !   |  @   |  #   |  $   |  %   |      |           |      |  ^   |  &   |  *   |  (   |  )   |  F12   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |Capslock|      |      |      |      |      |------|           |------|      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |  Up  |        |
     * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
     *   |      |      |      |                                                                   | Left | Down | Right|
     *   `--------------------'                                                                   `--------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                        |      |      |       |      |------|
     *                                        |      |      |       |      |      |
     *                                        `-------------'       `-------------'
     */
    [_LOWER] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,      _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,      _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
        KC_CAPS, _______, KC_LEFT, KC_RGHT, KC_UP,   _______,                        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_DOWN, _______, _______,      _______, _______, _______, _______, _______, KC_UP,   _______,
        _______, _______, _______,                                                                              KC_LEFT, KC_DOWN, KC_RGHT,
                                                     _______, _______,      _______, _______,
                                                     _______, _______,      _______, _______
    ),

    /*
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ~    |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |     |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |  !   |  @   |  #   |  $   |  %   |      |           |      |  ^   |  &   |  *   |  (   |  )   |  F12   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |Capslock|      |      |      |      |      |------|           |------|      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |  Up  |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
     *   | Left | Down | Right|                                                                   |      |      |      |
     *   `--------------------'                                                                   `--------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                        |      |      |       |------|      |
     *                                        |      |      |       |      |      |
     *                                        `-------------'       `-------------'
     */
    [_RAISE] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,      _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,      _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
        KC_CAPS, _______, KC_LEFT, KC_RGHT, KC_UP,   _______,                        _______, _______, _______, _______, _______, _______,
        _______, KC_UP,   _______, _______, KC_DOWN, _______, _______,      _______, AG_NORM, AG_SWAP, _______, _______, _______, _______,
        KC_LEFT, KC_DOWN, KC_RGHT,                                                                              _______, _______, _______,
                                                     _______, _______,      _______, _______,
                                                     _______, _______,      _______, _______
    ),

    /*
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
     *   |      |      |      |                                                                   |      |      |      |
     *   `--------------------'                                                                   `--------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                        |      |      |       |      |------|
     *                                        |      |      |       |      |      |
     *                                        `-------------'       `-------------'
     */
    [_MOUSE] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_BTN3, KC_MS_U, KC_BTN2, _______, _______,      _______, _______, KC_BTN2, KC_WH_U, KC_BTN2, _______, _______,
        _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,                        KC_BTN1, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                                                                              _______, _______, _______,
                                                     KC_BTN1, KC_BTN2,      _______, _______,
                                                     KC_BTN1, KC_BTN2,      _______, _______
    ),
};
