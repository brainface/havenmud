//Mahkefel@Haven
//2011
#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

void eventSpecial();

static void create() {
  npc::create();
  SetKeyName("viper");
  SetId( ({"viper"}) );
  SetShort("a horned viper");
  SetAdjectives( ({ "spitting" }) );
  SetRace("snake");
  SetSkill("dodge",1);
  SetSkill("parry",1);
  SetClass("animal");
  SetLevel(10);
  SetGender("male");
  SetLong(
    "This viper is colored a spottled brown; he might "
    "be hard to see along the desert sands. Two small horns "
    "cover his eyes."
  );
  SetFirstCommands( ({ "emote %^ORANGE%^bursts%^RESET%^ from the ground!"}) );
  SetAction(6, ({
     "!emote slowly burrows backward into the ground.",
     "!emote twitches angrily.",
  }) );
}

void eventMeleeAttack(object target, string limb) {
  npc::eventMeleeAttack(target, limb);
  if(!(random(10))) {
    target->AddPoison(10);
  message("system",
        "You feel the %^RED%^poison%^RESET%^ moving through your body.",
        target);
    message("system",
        capitalize(target->GetKeyName()) + " suddenly looks ill.",
        environment(target), target);
    }
  return;
}

