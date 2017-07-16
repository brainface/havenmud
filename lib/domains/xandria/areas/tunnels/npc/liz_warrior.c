#include <lib.h>
#include "../tunnels.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("thri-kreen warrior");
  SetRace("thri-kreen");
  SetGender(random(2) ? "male" : "female");
  SetClass("fighter");
  SetLevel(50 + random(20));
  SetShort("a thri-kreen warrior");
  SetId( ({ "thri-kreen", "warrior" }) );
  SetAdjectives( ({ "thri-kreen" }) );
  SetLong(
    "This proud creature defends the hive from all harm. This is one thri-kreen that surely "
    "knows " + possessive() + " around weapons."
    );
  SetInventory( ([
    TUNNELS_DIR "sword" : 4,
    TUNNELS_DIR "loin"  : "wear loincloth",
    ]) );
  SetFirstCommands(({
    "wield first sword", "wield first sword", "wield first sword", "wield first sword", 
  }) );
  SetFriends( ({ "thri-kreen" }) );
}