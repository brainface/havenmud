#include <lib.h>
#include "../../parva.h"
inherit LIB_NPC;

static void create() {
   npc::create();
   SetTown("Parva");
   SetKeyName("citizen");
   SetProperty("parvanoleave",1);
   SetShort("a hurt citizen");
   SetId( ({ "citizen" }) );
   SetAdjectives( ({ "hurt" }) );
   SetLong("Dirty, straggly hair frames this hurt citizen's "
           "bruised face.  He looks like he is in a good deal "
           "of pain.  However, he is smiling slightly.");
   SetRace("human");
   SetGender("male");
   SetClass("rogue");
   SetLevel(2);
   AddHealthPoints(-((1/2) * GetHealthPoints()));
   SetAction(5, ({ "!groan","!whimper","!say I hurt!",
                   "!emote 's eyes search for Abijah.",
                   "!say Abijah, come heal me!","!emote smiles "
                   "weakly.", }) );
   SetCombatAction(20,({ "!say Abijah!  Save me!","!say Someone "
                         "help me!","!say No, no!","!say Get "
                         "out of here!","!say Help me!","!shout "
                         "Help!!" }) );
   SetInventory( ([
                    "/std/clothing/pant/drab_med" : "wear pants",
                    "/std/clothing/shirt" : "wear shirt",
               ]) );
}
