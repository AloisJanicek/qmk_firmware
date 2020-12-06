#include "../../config.h"

#define ONESHOT_TAP_TOGGLE 2    /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000    /* Time (in ms) before the one shot key is released */
#define PREVENT_STUCK_MODIFIERS /* This probably do something else that I hope for */
#define QMK_KEYS_PER_SCAN 4
