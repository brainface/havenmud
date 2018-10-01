#include <lib.h>
#include <size.h>

inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("lightning bug");
    SetProperty("minaretnoleave", 1);
    SetId( "bug" );          
    SetAdjectives( ({ "lightning" }) );
    SetShort("a lightning bug");      
    SetLong(
      "This tiny little bug radiates light."
    );                                                             
    if(random(2)) { SetGender("male"); 
      }  else  { SetGender("female"); }
    SetRace("insect");
    SetSize(SIZE_TINY);
    SetClass("animal");
    SetLevel(1);
  SetMorality(-500);
    SetRadiantLight(5);
  }
