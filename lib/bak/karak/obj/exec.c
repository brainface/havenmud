#include <lib.h>
#include "../karak.h"
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;
int WieldMe();

static void create() {
  item::create();
  SetKeyName("exterminator");
  SetId( ({ "executioner", "exterminator", "weapon" }) );
  SetShort("exterminator");
  SetLong("This bizarre weapon is essentially  a large steel "
             "cylinder inside which is a pyro squig and a generous "
              "supply of curry for him to eat.  The trigger mechanism "
             "is basically a pair of tongs that squeeze the squig, "
              "which will promptly spit a gout of flame out of the "
               "cylinder nozzle.  Only an orc would be crazy enough "
              "to use such a dangerously voliatile weapon.  On the whole "
              "it appears powerful, but rather fragile.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(200);
  SetClass(15);
  SetValue(200);
  SetMass(100);
  SetWeaponType("projectile");
  SetDamageType(HEAT);
  SetWield( (: WieldMe :) );
  }

  int WieldMe() {
    if ( this_player()->GetRace() == "ork" ) {
       write("The exterminator is ready to turn up the heat!");
        say(this_player()->GetCapName() + " wields an extermintor "
              + "weapon!");
      return 1;
     }
     else {
            write("Are you insane?  This weapon looks far to dangerous for any normal person to even consider using.");
     return 0;
    }
}
