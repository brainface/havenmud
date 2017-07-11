#include <lib.h>
#include "../gnome_lab.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("gnome");
  SetId( ({"gnome"}) );
  SetAdjectives( ({"dirty"}) );
  SetShort("a dirty gnome");
  SetLong(
     "This stocky gnome is unkept and dirty looking. His face is "
         "unshaven and covered in dried mud. A noticeable hump can be "
         "seen on his back. His piercing eyes are grey in color, much "
         "like an incoming rainstorm." );
  SetAdjectives("stocky", "dirty", "unkept");
  SetRace("gnome");
  SetClass("necromancer");
  SetLevel(11);
  RemoveLanguage("Nibelungen");
  SetLanguage("Eltherian", 100, 1);
  SetGender("male");
  SetMorality(-600);
  SetSpellBook( ([
          "shroud"     : 100,
          "ice ball"   : 100,
          "wound"      : 100,
          "hunger"     : 100,
          "acid blast" : 100,
          ]) );
  SetAction(10, ({
          "!cast shroud",
          "!yell where are my specimens!.",
          "!say did you bring me my specimens?",
          "!say why are you here?",
          "!say I need them",
     }) );
  SetCombatAction(60, ({ 
          "!yell useless dwarves!",
          "!cast ice ball",
          "!cast acid blast,",
          "!cast shroud",
          "!yell You must be crazy to cross me!",
          "!cast hunger,"
          "!cast wound,",
     }) );
  SetInventory( ([
     G_OBJ + "pole"       : "wield pole",
     G_OBJ + "pants"  : "wear pants",
           G_OBJ + "jacket" : "wear jacket",
           G_OBJ + "boots"  : "wear boots",
     ]) );
//  SetEncounter(40);
}
