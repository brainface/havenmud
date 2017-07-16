// In the attic, plans I had for it are nix 
// An item you cannot get, was supposed to be 
// stuck to the ceiling
// Urien 102913
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("ruby");
  SetId( ({ "ruby" }) );
  SetAdjectives( ({ "red", "diamond","cut" }) );
  SetShort( "a diamond cut red ruby" );
  SetLong( "This ruby glows with magical power. It has been cut by "
           "a master craftsman to form a perfect diamond shape. It "
           "appears flawless and would probably fetch a pile of "
           "wealth to any legitimate collector. Its surface "
           "appears hardened but shines like the most perfect glass "
           "ever formed in Kailie. It is mounted in the ceiling by "
           "three cut triangles which hold the diamond in place.");
  SetPreventGet("It flickers as you try to grab it from the ceiling. A "
                "strong force prevents release of the ruby!");
}