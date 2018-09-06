/* A josh killing shuggoth */

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include "../tulu.h"

inherit LIB_NPC;
inherit LIB_FEAR;

void eventSpecial();
void eventExhale();
void eventSlam();
void eventWhisper();

static void create() {
  npc::create();
  SetKeyName("shuggoth");
  SetId( ({ "mass", "shuggoth" }) );
  SetAdjectives( ({ "luminescent", "shapeless" }) );
  SetShort("a luminescent shapeless mass");
  SetLong(
    "A quivering, formless mass rolls over the ground. "
    "Large, unblinking eyes cover the mass like spider eggs. "
    "Gaping maws full of ragged bleach-white and yellow teeth open and "
    "close violently along its grasping psuedopods."
  );
  SetGender("female");
  SetRace("shuggoth",1);
  SetLanguage("Archaic",100,1);

  AddLimb("ooze", 0, 1);

  AddLimb("thin pseudopod","ooze",2);
  AddLimb("toothy maw","thin pseudopod",1,({A_WEAPON}));

  AddLimb("scaly pseudopod","ooze",2);
  AddLimb("gibbering maw","scaly pseudopod",1,({A_WEAPON}));

  AddLimb("fat pseudopod","ooze",2);
  AddLimb("yawning maw","fat pseudopod",1,({A_WEAPON}));

  AddLimb("gleaming pseudopod","ooze",2);
  AddLimb("screaming maw","gleaming pseudopod",1,({A_WEAPON}));

  AddLimb("twitching pseudopod","ooze",2);
  AddLimb("blinking eyestalk","twitching pseudopod",1);

  AddLimb("furry pseudopod","ooze",2);
  AddLimb("staring eyestalk","furry pseudopod",1);

  SetClass("fighter");
  SetLevel(220);
  SetStat("strength",100);
  SetStat("durability",100);
  SetStat("agility",100);
  SetStat("coordination",100);

  SetStat("luck",10);
  SetStat("wisdom",10);
  SetStat("charisma",10);
  SetStat("intelligence",10);

  SetFearLength(15);
  SetFearType("formless terror");

  SetAction(5, ({
    "!emote glides along the ground noiselessly.",
    "!yell Tekeli-li! Tekeli-li!",
     "!say Tekeli-li!",
    "!yell Tekeli-li! Tekeli-li!",
    "!emote gnaws on your foot.",
    "!emote bubbles fouly.",
    "!emote clings to the walls.",
  }) );
  SetCombatAction(30, (: eventSpecial :) );
  SetEncounter(125);
  SetFirstCommands( ({"wield teeth"}) );
  SetInventory( ([TULU_OBJ "shug_tooth" : 4]));
  SetResistance(ALL_DAMAGE, "immune");
  SetResistance(MAGIC, "high");
  SetResistance(HEAT|COLD|ACID|SHOCK|SOUND, "weakness");
  SetResistLevel(100);
  SetDie("The shapeless mass decoheres and spills over the floor, now "
    "nothing but inert goo.");
  SetNoCorpse(1);
}

void eventSpecial() {
  switch(random(3)) {
    case 0: eventExhale();
            break;
    case 1: eventSlam();
            break;
    case 2: eventWhisper();
            break;
  }
}

void eventExhale() {
  object who = this_object();
  object target = GetCurrentEnemy();
  send_messages("exhale",
    "$agent_name%^BLACK%^BOLD%^ $agent_verb%^RESET%^ a noxious "
    "cloud at $target_name.", who, target, environment() );
  target->eventReceiveDamage(who, ACID, random(750), 0,
    target->GetRandomLimb("head") );
  return;
}

void eventSlam() {
  object who = this_object();
  object target = GetCurrentEnemy();

  send_messages("slam",
    "$agent_name%^MAGENTA%^BOLD%^ $agent_verb%^RESET%^ into "
    "$target_name "
    "with a huge psuedopod!", who, target, environment() );
  target->eventReceiveDamage(who, BLUNT, random(500), 0,
    target->GetRandomLimb("head") );
  if(!random(4)) target->eventCollapse();
  return;

}

void eventWhisper() {
  object who = this_object();
  object target = GetCurrentEnemy();

  send_messages("whisper",
    "$agent_possessive_noun many maws%^MAGENTA%^ whisper%^RESET%^ "
    "horrible chants that errode your sanity!",
     who, target, environment() );
  target->AddDrunk(random(20));
  target->AddDaze(random(50));
  return;
}

void init() {
  npc::init();
  fear::init();
}



