#include <lib.h>
#include <domains.h>
inherit LIB_SENTIENT; 

static void create() {
  sentient::create();
  SetKeyName("fisher");
  SetId( ({ "fisher", "short fisher" }) );
  SetShort("a short fisher");
  SetLong(
    "This short man seems to have a certain air about him "
    "that suggests that he is a fisherman. His hair is "
    "unkempt and his eyes are sad."
  );
  SetGender("male");
  SetRace("human");
  SetClass("fighter");
  SetLevel(5);
  SetAction(1, ({
          "!say what a gentle breeze.",
          "!sit down",
          "!fish with pole",
          "!emote peers into the water.",
          }) );
  SetInventory( ([
         AVERATH_OBJ + "waders" : "wear waders",
         AVERATH_OBJ + "fishing_knife" : "wield knife",
         AVERATH_OBJ + "pole" : 1,
           ]) );
  }     
