/*  My Angel Area.  A small forest.
 *  Edited further by Vaashan@Haven 9/01/09
 */
#include <lib.h>
#include "../vaashan.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetAmbientLight(25);
  SetClimate("sub-arctic");
  SetShort("a dismal forest");
  SetDayLong(
     "The sun shines distantly through the thickly overgrown canopy, sending "
     "a sickly light down on the forest floor. Tall trees tower high into "
     "the air, their needles occasionally raining down when the wind blows. "
     "A large broken stump is visible here, perhaps where lightning may have "
     "struck years ago. Though the underbrush is heavy, a faint path can be "
     "seen leading southeast and north."
     );
  SetNightLong(
     "The moon shines distantly through the thickly overgrown canopy, sending "
     "a eerie light down on the forest floor. Tall trees tower high into "
     "the air, their needles occasionally raining down when the wind blows. "
     "A large broken stump is visible here, perhaps where lightning may have "
     "struck years ago. Though the underbrush is heavy, a faint path can be "
     "seen leading southeast and north."
     );
  SetSmell( ([
     "default" : "The forest smells of mold and pine sap.",
     ]) );
  SetListen( ([
     "default" : "The sound of birds can be heard from above.",
     ]) );
  SetItems( ([
     ({"tree","trees","canopy"}) : "The trees here are ancient, and appear "
       "to be mostly pines.",
     ({"light","sunlight","moonlight"}) : "The light from above has trouble "
       "penetrating through to the lowest levels of the forest.",
     ({"needles","needle"}) : "Long green needles occasionally drift from high "
         "above to the forest floor.",
     ({"underbrush","shrub","shrubs","bush","bushes"}) : "Small shrubs and "
         "bushes struggle for existance in the meager light allowed them from "
         "the towering trees above.",
     ({"floor","ground"}) : "The forest floor is covered in several "
       "centimeters of rotted pine needles.",
     ({"path"}) : "This path appears to be the result of animals moving about.",
     ({"stump"}) : "This jagged stump stretches about a meter into the air, "
         "where it ends in a sharp sliver of wood.",
     ({"forest"}) : (:GetLong:),
    ]) );
  SetItemAdjectives( ([
     "floor" : "forest",
     "tree" : ({"tall","pine","ancient","towering"}),
     "needles" : ({"long","green","pine","rotted"}),
     "canopy" : "overgrown",
     "path" : "faint",
     "stump" : ({"broken","large","jagged"}),
     "light" : ({"sickly","eerie","meager"}),
     "underbrush" : ({"small","heavy"}),

     ]) );
  SetInventory( ([
     VAAS_NPC + "rabbit" : 4,
     ]) );
  SetExits( ([
     "southeast" : VAAS_ROOM + "forest5",
     "north" : VAAS_ROOM + "forest7",
     ]) );
}
