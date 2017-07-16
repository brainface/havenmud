/*  Portia  10-21-98
    A cleric leader for Malveillant.
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Tallia");
  SetShort("Tallia Vestilanti, the High Priestess of Soirin");
  SetId( ({"tallia", "priestess", "priestess of soirin", "vestilanti"}) );
  SetAdjectives( ({"high"}) );
  SetLong("This woman is very beautiful but has an aura about her "
           "warning one not to come to close. Her demeanor is that of "
          "one who thinks herself better than everyone else.");
  SetRace("dark-elf"); 
  SetReligion("Soirin","Soirin");
  SetTown("Malveillant");
  SetMorality(-2000);
  SetGender("female");
  SetInventory( ([
      MAL_OBJ + "/clothing/elf_blouse"     : "wear blouse",
      MAL_OBJ + "/clothing/elf_skirt"      : "wear skirt",
      MAL_OBJ + "/clothing/cler_medallion" : "wear medallion",
      MAL_OBJ + "/weapons/elf_dagger"      : "wield dagger",
      MAL_OBJ + "/weapons/g_knife"         : "wield knife",
      MAL_OBJ + "/misc/pleasurable_worship" : 1,
      ]) );
  SetClass("priest");
  SetSkill("poison magic",1,2);
  SetUniqueSkills( ([
      "blunt combat" : 0,
      "knife combat" : 1,
      "stealth" : 2,
      ]) ); 
  SetLevel(80);
  SetCurrency("roni",random(300) + 500);
  SetSpellBook( ([
      "purify"             : 100,
      "pious obstructions" : 100,
      "touch of death"     : 100,
      "poison arrow"       : 100,
      "stab in the dark"   : 100,
      ]) );
  SetCombatAction(60, ({
      "!cast poison arrow",
      "!cast pious obstructions",
      "!cast purify",
      "!cast touch of death",
      "!cast stab in the dark",
      }) );
  SetPlayerTitles( ([
      "newbie" : "the Tempted",
      "mortal" : "the Wielder of the Black Rose",
      "hm"     : "the Divine Theorist of Avarice",
      "legend" : "the Zealous Preacher of Lust",
      "avatar" : "the Ravenous Hierophant",
     "fighter" : "the Eternally Devoted Blade of Alessandra",
      "rogue"   : "the Shadow of the Dark Mistress",
       ]) );
  SetFreeEquip( ([
        MAL_OBJ + "/weapons/cleric_knife" : 1,
        MAL_OBJ + "/misc/dayofroses" : 1,
      ]) );
   SetTaughtSpheres( ({
      "clerical necromancy",
      "clerical evokation", 
      "religion soirin",
      "clerical",
      }) );
  }
