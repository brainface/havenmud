#include <lib.h>
#include "../path.h"

inherit LIB_SENTIENT;

static void create()
{
  ::create();
  SetKeyName("rat");
  SetId( ({ "a rat", "rat" }) );
  SetAdjectives( ({ "mutant", "oddlooking", "orange", "pale" }) );
  SetShort("a mutant rat");
  SetLong("This animal is rather oddlooking for a rat. The mutatations "
          "that its ancesotors accumulated while living in Teras' lab "
          "have added to its departure from a normal appearance.  Its "
          "fur has deviated to a pale orange and his eyes have grown "
          "to about twice the normal size.");
  SetRace("rodent");
  SetClass("animal");
  SetGender("male");
  SetLevel(5);
  SetMorality(0);
  SetAction(4, ({"A rat scuffles around looking for food to eat.",
                 "A rat stands up straight and sniffs around." }) );
  SetWander(25);
  SetDie("The rat lets out a horrible shriek as he passes from existence.");
  SetProperty("lab_wander", 1);
}
