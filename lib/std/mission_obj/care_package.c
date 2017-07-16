
#include <lib.h>
#include <std.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("care package");
  SetId( ({"package", "care package" }));
  SetShort("a care package for Calliste");
  SetAdjectives( ({ "for calliste", "for Calliste" }) );
  SetLong("This package has been wrapped up nice and"
          " neat with a ribbon that has been tied"
          " into a bow. It has a label on it which"
          " says: \"For Calliste.\"");
  SetMass(50);
  SetValue(0);
  SetDestroyOnSell(1);
  SetMaterial( ({"natural"}) );
  }
