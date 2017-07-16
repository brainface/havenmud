//Rogue-Bard trainer for Malv     //
//by Alessandra  10/2004          //

#include <lib.h>
#include <std.h>
#include "../mal.h"
inherit LIB_TRAINER;

static void create() {
  ::create();

  SetKeyName("lorsay");
  SetId( ({ "lorsay", "barmaid" }) );
  SetShort("Lorsay, the skulking barmaid");
  SetLong(
     "Lorsay is a waifish looking half dark-elf woman. She helps Paige "
     "out by running drinks to patrons, but is better known for her great skill "
     "in certain trades. Perhaps if asked, she might take you aside for a "
     "discrete lesson or two."
     );
  SetRace("half-elf");
  SetGender("female");
  SetClass("rogue");
  SetTown("Malveillant");
  SetMorality(-250);
  SetLevel(40);
  SetCurrency("roni", random(350)+20);
  
  SetAdjectives( ({
     "skulking",
     }) );
  SetInventory( ([
     MAL_OBJ + "/weapons/etched_dagger" : "wield dagger", 
     ]) );
  SetTrainingSkills( ({
 		 "knife combat",
     "lockpicking",
  	 "stealing",
  	 "stealth",
     "bargaining",
  	 }) );
  	  
}
