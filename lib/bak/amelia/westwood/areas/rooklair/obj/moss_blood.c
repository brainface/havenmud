#include <lib.h>
#include <vendor_types.h>
#include "../rook.h"

inherit LIB_ITEM;
 
static void create() {
  item::create();
  SetKeyName("moss");
  SetId( ({"moss","fuzzy"}) );
  SetShort("%^RED%^BOLD%^a fuzzy red piece of moss%^RESET%^");
  SetLong("This is a rare thing called blood moss.  It "
    "is red in colour and fuzzy.");
  SetAdjectives( ({"fuzzy","red","piece"}) );
  SetMass(5);
  SetValue(10000);
  SetMaterial("natural");
  SetVendorType(VT_TREASURE);
}
