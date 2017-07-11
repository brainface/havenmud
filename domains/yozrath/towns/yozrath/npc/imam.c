#include <lib.h>
#include "../yozrath.h"
#include <domains.h>
#include <std.h>
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("bektash");
  SetLimit(1);
  SetShort("Hajji Bektash Wali, Supreme Imam of Yozrath");
  SetId( ({ "bektash", "wali", "imam", "hajji" }) );
  SetAdjectives( ({ "hajji", "bektash", "imam" }) );
  SetGender("male");
  SetRace("human");
  SetBaseLanguage("Padashi");
  SetTown("Yozrath");
  SetReligion("Kylin");
  SetLong(
    "Hajji Bektash Wali is the Supreme Imam of Yozrath.  He is the sole "
    "person allowed to induct new Imams, and he is the primary person to "
    "convert infidels to the True Faith of He Who Judges."
    );
  SetClass("imam");
  SetLevel(185);
  SetMorality(1500);
  SetSpellBook( ([
    "wall of force" : 100,
    "desert banishment" : 100,
    "hand of judgement" : 100,
    ]) );
  SetAction(10, ({
    "!speak The Faithful are called to He Who Judges.",
    "!speak I can convert you to the True Faith.",
    "!speak He Who Judges will smite the Infidels.",
    "!speak He Who Judges will bring his Hand of Judgement upon the Infidels.",
  }) );
  SetCombatAction(80, ({
    "!cast hand of judgement",
    "!cast desert banishment",
  }) );
  SetPlayerTitles( ([
    "newbie" : "$N the Desert Acolyte of Kylin",
    "mortal" : "$N the Preacher of the Sands",
    "hm"     : "Hajji $N the Desert Imam",
    "legend" : "Hajji $N the Mahdi of the Dunes",
    "avatar" : "Hajji $N the Prophet of the Desert",
    ]) );
  SetFreeEquipment( ([
    SOUTHERN_COAST_TOWNS "haven/obj/kylin_book" : 1,
    ]) );
  SetFirstCommands( ({ 
    "cast wall of force", 
    "cast wall of force", 
    "cast wall of force", 
    "cast wall of force",
    "cast wall of force",
    }) );
  SetInventory( ([
    YOZRATH_OBJ "thobe" : "wear thobe",
    YOZRATH_OBJ "bisht" : "wear bisht",
    YOZRATH_OBJ "turban" : "wear turban",
    ]) );

}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast wall of force");
  }
}
