//
// Virtual replacement room leading to Sarde
// filename: 2,10
// Thoin@Haven 01-16-06
//

#include <lib.h>

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("in a sweltering jungle");
   SetClimate("tropical");
   SetDomain("Baria");
   SetDayLong(
              "A small path has been carved from the jungles edge leading "
              "north into the low-land hills of the frostmarches. The jungle "
              "continues futher to the south as well as the east and west. The "
              "frostmarches rise out of the ground to the north. Sunlight "
              "shimmers into the room through the dense jungle lighting the "
              "small dirt path."
   );
   SetNightLong(
                "To the north several fires can be seen within the cave mouths "
                "in the low-land foothills of the frostmarches. The jungle "
                "surrounds everything except for a small path that leads north "
                "into the foothills. Through the dense jungle starlight illuminates "
                "the small path."
   );
   SetItems( ([
      ({ "jungle", "ground", "room" }) :
         (: GetLong :),
      ({ "hills", "froshmarches", "peaks", "foothills" }) :
         "The frostmarches slowly rise in the northern distance into a great "
         "mountain range with snow capped peaks.",
      ({ "sunlight" }) :
         "Sunlight shimmers into the room through the dense jungle exposing "
         "the dirt path.",
      ({ "fires", "fire", "light" }) :
         "The flickering lights of the fires expose the cave mouths hidden "
         "in the foothills.",
      ({ "mouth", "mouths" }) :
         "Several caves can be seen in the northern distance, they appear to "
         "house creatures about human size.",
      ({ "path" }) :
         "The small dirt path slowly carves its way through the jungle into "
         "the northern foothills.",
      ({ "starlight", "stars" }) :
         "The barely visible stars twinkle slightly through the dense brush "
         "of the jungle. Providing a small amount of light.",
   ]) );
   SetItemAdjectives( ([
      "hills" : ({ "low-land" }),
      "path" : ({ "small", "dirt" }),
      "fires" : ({ "flickering" }),
      "mouths" : ({ "cave" }),
      "jungle" : ({ "dense" }),
   ]) );  
   SetExits( ([ 
      "north" : "/realms/thoin/sarde/room/outside2",
      "east" : "/domains/baria/virtual/jungle/3,10",
      "west" : "/domains/baria/virtual/jungle/1,10",
      "south" : "/domains/baria/virtual/jungle/2,9",
   ]) );
}
