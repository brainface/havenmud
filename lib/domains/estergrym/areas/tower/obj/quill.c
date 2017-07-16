//A used and broken quill

#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("quill");
  SetId( ({ "quill" }) );
  SetAdjectives( ({ "stained" }) );
  SetShort( "a stained quill" );
  SetLong( "It is roughly about two lengths of a humans index finger. "
           "Most of the bristles of the feather part of the quill have been "
           "worn and some are missing. The tip is bent and hanging off slightly "
           "and the entire thing is covered in damp and sticky ink. Numerous "
           "dents lie in the stem of the feather exposing its hollow inside.");
  SetMass(1);
  SetValue(1);
  SetVendorType(VT_TREASURE);
}