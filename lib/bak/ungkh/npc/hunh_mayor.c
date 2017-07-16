/* Ogre chieftain - Hunh
 * Ranquest@Haven
 * 02/13/99
 */
#include <lib.h>
#include "../ungkh.h"

inherit LIB_MAYOR;

static void create() {
   mayor::create();
   SetKeyName("hunh");
   SetShort("Warlord Hunh, mayor of Ungkh");
   SetId( ({ "hunh", "warlord", "mayor" }) );
   SetLong(
     "Warlord Hunh is the chieftain of Ungkh and head"
     " of the council of the skull. His nostrils are"
     " the most capacious ever seen, with large clumps"
     " of hair sticking out.");
   SetRace("ogre");
   RemoveLanguage("Shangtai");
   SetLanguage("Uruk",100,1);
   SetMorality(-100);
   SetGender("male");
   SetClass("barbarian");
   SetInventory( ([ 
     U_OBJ + "breastplate" : "wear breastplate",
     U_OBJ + "bigsword" : "wield sword",
     ]) );
   SetLevel(55);
   SetTown("Ungkh");
   SetLocalCurrency("skins");
   SetTax(20);
   SetAction(4, ({
     "!say me Hunh.",
     "!emote scratches his head.",
     "!emote crushes a flea between his fingers.",
     "!frown",
     "!say you give me money, you join Ungkh.",
     }) );
   SetCombatAction(1, ({
     "!emote roars in anger.",
     "!emote swings his sword in a vicious arc around his head.",
     "!yell guards!",
     }) );
   SetFriends( ({ "guard","elite_guard" }) );
}