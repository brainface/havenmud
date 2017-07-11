#include <lib.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Timmy Longdorf");
  SetShort("Timmy Longdorf, a retired merchant");
  SetId( ({ "timmy", "timmy longdorf", "longdorf", "merchant" }) );
  SetRace("human");
  SetTown("Haven");
  RemoveLanguage("Enlan");
  SetLanguage("Eltherian", 100, 1);
  SetClass("merchant");
  SetGender("male");
  SetLevel(22);
  SetMorality(100);
  SetLong("Timmy Longdorf is an older man now, but one with years \n"
          "of experience in the trades of war.  He was known in his \n"
          "day as a warrior merchant that could fix any weapon that \n"
          "man could think of.  His tirades were known far and wide.");
  SetPlayerTitles( ([
      "newbie"  : "the fortune seeker",
      "mortal"  : "the Merchant",
      "hm"      : "the Lord Merchant",
      "avatar"  : "the Merchant Prince",
      "fighter" : "the Highway Traveller",
      "rogue"   : "the Highway Traveller",
      ]) );
  SetFreeEquip( ([
    "/std/obj/fishing/pole" : 1,
    "/std/weapon/knife/small_knife" : 1,
     ]) );
  }
