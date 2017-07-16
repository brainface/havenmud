/*  A barbed devil */
#include <lib.h>
#include <damage_types.h>
#include "../planes.h"
inherit LIB_NPC;
inherit LIB_FEAR;
int eventTail();

static void create() {
  npc::create();
  SetKeyName("barbed devil");
  SetMorality(-200);
  SetShort("a barbed devil");
  SetId( ({ "devil" }) );
  SetAdjectives( ({ "barbed" }) );
  SetRace("devil");
  SetClass("rogue");
  SetLevel(120);
  SetCurrency("imperials", random(800)+1);
  SetFearType("devil fear");
  SetResistLevel(18);
  SetFearLength(8);
  SetGender("male");
  SetLong("This is a barbed devil, a fiery evil looking creature with "
          "wicked spiked hands and a long, evil looking tail.");
  AddLimb("tail", "torso", 2);
  SetCombatAction(5, (: eventTail :) );
  SetInventory( ([
    PLANE_OBJ + "spike_barbed" : 2,
    PLANE_OBJ + "hide_leggings" : "wear leggings on right leg and left leg",
    PLANE_OBJ + "hide_armour" : "wear armour on torso and right arm and left arm",
  ]) );
  SetFirstCommands(({"wield spikes"}));
}

void init() {
  npc::init();
  fear::init();
}

int eventTail() {
  object target = GetCurrentEnemy();
  object who = this_object();
  if (GetLimb("tail")) {
    send_messages("swipe",
      "$agent_name $agent_verb%^RED%^BOLD%^ evilly%^RESET%^ with "
      "$agent_possessive tail!", who, target, environment() );
    target->eventReceiveDamage(who, PIERCE, random(200));
    return 1;
  }
  return 0;
}

