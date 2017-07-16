#include <lib.h>
#include <damage_types.h>
#include <domains.h>

inherit LIB_NPC;

static void create() {
  ::create();

  SetKeyName("goblin general");
  SetId( ({"goblin","general"}) );
  SetAdjectives( ({"general"}) );
  SetShort("the goblin general");
  SetLong("This goblin is much taller and larger than the others, giving "
     "a feeling that he may be in charge. He also appears to be the worst "
     "to look at, his fat greenish body dirty with sweat and slime, and "
     "his teeth are broken and nearly black. He looks ready to do battle.");
  SetRace("goblin");
  SetClass("fighter");
  SetGender("male");
  SetLevel(15);
  AddCurrency("ducats", random(8));
  SetSkill("blunt combat", 20, 2);
  SetSkill("knife combat", 15, 2);
  SetCombatAction(3, ({
     "!say now you will die!",
     "!emote elbows you hard in the jaw.",
     "!say GUARDS!! I AM BEING ATTACKED!",
    }) );
  SetAction(3, ({
     "!emote paces around the room grumbling.",
     "!say soon.... soon we will be able to go topside and fight!",
    }) );
  SetInventory( ([
     AVERATH_OBJ "heavy_axe" : "wield axe",
     AVERATH_OBJ "tlarmour" : "wear armour",
     AVERATH_OBJ "sshield.c" : "wear shield on right arm", 
     ]) );
  SetEncounter(0);
  SetMorality(-50);
}
