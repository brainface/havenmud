/*  A gnomish explorer */
#include <lib.h>
#include "../stryke.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("explorer");
  SetRace("gnome");
  SetClass("fighter");
  SetLevel(15+random(10));
  SetShort("a gruff gnomish explorer");
  SetId( ({ "gnome", "explorer" }) );
  SetAdjectives( ({ "gruff", "gnomish" }) );
  SetLong("This small gnome looks experienced in the arts of cave "
          "exploration enough to handle his own down here.");
  SetInventory( ([
     STRYKE_OBJ + "pickaxe" : "wield axe",
     STRYKE_OBJ + "helm" : "wear helmet",
     STRYKE_OBJ + "leather_vest" : "wear vest",
     ]) );
  SetCurrency("imperials",random(300)+10);
  SetGender("male");
  SetMorality(150 + random(50));
  }

