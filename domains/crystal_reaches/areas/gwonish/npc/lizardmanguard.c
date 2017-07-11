#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../path.h"

inherit LIB_NPC;

static void create()
{
  npc::create();
  SetKeyName("lizardman");
  SetId( ({"lizardman","guard","lizard","alert lizardman","reptile"}) );
  SetShort("an alert lizardman");
  SetLong("The seven foot tall lizardman stands around looking alert.");
  
  SetRace("lizardman");
  SetClass("fighter");
  SetLevel(9);
  SetGender("male");
  
  SetCombatAction(15,({"The lizardman calmly eyes your defenses."}));
  SetCombatAction(7,({"!growl"}));
  
  SetFriends( ({"lizardman","elite lizardman"}) );
  
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
