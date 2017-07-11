/*  Kobold Guards  -  Level #1 Caverns */

#include <lib.h>
#include "../caves.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("kobold guard");
  SetId( ({ "kobold guard", "kobold", "guard" }) );
  SetAdjectives( ({ "kobold", "guard", "large" }) );
  SetShort("a kobold guard");

  SetLong("The Kobold Guard is one of the largest kobolds in the tribe.  "
          "In addition to being very large, he also seems very ready to fight "
          "with his weapon out and ready.  He also wears some bright orange "
          "leather armour, which appears to be in pretty good condition.");

  SetRace("kobold");
  SetClass("fighter");
  SetSkill("pierce combat",1,2);
  SetLevel(5);
  SetGender("male");
  SetMorality(-95);
  SetFriends( ({ "kobold chief" }) );
  SetDie("The Kobold Guard spends his last breath in the attempt of "
         "defending his chief.");

  SetAction(10, ({ "The Kobold Guard picks his nose.",
                   "The Kobold Guard looks very bored with his exsistance.",
                   "The Kobold Guard looks about ready to topple over.",
  }) );

  SetCombatAction(10, ({ "The Kobold Guard growls furiously.",
                         "The Kobold Guard attempts to defend his chief.",
  }) );

  SetInventory( ([ OBJS + "/armour_leather1" : "wear koboldish leather",
                   OBJS + "/spear_crude1.c" : "wield spear",
  ]) );
}
