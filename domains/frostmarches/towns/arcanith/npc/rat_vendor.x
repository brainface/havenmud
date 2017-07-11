 /*
  * boot vendor
  * Balishae 1997
  * Fixed and repaired, Sept 19th 2004
  * by Duuk
  */
#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../ruins.h"

inherit LIB_BARKEEP;

static void DoHawk();

static void create() {
  ::create();
  SetKeyName("dwarven snack vendor");
  SetId( ({ "vendor", "merchant", "dwarf", "glim_wander" }) );
  SetAdjectives( ({ "snack", "dwarf", "dwarven",}) );
  SetShort("a dwarven snack vendor");
  SetLong(
    "This dwarf wanders the ruins of Arcanith looking "
    "for people in need of a tasty snack. He has a friendly "
    "appearance and a smile that can light up a room. "
    "His treats have made him a permanent resident of Arcanith."
  );
  SetRace("dwarf");
  SetBaseLanguage("Koblich");
  SetClass("merchant");
  SetSkill("melee combat", 1, 1);
  SetLevel(20);
  SetGender("male");
  SetInventory( ([
    STD_CLOTHING "shirt/tunic" : "wear tunic",
    ]) );
  SetLocalCurrency("senones");
  SetMenuItems( ([
    "snacks"            : CRYSTAL_REACHES_TOWNS "glimmerdin/obj/" "rat_meal",
    "rat-on-a-stick" : CRYSTAL_REACHES_TOWNS "glimmerdin/obj/" "rat_meal",
    "sammich"         : OBJ "/sammich",
    ]) );
  SetAction(3, (: DoHawk :) );
  SetLimit(1);
}

void DoHawk() {
  string m_mesg, m_volume;
  
  switch(random(8)) {
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
 	  m_mesg = "Rat-On-A-Stick!  Two for only a few senones!";
 	  break;
 	case 4 :
 	  m_mesg = "For a few senones gets you two Rat-On-A-Sticks!";
 	  break;
                          case 5 :
                             m_mesg = "Fresh roasted spider sammiches!  Cheap!";
                             break;
                          case 6 :
                             m_mesg = "Only the best spider salad sammich ever made! For only a few senones!";
                             break;
                          case 7 :
                             m_mesg = "Blue cheese and Mayo bring out the sophisticated taste of the spider! Get them while they crunch!";
                             break;
  }
  if(random(4)) m_volume = "speak ";
  else m_volume = "shout ";
  eventForce(m_volume + " " + m_mesg);
}
