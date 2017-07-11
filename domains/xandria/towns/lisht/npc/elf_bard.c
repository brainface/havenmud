#include <lib.h>
#include "../lisht.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("ari");
  SetShort("Ari the Musician");
  SetRace("elf");
  SetBaseLanguage("Alatherian");
  SetGender("male");
  SetClass("bard");
  SetLevel(25);
  SetInventory( ([
    LISHT_OBJ "slave_pipe" : "wield pipe",
    ]) );
  SetFreeEquipment( ([
    LISHT_OBJ "slave_pipe" : 1,
    ]) );
  SetId( ({ "ari", "musician" }) );
  SetAdjectives( ({ "musician" }) );
  SetSongBook( ([
    "star fall" : 100,
    ]) );
  SetLong(
    "Ari the Musician is a humble slave that keeps the spirits of the "
    "other slaves high through the use of his magical music. Those "
    "inspired could <ask ari to join bards> to continue his efforts "
    "to free the slaves through music."
    );
  SetPlayerTitles( ([
    "newbie" : "the Mournful Musician of the Maligned",
    "mortal" : "the Sorrowful Singer of the Slaves",
    "hm"     : "the Arranger of Aural Alleviation",
    "legend" : "the Chariot of the Choir",
    "avatar" : "the Inspired Bard of the Downtrodden",
    ]) );
  SetAction(6, ({
    "!speak You could join my music.",
    "!speak Ask me to join bards!",
    "!speak Our people are down, but not broken.",
    "!speak Some day, He will deliver us.",
  }) );
  SetRestrictRace(1);
  SetCurrency("deben", 30);
  SetMorality(250);
  SetTown("Lisht");
}
