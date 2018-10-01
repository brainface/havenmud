#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

string DoCreate();
int *Twn = "Haven";

static void create() {
  armour::create();

  SetShort("a metal armour");  
  SetLong("For each town, this varies slightly.");
  SetKeyName("armour");
  SetId( ({ "armour", "armor" }) );
  SetAdjectives( ({ "plate" }) );
  SetShort("a armour");
  SetLong("This is a setlong.");
      (: DoCreate :);

  SetDestroyOnSell(1);

}


string DoCreate() {
  switch(Twn) {
  case("Haven"):
  break;
  default:
        SetLong( + " This one is from nowhere.");
        debug(Tried to set town to " + Twn + ".");
  break;
}
return ({ (: DoCreate() :) });

}
