#include <lib.h>
#include "../aelithol.h"
inherit LIB_NPC;
    static void create() {
    npc::create();
    SetKeyName("beast");
    SetId( ({ "beast", "developing beast" }) );
    SetAdjectives( ({"young", "developing"}) );
    SetShort("a developing beast");
    SetLong("Obviously an object of the most unnatural synthesis, "
      "it appears to be in the early stages of development.  Its "
      "skin is a light orange color.  It appears rather harmless.");

    SetRace("primate");
    SetClass("animal");
    SetLevel(2);
    SetGender("male");
    SetMorality(0);
    SetAction(4, ({ "The developing beast looks around helplessly." }));
}
