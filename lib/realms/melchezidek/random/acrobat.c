#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../parva.h"

inherit LIB_LEADER;
 
static void create() {
  leader::create();
  SetKeyName("Moonboy");
  SetProperty("parvanoleave", 1);
  SetRace("human");
  SetClass("acrobat");
  SetLevel(60);
  SetGender("male");
  SetShort("Moonboy the Motley Merrymaker");
  SetId( ({ "moonboy","acrobat","merrymaker", "fool" }) );
  SetLong("Moonboy is a tall and skinny individual. His face is painted black"
          " with a silver crescent moon painted on the right side, no doubt"
          " a way to identify him. His small body is wreathed in taut and"
          " tone muscles indicating that he is very athletic and probably"
          " more than able to defend himself should the need arise. He"
          " is known throughout Parva and the greater Havenwood area as"
          " a fine jester and master acrobat.");
  SetAction(5, ({
    "!emote does a backflip.",
    "!snicker",
    "!speak Who-de-who and what-de-what for why-oh-why are you looking at my butt?",
    "!emote somersaults around the area.",
    "!yell Dum de dum dum dun, I want to have some fun",
    "!speak Ho-te-ho-ho your face looks like the old Quasimoto",
    "!speak Acrobatics and general tom-foolery are my game, talk to me if you want to play",
    }) );
  SetCombatAction(50, ({
    "!disorient",
    "!disarm",
    "!emote rolls away from a blow.",
    }) );
  SetTown("Parva");
  SetMorality(0);
  SetPlayerTitles( ([
      "newbie"   : "the Foolish Apprentice",
      "mortal"   : "the Silly Adventurer",
      "hm"       : "the Master of Motley",
      "legend"   : "the Fool of Parva",
      "avatar"   : "the Jester",
      "ranger"   : "the Farseeing Scout of the Havenwood Forest";
     ]) );
  SetFreeEquip( ([
     STD_OBJ "baton" : 1,
     ]) );
  SetInventory( ([
     PARVA_OBJ "fool_sceptre" : "wield sceptre",
     ]) );
  SetCurrency("shrydes", 50000);
  }
