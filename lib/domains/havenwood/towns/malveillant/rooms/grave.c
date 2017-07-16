/*   Portia  12-11-98
     The graveyard.
     version 2.0
 */

#include <lib.h>
#include <std.h>
#include "../mal.h"
inherit LIB_ROOM;

 static void create() {
 room::create();
 SetShort("a dark graveyard");
 SetNoClean(1);
 SetClimate("underground");
 SetExits( ([
   "west" : MAL_ROOMS + "church",
   ]) );
 SetListen( ([
   "default" : "The graveyard is deathly quiet.",
   ]) );
 SetSmell( ([
   "default" : "The area smells faintly of decaying "
       "flesh",
   ]) );
 SetInventory( ([
     STD_OBJ "reztotem" : 1,
/*
    "/quests/alchemist/npc/whey_spider" : 5,
*/
   MAL_NPC + "necro_lead" : 1,
   ]) );
 SetLong("The graveyard of Malveillant is a place "
   "of evil. The graves are lined up in neat rows "
   "but despite the obvious order the place radiates "
   "a sense of fear. The ground is covered in moss "
   "and the fungus has started to cover some of the "
   "headstones. The seclusion of this place allows "
   "one to mourn their dead in relative peace.");
 SetItems( ([
   ({"graveyard", "place", "this place"}) : (:GetLong:),
   ({"graves", "grave", "rows", "row", "neat rows"}) :
       "The graves are aligned perfectly.",
   ({"ground", "moss", "headstones", "headstone"}) :
       "The headstones and the ground are covered with moss.",
   ]) );
 SetItemAdjectives( ([
   "graves" : ({"aligned", "neat", "perfectly"}),
   "ground" : ({"covered"}),
   ]) );
 }

