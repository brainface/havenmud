/*  A primative human thing */
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("native");
  SetShort("a primitive jungle native");
  SetMorality(200);
  SetId( ({ "native" }) );
  SetAdjectives( ({ "primitive", "jungle" }) );
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetClass("ranger");
  SetLevel(10+ random(10) );
  SetGender("male");
  SetLong(
     "This muscular man is one of the many natives of the jungle. "
     "His heavily tanned skin covers his defined body. His hair "
     "looks dirty and is ruffled into a wirey bush ontop of his scalp. "
     "He has a confident look upon his face, suggesting he's proficient "
     "in his art of hunting. "
  );
  if (random(2)) {
     SetInventory( ([
        __DIR__ + "obj/wood_mail" : "wear armour",
        __DIR__ + "obj/boomer" : "wield boomerang",
        "/domains/baria/towns/baria/obj/loincloth" : "wear loincloth",
        ]) );
     } 
    else {
       SetInventory( ([
        __DIR__ + "obj/wood_mail" : "wear armour",
        __DIR__ + "obj/spear" : "wield spear",
        "/domains/baria/towns/baria/obj/loincloth" : "wear loincloth",
       ]) );
    }
  }
