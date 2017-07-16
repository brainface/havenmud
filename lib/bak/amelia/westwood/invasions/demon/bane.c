/*  A Bane Devil */
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
inherit LIB_INVADER;
inherit LIB_FEAR;
int eventThing();

static void create() {
  invader::create();
  SetKeyName("bane devil");
  SetShort("a bane devil");
  SetId( ({ "devil" }) );
  SetAdjectives( ({ "bane" }) );
  SetLong("This bane devil is a short and stocky creature with pure "
          "evil written on his face. His horrible hooked tail "
          "looks sharp and viscious.");
  SetGender("male");
  SetRace("devil");
  AddLimb("tail", "torso", 2);
  SetClass("valkyr");
  SetLevel(25);
  SetFearType("devil fear");
  SetResistLevel(24);
  SetFearLength(10);
  SetCombatAction(6, (: eventThing :) );
  SetEncounter(101);
  SetMorality(-200);
  SetFriends( ({"barbed devil","bane devil","black abashai",
    "lemure","maralith","pit fiend"}) );
  SetAction(50, ({ "!go west","!go east","!go north","!go south",
    "!go northeast","!go northwest","!go southeast","!go southwest",
  }) );
}

int eventThing() {
     if (1) {
     send_messages("attack",
        "$agent_name $agent_verb%^RED%^BOLD%^ $target_name "
        "%^RESET%^with "
        "$agent_possessive tail!", this_object(), 
         GetCurrentEnemy(), environment() );
      GetCurrentEnemy()->eventReceiveDamage(this_object(), COLD,
              (random(50) + 50), 0); 
    return 1;
        }
  return 0;
  }

void init() {
  fear::init();
  invader::init();
  }
