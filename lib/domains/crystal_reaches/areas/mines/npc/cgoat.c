/*    /realms/haun/areas/mines/npc/cgoat.c
 *    created on 12/20/98
 *    by Haun
*/
#include <lib.h>
#include "../mine1.h"
inherit LIB_SENTIENT;
static void create() {
    sentient::create();
    SetKeyName("mountain goat");
    SetId( ( "goat" ) );
    SetAdjectives( ({"crazed", "mountain"}) );
    SetShort("a crazed mountain goat");
    SetLong("This goat is staggering about in a crazed fashion.  It seems"
      "to have no idea where it is going, wandering aimlessly"
      " around the area trying to find its way.  This goat has"
      " tan color fur, and white spots under its neck and on"
      " its tail.");            

    
    SetRace("cow", "goat");
    SetClass("animal");
    SetLevel(4);
    SetGender("male");
    SetWander(15, ({ "go southwest", "go south", "go northwest", "go west"
      }));

    SetMorality(0);
    SetAction(6, ({ "The goat staggers around the room."}));
}
