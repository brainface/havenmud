/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: ruins.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: Sept 17th, 1998
// Abstract: This is the ruins of the temple of Zaxan
/* ----------------------------------------------------------------------- */


#include <lib.h>
inherit LIB_ROOM;
#include "../jidoor.h"

static void create() {
  room::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetTown("Jidoor");
  SetShort("the ruins of a temple");
  SetDayLong(
            "This was once the site of the monument to the old and ancient "
            "god of magic but was destroyed in some cataclysmic event. All "
            "that remains now is the rubble of the massive temple that once "
            "stood here. The monument is now barely touched by "
            "sunlight and seems as thought it has almost been forgotten. "
            "The local goverment has put a sign nearby and declared the "
            "area a historical site.");
  SetNightLong(
            "This was once the site of the monument to the old and ancient "
            "god of magic but was destroyed in some cataclysmic event. All "
            "that remains now is the rubble of the massive temple that once "
            "stood here. The moonlight barely lights the area "
            "and it seems as though the temple of this forgotten god is "
            "now all but forgotten. The local goverment has put a sign "
            "nearby and declared the area a historical site.");
  SetItems( ([ 
          ({"temple", "rubble", "monument"}) : 
               "The remains of a church is hardly recognizable as anything "
               "but a massive pile of rubble.",
          ({"sign"}) : "The sign has some writing on it.",
          ({"site"}) : (: GetLong :),
          ]) );
  SetItemAdjectives( ([
            "temple" : ({ "destroyed", "massive" }),
            "monument" : ({"wonderous", "great", "great and wonderous"}),
            "rubble" : ({"pile of"})
                  ]) );
   SetRead("sign", "Once the temple of the fabled god of Magic known as "
            "Zaxan Zimtafarous, this site has been declared of "
            "historical importance to the city of Jidoor. It is a "
            "reminder of the original immortal who built this city and "
            "who lead us to Kailie. It is also a reminder of the great "
            "work of our lord, Zaxan Zimtafarous. He who has rebuilt this city "
            "from it's grim past and taken the Magildan faith to all "
            "new heights.");
  SetListen( ([ 
            "default" : "The silence of this area is a grim reminder of "
                  "what happened to the immortal whose temple used to be here."
             ]) );
  SetSmell( ([ 
            "default" : "The smell of dust is prevalent."
          ] ));
  SetExits( ([
      "east" : JID_ROOM "/road10",
          ]) );
  }
