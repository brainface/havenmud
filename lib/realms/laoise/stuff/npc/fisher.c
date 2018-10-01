#include <lib.h>
#include <domains.h>
inherit LIB_SENTIENT; 

static void create() {
  sentient::create();
  SetKeyName("fisher");
  SetGender("male");
  SetLong("This short man seems to have a certain air about him "
          "that suggests that he is a fisherman. His hair is "
          "unkempt and his eyes are sad.");
  SetShort("a short fisher");
  SetRace("human");
  SetClass("fighter");
  SetLevel(5);
  SetAction(1, ({
          "!say what a gentle breeze.",
          "!sit down",
          "!fish with willow",
          "!emote peers into the water.",
          }) );
  SetInventory( ([
         AVERATH_OBJ + "waders" : "wear waders",
         AVERATH_OBJ + "fishing_knife" : "wield knife",
         AVERATH_OBJ + "pole" : "fish with pole",
           ]) );
  SetId( ({ "fisher", "short fisher" }) );
  }     
