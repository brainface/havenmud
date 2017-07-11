/*    /realms/haun/areas/mines/npc/raven.c
 *    created on 12/20/98
 *    by Haun
 */
#include <lib.h>
#include "../mine1.h"
inherit LIB_NPC;
static void create() {
    npc::create();
    SetKeyName("raven");

    SetId( ( "raven" ) );
    SetAdjectives( ({"squawking", "small", "black"}) );
    SetShort("a squawking raven");
    SetLong("This small black raven, which is squawking violently, has very"
      " shiny black wings.  It appears that its beauty would embrace the sky"
      " at any moment.  After repeated attempts the bird gives up"
      " the hope of flying away. It appears to have been attacked"
      " by some large animal, because of some scars that appear on"
      " it's body.  Its wounds appear to have self-healed after many"
      " months of infection.");             
    SetRace("bird");
    SetGender("male");
    SetClass("animal"); 
    SetLevel(1);
    SetMorality(0);
    SetAction(6, ({ 
    	"The raven squawks loudly.", 
    	"The raven attempts to fly."
      }));
}
