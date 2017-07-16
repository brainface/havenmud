#include <lib.h>
#include <domains.h>
inherit LIB_DOOR;

static void create() {
    door::create();
    SetId("house", "door");
    SetShort("house", "a door made from old wood");
    SetLong("house", "This is a plain wooden door. Its use is highly complicated, "
            "requiring a turning of the knob and a general swinging-open motion "
            "to operate. ");
    SetLockable("house", 1);
    SetKeys("house", "#nothing_can_unlock_me#");
    SetId("out", "door");
    SetShort("out", "a door made from old wood");
    SetLong("out", "This is a plain wooden door. ");
    SetLockable("out", 1);
    SetKeys("out", "#nothing_can_unlock_me#");
    SetClosed(1);
    SetLocked(1);
    SetLockStrength(60);
}
