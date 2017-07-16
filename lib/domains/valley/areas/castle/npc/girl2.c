#include <lib.h>
inherit LIB_NPC;
#include "../castle.h"

static void create() {
   npc::create();
   SetKeyName("little girl");
   SetShort("a little girl");
   SetId( ({ "girl" }) );
   SetAdjectives( ({ "little" }) );
   SetLong("Little dimples appear in each of the cheeks of the little "
           "girl as she looks around impishly.  Her eyes twinkle with "
           "the fun and games of youth.");
   SetGender("female");
 
   SetRace("dwarf");
   SetClass("rogue");
   SetLevel(2);
   SetAction(15,({ "!giggle","!beam","!emote twinkles." }) );
   SetMorality(600);
   SetInventory( ([
                    VC_OBJ + "/ribbon" : "wear ribbon",
               ]) );
   SetCurrency("nuggets",random(6) + 1);
}