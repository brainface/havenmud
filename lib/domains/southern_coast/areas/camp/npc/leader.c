#include <lib.h>
#include <daemons.h>
#include "../camp.h"
inherit LIB_NPC;
void UseWand();

static void create() {
  npc::create();
  SetKeyName("bandit leader");
  SetShort("the bandit leader");
  SetId( ({ "bandit", "leader" }) );
  SetRace("human");
  SetLong("This is the leader of the bandits.  He is wiry and seems "
         "prepared for battle.");
  SetClass("fighter");
  SetLevel(random(10)+10);
  SetGender("male");
  SetCurrency("imperials", random(300)+1);
  SetMorality(-300);
  SetInventory( ([
    CAMP_OBJ + "/longsword" : "wield longsword in right hand",
    CAMP_OBJ + "/wand" : "wield wand in left hand",
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

varargs int eventDie(object agent) {
  object bandit_inv;
  if (!random(200)) {
    bandit_inv = new(DIR_INVASIONS + "/parva_bandit/bip_inv");
  INVASION_D->eventRegisterInvasion(bandit_inv, agent);
  }
  ::eventDie(agent);
 }
