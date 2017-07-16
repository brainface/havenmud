// Treasure by Urien@Haven 011913
// Player request Bill 
// arkelite gem, lets make this random colors....
//   This gem has excellent targeting. Hence 
//   the use in the short, id, and adjective.

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>

inherit LIB_ITEM;
 
static void create(){
  string theColor;
 
  ::create();
  SetKeyName("arkelite gem");
  switch(random(7))
  {
    case 0: theColor = "red"; break;
    case 1: theColor = "brown"; break;
    case 2: theColor = "grey"; break;
    case 3: theColor = "black"; break;
    case 4: theColor = "green"; break;
    case 5: theColor = "white"; break;
    case 6: theColor = "blue"; break;
  }
  
  SetShort("a sparkling " + theColor + " arkelite gem");
  SetId( ({ "gem", "arkelite", ""+theColor+ " gem" }) );
  SetAdjectives( ({ "sparkling", "arkelite", ""+theColor+"" }) );
  SetLong("This particular gem is a clear shaped "
          "dodecahedron. It reflects light almost "
          "like a low quality glass. It has a pure "
          "quality with a no inclusion however, "
          "this would prove more useful to entertain "
          "in a board game. The " +theColor+ " color "
          "it displays is just a soft hue similar "
          "to bargain stained glass.");
  SetMass(2);
  SetValue(10);
  SetDamagePoints(40);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM);
  SetProperty("magic","This arkelite gem magically changes color.");
  SetProperty("history","This is the favored gem to use in any "
                        "strategic game or for betting. Held "
                        "highly by many as a perfect dice token. ");
}

