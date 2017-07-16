/*   Portia  12-11-98
     The Soirin Church
     version 2.0
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_CHAPEL;

 static void create() {
 chapel::create();
 SetShort("Church of Soirin");
 SetClimate("indoors");
 SetReligion("Soirin");
 SetTown("Malveillant");
 SetClasses( ({"cleric"}) );
 SetExits( ([
   "out" : MAL_ROOMS + "path11",
   "east" : MAL_ROOMS + "grave",
   ]) );
 SetListen( ([
   "default" : "The church is respectfully quiet.",
   ]) );
 SetSmell( ([
   "default" : "The church smells of flowers and incense.",
   ]) );
 SetInventory( ([
   MAL_OBJ + "/misc/statue" : 1,
   MAL_OBJ + "/misc/rose" : 5,
   MAL_NPC + "cleric_lead" : 1,
   MAL_NPC + "healer" : 1,
   MAL_OBJ + "/misc/pleasurable_worship" : 1,
   MAL_OBJ + "/misc/dayofroses" : 1,
   ]) );
 SetLong("This enormous place of worship has been carved "
   "out of the finest obsidian, and great detail was put "
   "into the ornate carvings on the walls. Rows of pews "
   "respectfully face the large shining altar, each adorned "
   "with a wreath of black roses. The altar itself has a "
   "carving of the symbolic black rose that shimmers in the "
   "candle light. Heavy doors lead out to the east while "
   "smaller lighter doors stand wide open leading out to the "
   "center of town welcoming all who pass.");
 SetItems( ([
   ({"church", "church of soirin", "place", "place of worship"}) :
       (:GetLong:),
   ({"obsidian", "walls", "carvings", "wall", "carving"}) :
       "The large walls of obsidian are highly decorated.",
   ({"pews", "rows", "rows of pews"}) : "The obsidian pews are "
       "garnished with wreaths.",
   ({"altar"}) : "The large altar is quite intimidating.",
   ({"wreaths", "wreath", "symbol"}) :
       "The wreaths of roses symbolize the Soirin faith.",
   ({"light", "candle light"}) : "The light glints off of the "
       "altar",
   ({"heavy doors", "door"}) : "The heavy doors lead eastward.",
   ({"lighter doors", "door"}) : "The light doors lead west "
       "towards town.",
   ]) );
 SetItemAdjectives( ([
   "church" : ({"enormous"}),
   "obsidian" : ({"finest", "large", "decorated"}),
   "pews" :  ({"obsidian", "garnished", "adorned"}),
   "altar" : ({"large", "intimidating", "obsidian" }),
   "wreaths" : ({"large", "black"}),
   ]) );
 }
