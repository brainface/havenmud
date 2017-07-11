// Written by Vanyel
#include <lib.h>
#include "ice.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("ice wolf");
  SetShort("an icy blue wolf");
  SetId( ({ "wolf" }) );
  SetAdjectives( ({ "icy", "ice", "blue", "chillingly", "chilling", "pale" }) );
  SetRace("dog");
  SetClass("animal");
  SetLong("Chillingly blue, this pale wolf blends in with the "
    "surrounding snow and ice perfectly.");
  SetGender("male");
  SetWander(25);
  SetLevel(random(5)+10);
}
