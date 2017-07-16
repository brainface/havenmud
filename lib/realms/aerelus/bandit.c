#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../camp.h"
inherit LIB_NPC;
int Fighty();

static void create() {
  npc::create();
  SetKeyName("bandit");
  SetShort("a rough looking bandit");
  SetLong("This is a large rough looking bandit.  His demeanor suggests "
          "that combat is nothing new to him.");
  SetId( ({ "bandit", "rough looking bandit" }) );
  SetAdjectives( ({ "rough", "rough looking" }) );
  SetProperty("no bump", 1);
  SetClass("fighter");
  SetMorality(-200);
  SetLevel(random(2)+1);
  SetFriends( ({ "bandit" }) );
  SetGender("male");
  SetRace("human");
  SetCurrency("imperials",random(70)+1);
  SetInventory( ([
       CAMP_OBJ + "/shield" : "wear shield on right arm",
       CAMP_OBJ + "/battleaxe" : "wield battleaxe",
         ]) );
  }

int eventDie(object agent) {
  object bandit_inv;
  if(!random(1000)) {
    bandit_inv = new(DIR_INVASIONS + "/parva_bandit/bip_inv");
  INVASION_D->eventRegisterInvasion(bandit_inv, agent);
    }
  return ::eventDie(agent);
  }
