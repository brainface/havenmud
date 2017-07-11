#include <lib.h>
#include "../parva.h"
inherit LIB_SENTIENT;

static void create() {
   sentient::create();
   SetTown("Parva");
   SetProperty("parvanoleave",1);
   SetKeyName("citizen");
   SetShort("a citizen of Parva");
   SetId( ({ "citizen","of parva" }) );
   SetAdjectives( ({ "citizen","parvan" }) );
   SetLong("The Parvan citizen is a shady, unwashed character.  "
           "Something about the citizen suggests that "
           "Parva is not the nicest place in the world.");
   SetRace("human");
   SetClass("rogue");
   SetLevel(random(3)+1);
   if(random(2)) { SetGender("male"); }
   else  { SetGender("female"); }
   SetAction(5, ({ "!emote slinks around.","!emote curses.",
                   "!emote looks on edge.","!emote frowns." }) );
   SetCombatAction(20, ({ "!say Help!!!","!shout Help!",
                          "!say Get away from me!","!say Get out "
                          "of Parva!" }) );
   SetInventory( ([
                    PARVA_OBJ + "/knife_cit" : "wield knife in right hand",
                    PARVA_OBJ + "/pants_cit" : "wear pants",
                    PARVA_OBJ + "/shirt_cit" : "wear shirt",
                    PARVA_OBJ + "/boots_cit" : "wear boots",
               ]) );
   SetWander(15);
   SetCurrency("oros", 5);
   SetFriends( ({"citizen","pecunia","minkin","drunk","arpachshad"}) );
   SetMorality(-300);
   SetLimit(4);
}
