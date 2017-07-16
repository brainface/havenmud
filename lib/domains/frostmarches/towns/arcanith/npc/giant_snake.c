/* A giant snake */

#include <lib.h>
#include "../ruins.h"
#include <damage_types.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("snake");
  SetId( ({ "snake" }) );
  SetAdjectives( ({ "giant" }) );
  SetShort("a giant snake");
  SetLong("The giant snake measures well over twelve feet long.  Her green "
          "scales glisten slightly.  A forked tongue quickly slides in "
          "and out of her mouth.");

  
  SetRace("snake");
  SetTown("all");
  SetClass("animal");
  SetGender("female");
  SetLevel(3);
  SetMorality(0);
  
  SetAction(5, ({ "The snake hisses threateningly." }) );
  SetMeleeAttackString("sharp teeth");
  SetMeleeDamageType(POISON);
  SetDie("The snake's tail twitches violently in her deaththroes.");

}
