//Illura@Haven
//May 2009
#include <lib.h>
#include "../cake.h"

inherit LIB_BARKEEP;

static void DoHawk();
static void create (){
  barkeep::create();
  string MY_NAME;
  switch(random(6)) {
  	case 0:
  	MY_NAME = "Babinka";
  	break;
  	case 1:
  	MY_NAME = "Khleba";
  	break;
  	case 2:
  	MY_NAME = "Sakharina";
  	break;
  	case 3:
  	MY_NAME = "Nechenye";
  	break;
  	case 4:
  	MY_NAME = "Sladastna";
  	break;
  	case 5:
  	MY_NAME = "Testa";
  	break;
  }
  SetKeyName(MY_NAME);
  SetShort(MY_NAME + " the Cake Vendor");
  SetId( ({ "vendor", "merchant", MY_NAME }) );
  SetAdjectives( ({ "cake" }) );
  SetRace("human");
  SetGender("female");
  SetBaseLanguage("Gurovian");
  SetTown("Gurov");
  SetClass("merchant");
  SetLevel(20);
  SetLong(
    MY_NAME + " is a portly young lady with an infectuous grin "
    "and a penchant for making tasty desserts. She wanders "
    "the Gurovian countryside selling her wares."
  );
  SetLocalCurrency("rubles");
  SetMenuItems( ([
    "raspberry cake" : CAKE_OBJ "cake1",
    "strudel" : CAKE_OBJ "strudel",
    "lunaberry cake" : CAKE_OBJ "cake2",
    "carrot cake" : CAKE_OBJ "cake3",
    ]) );
  SetAction(3, (: DoHawk :) );
  SetLimit(1);
  SetMorality(100);
}

void DoHawk() {
  string m_mesg, m_volume;

  switch(random(4)) {
    case 0 :
      m_mesg = "Cakes for sale! Tasty cakes!";
      break;
    case 1 :
      m_mesg = "Come try the best cakes in Gurov!";
      break;
    case 2 :
      m_mesg = "Everybody likes my cakes! Buy one!";
      break;
    case 3 :
      m_mesg = "Cakes! Magically delicious, perhaps?";
      break;
  }
  if(random(4)) m_volume = "speak";
  else m_volume = "shout ";
  eventForce(m_volume + " " + m_mesg);
}
