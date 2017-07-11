// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("ghost");
   SetShort("an dryad ghost");
   SetId( ({ "ghost","dryad" }) );
   SetAdjectives( ({ "dryad" }) );
   SetLong("Blood-red hair curls over the shoulders of the "
           "dryad ghost, dangling down her lithe, muscular "
           "figure.");
   SetGender("female");
   SetRace("dryad");
   SetClass("thief");
   SetSkill("knife combat",1,1);
   SetSkill("knife combat",1,1);
   SetLevel(13);
   SetCurrency("ducats",30);
   SetInventory( ([
                    FOREST_OBJ + "dryadknife" : "wield knife",
                    FOREST_OBJ + "dryadpendant" : "wear pendant",
               ]) );
   SetAction(1, ({ "!emote screams.","!emote growls.","!say Someone "
                   "killed my tree!" }) );
   SetUndead(1);
}
