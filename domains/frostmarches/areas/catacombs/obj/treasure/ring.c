#include <lib.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("ring");
  SetId( ({"ring"}) );
  switch(random(4)) {
  case 0:
    SetShort("an emerald ring");
        SetAdjectives( ({ "emerald" }) );
        SetLong("This expensive looking ring has a band of gold"
                " with a large emerald embedded into it. It looks"
                " as though it were made by a master.");
        break;
    case 1:
       SetShort("a ruby ring");
        SetAdjectives( ({ "ruby" }) );
        SetLong("This expensive looking ring has a band of gold"
                " with a large ruby embedded into it. It looks"
                " as though it were made by a master.");
        break;
    case 2:
        SetShort("an onyx ring");
        SetAdjectives( ({ "onyx" }) );
        SetLong("This expensive looking ring has a band of gold"
                " with a large onyx embedded into it. It looks"
                " as though it were made by a master.");
        break;
    case 3:
      SetShort("an opal ring");
        SetAdjectives( ({ "opal" }) );
        SetLong("This expensive looking ring has a band of gold"
                " with a large opal embedded into it. It looks"
                " as though it were made by a master.");
        break;    
   }  
  SetMass(40);
  SetValue(random(500) + 1000);
  SetMaterial( ({ "metal", "natural" }) );
  SetRepairSkills( ([
         "metal working" : 10,
         "armour smithing" : 10,
         "natural working" : 10,
         ]) );
  SetVendorType(VT_GEM|VT_TREASURE);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CHAIN);
  SetArmourType(A_RING);
}
