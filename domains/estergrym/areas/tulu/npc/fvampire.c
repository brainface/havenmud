// fire immune enemy for tulu area.

#include <lib.h>
#include <damage_types.h>
#include "../tulu.h"
inherit LIB_NPC;
inherit LIB_FEAR;

void eventSpecial();

static void create() {
  mapping inventory;

  ::create();
  SetKeyName("fire vampire");
  SetId( ({ "fire vampire", "vampire" }) );
  SetAdjectives( ({ "fire", }) );
  SetShort("a fire vampire");
  SetLong("A vaguely humanoid figure of blue flame whisps about through the "
    "air, frost forming on the cavern walls around it. From what might be a "
    "mouth a hungry tongue of flame flicks about, snakelike. It seems to almost "
    "be feeding on heat around it. "
  );
  SetGender("female");
  SetRace("elemental");
  SetClass("rogue");
  SetLevel(250);

  SetCombatAction(15, (: eventSpecial :) );
  SetEncounter(100);
  SetFearLength(5);
  SetFearType("eldritch fear");
  //SetInventory(inventory);
  SetMeleeAttackString("flaming tongue");
  SetMeleeDamageType(HEAT);
  SetResistance(ALL_ELEMENTS, "high");
  SetResistance(ALL_PHYSICAL|HEAT, "immune");
  SetResistance(WATER|COLD, "weakness");
  SetResistLevel(80);
}

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();

  if (!target) return;
  send_messages("lance",
      "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name with a tongue of flame!",
      who, target, environment() );
  target->eventPrint("You feel exhausted, as if the very lifeforce is draining out of you!");
  target->AddStamina(-random(100)+25);
  target->eventReceiveDamage(who, COLD, random(500), 0, target->GetRandomLimb("torso") );
  return;
}

void init() {
  npc::init();
  fear::init();
}

