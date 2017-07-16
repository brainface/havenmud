#include <lib.h>
#include <damage_types.h>

#include <domains.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("plump rat");
  SetShort("a plump rat");
  SetId( ({ "rat" }) );
  SetAdjectives( ({ "plump" }) );
  SetLong("This disgusting little creature looks like she hasn't "
          "missed a meal, considering she about as wide as two "
          "normal rats put together.");
  SetRace("rodent");
  SetSkill("melee attack", 1, 1);
  SetSkill("melee defense", 1, 1);
  SetGender("male");
  SetLevel(1);
  SetCombatAction(3, ({
    "!emote glares at you with her beady little eyes.",
    "!emote sceeches loudly.",
    }) );
  SetAction(3, ({
    "!emote wobbles around awkwardly.",
    }) );
  SetEncounter(101);
  SetMorality(-20);
   SetCorpseItems( ([ AVERATH_OBJ + "ratclaw" : 4 ]) );
}
