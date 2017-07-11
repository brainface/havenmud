#include <lib.h>
#include "../rome.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Phariel");
  SetShort("Phariel the retired bard");
  SetId( ({ "phariel", "bard" }) );
  SetAdjectives( ({ "retired" }) );
  SetRace("human");
  SetTown("Sanctum");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetClass("bard");
  SetGender("female");
  SetLevel(22);
  SetLong("Phariel is an old women but in her youth she was known as the voice "
          "of the legion for her bravery and singing skills. Her knowledge "
          "of music is surpassed by none. Though she is "
          "long retired she still teaches anyone who would ask the ways "
          "of the bard.");
 SetPlayerTitles( ([
      "newbie" : "the Novice Tubicine",
      "mortal" : "the Signifer of the Cohors",
      "hm"     : "the Cornicine of the Cataphractii",
      "legend" : "the Virtuoso of the Sagitarii",
      "avatar" : "Praefectus $N the Aulos of the Praetoriani",
    ]) );
  SetFreeEquip( ([
    "/std/instruments/fife" : 1,
    "/std/weapon/knife/small_knife" : 1,
     ]) );
  SetSongBook( ([
    "banshee scream" : 100,
    ]) );
  SetInventory( ([
    ROME_OBJ "stola_rich" : "wear stola",
  ]) );
  }

