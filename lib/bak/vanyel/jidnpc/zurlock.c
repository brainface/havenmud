/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: zurlock.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Sept 21st, 1998
// Abstract: Zurlock, Jidoor Healer and Special Vendor
// Revision History:  Base file created by Zaxan@Haven 
// Edited by Gaby to discourage people from sitting all day
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <std.h>
#include "../jidoor.h"

inherit LIB_HEALER;

int HealHealth();
int HealMagic();
int HealStamina();
void DoSomething(); /* Thanks Zeddicus for some sourcecode */
void DoCombatSomething(); /* Thanks Zeddicus for some sourcecode */
int CheckWanted(); /* Thanks Duuktsary & Zaxan for some sourcecode */
int DoHeal(object who, string args);

#include "../wanted.h"

static void create() {
   healer::create();
   SetKeyName("zurlock");
   SetId( ({ "zurlock", "healer" }) );
   SetShort("Zurlock the Healer");
   SetLong("This little old man looks friendly and gentle. He seems "
           "to want to give all he can to heal anyone who needs it.");
   SetLevel(50);
   SetReligion("Magildan","Magildan");
   SetRace("sprite");
   SetMorality(50);
   SetClass("cleric");
   SetSkill("evokation",75,1);
   SetSkill("necromancy",75,1);
   SetSkill("blunt attack",75,1);
   SetSkill("enchantment",75,1);
   SetSkill("healing",75,1);
   SetSpellBook( ([ 
      "mend" : 100,
      "blessed water" : 100,
      "divine mana" : 100,
      "barrier of faith" : 100,
      "divine field" : 100,
      "harm body" : 100,
   ]) );
   SetCombatAction(75, (: DoCombatSomething :) );
   AddFood(-2400);
   SetAction(75, (: DoSomething :) );
   SetLocalCurrency("rupies");
    SetFees( ([
    "resurrect" : 100,
    "magic" : 10,
    "stamina" : 1,
    "health" : 3,
    "restore" : 50,
    ]) );
   SetGender("male");
   SetCurrency("rupies", 100);
   SetEncounter( (: CheckWanted : ) );
   SetInventory( ([ 
      STD_CLOTHING + "body/turquoise_robe" : "wear robe",
      STD_CLOTHING + "boot/high_boots" : "wear boots",
      JID_OBJ + "/mithril_hammer" : "wield hammer",
   ]) );
}

int DoHeal(object who, string args) {
   if(!args) {
      eventForce("speak Do you want me to heal health, magic "
                 "or stamina?");
      return 1;
   }
    if (who->GetTown() != "Jidoor" && 
        who->GetReligion() != "Magildan"
        == -1 ) {
      eventForce("speak I don't heal people I don't know from our town.");
      return 1;
    }
   switch (args) {
      case "health" :
         HealHealth();
         break;
      case "magic" :
         HealMagic();
         break;
      case "stamina" :
         HealStamina();
         break;
      default :
         eventForce("speak Do you want me to heal health, "
                    "magic, or stamina?");
         break;
   }
}

int HealHealth() {
   int hpcur, rupies, hpmax, hpheal;
   int mp = GetMagicPoints();

   if( mp <= 74 ) {
      eventForce("speak I am too low on magic to heal.");
      return 0;
   }
   hpmax = (int)this_player()->GetMaxHealthPoints();
   hpcur = (int)this_player()->GetHealthPoints();
   hpheal = hpmax - hpcur;
   rupies = (hpheal)*100;
   if( hpmax == hpcur ) {
      eventForce("speak You do not need to be healed!");
      return 0;
   }
   if( (int)this_player()->GetCurrency("rupies") < rupies ) {
      eventForce("speak You do not have enough money to be "
                 "healed.");
      eventForce("speak That will cost you " + (int)rupies +
                 " rupies.");
      return 0;
   }
   this_player()->AddCurrency("rupies", -rupies);
   AddMagicPoints(-75);
   this_player()->eventHealDamage(hpheal);
   eventForce("emote closes his eyes and begins"
             " %^BOLD%^BLUE%^uttering an incantation%^RESET%^.");
   eventForce("speak All Healed.");
   return 0;
}

int HealMagic() {
   int mpcur, rupies, mpmax, mpheal;
   int mp = GetMagicPoints();

   if( mp <= 74 ) {
      eventForce("speak I am too low on magic to heal.");
      return 0;
   }
   mpmax = (int)this_player()->GetMaxMagicPoints();
   mpcur = (int)this_player()->GetMagicPoints();
   mpheal = mpmax - mpcur;
   rupies = (mpheal)*400;
   if( mpmax == mpcur ) {
      eventForce("speak You do not need to be healed!");
      return 0;
   }
   if( (int)this_player()->GetCurrency("rupies") < rupies ) {
      eventForce("speak You do not have enough money to be "
                 "healed.");
      eventForce("speak That will cost you " + (int)rupies +
                 " rupies.");
      return 0;
   }
   this_player()->AddCurrency("rupies", -rupies);
   AddMagicPoints(-75);
   this_player()->AddMagicPoints(mpheal);
   eventForce("emote closes his eyes and begins"
             " %^BOLD%^BLUE%^uttering an incantation%^RESET%^.");
   eventForce("speak All healed!");
   return 0;
}

int HealStamina() {
   int spcur, rupies, spmax, spheal;
   int mp = GetMagicPoints();

   if( mp <= 74 ) {
      eventForce("speak I am too low on magic to heal.");
      return 0;
   }
   spmax = (int)this_player()->GetMaxStaminaPoints();
   AddMagicPoints(-75);
   spcur = (int)this_player()->GetStaminaPoints();
   spheal = spmax - spcur;
   spheal = to_int(spheal);
   rupies = spheal*150;
   if( spmax == spcur ) {
      eventForce("speak You do not need to be healed!");
      return 0;
   }
   if( (int)this_player()->GetCurrency("rupies") < rupies ) {
      eventForce("speak You do not have enough money to be "
                 "healed.");
      eventForce("speak That will cost you " + (int)rupies +
                 " rupies.");
      return 0;
   }
   this_player()->AddCurrency("rupies", -rupies);
   this_player()->AddStaminaPoints(spheal);
   eventForce("emote closes his eyes and begins"
             " %^BOLD%^BLUE%^uttering an incantation%^RESET%^.");
   eventForce("speak All healed!");
   return 0;
}

int CheckWanted() {

  if (this_player()->GetInvis()) return 0;

  if( (newbiep(this_player())) &&
       (member_array(this_player()->GetKeyName(), Wanted) != -1) ) {
      eventForce("speak I'd get out of the city, "+
                 this_player()->GetName()+". You're in a bit of trouble.");
   }

  if ((sizeof(GetMagicProtection()) < 2) ||
    ((!random(2)) && (sizeof(GetMagicProtection()) < 3))) {
     eventForce("cast divine field");
  }

  if( (!newbiep(this_player())) &&
       (member_array(this_player()->GetKeyName(), Wanted) != -1) ) {
      eventForce("cast barrier of faith");
      eventForce("speak Die "+this_player()->GetName()+"! Die!");
      eventForce("follow " + this_player()->GetKeyName());
      eventForce("attack " + this_player()->GetKeyName());
    }

   if(this_player()->GetProperty("invader")) {
     eventForce("yell Invaders in my Healing Shop!");
     eventForce("cast barrier of faith");
     AddEnemy(this_player());
     return 1;
   }
  return 0;
}

void DoSomething() {

  int randnum = random(6);

   if(GetHealthPoints() < GetMaxHealthPoints()) {
      eventForce("!cast mend");
      }
   if(GetDrink() < 500) {
     eventForce("cast blessed water");
     eventForce("drink water");
      AddDrink(5000);
      }
   if(GetFood() < 500) {
     eventForce("cast divine mana");
     eventForce("eat first mana");
     AddFood(5000);
     }

  if (!random(50)) {
   if (randnum == 0) { eventForce("read sign");}
   if (randnum == 1) { eventForce("speak are you here for my services?");}
   if (randnum == 2) { eventForce("smile solemnly");}
   if (randnum == 3) { eventForce("nod quietly");}
   if (randnum == 4) { eventForce("nod solemnly");}
   if (randnum == 5) { eventForce("nod quietly");}
  }

  if ((sizeof(GetMagicProtection()) < 2) ||
     ((!random(3)) && (sizeof(GetMagicProtection()) < 3))) {
    eventForce("cast divine field" );
    return;
    }
  } 

void DoCombatSomething() {

  int randnum = random(3);

  if (!random(50)) {
   if (randnum == 0) { eventForce("speak Why attack me?");}
   if (randnum == 1) { eventForce("yell Help Shadowguards!");}
   if (randnum == 2) { eventForce("speak Foolish One, you shall pay dearly "
                                   "for your insolence.");}
  }

  if ((sizeof(GetMagicProtection()) < 2) ||
     ((!random(2)) && (sizeof(GetMagicProtection()) < 5))) {
    eventForce("cast barrier of faith" );
    return;
    }

  if (GetMagicPoints() > (GetMaxMagicPoints()/6)) {
      eventForce("cast harm body");
  }
}
