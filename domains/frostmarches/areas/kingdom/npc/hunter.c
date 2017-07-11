/* A faerie hunter
   Ela 4/19/98
*/

#include <lib.h>
#include "../kingdom.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("hunter");
  SetShort("a faerie hunter");
  SetId( ({"hunter","faerie","man"}) );


  SetAdjectives( ({"faerie","agile","successful","soundless","capable"}) );
  SetLong("This agile faerie is the most successful hunter in the area due to "
          "his soundless movement through the forest. His daily encounters "
          "with the unpredictable behavior of wild beasts have honed his own " 
          "skills. He is quite capable of defending himself if the need "
          "arises.");
  SetGender("male");
  SetRace("faerie");
  SetClass("rogue");
  SetLevel(20);
  SetAction(5,
        ({"!emote stands motionless as he observes you quietly with "
          "glittering, intelligent eyes."})
         );
  SetInventory( ([
         KINGDOM_OBJ + "crossbow" : "wield crossbow",
         ]) );
}
