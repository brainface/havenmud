/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: cemetery.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Unknown
// Abstract: The cemetery of Jidoor.
// Revision History: Originally coded by Zaxan@Haven.  
//                   Recoded entirely by Dylanthalus@Haven
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <std.h>
#include "../jidoor.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetProperties( ([ 
   ]) );
   SetDomain("Valley");
   SetShort("the Jidoor Cemetery");
   SetDayLong("The Jidoor cemetery is a dark an mysterious place. A "
              "heavy fog covers the hilly area of tombstones and grave "
              "markers. This is the final resting place for the souls "
              "of the citizens of Jidoor. Rumour has it that some "
              "have mysteriously appeared in the cemetery suddenly "
              "regaining life again. To the west a beautiful glade "
              "occasionally can be seen through the fog. Just south of "
              "here is Mystic's Crescent. Although it is daytime, the "
              "area is dark and ominous. A mausoleum rests in the "
              "center of the cemetery.");
   SetNightLong("The Jidoor cemetery is a dark an mysterious place. A "
              "heavy fog covers the hilly of tombstones and grave "
              "markers. This is the final resting place for the souls "
              "of the citizens of Jidoor. Rumour has it that some "
              "have mysteriously appeared in the cemetery suddenly "
              "regaining life again. To the west a beautiful glade "
              "occasionally can be seen through the fog. South of "
              "here is the well lit, Mystic's Crescent. During the "
              "night, the cemetery is a scary enviroment. A mausoleum "
              "rests in the center of the cemetery.");
   SetItems( ([ 
      ({ "cemetery","place","area" }) : (: GetLong :),
      ({"crescent"}) : "The fog makes it hard to see from here.",
      ({ "fog" }) : "The heavy fog of the cemetery is blanketing "
             "the area in a white myst.",
      ({ "tombstone","tombstones","markers","marker" }) : "",
      ({ "soul","souls" }) : "One cannot see a soul.",
      ({ "glade" }) : "The glade is just west of here and is barely "
                "visible through the fog.",
      ({ "mausoleum","building" }) : "The mausoleum is a dark stone "
              "building that rests just slightly above the ground as "
              "most of it is in buried.",

           ]) );
   SetItemAdjectives( ([
      "crescent" : ({"mystic's"}),
      "cemetery" : ({ "jidoor","dark","mysterious","hilly","resting" }),
      "fog" : ({ "heavy" }),
      "tombstone" : ({ "grave" }),
      "glade" : ({ "beautiful" }),
                    ]) );
   SetExits( ([ 
      "west" : JID_ROOM "/glade",
      "south" : JID_ROOM "/road17",
           ]) );
   SetEnters( ([ 
      "mausoleum" : JID_ROOM "/misc_buildings/mausoleum",
           ]) );
  SetDomain("Valley");
  SetListen( ([ "default" : "Erie noises filter around the cemetery.",
                "souls" : "The sounds of souls mix in emotions from "
                          "every imaginable feeling. Some are joyous "
                          "and others are angry."  ]) );
  SetSmell( ([ "default" : "The air is moist and heavy." ] ));
  SetInventory( ([
    STD_OBJ "reztotem" : 1,
  ]) );
}
