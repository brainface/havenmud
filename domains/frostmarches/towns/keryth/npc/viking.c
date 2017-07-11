
#include <lib.h>
#include <std.h>
#include "../keryth.h"

inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("haggar");
  SetId( ({ "haggar", "viking" }) );
  SetShort("Haggar the Horrible");
  SetLong(
    "Haggar is a fierce warrior of a goden that spends his days watching "
    "the construction of new ships for the goden fleet. His eyes are still "
    "sharp and his demeanor harsh, but for those wanting to know how to "
    "plunder and be a scourge of the sea, he is the one to talk to."
    );
  SetRace("goden");
  SetClass("viking");
  SetTown("Keryth");
  SetGender("male");
  SetLevel(25);
  SetCurrency("senones", 5 + random(250));

  SetMorality(-300);
  SetFreeEquip( ([
     STD_SLASH "shortsword" : 1,
     STD_HACK  "hand-axe"   : 1,
    ]) );
  SetPlayerTitles( ([
    "newbie" : "the Viking Deckhand",
    "mortal" : "the Northern Raider",
    //"hm"     : "Captain $N the Viking Raider",
    "hm" : "the Old Sea Cat",
    "legend" : "Captain $N the Legendary Scourge of the Northern Sea",
    "avatar" : "Captain $N the Ransacker of Cities and Bane of Shipping",
     "necromancer" : "the Reaving Wraith on the North Wind",
    ]) );
}

