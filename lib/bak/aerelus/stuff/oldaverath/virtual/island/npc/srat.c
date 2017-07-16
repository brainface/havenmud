#include <lib.h>
#include <damage_types.h>

#include <domains.h>
inherit LIB_NPC;

static void create() {
  ::create();

  SetKeyName("skinny rat");
  SetId( ({"rat"}) );
  SetAdjectives( ({"skinny"}) );
  SetShort("a skinny rat");
  SetLong("This little creature scurries around looking for food. "
     "She looks like she hasn't eaten in days, her beady little eyes "
     "looking you over for her next meal.");
  SetRace("rodent");
  SetSkill("melee attack", 1, 1);
  SetSkill("melee defense", 1, 1);
  SetGender("female");
  SetLevel(2);
  SetCombatAction(3, ({
    "!emote glares at you with her beady little eyes.",
    "!emote looks for a place to hide.",
    "!emote bites at your leg.",
    }) );
  SetAction(3, ({
    "!emote searches the floor for food.",
    "!emote squeaks loudly.",
    }) );
   SetCorpseItems( ([ AVERATH_OBJ + "ratclaw" : 4 ]) );
}
