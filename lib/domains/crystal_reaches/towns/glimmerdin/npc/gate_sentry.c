#include <lib.h>
#include "../path.h"
inherit LIB_TOWNGUARD;

static void create() {
  ::create();
  SetKeyName("gate sentry");
  SetId( ({ "sentry", "dwarf", "glim_wander" }) );
  SetAdjectives( ({ "gate", "dwarven", "dwarf", "bored" }) );
  SetShort("a bored dwarven sentry");
  SetLong(
    "Boredom radiates from the sentry who is guarding the entrance to "
    "the city. His lack of interest in passers-by doesn't say much for "
    "the rest of the city defense."
    );
  SetMorality(random(200));
  SetRace("dwarf");
  SetClass("fighter");
  SetLevel(35);
  SetTown("Glimmerdin");
  SetGender("male");
  SetInventory( ([ 
    G_OBJ "chainmail.c" : "wear chainmail",
    G_OBJ "axe.c" : "wield axe",
    G_OBJ "breeches.c" : "wear breeches",
    G_OBJ "boots.c" : "wear boots",
    ]) );
  SetFriends( ({ "glim_wander" }) );
}
