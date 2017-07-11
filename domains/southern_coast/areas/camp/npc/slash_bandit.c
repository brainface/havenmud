#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include <std.h>
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
  SetRace("human");
  SetClass("fighter");
  SetMorality(-200);
  SetLevel(random(2)+1);
  SetFriends( ({ "bandit" }) );
  SetGender("male");
  
  SetCurrency("imperials",random(70)+50);
  SetInventory( ([
       CAMP_OBJ + "/shield" : "wear shield on right arm",
       STD_WEAPON + "slash/shortsword" : "wield shortsword",
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
