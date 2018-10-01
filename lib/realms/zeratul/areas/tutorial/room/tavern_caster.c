// Zeratul@Haven - Adam Haye
// 09/12/2013

#include <lib.h>
#include "../tutorial.h"

inherit LIB_ROOM;

static void create () {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("within a secluded room");
  SetLong(
      "This room is tucked into the corner of the tavern. It is one of three rooms "
      "that branches off at the end of the hallway. Within this room is a small set "
      "of furniture situated around a desk in the center. There is an arrangement "
      "of chairs aimed to face the seat at the head of the desk. A chandelier of "
      "bronze hangs from the ceiling down as a focal point of the room. There is "
      "little in the way of furnishings on the perimeter of the room whilst "
      "the walls themselves remain completely bare of detail outside of the wood "
      "form that matches the architecture of the rest of the structure. "
      "\nType <%^MAGENTA%^BOLD%^greet trainer%^RESET%^> for instructions. "
  );
  SetInventory( ([
  ]) );
  SetItems( ([
      ({ "desk", "chairs" }) :
      "The desk is placed precisely in the center of the room. It acts as both a "
      "meeting location as well as a focal point for the center of the room. ",
      ({ "chandelier" }) :
      "This bronze cast chandelier hangs at the center of the room above the desk. "
      "It is a sturdy and functional piece of equipment with several candles arranged "
      "amongst it's four arms that stretch out from the center in a curved pattern. ",
      ({ "wall", "walls" }) :
      "The walls of this room have no furnishings or decoration of any kind. They "
      "seem to be very well insulated from the rest of the building. ",
  ]) );
  SetItemAdjectives( ([
      "chandelier" : ({ "bronze" }),
      "walls" : ({ "wood", "wooden", "bare" }),
  ]) );
  SetSmell( ([
      "default" : "The aroma of dry and stale air lingers here.",
  ]) );
  SetListen( ([
      "default" : "It is quiet and calm here.",
  ]) );
  SetExits( ([
      "west" : T_ROOM + "tavern2",
  ]) );
}
