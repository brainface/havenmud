
//Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_EQUIPPER;

static void create() {
   ::create();
   SetKeyName("Auran");
   SetShort("Auran the Helpful");
   SetId( ({ "auran","helpful" }) );
   SetAdjectives( ({ "auran","the","helpful" }) );
   SetLong("Auran's green eyes have a kindly sparkle to them, and his smile is "
           "pleasant and generous.");
   SetGender("male");
   SetRace("human");
   SetSkill("melee attack",1,1);
   SetLevel(20);
   SetFreeEquipment( ([
                        "mace" : AVERATH_OBJ + "newbie_mace",
                        "sword" : AVERATH_OBJ + "shortsword",
                        "knife" : AVERATH_OBJ + "newbie_knife",
                        "shirt" : AVERATH_OBJ + "drab_shirt",
                        "pants" : AVERATH_OBJ + "drab_pants",
                   ]) );
   SetLevelLimit(5);
   SetAction(1, ({ "!say If you're looking for a weapon or some clothes, "
                   "ask me to help!" }) );
}
