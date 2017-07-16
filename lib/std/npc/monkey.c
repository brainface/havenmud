#include <lib.h>
#include <std.h>
inherit LIB_NPC;
 
static void create() {
  npc::create();
  SetKeyName("monkey");
  SetId( ({"monkey", "animal"}) );
  SetAdjectives( ({"brown", "little", "cute"}) );
  SetShort("a brown monkey");
  SetLong("This is a cute little brown monkey. He is quite small "
        "and seems very frightened.");
  SetGender("male");
  SetRace("primate");
  SetClass("animal");
  SetLevel(3);
  }

/*Added for Monkey Meat quest in Baria */

int eventDie(object killer) {
  object meat;
  meat = new("/std/meal/food/monkeymeat");
  meat->eventMove(this_object());
  return (npc::eventDie(killer));
}


/*
int eventDie(object killer) {
  object pelt;
  pelt = new("/std/obj/treasure/pelt");
  pelt->eventMove(this_object());
  return (npc::eventDie(killer));
 }
*/

