// mahkefel 2010      
// got a little tired of all boarders having thin stilettos
#include <lib.h>                                           
#include <vendor_types.h>                                  
#include <damage_types.h>                                  
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("ball and chain");
  SetId( ({ "chain","ball" }) );
  SetAdjectives( ({ "ball","chain","heavy","and" }) );
  SetShort("a heavy ball and chain");
  SetLong(
    "This cruel implement shackles to the wrist and weighs down the "
    "victim, usually a criminal of some type. A large lead ball hangs "
    "down from a length of chain attached to the shackles."
  );
  SetProperty(
    "history",
    "These shackles were recovered from The Black Night, a notorious ghost "
    "ship that prowls the ruined sea. Victims of the ship were reanimated and "
    "forced to serve as sailors."
  );
  SetClass(15);
  SetDamagePoints(1500);
  SetValue(500);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetMass(2000);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(25);
}

