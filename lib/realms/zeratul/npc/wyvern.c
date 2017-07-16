// Zeratul@Haven - Adam Haye
// 09/17/2013

#include <lib.h>
#include <damage_types.h>

inherit LIB_FEAR;
inherit LIB_NPC;

void eventPoisonBiteTail();

static void create() {
  npc::create();
  SetKeyName("Wyvern");
  SetGender("male");
  SetFearType("%^RED%^wyvern fear%^RESET%^");
  SetResistLevel(99);
  SetFearLength(random(40));
  SetShort("a red wyvern");
  SetLong(
      "This large creature is a wyvern covered in red scales. It's powerful "
      "legs support a large full body stretching the length of several adult "
      "elves while weighting more than multiple oxen. It's wings stretch high "
      "up into the air, capable of gliding large distances over the ground to "
      "hunt down it's prey. It has a large spiked tail covered in barbs while it's "
      "head, in a reptilian shape resembling that of a mix between a snake and "
      "small dragon, is covered with poisonous barbs. It also supports two large "
      "sacs at the base of it's jaw full of toxic venom. "
  );
  SetEncounter(250);
  SetMeleeAttackString("claw");
  SetRace("dragon");
  SetClass("animal");
  SetLevel(250);
  SetMorality(0);
  SetId( ({ "wyvern", "dragon", "reptile" }) );
  SetAdjectives( ({ "red", "scaled" }) );
  SetCombatAction(22,
      (: eventPoisonBiteTail :)
  );
}

void init() {
  fear::init();
  npc::init();
}


void eventPoisonBiteTail() {
  object target = GetCurrentEnemy();

  if( present(target) )
  {
      send_messages( "bite",
      "$agent_name %^RED%^BOLD%^$agent_verb ^%RESET%^$target_name "
      "with a venomous attack! ",
      this_object(), target, environment(target) );

      target->eventReceiveDamage(this_object(), ACID, GetHealthPoints(), 0);
  }

/*

  or
  {
      send_messages( "sting"
      "$agent_name %^RED%^BOLD%^$agent_verb %^RESET%^$target_name "
      "with a tail strike!",
      this_object, target, environment(target) );

      target->eventReceiveDamage(this_object(), PIERCE, GetHealthPoints(), 0);
  }

*/


  return;
}

