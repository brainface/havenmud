#include <lib.h>
#include <domains.h>
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Reggy the Swift");
  SetShort("a thin shadowy man");
  SetId( ({ "man", "reggy", "swift", "rogue" }) );
  SetAdjectives( ({ "reggy", "the", "thin", "shadowy" }) );
  SetGender("male");
  SetRace("human");
  SetRestrictRace(1);
  SetClass("rogue");
  SetLevel(25);
  SetLong("Reggy the Swift is a respectable looking fellow of "
          "thin build and shadowy demeanor. He has the appearance "
          "of someone who could \"describe rogues\" if he was "
          "asked, and also someone who would know how to "
          "\"join rogues\".");
  SetMorality(-500);
  SetInventory( ([
    AVERATH_OBJ "wbknife" : "wield knife",
    ]) );
  SetFreeEquipment( ([
     AVERATH_OBJ "newbie_knife" : 1,
     ]) );
  SetPlayerTitles( ([
    "newbie" : "the Ruffian",
    "mortal" : "the Skulker of Averath",
    "high mortal" : "the Finder of Lost Things",
    "legend" : "the Shadow Stalker",
    "avatar" : "the Feared Outlaw",
    "demigod" : "the Swift-Fingered Bringer of Ruin",
  ]) );
  SetTown("Averath");
  SetProperty("no bump", 1);
}
