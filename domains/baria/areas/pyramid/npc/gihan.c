/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: gihan.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("Gihan");
  SetShort("Gihan the ruins examiner");
  SetId( ({ "gihan","gihan the ruins examiner","human","examiner",
            "ruins examiner"
       }) );
  SetRace("human");
  SetGender("male");
  SetMorality(50);
  SetClass("enchanter");
  SetLevel(18 + random(5));
  SetLong("Gihan is a dedicated student of the history of Kailie. "
          "He's specialized in examining ancient buildings and "
          "objects "
          "inside of it. If he had to face any danger while doing "
          "his work, he might be able to defend himself. Thanks to "
          "his studies, he has learned a few magic skills."
         );
  RemoveLanguage("Enlan");
  SetLanguage("Eltherian",100,1);  
  SetSpellBook( ([
        "shock"    : 100,
        "capsule"  : 100,
        "ice ball" : 100,
        ]) );
  SetAction(8, ({
                 "!say How interesting...",
                 "!say This place is very old, but still in great "
                 "shape",
                 "!say I found these pieces of armour recently",
                 "!say There must be a secret that the pillar hides...",
                 "!say I hope not to get lost on the way home",
                 "!say Petroglyphics and the GodsWar...",
                 "!say The inscription on the stela reads: \"Profane "
                 "the sacred light and thou shall meet thy doom.\"",
                 "!say The inscription on the stela reads: \"Profane "
                 "the sacred light and thou shall meet thy doom.\"",
                 "!say The inscription on the stela reads: \"Profane "
                 "the sacred light and thou shall meet thy doom.\"",
           }) );
  SetCombatAction(35, ({
           "!cast shock",
           "!cast capsule",
           "!cast ice ball"
                 }) );
  SetCurrency("crystals", 30 + random(11));
  SetInventory( ([
    P_OBJ "/dragon_armlet" : "wear armlet on right hand and right arm",
    P_OBJ + "/dragon_sandals" : "wear sandals",
    P_OBJ + "/mag_glass" : "wield magnifying glass",
    P_OBJ + "/white_robe" : "wear robe",
    ]) );
}
