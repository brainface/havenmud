//Selket@Haven
//2006
#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include <damage_types.h>
#include "../ungkh.h"

inherit LIB_NPC;
inherit LIB_FEAR;

void eventBite(object target);

static void create() {
  npc::create();
  SetKeyName("Flame");
  SetId( ({ "dragon", "drake" }) );
  SetShort("Flame, a pet drake");
  SetAdjectives( ({ "pet" }) );
  SetLong("Flame is a drake, something akin to a dragon, "
    "although much smaller in size. Her crimson scales glitter "
    "as she moves her body sinuously about the stable she "
    "calls home, and her azure eyes focus upon everything with "
    "a despairing kind of hatred, as if she has long since "
    "given up any kind of escape but still enjoys lashing out "
    "at her captors from time to time.");
  SetRace("dragon");
  SetGender("female");
  SetTown("Ungkh");
  SetClass("animal");
  SetMorality(200);
  SetSkill("pierce combat", 1, 1);
  SetSkill("slash combat", 1, 1);
  SetSkill("melee combat",  1, 1);
  SetLevel(100);
  SetLanguage("Eltherian", 100);
  SetMeleeAttackString("claws");
  SetMeleeDamageType(PIERCE);
  SetFearType("%^BOLD%^WHITE%^DRAGONFEAR%^RESET%^");
  SetFearLength(5 + random(5));
  SetResistLevel(50);
  SetEncounter(250);
  SetCurrency("skins",500 + random(5000) );
  SetResistance(MAGIC, "immune");
}

void eventEnemyDied(object who) {
  eventForce("eat corpse");
  npc::eventEnemyDied(who);
}

void init() {
  npc::init();
  fear::init();
}

void eventTailStrike(object target) {
  int damage = (GetHealthPoints()/10);
  int health = target->GetHealthPoints();
  int sp = GetStaminaPoints();

  if (sp > 100) {
    this_object()->AddStaminaPoints(-65);
    if(damage > health) {
      send_messages( ({"whip","strike"}),
        "%^RED%^Flame $agent_verb $agent_possessive tail over
$agent_possessive head and $agent_verb $target_name, impaling "
        "$target_possessive body!%^RESET%^", 
        this_object(), target, environment());
      target->eventReceiveDamage(this_object(), PIERCE, damage, 0);
      return;
    }
    else 
    {
      send_messages( ({"whip","slash"}),
        "%^RED%^Flame $agent_verb $agent_possessive tail over "
        "$agent_possessive head and $agent_verb $target_name!%^RESET%^", 
        this_object(), target, environment());
      target->eventReceiveDamage(this_object(), SLASH, damage, 0);
      return;
    }
  }
  else 
  {
    return;
  }
}

int eventDie(object killer) {
  object ogre_inv;
  if(!random(500)) {
     ogre_inv = new(DIR_INVASIONS + "/soleil_ogre/ois_inv");
    INVASION_D->eventRegisterInvasion(ogre_inv, killer);
  }
  return ::eventDie(killer);
}
