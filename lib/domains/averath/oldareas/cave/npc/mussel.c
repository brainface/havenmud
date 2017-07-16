
// Mussel
// Laoise
// May 2001

#include <lib.h>
#include <domains.h>

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("mussel");
    SetId("mussel");
    SetAdjectives("black");
    SetShort("a black mussel");
    SetLong(
    "A curved black shell formed the oblong shape of this small black "
    "mussel, which is attached directly to the rock at its base. The shell "
    "is split into two sides which open down the middle, allowing the mussel "
    "to open and close in response to the currents in the water. When "
    "the shell opens a soft white interior can be seen."
    );
    SetLevel(2);
    SetRace("slug", "mussel");
    SetClass("fighter");
    SetGender("male");
    SetEncounter(0);
    SetMorality(0);
}
