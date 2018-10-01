#include <lib.h>
#include "prasanna.h"
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("servant girl");
   SetId( ({ "servant girl" }) );
   SetAdjectives( ({ "woman","simple","servant" }) );
   SetShort("a servant girl");
   SetRace("human");
   SetGender("female");
   SetClass("necromancer");
   SetLevel(20);
   SetMorality(15);
   SetLong("This woman is a servant of the al-Ishraq house. "
           "Her slender form is carried lightly on graceful, light "
           "feet. She seems to dance through the area when she moves. "
           "Her face is touched with pixie wing beauty, and her black "
           "hair cascades down her back. Her movements are "
           "somnambulistic, and she smiles vaguely and with glassy "
           "eyes.");
   SetCurrency("imperials",150);
   SetSpellBook( ([ "dark flame" : 100, 
                    "wards of protection" : 100 ]) );
   SetAction(1, ({ "The servant girl brushes her hair out of her "
                   "face." }) ); 
   SetCombatAction(45, ({ "!cast wards of protection", 
                          "!cast dark flame" })); 
   SetInventory( ([ PR_OBJ +  "/sandals" : "wear sandals" ,
                ]) );
}
