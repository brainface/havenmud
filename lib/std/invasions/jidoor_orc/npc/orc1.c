// 
// Part of the 'Jidoor Orc' invasion
// Created by Zaxan@Haven
// Edited: Laoise, 2005

#include <lib.h>
#include "../oij.h"

inherit LIB_INVADER;
static void create() {
   invader::create();
   SetTown("Ungkh");
  SetKeyName("orc");
  SetShort("a dirty orc");
  SetId( ({ "orc", "orc_inv" }) );
  SetAdjectives( ({ "dirty" }) );   
  SetLong(
    "This orc is ready for the destruction of all in his path."
  );
  SetRace("orc");
  SetGender("male");
  SetClass("fighter");
  SetLevel(random(5)+15);
  SetInventory( ([ 
    OIJ_OBJ "/sword" : "wield sword" 
  ]) );
  SetCurrency("rupies", random(100)+50);
  SetAction(5, ({ 
    "!yell You puny Sprites shall die!",
    "!say How does it feel to have no wings?" 
  }) );
  SetFriends( ({ "orc_inv" }) );
  SetWanderSpeed(5);
  SetWanderPath( ({ 
    "go north", "go north", "go north", "go north",
    "go east", "go east", "enter inn", "attack barkeep" 
  }));
}
