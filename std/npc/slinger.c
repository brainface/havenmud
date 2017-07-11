/*  Sword Slinging trainer */
#include <lib.h>
#include <std.h>
inherit LIB_STYLE_TRAINER;

static void create() {
  ::create();
  SetKeyName("dartanian");
  SetRace("goden");
  SetClass("cavalier");
  SetShort("a callous-looking goden");
  SetId( ({ "dartanian", "goden" }) );
  SetAdjectives( ({ "callous", "looking" }) );
  SetLevel(30);
  SetCombatStyleLevel("sword slinging", 100);
  SetCombatStyle("sword slinging");
  SetCurrency("senones", random(800));
  SetMorality(-200);
  SetGender("male");
  SetInventory( ([
    STD_CLOTHING "pant/fencing_breeches" : "wear breeches",
/*
    STD_CLOTHING "shirt/sword_shirt" : "wear shirt",
    STD_CLOTHING "boot/high_boots" : "wear boots",
*/
    STD_CLOTHING "boot/boot" : "wear boots",
    STD_SLASH "bluesword" : "wield sword",
   STD_CLOTHING "cloak/cape" : "wear cape",
    ]) );
  SetLong("This swift and evil looking goden has an air of "
          "contempt about him which suggests he has knowledge "
          "of slaughter beyond his years. His hand stays near his sword "
         "at all times when he has it, which shows his need for it.");
}
