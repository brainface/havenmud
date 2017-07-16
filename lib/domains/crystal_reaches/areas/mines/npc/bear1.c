/*    /realms/haun/areas/mines/npc/bear1.c
 *    created on 12/20/98
 *    by Haun
 */

#include <lib.h>
#include "../mine1.h"
inherit LIB_NPC;
static void create() {
    npc::create();
    SetKeyName("brown bear");
    SetId( ( "bear" ) );
    SetAdjectives( ({"brown", "large", "huge", "powerful"}) );
    SetShort("a brown bear");
    SetLong("This huge brown bear appears to be a very powerful animal."
      "  It had matted brown fur, and black facial features.  It seems to be"
      " searching for food.");             
    

    SetRace("bear");
    SetClass("animal");
    SetGender("male");
    SetLevel(9);
    SetMorality(0);
    SetAction(6, ({ "The bear growls as it rises to its feet."}));
}
