// Coded by Zeratul 11-26-99
#include <lib.h>
#include "../lake.h"
inherit LIB_SENTIENT;

int type = random(2);
string CheckSetShort();

static void create() {
  sentient::create();
  SetKeyName("cricket");
  SetId( ({"small cricket","noisy cricket","cricket","bug"}) );
  SetShort("a small cricket");
  SetLong("This little green cricket chirps noisly. It hops along as it "
     "looks for something to eat. "
     );
  SetLimit(6);
  SetGender( (random(2) ? "male" : "female") );
  SetRace("insect");
  
  SetClass("animal");
  SetLevel(1);
  SetAction(5,({
     "!emote makes a strange noise.",
     }) );
  SetWander( 5 + random(2), ({ "go west", "go north","go east","go south", 
     "go northwest","go northeast","go southwest","go southeast",}), 1 );
  SetDie("A cricket goes silent as it dies.");

  if (type == 0) { /* CRICKET NPC TYPE: MALE CRICKET*/
  SetAdjectives( ({ "cricket","male","" }) );
  SetId( ({ "cricket","male cricket","bug","little cricket","small cricket" }) );
  }

  else if(type == 1) { /* CRICKET NPC TYPE: FEMALE CRICKET*/
  SetAdjectives( ({ "cricket","female","" }) );
  SetId( ({ "cricket","female cricket","bug","little cricket","small cricket" }) );
  }
}
