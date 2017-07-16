// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_BARKEEP;

static void create() {
   ::create();
   SetKeyName("Sitha");
   SetShort("Sitha the Herbalist");
   SetId( ({ "sitha","herbalist" }) );
   SetAdjectives( ({ "sitha","the","herbalist" }) );
   SetLong("Dirt covers Sitha's gnarled fingers, collecting beneath her "
           "jagged fingernails.  Her sharp eyes cast a scathing glance "
           "at her surrounding, scruntinizing every movement and quiver.  "
           "Her face hangs in bags, and her mouth curls up in a sneering "
           "scowl.  Wild fire-red hair rings her face in knotted strands that "
           "hang below her waist, tinged with random white strands.");
   SetGender("female");
   SetRace("dryad");
  SetSkill("melee combat",1,1);
   SetSkill("melee combat",1,1);
   SetSkill("bargaining",1,1);
   SetLevel(20);
   SetMorality(-450);
   SetAction(3, ({ "!emote scowls.","!emote frowns.","!emote digs at the "
                   "ground.","!emote examines a bulbous root.","!emote holds "
                   "a leaf up to the light.", }) );
   SetCombatAction(1, ({ "!emote screams.","!emote screeches.","!emote 's eyes "
                         "bulge out as she cackles." }) );
   SetLocalCurrency("ducats");
   SetCurrency("ducats",53);
   SetMenuItems( ([
                    "devilroot" : FOREST_OBJ + "devilroothp",
                    "adonis" : FOREST_OBJ + "adonissp",
                    "neem" : FOREST_OBJ + "neempoison",
                    "oxknee" : FOREST_OBJ + "oxkneemp",
               ]) );
   SetProperty("no bump",1);
   SetInventory( ([
                   FOREST_OBJ + "neempoison" : random(2),
                   FOREST_OBJ + "devilroothp" : 4,
                   FOREST_OBJ + "adonissp" : 3,
              ]) );
   SetCurrency("ducats",45);
}
