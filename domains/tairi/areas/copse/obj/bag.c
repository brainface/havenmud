

#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_STORAGE;


static void create() {
  ::create();
  SetKeyName("leather bag");
  SetId( ({ "pack","bag" }) );
  SetAdjectives( ({ "tattered", "leather" }) );
  SetShort("a tattered leather bag");
  SetLong("This bag has been beat nearly to uselessness."
          " There are rips and cuts all over it and the"
          " seams are tattered and ragged. It's amazing"
          " anyone would use it for storage.");
  SetMass(150);
  SetValue(0);
  SetArmourType(A_CLOAK);
  SetVendorType(VT_CLOTHING);
  SetArmourClass(ARMOUR_LEATHER);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(100);
  SetMaterial( ({ "leather" }) );
  SetWarmth(10);
  SetRepairSkills( ([ "leather" : 1,]) );
  SetRepairDifficulty(30);
  SetCanClose(1);
  SetClosed(1);
  SetMaxCarry(700);
  SetInventory( ([
     "/domains/southern_coast/areas/leatherstore/oldvest" : 1,
     "/domains/southern_coast/areas/leatherstore/oldpants" :1,
     "/domains/southern_coast/areas/leatherstore/oldboots" : 1,
     "/domains/southern_coast/areas/leatherstore/oldglove" : 2,
     "/domains/southern_coast/areas/leatherstore/oldhelmet" : 1, 
    ]) );
  }

int eventOpen() {
     eventDestruct();
     message("system", 
       "As you attempt to open the bag it falls apart spilling its contents.",
        this_player() );
    }


