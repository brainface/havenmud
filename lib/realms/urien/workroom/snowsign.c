#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("sign");
  SetId( ({ "sign" }) );
  SetAdjectives( ({ "covered", "snow" }) );
  SetShort("a snow covered sign");
  SetLong("This sign stands in the centre of the tower. It looks "
           "like someone carved into this piece of dishevelled wood. \n"
          "Perhaps you could <read> it.");
  SetRead( "default",
 //RP World Descriptions ONLY
    "\n"
    "    ________________________________      _______________    \n"
    "   /                           0    \\/\\  /       . .     |   \n"
    "  |   Portal Directory:                \\/       O. . .  <    \n"
    "  |        .   area - New Immortal Realm           .     |   \n"
    "  |       smokeshop - Lloryk Smokeshop       .           |   \n"
    "  |   o         hut - Platypus Bay Beach          .      |   \n"
    "   >          tower - Necromancers Tower                 |   \n"
 //   "  |           tairi - Wu Tang | 36 Chambers of Death     |   \n"
    "  | 0         ruins - Abandoned Ruins                    |   \n"
    "  |    headquarters - Invasion Control Room!             |   \n"
    "  |      .                                 o             |   \n"
    "  |___/\\________________________________________________/    \n"
    "                         | | U   .   |                        \n"
    "                         | |         |                        \n"
    "                         |      O    |                        \n"
    "                         |        |  |                        \n"                            
    );
// Just in case I need to add more lines to this sign
//  "  |                                                      |   \n"
   SetMass(20);
 } 
