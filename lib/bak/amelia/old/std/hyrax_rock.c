// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("hyrax");
   SetShort("a rock hyrax");
   SetId( ({ "hyrax","rock","dassie","mammel","rodent" }) );
   SetAdjectives( ({ "rock","little","brown","gray","brownish" }) );
   SetLong("The little mammel is about the size of a rabbit, but is "
           "blunt, nail-like hoofs on the end of his four legs.  Brownish "
           "gray fur covers his body, except for one small spot on his "
           "back where it has turned to a white color.");
   SetGender("male");
   SetRace("rodent");
   SetClass("animal");
   SetLevel(1);
}
