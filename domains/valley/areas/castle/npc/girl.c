#include <lib.h>
inherit LIB_NPC;
#include "../castle.h"

static void create() {
   npc::create();
   SetKeyName("female child");
   SetShort("a female child");
   SetId( ({ "child","female","girl" }) );
   SetAdjectives( ({ "female" }) );
   SetLong("An impish smile covers the girl's face, showing her "
           "innocence and life at such a young age.");
   
   SetRace("dwarf");
   SetGender("female");
   SetClass("rogue");
   SetLevel(2);
   SetInventory( ([
                    VC_OBJ + "/ball_gld" : 1,
               ]) );
   SetMorality(600);
}