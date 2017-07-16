// 
// Leader of the 'Jidoor Orc' invasion
// Created by Zaxan@Haven
// Edited: Laoise, 2005

#include <lib.h>
#include "../oij.h"

inherit LIB_INVADER;
static void create() {
  invader::create();
   SetTown("Ungkh");
  SetKeyName("orc leader");
  SetShort("a dirty orc leader");
  SetId( ({ "orc", "leader", "orc_inv" }) );
  SetAdjectives( ({ "dirty" }) );
  SetLong(
    "This orc is ready for the destruction of all in his path. He "
    "looks like he has very much control of the situation."
  );
  SetRace("orc");
  SetGender("male");
  SetClass("fighter");
  SetLevel(random(5)+30);
  SetInventory( ([ 
    OIJ_OBJ "/sword" : "wield sword",
    OIJ_OBJ "/chain" : "wear chainmail" 
  ]) );
  SetCurrency("rupies", random(100)+100);
  SetAction(5, ({ 
    "!yell You puny Sprites shall die!",
    "!say How does it feel to have no wings?",
    "!say Destroy it all!",
    "!say Follow me!" 
  }) );
  SetFriends( ({ "orc_inv" }) );
  SetWanderSpeed(10);
  SetWanderPath( ({ 
  "go north", "go north", "go north", "go north",
  "go north", "go north", "go north", "go north",
  "enter cave", "attack hima" 
  }) );
}
