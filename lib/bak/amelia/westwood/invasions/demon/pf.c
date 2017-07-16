/*  A pit fiend */
#include <lib.h>
#include <damage_types.h>
inherit LIB_INVADER;
inherit LIB_FEAR;

void eventSpecial();

static void create() {
  invader::create();
  SetKeyName("pit fiend");
  SetGender("male");
  SetShort("a pit fiend");
  SetRace("devil");
  SetId( ({ "fiend", "devil" }) );
  SetAdjectives( ({ "pit" }) );
  AddLimb("left wing", "torso", 2);
  AddLimb("right wing", "torso", 2);
  SetClass("valkyr");
  SetLevel(40);
  SetFearType("devil fear");
  SetResistLevel(35);
  SetFearLength(20);
  SetCombatAction(3, (: eventSpecial :) );
  SetAction(5, ({
      "!emote looks around maniacally.",
       }) );
  SetEncounter(100);
  SetLong("A pit fiend is a towering giant of a devil with a reddish "
          "body and huge wings jutting from his torso. His large claws "
          "and huge teeth set this creature apart as a viscious killer.");
  SetMeleeAttackString("claws");
  SetMeleeDamageType(SLASH);
  SetFriends( ({"barbed devil","bane devil","black abashai",
    "lemure","maralith","pit fiend"}) );
  SetAction(50, ({ "!go west","!go east","!go north","!go south",
    "!go northeast","!go northwest","!go southeast","!go southwest",
  }) );
  }

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();

  send_messages("tear",
     "$agent_name%^RED%^ $agent_verb%^RESET%^ at $target_name "
     "with $agent_possessive teeth.", who, target, environment() );
   target->eventReceiveDamage(who, SLASH, random(400), 0, 
              target->GetRandomLimb("head") );
     return;
  }

void init() {
  invader::init();
  fear::init();
  }
