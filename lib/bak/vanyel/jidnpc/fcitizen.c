/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: fcitizen.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Feb 10th, 1999
// Abstract: Random Female Citizens of Jidoor
// Revision History:  
/* ----------------------------------------------------------------------- */
#include <lib.h>
#include "../jidoor.h"

inherit LIB_SENTIENT;

int type = random(10);

static void create() {
   sentient::create();
  if (type == 0) { /* JIDOOR NPC TYPE: FEMALE SPRITE EVOKER*/
   SetAdjectives( ({ "sprite","female" }) );
   SetId( ({ "sprite","citizen", "jid_protect" }) );
   SetRace("sprite");
   SetShort("a female Sprite citizen of Jidoor");
   SetLong("Dressed in the attire of an evoker, the female citizen "
           "is wandering about the city attending to her daily "
           "business. She appears to be friendly.");
   SetSpellBook( ([ 
      "missile" : 100,
      "shock" : 100,
      "buffer" : 100,
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
  else if(type == 1) { /* JIDOOR NPC TYPE: FEMALE SPRITE ENCHANTER*/
   SetAdjectives( ({ "sprite","female" }) );
   SetId( ({ "sprite","citizen", "jid_protect" }) );
   SetRace("sprite");
   SetShort("a female Sprite citizen of Jidoor");
   SetLong("Dressed in the attire of an enchanter, the female citizen "
           "is wandering about the city attending to her daily "
           "business. She appears to be friendly.");
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
  else if(type == 2) { /* JIDOOR NPC TYPE: FEMALE SPRITE NECROMANCER*/
   SetAdjectives( ({ "sprite","female" }) );
   SetId( ({ "sprite","citizen", "jid_protect" }) );
   SetRace("sprite");
   SetShort("a female Sprite citizen of Jidoor");
   SetLong("Dressed in the attire of a necromancer, the female citizen "
           "is wandering about the city attending to her daily "
           "business. She appears to be friendly.");
   SetSpellBook( ([ 
      "wards of protection" : 100,
      "chill touch" : 100,
   ]) );
   SetCombatAction(5, ({ 
      "!cast chill touch",
      "!cast wards of protection",
   }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/necro_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
   SetClass("necromancer");
   SetMorality(20);
}
  else if(type == 3) { /* JIDOOR NPC TYPE: FEMALE SPRITE DIVINER*/
   SetAdjectives( ({ "sprite","female" }) );
   SetId( ({ "sprite","citizen", "jid_protect" }) );
   SetRace("sprite");
   SetShort("a female Sprite citizen of Jidoor");
   SetLong("Dressed in the attire of a diviner, the female citizen "
           "is wandering about the city attending to her daily "
           "business. She appears to be friendly.");
   SetSpellBook( ([ 
      "wards of protection" : 100,
      "chill touch" : 100,
   ]) );
   SetCombatAction(5, ({ 
      "!cast chill touch",
      "!cast wards of protection",
   }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/diviner_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
   SetClass("diviner");
   SetMorality(20);
}
  else if(type == 4) { /* JIDOOR NPC TYPE: FEMALE SPRITE MYSTIC*/
   SetAdjectives( ({ "sprite","female" }) );
   SetId( ({ "sprite","citizen", "jid_protect" }) );
   SetRace("sprite");
   SetShort("a female Sprite citizen of Jidoor");
   SetLong("Dressed in the attire of a mystic, the female citizen "
           "is wandering about the city attending to her daily "
           "business. She appears to be friendly.");
   SetSpellBook( ([ 
      "capsule" : 100,
      "shock" : 100,
   ]) );
   SetCombatAction(5, ({ 
      "!cast capsule",
      "!cast shock",
   }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/mystic_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
   SetClass("mystic");
   SetMorality(20);
}
  else if(type == 5) { /* JIDOOR NPC TYPE: FEMALE LAMRANI EVOKER */
   SetAdjectives( ({ "lamrani","female" }) );
   SetId( ({ "lamrani","citizen", "jid_protect" }) );
   SetRace("lamrani");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetShort("a female Lamrani citizen of Jidoor");
   SetLong("Dressed in the attire of an evoker, the female citizen "
           "is wandering about the city attending to her daily "
           "business. She appears to be friendly.");
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
  else if(type == 6) { /* JIDOOR NPC TYPE: FEMALE LAMRANI ENCHANTER */
   SetAdjectives( ({ "lamrani","female" }) );
   SetId( ({ "lamrani","citizen", "jid_protect" }) );
   SetRace("lamrani");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetShort("a female Lamrani citizen of Jidoor");
   SetLong("Dressed in the attire of an enchanter, the female citizen "
           "is wandering about the city attending to her daily "
           "business. She appears to be friendly.");
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
  else if(type == 7) { /* JIDOOR NPC TYPE: FEMALE LAMRANI NECROMANCER */
   SetAdjectives( ({ "lamrani","female" }) );
   SetId( ({ "lamrani","citizen", "jid_protect" }) );
   SetRace("lamrani");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetShort("a female Lamrani citizen of Jidoor");
   SetLong("Dressed in the attire of a necromancer, the female citizen "
           "is wandering about the city attending to her daily "
           "business. She appears to be friendly.");
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
  else if(type == 8) { /* JIDOOR NPC TYPE: FEMALE LAMRANI DIVINER */
   SetAdjectives( ({ "lamrani","female" }) );
   SetId( ({ "lamrani","citizen", "jid_protect" }) );
   SetRace("lamrani");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetShort("a female Lamrani citizen of Jidoor");
   SetLong("Dressed in the attire of a diviner, the female citizen "
           "is wandering about the city attending to her daily "
           "business. She appears to be friendly.");
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
  else if(type == 9) { /* JIDOOR NPC TYPE: FEMALE LAMRANI MYSTIC */
   SetAdjectives( ({ "lamrani","female" }) );
   SetId( ({ "lamrani","citizen", "jid_protect" }) );
   SetRace("lamrani");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetShort("a female Lamrani citizen of Jidoor");
   SetLong("Dressed in the attire of mystic, the female citizen "
           "is wandering about the city attending to her daily "
           "business. She appears to be friendly.");
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
   SetKeyName("citizen");
   SetLevel(3+random(15));
   SetTown("Jidoor");
   SetReligion("Magildan","Magildan");
   SetGender("female");
  SetLimit(4);
   SetCurrency("rupies", random(50)+50);
   SetAction(1, ({ 
      "!speak Hello",
      "!speak Hello",
      "!speak Hello",
      "Citizen smiles at you.",
      "Citizen smiles at you.",
      "Citizen smiles at you.",
      "!speak lovely day isn't it?",
      "!look at mountains",
      "!look at building",
      "!ponder",   }) );
   SetDie("The female citizen falls down dead.");
   SetFriends( ({ "child","guard", "citizen","navan" }) );
   SetWander(15);
}
