// updated lib chapel 2/june/2017 torak@haven

#include <lib.h>
#include "../rome.h"
inherit LIB_CHAPEL;

static void create() {
  ::create();
  SetShort("inside the Kylin Temple");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetExits( ([
    "out" : ROME_ROOM "rd12",
//    "north" : ROME_ROOM "cemetery",  
//does not jive with actual mapping and can be entered from grove 
    ]) );
  SetInventory( ([
    ROME_NPC "dalahalus" : 1,
    ROME_NPC "quelthon" : 1,
    ]) );
  SetSmell( ([
    "default" : "The temple smells of candles and incense.",
    ]) );
  SetListen( ([
    "default" : "Somewhere, acolytes chant with deep reverence.",
    ]) );
  SetLong("Marble stonework and gold inlays portray the glory of the "
          "Kylin religion. Favored by the Empire, the Kylin Temple is "
          "wealthy beyond the dreams of most religions. Around the "
          "temple are finely crafted wooden tables bearing the great "
          "weight of incense braziers. Statues of men and women holding "
          "various scales and balances line the walls in an effort to "
          "display the Order and Balance of the world.");
  SetReligion("Kylin");
  SetItems( ([
    ({ "brazier", "braziers" }) : "The brass braziers contain bits of "
         "finely smelling incense that burn slowly due to small candles "
         "beneath them.",
    ({ "candle", "candles" }) : "These small candles burn beneath the "
         "braziers, filling the air with incense.",
    ({ "statue", "statues" }) : "The statues depict men and women holding "
         "scales and balances, obviously showing Order and Balance.",
    ({ "scale", "scales", "balance", "balances" }) : 
         "The scales and balances are very easily displayed as two equal "
         "cups seperated by a lever and rope.",
    ({ "stonework" }) : "The marble stonework is finely inlaid with "
         "various artistic images of Kylin glory.",
    ({ "table", "tables" }) : "The heavy wooden tables exist mainly "
         "to hold up the braziers.",
    ]) );
}
