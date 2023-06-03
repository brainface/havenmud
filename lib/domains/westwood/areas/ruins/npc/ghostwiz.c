#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../castle.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetRace("muezzin");
  SetGender("female");
  SetClass("cleric");
  SetLevel(110);
  SetKeyName("Spirit");
  SetId( ({ "spirit","cleric"}) );
  SetAdjectives( ({ "wispy" }) );
  SetShort("a wispy cleric spirit");
  SetLong("This muezzin spirit seems to have reached a high "
          "knowledge of the clerical arts. Vines which seem "
          "to be part of her drape down her small body type and "
          "cover her shoulders to her knees. She ebbs "
          "a soft green hue from her misty body and displays "
          "a knowledgable, yet confused appearance of her "
          "surroundings. Her body shape is average sized for "
          "a Muezzin of her undead standard. ");
  SetInventory( ([
    RUINS_OBJ + "bmedallion" : "wear medallion",
    RUINS_OBJ + "scroll" : 1,
    ]) );
  SetSpellBook( ([
    "heal" : 100,
    ]) );
  SetDie("The spirit forms into a corpse!"); 
  SetUndead(1);
  SetMorality(-25);
  SetReligion("Eclat","Eclat");
  SetCombatAction(25, ({ 
    "!emote tries to cast but nothing happens!",
    "!wail",
    "!cast heal",
    }) ); 
  SetAction(2, ({
    "!speak .... some raiders enter and destroy ... "
           "but that ... i had my strength to speak.",
    "!speak The Ivory Castle is a shadow of ... once was.",
    "!speak Amelia ... be praised.",
    "!emote searches for something.",
    "!speak The guards ... nothing here to protect Soliel!",
    "!emote whimpers softly.",
    "!speak It ... duty to guard the treasure.",
    "!emote looks around.",
    "!speak Those monsters....turned ... this ...",
    "!speak ... Kill ... me ...",
    "!speak It would ... be my honor ...",
     }) );
}