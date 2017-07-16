/*  Ordinary Kobold Male - Level #1 Caverns  */

#include <lib.h>
#include "../caves.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("kobold");
  SetId( ({ "kobold" }) );
  SetAdjectives( ({ "male", "dirty" }) );
  SetShort("a male kobold");

  SetLong("Wearing rags and appearing very dirty gives the impression that he "
          "is not cared for by his chief.  He appears to be increadibly bored "
          "out of his mind, as he doesn't have much to do except sit here.");

  SetRace("kobold");
  SetClass("fighter");
  SetLevel(3);
  SetGender("male");
  SetMorality(-50);
  SetFriends( ({ "kobold child", "kobold" }) );

  SetAction(10, ({ 
  		"The Kobold lazily picks his way around.",
      "The Kobold looks overly bored.",
      "The Kobold stares at you for the longest time.",
  		}) );

  SetCombatAction(10, ({ 
  		"The Kobold attempts to defend himself as much as possible.",
      "The Kobold goes into a frenzy and froths at the mouth.",
      }) );

  SetInventory( ([ 
  		OBJS + "/rags_kobold" : "wear rags",
      OBJS + "/club1" : "wield club",
 			]) );
}
