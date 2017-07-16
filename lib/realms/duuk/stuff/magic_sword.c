#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
int WieldFunction();
int CheckBonus();

static void create() {
  item::create();
  SetKeyName("rapier");
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smith" : 1,
    ]) );
  SetProperty("magic", "The rapier is of heavenly origin.");
  SetMaterial( ({ "mithril" }) );
  SetShort("a finely crafted elven rapier");
  SetId( ({ "rapier", "fine rapier" }) );
  SetClass(18);
  SetMass(225);
  SetValue(1800);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pierce");
  SetDamageType(PIERCE|MAGIC);
  SetLong("This is a slightly glowing fine elven rapier.");
  SetRadiantLight(10);
  SetWield( (: WieldFunction :) );
  }

int WieldFunction() {
  message("system", "Function WieldFunction called.", environment() );
  return environment()->AddStatBonus("strength", (: CheckBonus :) );
}


int CheckBonus() {
  if (member_array(this_object(), environment()->GetWielded()) == -1) {
      message("system", "You're not wielding me, ass.", environment() );
      environment()->RemoveStatBonus("strength");
     return 0;
  }
  return 1;
}
