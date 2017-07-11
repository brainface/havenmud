 /*
  * Pouch vendor
  * Balishae 1997
  */
#include <lib.h>
#include "../path.h"
inherit LIB_BARKEEP;

static void DoHawk();

static void create() {
  ::create();
  SetKeyName("dwarven pouch vendor");
  SetId( ({ "vendor", "dwarf", "glim_wander"}) );
  SetAdjectives( ({"pouch", "dwarf", "dwarven", }) );
  SetShort("a dwarven pouch vendor");
  SetLong("Almost delicate looking, for a dwarf that is, the merchant is "
          "selling fine leather pouches.");
  SetWander(6);
  SetRace("dwarf");
  SetClass("merchant");
  SetLevel(20);
  SetGender("male");
  SetMenuItems( ([
    "pouch"        : G_OBJ "pouch",
    "medium pouch" : G_OBJ "med_pouch",
    ]) );
  SetLocalCurrency("nuggets");
  SetAction(3, (: DoHawk :) );
  SetWander(10);
  SetLimit(1);
  SetMorality(100);
}

static void DoHawk() {
 string m_mesg, m_volume;
  
  switch(random(5)) {
  	case 0 :
   	  m_mesg = "Fine pouches, for gentlemen or ladies.";
 	    break;
  	case 1 :
   	  m_mesg = "Fine pouches, on sale cheap!.";
 	    break;
    	case 2 :
   	  m_mesg = "Crafted of the finest skins.";
   	  break;
   	case 3 :
   	  m_mesg = "Get your fine pouches here.";
 	    break;
   	case 4 :
 	    m_mesg = "Something to keep your baubles and cash in!";
 	    break;
    }
  if(random(3)) m_volume = "speak ";
    else m_volume = "shout ";
  eventForce(m_volume + m_mesg);
}

