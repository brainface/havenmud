#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetShort("Inside a Cabin");
  SetAmbientLight(45);
  SetTown("Keryth");
  SetClimate("indoors");
  SetLong("Inside this humble house resides the only healer in town.  Wooden "
          "shelves with salves and other tools of the trade line the pale "
          "walls.  There is a cot set to one side for the very ill.  It "
          "appears to not see much use.");

  SetItems( ([
    ({ "humble house", "hut", "house" }) :
       (:GetLong:),
    ({ "wooden shelves", "wooden shelf", "shelf", "shelves" }) :
       "The wooden shelves stretch the entire length of the walls, and are "
       "held up by metal brackets.",
    ({ "black metal brackets", "black brackets", "metal brackets", "brackets",
       "black metal bracket", "black bracket", "bracket", "metal bracket" }) :
       "Black metal brackets support the wooden shelves.",
    ({ "pale walls", "pale wall", "walls", "wall" }) :
       "The room is encased by pale walls.  The give the room a light, "
       "friendly atmosphere.",
    ({ "tools of the trade", "instruments" }) :
       "Several different instruments line the shelves.  There are jars of "
       "salves, splints, and cloth to bandage wounds.",
    ({ "glass jars of salves", "glass jars", "glass jar", "salves",
       "jars of salves", "jar of salve", "salve", "jars", "jar" }) :
       "There is a line of glass jars which hold various healing salves.",
    ({ "wooden splints", "wooden splint", "splints", "splint" }) :
       "Wooden splints of varying lengths sit atop the shelves.  They look "
       "like they would splinter easily.",
    ({ "absorbent cloth", "cloth" }) :
       "Stacks of absorbent cloth sit atop the shelves.",
    ({ "military cot", "cot" }) :
       "This military style cot has sterile white sheets on it and is "
       "undisturbed.",
    ({ "sterile white sheets", "white sheets", "sterile sheets", "sheets" }) :
       "The white sheets are tucked in tightly under the thin mattress.",
    ({ "thin mattress", "mattress" }) :
       "The thin mattress on the cot doesn't look very comfortable."
  ]) );

  SetExits( ([ "out" : K_ROOM "kr_04" ]) );
  SetSmell( ([ "default" : "The smell of burnt incense is in the air." ]) );
}
