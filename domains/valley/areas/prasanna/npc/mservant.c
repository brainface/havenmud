#include <lib.h>
#include "prasanna.h"
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("male servant");
   SetId( ({ "male servant" }) );
   SetAdjectives( ({ "male" }) );
   SetShort("a male servant");
   SetLong(" This man is a servant of the al-Ishraq household. "
           "Wearing a leather vest and pants, his every motion is "
           "full of a mechanical, almost drugged grace.");
   
   SetGender("male");
   SetRace("human");
   SetClass("enchanter");
   SetLevel(20);
   SetMorality(15);
   SetFriends( ({ "maeralin","servant girl" }) );
   SetCurrency("imperials",150);
   SetSpellBook( ([ 
   		"ice ball" : 100,
   		"shock"    : 100,
      "aura"     : 100,
      ]) );
   SetAction(1, ({ "The servant glances around." }) ); 
   SetCombatAction(65, ({ 
   		"!cast ice ball",
   		"!cast shock", 
      "!cast aura" })); 
   SetInventory( ([ 
      PR_OBJ +  "/sandals" : "wear sandals" ,
      ]) );
}

