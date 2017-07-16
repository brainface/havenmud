
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
     "Though the underbrush is heavy, a faint path can be seen leading north "
     "and south. Several of the trees here have scorch marks on them, as if "
     "there had been a recent fire."
     );
  SetNightLong(
     "The moon shines distantly through the thickly overgrown canopy, sending "
     "an eerie light down on the forest floor. Tall trees tower high into the "
     "air, their needles occasionally raining down when the wind blows. "
     "Though the underbrush is heavy, a faint path can be seen leading north "
     "and south. Several of the trees here have scorch marks on them, as if "
     "there had been a recent fire."
     );
  SetSmell( ([
     "default" : "The forest smells of mold and pine sap, with a hint of "
     "charcoal.",
     ]) );
  SetListen( ([
     "default" : "The sound of birds can be heard from above.",
     ]) );
  SetItems( ([
     ({"tree","trees","canopy"}) : "The trees here are ancient, and appear "
       "to be mostly pines.  Ugly scorch marks mar the bark, evidence of a "
       "fire.",
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
     ({"marks","mark"}) : "Carbon deposits clearly indicate some sort of "
     	 "combustion has occurred here.",
     ({"forest"}) : (:GetLong:),
    ]) );
  SetItemAdjectives( ([
     "floor" : "forest",
     "tree" : ({"tall","pine","ancient","towering","scorched"}),
     "needles" : ({"long","green","pine","rotted"}),
     "canopy" : "overgrown",
     "path" : "faint",
     "marks" : "scorch",
     "light" : ({"sickly","eerie","meager"}),
     "underbrush" : ({"small","heavy"}),
     ]) );
  SetInventory( ([
     VAAS_NPC + "stag" : 1,
     VAAS_NPC + "rabbit" : 2,
     ]) );
  SetExits( ([
     "north" : VAAS_ROOM + "forest2",
     "south" : VAAS_ROOM + "forest4",
     ]) );
}