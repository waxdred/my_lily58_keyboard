# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
AUDIO_ENABLE          = no      # Audio output on port C6
BACKLIGHT_ENABLE      = no      # Enable keyboard backlight functionality
BLUETOOTH_ENABLE      = no      # Enable Bluetooth with the Adafruit EZ-Key HID
BOOTMAGIC_ENABLE      = no      # Virtual DIP switch configuration
COMMAND_ENABLE        = no      # Commands for debug and configuration
CONSOLE_ENABLE        = no      # Console for debug
EXTRAKEY_ENABLE       = yes     # Audio control and System control
MIDI_ENABLE           = no      # MIDI controls
MOUSEKEY_ENABLE       = no      # Mouse keys
NKRO_ENABLE           = yes     # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
OLED_DRIVER_ENABLE    = yes     # OLED display
RGBLIGHT_ENABLE       = no      # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE     = no      # Enable one-hand typing
UNICODE_ENABLE        = no      # Unicode
WPM_ENABLE            = yes     # Enable words per minute counter

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

# If you want to change the display of OLED, you need to change here
SRC += \
        ./lib/layer_state_reader.c \
        ./lib/keylogger.c
		# ./lib/rgb_state_reader.c \
        # ./lib/logo_reader.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/timelogger.c \
        # ./lib/host_led_state_reader.c

# Reduce hex file by enabling Link Time Optimization
# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/#Link_Time_Optimization_and_disabling_core_functionality
EXTRAFLAGS += -flto
LTO_ENABLED = yes
