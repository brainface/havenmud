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
  SetShort("Armoury of the Watch");
  SetLong(
     "This small square chamber of stone has a wooden rack and large wooden chest "
     "against the far south wall. A small table and chair sit in the middle of "
     "chamber. The ceiling and wall have a few cracks running across their surfaces. "
     "The doorway in the north wall leads back out to the watchman's training hall."
     );
  SetItems( ([
     ({"chamber","armoury"}) : (: GetLong :),
     ({"south wall"}) :
     "Along the south wall of this square chamber is a large wooden chest and "
     "wooden rack.",
     ({"table"}) : 
     "This small round wooden table sits in the middle of this chamber. The "
     "table top of the table looks scratched and beat up.",
     ({"chair"}) :
     "This wooden high back chair is placed near the small round wooden table. "
     "The legs of the chairs have been scratched up and down them.",
     ({"ceiling","wall","walls","cracks","surfaces"}) :
     "The four stonewalls and ceiling of this small chamber has many cracks "
     "running across there surfaces. These cracks must have been due to the "
     "fighting that must have ensued within the walls of Drazh.",
     ({"doorway","north wall","hall"}) :
     "The stone arched doorway leads back into the training hall of Drazh.",
     ({"rack"}) :
     "This wooden rack is a weapon storage rack. The rack is empty.",
     ({"chest"}) :
     "This large wooden chest is where the town watch get there armour. The "
     "wooden chest is empty.",
     ]) );
  SetItemAdjectives( ([
     "chamber"    : ({"stone","small","square"}),
     "hall"       : ({"training","watchman"}),
     "doorway"    : ({"stone","arched"}),
     "south wall" : ({"far"}),
     "table"      : ({"small","round","wooden"}),
     "chair"      : ({"high","back","highback","wooden"}),
     "ceiling"    : ({"stone"}),
     ]) );
  SetListen( ([
     "default" : 
     "The ringing of steel hitting steel echos from the hall.",
     ]) );
  SetSmell( ([
     "default" : 
     "The scent of lightly oil weapons fills the air.",
     ]) );
  SetInventory( ([
     V_NPC + "equipper" : 1,
     ]) );
  SetExits( ([
     "out" : V_ROOM + "misc/t_hall",
     ]) );

}