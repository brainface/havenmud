#include <lib.h>
#include <daemons.h>
#include "../camp.h"
inherit LIB_NPC;
void UseWand();

static void create() {
  npc::create();
  SetKeyName("ronin commander");
  SetShort("the ronin commander");
  SetId( ({ "ronin", "commander" }) );
  SetAdjectives( ({ "ronin" }) );
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Tai");
  SetClass("fighter");
  SetLong("This is the commander of the ronin.  He is muscular and seems "
          "well prepared for battle.");
  SetLevel(random(10)+10);
  SetCurrency("koken", random(600)+10);
  SetMorality(-300);
  SetInventory( ([
    CAMP_OBJ + "katana" : "wield katana in right hand",
    CAMP_OBJ + "wand" : "wield wand in left hand",
       ]) );
  SetCombatAction(4, (: UseWand :) );
  }

void UseWand() {
    object victim;
    string vicname;
   victim = GetCurrentEnemy();
   vicname = victim->GetKeyName();
  if (victim->GetParalyzed()) return;
   eventForce("use wand to paralyze " + vicname);
  return;
   }

/*
varargs int eventDie(object agent) {
  object bandit_inv;
  if (!random(200)) {
    bandit_inv = new(DIR_INVASIONS + "parva_bandit/bip_inv");
  INVASION_D->eventRegisterInvasion(bandit_inv, agent);
  }
  ::eventDie(agent);
 }
*/
