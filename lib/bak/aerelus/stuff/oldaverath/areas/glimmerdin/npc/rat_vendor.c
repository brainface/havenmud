 /*
  * Rat on a stick vendor
  * Balishae 1997
  */
#include <lib.h>
#include "../glim.h"

inherit LIB_BARKEEP;

static void DoHawk();

static void create() {
  ::create();
  SetKeyName("merchant");
  SetId( ({"vendor","merchant","dwarf", "town_wander"}) );
  SetAdjectives( ({"rat","rat on a stick","dwarf"}) );
  SetShort("a rat vendor");
  SetLong("This heavy-set dwarf seems to be happily wandering the town, "
          "selling his wares in the best way he knows how.");
  SetLimit(4);
  SetLevel(20);
  SetWander(5);
  SetRace("dwarf");
  SetClass("merchant");
  SetGender("male");
  AddInventory(G_OBJ + "l_tunic", "wear tunic"); 
  SetLanguage("Averath", 100);        // Set Languages so that vendor can speak
  SetLanguage("Eltherian", 100);      // to any who wish to deal with him.
  SetAction(15, (: DoHawk :) );
  AddMenuItem("rat", G_OBJ + "rat_meal");
  SetLocalCurrency("glims");
  SetTown("Glistendin");
}

static void DoHawk() {
  string Language, m_mesg, m_volume;
  
  Language = GetLanguages()[random(sizeof(GetLanguages()))];
  switch(random(5)) {
    	case 0 :
 	      m_mesg = "Get your hot Rat-On-A-Stick!";
 	      break;
 	    case 1 :
 	      m_mesg = "Rat-On-A-Stick! Yummy AND Delicious!";
 	      break;
  	  case 2 :
 	      m_mesg = "Rat-On-A-Stick! Tastes Great!";
 	      break;
 	    case 3 :
 	      m_mesg = "Rat-On-A-Stick! Get it here!";
 	      break;
 	    case 4 :
 	      m_mesg = "World famous RAT ON A STICK, right here!";
 	      break;
     }
  if(random(3)) m_volume = "speak ";
     else m_volume = "yell ";  
  eventForce(m_volume + "in " + lower_case(Language) + " " + m_mesg);

}


