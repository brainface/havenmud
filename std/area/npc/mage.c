#include <lib.h>
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("mage");
  SetTaughtSpheres( ({ "magical evokation" }) );
  SetShort("a mage");
  SetId( ({ "mage" }) );
  SetAdjectives( ({}) );
  SetRace("human");
  SetClass("evoker");
  SetLevel(2);
  SetSpellBook( ([
      "buffer" : 25,
      ]) );
  SetGender("male");
  SetAction(0, ({
      "!cast buffer",
     }) );
  SetLong("This is a buffer crazy mage.");
 }
