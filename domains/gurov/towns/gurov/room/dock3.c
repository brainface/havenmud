#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_FISHING;

static void create() {
  ::create();
  SetExits( ([
    "west"  : GUROV_ROOM "dock2",
    "north" : GUROV_ROOM "bay7",
    ]) );
  SetItems( ([
    "tavern" : "This is a local tavern.",
    ]) );
  SetEnters( ([
    "tavern" : GUROV_ROOM "tavern",
    ]) );  
  SetSpeed(5);
  SetFish( ([
    DIR_STD "fish/guppy" : 100,
    DIR_STD "fish/trout" : 50,
    DIR_STD "fish/boot" : 1,
    ]) );
  SetChance(25);
  SetMaxFishing(4);  
  SetShort("the docks near the Whiny Wench");
  SetLong(
    "The docks end here in front of a local tavern, this one known as "
    "\"the Whiny Wench\". The docks continue to the west, but the tavern "
    "has a certain look as if inviting people of less than reputable charms "
    "to explore within. The Gurov Bay gently crashes against the docks here, "
    "giving a quiet sense of peace and a longing for the sea."
    );
  SetSmell("The smells of shore, like rotting fish and seagull droppings, abound.");
  SetListen("The gentle waves of the Bay lap against the docks.");
}
