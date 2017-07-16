/*
 * Gantius the Enchanter leader
 * Balishae@haven
 */
#include <lib.h>
#include <std.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("gantius");
  SetShort("Gantius of Lloryk, Enchanter");
  SetId( ({ "gantius", 
            "mage", }) );
  SetRace("halfling");
  SetClass("enchanter");
  SetGender("male");
  SetLevel(60);
  SetLong("Although wizened and small, the man before you exudes "
          "competence and confidence while still maintaining humility.  "
          "From time to time the air flickers about him in a noticable "
          "aura.");
  SetSpellBook( ([
    "mesmer barrier" : 100,
    "disintegrate"   : 100,
    "paralysis" : 100,
    "chain lightning" : 100,
    "bolt" : 100,
    ]) );
  SetCombatAction(75, ({
    "!cast mesmer barrier",
    "!cast disintegrate",
    "!cast chain lightning",
    "!cast paralysis",
    "!cast bolt",
    }) );
  SetPlayerTitles( ([
    "newbie" : "the Apprentice Magius",
    "mortal" : "the Magius",
    "hm"     : "the Honored Magius",
    "avatar" : "the Archmage",
    "fighter": "the Sorceror of Llorykshire",
    ]) );
  SetTown("Lloryk");
  SetFreeEquip( ([
     STD_WEAPON "/pole/staff" : 1,
     ]) );
    SetInventory( ([
     STD_WEAPON "/pole/staff" : "wield staff",
     ]) );
}