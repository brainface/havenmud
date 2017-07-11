/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: glade.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Unknown
// Abstract: The glade of Jidoor.
// Revision History: Originally coded by Zaxan@Haven.  
//                   Recoded entirely by Zaxan Zimtafarous@Haven
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_ROOM;

int PreExit(string dir);

static void create() {
   room::create();
   SetTown("Jidoor");
   SetClimate("temperate");
   SetShort("a glade near the Crystal Reaches");
   SetDayLong("One of the nicest areas in the city of Jidoor is this glade "
              "filled with beautiful flowers, soft grass and other "
              "remenants of the grand work of nature. The mountain range "
              "known as the Crystal Reaches is easily seen north of here "
              "and at its base, an opening of a dark cave is easily "
              "reachable. A small shop sits on the west side of the road "
              "with a sign above the entrance. To the east a mysterious "
              "fog is "
              "clouding the the local cemetery. Sunlight illuminates the "
              "area well but the mountains to the north create lots of "
              "shadows as well.");
   SetNightLong("One of the nicest areas in the city of Jidoor is this "
              "glade filled with beautiful flowers, soft grass and other "
              "remenants of the grand work of nature. The mountain range "
              "known as the Crystal Reaches is easily seen north of here "
              "and at its base, an opening of a dark cave is easily "
              "reachable. A small shop sits on the west side of the road "
              "with a sign above the entrance. To the east a mysterious "
              "fog is "
              "clouding the the local cemetery. At night, the area is "
              "dark but not dismal by any means.  A small torch above "
              "the entrance of the shop is the only source of light other "
              "than moonlight.");
   SetItems( ([ 
      ({ "glade","area","city","jidoor","city of jidoor" }) : (: GetLong :),
      ({ "flower","flowers" }) : "The flowers are beautiful.",
      ({ "grass","ground" }) : "The ground is covered with a soft green "
              "grass.",
      ({ "remenants" }) : "The grass and flowers are reminders of the "
               "great force of nature.",
      ({ "mountain","mountains","mountain range", "crystal reaches" }) : 
               "The Crystal Reaches surround Jidoor like a "
               "giant horseshoe  From this vantage point, one can easily "
               "see them north, west and east of here.  At the base of "
               "the mountain there is an opening to a dark cave.",
      ({ "cave","opening" }) : "An opening in the mountain leads into "
               "a dark cloud.",
      ({ "shop"}) : "The shop is a "
               "small small building made from stone and wood.  Above "
               "the door is a small sign.",
      ({ "torch" }) : "The torch resting above the entrance to the shop "
               "casts a fair degree of light here.",
      ({ "cemetery" }) : "The local cemetery is just east of here and "
               "appears to be a foreboding area.",
      ({ "fog" }) : "The fog swirling around in the local cemetery is "
               "heavy and ominous.",
      ({ "road" }) : "The road only leads back south into the city of "
               "Jidoor.",
   ]) );
   SetItemAdjectives( ([
      "flower" : ({ "beautiful" }),
      "grass" : ({ "green","soft" }),
      "cave" : ({ "dark" }),
      "shop" : ({ "small" }),
      "glade" : ({ "dark" }),
      "torch" : ({ "small" }),
      "cemetery" : ({ "local" }),
      "fog" : ({ "mysterious" }),
   ]) );
   SetRead("sign", "%^GREEN%^BOLD%^The Jidoor Healing Shop%^RESET%^");
   SetExits( ([ 
      "south" : JID_ROOM "/road10",
      "east" : JID_ROOM "/cemetery",
   ]) );
   AddExit(
      "northeast", 
        "/domains/valley/areas/undead_tower/room/entrance", (: PreExit :)
          );
   SetEnters( ([ 
      "cave" : JID_ROOM "/cave",
      "shop" : JID_ROOM "/misc_buildings/healing",
   ]) );
  SetDomain("Valley");
  SetListen( ([ "default" : "Nothing but the sounds of the wind pass "
                            "through the area.",
           ]) );
  SetSmell( ([ "default" : "The smell of the grass and flowers is "
                           "fresh in the air." ] ));
}

int PreExit(string dir) {
   if(this_player()->id("jid_protect")) { return 0; }
   else return 1;
}
