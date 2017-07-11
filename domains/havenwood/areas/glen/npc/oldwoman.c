/* This file was updated on 01/15/99
* by Haun for mud-upkeep purposes.
*/
#include <lib.h>
#include "path.h"
inherit LIB_SENTIENT;
static void create() {
  sentient::create();
  SetKeyName("old gelfling woman");
  SetShort("an old gelfling woman");
  SetLong("The old woman is very grey and wrinkled.  Her hair is a deep "
          "silver and her eyes steel blue.  There is something very "
          "odd about the way she carries herself.  She seems to be "
          "quite a bit paranoid when approached.");
  SetId( ({ "gelfling", "old gelfling woman","gelfling woman",
            "woman","old woman" }) );
  SetRace("gelfling");
  SetClass("rogue");
  SetLevel(random(3)+8);
  SetGender("female");
	SetMorality(random(75)+130);
  SetCurrency("imperials",random(20)+60);
  SetInventory( ([
                   GLEN + "/arm/oldamulet" : "wear amulet"
              ]) );
  SetAction(15, ({ "The old woman looks into her kettle.",
                   "The woman cackles wildly.",
                   "!speak stop staring at me!",
                   "The old woman looks around fearfully.",
                   "The old woman tightly clutches at her amulet.",
                   "!speak evil be gone!"}));
}


/* Approved by Duuktsaryth on Wed Sep 24 13:11:03 1997. */
