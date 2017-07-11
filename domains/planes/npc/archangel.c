/*  A pit fiend */
#include <lib.h>
#include <size.h>
#include "../planes.h"
#include <damage_types.h>
inherit LIB_NPC;
inherit LIB_FEAR;

void eventSpecial();

static void create() {
  npc::create();
  SetKeyName("arch-angel"); 
  SetId( ({ "archangel", "angel" }) );
  SetAdjectives( ({ "arch", "divine", }) );
  SetGender("male");
  SetShort("a divine arch-angel");
  SetLong(
    "This creature of the Upper Planes is an arch-angel. His powerful frame "
    "is perfectly structured to strike terror into the hearts of evil around "
    "the universe."
    );
  SetRace("devil", "angel");
  AddLimb("left wing", "torso", 2);
  AddLimb("right wing", "torso", 2);
  SetMorality(3000);
  SetClass("cavalier");
  SetClass("priest");
  SetReligion("Kylin");
  SetSkill("multi-weapon", 1, 1);
  SetLevel(200);
  SetFearType("Divine Terror");
  SetResistLevel(50);
  SetFearLength(20);
  SetCombatAction(3, (: eventSpecial :) );
  SetAction(5, ({
      "!emote looks around for something to destroy in Holy Judgement.",
       }) );
  SetInventory( ([
    PLANE_OBJ "holy_avenger" : "wield avenger",
    PLANE_OBJ "divine_armour" : "wear armour",
    ]) );
  SetSpellBook( ([
    "superior wall of force" : 100,
    "hand of judgement"      : 100,
    "desert banishment"      : 100,
    ]) );
  SetFirstCommands( ({
    "cast superior wall of force",
    "cast superior wall of force",
    "cast superior wall of force",
  }) );
}

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();
  
  if (!target) return;
  switch(random(5)) {
    case 0:
      eventForce("cast hand of judgement on " + target->GetKeyName());
      break;
    case 1:
      eventForce("cast desert banishment on " + target->GetKeyName());
      break;
    case 2:
      eventForce("cast superior wall of force");
      break;
    default:
      send_messages( ({ "raise", "call" }),
        "$agent_name $agent_verb his arms to the sky and $agent_verb down %^BOLD%^WHITE%^divine justice%^RESET%^ on $target_name!",
        who, target, environment());
      target->eventReceiveDamage(who, SHOCK|MAGIC, GetHealthPoints(), 0, target->GetTorso());
      break;
    }
}

void init() {
  npc::init();
  fear::init();
}

int CheckResistFear(object who, int level, string type) {
  if (who->GetMorality() >750) {
    who->eventPrint("Being of good morality, you are not afraid of the ArchAngel.");
    return 0;
  }
  return ::CheckResistFear(who, level, type);
}