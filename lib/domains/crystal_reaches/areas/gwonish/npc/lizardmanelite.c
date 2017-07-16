#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../path.h"

inherit LIB_NPC;

static void create()
{
  npc::create();
  SetKeyName("lizardman elite");
  SetId( ({"lizardman","guard","lizard","solemn lizardman",
           "lizard man","reptile"}) );
  SetShort("a solemn lizardman");
  SetLong("Muscles ripple along the eight foot tall lizardman's physique.");
  
  SetRace("lizardman");
  SetClass("fighter");
  SetLevel(12);
  SetGender("male");
  SetCurrency("rounds", random(10) );

  SetFriends( ({"lizardman captain","lizardman elite"}) );
  
  SetCombatAction(15,({"The lizardman flexes before he swings."}));
  SetCombatAction(7,({"!growl"}));
  
  
  AddInventory(GWONISH+"obj/shield.c", "wear shield on left hand");
  AddInventory(GWONISH+"obj/chain_vest.c","wear vest"); 
  AddInventory(GWONISH+"obj/sword.c","wield sword in right hand");  
}
int eventDie(object killer) {
  object lizard_inv;
  if(!random(200)) {
    lizard_inv = new(DIR_INVASIONS + "/jidoor_lizardmen/lmij_inv");
    INVASION_D->eventRegisterInvasion(lizard_inv, killer);
  }
return ::eventDie(killer);
}
