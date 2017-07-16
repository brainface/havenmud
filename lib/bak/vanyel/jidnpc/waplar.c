//
// Waplar the bartender
// Created by Zaxan@Haven
//

#include <lib.h>
#include <std.h>
#include "../jidoor.h"

inherit LIB_BARKEEP;

static void create() {
   barkeep::create();
   SetKeyName("waplar");
   SetId( ({ "waplar", "bartender" }) );
   SetShort("Waplar the bartender");
   SetLong("This old man is sitting behind his counter constantly "
           "polishing it, acting as though he has nothing better to "
           "do.");
   SetLevel(15);
   SetRace("sprite");
   SetClass("evoker");
   SetGender("male");
   SetMorality(20);
   SetAction(5, ({ 
      "!emote polishes down his counter.",
   }) );
   SetLocalCurrency("rupies");
   SetMenuItems( ([ 
      "bread" : DIR_STD "meal/food/bhunk.c",
      "steak" : DIR_STD "meal/food/steak.c",
      "beer" : DIR_STD "meal/alcohol/beer.c",
      "milk" : DIR_STD "meal/drink/milk.c",
      "cheese" : DIR_STD "meal/food/cheese.c",
   ]) );
   SetSpellBook( ([ 
      "bolt" : 100,
      "missile" : 100,
      "terra" : 100,
   ]) );
   SetCombatAction(5, ({ 
      "!cast missile",
      "!cast bolt",
      "!cast terra",
   }) );
}
