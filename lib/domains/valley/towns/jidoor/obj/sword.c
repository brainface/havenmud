//
// The city guard's sword
// Created by Zaxan@Haven
//

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../jidoor.h"

inherit LIB_ITEM;

int Wielding(object ob);

static void create() {
   item::create();
   SetKeyName("rupie sword");
   SetId( ({ "sword" }) );
   SetShort("a large rupie sword");
   SetAdjectives( ({ "rupie", "large" }) );
   SetLong("A large sword that belongs to the guards of Jidoor.");
   SetMass(10); 
   SetValue(0);
   SetDamagePoints(5000);
   SetWeaponType("slash");
   SetDamageType(SLASH);
   SetClass(20);
   SetVendorType(VT_WEAPON);
   SetDestroyOnSell(1);
   SetWield( (: Wielding :) );
}

int Wielding(object ob) {
   if(member_array("guard", this_player()->GetId()) == -1) { 
      message("my_action","You are not worthy of using "
              "this!",this_player());
      message("my_action","The sword suddenly disappears into "
              "thin air.",this_player());
      eventDestruct();
      return 0;
   } else return 1;
}
