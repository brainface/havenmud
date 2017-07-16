/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: mcitizen.c
// Author: Derek Noble
// Creator: Dylanthalus@Haven
// Creation Date: February 10th, 1999
// Abstract: Random Male Citizen of Jidoor
// Revision History:  
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_SENTIENT;

int type = random(10);

static void create() {
  sentient::create();
  if (type == 0) { /* JIDOOR NPC TYPE: MALE SPRITE EVOKER*/
   SetId( ({ "sprite","citizen", "jid_protect" }) );
  SetAdjectives( ({ "male" }) );
  SetRace("sprite");
  SetShort("a male Sprite citizen of Jidoor");
  SetLong("This male citizen seems to be wandering around "
          "the peaceful city of Jidoor. He doesn't seem to "
          "have much of a sense of direction.  He is dressed "
          "in the robes of an evoker and looks somewhat "
          "dangerous but not overly threatening.");
  SetSpellBook( ([ 
      "fireball" : 100,
      "capsule" : 100 ]) );
  SetCombatAction(5, ({ 
      "!cast fireball",
      "!cast capsule" }) );
  SetClass("evoker");
   SetInventory( ([ 
      JID_OBJ + "/clothing/evoker_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
  }
  else if(type == 1) { /* JIDOOR NPC TYPE: MALE SPRITE ENCHANTER*/
  SetAdjectives( ({ "male" }) );
  SetRace("sprite");
   SetId( ({ "sprite","citizen", "jid_protect" }) );
  SetShort("a male Sprite citizen of Jidoor");
  SetLong("This male citizen seems to be wandering around "
          "the peaceful city of Jidoor. He doesn't seem to "
          "have much of a sense of direction.  He is dressed "
          "in the robes of a enchanter and looks somewhat "
          "dangerous but not overly threatening.");
  SetSpellBook( ([ 
     "fireball" : 100,
     "capsule" : 100 ]) );
  SetCombatAction(5, ({ 
     "!cast fireball",
      "!cast capsule" }) );
  SetClass("enchanter");
  SetInventory( ([ 
      JID_OBJ + "/clothing/enchanter_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
  }
  else if(type == 2) { /* JIDOOR NPC TYPE: MALE SPRITE NECROMANCER */
  SetAdjectives( ({ "male" }) );
   SetId( ({ "sprite","citizen", "jid_protect" }) );
  SetRace("sprite");
  SetShort("a male Sprite citizen of Jidoor");
  SetLong("This male citizen seems to be wandering around "
          "the peaceful city of Jidoor. He doesn't seem to "
          "have much of a sense of direction.  He is dressed "
          "in the robes of an necromancer and looks somewhat "
          "dangerous but not overly threatening.");
  SetSpellBook( ([ 
     "wards of protection" : 100,
     "chill touch" : 100 ]) );
  SetCombatAction(5, ({ 
     "!cast wards of protection",
     "!cast chill touch",
                 }) );
  SetClass("necromancer");
  SetInventory( ([ 
      JID_OBJ + "/clothing/necromancer_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
  }
  else if(type == 3) { /* JIDOOR NPC TYPE: MALE SPRITE DIVINER */
  SetAdjectives( ({ "male" }) );
  SetRace("sprite");
   SetId( ({ "sprite","citizen", "jid_protect" }) );
  SetShort("a male Sprite citizen of Jidoor");
  SetLong("This male citizen seems to be wandering around "
          "the peaceful city of Jidoor. He doesn't seem to "
          "have much of a sense of direction.  He is dressed "
          "in the robes of a diviner and looks somewhat "
          "dangerous but not overly threatening.");
  SetSpellBook( ([ 
     "wards of protection" : 100,
     "chill touch" : 100 ]) );
  SetCombatAction(5, ({ 
     "!cast wards of protection",
     "!cast chill touch",
                 }) );
  SetClass("diviner");
  SetInventory( ([ 
      JID_OBJ + "/clothing/diviner_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
  }
  else if(type == 4) { /* JIDOOR NPC TYPE: MALE SPRITE MYSTIC */
  SetAdjectives( ({ "male" }) );
  SetRace("sprite");
   SetId( ({ "sprite","citizen", "jid_protect" }) );
  SetShort("a male Sprite citizen of Jidoor");
  SetLong("This male citizen seems to be wandering around "
          "the peaceful city of Jidoor. He doesn't seem to "
          "have much of a sense of direction.  He is dressed "
          "in the robes of a mystic and looks somewhat "
          "dangerous but not overly threatening.");
   SetSpellBook( ([ 
      "capsule" : 100,
      "shock" : 100,
   ]) );
   SetCombatAction(5, ({ 
      "!cast capsule",
      "!cast shock",
   }) );
  SetClass("mystic");
  SetInventory( ([ 
      JID_OBJ + "/clothing/mystic_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
  }

  else if(type == 5) { /* JIDOOR NPC TYPE: MALE LAMRANI EVOKER */
   SetAdjectives( ({ "lamrani","male" }) );
   SetId( ({ "lamrani","citizen", "jid_protect" }) );
   SetRace("lamrani");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetShort("a male Lamrani citizen of Jidoor");
   SetLong("Tall and slender, this male Lamrani citizen of the "
           "city is dressed in the attire of an evoker. Although "
           "he appears to be friendly, he does look somewhat "
           "preoccupied.");
   SetSpellBook( ([ 
      "shock" : 100,
      "capsule" : 100,
   ]) );
   SetCombatAction(5, ({ 
      "!cast shock",
      "!cast capsule",
   }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/evoker_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
   SetClass("evoker");
   SetMorality(20);
   }
  else if(type == 6) { /* JIDOOR NPC TYPE: MALE LAMRANI ENCHANTER */
   SetAdjectives( ({ "lamrani","male" }) );
   SetId( ({ "lamrani","citizen", "jid_protect" }) );
   SetRace("lamrani");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetShort("a male Lamrani citizen of Jidoor");
   SetLong("Tall and slender, this male Lamrani citizen of the "
           "city is dressed in the attire of an enchanter. Although "
           "he appears to be friendly, he does look somewhat "
           "preoccupied.");
   SetSpellBook( ([ 
      "shock" : 100,
      "capsule" : 100,
   ]) );
   SetCombatAction(5, ({ 
      "!cast shock",
      "!cast capsule",
   }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/enchanter_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
   SetClass("enchanter");
   SetMorality(20);
   }
  else if(type == 7) { /* JIDOOR NPC TYPE: MALE LAMRANI NECROMANCER */
   SetAdjectives( ({ "lamrani","male" }) );
   SetId( ({ "lamrani","citizen", "jid_protect" }) );
   SetRace("lamrani");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetShort("a male Lamrani citizen of Jidoor");
   SetLong("Tall and slender, this male Lamrani citizen of the "
           "city is dressed in the attire of a necromancer. Although "
           "he appears to be friendly, he does look somewhat "
           "preoccupied.");
   SetSpellBook( ([ 
      "wards of protection" : 100,
      "chill touch" : 100,
   ]) );
   SetCombatAction(5, ({ 
      "!cast wards of protection",
      "!cast chill touch",
   }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/evoker_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
   SetClass("necromancer");
   SetMorality(20);
   }
  else if(type == 8) { /* JIDOOR NPC TYPE: MALE LAMRANI DIVINER */
   SetAdjectives( ({ "lamrani","male" }) );
   SetId( ({ "lamrani","citizen", "jid_protect" }) );
   SetRace("lamrani");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetShort("a male Lamrani citizen of Jidoor");
   SetLong("Tall and slender, this male Lamrani citizen of the "
           "city is dressed in the attire of a diviner. Although "
           "he appears to be friendly, he does look somewhat "
           "preoccupied.");
   SetSpellBook( ([ 
      "wards of protection" : 100,
      "chill touch" : 100,
   ]) );
   SetCombatAction(5, ({ 
      "!cast wards of protection",
      "!cast chill touch",
   }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/diviner_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
   SetClass("diviner");
   SetMorality(20);
   }
  else if(type == 9) { /* JIDOOR NPC TYPE: MALE LAMRANI MYSTIC */
   SetAdjectives( ({ "lamrani","male" }) );
   SetId( ({ "lamrani","citizen", "jid_protect" }) );
   SetRace("lamrani");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetShort("a male Lamrani citizen of Jidoor");
   SetLong("Tall and slender, this male Lamrani citizen of the "
           "city is dressed in the attire of a mystic. Although "
           "he appears to be friendly, he does look somewhat "
           "preoccupied.");
   SetSpellBook( ([ 
      "capsule" : 100,
      "shock" : 100,
   ]) );
   SetCombatAction(5, ({ 
      "!cast shock",
      "!cast capsule",
   }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/mystic_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
   SetClass("mystic");
   SetMorality(20);
   }
/* COMMON */
  SetMorality(15);
  SetKeyName("citizen");
  SetLevel(3+random(15));
  SetLimit(4);
  SetTown("Jidoor");
  SetReligion("Magildan","Magildan");
  SetCurrency("rupies",random(100));
  SetAction(1, ({ 
      "!speak Hello",
      "!speak Hello",
      "!speak Hello",
      "Citizen smiles at you.",
      "Citizen smiles at you.",
      "Citizen nods politely at you.",
      "Citizen nods politely at you.",
      "!speak It certainly is a nice day.",
      "!look at mountains",
      "!look at building",
      "!ponder",
   }) );
  SetGender("male");
  SetDie("The male citizen falls down dead.");
  SetWander(15);
}
