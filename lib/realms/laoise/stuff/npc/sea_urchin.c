
// Sea Urchin
// Laoise
// May 2001

#include <lib.h>
#include <domains.h>

inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("sea urchin");
    SetId("sea urchin");
    SetAdjectives("sea");
    SetShort("a sea urchin");
    SetLong(
    "This small spiney creature attaches itself directly to the rocks, "
    "leaving only its long spines facing outward. The spines are finger-"
    "length and thin with sharp points at the end. They are clustered "
    "together across the entire top of the creature, radiating outward "
    "in all directions. The spines are multicolored, beginning with a "
    "dark purple shade near the tip, fading towards white as they connect "
    "to the creature's body. The creature can flex these spines and "
    "redirect them, to both protect and defend itself."
    );
    SetLevel(1);
    SetRace("arachnid", "sea urchin");
    SetClass("fighter");
    SetGender("male");
    SetEncounter(0);
    SetMorality(-1000);
    SetAction(5, ({ "The sea urchin flexes its spines." }));
}
