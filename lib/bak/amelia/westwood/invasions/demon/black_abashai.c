/*  a black abashai */
#include <lib.h>
#include <damage_types.h>
inherit LIB_INVADER;
inherit LIB_FEAR;
void eventSpecial();

static void create() {
  invader::create();
  SetKeyName("black abashai");
  SetShort("a black abashai");
  SetId( ({ "abashai", "devil" }) );
  SetAdjectives( ({ "black" }) );
  SetRace("devil");
  AddLimb("tail", "torso", 4);
  AddLimb("left wing", "torso", 4);
  AddLimb("right wing", "torso", 4);
  SetClass("fighter");
  SetLevel(12);
  SetResistLevel(12);
  SetFearType("devil fear");
  SetFearLength(10);
  SetGender("male");
  SetLong("An abashai is a fearsome devil which looks vaguely "
          "like a lizard except for his powerful wings. The black "
          "variety are the weakest, but should not be underestimated.");
  SetMeleeAttackString("claws");
  SetMeleeDamageType(SLASH);
  SetCombatAction(15, (: eventSpecial :) );
  SetFriends( ({"barbed devil","bane devil","black abashai",
    "lemure","maralith","pit fiend"}) );
  SetAction(50, ({ "!go west","!go east","!go north","!go south",
    "!go northeast","!go northwest","!go southeast","!go southwest",
  }) );
  }

void init() {
  fear::init();
  invader::init();
  }

void eventSpecial() {
  switch (random(2)) {
     case 0:
   if (!GetLimb("tail")) return;
   send_messages("swipe",
       "$agent_name%^RED%^BOLD%^ $agent_verb%^RESET%^ $target_name "
       "visciously with $agent_possessive tail.",
       this_object(), GetCurrentEnemy(), environment());
  GetCurrentEnemy()->eventReceiveDamage(this_object(), 
        PIERCE, random(80), 0);
  GetCurrentEnemy()->AddPoison(10);
  return;
  default:
     return;
   }
 }
