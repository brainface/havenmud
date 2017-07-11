#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../path.h"
#define RIGHT + " in right hand"

inherit LIB_NPC;

static void create()
{
  npc::create();
  SetKeyName("lizardman");
  SetId( ({"lizardman","lizard","lizard man","reptile"}) );
  SetShort("a large lizardman");
  SetLong("This green scale covered humanoid is two meters of pure "
          "predator with a bad attitude.");
  
  SetRace("lizardman");
  SetClass("fighter");
  SetSkill("projectile combat",1,2);
  SetLevel(5 + random(5));
  
  if(random(5))
    SetGender("male");
  else
    SetGender("female");
  SetMorality(random(500)-500);
  
    
  SetAction(7,( { "The lizardman cleans it's teeth with its sharp claws."} ));
  SetAction(7,( { "A low rumble echoes forth from the reptiles stomach."} ));
  SetAction(7,( { "A hiss whispers between the lizardman's teeth."} ));
  
  SetCombatAction(15,({"The lizardman hisses in rage!"}));
  SetCombatAction(7,({"!growl"}));
  
  
  if(!random(5))
    AddInventory(GWONISH+"obj/shield.c","wear shield on left hand");
  if(!random(5))
    AddInventory(GWONISH+"obj/chain_vest.c","wear vest"); 
  switch (random(5))
  {
  case 0:
      AddInventory(GWONISH+"obj/spear.c","wield spear"RIGHT);
      break;
    case 1:
      AddInventory(GWONISH+"obj/trident.c","wield trident"RIGHT);
      break;
    default:
      AddInventory(GWONISH+"obj/sword.c","wield sword"RIGHT);
      break;
  }
  
}

int eventDie(object killer) {
  object lizard_inv;
  if(!random(200)) {
    lizard_inv = new(DIR_INVASIONS + "/jidoor_lizardmen/lmij_inv");
    INVASION_D->eventRegisterInvasion(lizard_inv, killer);
  }
return ::eventDie(killer);
}
