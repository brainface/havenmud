#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

string DoCreate(object who);

static void create() {
  armour::create( (: DoCreate :));

  SetShort("a metal armour");  
  SetLong("For each town, this varies slightly.");
  SetKeyName("armour");
  SetId( ({ "armour", "armor" }) );
  SetAdjectives( ({ "plate" }) );
  SetShort("a armour");
  SetDestroyOnSell(1);

}


string DoCreate(object who) {
 if( (int)who->GetTown() != -1 ) {
  string *town = who->GetTown();
  switch(town) {
  case("Haven"):
        SetLong(" This is from Haven.");
  break;
  default:
        SetLong(" This one is from nowhere.");
        debug("Tried to set town to something wrong.");
  break;
}

return(object who);
}
}
