// mahkefel april 2011
// bad dude does bad things stay away
#include <lib.h>                     
#include <domains.h>                      
#include <std.h>                          
#include <damage_types.h>                 
#include "reaver.h"                       
inherit LIB_PIRATE;                       

void heart_beat();

static void create() {
  ::create();         
  SetRace("orc");     
  SetGender("male");  
  SetClass("necromancer");  
  SetClass("viking");       
  SetSkill("enchantment",1,1);
  SetLevel(130);              
  SetKeyName("reaver");       
  SetId( ({ "reaver","orc" }) );
  SetShort("an orcish reaver");
  SetAdjectives( ({ "orcish" }) );
  SetLong(
    "This hulking brute's chest is marred by countless profane symbols scarred "
    "into his flesh, the evidence of service under an master even crueler than "
    " himself. His marred skin stretches taught over his muscles and sinew, as "
    "if he has gone long without a fresh meal."
  );

  SetMorality(-1500);
  SetInventory( ([
    INNERSEA_ENCOUNTERS + "obj/broad_axe" : "wield axe",
    INNERSEA_ENCOUNTERS + "obj/sharkskin" : "wear my leggings",
  ]) );

  SetCaptainAggressiveness(80);
  SetCombatAction(30, ({
     "!cast ice lance",
  }) );
  SetResistance(ALL_ELEMENTS|MAGIC,"low");//cheeeeaaatting
  SetProperty("pirate","orc");
  SetShipWander(1);
  SetCurrency("orcteef", 20000);

  SetMinLevel(150);
  SetMaxLevel(500);
  SetBoarder(REAVER_DIR "reaver");
  SetTown("Karak");
  SetReligion("Saahagoth");
}


