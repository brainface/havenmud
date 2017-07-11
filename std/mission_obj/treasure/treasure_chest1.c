#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>

inherit LIB_STORAGE;

static void create() {
  ::create();
  SetKeyName("chest");
  SetDamagePoints(5000);
  SetId( ({ "chest", "treasure_chest1" }) );
  SetShort("an old and decaying chest");
  SetLong("The wood that composes the majority of this chest is old and starting to"
          " decay. The metal bands used as support show significant rusting and in some"
          " places, holes. The lock has long since been inoporable.");
  SetAdjectives( ({ "old", "decaying", "decayed" "wood", "wooden" }) );
  SetMass(25000);
  SetPreventGet("If you picked it up, the chest would probably collapse.");
  SetClosed(1);
  SetCanClose(1);
  SetMaxCarry(9000000000);
  SetMaterial( ({ "wood" }) );
  SetKeys( ({ "treasure1_key" }) );
  SetInventory( ([
      "/std/mission_obj/treasure/weak_healing_potion"  : 5,
      "/std/mission_obj/treasure/weak_mana_potion"     : 3,
    ]) );
}



varargs mixed eventOpen(object who, string id, object tool) {
  if ((who->GetProperty("mission")) == "/std/missions/special/treasure1") {
   who->SetProperty("Treasure1", 1);

    ::eventOpen(who, id, tool);
   }
  if ((who->GetProperty("mission")) != "/std/missions/special/treasure1") {
  who->eventPrint("You did not earn this treasure, did you?");
 }
}
