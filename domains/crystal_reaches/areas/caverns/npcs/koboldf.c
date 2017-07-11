/*  Ordinary Kobold Female - Level #1 Caverns  */

#include <lib.h>
#include "../caves.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("kobold");
  SetId( ({ "kobold" }) );
  SetAdjectives( ({ "female", "dirty" }) );
  SetShort("a female kobold");

  SetLong("Wearing rags and appearing very dirty gives the impression that "
          "she is not cared for by her chief.  She appears to be increadibly "
          "bored out of her mind, as she doesn't have much to do except sit "
          "here.");

  SetRace("kobold");
  SetClass("fighter");
  SetLevel(3);
  SetGender("female");
  SetMorality(-50);
  SetFriends( ({ "kobold child", "kobold" }) );

  SetAction(10, ({ "The Kobold lazily picks her way around.",
                   "The Kobold looks overly bored.",
                   "The Kobold stares at you for the longest time.",
  }) );

  SetCombatAction(10, ({ "The Kobold attempts to defend herself as much as "
                         "possible.",
                         "The Kobold goes into a frenzy and froths at the "
                         "mouth.",
  }) );

  SetInventory( ([ OBJS + "/rags_kobold" : "wear rags",
                   OBJS + "/club1" : "wield club",
  ]) );
}
