/*  a black abashai */
#include <lib.h>
#include <damage_types.h>
#include "../planes.h"
inherit LIB_NPC;
inherit LIB_FEAR;
void eventSpecial();

static void create() {
  mapping inventory = ([]);
  npc::create();
  SetKeyName("black abashai");
  SetShort("a black abashai");
  SetId( ({ "abashai", "devil" }) );
  SetAdjectives( ({ "black" }) );
  SetRace("devil");
  AddLimb("tail", "torso", 4);
  AddLimb("left wing", "torso", 4);
  AddLimb("right wing", "torso", 4);
  SetClass("fighter");
  SetLevel(60);
  SetResistLevel(12);
  SetFearType("devil fear");
  SetFearLength(10);
  SetGender("male");
  // give random weapons
  switch(random(2)) {
    case 0:
      inventory = ([
        PLANE_OBJ "bone_mace" : "wield mace in right hand",
        PLANE_OBJ "scale_shield" : "wear shield on left hand",
      ]);
    break;
    case 1:
      inventory = ([
        PLANE_OBJ "claw_black_abashai" : 2
      ]);
      SetFirstCommands( ({ "wield hands" }) );
      break;
  }
  // give armour
  inventory[PLANE_OBJ "hide_leggings"] = "wear leggings on right leg and left leg";
  inventory[PLANE_OBJ "hide_armour"] = "wear armour on torso and right arm and left arm";
  // actually include stuff in inventory.
  SetInventory(inventory);
  SetLong("An abashai is a fearsome devil which looks vaguely "
          "like a lizard except for his powerful wings. The black "
          "variety are the weakest, but should not be underestimated.");
  SetMeleeAttackString("claws");
  SetMeleeDamageType(SLASH);
  SetCombatAction(15, (: eventSpecial :) );
  SetMorality(-200);
}

void init() {
  fear::init();
  npc::init();
}

void eventSpecial() {
  switch (random(2)) {
    case 0:
      if (!GetLimb("tail")) return;
      send_messages("swipe",
        "$agent_name%^RED%^BOLD%^ $agent_verb%^RESET%^ $target_name "
        "viciously with $agent_possessive tail.",
        this_object(), GetCurrentEnemy(), environment());
      GetCurrentEnemy()->eventReceiveDamage(this_object(),
        PIERCE, random(80), 0);
      GetCurrentEnemy()->AddPoison(10);
      return;
    default:
      return;
  }
}
