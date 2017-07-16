#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../path.h"

inherit LIB_NPC;

static void create()
{
  npc::create();
  SetKeyName("lizardman captain");
  SetId( ({"lizardman","captain","lizard","huge lizardman",
           "lizard man","reptile"}) );
  SetShort("a huge lizardman");
  SetLong("This lizardman is built on a scale that dwarfs other lizardmen.");
  
  SetRace("lizardman");
  SetClass("fighter");
  SetLevel(45);
  SetGender("male");
  SetMorality(-800);

  SetCombatAction(15,({"The lizardman looks disdainfully at you as he "
                       "prepares to decapitate you."}));
  SetCombatAction(7,({"!growl"}));

  SetFriends( ({"lizardman elite"}) );
  

  AddInventory(GWONISH+"obj/chain_vest", "wear vest");
  AddInventory(GWONISH+"obj/captainscloak", "wear cloak");
    AddInventory(GWONISH+"obj/captainsword", "wield sword");
}
int eventDie(object killer) {
  object lizard_inv;
  if(!random(200)) {
    lizard_inv = new(DIR_INVASIONS + "/jidoor_lizardmen/lmij_inv");
    INVASION_D->eventRegisterInvasion(lizard_inv, killer);
  }
return ::eventDie(killer);
}
