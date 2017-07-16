//   a small childs grocery list   //
//   Aless "depth" 2011   //

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName( "paper" );
  SetId(({ "paper", "note", "parchment" }));
  SetShort( "a crumpled paper" );
  SetAdjectives( ({ "crumpled", "small" }) );
  SetLong(
     "This small piece of paper has been crumpled as if held "
     "in a hand or pocket for too long. Perhaps you could <read> it?"
     );
  SetVendorType(VT_TREASURE);
  SetProperty("history", "This paper was given to a small child by "
     "their mother.");
  SetRead("default",
     "A loaf of bread \n\n"
     "A container of milk \n\n"
     "A stick of butter\n\n"
     );   
}
