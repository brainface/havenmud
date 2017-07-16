/*   Portia  1-6-99
     The Soirin Temple in Parva.
 */

#include <lib.h>
#include "../../parva.h"
inherit LIB_CHAPEL;

 static void create() {
 chapel::create();
 SetShort("a beautiful shrine");
 SetClimate("indoors");
 SetReligion("Soirin");
 SetTown("Parva");
 SetClasses( ({"cleric"}) );
 SetExits( ([
   "out" : P_ROOM + "/path6",
   ]) );
 SetListen( ([
   "default" : "The shrine is respectfully quiet.",
   ]) );
 SetSmell( ([
   "default" : "The shrine smells of incense.",
   ]) );
 SetInventory( ([
   PS_NPC + "/lita" : 1,
   ]) );
 SetLong("This small shrine is lit soley by flickering candles "
   "as no light from outside can enter. There are black roses "
   "scattered about the area, but mostly near the small altar "
   "at the front of the room. A large obsidian sculpture sits "
   "upon the altar which shimmers in the candle light.");
 SetItems( ([
   ({"shrine", "room", "area"}) : (:GetLong:),
   ({"light"}) : "The flickering light sets an eerie glow to the "
       "room.",
   ({"roses", "rose"}) : "The roses are the symbol of the Soirin faith.",
   ({"altar"}) : "The small altar is made of obsidian and "
       "shimmers in the candle light.",
   ({"sculpture"}) : "The sculpture is in the shape of a large rose.",
   ]) );
 SetItemAdjectives( ([
  "shrine" : ({"small"}),
 "light" : ({"candle", "flickering", "eerie"}),
   "roses" : ({"black", "scattered"}),
   "altar" : ({"small", "obsidian", "shimmering"}),
   "sculpture" : ({"large", "obsidian"}),
 ]) );
 }
