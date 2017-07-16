#include <lib.h>
#include "prasanna.h"
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("royal guard");
   SetId( ({ "guard" }) );
   SetAdjectives( ({ "royal" }) );
   SetShort("a royal guard");
   SetLong("This is a royal guard, his sole purpose in life being "
           "to protect the life of his mistress. His appearance is "
           "cold and intimidating. ");
   
   SetGender("male");
   SetRace("human");
   SetClass("cavalier");
   SetLevel(random(30)+30);
   SetMorality(15);
   SetCurrency("imperials",200);
   SetAction(5, ({ 
   		"The guard watches you closely.",
      "The guard shifts his weight and glances around."
      }) ); 
   SetFriends( ({ "maeralin","royal guard" }) );
   SetInventory( ([ 
   		PR_OBJ +  "/khopesh" : "wield khopesh",
      PR_OBJ +  "/sandals" : "wear sandals" ]) );
}

