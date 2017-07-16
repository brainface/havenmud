//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include <domains.h>
#include "../dalnairn.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("seagull");
  SetId( ({ "seagull" }) );
  SetAdjectives( ({ "green" }) );
  SetShort("a white seagull");
  SetLong(
    "The heavy body of this gull is covered in soft white plumage. "
    "It has a tapered yellow beak. Its tail feathers are forked and "
    "its wings have black tips. ",
    );
  SetRace("bird");
  SetClass("animal");
  if(random(2)) { 
    SetGender("male");
    } else  {
    SetGender("female");
  }
  SetLevel(3);
  SetAction(2 + random(2), ({
    "!attack first turtle",
  }) );
  SetCorpseItems( ([
    DAL_OBJ + "white_feather" : 1,
  ]) );
  SetProperty("dalnoleave", 1);
  SetWander(5 + random(3) + random(3));
  SetFriends( ({
    "seagull",
  }) );
  SetLimit(10);
}
