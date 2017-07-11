/* chalice
  Zara 8/14/98
*/

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("chalice");
  SetShort("a jeweled chalice");
  SetId( ({"chalice"}) );
  SetAdjectives( ({"jeweled","gold"}) );
  SetLong("This jeweled chalice is fashioned of gold. Square cut "
         "rubies and black diamonds are placed alternately around "
         "the rim and base. Delicate engravings depict sea nymphs "
         "frolicking in the surf.");
  SetMass(50);
  SetValue(3000);
  SetVendorType(VT_TREASURE);
}
