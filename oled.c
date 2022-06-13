// SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

// Toggle this between logo and anim commenting these includes
#include "cyberpunk/anim.c"
// #include "cyberpunk/logo.c"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

// If you want to change the display of OLED, you need to change here
void oled_task_user(void) {
    void render_status_main(void) {
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
        // oled_write_ln(read_timelog(), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    }

    void render_status_secondary(void) {
        // Toggle this between logo and anim commenting these code blocks
        // oled_write(read_logo(), false);

        // Toggle this between logo and anim commenting these code blocks
        render_anim();
        oled_set_cursor(1, 14);
        char wpm_str[10];
        sprintf(wpm_str, "WPM  %03d", get_current_wpm());
        oled_write(wpm_str, false);
    }

    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();  // Renders a static logo
    }
}
#endif  // OLED_DRIVER_ENABLE
