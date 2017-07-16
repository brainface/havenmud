#include <lib.h>
#include <damage_types.h>

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("rabid dog");
  SetShort("a foamy-mouthed dog");
  SetId( ({ "dog" }) );
  SetAdjectives( ({ "foamy", "mouthed", "rabid" }) );
  SetLong("This battered animal has foam frothing from its mouth.");
  SetRace("dog");
  SetClass("animal");
  SetSkill("melee attack", 1, 1);
  SetSkill("melee defense", 1, 1);
  SetGender("female");
  SetLevel(3);
  SetCombatAction(3, ({
    "!emote howls in pain and frustration.",
    "!emote pants loudly.",
    "!bark",
    }) );
  SetAction(3, ({
    "!emote pants and sniffles.",
    }) );
  SetEncounter(101);
  SetMorality(-20);
}

