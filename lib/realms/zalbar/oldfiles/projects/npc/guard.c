/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: shadowguard.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: May 11th, 1999
// Abstract: Shadowguard Sentry for Jidoor
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_TOWNGUARD;
#include "../wanted.h"

int type = random(4);
int CheckWanted();  /* Thanks Duuktsary & Zaxan for some sourcecode */
void DoSomething();  /* Thanks Zeddicus for some sourcecode */
void DoCombatSomething();
string CheckSetShort();
static void create() {
   ::create();

   if (type == 0) { /* JIDOOR NPC TYPE: MALE SPRITE SENTRY*/
   SetAdjectives( ({ "sprite","male","" }) );
   SetId( ({ "sprite","guard","sentry","shadowguard", "jid_protect" }) );
   SetInventory( ([
     JID_OBJ + "/shadowguard_knife" : "wield knife",
     JID_OBJ + "/clothing/vs_shadowguard_robe" : "wear robe",
     JID_OBJ + "/clothing/vs_shadowguard_boots" : "wear boots",
   ]) );
  }

  else if(type == 1) { /* JIDOOR NPC TYPE: FEMALE SPRITE SENTRY*/
   SetAdjectives( ({ "sprite","male","" }) );
   SetId( ({ "sprite","guard","sentry","shadowguard", "jid_protect" }) );
   SetInventory( ([
     JID_OBJ + "/shadowguard_knife" : "wield knife",
     JID_OBJ + "/clothing/vs_shadowguard_robe" : "wear robe",
     JID_OBJ + "/clothing/vs_shadowguard_boots" : "wear boots",
   ]) );
   }

  else if(type == 2) { /* JIDOOR NPC TYPE: MALE LAMRANI SENTRY*/
   SetAdjectives( ({ "lamrani","male","" }) );
   SetId( ({ "lamrani","guard","sentry","shadowguard", "jid_protect" }) );
   SetInventory( ([
     JID_OBJ + "/shadowguard_knife" : "wield knife",
     JID_OBJ + "/clothing/shadowguard_robe" : "wear robe",
     JID_OBJ + "/clothing/shadowguard_boots" : "wear boots",
   ]) );
   }

  else if(type == 3) { /* JIDOOR NPC TYPE: FEMALE LAMRANI SENTRY*/
   SetAdjectives( ({ "lamrani","female","" }) );
   SetId( ({ "lamrani","guard","sentry","shadowguard", "jid_protect" }) );
   SetInventory( ([
     JID_OBJ + "/shadowguard_knife" : "wield knife",
     JID_OBJ + "/clothing/shadowguard_robe" : "wear robe",
     JID_OBJ + "/clothing/shadowguard_boots" : "wear boots",
   ]) );
   }
   /* Common */
  SetLimit(10);
   SetRace( (random(2) ? "lamrani" : "sprite") );
   SetGender( (random(2) ? "male" : "female") );
   SetKeyName("shadowguard");
   SetClass("evoker");
   
   SetTown("Jidoor");
   SetMorality(-25);
   SetReligion("Magildan","Magildan");
   SetShort( (: CheckSetShort :) );
   SetLong("Wearing the standard issue outfit of the Jidoor City Shadow "
           "Guardians this sentry is not to be trifled with.  Fierce in "
           "combat with " + possessive(this_object()) + " weapon, and "
           "forever watching the city streets "
           "the Shadow Guardian can be your friend or your worst enemy.");
   SetLevel(50);
   SetSpellBook( ([ 
      "chain lightning" : 100,
      "disintegrate" : 100,
      "mesmer barrier" : 100,
      "invisibility" : 100,
      "channeling" : 100,
      "planar strength" : 100,
   ]) );  
   SetCombatAction(50, (: DoCombatSomething :) ); 
   SetAction(1, (: DoSomething :) );
   SetFriends( ({ 
      "jid_protect", "jidoor_npc"
   }) );
   SetEncounter( (: CheckWanted : ) );
   SetCurrency("rupies",random(300)+500);
   SetDie("A shadowguard sentry drops dead.");
   SetCombatStyleLevel("blade dancing", 60);
   if (GetRace() == "lamrani") { 
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
     if (GetGender() == "male") {
       SetStat("durability", 30, 5);
       SetStat("strength", 30, 5);
     }
     else {
       SetStat("durability", 25, 5);
       SetStat("strength", 25, 5);
     }
   }
   if (GetRace() == "sprite") {     
     if (GetGender() == "male") { 
       SetStat("durability", 35,3);
     } 
     else { 
       SetStat("durability", 30, 3);
     } 
   }
}

string CheckSetShort() {
  if(!GetInvis(1)) {
  return "a shadowguard sentry of Jidoor";
  }
  else {
  return "an invisible shadowguard";
  }
}

int CheckWanted() {

  if (this_player()->GetInvis()) return 0;

  if( (newbiep(this_player())) &&
       (member_array(this_player()->GetKeyName(), Wanted) != -1) ) {
      eventForce("speak I'd get out of the city, "+
                 this_player()->GetName()+". You're in a bit of trouble.");
   }

  if ((sizeof(GetMagicProtection()) < 2) ||
    ((!random(3)) && (sizeof(GetMagicProtection()) < 5))) {
     eventForce("cast mesmer barrier");
  }

  if( (!newbiep(this_player())) &&
       (member_array(this_player()->GetKeyName(), Wanted) != -1) ) {
      eventForce("speak Die "+this_player()->GetName()+"! Die!");
      eventForce("follow " + this_player()->GetKeyName());
      eventForce("attack " + this_player()->GetKeyName());
    }

   if(this_player()->GetProperty("invader")) {
     eventForce("yell Invaders!");
     AddEnemy(this_player());
     return 1;
   }
  return 0;
}

void DoSomething() {

  int randnum = random(6);

  if(!GetProperty("planar_strength")) {
    eventForce("cast planar strength");
    }

  if (!random(50)) {
   if (randnum == 0) { eventForce("look");}
   if (randnum == 1) { eventForce("look at first building");}
   if (randnum == 2) { eventForce("look at first guard");}
   if (randnum == 3) { eventForce("nod quietly");}
   if (randnum == 4) { eventForce("nod quietly");}
   if (randnum == 5) { eventForce("nod quietly");}
  }

  if (GetStaminaPoints() > (GetMaxStaminaPoints()/4)) {
    if(!GetInvis(1)) {
    eventForce("cast invisibility");
    }
  }


  if ((GetMagicPoints() < (GetMaxMagicPoints()/6)) &&
    (GetStaminaPoints() > (to_int(GetMaxStaminaPoints()/2))) &&
    (!random(3))) {
    eventForce("cast channeling");
  } 

  if ((sizeof(GetMagicProtection()) < 2) ||
     ((!random(3)) && (sizeof(GetMagicProtection()) < 5))) {
    eventForce("cast mesmer barrier" );
    return;
    }
  } 

void DoCombatSomething() {

  int randnum = random(3);

  if (!random(50)) {
   if (randnum == 0) { eventForce("speak I think I shall teach you a "
                                   "lesson in respect.");}
   if (randnum == 1) { eventForce("speak you dare to challenge the "
                                   "Shadowguards?");}
   if (randnum == 2) { eventForce("speak Foolish One, you shall pay dearly "
                                   "for your insolence.");}
  }

  if (GetMagicPoints() > (GetMaxMagicPoints()/6)) {
      eventForce("cast " + (random(3) ? "chain lightning" : 
        "disintegrate" ));
    }

 
  if ((GetMagicPoints() < (GetMaxMagicPoints()/6)) &&
    (GetStaminaPoints() > (to_int(GetMaxStaminaPoints()/2)))) {
    eventForce("set style to blade dancing");
        }
  else
    eventForce("set style to none");
  return;
}
