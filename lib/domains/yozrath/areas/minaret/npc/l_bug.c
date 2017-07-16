#include <lib.h>
#include "../minaret.h"
#include <size.h>

inherit LIB_SENTIENT;

static void create() {
  sentient::create();
    SetKeyName("bug");
    SetProperty("minaretnoleave", 1);
    SetId( "bug" );          
    SetAdjectives( ({ "lightning" }) );
    SetShort("a lightning bug");      
    SetLong(
      "This tiny little bug radiates with light "
      "as it flies around."
    );                                                             
    if(random(2)) { SetGender("male"); 
      }  else  { SetGender("female"); }
    SetRace("insect");
    SetSize(SIZE_TINY);
    SetClass("animal");
    SetLevel(1);
  SetRadiantLight(5);
    SetWander(10);
  SetLimit(25);
    SetAction(15, ({
      "!emote twinkles in the darkness.",
      "!emote blinks.",
      "!emote lands on a blade of tall grass "
      "and flutters its wings.",
      "!emote flies right by you!",
    }) );
  }
