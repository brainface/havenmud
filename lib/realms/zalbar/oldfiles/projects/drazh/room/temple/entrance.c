// by Dahaka
// Aug 2004

#include <lib.h>
#include <domains.h>
#include "../../drazh.h"

inherit LIB_ROOM;


static void create() {
  room::create();
  SetTown("Drazh");
  SetClimate("underground");
  SetAmbientLight(10);
  SetShort("Temple Entrance");
  SetLong(
     "At the center of the ground floor of the Temple is a blackened and "
     "winding stairway that climbs up into the benighted cathedral "
     "ceiling. The original colors of the Temple have been stained black "
     "by grime and unholy sacrifice. Beyond the stairway and through a "
     "massive archway is a massive room."
     );
  SetItems( ([
     ({"entrance","ground floor","temple"}) : (: GetLong :),
     ({"center","stairway"}) :
     "This blackened and winding stairway leads up to a landing.",
     ({"ceiling"}) : 
     "The cathedral ceiling is high above covered in darkness.",
     ({"doorway","north wall","hall"}) :
     "The stone arched doorway leads back into the training hall of Drazh.",
     ({"massive room","archway"}) :
     "Just beyond the stairway, heading west, is a massive archway and a "
     "massive room through the archway.",
     ({"wall","walls"}) :
     "The walls of the Temple are stained black by grime and unholy "
     "sacrifice",
     ]) );
  SetItemAdjectives( ([
     "archway"  : ({"massive"}),
     "stairway" : ({"blackened","winding"}),
     "ceiling"  : ({"cathedral","benighted"}),
     ]) );
  SetListen( ([
     "default" : 
     "Silence fills the room.",
     ]) );
  SetSmell( ([
     "default" : 
     "The stench of blood fills the air.",
     ]) );
  SetInventory( ([
     V_NPC + "c_agent" : 1 + random(3),
     ]) );
  SetExits( ([
     "west" : V_ROOM + "temple/sanctum",
     "up"   : V_ROOM + "temple/landing",
     "out"  : V_ROOM + "main_road/main4",
     ]) );

}