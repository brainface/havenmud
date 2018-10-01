#include <lib.h>    
inherit LIB_ITEM;                                  

static void create() {
  ::create();
  SetKeyName("eyedrops");
  SetShort("soothing eyedrops");
  SetId( ({ "eyedrops" }) );
  SetAdjectives( ({"soothing" }) );
  SetLong("An eyedropper, full of soothing eyedrops. \"Stop the squints!\" is the very dubious marketing message inscribed around it.");
  SetMass(10);
  SetValue(10);
}
