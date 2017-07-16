
// Horseshoe Crab
// Laoise
// May 2001

#include <lib.h>
#include <domains.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("horseshoe crab");
    SetId("crab");
    SetAdjectives("dark", "brown", "horseshoe", "horse", "shoe");
    SetShort("a dark brown horseshoe crab");
    SetLong(
    "A brown horseshoe crab lumbers along the stone here, scraping its "
    "shell along the ground. The crab has a brown shell, formed like a "
    "half circle, with a triangle on the flat side. From the triangle "
    "extends a long spiney point which the crab can raise and lower. "
    "Small spines also decorate the top of the shell. The crab lifts its "
    "point upwards so it can move forward without dragging along the "
    "ground. Its shell extends all the way down to the rock, protecting "
    "it on all sides."
    );
    SetLevel(6);
    SetRace("slug", "horseshoe crab");
    SetClass("fighter");
    SetEncounter(0);
    SetMorality(0);
    SetWander(1);
    SetWanderSpeed(10);
    SetAction(5, ({ "The horseshoe crab raises and lowers its spine.",
    "The horseshoe crab scrapes its shell along the ground as it moves."
    }) );
}
