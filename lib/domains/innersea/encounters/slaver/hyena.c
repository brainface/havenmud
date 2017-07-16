// mahkefel 20111017
// hyena, can't swim
//   infects dudes with wasting sickness.
#include <lib.h>
#include <domains.h>
#include <std.h>
#include <damage_types.h>
inherit LIB_NPC;

void doAction();

static void create() {
  ::create();
  SetKeyName("hyena");
  SetShort("a blood soaked hyena");
  SetId( ({ "hyena" }) );
  SetAdjectives( ({ "blood","soaked" }) );
  SetRace("wolf","hyena");
  SetTown("Lisht");
  SetClass("animal");
  SetMorality(-500);
  SetSkill("dodge",1);
  SetSkill("combat rage",1);
  SetSkill("accuracy",1);

  SetLevel(50);
  SetLong(
    "This slinking beast looks to have grown fat on the flesh "
    "of dead slaves, and the remains of her meals are still coating "
    "her mottled flesh. The wide grin forming at here mouth probably "
    "doesn't promise friendship."
  );
  SetGender("female");
  SetAction(10, ({
    "!cackle evilly",
    "!emote sniffs around for something dead to eat."
  }) );
  SetCombatAction(10, (:doAction:) );
  SetProperty("pirate", "gnoll");
}

void doAction() {
  object who = this_object();
  object target = GetCurrentEnemy();
  send_messages("snap",
    "$agent_name%^ORANGE%^ $agent_verb%^RESET%^ at $target_name, "
    "piercing $target_objective with $agent_possessive powerful "
    "jaws!",
    who, target, environment() );
  target->eventReceiveDamage(who, BLUNT|PIERCE, random(100), 0,
    target->GetRandomLimb("torso") );
  if (random(target->GetStatLevel("durability") +
    target->GetStatLevel("luck")) < 25) {
    target->eventPrint("You have a sinking feeling as you wonder "
      "what else this noxious scavenger has been eating.");
    STD_GERMS "waste_sick"->eventInfect(target);
  }
  eventForce("cackle"); 
  return;
}

