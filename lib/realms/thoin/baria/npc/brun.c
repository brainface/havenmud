/* warrior leader
    kyla 11-97
   Edited by Gaby
   Changed SetLong

*/
#include <lib.h>
#include "../jungle.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Brun");
  SetShort("Brun the Hunter of the Jungle");
  SetId( ({ "Brun", "hunter", "man"}) );
  SetAdjectives( ({"tall", "handsome", "strong"}) );
  SetLong("Brun is one of the most important people in the town. "
          "As the hunter he is, he is the one in charge of bringing "
          "food and natural materials to the village. He is very "
          "strong, so a wise person would stay out of his way.  He "
          "can teach one how to follow the ways of the valkyr, which is "
          "part of the path to being a true hunter."
         );
  SetRace("human");
  SetClass("valkyr");
  SetLevel(65);
  SetGender("male");
  SetMorality(50);
  SetTown("Baria");
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetInventory( ([
     BARIA_OBJ + "scale_knife" : "wield knife",
     BARIA_OBJ + "vest" : "wear vest",
     BARIA_OBJ + "loincloth" : "wear loincloth",
  ]) );
  SetFreeEquip( ([
                  "/std/weapon/blunt/mace" : 1,
                  BARIA_OBJ + "vest" : 1,
              ]) );
  SetPlayerTitles( ([
                     "newbie" : "the Student of the Hunting Arts",
                     "mortal" : "the Hunter of the Barian Jungle",
                     "hm" : "the Stone Fisted Hunter",
                     "legend" : "the Predator of Beasts",
                     "avatar" : "the Stalker of the Dark Jungle",
                  ]) );
}
