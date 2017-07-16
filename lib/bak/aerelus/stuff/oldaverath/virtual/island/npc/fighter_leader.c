#include <lib.h>
#include <domains.h>
inherit LIB_LEADER;

static void create() {
    leader::create();
    SetKeyName("elgard");
  SetId( ({ "elgard", "weary" }) );
    SetShort("Elgard the Weary");
    SetLong("It is obvious how Elgard Tal’Avrath recieved his misnomer. "
            "He is dressed in a decidedly haggard robe that hangs losely from "
             "his thin, frail body, weakened with age.  His once robust features are "
             "haggard and worn, and his flesh hangs limply from his face, giving him a "
             "almost half melted appearance.  His frail hands constantly shake, and "
            "are criss-crossed with a multitude of veins and pock-marks. His fierce "
           "grey eyes have been dulled by age, and a long, jagged scar creeps up from "
         "the corner of his mouth to his eye. Despite his feeble appearance, it is "
           "obvious that he can show you a thing or two about being a warrior.");
    SetLevel(35);
    SetRace("human");
    SetClass("fighter");
    SetGender("male");
    SetTown("Averath");
    SetMorality(-100);
    SetProperty("no bump", 1);
    SetFreeEquipment( ([
      AVERATH_OBJ "shortsword" : 1,
      ]) );
  SetPlayerTitles( ([
    "newbie" : "the Hotheaded Young Brawler",
    "mortal" : "the Sword for Hire",
   "high mortal" : "the Accomplished Swordsman",
    "legend" : "the Widowmaker",
    "avatar" : "the Supreme Master of War",
    "demigod" : "the Embodiment of Battle",
 ]) );
  SetInventory( ([
  "/std/clothing/body/black_robe" : "wear robe",
    AVERATH_OBJ "banksword" : "wield sword",
    ]) );
}
