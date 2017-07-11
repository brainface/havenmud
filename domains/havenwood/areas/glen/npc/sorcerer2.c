/* This file was updated on 01/15/99
*  by Haun for mud-upkeep purposes.
*  
*  Fixed by Gaby 08/27/99
*  Added evokation as a skill so he 
*  could cast his spells.
*/
#include <lib.h>
#include "path.h"
inherit LIB_SENTIENT;
static void create() {
  sentient::create();
  SetKeyName("sorcerer");
  SetId( ({"ancient sorcerer","ancient gelfling sorcerer",
    "gelfling sorcerer","gelfling","sorcerer"}) );
  SetShort("an ancient gelfling sorcerer");
  SetLong("Standing just a little over three feet tall, the ancient "
    "gelfling seems of little physical strength;  But the glow of "
    "wisdom in his eyes betrays a much stronger power, a power that "
    "can overwhelm most mortals of Kailie.  Though his clothes hang "
    "poorly on his body, one senses there is much more to him than "
    "meets the eye.");
  
  SetGender("male");
  SetRace("gelfling");
  SetClass("enchanter");
  SetLevel(random(14)+60);
  SetMorality(random(300)+400);
  SetCurrency("imperials",random(50)+50);
  SetInventory( ([
    GLEN + "/wpn/darkstaff" : "wield staff",
    GLEN + "/arm/darkrobe" : "wear robe",
  	]) );
  SetSpellBook( ([ 
    "bolt"            : 100,
    "fireball"        : 100,
    "chain lightning" : 100,
    "mesmer barrier"  : 100,
		]) );
  SetAction(20,({
    "!cast mesmer barrier",
    "!smile wisely",
    "!speak i know much of the magics of this world",
    "!speak strength is measured in more than muscle",
    "The sorcerer pages through an ornate book.",
  }) );
  SetCombatAction(65,({
    "!cast mesmer barrier",
    "!cast chain lightning",
    "!cast fireball",
    "!cast bolt",
  	}) );
}
