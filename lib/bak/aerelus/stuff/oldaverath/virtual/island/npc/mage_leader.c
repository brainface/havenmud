#include <lib.h>
#include <domains.h>

inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("brakesh");
  SetId( ({ "brakesh" }) );
  SetShort("Brakesh the Wise");
  SetLong("Brakesh the Wise is a short, strong looking man whose leathery "
          "face appears always stern. He might know a thing or two about "
          "magic.");
  SetLevel(35);
  SetRace("human");
  SetClass("enchanter");
  SetGender("male");
  SetTown("Averath");
  SetMorality(100);
  SetProperty("no bump", 1);
  SetTaughtSpheres( ({ "magical", "magical evokation", "magical enchantment" }) );
  SetFreeEquipment( ([ AVERATH_OBJ + "white_robe" : 1 ]) );
  SetPlayerTitles( ([
    "newbie"      : "the Eager Learner of Magic",
    "mortal"      : "the Practicioner of the Magical Arts",
    "high mortal" : "the Highly Accomplished Magician",
    "legend"      : "the Renowned Speaker of Spells",
    "avatar"      : "the Great Commander of the Magicks",
    "demigod"     : "of the Highest Order, Master of Reality"
  ]) );
}
