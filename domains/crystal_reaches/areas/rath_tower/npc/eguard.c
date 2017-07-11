#include <lib.h>
#include "../rath.h";
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("elite guard");
  SetShort("an elite guard");
  SetLong(
    "This is an elite soldier of Rath Khan's realm. He is a large figure "
    "that radiates a feeling of cold from his long dead form. Though he "
    "still stands watch over a no-longer existing empire, his duty "
    "remains clear in his mind."
  );
  SetFriends( ({ "guard","rath","elite guard","priest","diplomat" }) );
  SetGender("male");
  SetId( ({ "guard" }) );
  SetAdjectives( ({ "elite" }) );
  SetRace("elf");
  SetUndead(1);
  SetUndeadType("skeleton");
  SetClass("fighter");
  
  SetLevel(40+random(15));
  SetMorality(-400);
  SetCurrency("imperials",random(1000)+1);
  SetInventory( ([
     TOWER_O + "/gleamer" : "wield longsword",
     TOWER_O + "/chain" : "wear chainmail",
  ]) );
  RemoveLanguage("Eltherian");
  SetLanguage("Archaic", 100, 1);
  SetProperty("rath_guard", 1);
 }
