#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetRace("human");
  SetClass("merchant");
  SetLevel(45);
  SetTown("Gurov");
  SetBaseLanguage("Gurovian");
  SetKeyName("alexi Romanov");
  SetShort("Alexi Romanov, a Wealthy Merchant");
  SetGender("male");
  SetId( ({ "alexi", "romanov", "merchant" }) );
  SetAdjectives( ({ "alexi", "wealthy" }) );
  
  SetMorality(200);
  SetLong(
    "Alexi Romanov is an extremely wealthy man, and a man of some important "
    "in the Principality. He runs the greatest shipping concern in the north "
    "and can be counted on to know all opportunities to make money."
    );
  SetLimit(1);
  SetFreeEquipment( ([
    STD_OBJ "digging/shovel" : 1,
    STD_FISH "pole"          : 1,
    ]) );
  SetPlayerTitles( ([
    "newbie" : "the Serf",
    "mortal" : "the Peasant",
    "hm"     : "the Kulak",
    "legend" : "the Master of the Soil",
    "avatar" : "the Merchant Prince",
    ]) );
  SetAction(5, ({
    "!speak Did you want me to teach you to be a farmer?",
    "!speak Did you want me to teach you how to fish?",
    "!speak Ask me and I'll show you the ways of merchants!",
  }) );
}
