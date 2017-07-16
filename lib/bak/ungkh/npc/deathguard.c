#include <lib.h>
inherit LIB_NPC;
static void create() {
 npc::create();
  SetKeyName("elite deathguard");
  SetId( ({ "deathguard", "warrior", "guard", "elite deathguard" }) );
  SetShort("a elite deathguard of Malak");
  SetLong("This dark visaged warrior serves noone save the divine will "
       "of Malak.  His beady red eyes glare out from the cowels of his hooded "
       "cloak.  His almost corpse-white hands grip the haft of a mighty bone "
       "scythe.");
  SetLevel(10+random(10));
  SetRace("orc");
  SetClass("fighter");
  SetGender("male");
  SetMorality(-100);
  SetCombatAction(5, ({
     "!shout Join Malak in the Halls of the dead, heathen!"
                   }));
  SetAction(5, ({ 
      "!emote chants quietly.", "!say All praise Malak, Lord of Death!" }));
  SetFriends( ({
    "flink",
    "mmk",
    }) );
  SetDie("The warrior lets out a howl of joy as he dies.");
  SetInventory( ([ 
// Stupid fucking malak/cyric hard coded this? n00b.
//          "/realms/malak/kuthar_stuff/obj/cloak.c" : "wear cloak", 
//          "/realms/malak/kuthar_stuff/obj/scythe.c" : "wield scythe",
          ]) );
  }
