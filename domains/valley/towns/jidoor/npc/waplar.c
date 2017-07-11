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
   SetId( ({ "waplar", "bartender","jidoor_npc" }) );
   SetShort("Waplar the bartender");
   SetLong("This hoary old sprite is hovering behind his counter constantly "
           "polishing it, acting as though he has nothing better to "
           "do.");
   SetClass("evoker");
   SetGender("male");
   SetLevel(15);
   SetRace("sprite");


   SetMorality(20);
   SetAction(5, ({
      "!emote polishes down his counter.",
      "!emote hovers lazily.",
      "!quickly mixes a drink in a blur of motion and glass.",
      "!cast capsule",
      "!emote touches a glowing hand to a beer mug, immediately frosting it."
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
      "capsule" : 100,
      "shock"   : 100,
   ]) );
   SetCombatAction(70, ({
      "!cast capsule",
      "!cast shock",
   }) );
}

