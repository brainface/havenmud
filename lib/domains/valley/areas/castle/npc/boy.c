#include <lib.h>
inherit LIB_NPC;
#include "../castle.h"

static void create() {
   npc::create();
   SetKeyName("male child");
   SetShort("a male boy");
   SetId( ({ "child","boy","male" }) );
   SetAdjectives( ({ "male" }) );
   SetLong("Darling blond curls crown the boy's head, and brillant "
           "blue eyes sparkle out from underneath.  He looks "
           "very well fed and happy.");
   SetRace("dwarf");
   SetClass("rogue");
   SetLevel(2+random(2));
   SetGender("male");
   SetInventory( ([
                    VC_OBJ + "/shoes_sh" : "wear shoes",
               ]) );
   SetMorality(550);
}