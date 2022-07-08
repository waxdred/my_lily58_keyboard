/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oled.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:03:41 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/08 08:11:45 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

// Toggle this between logo and anim commenting these includes
#include "cyberpunk/anim.c"
#include "./logos/glcdfont_glitch.c"
#include <string.h>
// #include "cyberpunk/logo.c"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
void arasaka_draw(void);
void render_anim(void);
// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);
void oled_layer(int x, int y){
	char layer_use[10];
	sprintf(layer_use, "%s", read_layer_state() + 7);
	if (!strcmp(layer_use, "Default"))
		strcpy(layer_use, "Def");
        oled_write_ln("Layer", false);
        oled_write_ln(layer_use, false);
}

// If you want to change the display of OLED, you need to change here
void oled_task_user(void) {
    void render_status_main(void) {
	    oled_set_brightness(0);
  	    arasaka_draw();
    }

    void render_status_secondary(void) {
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
