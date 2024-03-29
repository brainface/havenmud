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
   SetAdjectives( ({ "sprite","male","elite" }) );
   SetId( ({ "sprite","guard","sentry","shadowguard", "jid_protect" }) );
    SetRace("sprite");
    SetGender("male");
   SetInventory( ([
      JID_OBJ + "/shadowguard_knife" : "wield knife",
      JID_OBJ + "/clothing/vs_shadowguard_robe" : "wear robe",
      JID_OBJ + "/clothing/vs_shadowguard_boots" : "wear boots",
    ]) );
  }

  else if(type == 1) { /* JIDOOR NPC TYPE: FEMALE SPRITE SENTRY*/
   SetAdjectives( ({ "sprite","female","elite" }) );
   SetId( ({ "sprite","guard","sentry","shadowguard", "jid_protect" }) );
   SetRace("sprite");
   SetGender("female");
   SetInventory( ([
      JID_OBJ + "/shadowguard_knife" : "wield knife",
      JID_OBJ + "/clothing/vs_shadowguard_robe" : "wear robe",
      JID_OBJ + "/clothing/vs_shadowguard_boots" : "wear boots",
   ]) );
   }

  else if(type == 2) { /* JIDOOR NPC TYPE: MALE LAMRANI SENTRY*/
   SetAdjectives( ({ "lamrani","male","elite" }) );
   SetId( ({ "lamrani","guard","sentry","shadowguard", "jid_protect" }) );
   SetRace("lamrani");
   SetGender("male");
   SetInventory( ([
      JID_OBJ + "/shadowguard_knife" : "wield knife",
      JID_OBJ + "/clothing/shadowguard_robe" : "wear robe",
      JID_OBJ + "/clothing/shadowguard_boots" : "wear boots",
   ]) );
   }

  else if(type == 3) { /* JIDOOR NPC TYPE: FEMALE LAMRANI SENTRY*/
   SetAdjectives( ({ "lamrani","female","elite" }) );
   SetId( ({ "lamrani","guard","sentry","shadowguard", "jid_protect" }) );
   SetRace("lamrani");
   SetGender("female");
   SetInventory( ([
      JID_OBJ + "/shadowguard_knife" : "wield knife",
      JID_OBJ + "/clothing/shadowguard_robe" : "wear robe",
      JID_OBJ + "/clothing/shadowguard_boots" : "wear boots",
   ]) );
   }
   /* Common */
   SetLimit(10);

   SetKeyName("shadowguard");
   SetClass("evoker");
   SetLevel(70);
   SetTown("Jidoor");
   SetMorality(-25);
   SetReligion("Magildan","Magildan");
   SetShort( (: CheckSetShort :) );
   SetLong("Wearing the standard issue outfit of the Jidoor City Shadow "
           "Guardians this sentry is not to be trifled with.  Fierce in "
           "combat with " + possessive(this_object()) + " weapon, and "
           "forever watching the city streets "
           "the Shadow Guardian can be your friend or your worst enemy. "
           );

   SetSpellBook( ([
      "chain lightning"   : 100,
      "disintegrate"      : 100,
      "mesmer barrier"    : 100,
      "invisibility"      : 100,
      "channeling"        : 100,
      "planar strength"   : 100,
      "planar durability" : 100,
      ]) );
   SetCombatAction(50, (: DoCombatSomething :) );
   SetAction(1, (: DoSomething :) );
   SetFriends( ({
      "jid_protect","jidoor_npc",
      }) );
  SetWander( 5 + random(3), ({ "go west","go west","enter bank","go out",
                "go east","enter store","go up","go down","go out",
                "go east","enter hall","go up","go down","go down",
                "go up","go out","go south","go south","enter library",
                "go up","go down","go east","go south","go north",
                "go east","go down","go up","go up","go up","go up",
                "go up", "go down", "go down", "go down", "go down",
                "go west", "go west", "go out", "go south", "enter pub",
                "go out", "go south", "go north", "go north", "go north",
                "go north", "go east", "enter inn", "go east", "go out"
                "enter office", "go out", "go east", "go east", "go north"
                "enter hall", "go out", "go north", "go north",
                "go northeast", "go northeast", "go north", "go south",
                "go southwest", "go southwest", "go west", "enter tower",
                "go up", "go down", "go out", "go west","enter hall",
                "go out", "go north", "enter mausoleum", "go out",
                "go west", "enter shop", "go out", "go south", "go west",
                "go east", "go south", "go south"}), 1 );
   SetEncounter( (: CheckWanted : ) );
   SetCurrency("rupies",random(400)+200);
   SetDie("A shadowguard sentry drops dead.");
   if (GetRace() == "lamrani") {
     SetLanguage("Sprith", 100, 1);
   }
}

string CheckSetShort() {
  if(!GetInvis(1)) {
    return "an shadowguard sentry of Jidoor";
  } else {
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

  if(!GetProperty("planar_durability")) {
    eventForce("cast planar durability");
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

  return;
}

