#include <lib.h>
#include <vendor_types.h>
#include "../../parva.h"

inherit LIB_CHAPEL;
 
static void create() {
  chapel::create();
  SetShort("a Thorian Shrine");
  SetClimate("indoors");
  SetAmbientLight(15);
  SetExits( (["out" : P_ROOM + "/cpath" ]) );
  SetProperty("no bump", 1);
  SetInventory( ([ PS_NPC + "/garric" : 1 ]) );
  SetLong("This wooden shack is about as basic as one can get.  The thin "
          "planks that make up the walls are bare and unpainted.  The only "
          "feature here is a small fire which provides a little light.");
  SetItems( ([
               ({ "thin planks", "planks", "thin plank", "plank", "walls",
                  "wall" }) :
                  "Nothing adorns these simple plank walls, as they serve no "
                  "purpose other than to support the ceiling.",
               ({ "small fire", "fire" }) :
                  "The fire is indeed small, and no source of fuel is "
                  "visible.  It simply burns there on the ground."
             ]) );
  SetTown("Parva");
  SetReligion("Thorian", "Thorian");
  SetClasses( ({ "cleric" }) );
  SetAllowSacrifice(1);
  SetSacrificeType(VT_ALL);
  SetDeities( ({ "Zeddicus" }) );
}
