// Treasure by Urien@Haven 011413
// Player request Bill 
// Widow Xarthinel - There is two types of xarthinel class
//                   gem this one is the lesser grade.
//                   Lower value and different purities.

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>

inherit LIB_ITEM;

static void create() {
  string theColor;
  string theGrade;
 
  ::create();
  
  SetKeyName("widow gem");
  
  switch(random(7))
  {
    case 0: theColor = "red"; break;
    case 1: theColor = "crimson"; break;
    case 2: theColor = "maroon"; break;
    case 3: theColor = "burgundy"; break;
    case 4: theColor = "cherry"; break;
    case 5: theColor = "scarlet"; break;
    case 6: theColor = "salmon"; break;
  }
  
  switch(random(4))
  {
    case 0: theGrade = "super fine"; break;
    case 1: theGrade = "very good"; break;
    case 2: theGrade = "fair"; break;
    case 3: theGrade = "poor"; break;
  }
  
  SetShort("a " + theGrade + " xarthinel gem");
  SetId( ({ "xarthinel", "gem", "widow" , ""+theColor+" gem"  }) );
  SetAdjectives( ({ "glowing", "widow", ""+theColor+"" }) );
  SetLong("This gem has a "+theGrade+" inclusion but contains "
          "the most pure "+theColor+" colour despite its quality. "
          "This is due to it being the widow xarthinel, "
          "which is less than pure. The widow gem is only "
          "identifiable due to it not being a solid black "
          "color, which is much more valuable. It is a favored treat "
          "to those who would collect such things.");
  SetMass(30);
  SetValue(40);
  SetDamagePoints(600);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM|VT_TREASURE);
}

