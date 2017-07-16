/*    /realms/haun/areas/mines/npc/mgoat.c
 *    created on 12/20/98
 *    by Haun
*/
#include <lib.h>
#include "../mine1.h"
inherit LIB_NPC;
static void create() {
    npc::create();
    SetKeyName("ram");
    SetId( ( "ram" ) );
    SetAdjectives( ({"large"}) );
    SetShort("a large ram");
    SetLong("This mountain goat is a dull tan color, and it has white spots"
      " under his neck and on his tail.  There are huge horns jutting out of"
      " this ram's head, which appear to have a light gray tint."
      " It seems to have great composition, and is the tallest in the"
      " group.");


    SetRace("cow", "goat");
    SetClass("animal");
    SetGender("male");
    SetLevel(5);
    SetMorality(0);
    SetAction(6, ({ "A goat eats from a small bush."}));
}
