#include <lib.h>
#include <vendor_types.h>
#include "../path.h"

inherit LIB_ITEM;

static void create()
{
  item::create();
  SetKeyName("onyx cube");
  SetId(( { "cube","onyx cube","cabin","figurine"} ));
  SetShort("a onyx cube");
  SetLong("A faint pattern fills the black cube, giving the appearance of a "
          "cabin that shifts perspective depending upon the way you look at "
          "the cube.");
  SetMass(10);
  SetValue(10);
  SetDamagePoints(200);

  SetVendorType(VT_TREASURE);

  SetProperty("history", "Although the cube is centuries old, it's past is " +
                         "indeterminate.  A slight residue of evil infuses " +
                         "it, but the cube does not seem evil in itself.");
}
