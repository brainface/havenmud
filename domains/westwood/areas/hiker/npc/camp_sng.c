#include <lib.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   switch(random(2)) {
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   SetKeyName("singing camper");
   SetShort("a singing camper");
   SetClass("bard");
   SetSkill("projectile combat",1,1);
   SetLevel(25+random(4));
   SetId( ({ "camper","singer" }) );
   SetAdjectives( ({ "singing" }) );
   SetMorality(-5+random(11));
   SetLong("The camper must love music, since " + nominative(this_object())
           + " is singing loudly.  The song is a rendition of a few "
           "old campfire songs that are often song as the flames "
           "jump up.  The camper is not merely a singer, however, but "
           "seems strong and able-bodied as well musical, with "
           "strong legs for hiking and strong arms for navigating "
           "steeper slopes.");
   switch(random(4)) {
      case 0:
      SetRace("human");
      switch(random(2)) {
         case 0:
         SetCurrency("senones",90);
         break;
         case 1:
         SetCurrency("chits",50);
         break;
      }
      break;
      case 1:
      SetRace("elf");
      SetCurrency("imperials",45);
      break;
      case 2:
      SetRace("muezzin");
      SetCurrency("cuicui",300);
      break;
      case 3:
      SetRace("dwarf");
      SetCurrency("nuggets",17);
   }
   SetAction(2, ({ 
   		"!emote changes songs.",
   		"!emote sings loudly.",
      "!emote whistles for a few verses.",
      "!emote tries to figure out the harmony for a song.",
      "!emote laughs suddenly, having forgotten to change songs.",
      "!emote starts to dance to the music.",
      "!emote blows into his bansuri, producing a flute-like sound." 
      }) );
   SetInventory( ([
      H_OBJ + "longbow" : "wield bow",
			H_OBJ + "bansuri" : 1,
      ]) );
   SetSongBook( ([
      "glory of the mage" : 100,
      "magical lullaby"   : 100,
      "staccato"          : 100,
      "aria of stone"     : 100,
			"warrior's honor"   : 100,
      ]) );
   SetCombatAction(50, ({ 
   		"!sing glory of the mage",
   		"!sing magical lullaby",
   		"!sing staccato",
      "!sing aria of stone",
      "!sing warrior's honor" 
      }) );
}