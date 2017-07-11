//
// filename: mirror5
// Thoin@Haven 01-16-06
//

#include <lib.h>
#include "../firecastle.h"

inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("a small room");
   SetClimate("indoors");
   SetProperty("lower plane",1);
   SetAmbientLight(35);
   SetLong(
              "The hallway dead ends in this small room. The only exit leads "
              "to the south. Several burned tapestries hang from the walls and "
              "a thick layer of ash covers the floor. Near the back of the room "
              "a small desk can be seen."
   );
   SetItems( ([
      ({ "hallway", "room" }) :
         (: GetLong :),
      ({ "walls", "wall", "tapestries" }) :
         "The walls covered in burned tapestries. The tapestries are made "
         "from some gossamer material and depict a scene of a large knight "
         "being burned alive.",
      ({ "ash", "floor" }) :
         "The floor is covered in a thick layer of ash. The ash covers "
         "the entire floor and appears to of been made into a small pile "
         "near the desk.",
      ({ "pile" }) :
         "This small pile of ash looks out of place next to the desk.",
      ({ "desk" }) :
         "This small desk is perfectly clean without a spec of dust or "
         "ash on it. It appears to be made from a type of wood. On the "
         "top of the desk an impression of what appears to be a key "
         "can be seen.",
   ]) );
   SetItemAdjectives( ([
      "hallway" : ({ "small" }),
      "tapestries" : ({ "burned" }),
      "ash" : ({ "thick" }),
      "pile" : ({ "small" }),
      "desk" : ({ "small" }),
   ]) );  
   SetListen( ([
      "default" : "The sounds of roaring flames echo through the room.",
   ]) );
   SetSmell( ([
      "default" : "The bitter smell of sulfur fills the air.",
   ]) );
   SetExits( ([ 
      "south" : FCASTLE_ROOM "room3",
   ]) );
   SetInventory( ([
      FCASTLE_NPC "rogue1" : 1,
   ]) );
}