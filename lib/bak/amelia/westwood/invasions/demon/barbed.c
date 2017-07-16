/*  A barbed devil */
#include <lib.h>
#include <damage_types.h>
inherit LIB_INVADER;
inherit LIB_FEAR;
int eventTail();

static void create() {
  invader::create();
  SetKeyName("barbed devil");
  SetMorality(-200);
  SetCurrency("imperials", random(800));
  SetShort("a barbed devil");
  SetId( ({ "devil" }) );
  SetAdjectives( ({ "barbed" }) );
  SetRace("devil");
  SetClass("valkyr");
  SetLevel(20);
  SetFearType("devil fear");
  SetResistLevel(18);
  SetFearLength(8);
  SetGender("male");
  SetLong("This is a barbed devil, a fiery evil looking creature with "
          "wicked spiked hands and a long, evil looking tail.");
  AddLimb("tail", "torso", 2);
  SetCombatAction(5, (: eventTail :) );
  SetFriends( ({"barbed devil","bane devil","black abashai",
    "lemure","maralith","pit fiend"}) );
  SetAction(50, ({ "!go west","!go east","!go north","!go south",
    "!go northeast","!go northwest","!go southeast","!go southwest",
  }) );
}

void init() {
   invader::init();
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
