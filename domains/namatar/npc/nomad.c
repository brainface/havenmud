#include <lib.h>
#include <domains.h>
#include "../namatar.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetRace("minotaur");
  SetKeyName("namatarian nomad");
  SetId( ({ "nomad", "minotaur" }) );
  SetShort("a Namatarian nomad");
  SetAdjectives( ({ "namatarian" }) );
  SetLong(
    "This very large creature has the basic humanoid structure... two arms, two legs.  Cloven hooves. "
    "And a large head with the appearance of a bull."
    );
  SetClass("fighter");
  SetLevel(75);
  SetMorality(random(500) - 250);
  SetInventory( ([
    NAMATAR_OBJ "loincloth" : "wear loincloth",
    NAMATAR_OBJ "axe"       : "wield axe",
    ]) );
  SetEncounter(100);
  SetGender("male");
}