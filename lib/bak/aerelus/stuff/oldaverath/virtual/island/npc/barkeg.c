#include <lib.h>
#include <domains.h>

inherit LIB_BARKEEP;

static void create() {
    barkeep::create();
   SetKeyName("barkeg");
  SetId( ({ "barkeg", "owner", "barkeep", "bartender", "keeper" }) );
    SetShort("Barkeg Beetlebottum, Barkeep of the Local Inn");
    SetLevel(12);
    SetLong("Barkeg is a short, squat ugly animal of a man."
            " Small, beady eyes stare out of his sunken, sweat-slicked skull, "
            "barely visible behind his huge, meaty cheeks, which easily contain "
        "more flesh than any normal human's thigh. Thick, meaty paws "
             "grope randomly at passersby, and often contain thick containers "
             "of venomous alcohol. A huge tarp-like apron adorns his massively "
             "obese body, barely concealing his disgusting bulk.");
    SetGender("male");
    SetMorality(-100);
    SetRace("human");
    SetClass("merchant");
    AddCurrency("ducats", random(40));
    SetSkill("bargaining", 150);
    SetProperty("no bump", 1);
SetLocalCurrency("ducats");
    SetMenuItems(([ 
      "goat's milk" : AVERATH_OBJ + "milk",
      "stew" : AVERATH_OBJ + "stew",
      "bread roll" : AVERATH_OBJ + "bread",
        "beer" : AVERATH_OBJ + "beer",
]));
}
