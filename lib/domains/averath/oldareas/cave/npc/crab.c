
// Crab
// Laoise
// May 2001

#include <lib.h>
#include <domains.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("orange crab");
    SetId("crab");
    SetAdjectives("small", "orange");
    SetShort("a small orange crab");
    SetLong(
    "A small crab is here, the top of its shell a bright orange color. It "
    "shuffles from side to side and snaps its claws angrily. Its eye stalks "
    "wiggle constantly, moving around to scan the cave. Its six legs make "
    "small clicking sounds as the crab moves across the rock. Occasionally "
    "the crab tilts the back of its shell down, revealing its white "
    "undershell."
    );
    SetLevel(3);
    SetRace("arachnid", "crab");
    SetClass("fighter");
    SetEncounter(0);
    SetMorality(0);
    SetWander(1);
    SetWanderSpeed(10);
    SetAction(5, ({ "The crab clicks its claws together.",
    "A crab's legs click against the rocks at it moves around." }));
}

varargs int eventDie(object agent) 
{
    object food = new(AVERATH_AREAS "cave/obj/"+"crab_meat.c");
    food->eventMove(this_object());
    return ::eventDie(agent);
}
