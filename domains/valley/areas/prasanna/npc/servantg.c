#include <lib.h>
#include "prasanna.h"
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("servant girl");
   SetId( ({ "servant girl" }) );
   SetAdjectives( ({ "woman","simple","servant" }) );
   SetShort("a servant girl");
   SetLong("This woman is a servant of the al-Ishraq house. She wears "
           "a simple, sleeveless robe. Her movements are "
           "somnambulistic, and she smiles vaguely and with glassy "
           "eyes... ");
   
   SetGender("female");
   SetRace("human");
   SetClass("necromancer");
   SetLevel(20);
   SetMorality(15);
   SetCurrency("imperials",150);
   SetSpellBook( ([ 
   		"acid blast"  : 100, 
      "capsule"     : 100,
      "acid splash" : 100,
      ]) );
   SetAction(1, ({ "The servant girl brushes her hair." }) ); 
   SetCombatAction(75, ({ 
   		"!cast capsule", 
      "!cast acid blast",
      "!cast acid splash", 
      })); 
   SetInventory( ([ 
   		PR_OBJ +  "/sandals" : "wear sandals" ,
      ]) );
}
