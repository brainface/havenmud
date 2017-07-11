/*    /realms/haun/areas/mines/npc/fgoat.c
 *    created on 12/20/98
 *    by Haun
 */
#include <lib.h>
#include "../mine1.h"
inherit LIB_NPC;
static void create() {
    npc::create();
    SetKeyName("mountain goat");
    SetId( ( "goat" ) );
    SetAdjectives( ({"mountain"}) );
    SetShort("a mountain goat");
    SetLong("This mountain goat is a dull tan color, and it has white spots"
      " under his neck and on his tail.  It seems to have great composition,"
      " and is very tall.");             
    
    
    SetRace("cow", "goat");
    SetClass("animal");
    SetLevel(5);
    SetGender("female");
    SetMorality(0);
}
