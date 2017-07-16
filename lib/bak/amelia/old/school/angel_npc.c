#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("confuzzled angel");
   SetShort("a confuzzled angel");
   SetId( ({ "angel","fool" }) );
   SetAdjectives( ({ "poor","confuzzled","confused","foolish" }) );
   SetLong("Wet paths streak down the cheeks of this poor confused "
           "fool of an angel.  It looks around desperately, fluttering "
           "its wings in a frantic attempt to fly.");
   SetGender("neuter");
   SetRace("elemental");
   SetClass("animal");
   SetLevel(1);
   SetAction(5, ({
                   "!emote looks around sadly and starts to cry.",
                   "!speak I wanna be a mortal again, this is too hard!",
                   "Tears run down the confuzzled angel's face, and "
                      "suddenly it collapses to the ground and begins "
                      "to sob pathetically.  A few moments later, it "
                      "comes out of the fetal position and looks around "
                      "frantically.",
              }) );
   SetInventory( ([
                    "/realms/amelia/school/angel_wand.c" : 1,
                    "/std/armour/cloak/bluerobe" : "wear robe on torso",
               ]) );
}
