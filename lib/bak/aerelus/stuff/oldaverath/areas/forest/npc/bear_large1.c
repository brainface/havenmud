//Lilavae
#include <lib.h>
#include <damage_types.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("bear");
   SetShort("a huge black bear");
   SetId( ({ "bear","ameliamommybear" }) );
   SetAdjectives( ({ "huge","black" }) );
   SetLong("Standing on sturdy legs, this gargantuan black bear "
	    "looks lethal and quite able to inflict excruciating pain "
            "on anyone naive enough to remain close to her lair .");
   SetGender("female");
   SetRace("bear");
   SetSkill("melee attack",1,1);
   SetSkill("melee defense",1,1);
   SetLevel(23);
   SetAction(3, ({
                  "!emote bats her paws in the air.",
       "!enter cave",
		  "!emote roars mightily.",
   }) );
   SetCombatAction(2, ({ "!emote snaps her jaws." }) );
}
