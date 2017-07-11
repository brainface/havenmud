#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../haven.h"

inherit LIB_LEADER;
 
static void create() {
  leader::create();
  SetKeyName("Cheveille");
  SetRace("elf");
  SetClass("acrobat");
  SetLevel(60);
  SetGender("female");
  SetShort("Cheveille the Acrobat");
  SetId( ({ "cheveille","acrobat" }) );
  SetLong("Cheveille is a short and thin woman with small"
          " but extremely toned muscles. She hovers rather than"
          " stands with a grace and poise that borders on the"
          " supernatural. Her renown as a great acrobat is"
          " a reputation that is not misplaced by any means.");
  SetAction(5, ({
    "!emote does a backflip.",
    "!emote stretches her limbs.",
    "!speak If one wished to learn the arts of the acrobat, one need speak only to me",
    "!speak I can teach you the ways of the acrobat.",
    "!speak To the acrobat, the world is but a place to play.",
    }) );
  SetCombatAction(50, ({
    "!disorient",
    "!disarm",
    }) );
  SetTown("Haven");
  SetMorality(1000);
  SetPlayerTitles( ([
        "newbie"  : "the Novice Tumbler",
        "mortal"  : "the Nimble",
        "hm"      : "the Advanced Aerialist",
        "legend"  : "the Adept Acrobat", 
        "avatar"  : "the Acclaimed Acrobat",
        "ranger"  : "the Scout of the South",
     ]) );
  SetFreeEquip( ([
     STD_POLE "baton" : 1,
     ]) );
  SetInventory( ([
     STD_POLE "staff" : "wield staff",
     ]) );
  SetCurrency("imperials", 5000);
  }
