// Junk by Urien@Haven 103013
// Passive way to obstruct miners 
// Not intended for crafting

#include <lib.h>
#include <vendor_types.h>
#include <loot.h>

inherit LIB_ITEM;
 
static void create(){
  string theDebris;
 
  ::create();
  SetKeyName("chunk");
  switch(random(7))
  {
    case 0: theDebris = "rock"; break;
    case 1: theDebris = "soft bone"; break;
    case 2: theDebris = "muddy"; break;
    case 3: theDebris = "soil"; break;
    case 4: theDebris = "pebble"; break;
    case 5: theDebris = "jagged rock"; break;
    case 6: theDebris = "dead root"; break;
  }

  SetShort("a "+theDebris+" chunk");
  SetId( ({ "chunk", ""+theDebris+"" }) );
  SetAdjectives( ({ ""+theDebris+"" }) );
  SetLong("This piece of "+theDebris+" is small in size "
          "and seems to have been exposed recently. It "
          "looks as though it has no purpose other than "
          "impeding those seeking fortune. This particular "
          ""+theDebris+" piece does not seem to contain any "
          "true value and is quite worthless.");
  SetMass(5);
  SetValue(1);
  SetDamagePoints(35);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_GEM);
  SetProperty("history","This "+theDebris+" chunk "
     "contains an essence as old as Kailie itself. ");
}

