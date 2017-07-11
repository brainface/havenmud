/*  A campfire */
#include <lib.h>
inherit LIB_BURN;

static void create() {
  ::create();
  SetKeyName("campfire");
  SetId( ({ "fire", "campfire" }) );
  SetShort("a crackling campfire");
  SetAdjectives( ({ "crackling" }) );
  SetLong("This is a warm crackling campfire.");
  SetRadiantLight(25);
  SetPreventGet("You cannot take a fire!");
  SetFlickerString("flickers slightly");
  SetMaxFuel(10000000);
  SetRadiantLight(30);
  SetHeat(20);  
  }
