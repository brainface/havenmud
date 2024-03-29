#include <lib.h>
inherit LIB_ROOM;
#include "../rook.h"
int DragonBait(string dir);
 
static void create() {
  room::create();
  
  SetShort("rook's lair");
  SetLong("This room appears to be the lair of something large.  The "
    "room is generally round in shape with some soft moss layering "
    "floor into a soft cushion.  Moss lines the walls, illuminating "
    "the room with bits of phosphorous stuck inside of it.  A slight "
    "shimmering reflection of light comes from the northwest and the "
    "sounds of a rushing river come from the south.");
  SetItems( ([
    ({"room","lair"}) : (:GetLong:),
    ({"moss","phosphorous"}) : "The moss forms a soft cushion on the "
      "ground, creating a welcome lair.  Small amounts of the moss "
      "also line the walls creating a soft glow of light from the "
      "phosphorous embedded into the moss.",
    ({"cushion"}) : "The moss creates a soft cushion on the ground.",
    ({"wall","walls"}) : "The walls are covered in the moss, creating "
      "the image of a carpeted wall.",
  ]) );
  SetItemAdjectives( ([
    "room" : ({"round","large"}),
    "cushion" : ({"soft","moss"}),
    "wall" : ({"moss","lined"}),
    "moss" : ({"illuminating","illuminated","phosphorous","soft"}),
    "light" : ({"shimmering","reflection","of"}),
  ]) );
  SetExits( ([
    "south" : R_ROOM + "lair8",
  ]) );
  SetClimate("indoors");
  AddExit("northwest", R_ROOM + "lair0", (: DragonBait :) );
  SetAmbientLight(0);
  SetSmell( ([
    "default" : "The room has no discernable odor."
  ]) );
  SetListen( ([
    "default" : "The sound of a river echos throughout the room."
  ]) );
  SetInventory( ([
    R_NPC + "rook" : 1,
    R_OBJ + "moss" : 5,
  ]) );
}

int DragonBait(string dir) {
  if (present("dragon", this_object())) {
    send_messages( ({ "eye", "prevent" }),
      "$agent_name $agent_verb $target_name carefully and "
      "$agent_verb $target_objective from going that way.",
      present("dragon", this_object()), this_player(), this_object() );
    return 0;
    }
  return 1;
 }
