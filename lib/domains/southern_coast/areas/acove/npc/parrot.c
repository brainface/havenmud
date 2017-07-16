/*parrot
  Zara 8/7/98
*/

#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include "../acove.h"
inherit LIB_NPC;

static void create()
{
  npc::create();
  SetKeyName("parrot");
  SetShort("a parrot");
  SetId( ({"parrot"}) );
  SetAdjectives( ({"undead","colorful","scurvy"}) );
  SetLong("This scurvy parrot is missing most of his colorful "
         "plumage. Odd tufts of feathers remain, giving him "
         "a motley appearance.");
  SetGender("male");  
  SetRace("bird");
  SetUndead(1);
  SetClass("animal");
  SetLevel(3);
  SetAction(5,
        ({"!emote scans his surroundings with intense red eyes, "
           "squawking agitatedly."})
         );
  SetInventory( ([
         ]) );
}

int eventDie(object killer) {
  object pirate_inv = new("/std/invasions/parva_pirate/pip_inv");
  if (!random(4)) {
    INVASION_D->eventRegisterInvasion(pirate_inv, killer);
    }
  return ::eventDie(killer);
}
