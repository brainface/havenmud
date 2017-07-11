 /*
  * boot vendor
  * Balishae 1997
  * Fixed and repaired, Sept 19th 2004
  * by Duuk
  */
#include <lib.h>
#include <std.h>
#include "../path.h"

inherit LIB_BARKEEP;

static void DoHawk();

static void create() {
  ::create();
  SetKeyName("dwarven shoe vendor");
  SetId( ({ "vendor", "merchant", "dwarf", "glim_wander" }) );
  SetAdjectives( ({ "shoe", "dwarf", "dwarven",}) );
  SetShort("a dwarven shoe vendor");
  SetLong(
    "This dwarf wanders the Great Hall of Glimmerdin, looking "
    "for people in need of boots for their feet. He has a friendly "
    "appearance and a smile that can light up a room."
  );
  SetRace("dwarf");
  SetClass("merchant");
  SetSkill("blunt combat", 1, 1);
  SetLevel(20);
  SetMorality(100);
  SetGender("male");
  SetInventory( ([
    STD_CLOTHING "shirt/tunic" : "wear tunic",
    G_OBJ "m_boots" : "wear boots",
    ]) );
  SetLocalCurrency("nuggets");
  SetMenuItems( ([
    "boots" : G_OBJ "boots",
    "black boots" : G_OBJ "black_boots",
    ]) );
  SetAction(3, (: DoHawk :) );
  SetWander(10);
  SetLimit(1);
}


static void DoHawk() {
  string m_mesg, m_volume;
  
  switch(random(5)) {
        case 0 :
          m_mesg = "Fine boots!  Get your fine boots here!";
          break;
        case 1 :
          m_mesg = "Genuine Leather boots!";
          break;
        case 2 :
          m_mesg = "Fine Leather boots!  Only eight nuggets a pair.";
          break;
        case 3 :
          m_mesg = "Special!  Today only!  Get both boots at once!";
          break;
        case 4 :
          m_mesg = "You won't find a better deal than eight nuggets for "
                   "these fine quality boots";
          break;
  }
  if(random(4)) m_volume = "speak ";
    else m_volume = "shout ";
  eventForce(m_volume + " " + m_mesg);
}

