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
  SetKeyName("dwarven snack vendor");
  SetId( ({ "vendor", "merchant", "dwarf", "glim_wander" }) );
  SetAdjectives( ({ "snack", "dwarf", "dwarven",}) );
  SetShort("a dwarven snack vendor");
  SetLong(
    "This dwarf wanders the Great Hall of Glimmerdin, looking "
    "for people in need of a tasty snack. He has a friendly "
    "appearance and a smile that can light up a room."
  );
  SetRace("dwarf");
  SetClass("merchant");
  SetSkill("blunt combat", 1, 1);
  SetLevel(20);
  SetGender("male");
  SetInventory( ([
    STD_CLOTHING "shirt/tunic" : "wear tunic",
    G_OBJ "m_boots" : "wear boots",
    ]) );
  SetLocalCurrency("nuggets");
  SetMenuItems( ([
    "snacks"         : G_OBJ "rat_meal",
    "rat-on-a-stick" : G_OBJ "rat_meal",
    ]) );
  SetAction(3, (: DoHawk :) );
  SetWander(10);
  SetLimit(1);
  SetMorality(100);
}

void DoHawk() {
  string m_mesg, m_volume;
  
  switch(random(5)) {
  	case 0 :
 	  m_mesg = "Get your hot Rat-On-A-Stick!";
 	  break;
 	case 1 :
 	  m_mesg = "Rat-On-A-Stick!  Two for one today!";
 	  break;
  	case 2 :
 	  m_mesg = "Rat-On-A-Stick!  Healthy and nutritious too.";
 	  break;
 	case 3 :
 	  m_mesg = "Rat-On-A-Stick!  Two for only one nugget!";
 	  break;
 	case 4 :
 	  m_mesg = "One mithril nugget gets you two Rat-On-A-Sticks!";
 	  break;
  }
  if(random(4)) m_volume = "speak ";
  else m_volume = "shout ";
  eventForce(m_volume + " " + m_mesg);
}
