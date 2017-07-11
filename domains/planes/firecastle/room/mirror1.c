//
// filename: mirror1
// Thoin@Haven 01-16-06
//

#include <lib.h>
#include "../firecastle.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("inside the castle");
   SetClimate("indoors");
   SetProperty("lower plane",1);
   SetAmbientLight(35);
   SetLong(
              "From the inside the castle appears to be well maintained and "
              "resistant to the harsh outside. Hallways lead to the northwest "
              "as well as to the northeast. The walls are bare except for a "
              "few scorch marks. Small bits of ash lightly dust the floor. "
   );
   SetItems( ([
      ({ "castle" }) :
         (: GetLong :),
      ({ "hallways", "hallway" }) :
         "The hallways lead off in two direction, to the northwest and the "
         "northeast. Neither direction looks any different from the other.",
      ({ "walls", "wall", "stone" }) :
         "The walls are completely bare except for a few scorch marks. They "
         "are made from some undiscernible material.",
      ({ "mark", "marks" }) :
         "The scorch marks are scattered on the walls and appear to be fresh. "
         "They appear to be of made from hands or perhaps claws.",
      ({ "ash" }) :
         "Small piles of ash lightly dust the floor creating a thin layer. The "
         "ash itself is as white as snow.",
      ({ "floor" }) :
         "The floor is thinly covered in a layer of ash.",
   ]) );
   SetItemAdjectives( ([
      "mark" : ({ "few", "scorch" }),
      "ash" : ({ "small", "bits", "piles" }),
   ]) );  
   SetListen( ([
      "default" : "The sounds of roaring flames echo through the room.",
   ]) );
   SetSmell( ([
      "default" : "The bitter smell of sulfur fills the air.",
   ]) );
   SetExits( ([ 
      "northeast" : FCASTLE_ROOM "mirror3",
      "northwest" : FCASTLE_ROOM "mirror2",
   ]) );
   SetInventory( ([
      FCASTLE_NPC "knight1" : 2,
   ]) );
}
