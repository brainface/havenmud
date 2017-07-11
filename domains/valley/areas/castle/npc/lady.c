#include <lib.h>
inherit LIB_NPC;
#include "../castle.h"

static void create() {
   npc::create();
   SetKeyName("Vale Castle Lady");
   SetShort("Vale Castle Lady");
   SetId( ({ "lady" }) );
   SetAdjectives( ({ "vale","castle" }) );
   SetLong("The pale figure of the lady smiles a royal smile, "
           "look as if she might faint sometimes soon, her tall figure "
           "ready to fall to the ground.  There is a little something "
           "left in her, though.");
   SetGender("female");
   SetRace("dwarf");
   SetClass("rogue");
   SetLevel(8);
   SetCombatAction(5, ({ "!emote grows all flustered and nearly faints.",
                          "!sit",
                          "!stand up",
                     }) );
   SetMorality(450);
   SetInventory( ([
                    VC_OBJ + "/glove_l" : "wear glove on right hand and right arm",
                    VC_OBJ + "/gloves_l" : "wear glove on left hand and left arm",
               ]) );
}
