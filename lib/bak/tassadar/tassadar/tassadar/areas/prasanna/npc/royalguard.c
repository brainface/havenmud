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
           "to protect the life of his mistress. He has long slender"
           "arms that ripple with muscle. His chest bulges through his "
           "shirt, and his neck is tapered to his shoulders. His "
           "appearance is cold and intimidating. ");
   SetLevel(random(40)+30);
   SetMorality(15);
   SetGender("male");
   SetRace("human");
   SetClass("cavalier");
   SetCurrency("imperials",200);
   SetAction(5, ({ "The guard watches you closely.",
                   "The guard shifts his weight and glances around."}) ); 
   SetFriends( ({ "maeralin","royal guard" }) );
   SetInventory( ([ PR_OBJ +  "/khopesh" : "wield khopesh",
                    PR_OBJ +  "/sandals" : "wear sandals" ]) );
}
