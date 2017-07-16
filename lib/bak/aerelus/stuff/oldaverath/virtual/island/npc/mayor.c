#include <lib.h>
#include <domains.h>
inherit LIB_MAYOR;

static void create() {
   ::create();
   SetTown("Averath");
   SetLocalCurrency("ducats");
   SetCurrency("ducats",450);
   SetTax(50);
   SetKeyName("Rummin");
   SetShort("Rummin, the Registrar of Averath");
   SetId( ({ "rummin","registrar","registrar of averath","mayor" }) );
   SetAdjectives( ({ "rummin","the","registrar","averath" }) );
   SetLong("Rummin's shoulder length hair hangs in a tight "
           "ponytail at the nape of his dark-skinned neck.  "
           "Keeping a pleasant contenance, his face portrays "
           "a rugged life in the forest.  A long scar marks him, "
           "running from the bridge of his nose to his right ear.");
   SetRace("human");
   SetClass("fighter");
   SetGender("male");
   SetLevel(50);
//   SetCombatAction(); I'd like to give him a combat style when we
//   have that all ready to go, or something.
   SetAction(2, ({ "!say Welcome to Averath!  I can help you with "
                   "town membership.","!say Be careful in the forest "
                   "southeast of town.  That's where I got my "
                   "scar.","!say Averath is a fine town.","!say "
                   "As the City Registrar, I keep accounts on "
                   "everyone who has ever lived in Averath.",
                    }) );
   SetMorality(450);
   SetInventory( ([
                    AVERATH_OBJ + "rumminsword" : "wield sword",
                    AVERATH_OBJ + "rummincloak" : "wear cloak",
               ]) );
   AddTalkResponse("forest","The forest is full of all sorts of "
                      "of animals.  I ran into a terrible monster "
                      "there.");
   AddTalkResponse("scar","I got this scar in the forest "
                      "southeast of town.  I go hunting there "
                      "often.  That's where I found my elk!  "
                      "But be careful!  There are dangerous "
                      "monsters in the forest.");
   AddTalkResponse("monsters","The most dangerous creature I "
                      "have ever faced in battle was a gargantuan "
                      "bear.");
   AddTalkResponse("bear","I got this scar from a bear in the "
                      "forest to the southeast.  He hides in a " 
                      "cave near the south side.");
   AddTalkResponse("elk","You see the elk hanging over the doors?  "
                      "I hunted him myself.  Found him on the edge "
                      "of the forest, barely out in the plains.  "
                      "The antlers looked so impressive I saved "
                      "the head for mounting, and the fur for a "
                      "cozy rug.");
   AddTalkResponse("averath","Averath is a beautiful town!  I am "
                      "its City Registrar.  I keep track of everyone "
                      "who has ever lived in Averath.");
}
