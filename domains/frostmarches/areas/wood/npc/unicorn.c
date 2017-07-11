/* a unicorn
  Ela 8/3/98
*/


#include <lib.h>
#include "../wood.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("unicorn");
  SetId( ({
          "unicorn",
          }) );
  SetAdjectives( ({
          "majestic", "regal", "legendary", "white",
          }) );
  SetShort("a majestic unicorn");
  
  SetMorality(1500);
  SetRace("unicorn");
  SetClass("animal");
  SetLevel(50);
  SetGender("female");
  SetAction(5,({
          "The unicorn shakes her head, tossing her mane wildly."
          }) );
  SetLong("Majestic and regal, this legendary white beast glows "
          "with goodness. A single horn adorns her brow.");
}

int eventDie(object agent) {
  object horn;

  horn = new(WOOD_OBJ + "horn");
  horn->eventMove(this_object());
  return (npc::eventDie(agent));
}
