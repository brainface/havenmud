#include <lib.h>
#include "prasanna.h"
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("dennise");
   SetId( ({ "dennise" }) );
   SetAdjectives( ({ "princess","elven","cute" }) );
   SetShort("Dennise the Elven Princess");
   SetLong("This is Dennise, the elven princess. She appears to be "
           "a guest at the palace. A sort of aura of 'cuteness' "
           "surrounds her.");
   
   SetGender("female");
   SetRace("elf");
   SetClass("evoker");
   SetLevel(25);
   SetMorality(15);
   SetCurrency("imperials",150);
   SetSpellBook( ([ 
   		"ice ball" : 100, 
      "aura"     : 100,
      "shock"    : 100,
      ]) );
   SetAction(1, ({ 
   		"Dennise smiles cutely.",
      "Dennise summons a cloud and floats around "
      "on it looking cute." }) ); 
   SetCombatAction(45, ({ 
   		"!cast aura", 
      "!cast ice ball",
      "!cast shock",
      }) ); 
   SetInventory( ([ 
   		PR_OBJ +  "/sandals" : "wear sandals" ,
      PR_OBJ + "/slinky_dress" : "wear dress" ]) );
}

