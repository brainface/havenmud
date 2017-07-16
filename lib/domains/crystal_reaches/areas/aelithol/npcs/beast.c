#include <lib.h>
#include "../aelithol.h"
inherit LIB_NPC;

    static void create() {
    npc::create();
    SetKeyName("beast");
    SetId( ({ "beast", "primate-like beast" }) );
    SetAdjectives( ({"unnatural"}) );
    SetShort("an unnatural beast");
    SetLong("Obviously an object of the most unnatural synthesis, "
      "this creature appears vaguely like a primate.  Skin hangs on "
      "its flesh caked with a caustic liquid.  It prowls the "
      "area hissing and searching for food.");
    SetRace("primate");
    SetClass("animal");
    SetLevel(5);
    SetGender("male");
    SetMorality(-400);
    SetAction(4, ({ "The beast arches its back and sends a piercing "
      "shriek through "
      "the forest." }));
}
