/*
 * fake energy mine for illusionists
 * Mahk 2018
 */


#include <lib.h>
#include <damage_types.h>
inherit LIB_ITEM;

int Life;
void destme();

static void create() {
  item::create();
  SetKeyName("energy mine");
  SetId( ({"mine",}) );
  SetAdjectives( ({"energy",}) );
  SetShort("an energy mine");
  SetLong(
    "This spherical object is a surging ball of magical energy. "
  );
  SetMass(0);
  SetPreventGet("A mystical force has fused the mine to the surroundings.");
  set_heart_beat(1);
  SetProperty("magic", "This is just a bundle of illusory light and noise in "
    "a crude statis field. It couldn't harm a fly.");  
  set_heart_beat(1);
  Life = 480;    
}

void heart_beat() {
  Life--;
  if (!Life) destme();
  }

void destme() {
  if (environment(this_object())) {
    message("system","An energy mine explodes harmlessly with a faint "
      "flash of light and warbly whistle.",environment(this_object()) );
    }
  eventDestruct();
}
